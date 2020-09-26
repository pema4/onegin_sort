# Text sorting program

## What is it

This is the second task for the C/C++ course at ISP RAS.

Program sorts lines of UTF-8 text, comparing them by letters (skipping punctuation and other symbols).
Programming language is C.

## How to build

Clone this resository with `git clone --recursive https://github.com/pema4/onegin_sort`

You need these tools:
* CMake
* Doxygen (optional)
* bash

Now you can build it with `cmake -B build`

## Usage

### Main application

Main application can be lauched with `build/apps/main`.
It accepts three command line arguments:
1. file for unmodified text
2. file for sorted text
3. file for text sorted in reverse order.
It reads text from stdin.

`run_hamlet.sh` downloads "THE TRAGEDY OF HAMLET, PRINCE OF DENMARK",
sorts it and puts output files into `example` directory.

Similarly, `run_onegin.sh` downloads "Eugene Onegin" in russian and sorts it too.

### Test suite

Tests suite can be launched with `cmake --build build -t test`
