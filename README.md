# Discrete Math Toolkit

A C++ application with an interactive menu that combines several discrete mathematics and computer science concepts into one console toolkit.

## Tools Included

### Caesar Cipher Decoder
Tests all 26 Caesar shifts and allows the user to select a shift to decrypt alphabetic text while preserving capitalization and punctuation.

### Number Base Converter
Converts nonnegative decimal integers to bases 2 through 16.

### Hamming(7,4) Encoder & Error Corrector
Encodes a value with four bits using Hamming(7,4), simulates an optional error in one bit, calculates the syndrome, corrects the detected bit, and decodes the result.

### Set Operations
Accepts two integer sets and calculates their union, intersection, A - B, and B - A.

### Truth Table Generator
Generates truth tables using XOR, NAND, NOR, XNOR, and logical implication.

## Concepts Demonstrated

- Discrete mathematics
- Boolean logic
- Codes that detect and correct errors
- Caesar cipher transformations
- Number systems and base conversion
- Mathematical set operations
- C++ functions and modular program design
- STL containers and algorithms

## Technologies

- C++17
- Standard Template Library
- `vector`
- `set`
- `bitset`
- `stringstream`
- STL set algorithms

## Compile and Run

Using g++:

```bash
g++ -std=c++17 discrete_math_toolkit.cpp -o discrete_math_toolkit
./discrete_math_toolkit
```

On Windows:

```bash
g++ -std=c++17 discrete_math_toolkit.cpp -o discrete_math_toolkit.exe
discrete_math_toolkit.exe
```

## Menu

```text
========== Discrete Math Toolkit ==========
1. Caesar Cipher Decoder
2. Number Base Converter
3. Hamming(7,4) Encoder & Error Corrector
4. Set Operations
5. Truth Table Generator
0. Exit
```

## Project Structure

```text
discrete-math-toolkit/
├── discrete_math_toolkit.cpp
├── README.md
└── .gitignore
```

## About

This project combines several smaller discrete mathematics exercises into a single organized C++ application. It demonstrates how concepts from logic, number systems, cryptography, coding theory, and set theory can be implemented programmatically.
