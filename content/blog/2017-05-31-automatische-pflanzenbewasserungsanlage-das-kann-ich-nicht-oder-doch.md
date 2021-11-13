+++
title = "Automatische Pflanzenbewässerungsanlage… das kann ich nicht, oder doch?!"
date = 2017-05-31T11:23:00Z
author = "Baustel"
path = "/blog/2017/05/31/automatische-pflanzenbewasserungsanlage-das-kann-ich-nicht-oder-doch"
+++
Ich stand vor dem Problem, dass ich gerne meinen eigenen Kleinstgarten
auf dem Balkon habe, aber andererseits auch in näherer Zukunft für rund
zwei Wochen nicht vor Ort sein werde. Da ich es nicht einsah für den Tod
meiner Pflanzen durch Wassermangel verantwortlich zu sein, musste ich
also handeln.  
Was tut man also? Im Internet nach Lösungen suchen.

[![](/media/IMG_8202.serendipityThumb.jpg)](/media/IMG_8202.jpg)

Der Teil am Geländer der bewässert wird

**Kommerzielle Kauflösung**

Von einem namenhaften Hersteller, gibt es ein System das irgendwas mit
Urlaub und sorgenfrei heisst. Ok... das ganze kann für maximal 36
Pflanzen eingesetzt werden und ist pro Tag einmal schaltbar und zwar
genau zu dem Zeitpunkt, zu dem man den Stecker des Controllers
einsteckt. Es ist weder veränder-, noch erweiterbar und soll rund 120 €
kosten. Das war nicht so ganz meine Welt.
Da ich noch nie groß gebastelt hatte und Elektronik schon immer für
etwas geheimnisvolles hielt. Besser gesagt, Eingeweihte mir wie
Mitglieder eines Geheimbundes mit eigener Sprache und Ritualen vorkamen,
sah ich so auch keine Möglichkeit meine Misere anderweitig zu lösen.

**Es geht auch anders!**

Als wir dann mal, an einem der ersten lauen Tage, nach dem grillen im
Space, im Hof an einem Feuer sassen, rutschte mir mein Leid heraus.
Worauf ich umgehend schulterzuckend Antwort bekam „Mach doch, das ist
ganz einfach", ich bekam schon vorsichtig Hoffnung, doch dann fielen
Wörter wie Raspberry Pi, Solid State Relais, Script usw.. Also sass ich
wieder da und dachte, die, ja die können so was, aber ich doch nicht.
Mir brannte aber mein Problem weiter unter den Fingernägeln, also dachte
ich, was soll´s versuchen kann ich es ja mal. Ich startete in unserem
Forum einen Thread dazu, erfragte wie dass denn konkret gemacht würde
und ob mir dann jemand einen Raspberry Pi leihen könne für ein paar
Wochen.

**Hilfe aus dem Space-Brainpool**

Die Antworten kamen -entgegen meiner Erwartungen- innerhalb kürzester
Zeit. Also klar, wieder ganz viel in dieser Geheimsprache, aber mir
wurde direkt ein Raspberry angeboten und auf nachfrage was dass denn
alles bedeutet, ein kurzes „wir setzen uns mal zusammen, das ist echt
einfach". Aufgeregt, mehr als skeptisch, aber auch ein bisschen
hoffnungsvoll sagte ich zu.
Gesagt getan. Es fing recht kompliziert an, ich solle den Raspberry
nehmen, in Crontab eine Zeile schreiben, eine Pumpe und ein paar
Schläuche kaufen, alles zusammen anschliessen und fertig!? Das soll es
gewesen sein? Ich fragte noch mal nach, da sicherlich ein paar
komplizierte und für mich unlösbare Details fehlten. Naja, ich müsse
noch so ein Relais anschliessen, dass der Raspberry die Steckdose an der
die Pumpe hängt an und aus macht. Und mehr nicht? Mehr nicht!

**Hardware sammeln, und los geht\'s!**

Das hörte sich doch ziemlich machbar an, also traute ich mich. Ich
bestellte eine Pumpe für einen Zimmerspringbrunnen und von einem
namenlosen chinesischen Hersteller ein Bewässerungsset, also dünne
Schläuche, mit kleinen einstellbaren Tropfern am Ende. In der
Zwischenzeit trug ich den mir geliehenen Raspberry Pi mit nach Hause,
stellte ihn auf meinen Schreibtisch und beäugte ihn für eine sehr lange
Zeit skeptisch. Mir wurde klar, dass ich von aussen nicht viel machen
brauchte also schloss ich ihn an Strom und Lan und fing ich an mich dem
kleinen Kerl vorsichtig zu nähern.

[![](/media/IMG_8201.serendipityThumb.jpg)](/media/IMG_8201.jpg)

Der Wasserspeicher

**Cron wird mein Freund**

Ich musste viel fragen, bekam eine Menge hilfreicher (in normaler
Sprache verfasster) Antworten und innerhalb weniger Stunden -ich denke
beim nächsten Mal sind es einige wenige Minuten- lief darauf Raspbian
(das Betriebssystem) und in dem sogenannten Crontab war eingerichtet
dass er einmal am Tag, für Zeit X die Steckdose mit der Pumpe anmachen
solle.

[![](/media/IMG_8195.serendipityThumb.jpg)](/media/IMG_8195.jpg)

