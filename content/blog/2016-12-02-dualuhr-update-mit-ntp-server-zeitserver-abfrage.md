+++
title = "Dualuhr Update mit NTP-Server (Zeitserver) - Abfrage"
date = 2016-12-02T09:17:39Z
author = "typ_o"
path = "/blog/2016/12/02/dualuhr-update-mit-ntp-server-zeitserver-abfrage"
+++
Die Dual-Uhr in der Lounge ist ein altes Projekt mit einem AVR und
[BASCOM](https://www.mcselec.com/?option=com_content&task=view&id=14&Itemid=41).
Diese Uhr gibt es in mehreren Varianten, u.A. auch
[so](https://www.youtube.com/watch?v=HVVzy0h6RqQ). (Das Gehäuse ist vom
Flohmarkt, vermutlich ein Röntgenfilmbetrachter, auf der Vorderseite
befand sich noch eine riesige Lupe auf einer Linearführung)

[![](/media/_uhr.serendipityThumb.jpg)](/media/_uhr.jpg)

Zeitbasis in der bisherigen Ausführung ist ein Timerinterrupt, das
funktioniert mit einer Abweichung von ca 1 min / a - allerdings nicht,
wenn jeden Abend der Strom ausgemacht wird. Deswegen ein Hard- und
Software-Update mit ESP8266.

[![](/media/_nodmcu.serendipityThumb.jpg)](/media/_nodmcu.jpg)

Ein [NodeMcu](https://nodemcu.com/index_en.html) wird via Arduino IDE
\[[1](https://www.esp8266.com/viewforum.php?f=25)\],
\[[2](https://github.com/esp8266/Arduino)\] mit ein paar Zeilen zur
Abfrage eines Zeitservers programmiert
([Quelle](https://www.arduinoclub.de/2016/05/07/arduino-ide-esp8266-ntp-server-timezone/)).
Dazu ein
[OLEDisplay](https://www.aliexpress.com/item/Free-Shipping-1Pcs-white-128X64-OLED-LCD-0-96-I2C-IIC-SPI-Serial-new-original/32389025950.html)
damit man auch was Nettes anzuschauen hat, mit einer Lib. von Adafruit
\[[1](https://github.com/adafruit/Adafruit_SSD1306)\],
\[[2](https://github.com/adafruit/Adafruit-GFX-Library)\],
\[[3](https://arduino-er.blogspot.de/2016/04/nodemcu-esp8266-to-display-on-128x64.html)\].
Weil das Dimmen mit dem ESP bei mehr als zwei Kanälen [Flackern mit sich
bringt](https://github.com/esp8266/Arduino/issues/836), habe ich als
Workaround [WS2801 serielle
LED](https://shop.led-studien.de/de/pixel-digital-dmx/pixel-ketten/rgb-pixel-50x50mm-inkl.-wannen-kabel)
eingesetzt, die ich von einem [alten
Projekt](https://www.youtube.com/watch?v=7NMdgT00_4U) noch übrig hatte.

[![](/media/_becher.serendipityThumb.jpg)](/media/_becher.jpg)

Das Programm aus der Vorlage habe ich nach Möglichkeit gegen Probleme
gesichert (Kein WiFi, kein Internet, NTP-Server nicht erreichbar) und um
den Wifi Manager erweitert, der beim ersten Start oder auf Knopfdruck
einen AP öffnet, damit die WiFi Zugangsdaten nicht hart in den Quelltext
codiert werden müssen.
[timeserver_OLED_055.1.ino](/media/timeserver_OLED_055.1.ino "timeserver_OLED_055.1.ino")
