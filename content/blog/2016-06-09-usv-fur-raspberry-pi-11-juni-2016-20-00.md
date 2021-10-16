+++
title = "USV für raspberry Pi - 11. Juni 2016, 20:00"
date = 2016-06-09T18:15:00Z
author = "typ_o"
path = "/blog/2016/06/09/usv-fur-raspberry-pi-11-juni-2016-20-00"
+++
[![](https://flipdot.org/blog/uploads/usv.serendipityThumb.jpg)](https://flipdot.org/blog/uploads/usv.jpg)

Raspberry Pi einfach im Betrieb auszuschalten ist keine gute Idee - die
Foren sind voller Berichte über zerschossene SDCARDs. Wir wollen eine
Unterbrechungsfreie Stromversorgung für den Pi bauen (incl. PCB), die
den PI so lange versorgen kann, bis er ordentlich heruntergefahren ist
oder der Strom wieder da ist.

Schaltungsvorschlag:

[![](https://flipdot.org/blog/uploads/usv-supply.serendipityThumb.jpg)](https://flipdot.org/blog/uploads/usv-supply.jpg)

Der DC-Wandler ist eine China-Platine für ca. 3 EUR. Das bistabile
Relais hat zwei Spulen, eine zum Einschalten, eine zum Ausschalten.
Vorteil: Komplette Abschaltung der Elektronik, kein Ruhestromverbrauch.
Der ATTINY erfasst über den Spannungsteiler die Netzteilspannung. Fällt
das Netz weg, erhält der Pi ein Signal an einem GPIO um das [Shut Down
Script](https://flipdot.org/blog/archives/207-Shut-down-your-Raspberry-Pi-on-button-press-and-add-reset-function.html)
zu starten. Nach 2 Minuten schaltet der ATTINY das Relais ab, und damit
sich selbst und den Pi.

[![](https://flipdot.org/blog/uploads/usv-supply2.serendipityThumb.jpg)](https://flipdot.org/blog/uploads/usv-supply2.jpg)

[Reichelt-Warenkorb](https://www.reichelt.de/my/1222447) für Bauteile
und Akku (18,60 €). Den
[Schaltregler](https://www.dx.com/p/lm2596-digital-display-adjustable-step-down-voltage-regulator-module-dark-blue-360654)
gibts bei DX (2,63 €).
