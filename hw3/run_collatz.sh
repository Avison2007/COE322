#!/bin/bash

# Loop through starting values from 1 to 100.
for n in {1..100}
do
    echo $n | ./collatz
done
