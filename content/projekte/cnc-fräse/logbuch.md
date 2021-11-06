+++
title = "CNC-Fräse: Logbuch"
+++

# 2021-10-12 Spindel mit Notaus gekoppelt \[typ_o, malled\]

- Relais1 -\> Spindelmotor. Relaisfreigabe evtl. noch per gcode aktivieren.
- Relais2 -\> Steckdose für Staubsauger o.Ä.. Steuerung über gcode (M8,M9)

# 2015-06-28 Maschine stoppt unerklärlicher weise

- Mit einem GCODE File Probleme <!-- (<attachment:Abziehsteinhalter01.nc>) -->.
  Maschine stoppte jedes Mal an etwa der gleichen Stelle. Nicht klar warum, später prüfen
  ([Forum](https://www.bountysource.com/issues/1383965-grbl-0-9c-stop-working-after-batch-some-gcode-commands)) -
  Geklärt: Die Fräspfade lagen ausserhalb des Bearbeitungsraumes -
  würden die Softlimits, die im GRBL Setup eingestellt sind,
  überfahren, stoppt GRBL die Abarbeitung - allerdings ohne Fehlermeldung.

-   Achsgeschwindigkeiten - Limits weiter hochgestellt, weil ich mal mit
    2m/s probieren wollte.
-   \$110=2000.000 (x max rate, mm/min)\<\
    \>\$111=2000.000 (y max rate, mm/min)\<\
    \>\$112=800.000 (z max rate, mm/min)
-   Die Fräser, die wir von BZT bekommen haben sind alle HSS, und nicht
    gut für Holz, weil sehr wärmeempfindlich (Hier braucht man
    Hartmetall, HM)

# 2015-06-21 Lüfter, Soft Limits, Rampen und max speed

-   Unter dem Triple Beast PC Lüfter angeschraubt - alles cool
-   für x und y Achse soft Limits eingestellt, dass (wenn vorher der
    Homing Cycle "\$H" den mechanischen Maschinen-Nullpunkt korrekt
    gesetzt hat) nicht in die mechanischen Begrenzungen (bei -x und -y
    maximal weit vom Nullpunkt weg) gefahren werden kann. Für Z Achse
    ist so ein Limit schwierig, da Werkzeuglänge ja variiert
-   Geschwindigkeit und Beschleunigung hochgedreht - jetzt gehts fix.
-   Mit der schnellen Geschwindigkeit auch für homing seek (\$25) bricht
    der Homing Cycle jetzt auch nicht mehr ab
-   [UnicersalGCODESender](UnicersalGCODESender)
    -   Die Return to Zero Funktion ist nach wie vor kaputt. Werde
        versuchen, das mit einem Makro zu machen
    -   **Obacht Bug:** Wenn die Steurung mit Cursortasten aktiv ist,
        und man in einem Datei öffnen Dialog mit den Tasten zu
        navigieren versucht, *bewegt sich die Maschine!*

GRBL 0.9g Config

    >>> $$
    $0=10 (step pulse, usec)
    $1=25 (step idle delay, msec)
    $2=0 (step port invert mask:00000000)
    $3=6 (dir port invert mask:00000110)
    $4=0 (step enable invert, bool)
    $5=0 (limit pins invert, bool)
    $6=0 (probe pin invert, bool)
    $10=3 (status report mask:00000011)
    $11=0.020 (junction deviation, mm)
    $12=0.002 (arc tolerance, mm)
    $13=0 (report inches, bool)
    $14=1 (auto start, bool)
    $20=1 (soft limits, bool)
    $21=1 (hard limits, bool)
    $22=1 (homing cycle, bool)
    $23=0 (homing dir invert mask:00000000)
    $24=100.000 (homing feed, mm/min)
    $25=1000.000 (homing seek, mm/min)
    $26=250 (homing debounce, msec)
    $27=1.000 (homing pull-off, mm)
    $100=400.000 (x, step/mm)
    $101=400.000 (y, step/mm)
    $102=400.000 (z, step/mm)
    $110=1500.000 (x max rate, mm/min)
    $111=1500.000 (y max rate, mm/min)
    $112=400.000 (z max rate, mm/min)
    $120=50.000 (x accel, mm/sec^2)
    $121=50.000 (y accel, mm/sec^2)
    $122=50.000 (z accel, mm/sec^2)
    $130=510.000 (x max travel, mm)
    $131=560.000 (y max travel, mm)
    $132=200.000 (z max travel, mm)

# 2015-03-07 GRBL Interpreter aufgebaut

[GRBL](https://github.com/grbl/grbl) Version 0.9 auf einem
Arduino Uno. Gehäuse mit SUB-D 25 Pol besorgt, wo der reinkommt
\[typ_o\]
