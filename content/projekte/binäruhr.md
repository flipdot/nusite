+++
title = "Binäruhr"
+++

Die Binäruhr zeigt die Uhrzeit im Space an. Leider ist der Name ein
bisschen fehlleitend, weil sie nicht ganz binär funktioniert.

## Aufbau

```
+----+----+----+----+----+----+----+----+
| B4 | B3 | B2 | B1 | G4 | G3 | G2 | G1 |
+----+----+----+----+----+----+----+----+
```

B = blaue [LEDs](LEDs)

G = gelbe [LEDs](LEDs)

## Uhrzeit ablesen

### Stunden

Die Stunden werden durch die blauen [LEDs](LEDs) dargestellt.
Wenn eine LED an ist, hat sie den Wert 1, wenn sie aus ist, hat sie den
Wert 0:

```
  B4 * 2^4 + B3 * 2^3 + B2 * 2^2 + B1 * 2^1
= B4 * 8   + B3 * 4   + B2 * 2   + B1 * 1
= Stunden
```

### Minuten

Die Minuten werden durch die gelben [LEDs](LEDs) dargestellt.
Je heller eine LED ist, desto näher ist sie dem Faktor 1, je dunkler,
desto näher dem Faktor 0. Dadurch lässt sich die Zeit nur sehr grob
definieren:

```
  G4 * 15 + G3 * 15 + G2 * 15 + G1 * 15
```

### Beispiel

Hier ein kleines Beispiel, um zu lernen, wie man die Uhrzeit liest:

```
+----+----+----+----+----+----+----+----+
| ██ | ██ |    | ██ |    | ░░ | ██ | ██ |
+----+----+----+----+----+----+----+----+
```

Beim Beispiel wäre die Uhrzeit: `8 + 4 + 1 = 13` Stunden und
`~7 + 15 + 15 = 37` Minuten, also `13:37`.
