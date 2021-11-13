+++
title = "Drinks Storage"
+++

Das Projekt *Drinks Storage* versucht, den Nachschub an Mate vollkommen
zu automatisieren. Dafür werden auf einzelnen, sortenreinen
Getränkekistenstapeln die Anzahl der sich darauf befindlichen Kisten
gemessen. Ein Programm prüft regelmäßig, ob noch genug Getränke
vorhanden sind und überprüft das an Hand einer Soll-Zustandsliste. Wenn
genug Kisten für eine Bestellung zusammengekommen sind, wird diese an
den CEOB (Chief Executive Of Boozyness) übermittelt der die Bestellung
dann prüft. Falls die Maschinen alles richtig gemacht haben, kann die
Bestellung an den Getränkelieferanten gemailt werden. Dieser kann dann
mit eigenem Gebäudezugang die Getränke nachfüllen.

Historische Daten der Getränkewaagen sind im
[Grafana](Grafana) zu finden, wobei man auch dem Lieferanten
live aus der Ferne zuschauen kann, wie er Mate stapelt. In der Industrie
würde das Projekt wohl als Supply Chain Management für Spirituosen
benannt werden.

## Schema

Das folgende Diagramm soll helfen zu erklären, wie die einzelnen Teile
des Projekts ineinander greifen:

<!-- [`{{attachment:drinks-storage.png||width=100%}}`{=mediawiki}](Projekte/Drinks%20Storage?action=AttachFile&do=get&target=drinks-storage.png) -->

*Datei auch als [.dia-Datei](attachment:drinks-storage.dia)
vorhanden*

### Waagen

#### Video

