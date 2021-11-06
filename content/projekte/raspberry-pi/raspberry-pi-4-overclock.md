+++
title = "Raspberry Pi 4 Overclock"
+++

Nach Kühlkörper (klein) installation in config.txt (Boot) einfügen:

```
arm_freq=1600
force_turbo=1
over_voltage=4
temp_soft_limit=80
```

Frequenz ab bootstart auf 1600, SPannung für CPU erhöht für mehr
stabilität, Governour max, limitiert ab 80grad Stufenweise runter.
Direkte Spannungsversorgung über GPIO-Pins scheint möglich.

<https://www.raspberrypi.org/documentation/configuration/config-txt/overclocking.md>
