
/*
  source of time server code:
  http://www.arduinoclub.de/2016/05/07/arduino-ide-esp8266-ntp-server-timezone/

  https://github.com/esp8266/Arduino/tree/master/libraries/ESP8266WiFi

  source of OLED code & lib:
  http://arduino-er.blogspot.de/2016/04/nodemcu-esp8266-to-display-on-128x64.html
  http://arduino-er.blogspot.de/2016/04/hello-world-nodemcu-esp8266-128x64-i2c.html

  source of serial controlable LED code & lib:
  https://github.com/adafruit/Adafruit-WS2801-Library

  source of WiFi manager (allow to config wifi if no credentials set or button pressed:
  https://github.com/tzapu/WiFiManager

  D0 - hartbeat 1 sec (onboard LED on NodeMcu
*/

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <WiFiUdp.h>
#include <TimeLib.h>  //by Paul Stoffregen, not included in the Arduino IDE !!!
#include <Timezone.h> //by Jack Christensen, not included in the Arduino IDE !!!

// wifi manager
#include <ESP8266WebServer.h>
#include <DNSServer.h>
#include <WiFiManager.h>          //https://github.com/tzapu/WiFiManager

// select wich pin will trigger the configuraton portal when set to LOW
// ESP-01 users please note: the only pins available (0 and 2), are shared
// with the bootloader, so always set them HIGH at power-up
#define TRIGGER_PIN D7

// OLED display
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>