<!-- [`{{attachment:vimeo-link.png||width=800}}`{=mediawiki}](https://vimeo.com/234878854) -->

Auf dem Video sollte gut zu erkennen sein, wie die MQTT-Nachrichten bei
einer Veränderung der Kastenanzahl eintreffen.

#### Frästeil

<!-- {{attachment:kisten-schema.png||width=100%}} -->

Die aktuelle Iteration der Waagen sind beidseitig aus MDF-Platten
gefräst und mit einigen Millimetern Spiel auf die einzelnen Kistenböden
angepasst. Auf der Unterseite sind passgenaue Taschen für die jeweils 4
[Gewichtssensoren](https://www.aliexpress.com/item/1/32811319141.html).
Gefräste Kabelkanäle führen die Kabel von den Sensoren in die Mitte und
von dort aus gebündelt zur Seite. An der Seite ist ein Einschub für ein
3D-Druck-Gehäuse in dem sich das Sensor-Board befindet.

<!-- {{attachment:magic.gif||width=640}} -->

Erstellt wurde das 3D-Modell mit
[Rhino](https://www.rhino3d.com/). Die Konturlinien für die
einzelnen Kistenböden sind aus den jeweiligen abfotografierten Kisten
entstanden. Oben sieht man die schematische Nachzeichnung. Hier
3D-Frästeile ohne den seitlichen Einschub

<!-- {{attachment:aschorle_unten.jpg||width=100%}} -->

<!-- {{attachment:aschorle_oben.jpg||width=100%}} -->

Und die fertig gefrästen Teile:

<!-- {{attachment:mio_xxx.jpg||width=100%}} -->

#### 3D-Druck-Gehäuse

Das Gehäuse für das PCB ist 3D-gedruckt auf unserem space-eigenen
[3D-Drucker](3D-Drucker). Es war schwerer erfolgreich zu
drucken als anfangs gedacht. Das liegt hauptsächlich daran, dass das
nicht fehlen dürfende flipdot-Logo zu häufigen Überhängen an der
Oberfläche führt. Das 3D-Modell wurde in
[Rhino](https://www.rhino3d.com/) erstellt und von dort aus
als `.stl`-Datei exportiert. Die `.stl`-Datei wurde dann in
[Cura](https://ultimaker.com/en/products/ultimaker-cura-software)
importiert wovon dann die zu druckende `.gcode`-Datei erstellt wurde.

<!-- {{attachment:3d_druck_1.jpg||width=100%}} -->

<!-- {{attachment:einschub.jpg||width=100%}} -->

#### Board

Auf dem kruden selbstgeätzten und -gebohrten PCB befindet sich ein ESP
und ADC. Das Board prüft regelmäßig die Werte der Gewichtssensoren und
bildet den Median über mehrere Messpunkte. Dieser Median hat den Vorteil
gegenüber einem gemittelten Wert, dass er statistisch robust ist. Der
Median wird mit einem Zähler an bereits erfolgreich übertragenen Paketen
im MQTT-Topic `sensors/cellar/drinks_scale_measurements_raw`
veröffentlicht. Der Zähler bringt den Vorteil, dass man aus der Ferne
erkennen kann, wenn eine Waage zu hohen Packet Loss hat oder eine
schlechte Stromversorgung. Gesendet wird durch eine etwa halben Meter
dicke tragende Wand aus Backstein, bzw. durch eine dicke Eisentür. Der
daraus resultierende Packet Loss stellt allerdings kein Problem dar, da
die Daten nicht zeitkritisch sind.

<!-- {{attachment:lol_breakout.png||width=100%}} -->

<!-- {{attachment:breakout_haufen.jpg||width=100%}} -->

### Datenpfad

#### Space-Intern

Der von den Waagen jeweils übertragene Sensorrohwert wird von einem
MQTT-Client ([`drinks-storage-mqtt` auf
Github](https://github.com/flipdot/drinks-storage-mqtt))
eingelesen. An Hand der Konfiguration wird erkannt, wievielen Kästen der
Sensorwert entspricht. Hierfür muss einmalig jede Waage einzeln mit
zuerst keinem Gewicht und danach mit möglichst vielen Kästen der
gleichen Sorte belastet werden. Die gemittelten Werte bieten einem zum
Einen einen Nullpunkt und zum andern das spezifische
[Tara](https://de.wikipedia.org/wiki/Tara_(Gewicht)) der
jeweiligen Getränkesorte angepasst auf den speziellen Sensor. Dieser
ermittelte Wert für die Anzahl der Kästen wird dann periodisch im
MQTT-Topic `sensors/cellar/drinks_crate_counts` veröffentlicht.

<!-- {{attachment:waage_mit_eichstein.jpg||width=100%}} -->

#### Web-Server

Das Projekt
[`iod-api-bridge`](https://github.com/flipdot/iod-api-bridge)
sort dafür, dass die Anzahl der Kästen an unsere
[Space-API](Space-API) übertragen wird, wo sie auch aus dem
Internet aus abrufbar sind.

#### Statistiken

Die nächste Station ist zum einen unsre
[Grafana](Grafana)-Instanz, die die Daten von der
[Space-API](Space-API) minütlich pollt und die historischen
Daten der Öffentlichkeit anbietet. Auf dem entsprechenden
[Dashboard](https://stats.flipdot.org/dashboard/db/drinks-storage)
findet man aktuelle Daten.

Bevor Grafana integriert war in das System wurde mit einem
[Python-Skript](https://github.com/flipdot/drinks-storage-mqtt/blob/master/plot-raw.py)
ein Mitschnitt des MQTT-Verkehrs der entsprechenden Channel analysiert.
Ziel der Analyse war festzustellen, ob temperaturbedingter Drift
vorhanden ist. An folgendem Plot kann man dabei erkennen, dass dem nicht
so ist. Da eine einzelne Kiste etwa einen rohen Sensorwert von 25k hat,
ist das Rauschen selbst bei `fritz_cola` zu vernachlässigen:

<!-- {{attachment:no_drift.png||width=100%}} -->

#### Bestellungen

Zum andern gibt es noch ein Skript
([drinks-storage-order](https://github.com/flipdot/drinks-storage-order)
auf Github) was täglich die von der API gepollten Daten überprüft. Dabei
wird der aktuelle Bestand mit einer Soll-Liste abgeglichen. Wenn dann
die insgesamte Anzahl der zu bestellenden Kästen einen Schwellwert
übersteigt, wird eine Bestellung per Mail Versand. Der PDF-Anhang für
unsre allererste Bestellung sah so aus:

<!-- {{attachment:erste-bestellung.png||width=100%}} -->

Diese wird von unserem CEOB (Chief Executive Of Boozyness)
entgegengenommen, auf Richtigkeit geprüft und anschliessend an den
Getränkehändler weitergereicht.

### Debugging

Die Waagen haben das Problem, dass sie regelmäßig neu tariert werden
müssen, da einige Sensordrift aufweisen. Das Problem wird bei genauer
[Analyse der
Rohwerte](https://stats.flipdot.org/d/000000023/drinks-storage-debug)
erkennbar. Der Sensordrift kann dadurch entstehen, dass die [Verkabelung
der
Verstärker](https://github.com/flipdot/drinks-storage-state#hardware)
eine lose Verbindung hat, was irgendwann mal zu prüfen ist.

#### Tarieren

Um die Waagen zu tarieren muss wie folgt vorgegangen werden:

1. [Github-Repo](https://github.com/flipdot/drinks-storage-mqtt) klonen
2. Betroffene Waagen leeren.
3. Werte aufnehmen
   ```
   mosquitto_sub -h mqtt.fd -t 'sensors/cellar/drinks_scale_measurements_raw' >> drinks-storage-$(date -I).log
   ```
4. Werte in einzelne Dateien pro Waage schreiben
   ```
   DRINKS_STORAGE_MQTT=/path/to/cloned/github/directory
   while read -r esp_id; do esp_int=$(printf "%i" "$esp_id"); grep $esp_int *.log | sed -r 's/.+scale_value":([0-9]+),".+/\1/' > $esp_id.values; done <<< $(grep -Eo '0x[0-9a-f]+' $DRINKS_STORAGE_MQTT/config.yaml)
   ```
5. Mittelwert ausgeben lassen
   ```
   for esp_id in *.values; do awk "{a+=\$1} END{printf "${esp_id%%.values} %i\n", a/NR}" $esp_id; done
   ```

Um jetzt den Wert für `crate_raw` zu berechnen, muss das obige
Vorgehen wiederholt werden mit `n` Kisten. Dann muss man im
Taschenrechner der Wahl jeweils folgendes berechnen:

```
(value_1st - value_2nd) / n_crates
```

Nach dem Tarieren muss nur ein entsprechender Commit für die
[Config-Datei](https://github.com/flipdot/drinks-storage-mqtt/blob/master/config.yaml)
(`config.yaml`) im Github-Repo erstellt und gepusht werden.

#### Deployment

Wenn die Waagen neu tariert wurden, muss neu deployt werden. Hierfür
muss man sich auf `power-pi.fd` verbinden, pullen und den Daemon neu
starten, in anderen Worten:

```
$ ssh pi@power-pi.fd
$ cd ~/iod/drinks-storage-mqtt
$ git pull
$ sudo systemctl restart drinks-storage-mqtt
```

#### MQTT-Fehlernachrichten

Nach erfolgreichem Deployment sollte auf Fehlernachrichten im Kanal
`errors` geprüft werden. In anderen Worten:

```
$ mosquitto_sub -h mqtt.fd -t "errors" -v
```

Wenn man Wasserfälle mag und mehr Noise sehen will, kann man auch alle
Kanäle prüfen:

```
$ mosquitto_sub -h mqtt.fd -t "#" -v
```
