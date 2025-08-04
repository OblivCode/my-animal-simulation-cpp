# Animal Simulation

A simple 2D animal simulation built with C++ and SFML, featuring animals in a natural environment.

## Description

This project simulates animals (rabbits and wolves) moving around in a 2D world with food sources (carrots). The simulation uses object-oriented programming principles with inheritance and polymorphism.

## Features

- **Animals**: Rabbits and wolves with different behaviors
- **Food System**: Carrots that animals can interact with
- **2D Graphics**: Real-time rendering using SFML
- **Object-Oriented Design**: Clean class hierarchy with inheritance

## Prerequisites

- C++ compiler with C++17 support (g++)
- SFML 2.5+ installed
- Make build system

## Project Structure

```
playground/
├── src/
│   ├── main.cpp                    # Entry point
│   ├── ui/
│   │   ├── window.h/cpp           # Window and rendering
│   │   └── colours.h              # Color definitions
│   ├── models/
│   │   ├── animals/
│   │   │   ├── animal.h/cpp       # Base animal class
│   │   │   ├── rabbit.h           # Rabbit implementation
│   │   │   └── wolf.h             # Wolf implementation
│   │   └── foods/
│   │       ├── food.h/cpp         # Base food class
│   │       └── carrot.h           # Carrot implementation
├── makefile                       # Build configuration
└── README.md                      # This file
```

## Building and Running

### Build the project:
```bash
make
```

### Run the simulation:
```bash
make run
```

### Clean build files:
```bash
make clean
```

## Controls

- Close the window to exit the simulation

## Classes

### Animals
- **Animal**: Base class with position, name, age, and movement
- **Rabbit**: Inherits from Animal
- **Wolf**: Inherits from Animal

### Food
- **Food**: Base class for all food items
- **Carrot**: Specific food type for rabbits

## Technologies Used

- **C++17**: Modern C++ features
- **SFML**: Graphics and window management
- **Make**: Build system

## Future Improvements

- [ ] Animal AI and behaviors
- [ ] Food consumption mechanics
- [ ] Population dynamics
- [ ] Different terrains
- [ ] Sound effects
- [ ] Configuration files

## License

This project is for educational purposes.

---

*Built as a learning project to explore C++, OOP concepts and game development.*

