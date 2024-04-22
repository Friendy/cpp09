#!/bin/bash
# Check if the number of command-line arguments is correct
if [ $# -ne 1 ]; then
    echo "Usage: $0 <filename>"
    exit 1
fi

# Get the filename from the command-line argument
filename=$1

# Check if the file exists
if [ ! -f "$filename" ]; then
    echo "File '$filename' not found."
    exit 1
fi

# Read the numbers from the file into an array
numbers=($(cat "$filename"))

# Iterate through the numbers and check if they are sorted
sorted=true
for (( i = 1; i < ${#numbers[@]}; i++ )); do
    if (( ${numbers[i]} < ${numbers[i-1]} )); then
        sorted=false
        break
    fi
done

# Print the result
if [ "$sorted" = true ]; then
    echo "The numbers in '$filename' are sorted."
else
    echo "The numbers in '$filename' are not sorted."
fi
