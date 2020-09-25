# Text sorting program

## What is it

This is the second task for the C/C++ course at ISP RAS.

Program sorts lines of UTF-8 text, comparing them by letters (skipping punctuation and other symbols).
Main programming language is C.

## How to build

Clone this resository with `git clone --recursive https://github.com/pema4/onegin_sort`

You will need these tools:
* CMake
* Doxygen (optional)
* bash

Now you can build it with `cmake -B build`

## How to run

### Main application

Main application is lauched with `build/apps/main`.
It reads text from stdin and prints sorted lines to stdout.

`run_hamlet.sh` downloads "THE TRAGEDY OF HAMLET, PRINCE OF DENMARK" and sorts it.

Similarly, `run_onegin.sh` downloads "Eugene Onegin" in russian and sorts it too.

### Test suite

Tests suite can be launched with `cmake --build build -t test`

