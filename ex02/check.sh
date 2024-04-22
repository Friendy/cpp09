#!/bin/bash
# Check if the number of command-line arguments is correct
if [ $# -ne 1 ]; then
    echo "Usage: $0 <filename>"
    exit 1
fi

# Get the filename from the command-line argument
filename=$1

# Read the numbers from the command-line argument into an array
read -a numbers <<< "$1"

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
    echo "The numbers are sorted."
else
    echo "The numbers are not sorted."
fi
