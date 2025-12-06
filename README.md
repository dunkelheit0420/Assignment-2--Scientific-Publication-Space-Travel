# 🚀 StarFleet Simulation Project

## Overview
This project is a C++ simulation of futuristic spacecraft for **StarFleet**.  
It models different ship types (Cargo Ship, Starship, Warbird) and their subsystems:
- **Payload** (passengers, cargo, workstations)
- **Propulsion** (fuel, light level, energy consumption)
- **Weapons** (torpedoes, laser cannons)

The simulation demonstrates acceleration, travel, fuel generation, and combat scenarios.

---

## ✨ Features

### Payload
- Tracks passenger, cargo, and workstation masses.
- Supports adding to each category.
- Provides total mass calculation.
- Generates a report of payload details.

### Propulsion
- Manages fuel levels (max 1000 kg).
- Consumes fuel based on Einstein’s equation \(E = mc^2\).
- Generates fuel from light exposure over time.
- Reports current fuel and light levels.

### Weapons
- Tracks torpedoes (max 100) and laser cannons (max 8).
- Fires torpedoes if available.
- Fires lasers, consuming energy proportional to time × number of cannons.
- Reports current weapon inventory.

### Ships
- **Cargo Ship**: Two payloads, one propulsion system.
- **Starship**: One payload, one propulsion system, one weapon system.
- **Warbird**: One payload, two propulsion systems, two weapon systems.
- Each ship can:
  - Accelerate (consuming fuel).
  - Travel (generating fuel and updating distance).
  - Engage in combat (fire torpedoes and lasers).
  - Generate detailed reports.

---

## 📁 Project Structure

- `Payload.h` / `Payload.cpp` – Payload subsystem  
- `Propulsion.h` / `Propulsion.cpp` – Propulsion subsystem  
- `Weapons.h` / `Weapons.cpp` – Weapons subsystem  
- `Starship.h` / `Starship.cpp` – Starship implementation  
- `Warbird.h` / `Warbird.cpp` – Warbird implementation  
- `CargoShip.h` / `CargoShip.cpp` – Cargo Ship implementation  
- `StarFleet.cpp` – Main test driver

---

## 📊 Expected Output

The program will:
- Accelerate ships by fractions of the speed of light.
- Generate fuel during travel.
- Print reports for each ship (speed, distance, fuel, payload, weapons).
- Simulate combat (torpedoes and lasers fired).

### Example snippet

ACCELERATION REPORT 1:
The war bird is travelling at 2997924.58 m/s and has travelled 0.00 m.
Propulsion: fuel level: 996.67 kg of matter/anti-matter, light level: 0.10.
Payload: mass of passengers: 30000.00 kg, mass of cargo: 100000.00 kg, mass of workstations: 3000.00 kg.
Weapon: number of laser cannons: 5, number of torpedoes: 100.

---

## 👨‍💻 Authors
- Daryl Gonzales  
- Shay Symonette  
- Yevhenii Karaman (Eugene)  

---

## 📜 License
This project is for academic purposes (**SEP101 Assignment 2**).  
Feel free to adapt and extend for learning or experimentation.
