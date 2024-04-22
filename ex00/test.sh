#!/bin/bash

echo "*****subject test******"
./btc "tests/input.txt"
echo "******test********"
./btc "tests/input1.txt"
# echo "**err test**"
# ./btc "tests/input.txt"
# echo "**no err test**"
# ./btc "tests/input.txt"
echo "**bad input file path1**"
./btc "tests/inputttt.txt"
echo "**bad input file path1**"
./btc ""
echo "****no input file test****"
./btc