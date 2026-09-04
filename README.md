# so_long

A small 2D game developed in C using the MiniLibX graphical library as part of the 42 curriculum.

The goal of the project is to create a simple playable game where the player must collect all the collectibles before reaching the exit, while respecting the map constraints.

## 🎮 About the Project

**so_long** is a project from the 42 curriculum focused on graphical programming, event handling, map parsing, textures, and memory management in C.

The project uses **MiniLibX** to create the game window, display the game elements, handle keyboard events, and manage player movement.

## 👥 Team & Contributions

This project was completed as a **team project**.

### Noura Akebli

I was responsible for:

* **Map parsing and validation**
* Reading and processing `.ber` map files
* Checking the validity of the map
* Verifying the required map elements (`P`, `E`, `C`, `0`, `1`)
* Implementing the map validation logic
* **Textures**
* Loading and managing the game's textures
* Preparing the graphical assets used by the game

### Oumaima Chachi

My teammate **Oumaima Chachi** was responsible for the **other parts of the project**, including the remaining game logic and implementation.

We worked together to integrate our respective parts into a functional game.

## ✨ Features

* 2D graphical game using MiniLibX.
* `.ber` map parsing.
* Map validation.
* Player movement.
* Collectibles.
* Exit.
* Walls and map boundaries.
* Texture management.
* Movement counter.
* Path validation to ensure the map is playable.
* Error handling and memory management.

## 🛠️ Technologies

* **C**
* **MiniLibX**
* **Makefile**
* **Git**
* **Unix/Linux**

## 📋 Map Rules

The map uses the following characters:

| Symbol | Meaning     |
| ------ | ----------- |
| `1`    | Wall        |
| `0`    | Empty space |
| `P`    | Player      |
| `C`    | Collectible |
| `E`    | Exit        |

A valid map must contain:

* Exactly one player (`P`).
* Exactly one exit (`E`).
* At least one collectible (`C`).
* Walls surrounding the map.
* A valid path allowing the player to collect all collectibles and reach the exit.

Example:

```text
111111111
100000001
101110101
100C0C001
101010101
10P0000E1
111111111
```

## 🚀 Installation

Clone the repository:

```bash
git clone <repository-url>
cd so_long
```

Compile the project:

```bash
make
```

## ▶️ Usage

Run the game with a `.ber` map:

```bash
./so_long maps/map.ber
```

## ⌨️ Controls

| Key       | Action        |
| --------- | ------------- |
| `W` / `↑` | Move up       |
| `A` / `←` | Move left     |
| `S` / `↓` | Move down     |
| `D` / `→` | Move right    |
| `ESC`     | Exit the game |

## 🧠 Concepts Practiced

Through this project, I practiced:

* File parsing.
* Map validation.
* 2D arrays and grid manipulation.
* Pointers and structures.
* Dynamic memory allocation.
* Texture loading.
* Graphical programming with MiniLibX.
* Event handling.
* Keyboard input.
* Flood-fill/path validation.
* Memory management.
* Makefiles and compilation.
* Team collaboration using Git.

## 🗂️ Project Structure

```text
so_long/
├── Makefile
├── include/
├── src/
├── textures/
├── maps/
└── README.md
```

The exact organization may vary depending on the implementation.

## 🎯 Project Objective

The objective of **so_long** was to create a functional 2D game while learning how to combine C programming with graphical programming and algorithms.

Working as a team also allowed us to divide the project into different parts and integrate our implementations into one final application.

## 👤 Authors

**Noura Akebli**
Map Parsing & Validation — Textures

**Oumaima Chachi**
Game Logic & Other Project Components

42 Network
