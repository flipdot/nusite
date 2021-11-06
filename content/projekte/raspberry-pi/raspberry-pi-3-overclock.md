+++
title = "Raspberry Pi 3 Overclock"
+++

Nach Kühlkörper (klein) installation in config.txt (Boot) einfügen:

```
arm_freq=1250
force_turbo=1
over_voltage=2
temp_limit=75
```

Frequenz ab bootstart auf 1250, Governour max, limitiert ab 75grad auf
?700mhz. Falls Spannungsfall zu hoch, eventuell Polyfuse brücken
(Strom-/Hitzeabhängige, rückstellbare Sicherung, die Kurzschlüssschäden
verhindern soll, nähe Netzteilanschluss, unterseite Platine) Direkte
Spannungsversorgung über GPIO-Pins scheint auch möglich.

<https://www.raspberrypi.org/documentation/configuration/config-txt/overclocking.md>
