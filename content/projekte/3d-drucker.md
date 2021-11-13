+++
title = "3D-Drucker"
+++

Unter-Seiten:

* [Autobedleveling](autobedleveling/)
* [Slicing](slicing/)

## Anleitung für Space Printer

Wir haben im Space einen 3D-Drucker stehen. Wenn du mit dem
Space-Drucker drucken willst, les hier einfach ein Mal den Artikel
durch.

Die folgende Anleitung führt dich Schritt für Schritt von der Idee bis
zum fertigen Druckteil.

## Nach dem Drucken:

- Filament in einer Länge von ca 50 cm über dem Druckkopf abschneiden
  und das Ende des Filaments durch das Befestigungsloch in der Rolle
  schieben und die Rolle wieder in den Eimer legen.
- Wenn man das Filament aus dem Drukkopf enfernen will heizt man den
  Kopf auf, schiebt das Filament erst ein kleines Stück nach unten in
  den Druckkopf hinein und zieht es dann schnell heraus.
- Wenn man versucht das Filament nach dem Aufheizen direkt heraus zu ziehen,
  verklebt es und man muss den Drukkopf auseinander bauen um es zu entfernen.
- Das Filament in den Eimern kann benutzt werden. Neben dem Drucker
  steht die Filamentspendendose.

## Software Zur Erstellung von 3D Modellen

