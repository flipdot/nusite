+++
title = "Hardwarehack - Solarlampe mit Bewegungsmelder (Nicht immer an, nur bei Bewegung)"
date = 2018-09-15T21:47:42Z
author = "Baustel"
path = "/blog/2018/09/15/hardwarehack-solarlampe-mit-bewegungsmelder-nicht-immer-an-nur-bei-bewegung"
aliases = ["/blog/archives/415-Hardwarehack-Solarlampe-mit-Bewegungsmelder-Nicht-immer-an,-nur-bei-Bewegung.html"]
+++
Dieser kleine und günstige Wand/Treppen Solarstrahler von Aldi, kann
durch Durchtrennen einer Leiterbahn und Verbinden zweier Bauteile mit
einem Draht, zur sparsamen Lampe nur für das automatische Einschalten
bei detektierter Bewegung umgebaut werden.

[![](/media/716f80a420c556a4402daf16bf944be0b6263eb5_1_664x500.serendipityThumb.jpg)](/media/716f80a420c556a4402daf16bf944be0b6263eb5_1_664x500.jpg)

Ansonsten würde er Nachts immer gedimmt leuchten bis der Akku leer ist
oder die Sonne am anderen Tag genug scheint um die Entladung wieder
auszugleichen.

Dazu muß (siehe nachfolgendes Bild),

[![](/media/10460d4f87f3b6e370fbb8b5ee6399a33acdc377_1_690x200.serendipityThumb.jpg)](/media/10460d4f87f3b6e370fbb8b5ee6399a33acdc377_1_690x200.jpg)

beim 8-beinigen IC, die Leiterbahn nach dem Pin 7 aufgetrennt werden, so
dass keine Verbindung mehr von Pin7 zum SMD Widerstand R10 nahe des
Schalters mehr besteht.

Danach wird stattdessen Pin 6 direkt mit einem Draht an die linke Seite
des SMD Widerstandes R10 gelötet.
(Schwarzer Draht, Mitte)

Und siehe da, die solarbetrieben Lampe leuchtet wenn es darauf ankommt
und der PIR Sensor auslöst und nicht nur wenn es die Tage vorher Sonne
gab da sie ansonsten Nachts mit dauerhaft gedimmtem Licht leergelaufen
wäre.

[![](/media/de42042bcbc1651868e2f77557786f907271b52a_1_690x398.serendipityThumb.jpg)](/media/de42042bcbc1651868e2f77557786f907271b52a_1_690x398.jpg)
Innenansicht der Solarlampe

Der PIR Sensor läuft wie ursprünglich auch im Hellen immer mit.
Das Signal wird nur nicht weitergeleitet solange es hell ist.

Der Strahler bleibt entsprechend länger an, wenn sich während der 30 s
etwas bewegt.
Der Sensor retriggert den Timer.

Man kann diesen Strahler auch wunderbar als Microcontrollerzuhause
mißbrauchen.
Z.B. Atmegas (Arduino) laufen oft von 3 bis 5 V ohne weitere Probleme.

Modell 2, Solarpanel 5 V 80 mA, 6 SMD-LEDs Li-Ionen-Akku, 3,7 V, 800 mAh,
Dauerlicht (10--20 lm) bei Dunkelheit (80 lm) für 30 Sek. bei
Bewegungsmelder. z.B
https://weltderangebote.de/aldi-nord-solar-treppenstrahler/ ,