// ----- serial controlled LEDs definitions ------------------------------------------------------
#include "Adafruit_WS2801.h"
#define dataPin D6
#define clockPin D5
#define stripLength 8
uint8_t prefix[] = {0x41, 0x64, 0x61, 0x00, 0x18, 0x4D};
Adafruit_WS2801 strip = Adafruit_WS2801(stripLength, dataPin, clockPin);
// logarithmic gamma corretion tables
// byte gamma_table_5[256] = {0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 4 , 4 , 4 , 4 , 4 , 4 , 4 , 4 , 4 , 5 , 5 , 5 , 5 , 5 , 5 , 5 , 5 , 6 , 6 , 6 , 6 , 6 , 6 , 6 , 7 , 7 , 7 , 7 , 7 , 8 , 8 , 8 , 8 , 8 , 8 , 9 , 9 , 9 , 9 , 10 , 10 , 10 , 10 , 10 , 11 , 11 , 11 , 11 , 12 , 12 , 12 , 12 , 13 , 13 , 13 , 14 , 14 , 14 , 15 , 15 , 15 , 16 , 16 , 16 , 17 , 17 , 17 , 18 , 18 , 19 , 19 , 19 , 20 , 20 , 21 , 21 , 21 , 22 , 22 , 23 , 23 , 24 , 24 , 25 , 25 , 26 , 26 , 27 , 28 , 28 , 29 , 29 , 30 , 31 , 31 , 32 , 33 , 33 , 34 , 35 , 35 , 36 , 37 , 38 , 38 , 39 , 40 , 41 , 42 , 43 , 43 , 44 , 45 , 46 , 47 , 48 , 49 , 50 , 51 , 52 , 53 , 54 , 55 , 56 , 58 , 59 , 60 , 61 , 62 , 64 , 65 , 66 , 68 , 69 , 70 , 72 , 73 , 75 , 76 , 78 , 79 , 81 , 83 , 84 , 86 , 88 , 89 , 91 , 93 , 95 , 97 , 99 , 101 , 103 , 105 , 107 , 109 , 111 , 114 , 116 , 118 , 120 , 123 , 125 , 128 , 130 , 133 , 136 , 138 , 141 , 144 , 147 , 150 , 153 , 156 , 159 , 162 , 165 , 169 , 172 , 175 , 179 , 182 , 186 , 190 , 194 , 197 , 201 , 205 , 209 , 214 , 218 , 222 , 227 , 231 , 236 , 240 , 245 , 250 , 255};
// byte gamma_table_4[256] = {0 , 0 , 0 , 0 , 0 , 0 , 0 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 4 , 4 , 4 , 4 , 4 , 4 , 4 , 4 , 5 , 5 , 5 , 5 , 5 , 5 , 6 , 6 , 6 , 6 , 6 , 6 , 7 , 7 , 7 , 7 , 7 , 8 , 8 , 8 , 8 , 8 , 9 , 9 , 9 , 9 , 9 , 10 , 10 , 10 , 10 , 11 , 11 , 11 , 11 , 12 , 12 , 12 , 12 , 13 , 13 , 13 , 13 , 14 , 14 , 14 , 15 , 15 , 15 , 16 , 16 , 16 , 16 , 17 , 17 , 18 , 18 , 18 , 19 , 19 , 19 , 20 , 20 , 20 , 21 , 21 , 22 , 22 , 23 , 23 , 23 , 24 , 24 , 25 , 25 , 26 , 26 , 27 , 27 , 28 , 28 , 29 , 29 , 30 , 30 , 31 , 31 , 32 , 33 , 33 , 34 , 34 , 35 , 36 , 36 , 37 , 38 , 38 , 39 , 40 , 40 , 41 , 42 , 42 , 43 , 44 , 45 , 46 , 46 , 47 , 48 , 49 , 50 , 50 , 51 , 52 , 53 , 54 , 55 , 56 , 57 , 58 , 59 , 60 , 61 , 62 , 63 , 64 , 65 , 66 , 67 , 68 , 70 , 71 , 72 , 73 , 74 , 76 , 77 , 78 , 80 , 81 , 82 , 84 , 85 , 86 , 88 , 89 , 91 , 92 , 94 , 95 , 97 , 99 , 100 , 102 , 103 , 105 , 107 , 109 , 110 , 112 , 114 , 116 , 118 , 120 , 122 , 124 , 126 , 128 , 130 , 132 , 134 , 136 , 139 , 141 , 143 , 146 , 148 , 150 , 153 , 155 , 158 , 160 , 163 , 166 , 168 , 171 , 174 , 177 , 179 , 182 , 185 , 188 , 191 , 194 , 198 , 201 , 204 , 207 , 211 , 214 , 217 , 221 , 224 , 228 , 232 , 235 , 239 , 243 , 247 , 251 , 255};
// byte gamma_table_3[256] = {0 , 0 , 0 , 0 , 1 , 1 , 1 , 1 , 1 , 2 , 2 , 2 , 2 , 2 , 2 , 3 , 3 , 3 , 3 , 3 , 4 , 4 , 4 , 4 , 4 , 5 , 5 , 5 , 5 , 5 , 6 , 6 , 6 , 6 , 7 , 7 , 7 , 7 , 8 , 8 , 8 , 8 , 9 , 9 , 9 , 9 , 10 , 10 , 10 , 10 , 11 , 11 , 11 , 12 , 12 , 12 , 13 , 13 , 13 , 13 , 14 , 14 , 14 , 15 , 15 , 15 , 16 , 16 , 16 , 17 , 17 , 18 , 18 , 18 , 19 , 19 , 19 , 20 , 20 , 21 , 21 , 21 , 22 , 22 , 23 , 23 , 24 , 24 , 24 , 25 , 25 , 26 , 26 , 27 , 27 , 28 , 28 , 29 , 29 , 30 , 30 , 31 , 31 , 32 , 32 , 33 , 33 , 34 , 34 , 35 , 36 , 36 , 37 , 37 , 38 , 39 , 39 , 40 , 40 , 41 , 42 , 42 , 43 , 44 , 44 , 45 , 46 , 46 , 47 , 48 , 49 , 49 , 50 , 51 , 52 , 52 , 53 , 54 , 55 , 55 , 56 , 57 , 58 , 59 , 60 , 60 , 61 , 62 , 63 , 64 , 65 , 66 , 67 , 68 , 69 , 70 , 71 , 72 , 73 , 74 , 75 , 76 , 77 , 78 , 79 , 80 , 81 , 82 , 83 , 84 , 86 , 87 , 88 , 89 , 90 , 92 , 93 , 94 , 95 , 97 , 98 , 99 , 101 , 102 , 103 , 105 , 106 , 108 , 109 , 110 , 112 , 113 , 115 , 116 , 118 , 119 , 121 , 123 , 124 , 126 , 127 , 129 , 131 , 132 , 134 , 136 , 138 , 139 , 141 , 143 , 145 , 147 , 149 , 151 , 153 , 155 , 156 , 158 , 161 , 163 , 165 , 167 , 169 , 171 , 173 , 175 , 178 , 180 , 182 , 184 , 187 , 189 , 192 , 194 , 196 , 199 , 201 , 204 , 206 , 209 , 212 , 214 , 217 , 220 , 223 , 225 , 228 , 231 , 234 , 237 , 240 , 243 , 246 , 249 , 252 , 255};

