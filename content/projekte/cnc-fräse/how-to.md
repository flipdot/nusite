+++
title = "Fräse How To - Einrichten leicht gemacht"
+++

## Opferplatte aus MDF

* Die Platte ist aus MDF, 17 mm dick, 600 mm x 780 mm.
* Wird mit 4 Gleitmuttern und 4 Stück M6 Inbusschrauben (15 mm Gewindelänge) auf der Nutenplatte befestigt.
* Bohrdurchmesser für die Schrauben 7 mm.
* Senkung mit einem 10 mm Holzbohrer 6 mm tief - dann sind die Schraubenköpfe nicht im Weg.

## Werkstück (Plattenmaterial) - Befestigung auf der Opferplatte

* Fräsbahn auf Papier ausdrucken - dann lassen sich die Befestigungspunkte sicher so wählen, dass man nicht mit dem Fräser in die Schrauben fährt.
* Löcher in Werkstück bohren für die Spax - Schrauben. (Unterlage aus Restholz)
* Werkstück festspaxen. Obacht: Wenn Schrauben zu lang, wird die Nutenplatte darunter beschädigt.

## Erklärbär - Video zum Einrichten der Fräse

https://youtu.be/uf1zHfzn9n8

## Spannzange und Fräser (Maschine stromlos)

* Zum Fräser passende Spannzange wählen. Obacht: Z.B die Fräser mit den bunten Ringen haben keinen 3 mm Schaft, sondern 1/8" = 3,175 mm. Dazu gibt's die passende 1/8" - Freedom - Unit - Spannzange.
* Den Konus der Spannzange möglichst nicht mit schwitzigen Fingern berühren. Rost -> schlecht.
* Werkzeug - Einbau
  * Spannzange in die Überwurfmutter drücken. Obacht: Die Spannzange muss ganz einrasten, und unten bündig mit der Mutter abschließen, sonst Verklemmungs - Gau.
  * Fräser in die Spannzange schieben. Nicht unnötig weit herausstehen lassen, sonst Gefahr: Vibration, schlechtes Fräsbild, Bruch.
  * Spannzange in den Spindelmotor schrauben.
  * Verriegelungstaste unten am Motor drücken und Spindel drehen, bis Einrasten spürbar ist
  * Spannzange mit 17 mm Gabelschlüssel festschrauben. Mit Gefühl, auch mäßig stark angezogen reicht, da Konus.
* Werkzeug - Ausbau
  * Verriegelungstaste unten am Motor drücken und Spindel drehen, bis Einrasten spürbar ist
  * Spannzange mit dem 17 mm Gabelschlüssel losschrauben. Obacht: Nach dem ersten Lösen kommt nochmal eine "schwere Stelle", wenn die Spannzange aus dem Konus gezogen wird. Mutig weiterschrauben.
  * Fräser aus der Spannzange ziehen
  * Spannzange aus der Mutter drücken. Tricky. Mit dem Daumen von der unterseite her gehts am besten.

## Arbeitsbereich

Der maximale Verfahrweg wurde durch versetzen der Endschalter nochmal etwas erweitert und beträgt jetzt

* Y: -600 mm
* X: -530 mm

Direkt über diesen Werten greifen die "Soft Limits", die im GRBL Controller eingetragen sind.

## Nullpunkte einrichten

* Maschinennullpunkt anfahren: Das ist der $H Befehl in GRBL
* Werkstücknullpunkt anfahren
  * Maschine verfahren. Obacht: Default ist Zoll, Risiko.
  * X und Y nach Zeichnung anfahren und "Nullen"
  * Z nullen:
    * Spindelmotor einschalten
    * An Werkstückoberfläche annähern
    * in 0,05 mm Schritten weiter, bis ein erstes Kratzen zu hören
    * Reset Z

## Fräsprogramm ablaufen lassen

* Ich habe am Anfang oft die Z-Achse z.B. 20 mm ''über ''der Werkstückoberfläche genullt, und dann das Programm mal durchlaufen lassen, um Denkfehler zu finden
* File Mode, Send
* Wenn der Nullpunkt so gewählt wurde, dass das Werkstück zu groß für den Bearbeitungsraum ist, dann stoppt die Bearbeitung vor den Grenzen der Maschine ohne aussagekräftige Fehlermeldung
* Gelegentlich trat ein "Empty Stream" (sinngemäß) - Fehler auf, Bearbeitung musste wieder von Anfang an gestartet werden. Ursache unklar.

## Tips 'n Tricks

* An den Werkstücken "Stege" im CAM programmieren, damit die Teile nicht gänzlich losgefräst werden. Das Festhalten der Frästeile ist unsicher.
* Tip für Fräswerkstücke, die nicht in den Arbeitsbereich passen (Passbolzen zum Wenden)
  * Mindestens zwei Bohrungen so anlegen, dass sie auch bei 180 Drehung die Position behalten (spiegelsymmetrisch). Dann bei der ersten Werkstückhälfte ganz durch das Werkstück und fast ganz durch die Opferplatte fräsen (bohren). Nach dem Wenden lässt sich das Werkstück dann z.B. mit zwei Bohrern als Bolzen vor dem Spannen ausrichten. Wenn man 6 mm Bohrungen brauchen kann, dann eignen sich die Bolzen von Ikea-Ivar-Regalen ganz hervorragend. Sind welche in der Werkstatt.
  * Das Verfahren ist auch sinnvoll, wenn Vorder- und Rückseite passgenau bearbeitet werden müssen.
