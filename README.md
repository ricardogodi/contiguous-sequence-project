# Contiguous Sequence Project README

## Project Overview
The Contiguous Sequence Project introduces a hybrid data structure in C++, designed to manage sequences of integers with adaptive resizing capabilities. This structure merges the direct access speed of arrays with the flexible sizing characteristic of linked lists. The implementation is focused on optimizing memory management, ensuring that the dynamic array adjusts its size efficiently and maintains the integrity of the sequence continuity without memory leaks.

## Technical Description
- **Dynamic Resizing:** The system starts with a predefined array size and expands dynamically, doubling its capacity when the current space is exhausted to accommodate new elements.
- **Memory Management:** Careful management of memory allocation and deallocation is employed to prevent memory leaks and ensure data integrity during transfers between array sizes.
- **Accessibility:** Provides direct element access similar to arrays, while maintaining the ability to resize like linked lists.
- **Efficiency:** Implements efficient operations for inserting, finding, and removing elements, with considerations for edge cases such as boundary conditions.

## Core Functionalities
- **insertAt:** Inserts an element at a specified index, resizing the array when necessary.
- **find:** Searches for an element and returns its index if found.
- **removeAt:** Removes an element at a specified index, shifting elements as needed to fill the gap.
- **iterate:** Applies a function to each element in the sequence, modifying the sequence in-place.
- **Array Access:** Overloaded [] operators for both reading and writing to sequence positions, with bounds checking.

## Files Included
- **main.cpp:** Main executable demonstrating the functionalities of the Contiguous Sequence.
- **ContiguousSequence.h:** Header file defining the ContiguousSequence class and its interface.
- **ContiguousSequence.cpp:** Implementation file for the ContiguousSequence class.

## Compilation and Execution
Compile the project using the provided Makefile commands to handle building and running the application efficiently:

## Compile the project
```bash
make all
```
## Run the compiled program
```bash
make run
```
## Clean up compiled binaries
```bash
make clean
```