// gamma_table_3[256] selected:
byte gamma_table[256] = {0 , 0 , 0 , 0 , 1 , 1 , 1 , 1 , 1 , 2 , 2 , 2 , 2 , 2 , 2 , 3 , 3 , 3 , 3 , 3 , 4 , 4 , 4 , 4 , 4 , 5 , 5 , 5 , 5 , 5 , 6 , 6 , 6 , 6 , 7 , 7 , 7 , 7 , 8 , 8 , 8 , 8 , 9 , 9 , 9 , 9 , 10 , 10 , 10 , 10 , 11 , 11 , 11 , 12 , 12 , 12 , 13 , 13 , 13 , 13 , 14 , 14 , 14 , 15 , 15 , 15 , 16 , 16 , 16 , 17 , 17 , 18 , 18 , 18 , 19 , 19 , 19 , 20 , 20 , 21 , 21 , 21 , 22 , 22 , 23 , 23 , 24 , 24 , 24 , 25 , 25 , 26 , 26 , 27 , 27 , 28 , 28 , 29 , 29 , 30 , 30 , 31 , 31 , 32 , 32 , 33 , 33 , 34 , 34 , 35 , 36 , 36 , 37 , 37 , 38 , 39 , 39 , 40 , 40 , 41 , 42 , 42 , 43 , 44 , 44 , 45 , 46 , 46 , 47 , 48 , 49 , 49 , 50 , 51 , 52 , 52 , 53 , 54 , 55 , 55 , 56 , 57 , 58 , 59 , 60 , 60 , 61 , 62 , 63 , 64 , 65 , 66 , 67 , 68 , 69 , 70 , 71 , 72 , 73 , 74 , 75 , 76 , 77 , 78 , 79 , 80 , 81 , 82 , 83 , 84 , 86 , 87 , 88 , 89 , 90 , 92 , 93 , 94 , 95 , 97 , 98 , 99 , 101 , 102 , 103 , 105 , 106 , 108 , 109 , 110 , 112 , 113 , 115 , 116 , 118 , 119 , 121 , 123 , 124 , 126 , 127 , 129 , 131 , 132 , 134 , 136 , 138 , 139 , 141 , 143 , 145 , 147 , 149 , 151 , 153 , 155 , 156 , 158 , 161 , 163 , 165 , 167 , 169 , 171 , 173 , 175 , 178 , 180 , 182 , 184 , 187 , 189 , 192 , 194 , 196 , 199 , 201 , 204 , 206 , 209 , 212 , 214 , 217 , 220 , 223 , 225 , 228 , 231 , 234 , 237 , 240 , 243 , 246 , 249 , 252 , 255};


// ----- WiFi client name definition ------------------------------------------------------
const char WiFiHostname[] = "typ-o-clock";


// ----- serial debug messages on/off definition ------------------------------------------------------
#define DBG_OUTPUT_PORT Serial
volatile bool debug = true;  // set = true for lots of debug informations


// ----- Hartbeat LED port definition ------------------------------------------------------
#define HARTBEAT    D0        // hartbeat


// ----- OLED definitions ------------------------------------------------------
#define OLED_RESET LED_BUILTIN  //4
Adafruit_SSD1306 display(OLED_RESET);
// D1 = SCL
// D2 = SDA
// 3,3 V
// GND
#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

unsigned long previousMillis = 0;
const long interval = 1000;           // telling time via serial every 1 seconds
byte failedAttempts = 0;              // counting failed NTP request for reboot
unsigned long resyncInterval = 600;    // resync n * interval. // 60 (with interval = 1000) = resync every 10 min
unsigned long resyncIntervalCounter = 0;
volatile bool wasConnected = false;


