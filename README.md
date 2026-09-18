# Solar Tracker Using Arduino & LDR

An automatic solar panel system that tracks sunlight using LDR sensors to maximize power generation.

## Components Required
- Arduino UNO
- 2x LDR (Light Dependent Resistor) - A0, A1
- 1x Servo Motor SG90 - Pin 11
- Solar Panel (5V)
- 2x 10kΩ Resistor
- Breadboard & Jumper Wires

## How It Works
1. Two LDRs (LDR1 and LDR2) measure light intensity on left and right side
2. Arduino compares readings from A0 and A1
3. If LDR1 > LDR2, servo rotates left (towards more light)
4. If LDR2 > LDR1, servo rotates right
5. If difference < ERROR (10), it stays stable to avoid shaking
6. Solar panel mounted on servo always faces the sun

## Arduino Code
The code uses `Spoint` variable to track servo position (90° initial).
- `ERROR = 10` prevents jitter in low light changes
- Servo moves step-by-step with 80ms delay for smooth tracking
- Serial Monitor prints LDR values for debugging

File: `solar_tracker.ino`

## Connection Details
- LDR1 -> A0 with 10k resistor to GND
- LDR2 -> A1 with 10k resistor to GND
- Servo Signal -> Pin 11 (PWM)
- Servo Power -> 5V & GND
- LDRs powered by 5V rail

## Advantages
- 30-40% more power than fixed panel
- Simple and low cost
- Automatic operation

## Created By
saikumar2510 
