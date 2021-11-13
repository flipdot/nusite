+++
title = "Getränkezähler: Usage"
+++

## Getränke kaufen

1. Getränk mit Scanner an der Wand einscannen
2. Deinen Username auswählen
3. Auf Zuordnen klicken
4. Bestätigung wird angezeigt

## Guthaben aufladen

1. Die Seite <http://drinks-touch.fd/> während du im Space bist öffnen
2. Auswählen, dass du Guthaben aufladen willst
3. Den Anweisungen auf dem Bildschirm folgen

## Neue Getränke-Arten hinzufügen

1. [Git-Repo](https://github.com/flipdot/drinks-scanner-display) klonen
2. Einen SSH-Tunnel bauen, damit du auf die Datenbank kommst
   (`ssh -L 5432:127.0.0.1:5432 pi@drinks-touch`)
3. Das Skript `./tool_add_drink.py --help` ausführen,
   die Hilfe zeigt dir, welche Parameter eingegeben werden müssen

## Siehe auch

<https://flipdot.org/wiki/Getr%C3%A4nke>
