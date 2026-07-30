# Cryptography

A personal cryptography study and implementation repository written primarily in **C**.

This repository is a long-term project to study, implement, analyze, and document cryptographic algorithms from fundamental concepts to modern cryptographic systems. The primary goal is not only to produce working implementations but also to understand the underlying theory, official specifications, implementation details, and security considerations.

---

## Objectives

* Study cryptographic algorithms from trusted references.
* Implement algorithms in C with readable and maintainable code.
* Verify implementations using official test vectors whenever available.
* Document implementation details and design decisions.
* Explore basic cryptanalysis techniques.
* Build a long-term cryptography engineering portfolio.

---

## Repository Structure

```text
cryptography/

├── classical/         # Classical cryptography
├── block_cipher/      # DES, AES, ...
├── hash/              # SHA family, ...
├── public_key/        # RSA, ECC, ...
├── common/            # Shared utilities
├── docs/              # Study notes and references
├── test/              # Common test utilities
└── README.md
```

Each algorithm is organized as an independent project with its own source code, documentation, and test cases.

---

## Progress

### Classical Ciphers

* [ ] Caesar Cipher
* [ ] Vigenère Cipher
* [ ] Affine Cipher
* [ ] Playfair Cipher

### Block Ciphers

* [ ] DES
* [ ] Triple DES
* [ ] AES-128
* [ ] AES-GCM

### Hash Functions

* [ ] SHA-256
* [ ] SHA-512

### Public-Key Cryptography

* [ ] RSA
* [ ] Elliptic Curve Cryptography (ECC)

### Cryptanalysis

* [ ] Frequency Analysis
* [ ] Index of Coincidence
* [ ] Tetragram Scoring
* [ ] Differential Cryptanalysis (Study)
* [ ] Linear Cryptanalysis (Study)

---

## Development Principles

* Implement algorithms before relying on external libraries.
* Follow official specifications whenever possible.
* Prioritize correctness over optimization.
* Keep implementations simple, readable, and well documented.
* Separate implementation, testing, and documentation.

---

## References

This repository primarily follows official specifications and well-established references.

* Crypto101
* NIST Publications
* FIPS Standards
* RFC Documents
* Academic Papers (when applicable)

Individual projects include more detailed references in their own documentation.

---

## License

This repository is intended for educational and research purposes.

Unless otherwise specified, all source code is released under the MIT License.

