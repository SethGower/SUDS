# SUDS
Shower Use Detection System

| Wiring Diagram | Circuit Geography| Proto Board |
| :------------- | :------------- | :- |
| ![Wiring Diagram](https://github.com/SethGower/SUDS/raw/master/SUDS.png)|![Geography](https://github.com/SethGower/SUDS/raw/master/SUDS%20Geography.png)| ![Proto board, herein "The board"](https://github.com/SethGower/SUDS/raw/master/Proto%20Board%20Eagle%20Pic.png)|


## Current Progress
LEDs on the wall on exterior of bathroom show the occupancy status of the showers (ON == occupied). Uses limit switches on the shower locks to determine occupancy.


## Parts
1. [Various resistors: E-Projects EPC-103/A-0005-A04. 220 ohm(x4) and 110 ohm(x1)](https://www.amazon.com/gp/product/B00E9YQQSS/ref=oh_aui_detailpage_o09_s00?ie=UTF8&psc=1)
2. Green Light Emitting Diodes
3. [Adafruit Perma-Proto HAT for Raspi. P2310](https://www.adafruit.com/product/2310)
4. [Raspberry Pi 2 Model B](https://www.raspberrypi.org/products/raspberry-pi-2-model-b/)
5. Limit switch (x2)

## Wiring

Each shower has an identical setup except for color codes.


###### The Shower Switches
There are two sets of wires used in the ethernet cable going to the showers. The far shower consists of the Orange channel (Solid orange and white and orange), and the close shower using the Brown channel (solid brown and white and brown). The solid wire carries current to the `COM` terminal. The striped wire carries current from the `NO` terminal (default off terminal).

###### The Board
Current flows from the 5V rail on the board on the same row as the GPIO pin that the certain shower uses. Then through a resistor to the adjacent proto row and to the `COM` terminal on the corresponding switch (connects to the ethernet cable via the green cable for the close shower, and blue for the far). Across the gap, the switch's `NO` terminal connects via a white wire for the close shower and yellow for far shower.

###### SUDS Box
Another ethernet cable (using solid orange, striped orange, and solid green) connects the board to the LEDs in the SUDS box next to the door. Current flows to the anode on the LED (when the switch is closed) through the solid channel on the ethernet cable (top/close is on the green and is connected on both ends to a yellow wire, bottom/far is orange and is connected on both sides to a blue wire). Both share a common ground.


## Future Expansion
Will be writing a web app that shows the status of the showers for ease of access. Will possibly collect statistics to create a heat map of when the showers are most used.