Der untere Teil, mit Tomaten, Chili, Knoblauch, Majoran, Lilien uvm.

Ein bisschen stolz, aber auch sehr verwundert sass ich nun da, kratze
mich am Kopf und überlegte warum ich, wenn dass doch so einfach ist,
nicht schon viel mehr in diese Richtung gemacht habe.

**Features? MEHR Features!**

Kurz darauf war der wssiütww-Workshop und ich lernte noch viel mehr. Ich
nahm mir vor das ganze Kleinteilig anzugehen. Jetzt erst mal einfach nur
die Pflanzen überleben lassen und später dann eine Status E-Mail,
Kameraüberwachung und einen Bodefeuchtesensor in das System einzubauen.
Denn, das ist ja kein fixes System eines namenhaften Herstellers,
sondern (wenn auch keinesfalls von mir entwickelt und mit ganz viel
Hilfe und Unterstützung durch den Space) meines! :)
[video_bewaesserung](/media/video_bewaesserung "video_bewaesserung")
Ich schloss mein 60l Fass (der Vorratsbehälter des ganzen) an, machte
ein paar Testläufe, justierte hier ein bisschen, rückte dort ein wenig
und es lief alles wie es sollte. Stolz und sehr sehr dankbar, antwortete
ich mit ein paar Bildern im Forum, dankte allen beteiligten von Herzen
und führte kurz meine Pläne für die Zukunft aus. Nach kurzer Zeit ging
ein Raunen durch den Thread, warum ich dass denn nicht alles gleich
machen würde. Wieder von mir die Antwort, dass das zu aufwändig,
kompliziert und so von mir nicht zu machen sei. Nächster Post war dass
man mir eine USB-Kamera zu Überwachung leihe, direkt mit dabei wie ich
die in den bestehenden Crontab Befehl einbaue und zack noch eins später
ein Tutorial wie ich mir eine Statusmail -mit Bild- zuschicken lasse.

```
$ apt-get remove msmtp heirloom-mailx
$ apt-get install mailutils postfix
$ rm -f .netrc -msmtp .mailrc
```

dann kommt eine wunderschöne install-"GUI"

Hier wähle ich:

```
General type of mail configuration
Satellite system
System Mail Name:
pizero.cfs.im (ich empfehle eine domain auszudenken. Sie wird
lediglich als absender verwendet, muss also nicht existieren)
SMTP relay host:
smtp.gmail.com:587
```

Dann editiere ich /etc/postfix/main.cf. Irgendwo sollte schon
`relayhost = smtp.gmail.com:587` stehen.

Ganz ans ende hinzufügen:

```
smtp_sasl_auth_enable = yes
smtp_sasl_password_maps = hash:/etc/postfix/smtp_auth
smtp_sasl_security_options = noanonymous
smtp_use_tls = yes
smtp_tls_CAfile = /etc/ssl/certs/ca-certificates.crt
smtp_tls_security_level = secure
# Ich hab kein ipv6... und irgendwie denkt der dass es so ist
inet_protocols = ipv4
```

Unter https://myaccount.google.com/apppasswords erstelle ich mir ein
"App-spezifisches passwort"
Eine neue datei /etc/postfix/smtp_auth mit folgendem inhalt: (hinter
dem doppelpunkt das neue passwort, davor deinen gmail-account)

```
smtp.gmail.comich@gmail.com:fj2hg92hfgpsh
```

Und noch ein paar kommandos:

```
$ postmap hash:/etc/postfix/smtp_auth
$ systemctl restart postfix
$ systemctl enable postfix

$ echo "inhalt" | mailx -s "test" ich@gmail.com
mit journalctl -f -u postfix kannst du sehen wie postfix die mail im
hintergrund versendet...
```

Da ist allerdings ein Bug drin, [den man so lösen
kann](https://bugs.launchpad.net/ubuntu/+source/postfix/+bug/1519331)

bzw. sagte mir der gute Feerich (wie ist die maskuline Form?) der mir
dabei half als ich wieder kurz vor einem Nervenzusammenbruch stand, dass
das anders zu lösen sei:

> „ich hab eine viel lustigere loesung gefunden: alle 5 minuten wird
> einfach die datei per crontab überschrieben mit dem was sie sein
> sollte"

**Pic or it didn\'t happen**

Kurzum, das ganze hat vor knapp anderthalb Wochen begonnen. Heute
bekomme ich noch die USB-Kamera geliehen, -die ich sogar mittlerweile
selbst in das System einbauen kann- und dann bin ich weiter mit meiner
automatischen Bewässerungsanlage, als ich es mir je hätte träumen
lassen.

[![](/media/IMG_8203.serendipityThumb.jpg)](/media/IMG_8203.jpg)

und so unscheinbar sieht das ganze fertig aufgebaut aus.

**tl;dr: Hackerspace Member sein ist toll und macht schlau!**

Ich bin mir sicher dass ich in Zukunft mehr mit diesem ganzen
Geheimbündlerischen Elektronikzeugs machen werde, ich habe einen neuen
kleinen Freund der Pi heisst und ich bin sehr glücklich und dankbar zu
einem Haufen von Menschen zu gehören, nein, gehören zu dürfen, die mich
so toll unterstützt und eine neue Welt eröffnet haben! Danke!
