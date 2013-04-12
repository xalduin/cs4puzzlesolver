cs4puzzlesolver
===============
A generic puzzle solving program that uses breadth first search to solve puzzles.
Puzzles that are specified with a class deriving from Config are able to be solved using the generic solver.

Compiler requirements:
======================
* CMake >= 2.6
* A relatively recent version of clang with c++11 support and libc++ (I am running clang 4.2 which is based on 3.2)

To compile:
===========
1. Create a directory ./bin in the root of the repository
2. From within the new directory, use cmake ../src to generate a Makefile
3. Use make to build all project files

Example:

    mkdir bin
    cd bin
    cmake ../src
    make

Running
=======
Check [info/readme](info/readme) for more information about the project and how to run each individual puzzle.
