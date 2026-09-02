# Underwater Wireless Communication System Using IR Signals

This project demonstrates a physical prototype of an underwater wireless optical communication system. The setup facilitates real-time data transmission between a transmitter node and a receiver node submerged in an aquatic medium, serving as a low-cost alternative to traditional acoustic communication methods.

## ⚙️ How It Works

* **Data Transmission:** The transmitter node uses an Arduino Uno to sample manual inputs, encoding data commands into high-frequency infrared light pulses via a submerged IR LED using the NEC protocol stack.
* **Signal Propagation:** Infrared light signals travel through the water channel, acting as the physical medium carrying the data frames.
* **Signal Reception:** A TSOP1738 IR receiver module detects the transmitted pulses at a specific frequency layer, filtering and stabilizing the hardware input lines.
* **Output Processing:** A secondary receiver Arduino decodes the incoming 8-bit command bitmasks, running a toggle verification path to update status indicators and confirm successful data packet delivery.

## 💻 Tech Stack & Protocol Specifications

* **Hardware:** Arduino Uno R3, TSOP1738 IR Receiver, High-Intensity IR LED, Indicator LEDs
* **Language:** Embedded C / C++ (Arduino Framework)
* **Library Configuration:** `IRremote.hpp` (v4.x+)
* **Protocol Standard:** NEC Protocol Framework (Target Address: `0x00FF`)
