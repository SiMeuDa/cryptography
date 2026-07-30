# Git Workflow

This document defines the Git workflow used throughout this repository.

---

# Branch Strategy

For now, all development is performed on the `main` branch.

As the repository grows, feature branches may be introduced.

---

# Commit Message Format

```
<type>: <short description>
```

Examples

```
feat: implement Caesar encryption
fix: correct key schedule bug
docs: update AES README
test: add SHA-256 test vectors
```

---

# Commit Types

## feat

**Purpose**

Introduce a new feature or implementation.

Use when

- Adding a new algorithm
- Adding a new function
- Adding a new module

Examples

```
feat: implement Caesar encryption
feat: implement AES key expansion
feat: add SHA256 compression function
```

---

## fix

**Purpose**

Correct incorrect behavior.

Use when

- Fixing bugs
- Correcting algorithm implementation
- Resolving logical errors

Examples

```
fix: correct padding calculation
fix: resolve endian conversion bug
fix: handle empty input correctly
```

---

## docs

**Purpose**

Documentation changes only.

Use when

- Updating README
- Writing study notes
- Adding references

Examples

```
docs: update README
docs: add AES implementation notes
docs: revise repository roadmap
```

---

## test

**Purpose**

Add or modify tests.

Use when

- Adding official test vectors
- Writing unit tests
- Improving validation

Examples

```
test: add Caesar test cases
test: verify AES with NIST vectors
test: improve RSA validation
```

---

## refactor

**Purpose**

Improve code structure without changing behavior.

Use when

- Splitting functions
- Improving readability
- Removing duplicated code

Examples

```
refactor: simplify key expansion
refactor: split utility functions
```

---

## perf

**Purpose**

Improve performance without changing functionality.

Use when

- Optimizing encryption speed
- Reducing memory usage

Examples

```
perf: optimize MixColumns
perf: reduce memory allocation
```

---

## build

**Purpose**

Build system changes.

Use when

- Updating Makefile
- Changing compiler flags
- Modifying build scripts

Examples

```
build: update Makefile
build: enable sanitizers
```

---

## style

**Purpose**

Formatting changes only.

Use when

- Reformatting code
- Fixing indentation
- Renaming variables for consistency

Examples

```
style: apply repository coding style
style: format source files
```

---

# Commit Policy

Make small and meaningful commits.

Recommended development order

```
Initialize Project
        ↓
Implementation
        ↓
Testing
        ↓
Documentation
        ↓
Refactoring
```

Avoid commits like

```
update
finish
today work
fix
```

Every commit should clearly describe **what changed**.

Good examples

```
feat: implement Caesar decryption

docs: add frequency analysis explanation

test: add official AES test vectors

fix: correct inverse MixColumns
```

---

# General Rules

- Use English only.
- Keep commit messages concise.
- One logical change per commit.
- Test before committing.
- Documentation should be committed together with completed implementations whenever possible.
