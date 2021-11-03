+++
title = "Echtes VGA für den Raspberry Pi"
date = 2014-11-21T13:00:01Z
author = "typ_o"
path = "/blog/2014/11/21/echtes-vga-fur-den-raspberry-pi"
+++
Fand ich immer schade, dass der Pi nur HDMI liefert - [aber jetzt kann
er auch VGA](https://www.raspberrypi.org/gert-vga-adapter/), und all die
alten Monitore in unseren Kellern sind jetzt für Baustelzwecke zu
verwenden. Nötig ist allerdings ein RasPi Modell B+ oder A+, weil das
Widerstandsnetzwerk für die D/A - Wandlung (3x6bit = 262144 Farben) eine
Menge Ports braucht. Die verwendeten Ports sind nicht veränderbar,
deswegen fehlen leider sowohl I2C als auch die serielle Schnittstelle.

![](/media/vgapi03.serendipityThumb.jpg)

Obwohl Gert van Loo [in seiner Doku](https://github.com/fenlogic/vga666)
zu dieser Erweiterung schreibt "If you look  
very closely there is a slight pixel crawl", sehe ich da nichts -
einwandfreies Bild!

![](/media/vgapi00.serendipityThumb.jpg)

Die Farbwiedergabe hat mich überrascht. Eigentlich hatte ich jede Menge
Farbsäume erwartet, aber Fotos sehen ausgesprochen gut aus:

[![](/media/blue.serendipityThumb.JPG)](/media/blue.JPG)

(Dieses Foto vom Bildschirm gibt die Qualität nur annähernd wieder -
ohne Farbabgleich geht da natürlich nichts. In Echt \[TM\] isses
besser)

Verwendete Hardware: [VGA
Buchse](https://www.reichelt.de/High-Density-Steckverbinder/HD-15FW/3//index.html?ACTION=3&GROUPID=3209&ARTICLE=8506&SEARCH=HD%2015FW%20&OFFSET=500&WKID=0&)
([Belegung](https://www.theavguide.co.uk/view_page.php?page=18)), [B+
Proto Board](https://www.watterott.com/de/RPi-Proto-HAT) und die
[geeigneten
Widerstände](https://www.reichelt.de/1-4W-1-/2/index.html?&ACTION=2&LA=3&GROUPID=3074)
(1% Metallfilm)

![](/media/vgapi04.jpg)

Die Installation ist super simpel: Ein File in die Bootpartition
kopieren und ein Eintrag in der config.txt (Infos dazu von
[hier](https://elinux.org/RPiconfig)):

```
enable_dpi_lcd=1
display_default_lcd=1

# https://elinux.org/RPiconfig
# hdmi_mode=35 1280x1024 60 Hz
# hdmi_mode=36 1280x1024 75 Hz
# hdmi_mode=37 1280x1024 85 Hz
dpi_group=2
dpi_mode=36
```

Die im Video erwähnte Möglichkeit, den Pi mit HDMI _und_ VGA
gleichzeitig zu betreiben, habe ich in der Doku nicht gefunden\...
