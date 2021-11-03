+++
title = "Dashboard mit Spacedaten"
date = 2015-02-06T22:21:15Z
author = "wegenerd"
path = "/blog/2015/02/06/dashboard-mit-spacedaten"
+++
Letztens ging unser neues Flipdot Dashboard an den Start. Auf unserem
Fernseher im Space können mittels des kleinen Bildschirms an der Tür
verschiedenste Messdaten des Spaces aufgerufen werden. Zurzeit ist dies
nur die Anzahl der Geräte im WLAN sowie unser Stromverbrauch, für die
Zukunft sind Raumtemperatur, Netzwerktraffic sowie der Getränkefüllstand
geplant.

Bereitgestellt werden die angezeigten Daten über
<https://api.flipdot.org/> (der Stromverbrauch wird
demnächst ebenfalls darüber abrufbar sein, zurzeit noch via
<https://infragelb.de/flipdot-power/>). Jede Minute wird ein Cronjob
angestoßen, welcher die Daten abholt ([GitHub
Gist](https://gist.github.com/swege/ee89056fc857a3f37e05)). Dieser
schreibt die empfangenen Daten in eine [InfluxDB](https://influxdb.com)
Datenbank, welche automatisch Zeitstempel einfügt.

Das Dashboard selber ist eine JavaScript Anwendung namens
[Grafana](https://grafana.org). In dieser wurden entsprechende Querys und
verschiedene Ansichten konfiguriert.

Die verschiedenen Ansichten sind über das pi Display erreichbar. Die
dort laufende Anwendung ist unter
<https://github.com/flipdot/flipdot-power-consumption> zu finden.

Die Seite kann auch von Zuhause über
[flipdot.wegenerd.de](https://flipdot.wegenerd.de) aufgerufen werden.
Viel Spaß damit!

![](https://i.imgur.com/vQmSDus.png)
