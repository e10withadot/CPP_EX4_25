# MyContainer with Multiple Iterators

This project implements a custom container class `MyContainer<K>` with various iterator implementations that traverse the container elements in different orders. The project is written in C++ and uses the doctest framework for testing.

## Features

- Generic container that can store any data type
- Multiple iterator implementations:
  - `AscendingOrder`: Traverses elements in ascending order
  - `DescendingOrder`: Traverses elements in descending order  
  - `Order`: Traverses elements in original insertion order
  - `ReverseOrder`: Traverses elements in reverse insertion order
  - `SideCrossOrder`: Traverses elements alternating between smallest and largest
  - `MiddleOutOrder`: Traverses elements starting from middle, then left, then right, etc.

## Building and Running

Requirements:
- gcc
- make

To build and run:

```bash
# Build and run main program
make main

# Run tests
make tests

# Run with Valgrind memory checking
make valgrind

# Clean build files
make clean
```

## Testing

The project uses the doctest framework for unit testing. Tests cover:
- Basic container operations
- Iterator functionality
- Reset operations
- Copy constructors

Run the tests with:

```bash
make tests
```