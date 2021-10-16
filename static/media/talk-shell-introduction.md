# Eine Einführung in die Benutzung einer `$SHELL`

## Unterschied `$SHELL` zur Terminal-Emulator
* Die `$SHELL` ist auch nur ein Programm, welches eine Skriptsprache
  interpretiert. Deswegen gibt es auch sogenannte `$SHELL`-Skripte. Jedes
  "Terminal-Fenster" ist im Grunde eine interaktive `$SHELL`-Session.

## Ein paar erste Befehle
* `echo Hello World`
* `echo` ist nur ein Programm
* `which echo`
* `which` ist auch nur ein Programm
* Textdatei erstellen
  * Graphischen Texteditor und Dateibrowser öffnen
  * In Texteditor "asdf\nqwer" eintippen und speichern
  * Dateibrowser zeigt neue Datei an
* `cat datei1.txt`
  * `cat` ist auch wieder nur ein Programm
  * `cat` wurde früher entwickelt um Dateien aneinanderzukleben (vgl. `split`)
* `ls`
  * Zeigt Dateien in einem Ordner an

## Argumente/Parameter
* `ls`
  * `-1` Einspaltig als Liste anzeigen
    (Default beim Pipen, später mehr zu Pipes)
  * `-l` Mehrspaltige Liste mit:
    * Berechtigungen für Nutzer/Gruppe/Alle
    * Anzahl der Verweise auf die Inode
    * Nutzer
    * Gruppe
    * Größe
    * Letzte Änderung
      * Monat
      * Tag
      * Uhrzeit
    * Dateinamen
  * `-a` Auch alles versteckte anzeigen
  * `-A` Alles bis auf `.` und `..`
  * `-h` Menschlich lesbare Größenangaben
  * `-t` Nach Zeit sortiert
  * `-r` Rückwärts

## RTFM!
* `man $programm`
  * Sog. "man page"
  * Anleitung des Programms
  * Enthält (im Idealfall) Dokumentation zu allen Argumenten/Parametern
    und Beispiele
* Alternativ: `$programm --help`

## Pipes
* `$programm --help | less`
* `cat datei1.txt | less`
  * Eigentlich sinnlos, da `less datei1.txt` auch geht
  * Macht Graubärte traurig
* `echo flipdot | morse -e`
* `echo ..-. .-.. .. .--. -.. --- - | morse -d`
* `echo flipdot | morse -e | morse -d`
* `tree /usr/share | less`
  * Programme sind oft schlau und merken wenn gepipet wird
  * `tree -C /usr/share | less`
  * `tree -C /usr/share | less -r`
* `cat datei1.txt | wc -l`
  * Zählt die Zeilen der Datei `datei1.txt`
* `cat datei1.txt | tail -3`
  * Gibt die ersten 3 Zeilen der Datei `datei1.txt` aus
* `cat datei1.txt | head -5`
  * Gibt die letzten 5 Zeilen der Datei `datei1.txt` aus
* `curl -s api.flipdot.org | grep -A3 "people_now_present" | grep "names" | sed -r 's/.*: ([^,]+),?/\1/'`
  * Für den interessierten Zuhörer
  * Befehl Stück für Stück aufbauen und analysieren (denn so werden sie auch geschrieben)
  * `curl -s api.flipdot.org`
  * `curl -s api.flipdot.org | grep -A3 "people_now_present"`
  * `curl -s api.flipdot.org | grep -A3 "people_now_present" | grep "names"`
  * `curl -s api.flipdot.org | grep -A3 "people_now_present" | grep "names" | sed -r 's/.*: ([^,]+),?/\1/'`
  * Leute schlagen Hände überm Kopf zusammen? Zu Recht!
  * Bessere Alternative: `jshon` nutzen!

## Shortcuts
* `CTRL+R` Rückwärtssuchen nach Befehlen, die man bereits vorher verwendet hat
* `CTRL+L` entspricht dem Programm `clear`
* `ALT+.` fügt den letzten Parameter des letzten Befehls ein
  * Typisches Problem: `cd ordner` geht nicht
  * Lösung: `mkdir <ALT+.>`
* Shell-abhängig
  * `CTRL+Left` Cursor springt ein Wort zurück
  * `CTRL+Right` Cursor springt ein Wort weiter
  * `Pos1` Cursor springt an den Anfang der Zeile
  * `Ende` Cursor springt ans Ende der Zeile

## Escape Codes
* Enthalten "Steuerzeichen"
  * Cursor bewegen
  * (Hintergrund-)Farben (zurück-)setzen
* `echo -e '\033[0;36masdf'`
* `nasa-apod`
* `ncurses` basiert auf "Escape Codes"

## Redirects etc.
* `echo test > datei2.txt`
  * `>` heisst Redirect
  * `>` leitet Output in eine Datei um
