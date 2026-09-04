# so_long

A small 2D game developed in C using the MiniLibX graphical library.

The goal of the project is to create a simple playable game where the player must collect all the collectibles on a map before reaching the exit, while respecting the map's constraints.

## 🎮 About the Project

**so_long** is a project from the 42 curriculum focused on graphical programming, event handling, map parsing, and memory management in C.

The project introduces the use of **MiniLibX**, a lightweight graphical library provided by 42, to create a window, display textures, handle keyboard events, and manage a simple game loop.

The player must:

* Move around the map.
* Collect all collectibles.
* Reach the exit after collecting everything.
* Avoid invalid moves outside the map or through walls.
* Complete the game using the minimum number of necessary movements.

## ✨ Features

* 2D graphical game.
* Map loaded from a `.ber` file.
* Player movement using the keyboard.
* Collectible items.
* Exit that becomes available after collecting all collectibles.
* Walls and map boundaries.
* Movement counter displayed in the terminal.
* Map validation.
* Flood-fill/path validation to ensure the map is playable.
* Basic error handling.
* Proper resource and memory management.

## 🛠️ Technologies

* **C**
* **MiniLibX**
* **Makefile**
* **Git**
* **Unix/Linux**

## 📋 Map Rules

The map must follow the required format and contain:

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

Run the game with a valid `.ber` map:

```bash
./so_long maps/map.ber
```

The game window will open and the player can move using the supported keyboard controls.

## ⌨️ Controls

| Key       | Action        |
| --------- | ------------- |
| `W` / `↑` | Move up       |
| `A` / `←` | Move left     |
| `S` / `↓` | Move down     |
| `D` / `→` | Move right    |
| `ESC`     | Exit the game |

## 🧠 Concepts Practiced

This project allowed me to practice and strengthen several important C programming concepts:

* Parsing files.
* Working with 2D maps.
* Dynamic memory allocation.
* Structures.
* Pointers.
* String manipulation.
* File descriptors.
* Event handling.
* Keyboard input.
* Basic graphical programming.
* Map validation.
* Flood-fill algorithms.
* Memory management.
* Makefiles and compilation.

## 🗂️ Project Structure

```text
so_long/
├── Makefile
├── include/
│   └── so_long.h
├── src/
│   ├── parsing/
│   ├── map/
│   ├── movement/
│   ├── rendering/
│   └── ...
├── textures/
│   └── ...
├── maps/
│   └── ...
└── README.md
```

> The exact structure may vary depending on the implementation.

## 🧪 Compilation

The project is compiled using the provided `Makefile`.

Available commands:

```bash
make
make clean
make fclean
make re
```

* `make` — compiles the project.
* `make clean` — removes object files.
* `make fclean` — removes object files and the executable.
* `make re` — recompiles the project from scratch.

## 🎯 Project Objective

The main objective of **so_long** is to build a small functional 2D game while learning how to combine:

**C programming + algorithms + file parsing + graphics + event handling.**

This project was an opportunity to work with a graphical library for the first time and to understand how user input and graphical events can interact with a C program.

## 👤 Author

**Noura Akebli**

42 Network

