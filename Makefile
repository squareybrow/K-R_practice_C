# Basic Makefile for compiling C and C++ source files individually
# Usage:
#   - For hello.c → run: make hello
#   - For hello.cpp → run: make hello
#   - Run `make clean` to remove compiled files


#CC Compiler for C
#CXX Compiler for C++
CC = gcc
CXX = g++

# -Wall Turns on most commonly useful compiler warnings (like unused variables, comparisons, etc.)
# -Wextra Turns on extra warnings to catch more bugs
# -pedantic Warn anything not standard compliant
# -std=c17 Forces C++17/C17 standard
CFLAGS   = -Wall -Wextra -Wpedantic -pedantic -std=c17 -g -fsanitize=address,undefined
CXXFLAGS = -Wall -Wextra -Wpedantic -pedantic -std=c++17 -g -fsanitize=address,undefined


# Linker flags to include common libraries
LDFLAGS = -lm -lpthread


# For C files → ex: hello.c → run: make hello
%: %.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

# For C++ files → ex: hello.cpp → run: make hello
%: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@ $(LDFLAGS)

.PHONY: clean

clean:
	find . -maxdepth 1 -type f -perm /111 ! -name "*.c" ! -name "*.cpp" -exec rm -f {} +