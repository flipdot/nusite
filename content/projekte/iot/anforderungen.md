+++
title = "IoT: Anforderungen"
+++

Entwurf - möglichst kein Feature Creep!

## Sensoren / Aktoren = Knoten

- Knoten laufen mit Batterieversorgung
- Knoten laufen mit Netz, wenn Spannung verfügbar, oder Knoten immer
  erreichbar sein muß (Für Aktoren wie Heizung)
- Hardware und Software für Batterie- und Netzbetrieb identisch,
  Auswahl durch Jumper
- Batterielebensdauer ~ 1 a
- Experiment mit Nachladung der Batterien via PV?
- Knoten erfassen
  - Ihren Batteriestatus
  - Die Wlan Feldstärke
  - Mechanische Zustände
  - Temperaturen (optional)
  - Wasser (optional)
  - Stromverbrauch / Aktivität von 230 V Verbrauchern (optional)
- (Batterie-)Knoten schlafen immer, wachen auf durch
  - mechanischen Vorgang (Tür wird geöffnet)
  - Schwellwertüberschreitung (Helligkeit \< Schwellwert) (optional,
    Anwendungsfall noch offen, Detektion offener Fenster?)
- Knoten übertragen entweder
  - nur eine Transition (Lichtschranke durchschritten, Klingeltaste
    gedrückt) => einfacher Aufbau, ESP im
    [DeepSleep](DeepSleep), oder
  - Transition und neuen Status (Tür wurde bewegt, ist jetzt offen)
    => Attiny nötig um *Wechsel* zu erkennen, *oder* Lösung mit zwei Schaltern
- Knoten sind billig

## Infrastruktur / Vernetzung

- Denkbar: Ein separates Wlan nur für IoT ohne Kontakt zum Internet
- lokale Zentrale im Space ist in diesem separaten Netz

## Zentrale / API

- Es gibt eine lokale Zentrale im Space, die die Knotendaten
  einsammelt und verteilt (MQTT Broker)
- Die Sensorbenamung folgt einem Regelwerk: mögliche Messwerte,
  Raumbezeichner..

## Verarbeitung

- Es kann (einen) Knoten geben, welcher Daten vom Broker erhält
  (abonniert) und verarbeitet, und der
  - Die Daten verknüpft (Heizung = an & Fenster = auf),
    (Kühlschrank > 5 min geöffnet) und Aktionen an die Knoten sendet
  - Die Daten (zyklisch) an die Space API "draussen" meldet
  - Befehle entgegennimmt (IRC, HTTP, ...) und an die Knoten sendet
  - Eine Hardware-Benutzerschnittstelle zur Verfügung stellt
  - und leitet daraus ggf. Aktionen ab (Anzeige an zentralem
    Terminal im Space, Mail an Paten) (Space wurde verlassen /
    abgeschlossen => Heizungen runterfahren)
- Mobile Knoten (aka Fernsteuerungen) denkbar mit festgelegten
  Funktionen

## Aktoren / Melder

- Die Daten der Space Knoten finden Aufnahme in den !Status im IRC
- Knotenpaten bekommen Mail wenn Batterie alle
- Anzeige an der Ausgangstür: Ein Blick - alle Knoten auf grün, Space
  kann geschlossen werden, und / oder akustische Benachrichtigung wenn
  noch ein Knoten auf rot steht
- Aktionen triggern (Anzeigen am Space-Ausgang: "Dachluken offen",
  Klopapier alle", "Herd noch an")
- Triggern von Einträgen in Einkaufslisten (Klopapier) oder
  Bestellungen (Bier? ;)
- Reaktionen auf besondere Zustände (Einbruch o.ä.) Mail, SMS ...
