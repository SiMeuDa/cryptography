## Introduction

- One of the earliest cipher system.

- Each letter is shifted by key value

- Key space is 26

## Algorithm

- Caesar encryption
- Caesar decryption
- Brute-force attack
- Frequency analysis attack

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
./build/caesar
```

Run unit tests

```bash
./build/test_caesar
```

Run brute-force analysis

```bash
./build/brute_force
```

## Reference

- WIKIPEDIA (Caesar cipher)
