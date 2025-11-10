# C++ Basics: Data Structures & Algorithms

Learning repository covering C++ fundamentals, data structures, and algorithms.

## Setup

**Requirements**:

- GCC/G++ compiler
- IDE: [VS Code](https://code.visualstudio.com/download) (recommended)
- C/C++ extensions for VS Code(Optional)

**Compile and run**:

```bash
# Fundamentals
g++ -o pointers src/fundamentals/pointers.cpp
./pointers

# Data structures
g++ -o stack src/data-structures/stack.cpp
./stack

# Algorithms
g++ -o bubble src/algorithms/bubble-sort.cpp
./bubble
```

## PostgreSQL Setup

For database interaction, install PostgreSQL C++ binding library:

1. **Install libpq-dev**:

```bash
sudo apt install libpq-dev
```

2. **Compile and run**:

```bash
g++ -o user src/fundamentals/db/user.cpp -I/usr/include/postgresql -lpq
./user
```

**Note**: Update database credentials in `user.cpp` before running.

## Learning Path

1. **Fundamentals** - Start here if new to C++
   - `fundamentals/pointers.cpp` - Pointer basics
   - `fundamentals/structs.cpp` - Struct usage
   - `fundamentals/recursion.cpp` - Recursion examples
   - `fundamentals/db/user.cpp` - PostgreSQL database integration

2. **Data Structures** - Core DSA implementations
   - Stack: LIFO structure
   - Queue: FIFO structure
   - Linked Lists: singly, doubly linked
   - Binary Trees: basic and advanced

3. **Algorithms** - Search and sort implementations
   - Sorting: bubble, insertion, selection
   - Searching: linear, binary
   - Graph: Dijkstra's shortest path

## References

1. Grokking Algorithms, by Aditya Y. Bhargava
2. Data Structures and Algorithm Analysis in C++, 4th edition, by Mark Allen Weiss
