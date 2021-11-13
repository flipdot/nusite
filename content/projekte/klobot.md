+++
title = "Klobot"
+++

Der klobot ist ein Teil der [Hackerspace Kybernetik](Neuland/Cyber/).

## Hacker

- Dennis (Projektmanagement)
- Wolfi (Lüfter)
- Jonas (Spiele Engine, Pi)
- Jaro (Kapazitiver Sensor, Arduino)
- Malte (Lüfter, Monitor, Papierzähler Gehäuse fräsen)
- Felix (google dreams)
- Helmut (blinkenbürste)
- Dino (Papierzähler Arduino)

## Aktueller Stand

- Industrielüfter bläst Gerüche aus dem Dach hinaus
- Bewegungsmelder (montiert, verkabelt, "Besetzt"-Status noch nicht)
- Monitor (in Sichthöhe montiert, verkabelt)
- Kabel für Türsensor (unangeschlossen)
- Berührungsfreies Interface mit Arduino! (unangeschlossen)
- Raspberry Pi mit VGA Adapter (vorerst mit [google
  dreams](http://deepdreamgenerator.com/) bespielt)
- Stromversorgung (Wanddurchbohrung)
- Angewärmte Zuluft aus Spülküche (mit 12V Ventilator, Bewegungsmelder
  gesteuert)
- Schwarzlicht für Cybertoilette (Bewegungsmelder gesteuert)

## Final Form

- Cooles Schwarzlicht für Cybertoilette *aktuell kaputt*
- Bewegungsmelder startet Lüfter, Spiel und Monitor.
- Klo-Highscore wird auch per Interface eingebbar
- Interface neben dem Klo zum Spielen des Klo-Spiels
- Türsensor an Klotür misst, ob abgeschlossen ist
- Leuchtschild zeigt "Besetzt"-Status im großen Raum
- Papierspender/-zähler meldet den Nachfüllbedarf und zählt mit
  Ultraschall
- Messung der Sitzungszeit. Wenn > 30 sec., nach dem Spülen
  Notification: "Bitte Toilette reinigen", um die Klobürste und um
  den WC - Reiniger herum blinken LED, bis beide aus ihren
  Sensorhalterungen entnommen und benutzt worden sind.

## Fehlende Komponenten

- <https://github.com/flipdot/shit> das Spiel
- Papierspender/-zähler (funktionierendes Design und Zählelektronik)
- 220V Relais, dass den Bewegungsmelder auslesen kann für Besetzt-Schild
- Drucktaster im Schloss
- ~~(vielleicht 2 Lüfter verbauen, die mit einem Y-Rohr Adapter addiert werden)~~
  stattdessen Zuluftventilator in Tür verbaut
- V Trichter (Diffusor) oberhalb vom Lüfter im Blechrohr (max. 10°,
  möglichst glatt -\> 3d Druck?)
- Anströmdüse vor dem Ventilator

<!--
\|\|`{{attachment:luefter.png|Lüfter|heigth="400px"}}`{=mediawiki}\|\|`{{attachment:papierzähler.png|Papierzähler|height="400px"}}`{=mediawiki}\|\|
\|\|Lüfter\|\|Papierzähler\|\|
-->

## Infos

- <http://www.trox-tlt.de/de2/service/download_center/structure/Fachartikel/07fachartikel_grundlagen_der_ventilatorentechnik.pdf>
  (siehe Seite 11)
- <http://www.druckverlust.de/Online-Rechner/Luft.html> (aktuell:
  scharfkantiges T-Stück nach oben auf dem Dach 200x200mm -\> zweimal
  50x200mm)
- Maltes Lüfter hat 130
  [cfm](https://en.wikipedia.org/wiki/Actual_cubic_feet_per_minute),
  der verbaute von Wolfi 160 cfm ([= 271
  m³/h](http://www.endmemo.com/sconvert/m3_hft3_min.php),
  Vgl. [100€ Baumarktlüfter 295
  m³/h](http://www.obi.de/decom/product/OBI_Ventilator_Air-Style_System_150/5168802))
- Klo plus Pissoir Raum ca. 10m³ (bei 160 cfm ca. 2:13 min. um die
  Toilettenluft komplett auszutauschen)
- Github Repository: <https://github.com/flipdot/shit>