// ----- check if wifi connection is up -----------------------------------------
bool isConnected(long timeOutSec, bool show)
{
  timeOutSec = timeOutSec * 1000;
  int z = 0;
  if (show){
    display.clearDisplay();
    display.display();
    display.setTextSize(1);
    display.setTextColor(WHITE, BLACK);
    display.setCursor(0, 0);
    display.println(F("Checking WiFi"));
  }
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(200);
    if (debug)
    {
      DBG_OUTPUT_PORT.print(".");
      if (show){      
        display.print(".");
        display.display();
      }
    }
    if (z == timeOutSec / 200)
    {
      return false;
    }
    z++;
  }
  return true;
}


// ----- NTP, TIME & TIMEZONE ------------------------------------------------------
//UDP
WiFiUDP Udp;
unsigned int localPort = 123;

//NTP Server
char ntpServerName1[] = "ntp1.t-online.de";
char ntpServerName2[] = "time.nist.gov";

//Timezone
//Central European Time (Frankfurt, Paris)
TimeChangeRule CEST = { "CEST", Last, Sun, Mar, 2, 120 };     //Central European Summer Time
TimeChangeRule CET = { "CET ", Last, Sun, Oct, 3, 60 };       //Central European Standard Time
Timezone CE(CEST, CET);
TimeChangeRule *tcr;        //pointer to the time change rule, use to get the TZ abbrev
time_t utc, local;

const int NTP_PACKET_SIZE = 48; // NTP time is in the first 48 bytes of message
byte packetBuffer[NTP_PACKET_SIZE]; //buffer to hold incoming & outgoing packets


// ----- send an NTP request to the time server at the given address -------------------------
void sendNTPpacket(IPAddress &address)
{
  // set all bytes in the buffer to 0
  memset(packetBuffer, 0, NTP_PACKET_SIZE);
  // Initialize values needed to form NTP request
  // (see URL above for details on the packets)
  packetBuffer[0] = 0b11100011;   // LI, Version, Mode
  packetBuffer[1] = 0;     // Stratum, or type of clock
  packetBuffer[2] = 6;     // Polling Interval
  packetBuffer[3] = 0xEC;  // Peer Clock Precision
  // 8 bytes of zero for Root Delay & Root Dispersion
  packetBuffer[12] = 49;
  packetBuffer[13] = 0x4E;
  packetBuffer[14] = 49;
  packetBuffer[15] = 52;
  // all NTP fields have been given values, now
  // you can send a packet requesting a timestamp:
  Udp.beginPacket(address, 123); //NTP requests are to port 123
  Udp.write(packetBuffer, NTP_PACKET_SIZE);
  Udp.endPacket();
}


// ----- get NTP time from server in argument -------------------------------------------------
bool getNtpTime(char* ntpServerName)
{
  if (timeStatus() == timeSet)  // 2 = time has been set recently, 0 = time was never set
  {
    resyncIntervalCounter++;
    if (resyncIntervalCounter < resyncInterval)
    {
      return true;              // true = no need to resync
    }
  }

  // time has never been set or resyncInterval is over: get current time now from time server
  IPAddress ntpServerIP; // NTP server's ip address
  // function of this line?!?
  while (Udp.parsePacket() > 0); // discard any previously received packets
  // get server from the function argument
  WiFi.hostByName(ntpServerName, ntpServerIP);
  if (debug)
  {
    DBG_OUTPUT_PORT.println(F("Transmit NTP Request"));
    DBG_OUTPUT_PORT.print(ntpServerName);
    DBG_OUTPUT_PORT.print(": ");
    DBG_OUTPUT_PORT.println(ntpServerIP);

    display.clearDisplay();
    display.display();
    display.setTextSize(1);
    display.setTextColor(WHITE, BLACK);
    display.setCursor(0, 0);
    display.println(F("Transmit NTP Request"));
    display.println(ntpServerName);
    display.println(ntpServerIP);
    display.display();
    delay(3000);


  }
  sendNTPpacket(ntpServerIP);
  uint32_t beginWait = millis();
  while (millis() - beginWait < 1500) {
    int size = Udp.parsePacket();
    if (size >= NTP_PACKET_SIZE) {
      if (debug)
      {
        DBG_OUTPUT_PORT.println(F("Receive NTP Response"));
      }
      Udp.read(packetBuffer, NTP_PACKET_SIZE);  // read packet into the buffer
      unsigned long secsSince1900;
      // convert four bytes starting at location 40 to a long integer
      secsSince1900 = (unsigned long)packetBuffer[40] << 24;
      secsSince1900 |= (unsigned long)packetBuffer[41] << 16;
      secsSince1900 |= (unsigned long)packetBuffer[42] << 8;
      secsSince1900 |= (unsigned long)packetBuffer[43];
      setTime(secsSince1900 - 2208988800UL);
      //setTime(23, 55, 0, 30, 3, 2016); //simulate time for test
      resyncIntervalCounter = 0;
      return true;
    }
  }
  if (debug)
  {
    DBG_OUTPUT_PORT.println(F("FATAL ERROR : No NTP Response."));
  }
  return false; // return 0 if unable to get the time
}


