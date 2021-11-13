+++
title = "IoT: Nodes"
+++

Nodes sind alle Teilnehmer am IoT Netz.

## Sechseck-Lampe

Basiert auf der [WS2812FX
Lib](https://github.com/kitesurfer1404/WS2812FX).

- Node subscribed Topic: actors/misc/honeycomb0
  - Funktionen
    - mode \[0..46\]
    - speed \[0..255\]
    - brightness \[0..255\]
    - color \[#rrggbb\] Hex Werte

Nette modes:

- FX_MODE_FIREWORKS, **mode 42, speed 255**
- FX_MODE_STROBE_RAINBOW, **mode 24, speed 190**
- FX_MODE_HYPER_SPARKLE,**mode 22, speed 0**
- FX_MODE_FADE, **mode 12, speed 20**
- X_MODE_RAINBOW_CYCLE, **mode 9, speed 0**
- FX_MODE_STATIC **mode 0**

## Panel

(Neben der Lounge - Tür, 5 LEDs als Demo für ein
späteres Status - Panel

- Node subscribed Topic: actors/lounge/panel
  - Funktionen: \[n m\]
    - n = LED \[0..4\]
    - m = Zustand \[0..1\]

## Strassenlicht

- Topic: actors/work_mech/stolperlicht/cmnd/POWER
- Nachricht
  - 0 -\> Aus
  - 1 -\> Ein

## Sensor

(Neben der Lounge - Tür, Rollen-Mikroschalter als Demo für späteren
Fenstersensor o.ä.)

- Topic:
- Funktionen:
