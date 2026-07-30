# Style Guide

## Language

- C11 preferred
- Use `<stdint.h>` fixed-width integer types.

## Naming

### Variables

Use `snake_case`.

Example:

```c
uint8_t round_key[16];
```

### Functions

```c
aes_encrypt();
aes_decrypt();
```

### Macros

```c
AES_BLOCK_SIZE
AES_KEY_SIZE
```

## Formatting

- 4-space indentation
- K&R braces
- Maximum practical line length: about 100 characters

## Comments

Document every public function using Doxygen-style comments.

## File Names

Lowercase with underscores.

Example:

```
key_schedule.c
key_schedule.h
```
