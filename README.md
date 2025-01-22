# **King's Quest**

## **Overview**

**King's Quest** is a strategy game built in C++. The goal is to guide the king to the throne while solving puzzles, overcoming obstacles, and using characters with unique abilities.

## **Features**

- **Characters**: Wizard (extinguishes fire), Warrior (defeats orcs), Thief (unlocks gates), King (reaches the throne).
- **Obstacles**: Orcs, fire, gates, walls, dwarves, and teleportation cells.
- **Gifts**: Random effects like adding/losing time or eliminating dwarves.

## **Technical Highlights**

- Physics-based collisions with **Box2D**.
- Implements design patterns, including Double Dispatch for collision handling.
- Modular OOP design with smart pointers (`unique_ptr`).
- Dynamic level loading and randomized elements for replayability.

  
