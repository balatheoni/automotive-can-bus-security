CAN Bus Security & Attack Simulation using Arduino

An Arduino-based automotive cybersecurity project focused on the study of Controller Area Network (CAN Bus) communication, vulnerabilities, attack scenarios, and security mechanisms. The project was developed in a controlled laboratory environment using Arduino CAN Bus Shields, MCP2515-based CAN communication, ECUsim, TeraTerm, and VatiCAN concepts. The experimental setup consists of multiple CAN nodes representing a legitimate Sender, Receiver, and an additional Attacker node used to simulate different communication disruption and message-manipulation scenarios.


Experimental Architecture

The experimental CAN network consists of three main nodes:
Sender: The Sender Arduino generates and transmits legitimate CAN messages over the network.

Receiver: The Receiver monitors the CAN Bus, receives transmitted frames, extracts CAN identifiers and payloads, and displays the received data through the serial interface.

Attacker: A third Arduino is connected to the same CAN network and is used to simulate controlled cybersecurity experiments.


⚠️ Disclaimer

This project was developed strictly for educational and academic research purposes in a controlled laboratory environment. The code and techniques demonstrated here are intended to illustrate CAN Bus security concepts, vulnerabilities, and defensive mechanisms. Do not use this code to interfere with, disrupt, modify, or gain unauthorized access to real vehicles, production systems, or CAN networks. The author is not responsible for misuse of the information or code contained in this repository.
