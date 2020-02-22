+++
title = "Track a Bike"
date = 2017-04-17T09:00:00
author = "wegenerd"
+++
Wir haben uns mit unserem lokalen Fahrradleihsystem
[Konrad](http://www.konrad-kassel.de) auseinandergesetzt und uns dabei
die App etwas näher angeschaut. Mithilfe von
[mitmproxy](https://mitmproxy.org/) konnten wir die Funktionsweise der
API nachvollziehen und sammeln so seit einigen Wochen die Daten darüber,
wann welches Fahrrad an welcher Station steht.  
  
Die Rohdaten liegen als XML Dateien vor. Zur besseren Verarbeitung
konvertieren wir diese zunächst zu CSV Dateien, welche sich leicht in
Datenbanksysteme importieren lassen. Bisher haben wir die Graphdatenbank
[Neo4J](https://neo4j.com/) verwendet.  
  
Zunächst haben wir einzelne Tagesausschnitte visualisiert. Hier sieht
man etwa alle Fahrten, welche am 29.03. zwischen 07:00 und 08:00 Uhr
angetreten wurden:  
  
[![](https://flipdot.org/blog/uploads/track-a-bike_2017-03-29_07_00-2017-03-29_08_00.serendipityThumb.png)](https://flipdot.org/blog/uploads/track-a-bike_2017-03-29_07_00-2017-03-29_08_00.png)  
  
Auffällig sind dabei die hier bereits rot markierten Fahrten: Sie alle
haben gemeinsam, dass sie fast gleichzeitig an der selben Station
starteten und auch endeten. Vermutlich handelt es sich hier um einen
Fahrradtransporter, welchen die DB Rent einsetzt, um die Fahrräder
gleichmäßig in der Stadt zu verteilen. Auch sind uns Fahrräder
aufgefallen, welche im Zuge eines Fahrradtransportes erst einige Tage
später wieder eingesetzt wurden - vermutlich wurden diese zur Wartung
in eine Werkstatt gebracht und später wieder eingesetzt.  
  
Um zu sehen, welche Stationen mehr mit Transportern versorgt werden
müssen als andere, haben wir die folgende Grafik erstellt:  
  
[![](https://flipdot.org/blog/uploads/track-a-bike_popular.serendipityThumb.png)](https://flipdot.org/blog/uploads/track-a-bike_popular.png)  
  
Die roten Pfeile zeigen, zwischen welchen Stationen Fahrradtransporte
stattgefunden haben, während die grünen Pfeile die regulären Fahrten der
Kunden darstellen. Zu sehen ist, dass 4,3% aller Transportfahrten
zwischen den Stationen "Uni-Kassel / Menzelstr." und "ICE Bahnhof /
Willy-Brandt-Platz" stattfinden. Nur die 8 häufigsten Transporte und
Fahrten zwischen zwei Stationen sind aus Übersichtlichkeitsgründen
dargestellt.  
  
Man sieht hier schnell bestätigt, was man vielleicht bereits im Gefühl
hatte: Vom ICE Bahnhof aus schnappt man sich schnell ein Rad und fährt
bergab zum Kirchweg oder zur Menzelstraße, während kaum einer Lust hat,
den Berg wieder hochzuradeln - das erledigen dann die Transporter von
Konrad. Auch an der Weserspitze sammeln sich die Räder, welche dann von
Konrad auf Hauptbahnhof / ICE Bahnhof / FES verteilt werden müssen.  
  
[![](https://flipdot.org/blog/uploads/track-a-bike_timeline.serendipityThumb.png)](https://flipdot.org/blog/uploads/track-a-bike_timeline.png)  
Diese Grafik zeigt, wieviele Fahrräder an der jeweiligen Station
verfügbar sind. Auch hier sieht man einigen Stationen an, ob sie auf
Bergen oder in Tälern liegen. Die Station "Ihringshäuser Str. / KVG"
etwa hat eine konstante Abnahme der Fahrradzahl, bis sie wieder
schlagartig ansteigt. Kein Wunder, dass kaum jemand dort hinauf radeln
möchte.  
  
Übrigens: Insgesamt konnten wir 491 Fahrräder und 58 Stationen finden.
Das sind zwei Stationen mehr, aber 9 Fahrräder weniger als auf der
Konrad Website angegeben.  
  
Eine Fragestellung von uns war, herauszufinden, ob und wie man die
Transportfahrten optimieren / minimieren kann, jedoch fehlen uns hier
noch gute Ansätze.  
  
Über weitere Ideen zur Auswertung der Daten / Informationsgewinnung /
Ansätze für maschinelle Lernverfahren freuen wir uns\!  
  
Alle hier gezeigten Grafiken wurden mit der Datenbasis vom 25.03. -
14.04.2017 erstellt.
