+++
title = "Getränkezähler"
+++

## Benutzer-Guide

### Anonym Bezahlen

Um anonym zu bezahlen, kannst du dir kleine Zettel mit einem Barcode
ausdrucken. Dieser Barcode verfällt, nachdem sein Guthaben aufgebraucht
ist.

1. Hierzu tippst du am Getränkescanner auf **Geld einwerfen**
2. Wirf einen Schein in die Kasse hinter dir.
3. Tippe den entsprechenden Betrag auf dem Display an.
4. Dein Code wird ausgedruckt. Du kannst jetzt Buchen!

### Getränk Trinken

1. Scanne ein Getränk.
2. Tippe **Buchen**. Alternativ kannst du deinen Zettel oder Member-Code scannen.
   1. Wähle deinen Anfangsbuchstaben.
   2. Wähle deinen Nutzer.
3. Drücke **Trinken**!

Alternativ kannst du auch zuerst deinen Nutzer auswählen (oder
Member-Code scannen), und dann dein Getränk scannen. Drücke danach
genauso auf **Trinken**.

## Konzept

### Idee

Es soll mithilfe eines Barcode Scanners gezählt werden, wie viele
Getränke man getrunken hat. So behält jeder den Überblick, wieviel er
dem Verein spenden sollte und wir wissen, wann neue Getränke besorgt
werden müssen.

