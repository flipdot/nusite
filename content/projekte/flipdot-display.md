+++
title = "Flipdot-Display"
+++

Das Display hat 48x20 Pixel und einen 1 Bit Farbraum. Du kannst auch
Späße übers Netzwerk mit UDP haben: 192.168.3.36:2323

## Bilder anzeigen

### Python

Um Bilder hier anzuzeigen, [dieses
Skript](https://gist.github.com/icks/0b5dd6761fa1c27148184abcaff0af9b)
zum Laufen bringen, und den Pfad zu einem animierten GIF, oder normalem
Bild angeben.

Das Skript befindet sich neben einigen anderen nützlichen Skripten auch
in [unserem GitHub Repository](https://github.com/flipdot/flipdots-wall). Dort
findet sich beispielsweise ein flipdot Simulator, um auch zuhause mit
dem flipdot Display experimentieren zu können.

### GIMP

Für das oben genannte Python-Skript kannst du auch Bilder in GIMP
erstellen. Entweder statisch, oder animierte GIFs.
Das beste Ergebnis gibts bei purem Schwarz-Weiss in der Auflösung des Displays.

### Blender

Alternativ gibts auch die Möglichkeit in 3D Bilder zu erzeugen. Hierfür
gibts auch ein paar Demo-Dateien die dir ein bisschen Starthilfe geben
sollen: <!-- <attachment:cube.blend>, <attachment:monkey.blend>, <attachment:monkey2.blend> -->

Du kannst über `Scene \> Render \> Animation` eine Bildfolge
exportieren und diese dann unter Linux in der Kommandozeile mit
folgendem Befehl in ein animiertes GIF umwandeln: `convert /tmp/\*.png
/tmp/BILDNAME.gif`

## Bilder

Auf dem Desktop PC (guest Pi) im Space liegt ein Ordner rot umrandet.
Alle Bilder die dort hineingelegt werden, werden zufällig auf dem
Flipdot Display angezeigt. Außerdem werden folgende Bilder
hineingemischt:

<!--
\|\|[{{attachment:box.gif}}](attachment:box.gif)
\|\|[{{attachment:auto.gif}}](attachment:auto.gif)
\|\|[{{attachment:dickbutt.gif}}](attachment:dickbutt.gif)
\|\|
\|\|[{{attachment:monkey.gif}}](attachment:monkey.gif)
\|\|[{{attachment:black.png}}](attachment:black.png)
\|\|[{{attachment:flipdot.png}}](attachment:flipdot.png)
\|\|
\|\|[{{attachment:monkey2.gif}}](attachment:monkey2.gif)\|\|[{{attachment:link.png}}](attachment:link.png)
\|\|[{{attachment:hase.png}}](attachment:hase.png)
\|\|
-->

## Troubleshooting

Manchmal springt der fd-Raspi nicht an. Dann blinkt das grüne Lämpchen
nicht und ist er nicht pingbar. Das hat u.a. zur Folge, dass der Space
Status als geschlossen angezeigt wird. Dann muss man den Micro USB
Stecker hinter dem Display direkt am Pi raus und wieder reinstecken
(nicht den 230V Stecker). Dabei darauf achten, dass nicht aus Versehen
die GPIO Steckverbindung gelockert wird.
