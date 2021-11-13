+++
title = "IoT: MQTT-Topics"
+++

Grundlegende Aufteilung der MQTT-Topics in Quellen und Senken (Sensoren
= Quellen, Aktoren = Senken). Ein Topic-Namensraum gehört den Sensoren,
ein Topic-Namensraum den Aktoren. Ein Verknüpfungs-Layer abonniert die
Sensor-Namensräume, und postet in den Aktor-Namensräumen. Klartext
Topics erlauben z.B. auf einem Bedienpanel lesbare Logs anzuzeigen.
(vgl.:
[Bamberg](https://www.hackerspace-bamberg.de/Space_Automation))

\--(Ein besonderer Topic-namensraum ist *Device Presence Control*. Hier
können kritische Nodes wie z.B. Einbruchssensoren etc. zyklisch ihre
Funktionsfähikeit melden)\-- Ist in MQTT schon eingebaut

## Raumnamen

- `lounge` (Sofaecke, \...)
- `work_el` (Elektronikwerkstatt, Netzwerkschrank, \...)
- `work_mech` (Mechanikwerkstatt, Fräsraum, \...)
- `raum4` (Beamer, Regalreihe, Workshops, \...)
- `kitchen` (Küche, Besteck, Dusche, \...)
- `hall` (Flur, Ofen, Geschirr, \...)
- `restroom` (Toiletten, Reinigungsmittel, \...)
- `cellar` (Ebenerdiger "Keller", Getränkelager, \...)
- `entrance_front` (Gelbe Eingangstür, Südwestseite, Klingel, Abstellgleis, \...)
- `entrance_back` (Orange Eingangstür, Nordortseite, Hof, Pennertonne, \...)
- `all` (Spezialfall für Sensoren/Aktoren die in allen Räumen gleich
  sind, z.B. `sensor/audio/all/mpd`)

## Beispiel Topics

- `sensors/`
  - `lounge/`
    - `light_state`
    - `window_state`
  - `work_el/`
    - `door_state`
    - `light_state`
    - `soldering_iron_state`
  - `work_mech/`
    - `light_state`
    - `window_state`
  - `kitchen/`
    - `light_state`
  - `hall/`
    - `light_state`
  - `restroom/`
    - `light_state`
    - `smell_state`
    - `toilet_flush`
    - `urinal_flush`
  - `cellar/`
    - `drinks_crate_counts`
    - `drinks_scale_measurements_metric`
    - `drinks_scale_measurements_raw`
    - `light_state`
  - `entrance_front/`
    - `door_state`
  - `entrance_back/`
    - `door_state`
  - `all/`
    - `music_info`
- `actors/`
  - `lounge/`
    - `light_state`
    - `window_state`
  - `work_el/`
    - `light_state`
  - `work_mech/`
    - `light_state`
    - `window_state`
  - `raum4/`
    - `light_state`
    - `window_state`
  - `kitchen/`
    - `light_state`
    - `window_state`
  - `hall/`
    - `light_state`
    - `window_state`
  - `restroom/`
    - `light_state`
    - `toilet_flush`
    - `urinal_flush`
  - `cellar/`
    - `light_state`
  - `entrance_front/`
  - `entrance_back/`
  - `all/`
    - `music_next_track`
    - `music_previous_track`
    - `music_play_pause`
    - `music_volume_up`
    - `music_volume_down`

## Sammlung möglicher Sensoren

### Mit Schaltern zu realisieren

- Dachluke Lounge und Küche
- Fenster in den einzelnen Räumen (Einfachversion: Schalter in Reihe für Fenster auf / zu).
  Erfordert dann statt Umschalter eine Kette aus Öffnern + Pullup-Widerstand
  - Mechanik-Werkstatt
  - Lounge
  - Raum 4
- Tür Raum 2 (E-Werkstatt / Haupteingang), Erfassung Verriegelungsstatus. Speziell: Sowohl
  Motorschloß-Riegel als auch Abus-Knebelschloß-Riegel müssen überwacht werden
- Tür Raum 4, Erfassung Schließriegel (Öffner gegen Wechsler tauschen)
- Kühlschranktür
- Klopapierlager (Spender mit senkrechtem Rollenstapel, vorletzte Rolle => Sensorsignal)
- Klo besetzt / frei
- Außentüren zugezogen (schwierig wegen abgeranzter Mechanik)
- Klingelschalter (Ersatz für ISM - Funkklingeln) - ermöglicht
  automatisches Türöffnen wenn Space auf

### Besondere Sensoren

- Bewegungsmelder (Versorgung aus Akku sollte gehen)
  - Der über dem Kücheneingang
  - Innenräume im Space?
- Wasseralarm (Am Fenster oder auf dem Boden?)
- Temperatur in den einzelnen Räumen
  - In Raummitte
  - Auf dem Fensterbrett (Detektion offener Fenster zusätzlich zum Fenstersensor?)
- Herd / Pizzaofen
  - Anschluss an Kontrollampe, also Erfassung ob an / aus
  - Stromerfassung über Wandler / Shunt?
- Lötstationen

## Sammlung möglicher Aktoren

- 230 V - Lasten (China Relaisplatinen, günstiger 433 MHz Gateway auf
  Funksteckdosen, spart ausserdem Aufwand für Berührschutz)
- Türöffner unten (Relais wie GSM Schloss)
- Audio (MPD Ansteuerung)
- flipdots
- Lüftung
  - Vorhandener Lüfter im Klo
  - Motoren an den Dachluken
- flipdot - Leuchtkasten vor der M-Werkstatt
- Posting im IRC
- Mail (Vor allem bei niedrigem Batteriestand wichtig)
