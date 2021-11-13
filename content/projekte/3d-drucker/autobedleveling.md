+++
title = "3D-Drucker Autobedleveling"
+++

Bei 3D-Druckern ist es wichtig, dass die Druckdüse bei der ersten
Schicht den Richtigen Abstand zum Druckbett hat. Mann kann das Druckbett
manuell justieren aber genauer geht es mit einem Sensor.

Vor dem Druck tastet der 3D Drucker das Druckbett an 9 Puntken ab und
erstellt eine Höhenkarte des Druckbetts.

Die Abtastung des Druckbetts wird automatisch durch den Befehl "G29;
Bed Leveling" gestartet.

Falls die Düse bei der ersten Schicht nicht den richtigen Abstand zu dem
Druckbett hat kann der Abstand im Menü eingestellt werden.

- Starte den Druck und beobachte den Rand, der um das Druckobjekt
  gedruckt wird. Falls die Düse zu dicht an dem Druckbett ist drehst
  du beide Spindeln der Z-Achse um eine raste nach rechts.
- Dadurch hebt sich die Düse um 0,04mm. Weite einen Moment und prüfe
  ob es besser ist.
- Falls die Düse zu weit von dem Rruckbett entfernt ist drehe die
  beiden Spindeln der Z-Achse um eine Rasate nach links. Mit ein wenig
  Übung kann man den Abstand einstellen bevor das Bauteil gedruckt
  wird.
- Merke dir wie viele Rasten du gedraht hast und stelle den neuen Wert
  an dem Display des 3D-Druckers ein: Einstellungen>Bewegung>Z Versatz

Werte zwischen -1.00 und - 1.90 Sind Normal. Anpassungen im Bereich von
ca. 0,02 bis 0,08mm sind üblich. Eine Raste der Schrittmotoren
entspricht 0,04mm. Dabei wird der Abstand kleiner wenn die Zahl
negativer wird.

Wenn du eine gute einstellung gefunden hast speichere die Einstellungen
ab. Einstellungen>Konfig. speichern

Einstellung des Z-Versatzes

Die Funktion ist in der Anleitung zu der MARLIN-Firmware nachzulesen.
<http://marlinfw.org/docs/features/auto_bed_leveling.html>

Die Halterung des Sensors ist auf Thingverse veröffentlicht.
<https://www.thingiverse.com/thing:3956207>
