+++
title = "3D-Drucker Slicing"
+++

## PrusaSlicer

<https://www.prusa3d.de/prusaslicer/> ist sehr empfehlenswert.
`{{https://forum.flipdot.org/uploads/default/original/2X/b/bf69286baff3bed6238a4c45baf08a16f99df278.jpeg}}`{=mediawiki}

Die Einstellungen für den Slicer sind in der INI Datei zusammengefasst.

<!-- <attachment:Prusa_config_Anet_A8_2020-06-13.ini> Slicing -->

## Cura

*[Cura](https://ultimaker.com/en/products/cura-software)* ist
freie(?) Software, mit der man Mesh-basierte 3D-Daten in GCode umwandeln
kann. Du kannst die bereits dafür angelegt
[.curaprofile-Datei](attachment:flipdot.curaprofile) oder das
neue curaprofile <!-- <attachment:flipdot2019-10-02.curaprofile> --> verwenden,
die die richtigen Einstellungen für den Space-Drucker hat. Zusätzlich sind noch
die Maschineneinstellungen des Druckers zu ergenzen. Das geht unter
Settings-\>Printer-\>Manage Printers-\>Printers-\>Machine Settings

Unser Filament hat einen Durchmesser von 1,75mm und die Düse hat einen
Durchmesser von 0,4 mm

<!-- [<attachment:3D-Drucker_Cura_AnetA8.png>](attachment:3D-Drucker_Cura_AnetA8.png) -->

<!-- {{attachment:3D-Drucker_Cura_AnetA8.png}} -->

Start gcode:

    G21 ;metric values
    G90 ;absolute positioning
    M82 ;set extruder to absolute mode
    M107 ;start with the fan off
    G28 X0 Y0 ;move X/Y to min endstops
    G28 Z0 ;move Z to min endstops
    G29; Bed Leveling
    G1 Z15.0 F9000 ;move the platform down 15mm
    G01 X-30 Y170 ; links Mitte
    G92 E0 ;zero the extruded length
    G1 F200 E3 ;extrude 3mm of feed stock
    G92 E0 ;zero the extruded length again
    G1 F200 Z1 ; absenken
    G1 F200  X10 Z0.0 ; Move to start of Intro Line
    G1 F200 Y70 E7.5 ;Print Intro Line
    G1 Z5
    G1 F9000
    M117 Printing...
    G92 E0.0 ; reset extruder distance position
    G1 E-2

End gcode:

    M104 S0 ; turn off extruder
    M140 S0 ; turn off heatbed
    G91; relative Positionierung
    G1 Z10
    G90; absolute Positionierung
    M107 ; turn off fan
    G1 X110 Y210; home X axis and push Y forward
    M84 ; disable motors

Um *Cura* zu verwenden brauchst du einen Rechner dessen GPU mit OpenGL
2.0 kompatibel ist, ansonsten kriegst du folgenden Fehler:

    Could not probe OpenGL. This program requires OpenGL 2.0 or higher. Please select your video card driv

## Slic3r

*[Slic3r](http://slic3r.org/download)* ist ähnlich wie
*Cura*. Kann sein, dass die

    .curaprofile

-Dateien importierbar und verwendbar sind. Wenn du ein bisschen damit
experimentiert hast, melde dich am Besten bei DmB, oder einem anderen
3D-Druck-Menschen.
