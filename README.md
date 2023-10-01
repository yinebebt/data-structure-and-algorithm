# Data Structure and Algorithm

## Class exercises and projects
Here you can get exercise codes for basic topics on DSA including additional projects.

## Installation
 Belows are tools you need to have:
 - IDE, such as [visual studio code(recommended)](https://code.visualstudio.com/download)
 - GCC compiler


## Usage
- Clone the project to your local machine, open with vscode.
- install c/c++ related extensions
- Make sure to install external libraries(only for the projects) like postgreql's c++ binding linrary-libpq.
    - `sudo apt install libpq-dev`
    - add `/usr/include/postgresql` into your c++ configration
    - Make sure you compile via specifying linker as in:
        `g++ -o user src/projects/db/user.cpp -I/user/include/postgresql -lpq`

## Contributing
Contributions are always welcome.

## Authors
 [Yinebeb T.](https://github.com/Yinebeb-01)

## References
1. [Grokking Algorithm, by Aditya Y. Bhargava](https://www.amazon.com/Grokking-Algorithms-illustrated-programmers-curious/dp/1617292230)
2. [Data Structures and AlgorithM Analysis in C++, 4th edition, by Mark Allen Weiss](https://www.amazon.com/Data-Structures-Algorithm-Analysis-C/dp/0273769383)
