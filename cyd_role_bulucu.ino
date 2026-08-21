/*
   Bu sürümde:
   1) Mesafe üst taraftaki + ve - ile 10 ar km. şeklinde ayarlanabilmektedir.
   2) Ana ekrandaki bir röleye vs. tıklatınca detayları gelmektedir.

*/
#include <TFT_eSPI.h>
#include <XPT2046_Touchscreen.h>
#include <TinyGPS++.h>
#include <SPI.h>
#include "roleler.h"

// *** CYD bacak tanımlamaları ***
#define XPT_CS   33
#define XPT_IRQ  36
#define XPT_MOSI 32
#define XPT_MISO 39
#define XPT_CLK  25

// *** GPS bacak tanımlamaları ***
#define RXD2 22
#define TXD2 27

SPIClass touchSPI(VSPI);
XPT2046_Touchscreen touch(XPT_CS, XPT_IRQ);
TFT_eSPI tft = TFT_eSPI();
TinyGPSPlus gps;
HardwareSerial gpsSerial(2);

enum Mode { LISTE, DETAY };
Mode aktifMod = LISTE;

int seciliRoleIndex = -1;
unsigned long sonEkranGuncelleme = 0;
bool ilkKilit = false;
float taramaCapi = 60.0;  // Başlangıçtaki röle arama çapı
double sonLat = 0;
double sonLon = 0;

#define PANEL_BG      0x1084
#define TURKUAZIM  0x07F9    // Turkuaz renk tanımı 

// *** SETUP kısmı **************************************************************
void setup() {
  Serial.begin(115200);
  gpsSerial.begin(9600, SERIAL_8N1, RXD2, TXD2); //GPS başlatılıyor

  tft.init();
  tft.setRotation(1);
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_YELLOW);
  tft.setTextSize(2);
  tft.setCursor(20, 100);
  tft.println("GPS BEKLENiYOR...");

  touchSPI.begin(XPT_CLK, XPT_MISO, XPT_MOSI, XPT_CS);
  touch.begin(touchSPI);
  touch.setRotation(1);
  pinMode(XPT_IRQ, INPUT);
}
// *** SETUP kısmının sonu ******************************************************

double get_distance(double lat1, double lon1, double lat2, double lon2) {
  double dLat = (lat2 - lat1) * M_PI / 180.0;
  double dLon = (lon2 - lon1) * M_PI / 180.0;
  double a = sin(dLat / 2) * sin(dLat / 2) + cos(lat1 * M_PI / 180.0) * cos(lat2 * M_PI / 180.0) * sin(dLon / 2) * sin(dLon / 2);
  return 6371.0 * (2 * atan2(sqrt(a), sqrt(1 - a)));
}

void drawListe(double myLat, double myLon) {
  tft.fillScreen(TFT_BLACK);

  // ekranın üst kısmında sâdece Mesafe ve butonlar görünecek
  tft.fillRect(0, 0, 320, 40, PANEL_BG);
  tft.drawFastHLine(0, 40, 320, TFT_SILVER);
  tft.setTextSize(2);
  tft.setTextColor(TFT_WHITE);
  tft.setCursor(10, 12);
  tft.printf("%.0f KM MESAFE", taramaCapi);

  tft.fillRoundRect(220, 5, 40, 30, 4, TFT_RED);
  tft.fillRoundRect(270, 5, 40, 30, 4, TFT_DARKGREEN);
  tft.setTextColor(TFT_WHITE);
  tft.setCursor(233, 12); tft.print("-");
  tft.setCursor(283, 12); tft.print("+");

  int y = 55;
  int sayac = 0;
  Role r;
  for (int i = 0; i < role_sayisi; i++) {
    memcpy_P(&r, &role_veritabani[i], sizeof(Role));
    double d = get_distance(myLat, myLon, r.latitude, r.longitude);

    if (d <= taramaCapi) {
      tft.setCursor(10, y);
      tft.setTextSize(2);
      tft.setTextColor(TFT_GREEN, TFT_BLACK);
      tft.printf("%s %.1fkm", r.yer, d);
      y += 26;
      sayac++;
      if (sayac >= 6) break;
    }
  }

  // Alt bilgi satırı - konum bilgileri
  tft.drawFastHLine(0, 220, 320, 0x4208);
  tft.setTextSize(1);
  tft.setTextColor(TFT_SILVER);
  tft.setCursor(10, 228);
  tft.printf("KONUM: %.4f, %.4f", myLat, myLon);
}

