#!/bin/bash
# Get the filename from the command-line argument
filename=$1

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

if [ "$sorted" = true ]; then
    echo "sorted."
else
    echo "not sorted."
fi