* `cat datei2.txt`
* `echo überschrieben > datei2.txt`
* `cat datei2.txt`
* `echo angehängt >> datei2.txt`
  * `>>` heisst auch Redirect
  * `>>` hängt an die Datei hinten an
  * `>` überschreibt die Datei
* `cat < datei2.txt`
  * `<` liest die Datei ein und gibt ihren Inhalt an den Input weiter
* `cat <<< datei2.txt`
  * `<<<` liest den String ein und gibt ihn an den Input weiter
  * `<<<` liest **nicht** die Datei ein wie man sieht
* `cat <<< meintext`

## Aufzählungen
`man bash` -> Brace Expansion

### `..`
* `echo {1..10}`
* `echo a{1..10}b`
* `echo a{1..10..2}b`
* `echo a{01..10}b`
* `echo a{001..010}b`
* `echo a{001..10}b`
* `echo a{a..f}b`
* `echo a{a..f}b`
* `echo a{A..F}b`

### `,`
* `echo a{a,c,z,b}b`
* `mv asdf.{pdf,txt}`
  * Ändert Dateiendung
* `mv {ordner1,ordner2}/datei`
  * Verschiebt `datei` von `ordner1` nach `ordner2`
  * Für Golfer: `mv ordner{1,2}/datei`
* `cp datei{,.bak}`
  * Erstellt eine Kopie der Datei `datei` mit dem Namen `datei.bak`

### Kombination
* `echo {A..C}{3..7}-{v,x,n,p}`

## Subshells
* `date --date=yesterday`
* `date --date=$(echo yesterday)`
* `curl icanhazip.com`
* `geoiplookup $(curl icanhazip.com)`
* `file $(which bash)`

## Variablen
* `variable=Hallo Welt`
  * Schmeisst Fehler, weil versucht wird, das Programm `Welt` mit der Variable
    `variable` mit dem Wert `Hallo` zu starten, das Programm `Welt` allerdings
    nicht vorhanden ist.
* `variable="Hallo Welt"`
* `$PATH` ist besonders
  * Sie gibt an, in welchen Ordnern nach Programmen gesucht wird
  * `echo $PATH`
  * `echo $PATH | sed -r 's/:/\n/g'`

## Rückgabewerte
* `true`
  * Ist ein Programm
  * Gibt immer den "Return Code" `0` zurück
    * Wird als "kein Fehler" interpretiert
    * Einsehbar in Variable `$?`
      * `true`
      * `echo $?`
* `false` ist ein Programm
  * Analog zu `true`
  * Gibt immer den "Return Code" `1` zurück
    * Wird als "Fehler" interpretiert
    * Einsehbar in Variable `$?`
      * `false`
      * `echo $?`

## If-Abfragen
```
if true; then
    echo Immer wahr
fi
```

```
if false; then
    echo Immer falsch
fi
```

```
if ping -c1 -w3 space.flipdot.org; then
    echo Space ist erreichbar
fi
```

## Loops
### `for`
```
for i in {1..10}; do
    echo zahl: $i
done
```

### `while`
```
while true; do
    echo -n .
    sleep 1
done
```

```
while read -r variable; do
    echo X $variable X
done < $datei
```

```
while read -r variable; do
    echo X $variable X
done <<< $(echo asdf qwer zxvc)
```

## Arithmetik
* `echo $((1+1))`
* `echo $((a+b))`

## Funktionen
* `echo_hello_world() { echo "Hello, World." }`
* `$0`, `$1`, ... Parameter 1, 2, ...
* `$@` Alle Parameter, separiert über Spaces
* `$#` Anzahl Parameter

## Obskureres
* `$?` "Return Code" des letzten Befehls
  * Return Codes haben die Norm
    * 0 = kein Fehler
    * 1 oder größer = Fehler mit entsprechender Nummer
* `$!` ...?
* `$$` Process ID

## Arrays
* Existieren, werden allerdings nicht so oft wie sonst verwendet, da Space-separierte Strings oft genau so funktionieren

## Interessante Programme
* `youtube-dl` Mediendateien herunterladen
* `mpv` Medienwiedergabe (hat `youtube-dl` eingebaut)
* `ffmpeg`/`avcodec` Medienkonvertierung (von `.avi` nach `.webm`)
* `sox` Audiodinge (Klänge aufnehmen, abspielen, verändern)
* `nc`/`ncat`/`netcat` Netzwerkdinge (`telnet`, Spaß mit Pipes)
* `qrencode` Erzeugt QR-Codes (Bilddateien, ASCII-Art)
* `rsync -a` Synchronisiert Dateien über SSH oder lokal
* `watch` Führt Befehl in einem Intervall aus (ähnlich zu `while true`)

## Weiterführende Tutorials
* http://mywiki.wooledge.org/BashGuide