void drawDetay(int index, double myLat, double myLon) {
  tft.fillScreen(TFT_BLACK);
  Role r;
  memcpy_P(&r, &role_veritabani[index], sizeof(Role));
  double d = get_distance(myLat, myLon, r.latitude, r.longitude);

  tft.fillRect(0, 0, 320, 40, PANEL_BG);
  tft.drawFastHLine(0, 40, 320, TFT_SILVER);
  tft.fillRoundRect(5, 5, 50, 30, 6, 0x8000);
  tft.setTextColor(TFT_WHITE); tft.setTextSize(2);
  tft.setCursor(20, 12); tft.print("<");
  tft.setCursor(65, 12); tft.setTextColor(TFT_YELLOW); tft.println(r.yer);

  int y = 55;
  auto printLine = [&](const char* label, const char* val) {
    tft.setTextColor(TFT_WHITE); tft.setCursor(20, y); tft.print(label);
    tft.setTextColor(TFT_GREEN); tft.setCursor(130, y); tft.print(val);
    y += 26;
  };

  tft.setTextColor(TFT_WHITE); tft.setCursor(20, y); tft.print("Frekans:");
  tft.setTextColor(TFT_GREEN); tft.setCursor(130, y); tft.printf("%.4f MHz", r.frekans);
  y += 26;
  printLine("Band   :", r.band);
  printLine("RX Ton :", r.rx_ton);
  printLine("TX Ton :", r.tx_ton);
  printLine("Kip    :", r.kip);
  printLine("Gorev  :", r.gorev);

  y += 8;
  tft.setTextColor(TURKUAZIM); tft.setCursor(20, y); tft.printf("Mesafe : %.2f km", d); // 
}

void loop() {
  while (gpsSerial.available() > 0) gps.encode(gpsSerial.read());

  if (touch.touched()) {
    TS_Point p = touch.getPoint();
    if (p.z > 750 && p.x > 100 && p.y > 100) {
      int x = map(p.x, 200, 3800, 0, 320);
      int y = map(p.y, 200, 3800, 0, 240);

      if (aktifMod == LISTE) {
        if (y < 40) {
          if (x > 220 && x < 260) {
            taramaCapi = max(10.0f, taramaCapi - 10.0f);
            drawListe(gps.location.lat(), gps.location.lng());
            delay(250);
          }
          else if (x > 270 && x < 310) {
            taramaCapi = min(500.0f, taramaCapi + 10.0f);
            drawListe(gps.location.lat(), gps.location.lng());
            delay(250);
          }
        } else if (y >= 50 && y < 215) {
          int satir = (y - 50) / 26;
          int sayac = 0;
          for (int i = 0; i < role_sayisi; i++) {
            Role r; memcpy_P(&r, &role_veritabani[i], sizeof(Role));
            if (get_distance(gps.location.lat(), gps.location.lng(), r.latitude, r.longitude) <= taramaCapi) {
              if (sayac == satir) {
                seciliRoleIndex = i; aktifMod = DETAY;
                drawDetay(seciliRoleIndex, gps.location.lat(), gps.location.lng());
                delay(350); break;
              }
              sayac++;
            }
          }
        }
      } else if (aktifMod == DETAY && x < 65 && y < 45) {
        aktifMod = LISTE; drawListe(gps.location.lat(), gps.location.lng()); delay(350);
      }
    }
  }

  // GPS Yönetimi - Sadece Konum Değişirse Çiz
  if (gps.location.isValid()) {
    double cLat = gps.location.lat();
    double cLon = gps.location.lng();

    if (!ilkKilit) {
      ilkKilit = true;
      drawListe(cLat, cLon);
      sonLat = cLat; sonLon = cLon;
      sonEkranGuncelleme = millis();
    }

    if (aktifMod == LISTE) {
      bool konumDegisti = (abs(cLat - sonLat) > 0.001 || abs(cLon - sonLon) > 0.001);
      bool zamanDoldu = (millis() - sonEkranGuncelleme > 60000); // Otomatik tazeleme süresi 1 dakika

      if (konumDegisti || zamanDoldu) {
        drawListe(cLat, cLon);
        sonLat = cLat;
        sonLon = cLon;
        sonEkranGuncelleme = millis();
      }
    }
  }
}
