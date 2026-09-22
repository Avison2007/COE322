#!/bin/bash

if [ "$#" -ne 1 ]; then
    echo "Usage: $0 nonnegative_integer"
    exit 1
fi

if [ "$1" -lt 0 ]; then
    echo "Error: argument must be nonnegative"
    exit 1
fi

echo "$1" | ./newton
