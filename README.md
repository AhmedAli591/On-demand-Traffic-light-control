# On-Demand Traffic Light Control

The **On-Demand Traffic Light Control** system is designed to enhance traffic management by allowing dynamic and responsive control of traffic signals. This system aims to reduce congestion and improve traffic flow efficiency based on real-time demand, prioritizing pedestrian safety and accommodating emergency vehicle passage.

## Project Overview

This project implements a traffic light control system using the **ATmega32 microcontroller** programmed in **C**. The system operates in two primary modes:

- **Normal Mode**: Traffic lights function on a fixed timer, cycling through green, yellow, and red phases for both vehicles and pedestrians.
- **Pedestrian Mode**: Activated by a pedestrian request button, this mode temporarily halts vehicle traffic to allow safe pedestrian crossing.

## Key Features

- **Real-Time Traffic Monitoring**: Continuously assesses traffic conditions to adjust signal timings dynamically.
- **Pedestrian Request System**: Pedestrians can request crossing signals, prompting an immediate response from the system.
- **Adaptive Signal Control**: Traffic light durations adjust based on current traffic density, optimizing flow and reducing wait times.
- **Emergency Vehicle Priority**: Detects emergency vehicles and alters signal phases to provide them with priority passage.

## System Components

- **Microcontroller**: ATmega32
- **Programming Language**: C
- **Development Environment**: Atmel Studio
- **Simulation Tool**: Proteus 8 Professional

## Hardware Requirements

- **ATmega32 Microcontroller**: The central unit controlling the traffic light sequences.
- **LEDs**: Six LEDs representing the traffic lights for vehicles (green, yellow, red) and pedestrians (green, yellow, red).
- **Push Button**: An on-demand crosswalk button allowing pedestrians to request crossing signals.

## Software Requirements

- **Atmel Studio**: Integrated development environment for programming the ATmega32.
- **Proteus 8 Professional**: Simulation software used to model and test the traffic light system.

## System Functionality

- **Normal Mode Operation**:

  - Vehicle green light is active for 5 seconds.
  - Vehicle yellow light blinks for the next 5 seconds.
  - Vehicle red light is active for 5 seconds.
  - Pedestrian lights remain red until a request is made.

- **Pedestrian Mode Activation**:
  - Pressing the pedestrian request button interrupts the normal cycle.
  - Vehicle traffic is halted (red light) to allow pedestrians to cross safely.
  - After a predetermined time, the system returns to normal mode.

## Future Enhancements

- **Integration with Traffic Sensors**: Implement sensors to detect real-time vehicle counts, further optimizing signal timings.
- **Wireless Communication**: Enable communication between traffic lights for coordinated control across intersections.
- **Data Logging and Analytics**: Collect traffic data for analysis and future planning.