[github
repository](https://github.com/flipdot/drinks-scanner-display)
des Getränkezählers.

### Anleitung

==> Hier gehts zur
[Getränkezähler_Usage](Getränkezähler_Usage)

### Hacker

- DoB (Projektmanagement)
- Niklas (Datenbank/Modellierung, Externe Schnittstellen (später))
- Sören ([Ansteuerung
  Display](http://www.raspberrypi-spy.co.uk/wp-content/uploads/2012/07/16x2_lcd_module.jpg))
- Eike
  (http://www.raspberrypi-spy.co.uk/2012/07/16x2-lcd-module-control-using-python\|Elektronik\]\])
- Anselm (Core-Logik)
- Jonas (Core-Logik)
- kssoz (Testing, Installation, Buchungsdialoge)
- nox_x (Callibration Display)

### Zeitplan

```
1. Termin: 02.07.2015 18:00 Uhr
    Technologie entscheiden
    Setup Raspberry PI
    Ausgabe Barcode auf Anzeige (HDMI-Bildschirm)
2. Termin: 09.07.2015 18:00 Uhr
    Barcode-Format spezifizieren
    Hintergrundbeleuchtung, Kontrast einstellen
3. Termin: 16.07.2015 18:00 Uhr
    SQL Datenbank modellieren
4. Termin: 27.04.2016
    Case fertigbauen und im Space installieren
    [RasPi](RasPi) bestellen
5. Termin: 28.04.2016
    Raspi anschliessen und einrichten
    Barcodes in Datenbank speichern und zählen
6. Termin 29.04.2016
    Flipdot Display ansteuern
    low-res font implementieren
    Testing (Hacked) ^^
7. Termin: 28.05.2016
     Touchscreen Interface:
     Touch-Matrix,
     homescreen mit Namensauswahl,
     login Begrüßung mit Piechart-Dummy und Scan Aufforderung
8. Termin: 29.05.2016
     Anbindung an LDAP (User-Datenbank)
9. Termin: 11.06.2016
     Kallibration der Touch-Matrix - fixed!
```

### Details

#### Buchungsprozesse

Spenden per Prepaid-Karte soll ermöglicht werden, nicht erzwungen. Das
analoge Spendensystem (von \*hel) wird nicht abgeschafft, sondern
ergänzt.

##### Fall 1 - member ohne Digital-Konto

1\. homescreen with login

    Flipdot
    Getränkescanner
    Wer bist du?
    [a][b][c][d][e][f][g]
    [h][i][j][k][l][m][n]
    [o][p][q][r][s][t][u]
    [v][w][x][y][z][#]
    [Gast]

(Ereignis: Tastendruck z.B. wenn \# dann Sonderzeichen Namen zeigen)

2\. name selection

    Dennis
    DoB
    DmB
    ...

(Ereignis: Namenswahl oder timeout 5s)

3\. scan demand

    Hallo Dennis,
    Scanne ein Getränk!

(Ereignis: Scan! oder timeout 10s)

4\. scan result & donate prompt

    Club Mate
    EAN 123456778890
    Spende bitte 1,00€ in die Kasse!
    Flaschenaufkleber wird gedruckt...

(Warten bis timeout 10s oder Touch! -\> home)

------------------------------------------------------------------------

##### Fall 2 - member mit Digital-Konto und Barcode membercard

(Ereignis: Scan einer membercard!)

1\. scan demand & credit balance

    Hallo Banana,
    Kontostand: 13€
    Scanne ein Getränk!

(Ereignis: timeout 10s -\> home oder Scan!)

2\. scan result & credit balance

    Club Mate
    EAN 123456778890
    1,00€ von Dir wurde gespendet!
    Kontostand: 12€
    Flaschenaufkleber wird gedruckt...

------------------------------------------------------------------------

##### Fall 3 - Direkter Scan einer Flasche/Objekts

(Ereignis: Scan!)

1\. scan result & donation prompt

    Club Mate
    EAN 123456778890
    1,00€ in die Kasse spenden?
    [Ja] [Nein]

(Ereignis: "Nein"! oder timeout 10s -\> zurück nach homescreen.
"Ja"! -\> Namensauswahl)

2\. homescreen with login

    Wer bist Du?
    [a][b][c][d][e][f][g]
    [h][i][j][k][l][m][n]
    [o][p][q][r][s][t][u]
    [v][w][x][y][z][#]
    [Gast]

(Ereignis: timeout 5s -\> home; Tastendruck z.B. wenn \# dann
Sonderzeichen Namen zeigen)

3\. name selection

    Dennis
    DoB
    DmB
    ...

(Ereignis: timeout 5s -\> home oder Namenswahl)

4\. donation prompt

    Hallo DmB,
    Spende bitte 1,00€ in die Kasse!
    Flaschenaufkleber wird gedruckt...

(Warten bis timeout 10s oder Touch! -\> home)

------------------------------------------------------------------------

#### Spezifikation für den Barcode

    23Z YYYY YYYXX C

    enum Z
    {
        Steuerkarte = 0,
        Guthabenkarte = 1
    }

    X - Steuerkarte:
            Anzahl an Elementen/Flaschen
        Guthabenkarte:
            Ursprünglicher Betrag

    Y - Steuerkarte:
            0
        Guthabenkarte:
            Random

    C - EAN-Checksum

Der Barcode startet mit 23, um mit dem EAN-13-Standard kompatibel zu
sein (20-29 für In-Store-Functions). Vgl:
<http://www.barcodeisland.com/ean13.phtml>

#### Datenbank

<!-- {{http://i.imgur.com/QJvq4nW.png}} -->

#### Feature Ideen

- Scanpiep ersetzen durch Schraubverschluss Geräusch (Zischhhh)
- NFC Bezahl Methode
- Nach Scan wird ein selbstklebendes Etikett ausgedruckt zum
  Flasche markieren (User ID, Datum, Glückskeksspruch ...)
- Auf Flipdot Display werden gescannte Getränke gezählt (beta: nur
  3 stellig, später mehr Infos wie Getränketyp)
- Datenbank schlägt Alarm, wenn kritische Lagerbestände
  unterschritten werden (-\> Getränke-Einkauf)
- Statistiken über Getränke :D
- Zusätzlich gibt es einen Hardware Knopf mit dem ich alle
  Aktionen abbrechen kann und wieder zurück in den Initialzustand
  wechseln kann
- Datenbank läuft mit auf dem PI, Daten bleiben im Space

#### Hack

Getränkezähler mit Flipdotdisplay verbunden und schöne Invaders
lowres-font implementiert.

"Wir kommen doch nicht über 999 Getränke pro Tag oder?" -\>
Getränkezähler geDoSt: Makita, Deutschlandflagge, Krepklebeband,
Bier-Etikett, Mate-Ettiket \^\^

<!-- {{attachment:IMG_20160429_190628.jpg}} -->
<!-- {{attachment:IMG_20160429_190844.jpg}} -->
<!-- {{attachment:VID_20160429_190711.mp4}} -->
<!-- {{attachment:VID_20160429_190901.mp4}} -->
<!-- {{attachment:VID_20160501_211820.mp4}} -->
<!-- <attachment:VID_20160501_211820.mp4> -->
<!-- <attachment:VID_20160429_190711.mp4> -->
<!-- <attachment:VID_20160429_190901.mp4> -->
