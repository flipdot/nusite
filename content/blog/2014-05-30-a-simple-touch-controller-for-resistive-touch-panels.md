+++
title = "A simple Touch Controller for resistive touch panels"
date = 2014-05-30T09:30:01Z
author = "typ_o"
path = "/blog/2014/05/30/a-simple-touch-controller-for-resistive-touch-panels"
+++
([Hier gehts zur deutschen
Version](http://flipdot.org/blog/index.php?/archives/244-A-simple-Touch-Controller-for-resistive-touch-panels.html#extended))
Flipdot member \[typ.o\] writes: There are more and more affordable TFT
displays for Raspberry Pi coming with a resistive touch panel like
[this](http://www.pollin.de/shop/dt/NTMwOTc4OTk-/Bauelemente_Bauteile/Aktive_Bauelemente/Displays/7_17_78_cm_Display_Set_mit_Touchscreen_LS_7T_HDMI_DVI_VGA_CVBS.html)
from german cheapo - supplier Pollin. I don't wanted to waste a USB
connector for the touch input and also I'm planning to use the display
with Python in text mode. Because I couldn't find a driver for this
usecase I decided to do my own stuff.

![](https://flipdot.org/blog/uploads/touch_USB.jpg)

Original touch controller with USB to be replaced.

![](https://flipdot.org/blog/uploads/touch_sch.jpg)

Here you have
[touch.zip](https://flipdot.org/blog/uploads/touch.zip "touch.zip"),
containing the
[BASCOM](http://mcselec.com/index.php?option=com_frontpage&Itemid=1)
source for the Attiny85, corresponding HEX file, quick and dirty Python
test program and lcd.py module containing some VT100 shortcuts. The
Attiny is set to 8 Mhz internal RC clock and brownout detection for 2,7
V. It runs nicely with the 3V3 supply of the Pi and therefore doesn't
need a level shifter.

![](https://flipdot.org/blog/uploads/touch_final.jpg)

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
[KISS](http://en.wikipedia.org/wiki/KISS_principle).  
["A simple Touch Controller for resistive touch panels" vollständig
lesen](https://flipdot.org/blog/archives/244-A-simple-Touch-Controller-for-resistive-touch-panels.html#extended)
