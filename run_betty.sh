#!/bin/bash

# Loop through all .c files in the current directory
for file in *.c; do
    # Run Betty style checker on each .c file
    betty-style "$file"
done

# Loop through all .h files in the current directory
for file in *.h; do
    # Run Betty style checker on each .h file
    betty-style "$file"
done