void sPrintI00(int val)
{
  if (val < 10) {
    DBG_OUTPUT_PORT.print('0');
    display.print('0');
  }
  DBG_OUTPUT_PORT.print(val, DEC);
  display.print(val, DEC);
  return;
}


// ----- Print an integer in ":00" format (with leading zero).
//       Input value assumed to be between 0 and 99.
void sPrintDigits(int val)
{
  DBG_OUTPUT_PORT.print(':');
  display.print(':');
  if (val < 10) {
    DBG_OUTPUT_PORT.print('0');
    display.print('0');
  }
  DBG_OUTPUT_PORT.print(val, DEC);
  display.print(val, DEC);
}

// ----- Show time on OLEDisplay and LED string ------------------------------------------------------
void printTime(time_t t) {
  byte mint = minute(t);
  byte mint_dim = 0;
  byte hour12 = hour(t);

  display.clearDisplay();
  display.setTextSize(2);
  display.setCursor(0, 0);
  display.print(" ");

  //  DBG_OUTPUT_PORT.print(F("Time: "));
  sPrintI00(hour(t));
  sPrintDigits(minute(t));
  sPrintDigits(second(t));

  DBG_OUTPUT_PORT.println(' ');
  //display.println(" ");
  //display.display();

  // ----- Show hour values in 4 bit dual representation
  if (hour12 > 12) {
    hour12 = hour12 - 12;
  }

  if (hour12 == 0) {
    strip.setPixelColor(0, 0, 0, 0);     strip.setPixelColor(1, 0, 0, 0);    strip.setPixelColor(2, 0, 0, 0);    strip.setPixelColor(3, 0, 0, 0);
    strip.show();
  }

  if (hour12 == 1) {
    strip.setPixelColor(0, 0, 0, 0);     strip.setPixelColor(1, 0, 0, 0);    strip.setPixelColor(2, 0, 0, 0);    strip.setPixelColor(3, 50, 200, 0);
    strip.show();
  }

  if (hour12 == 2) {
    strip.setPixelColor(0, 0, 0, 0);     strip.setPixelColor(1, 0, 0, 0);    strip.setPixelColor(2, 50, 200, 0);    strip.setPixelColor(3, 0, 0, 0);
    strip.show();
  }

  if (hour12 == 3) {
    strip.setPixelColor(0, 0, 0, 0);     strip.setPixelColor(1, 0, 0, 0);    strip.setPixelColor(2, 50, 200, 0);    strip.setPixelColor(3, 50, 200, 0);
    strip.show();
  }

  if (hour12 == 4) {
    strip.setPixelColor(0, 0, 0, 0);     strip.setPixelColor(1, 50, 200, 0);    strip.setPixelColor(2, 0, 0, 0);    strip.setPixelColor(3, 0, 0, 0);
    strip.show();
  }

  if (hour12 == 5) {
    strip.setPixelColor(0, 0, 0, 0);     strip.setPixelColor(1, 50, 200, 0);    strip.setPixelColor(2, 0, 0, 0);    strip.setPixelColor(3, 50, 200, 0);
    strip.show();
  }

  if (hour12 == 6) {
    strip.setPixelColor(0, 0, 0, 0);     strip.setPixelColor(1, 50, 200, 0);    strip.setPixelColor(2, 50, 200, 0);    strip.setPixelColor(3, 0, 0, 0);
    strip.show();
  }

  if (hour12 == 7) {
    strip.setPixelColor(0, 0, 0, 0);     strip.setPixelColor(1, 50, 200, 0);    strip.setPixelColor(2, 50, 200, 0);    strip.setPixelColor(3, 50, 200, 0);
    strip.show();
  }

  if (hour12 == 8) {
    strip.setPixelColor(0, 50, 200, 0);     strip.setPixelColor(1, 0, 0, 0);    strip.setPixelColor(2, 0, 0, 0);    strip.setPixelColor(3, 0, 0, 0);
    strip.show();
  }

  if (hour12 == 9) {
    strip.setPixelColor(0, 50, 200, 0);     strip.setPixelColor(1, 0, 0, 0);    strip.setPixelColor(2, 0, 0, 0);    strip.setPixelColor(3, 50, 200, 0);
    strip.show();
  }

  if (hour12 == 10) {
    strip.setPixelColor(0, 50, 200, 0);     strip.setPixelColor(1, 0, 0, 0);    strip.setPixelColor(2, 50, 200, 0);    strip.setPixelColor(3, 0, 0, 0);
    strip.show();
  }

  if (hour12 == 11) {
    strip.setPixelColor(0, 50, 200, 0);     strip.setPixelColor(1, 0, 0, 0);    strip.setPixelColor(2, 50, 200, 0);    strip.setPixelColor(3, 50, 200, 0);
    strip.show();
  }

  if (hour12 == 12) {
    strip.setPixelColor(0, 50, 200, 0);     strip.setPixelColor(1, 50, 200, 0);    strip.setPixelColor(2, 0, 0, 0);    strip.setPixelColor(3, 0, 0, 0);
    strip.show();
  }

  // ----- Show minutes value on four LED, each covering 1/4 hour dimming up within 15 minutes
  if ((mint >= 0) && (mint <= 14)) {
    mint_dim = mint * 16;
    strip.setPixelColor(4, 0, 0, 0);     strip.setPixelColor(5, 0, 0, 0);    strip.setPixelColor(6, 0, 0, 0);    strip.setPixelColor(7, 0, 0, gamma_table[mint_dim]);
    strip.show();
  }

  if ((mint > 14) && (mint <= 29)) {
    mint_dim = mint - 15;
    mint_dim = mint_dim * 16;
    strip.setPixelColor(4, 0, 0, 0);     strip.setPixelColor(5, 0, 0, 0);    strip.setPixelColor(6, 0, 0, gamma_table[mint_dim]);    strip.setPixelColor(7, 0, 0, 255);
    strip.show();
  }

  if ((mint > 29) && (mint <= 44)) {
    mint_dim = mint - 30;
    mint_dim = mint_dim * 16;
    strip.setPixelColor(4, 0, 0, 0);     strip.setPixelColor(5, 0, 0, gamma_table[mint_dim]);    strip.setPixelColor(6, 0, 0, 255);    strip.setPixelColor(7, 0, 0, 255);
    strip.show();
  }

  if ((mint > 44) && (mint <= 59)) {
    mint_dim = mint - 45;
    mint_dim = mint_dim * 16;
    strip.setPixelColor(4, 0, 0, gamma_table[mint_dim]);     strip.setPixelColor(5, 0, 0, 255);    strip.setPixelColor(6, 0, 0, 255);    strip.setPixelColor(7, 0, 0, 255);
    strip.show();
  }

}


