# 6-Channel Transmitter Using Arduino Nano & NRF24L01  

## Overview  
This project demonstrates how to build a **6-channel wireless transmitter** using an **Arduino Nano**, **NRF24L01 module**, and **joysticks**. It improves upon a previous **4-channel version**, adding **better joystick accuracy** and **more control channels** for enhanced functionality.  

## Improvements from Previous Version  
**Better Joystick Accuracy** – Higher-resolution potentiometers for smoother control  
**Increased Channels** – Upgraded from 4 channels to 6 channels for more functions  
**More Control Options** – Two toggle switches for additional commands  

## Components Required  
- **Arduino Nano**  
- **NRF24L01 module** (for wireless communication)  
- **Two Joysticks**  
- **Two Toggle Switches**  
- **Jumper Wires**  
- **Soldering Iron**  
- **7.4V Battery Pack** (for power supply)  

## Assembly Steps  
1. Use an old RC transmitter for better-quality joysticks and switches.  
2. Desolder the joystick from the circuit board.  
3. Follow the circuit diagram to connect the joysticks, switches, and NRF24L01 module to the Arduino Nano.  
4. Secure all connections and ensure proper power distribution.  

## Circuit Diagram  
 *Refer to the project documentation for a complete circuit diagram.*  

## Programming the 6-Channel Transmitter  
The Arduino Nano reads joystick and switch inputs and transmits them via **NRF24L01**.  
