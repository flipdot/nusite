+++
title = "Pimp my Arduino & Co."
date = 2014-01-25T14:48:22Z
author = "Aleks"
path = "/blog/2014/01/25/pimp-my-arduino-co"
+++
Ich musste in letzter Zeit ziemlich oft unterschiedliche Sensoren und
Aktoren mit Arduino ansteuern. Die meisten von ihnen haben einen
dreipoligen Anschluss - Signal, Vcc und Masse. Also habe ich überlegt
einen Adapterboard zu verwenden. Dann ist mir was eingefallen :)

![](/media/Wattuino-Con-Mod8.jpg)  

Die Zutaten

Arduino Pro Mini oder auch anderes Board, das die Anschlüsse am Rand der
Platine hat. In meinem Fall z.B. ein Arduino-kompatibles Wattuino Pro
Mini, 5V @ 16MHz.

- 28 dreipolige Stiftleisten
- 1 sechspolige Stiftleiste
- Silberdraht

Alle Stecker mit einem Pin in die signalführenden Pads einlöten. Der
sechspolige Stecker für einen FTDI Kabel darf natürlich auch nicht
vergessen werden.
![](/media/Wattuino-Con-Mod1.jpg)

![](/media/Wattuino-Con-Mod2.jpg)

Im nächsten Schritt werden mit Hilfe von Silberdraht alle mittleren Pins
(Vcc) und alle äußeren Pins (GND) untereinander verbunden bzw. verlötet.
Dabei wird der mittlere Silberdraht mit dem GND-Pin des sechspoligen
seriellen Stecker verbunden.

![](/media/Wattuino-Con-Mod4.jpg)

Die Vcc Schiene hängt erstmal in der Luft. Die Versorgungsspannung wird
mit einem Jumper gesetzt.
Den Jumper bei Vcc setzen damit an allen mittleren Pins die Vcc Spannung
anliegt.

![](/media/Wattuino-Con-Mod6.jpg)

Wenn der Jumper bei Vin statt Vcc gesetzt wird, liegt auf allen
mittleren Vcc Pins die Vin Spannung an.

![](/media/Wattuino-Con-Mod5.jpg)

Wenn das Board extern über Vin versorgt wird und der Jumper auf Vcc
gesetzt wurde, muss darauf geachtet werden, dass die angeschlossenen
Sensoren/Aktoren den maximal zulässigen Strom nicht überschreiten.

Genau so gilt es, wenn das Board extern über Vin versorgt wird und der
Jumper bei Vin gesetzt wurde, muss darauf geachtet werden, ob alle
angeschlossenen Sensoren etc. die Vin Spannung auch vertragen.

![](/media/Wattuino-Con-Mod8.jpg)

Eine weitere Konfiguration, die noch möglich ist, dass man das Board
extern versorgen möchte, allerdings auf der Vcc Schiene die 5V anliegen
sollen. Hier hat es ganz gut gepasst, dass der GND Pin direkt neben dem
Vin Pin liegt. Also hier die externe Versorgung anschließen und den
Jumper bei Vcc setzen.

Ist so bisschen verwirren, aber wenn man das mal aufgebaut hat, wird man
schnell verstehen wann und in welche Richtung der Strom fließt :D

Noch ein kleiner Tipp am Rande: an zwei Ecken wo der Silberdraht
verläuft, könnte man noch Kondensatoren anlöten z.B. 10µF
Elektrolytkondensator (auf Polung achten) und 100nF Keramikkondensator.
Dadurch kann man die Spannungseinbrüche etwas vermeiden, wenn zu viel
Peripherie dran hängt ;-)

Diese Modifikation lässt sich mit beinah jedem Board, das für
Steckbrettmontage gedacht ist, durchführen :)
