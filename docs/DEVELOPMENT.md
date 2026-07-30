# Development Guide

## Purpose
This document defines the common development rules for every cryptographic implementation in this repository.

## Standard Project Layout

```text
Algorithm/
├── include/
├── src/
├── test/
├── docs/
├── README.md
└── Makefile
```

## Directory Rules

- `include/` : Public headers
- `src/` : Implementation source code
- `test/` : Test programs and official test vectors
- `docs/` : Algorithm-specific notes
- `README.md` : Overview, build instructions, references
- `Makefile` : Build configuration

## General Principles

1. Correctness before optimization.
2. Follow official specifications whenever possible.
3. Avoid unnecessary external libraries.
4. Every implementation should have test code.
5. Every algorithm should include references.

## Required Deliverables

- Source code
- Header files
- Tests
- README
- References
