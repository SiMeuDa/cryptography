## Introduction

# mathmatic
- moular archimatic
- C<sub>i</sub> = (P<sub>i</sub> + K<sub>i</sub> ) mod 26

## Algorithm


## Project Structure

├── include/
├── src/
├── analysis/
├── test/
├── docs/
└── README.md

## Build

This project uses **CMake** as its build system.

### Requirements

- CMake 3.20 or later
- C11 compatible compiler
  - GCC
  - Clang

### Build

```bash
cmake -S . -B build
cmake --build build
```

The generated executables will be located in the `build/` directory.

## Usage

Run the main program

```bash
./build/
```

Run unit tests

```bash
./build/
```

Run brute-force analysis

```bash
./build/brute_force
```

## Reference

- WIKIPEDIA (Caesar cipher)
