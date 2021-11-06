+++
title = "A simple Touch Controller for resistive touch panels"
date = 2014-05-30T09:30:01Z
author = "typ_o"
path = "/blog/2014/05/30/a-simple-touch-controller-for-resistive-touch-panels"
+++
*Deutsche Version [weiter unten](#german-version)*

Flipdot member \[typ.o\] writes: There are more and more affordable TFT
displays for Raspberry Pi coming with a resistive touch panel like
[this](https://www.pollin.de/shop/dt/NTMwOTc4OTk-/Bauelemente_Bauteile/Aktive_Bauelemente/Displays/7_17_78_cm_Display_Set_mit_Touchscreen_LS_7T_HDMI_DVI_VGA_CVBS.html)
from german cheapo - supplier Pollin. I don't wanted to waste a USB
connector for the touch input and also I'm planning to use the display
with Python in text mode. Because I couldn't find a driver for this
usecase I decided to do my own stuff.

![](/media/touch_USB.jpg)

Original touch controller with USB to be replaced.

![](/media/touch_sch.jpg)

Here you have
[touch.zip](/media/touch.zip "touch.zip"),
containing the
[BASCOM](https://mcselec.com/index.php?option=com_frontpage&Itemid=1)
source for the Attiny85, corresponding HEX file, quick and dirty Python
test program and lcd.py module containing some VT100 shortcuts. The
Attiny is set to 8 Mhz internal RC clock and brownout detection for 2,7
V. It runs nicely with the 3V3 supply of the Pi and therefore doesn't
need a level shifter.

![](/media/touch_final.jpg)

Final touch controller on perfboard.

The controller in the first step connects the X-resistor-plane to VCC
and GND using port b3 and b1 and then measures the voltage at one
terminal of the Y-plane. This A/D-input also is connected to VCC via an
internal pullup resistor to acieve a full scale reading if no touch
(i.e. no connection between X and Y plane). Afterwards X and Y is
swapped and treated accordingly. The controller sends the x,y coordinate
as raw A/D-converter values. Calibration and calculation of touched
character position is done by the Python script. If you touch the
surface of the panel, there will be a "503,220" on the serial line for
example. If you remove your finger, the controller will transmit the
text "RELEASE". That'sall.
[KISS](https://en.wikipedia.org/wiki/KISS_principle).

## German Version

Inzwischen gibt\'s eine Menge bezahlbarer TFTs für den Pi, zum Beispiel
[das
da](https://www.pollin.de/shop/dt/NTMwOTc4OTk-/Bauelemente_Bauteile/Aktive_Bauelemente/Displays/7_17_78_cm_Display_Set_mit_Touchscreen_LS_7T_HDMI_DVI_VGA_CVBS.html)
von Pollin. Die Touch-Controller verbraten immer einen USB-Port, von
denen der Pi ja bloss zwei hat, und für den Textmodus auf der Konsole
habe ich auch noch keinen Treiber gefunden - was soll man da als
Text-Interface-Fan machen? Selber.

Der Controller legt zuerst die Anschlüsse der X-Widerstandsfläche an
+3,3 V und Masse, und guckt dann, ob auf einer der Y-Leitungen was kommt.
Das ist immer dann der Fall, wenn durch einen Findgerdruck sich die
beiden Folien berühren. Ohne Druck ist die Y-Folie offen. Damit ich
diesen Fall sauber erkennen kann, wird der A/D - Eingang vom Controller
mit einem internen Pullup auf Betriebsspannunge gezogen. Ohne Berührung
liefert die Messung dann Vollausschlag.

Für die Y-Folie wird\'s mit getauschten Rollen genau so gemacht.

Die Messwerte sendet der Controller ohne weitere Verarbeitung über die
serielle Schnittstelle. Bei einem Fingerdruck kommt dann beispielsweise
"503,220" mit 9600 bit/s. Macht man den Finger wieder weg, sendet der
Controller ein "RELEASE". Das ist schon alles.
[KISS](https://de.wikipedia.org/wiki/KISS-Prinzip).

im [touch.zip](/media/touch.zip "touch.zip") ist die Controller -
Firmare in BASCOM, das entsprechende kompilierte HEX File, ein krudes
Python Testprogramm mit einem kleinen Modul mit VT100 Befehlen, das ich
noch rumliegen hatte. \[flipdot mitglied typ.o\]
