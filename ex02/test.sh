#!/bin/bash

ARG=`jot -r 3 1 100000 | tr '\n' ' '`
./PmergeMe $ARG