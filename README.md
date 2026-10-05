**CAN Bus Security & Attack Simulation using Arduino**

An Arduino-based automotive cybersecurity project focused on the study of Controller Area Network (CAN Bus) communication, vulnerabilities, attack scenarios, and security mechanisms. The project was developed in a controlled laboratory environment using Arduino CAN Bus Shields, MCP2515-based CAN communication, ECUsim, TeraTerm, and VatiCAN concepts. The experimental setup consists of multiple CAN nodes representing a legitimate Sender, Receiver, and an additional Attacker node used to simulate different communication disruption and message-manipulation scenarios.

Project Overview

The Controller Area Network (CAN Bus) is widely used in automotive and embedded systems to allow Electronic Control Units (ECUs) to exchange information efficiently.

Although CAN provides reliable real-time communication, the classical CAN protocol was not originally designed with modern cybersecurity threats in mind.

Some important security limitations include:

- Lack of built-in message authentication
- Lack of built-in encryption
- Broadcast-based communication
- Trust between connected nodes
- Possibility of message injection
- Susceptibility to spoofing and flooding attacks
- Limited protection against unauthorized nodes

The purpose of this project was to experimentally investigate these characteristics using a small-scale CAN Bus test environment.


Objectives

The main objectives of the project were to:

- Establish CAN Bus communication between Arduino nodes
- Simulate Sender and Receiver ECUs
- Monitor CAN messages in real time
- Investigate CAN message IDs and payloads
- Introduce an additional attacker node
- Simulate message manipulation and communication disruption
- Observe the impact of malicious or incorrect CAN traffic
- Study possible CAN security mechanisms
- Experiment with secure CAN communication concepts using VatiCAN


Experimental Architecture

The experimental CAN network consists of three main nodes:
Sender: The Sender Arduino generates and transmits legitimate CAN messages over the network.

Receiver: The Receiver monitors the CAN Bus, receives transmitted frames, extracts CAN identifiers and payloads, and displays the received data through the serial interface.

Attacker: A third Arduino is connected to the same CAN network and is used to simulate controlled cybersecurity experiments.


⚠️ Disclaimer

This project was developed strictly for educational and academic research purposes in a controlled laboratory environment. The code and techniques demonstrated here are intended to illustrate CAN Bus security concepts, vulnerabilities, and defensive mechanisms. Do not use this code to interfere with, disrupt, modify, or gain unauthorized access to real vehicles, production systems, or CAN networks. The author is not responsible for misuse of the information or code contained in this repository.
