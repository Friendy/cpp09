#!/bin/bash
echo "*****subject test******"
./btc "tests/input.txt"
echo "******test dates not in db********"
./btc "tests/middle.txt"
echo "******month day limits test********"
./btc "tests/months.txt"
echo "******err test*******"
./btc "tests/err.txt"
echo "**no err test**"
./btc "tests/input_perfect.txt"
echo "**bad input file path1**"
./btc "tests/inputttt.txt"
echo "**bad input file path1**"
./btc ""
echo "****no input file test****"
./btc
echo "******total mess test*******"
./btc "tests/bad.txt"