Um mit einem 3D-Drucker zu drucken, benötigt man eine Software-Pipeline,
bei der am Ende eine
[GCode-Datei](https://en.wikipedia.org/wiki/G-code) erzeugt
wird. Diese Datei beinhaltet die Steuerbefehle, mit denen der Druckkopf
bewegt wird, und der Drucker allgemein weiss was zu tun ist.

Der Erste Schritt ist die Erstellung eines 3D-Modells

- Das Modell kann in einem beliebigen 3D-Modellierungsprogramms
  erstellt werden.
  - [FreeCAD](https://www.freecadweb.org/) (Cross platform)
  - [Blender](https://www.blender.org/download/) (Cross platform)
  - [Rhinoceros](http://www.rhino3d.com/download/) (Windows)
  - ...

- Alternativ kann auch ein fertiges Modell von einer Plattform
  heruntergeladen werden.
  - [<https://www.yeggi.com/>](https://www.flipdot.org/wiki/https://www.yeggi.com/)
    (Suchmaschine für 3D-Modelle)
  - <https://www.prusaprinters.org/prints> (Platform zum Austausch
    von 3D-Modellen)
  - <https://www.thingiverse.com/> (Platform zum Austausch von
    3D-Modellen)
  - ...

Bei funktionalen Teilen sind die Tolleranzen entscheidend. Bei kleinen
Abmessungen ist mit einre Tolleranz von 0,1mm (PrusaSlicer) bus 0,2mm
(Cura) pro Oberfläche zu rechnen. Bei großen Teilen können die
Tolleranzen entsprechend größer ausfallen. Es lohnt sich vor allem bei
Modellen, die man von einer Tauschplatvorm heruntergeladen hat, die
Tolleranzen zu prüfen. Für den nächsten Schritt wird eine
[Stereolithographie-Datei
(.stl)](https://en.wikipedia.org/wiki/STL_(file_format))
benötigt. Dieses Dateiformat ist am gebräuchlichsten. Alternativ kan
auch [Wavefront OBJ
(.obj)](https://de.wikipedia.org/wiki/Wavefront_OBJ)
verwendet werden.

## Slicing

Beim Slicing wird eine .stl Datei in eine .gcode Datei umgewandelt.
Dabei wird ein 3-Dimensionales Objekt in Anweisungen für den 3D-Drucker
umgerechnet. Dabei Berücksichtigt der Slicer die Mechanischen
Eigenschaften des Druckers und die Materialeigenschaften des Filaments.
Unser Drucker hat folgende eigenschaften: Bauraum: 220mm x 220mm x 230mm
(Länge, Breite, Höhe)

- Beheizbares Druckbett mit einer maximalen Temperatur von 75°C (Abschaltung bei 79°C)
- Bei PLA empfiehlt sich eine Druchbettemperatur von 55°C (60°C für die erste Schicht). PETG kann bei einer Druckbettemperatur von 75°C gedruckt werden.
- Ein Extruder mit einem Düsendurchmesser von 0,4 mm
- Der Düsendurchmesser bestimmt die Extrusionsweite. Extrusionsweite von 0,6mm  (0,45 mm bis 0,7) hat sich bewährt.
- Schichtstärke 0,1 mm bis 0,3 mm
- Eine geringe Schichtstärke verbessert die Oberfläche und verbessert das Druckverhalten bei Überhängen.  Bei dicken Schichten verkürzt sich die Druckzeit. Die Schichtstärke sollte maximal 50% der Extrusionsweiter betragen.
- Maximale Drucktemperatur 230°C (Abschaltung bei 250°C)
- Mit unsterem Drucker können PLA (200°C) und PETG (220°C) verdruckt werden.

Zum Slicen können Cura oder [PrusaSlicer](PrusaSlicer)
verwendet werden. Die Einrichtung des Slicers ist auf der folgenden
Seite beschrieben.
<https://www.flipdot.org/wiki/Projekte/3D-Drucker/Slicing>

Die fertige .gcode Datei wird auf eine Micro SD-Karte gespeichert und
die SD-Karte in den Drucker gesteckt. Lege einen Ordner mit deinem Namen
an und speichere deine Dateien in den Ordner. Dateien im
Stammverzeichniss der Karte dürfen gelöscht werden.

Das Lesegerät für SD-Karten liegt neben dem Drucker.

## Bedienung des 3D-Druckers

- Druckbett reinigen
- Vorheizen (Vorbereitung>Vorwärmen PLA>Vorwärmen PLA)  
  Das Druckbett und der Druckkopf werden auf die Betreibstemperatur aufgeheizt.
- Filament einlegen
- G-Code Datei auswählen
- SD-Karte erkennen  
  SD-Karte>Ordner>Druckteil.gcode Der Slicer ist so eingestellt, das als erstes
  das Druckbett vermessen wird. Danach würd die Düse entlüftet indem links vorne
  etwas Filament extrudiert wird. Danach streift der Drucker den Faden ab und
  beginnt einen Rand um das Druckteil zu drucken. Während der Rand gedruckt wird
  solltest du den Drucker genau beobachten. Wenn der Rand gut gedruckt wird ist
  die Wahrscheinlichkeit sehr hoch, das der Druck gelingt. Bleibe während des
  Druckvorgangs in Sichtweite des Druckers. Der Drucker darf nur unter Aufsicht
  betrieben werden.

## Fernbedienung des 3D-Druckers über Octoprint

- Einfach Drucker einschalten und kurz warten
- aus einem Browser im Netzwerk des Flipdots <http://octopi.fd> aufrufen

## Nach dem Drucken

- Filament in einer Länge von ca 50 cm über dem Druckkopf abschneiden
  und das Ende des Filaments durch das Befestigungsloch in der Rolle
  schieben und die Rolle wieder in den Eimer legen.
- Wenn man das Filament aus dem Drukkopf enfernen will heizt man den
  Kopf auf, schiebt das Filament erst ein kleines Stück nach unten in
  den Druckkopf hinein und zieht es dann schnell heraus.
- Wenn man versucht  das Filament nach dem Aufheizen direkt heraus zu ziehen, verklebt es und man muss den Drukkopf auseinander bauen um es zu entfernen.
- Das Filament in den Eimern kann benutzt werden. Neben dem Drucker
  steht die Filamentspendendose.

## Filament

- PLA  
  PLA ist der gebräuchlichsten Kunststoffe für 3D Druck. PLA ist etwas steifer als PETG und hat eine ähnliche Festigkeit. Es lässt sich mit Alleskleber und mit Sekundenkleber kleben.
- PETG  
  PETG lässt sich ähnlich leit drucken wie PLA, ist aber etwas Temperaturbeständiger als PLA und etwas elastischer. Es lässt sich mit Acetonhaltigem Alleskleber und Mit Sekundenkleber kleben. Bei der Verwendung von Sekundenkleber muss das Material mit Aceton vorbehandelt werden.

Klebstoffe

- Alleskleber  
  Mit Alleskleber lässt sich PLA und PETG kleben. Hierbei weden Festigkeiten von 5 bis 7N/mm² erreicht. Bei der Verklebung von PETG ist alleskleber mit Aceton zu bevorzugen. Die Trockenzeit beträgt bei Holz ca. einen Tag und bei PETG auf PETG eine Woche.`
- Sekundenkleber
- ungesunder Sekundenkleber