// ----- set all LED on LED string to same colour ------------------------------------------------------
void setAllPixel(byte colour){
  for (int i = 0; i <= 7; i++) {
    strip.setPixelColor(i, colour, colour, colour);
    }
  strip.show();  
}


// ----- this function will be called if wifi manager was started ------------------------------------------------------
void configModeCallback (WiFiManager *myWiFiManager) {
  setAllPixel(50);
  display.clearDisplay();
  display.display();
  display.setTextSize(1);
  display.setTextColor(WHITE, BLACK);
  display.setCursor(0, 0);
  display.println("WIFI CONFIG:");
  display.println("");
  display.println("SSID: typ-o-clock");
  display.println("PASS: aaaabbbbcccc");
  display.display();
}


// ----- Setup, executed once on startup ------------------------------------------------------
void setup()
{
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.display();
  display.setTextSize(1);
  display.setTextColor(WHITE, BLACK);
  display.setCursor(0, 0);
  display.println("timeserver_OLED_055");
  display.println("Booting ...");
  display.println("");
  display.println("debug 38.400");  
  display.display();

  // initialise our LED strip
  strip.begin();
  // strip.setPixelColor(0, blue, red, green);
  // some time to wait until wifi is connected. impersonate flourescent lamp meanwhile
  setAllPixel(255);
  delay(50);
  setAllPixel(0);
  delay(800);
  
  setAllPixel(255);
  delay(50);
  setAllPixel(0);
  delay(440);

  setAllPixel(255);
  delay(50);
  setAllPixel(0);
  delay(200);

  setAllPixel(255);
  
  pinMode(TRIGGER_PIN, INPUT);      // if pin = 0 start wifi config
  pinMode(HARTBEAT, OUTPUT);        // HARTBEAT pin as output.
  digitalWrite(HARTBEAT, HIGH);     // turn HARTBEAT led off.

  DBG_OUTPUT_PORT.begin(38400);

  if (debug) {
    Serial.setDebugOutput(true);    // wifi lib will give debug informations
  }
  else {
    Serial.setDebugOutput(false);
  }

  if (isConnected(30, true)) {            // try 30 seconds to connect to wifi access point
    wasConnected = true;
    Udp.begin(localPort);
    if (debug)
    {
      DBG_OUTPUT_PORT.println(F("Starting UDP"));
      DBG_OUTPUT_PORT.print(F("Local port: "));
      DBG_OUTPUT_PORT.println(Udp.localPort());
      DBG_OUTPUT_PORT.println(F("waiting for sync"));
    }
  }
  /* add setup code here */
}

