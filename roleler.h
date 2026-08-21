#ifndef ROLELER_H
#define ROLELER_H

#include <Arduino.h>

struct Role {
  char yer[32];      // 1. YER
  char band[8];      // 2. BAND
  char gorev[16];    // 3. GOREV
  char kip[12];      // 4. KIP
  double frekans;    // 5. FREKANS
  char rx_ton[8];    // 6. RX Ton
  char tx_ton[8];    // 7. TX Ton
  double latitude;   // 8. Lat (Locator'dan hesaplandı)
  double longitude;  // 9. Long (Locator'dan hesaplandı)
};

const Role role_veritabani[] PROGMEM = {
  {"ADANA", "VHF", "Role", "Analog", 145.700, "88.5", "88.5", 37.0625, 35.3750}, // KM77PB
  {"ADANA", "UHF", "Role", "Analog", 439.275, "Yok", "Yok", 37.0208, 35.3750},   // KM77PA
  {"ADANA", "UHF", "Role", "Analog", 439.2875, "Yok", "Yok", 37.0625, 35.3750}, // KM77PB
  {"MERZIFON", "UHF", "Role", "Analog", 439.425, "Yok", "88.5", 40.8541, 35.4583}, // KN70RV
  {"ANKARA", "VHF", "Role", "Analog", 145.675, "Yok", "88.5", 39.8125, 32.7083}, // KM69LT
  {"ANKARA", "UHF", "Role", "Analog", 439.400, "Yok", "88.5", 39.8125, 32.7083}, // KM69LT
  {"ANKARA", "UHF", "Echolink", "Analog", 432.850, "Yok", "Yok", 39.8958, 32.6250}, // KM69HX
  {"ANTALYA", "VHF", "Role", "Analog", 145.6125, "Yok", "88.5", 36.5625, 30.1250}, // KM66BM
  {"ANTALYA", "UHF", "Role", "Analog", 439.225, "Yok", "88.5", 36.5208, 30.0417}, // KM66AN
  {"ANTALYA", "UHF", "Role", "Analog", 439.2375, "Yok", "88.5", 36.6458, 30.2917}, // KM66DF
  {"ANTALYA", "UHF", "Role", "Analog", 439.2625, "Yok", "88.5", 36.5625, 30.2083}, // KM66AO
  {"AYDIN", "UHF", "Role", "Analog", 439.150, "Yok", "88.5", 37.8125, 27.8750}, // KM47DV
  {"AYDIN", "UHF", "Role", "Analog", 439.200, "Yok", "88.5", 37.9375, 28.1250}, // KM47GW
  {"AYDIN", "UHF", "Role", "Analog", 439.275, "Yok", "88.5", 37.7292, 27.9583}, // KM37RT
  {"AYDIN", "UHF", "Role", "Analog", 439.375, "Yok", "88.5", 37.6042, 27.8750}, // KM37OP
  {"BALIKESIR", "UHF", "Role", "Analog", 439.375, "77.0", "77.0", 39.9375, 28.1250}, // KM39WP
  {"BUCAK", "VHF", "Role", "Analog", 145.775, "Yok", "88.5", 37.4375, 30.2917}, // KM57DK
  {"BUCAK", "UHF", "Role", "Analog", 439.150, "Yok", "88.5", 37.4375, 30.2917}, // KM57DK
  {"BURSA", "VHF", "Role", "Analog", 145.650, "77.0", "77.0", 40.1458, 29.1250}, // KN40ND
  {"BURSA", "VHF", "Role", "Analog", 145.7375, "110.9", "110.9", 40.1042, 29.0833}, // KN40NC
  {"BURSA", "UHF", "Role", "Sayisal", 439.1625, "131.8", "131.8", 40.1875, 29.0417}, // KN40MI
  {"BURSA", "UHF", "Role", "Analog", 439.2375, "77.0", "77.0", 40.1458, 29.0417}, // KN40MH
  {"CANAKKALE", "UHF", "Role", "Analog", 439.400, "100.0", "100.0", 40.1458, 26.5417}, // KN30ED
  {"CANAKKALE", "UHF", "Echolink", "Analog", 433.575, "Yok", "77.0", 40.1042, 26.5417}, // KN30EC
  {"CANKIRI", "UHF", "Role", "Analog", 439.275, "88.5", "88.5", 40.6042, 33.9583}, // KN60TO
  {"CANKIRI", "UHF", "Echolink", "Analog", 439.175, "Yok", "88.5", 40.6042, 33.9583}, // KN60TO
  {"CANKIRI", "VHF", "APRS", "Sayisal", 144.800, "Yok", "Yok", 40.3958, 33.5417}, // KN60JP
  {"CANKIRI", "VHF", "APRS", "Sayisal", 144.800, "Yok", "Yok", 40.8541, 33.8750}, // KN61UB
  {"CANKIRI", "VHF", "APRS", "Sayisal", 144.800, "Yok", "Yok", 40.6875, 33.7917}, // KN60RL
  {"CANKIRI", "VHF", "APRS", "Sayisal", 144.800, "Yok", "Yok", 40.6042, 33.9583}, // KN60TO
  {"DENIZLI", "VHF", "Role", "Analog", 145.600, "Yok", "88.5", 37.7708, 29.2083}, // KM47PK
  {"DENIZLI", "UHF", "Role", "Analog", 439.1625, "Yok", "Yok", 37.8125, 29.2083}, // KM47PQ
  {"DENIZLI", "UHF", "Role", "Analog", 439.250, "Yok", "88.5", 37.8125, 29.2083}, // KM47PQ
  {"DENIZLI", "UHF", "Echolink", "Analog", 439.250, "Yok", "88.5", 37.8125, 29.2083}, // KM47PQ
  {"COKELEZ", "VHF", "APRS", "Sayisal", 144.800, "Yok", "Yok", 37.7708, 29.2083}, // KM47PK
  {"HONAZ", "VHF", "APRS", "Sayisal", 144.800, "Yok", "Yok", 37.8125, 29.2083}, // KM47PQ
  {"ELAZIG", "VHF", "APRS", "Sayisal", 144.800, "Yok", "Yok", 38.6875, 39.3750}, // KM98OQ
  {"ESKISEHIR", "UHF", "Role", "Analog", 439.275, "67.0", "67.0", 39.8125, 30.4583}, // KM59GV
  {"GIRESUN", "VHF", "Role", "Analog", 145.600, "Yok", "88.5", 40.8958, 38.4583}, // KN90BM
  {"GIRESUN", "UHF", "Role", "Analog", 439.175, "Yok", "88.5", 40.9792, 38.6250}, // KN90DW
  {"HATAY", "VHF", "Role", "Analog", 145.750, "Yok", "88.5", 36.4792, 36.2083}, // KM86DL
  {"HATAY", "UHF", "Role", "Analog", 439.2625, "Yok", "88.5", 36.4792, 36.2083}, // KM86DL
  {"HATAY", "UHF", "Role", "Analog", 439.275, "Yok", "71.9", 36.2292, 36.1250}, // KM86BE
  {"HATAY", "UHF", "Role", "Analog", 439.375, "Yok", "88.5", 36.1042, 36.0417}, // KM86BA
  {"MERSIN", "VHF", "Role", "Analog", 145.600, "Yok", "82.5", 36.7708, 34.6250}, // KM76ES
  {"MERSIN", "VHF", "Role", "Analog", 145.675, "Yok", "88.5", 36.8541, 34.7917}, // KM76GU
  {"MERSIN", "UHF", "Role", "Analog", 439.150, "103.5", "103.5", 36.9792, 34.0417}, // KM66XJ
  {"MERSIN", "UHF", "Role", "Analog", 439.175, "Yok", "88.5", 36.8541, 34.7917}, // KM76GU
  {"MERSIN", "UHF", "Role", "Analog", 439.2125, "Yok", "88.5", 36.6042, 34.5417}, // KM76AK
  {"MERSIN", "UHF", "Role", "Analog", 439.425, "Yok", "88.5", 36.8541, 34.7917}, // KM76GU
  {"MERSIN", "VHF", "APRS", "Sayisal", 144.800, "Yok", "Yok", 36.6458, 34.5417}, // KM76BU
  {"MERSIN", "VHF", "APRS", "Sayisal", 144.800, "Yok", "Yok", 36.9375, 34.9583}, // KM76WH
  {"MERSIN", "VHF", "APRS", "Sayisal", 144.800, "Yok", "Yok", 36.7291, 34.6250}, // KM76EP
  {"MERSIN", "VHF", "APRS", "Sayisal", 144.800, "Yok", "Yok", 36.7708, 34.6250}, // KM76ES
  {"ISTANBUL", "VHF", "Role", "Analog", 145.7125, "123.0", "123.0", 41.0208, 28.9583}, // KN41HA
  {"ISTANBUL", "VHF", "Role", "Analog", 145.7375, "110.9", "110.9", 40.9791, 29.2083}, // KN40IX
  {"ISTANBUL", "UHF", "Role", "Analog", 439.1625, "131.8", "131.8", 41.1041, 29.1250}, // KN41MA
  {"ISTANBUL", "UHF", "Role", "Analog", 439.250, "Yok", "94.8", 41.0208, 28.9583}, // KN41HA
  {"ISTANBUL", "VHF", "APRS", "Sayisal", 144.800, "Yok", "Yok", 41.0625, 29.0417}, // KN41JC
  {"ISTANBUL", "VHF", "APRS", "Sayisal", 144.800, "Yok", "Yok", 41.1458, 29.0833}, // KN41LB
  {"ISTANBUL", "VHF", "APRS", "Sayisal", 144.800, "Yok", "Yok", 41.1875, 29.2083}, // KN41OB
  {"IZMIR", "UHF", "Role", "Analog", 439.200, "88.5", "88.5", 38.4375, 27.2083}, // KM38MH
  {"IZMIR", "VHF", "APRS", "Sayisal", 144.800, "Yok", "Yok", 38.4375, 27.2083}, // KM38MH
  {"IZMIR", "VHF", "APRS", "Sayisal", 144.800, "Yok", "Yok", 38.5625, 27.2917}, // KM38NL
  {"KIRKLARELI", "UHF", "Role", "Analog", 439.275, "Yok", "77.0", 41.8125, 27.5417}, // KN31TT
  {"KIRKLARELI", "UHF", "Role", "Analog", 439.375, "Yok", "67.0", 41.6875, 27.4583}, // KN31OR
  {"GOLCUK", "UHF", "Role", "Analog", 439.1875, "Yok", "77.0", 40.7291, 29.9583}, // KN40VT
  {"KARAMURSEL", "UHF", "Role", "Analog", 439.200, "Yok", "77.0", 40.6875, 29.6250}, // KM40TQ
  {"KARAMURSEL", "UHF", "Role", "Analog", 439.375, "94.8", "94.8", 40.7291, 29.8750}, // KN40TQ
  {"KOCAELI", "UHF", "Role", "Analog", 439.4125, "91.5", "91.5", 40.8541, 30.1250}, // KN40XQ
  {"KARAMURSEL", "UHF", "Echolink", "Analog", 439.375, "94.8", "94.8", 40.7291, 29.8750}, // KN40TQ
  {"KARAMURSEL", "VHF", "APRS", "Sayisal", 144.800, "Yok", "Yok", 40.7708, 29.8750}, // KN40TS
  {"KONYA", "VHF", "Role", "Analog", 145.600, "88.5", "88.5", 37.8958, 32.5417}, // KM67EX
  {"KONYA", "VHF", "Role", "Analog", 145.675, "Yok", "67.0", 37.8958, 32.5417}, // KM67EX
  {"KONYA", "UHF", "Role", "Analog", 439.150, "88.5", "88.5", 37.8958, 32.5417}, // KM67EX
  {"KONYA", "UHF", "Role", "Analog", 439.200, "Yok", "88.5", 37.8958, 32.5417}, // KM67EX
  {"KONYA", "UHF", "Role", "Analog", 439.225, "88.5", "88.5", 38.1041, 32.6250}, // KM69KE
  {"MALATYA", "VHF", "Role", "Analog", 145.775, "Yok", "88.5", 38.4375, 38.2083}, // KM98DI
  {"MALATYA", "UHF", "Role", "Analog", 439.375, "Yok", "88.5", 38.4375, 38.2083}, // KM98DI
  {"MALATYA", "UHF", "Role", "Analog", 439.425, "Yok", "88.5", 38.4375, 38.2083}, // KM98DI
  {"MANISA", "VHF", "Role", "Analog", 145.775, "Yok", "88.5", 38.6042, 27.4583}, // KM38QO
  {"MANISA", "UHF", "Role", "Analog", 439.400, "Yok", "88.5", 38.6458, 27.5417}, // KM38RN
  {"MANISA", "UHF", "Role", "Analog", 439.4125, "67.0", "67.0", 39.1042, 28.1250}, // KM39GU
  {"MANISA", "UHF", "Role", "Analog", 439.425, "Yok", "77.0", 38.8125, 29.1250}, // KM48DM
  {"K.MARAS", "VHF", "Role", "Analog", 145.625, "Yok", "88.5", 37.5625, 36.8750}, // KM87KP
  {"K.MARAS", "VHF", "Role", "Analog", 145.750, "Yok", "77.0", 37.5625, 36.8750}, // KM87KP
  {"K.MARAS", "VHF", "Role", "Analog", 145.775, "Yok", "123.0", 37.5625, 36.8750}, // KM87KP
  {"K.MARAS", "UHF", "Role", "Analog", 439.2375, "Yok", "123.0", 37.5625, 36.8750}, // KM87KP
  {"K.MARAS", "UHF", "Role", "Analog", 439.2625, "Yok", "88.5", 37.5625, 36.8750}, // KM87KP
  {"K.MARAS", "VHF", "APRS", "Sayisal", 144.800, "Yok", "Yok", 37.5625, 36.8750}, // KM87KP
  {"FETHIYE", "VHF", "Role", "Analog", 145.675, "Yok", "88.5", 36.6042, 29.1250}, // KM46OM
  {"MUGLA", "VHF", "Role", "Analog", 145.725, "Yok", "88.5", 37.2292, 28.2917}, // KM47FE
  {"DALAMAN", "UHF", "Role", "Analog", 439.175, "Yok", "88.5", 36.7292, 28.7917}, // KM46KU
  {"FETHIYE", "UHF", "Role", "Analog", 439.375, "Yok", "123.0", 36.6042, 29.1250}, // KM46OM
  {"FETHIYE", "UHF", "Role", "Analog", 439.375, "Yok", "88.5", 36.6458, 29.1250}, // KM46MT
  {"MUGLA", "UHF", "Role", "Analog", 439.425, "Yok", "123.0", 37.2292, 28.2917}, // KM47FE
  {"FETHIYE", "VHF", "APRS", "Sayisal", 144.800, "Yok", "Yok", 36.6458, 29.1250}, // KM46MT
  {"FETHIYE", "VHF", "APRS", "Sayisal", 144.800, "Yok", "Yok", 36.6042, 29.1250}, // KM46OM
  {"MUGLA", "VHF", "APRS", "Sayisal", 144.800, "Yok", "Yok", 36.9375, 28.1250}, // KM46DV
  {"MUGLA", "VHF", "APRS", "Sayisal", 144.800, "Yok", "Yok", 37.2292, 28.2917}, // KM47FE
  {"ORDU", "VHF", "Role", "Analog", 145.600, "Yok", "88.5", 40.8958, 38.4583}, // KN90BM
  {"ORDU", "VHF", "Role", "Analog", 145.700, "Yok", "88.5", 41.2292, 37.8750}, // KN81UE
  {"ORDU", "UHF", "Role", "Analog", 439.250, "Yok", "88.5", 40.9375, 38.3750}, // KN90AW
  {"ORDU", "VHF", "APRS", "Sayisal", 144.800, "Yok", "Yok", 40.9375, 38.3750}, // KN90AW
  {"ORDU", "VHF", "APRS", "Sayisal", 144.800, "Yok", "Yok", 41.2292, 37.9583}, // KN81VB
  {"ORDU", "VHF", "APRS", "Sayisal", 144.800, "Yok", "Yok", 40.8958, 38.4583}, // KN90BM
  {"SAKARYA", "VHF", "Role", "Analog", 145.775, "Yok", "88.5", 40.8125, 30.7083}, // KN50JT
  {"SAKARYA", "UHF", "Role", "Analog", 439.200, "Yok", "88.5", 40.7292, 30.1250}, // KN50DS
  {"SAKARYA", "UHF", "Role", "Analog", 439.225, "Yok", "88.5", 40.7292, 30.1250}, // KN50DS
  {"SINOP", "UHF", "Echolink", "Analog", 144.900, "Yok", "Yok", 42.0208, 35.1250}, // KN72NA
  {"SINOP", "VHF", "APRS", "Sayisal", 144.800, "Yok", "Yok", 42.0208, 35.1250}, // KN72NA
  {"SIVAS", "VHF", "Role", "Analog", 145.700, "Yok", "88.5", 39.7292, 37.0417}, // KM89LS
  {"SIVAS", "UHF", "Role", "Analog", 439.175, "88.5", "88.5", 39.7292, 37.0417}, // KM89LS
  {"SIVAS", "UHF", "Role", "Analog", 439.400, "Yok", "88.5", 39.7292, 37.0417}, // KM89LS
  {"SIVAS", "UHF", "Role", "Analog", 439.400, "88.5", "88.5", 39.7292, 37.0417}, // KM89LS
  {"TEKIRDAG", "UHF", "Role", "Analog", 439.375, "74.4", "74.4", 41.1458, 27.4583}, // KN31VD
  {"TEKIRDAG", "UHF", "Role", "Analog", 439.4125, "77.0", "77.0", 41.1458, 27.6250}, // KN31XH
  {"TOKAT", "VHF", "Role", "Analog", 145.750, "Yok", "88.5", 40.3125, 36.3750}, // KN80GH
  {"TOKAT", "UHF", "Role", "Analog", 439.150, "88.5", "88.5", 40.3958, 36.4583}, // KN80GQ
  {"TOKAT", "UHF", "Role", "Analog", 439.225, "Yok", "88.5", 40.3125, 36.3750}, // KN80GH
  {"TOKAT ZILE", "UHF", "Role", "Analog", 439.175, "88.5", "88.5", 40.3125, 35.8750}, // KN70WI
  {"USAK", "VHF", "Role", "Analog", 145.675, "88.5", "88.5", 38.6875, 29.4583}, // KM48OS
  {"ZONGULDAK", "VHF", "Role", "Analog", 145.625, "Yok", "88.5", 41.2292, 31.8750}, // KN61BK
  {"AKSARAY", "UHF", "Role", "Analog", 439.1625, "131.8", "131.8", 38.3125, 33.8750}, // KM78AI
  {"AKSARAY", "UHF", "Echolink", "Analog", 439.1625, "131.8", "131.8", 38.3125, 33.8750}, // KM78AI
  {"KARAMAN", "VHF", "Role", "Analog", 145.650, "88.5", "88.5", 37.1875, 33.2917}, // KM67NJ
  {"KARAMAN", "UHF", "Echolink", "Analog", 145.650, "88.5", "88.5", 37.1875, 33.2917}, // KM67NJ
  {"KARAMAN", "VHF", "APRS", "Sayisal", 144.800, "Yok", "Yok", 37.1875, 33.2917}, // KM67NJ
  {"BARTIN", "VHF", "Role", "Analog", 145.600, "Yok", "88.5", 41.6042, 32.4583}, // KN61EO
  {"BARTIN", "UHF", "Echolink", "Analog", 144.950, "Yok", "88.5", 41.6042, 32.4583}, // KN61EO
  {"BARTIN", "VHF", "APRS", "Sayisal", 144.800, "Yok", "Yok", 41.6042, 32.4583}, // KN61EO
  {"BARTIN", "UHF", "Cross-Role", "Analog", 433.450, "Yok", "88.5", 41.5625, 32.3750}, // KN61CP
  {"BARTIN", "UHF", "Cross-Role", "Analog", 433.475, "Yok", "88.5", 41.6458, 32.4583}, // KN61ES
  {"KARABUK", "VHF", "Role", "Analog", 145.6125, "Yok", "88.5", 41.2292, 32.7083}, // KN61IF
  {"KARABUK", "VHF", "Role", "Analog", 145.650, "Yok", "88.5", 41.1875, 32.6250}, // KN61HI
  {"KARABUK", "VHF", "Role", "Analog", 145.675, "Yok", "100.0", 40.9792, 32.4583}, // KN61DE
  {"KARABUK", "VHF", "Role", "Analog", 145.700, "Yok", "88.5", 41.2292, 32.6250}, // KN61IA
  {"KARABUK", "VHF", "Role", "Analog", 145.775, "82.5", "82.5", 40.9375, 32.3750}, // KN61DB
  {"KARABUK", "UHF", "Role", "Analog", 439.175, "88.5", "88.5", 41.2292, 32.6250}, // KN61IA
  {"KARABUK", "UHF", "Role", "Analog", 439.250, "Yok", "88.5", 41.2292, 32.6250}, // KN61IA
  {"KARABUK", "VHF", "Echolink", "Analog", 144.975, "Yok", "88.5", 41.2292, 32.7083}, // KN61IF
  {"KARABUK", "VHF", "Echolink", "Analog", 145.700, "Yok", "88.5", 41.2292, 32.7083}, // KN61IF
  {"KARABUK", "VHF", "APRS", "Sayisal", 144.800, "Yok", "Yok", 41.2292, 32.6250}, // KN61IA
  {"DUZCE", "VHF", "Role", "Analog", 145.750, "Yok", "82.5", 40.8542, 31.2083}, // KN50MW
  {"DUZCE", "VHF", "APRS", "Sayisal", 144.800, "Yok", "Yok", 40.8542, 31.1250}, // KN50MR
  {"DUZCE", "VHF", "APRS", "Sayisal", 144.800, "Yok", "Yok", 40.8958, 31.2917}  // KN50NT
};

const int role_sayisi = sizeof(role_veritabani) / sizeof(Role);

#endif
