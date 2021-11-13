+++
title = "OPT Controller"
+++

Common crypto software runs on systems with an OS. Our approach is to
reduce the attack surface of an operating system with its user programs
by delegating the crypto part to a system as simple as possible.

## System scetch:

<!-- {{attachment:sketch.gif|system setup|width="500"}} -->

An AVR controller with keyboard and display is used to gather the plain
text which is held only in the controllers RAM. An One Time Pad
encryption is performed using a large keyfile stored on the SDCARD
attached to the AVR.

The AVR communicates using an ES8266 module.

The encrypted text is sent to an central server. That could be done via
SMTP or an simple HTTP request.

The encrypted answer is downloaded and decrypted in the AVR. the plain
text is shown on the display attached to the AVR.