// ----- Main loop ------------------------------------------------------
void loop()
{
  // is configuration portal requested?
  if ( digitalRead(TRIGGER_PIN) == LOW ) {
    WiFiManager wifiManager;
    // define function to be called if wifi manager was started
    wifiManager.setAPCallback(configModeCallback);
    wifiManager.setTimeout(300);
    if (!wifiManager.startConfigPortal("typ-o-clock", "aaaabbbbcccc")) {
      Serial.println("failed to connect and hit timeout");
      delay(3000);
      //reset and try again, or maybe put it to deep sleep
      ESP.reset();
      delay(5000);
    }
    //if you get here you have connected to the WiFi
    Udp.begin(localPort);
  }
  
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval)
  {
    previousMillis = currentMillis;
    if (!isConnected(10, false) && wasConnected)
    {
      ESP.restart();
    }

    // get current time. if > 2 fails, then reboot
    if (!getNtpTime(ntpServerName1)) {
      failedAttempts++;
      // server 1 no success, try backup server
      if (!getNtpTime(ntpServerName2)) {
        failedAttempts++;
      }
      else {
        failedAttempts = 0;
      }
    }
    else {
      failedAttempts = 0;
    }

    if (failedAttempts >= 2) {
      delay(3000);
      //reset and try again, or maybe put it to deep sleep
      ESP.reset();
      delay(5000);
    }

    local = CE.toLocal(now(), &tcr);
    printTime(local);

    display.setTextSize(1);
    display.setTextColor(WHITE, BLACK);
    display.setCursor(0, 16);
    display.println("");
    display.println(WiFi.SSID());
    display.println("");
    display.print("Signal   : "); 
    display.print(WiFi.RSSI());
    display.println(" dBm");
    display.print("Next Sync: ");  
    display.print(resyncInterval-resyncIntervalCounter);
    display.println(" s");    
    display.display();

    digitalWrite(HARTBEAT, LOW);          // turn the HARTBEAT-LED on.
    delay(50);         // wait
    digitalWrite(HARTBEAT, HIGH);         // turn the HARTBEAT-LED off.
  }
  /* add main program code here */
}


