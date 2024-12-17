#!/bin/bash

# Compile the program
g++ $(find src -name "*.cpp") -o bin/program

# Run the program
./bin/program

# Delete the compiled program
rm bin/program
