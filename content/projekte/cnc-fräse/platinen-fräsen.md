+++
title = "CNC-Fräse: Platinen-Fräsen"
+++

## Frästiefenregler

-   [Sorotec](http://www.sorotec.de/shop/CNC-Mechanik/Tiefenregler/Gravureinheit---Tiefenregler-GT43.html)
-   [BZT](http://www.bzt-cnc.de/shop/cnc-fraesen-zubehoer/242-gravuranschlag-tiefenregler)
-   [Gravurtiefenregler
    Eigenbau](http://www.einfach-cnc.de/gravurtiefenregler.html),
    verwendete
    [Mikrometerschraube](https://www.amazon.de/WABECO-Mikrometerschraube-0-25-mm/dp/B003V3RORA)
-   Idee: Neben dem aktuellen Spindelmotor (Der Kress) einen Brushless
    Motor mit Frästiefenregler anbauen. Dazu passt [diese
    Spannzangenaufnahme](http://mbp-rc.de/Spannzange-5x32mm),
    die sich an eine 5mm Achse von einem Brushlessmotor schrauben
    läßt.Der zweite Motor könnte immer montiert bleiben, incl.
    eingesetztem Stichel, wenn man die Höhe geeignet einstellt.

## Flatcam howto

-   Reiter "Options" Millimeter einstellen. Application und Project
    defaults
-   Gerber-Datei und Drill-Datei(Excellon) oeffnen
-   Offset anpassen
    -   Kordinaten der oberen linken Ecke der Platine ermitteln (Maus +
        Statusleiste)
    -   Gerber-Datei doppelklicken. Ganz untern Offset-Vector eintragen.
        -   Achtung: Offset ist immer relativ zur aktuellen Position
    -   Mit Drill-Datei wiederholen
-   \...
