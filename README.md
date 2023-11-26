# Formal Foundations (of Computer Science)

A single file for an assignment during my Formal Foundations (CMPS 341) course in the Spring of 2006.

## Build

```bash
$ make
g++ -c perceptron.cpp
g++ -o perceptron perceptron.o
```

## Run

```bash
$ ./perceptron
Welcome to the Single-Node Perceptron Program.

How many terms will be in the p vector? 5

Single-Node Perceptron Program: Main Menu

1. Train Network
2. Test Network
3. Print Weights and Bias Terms
4. Exit

Your choice? 3

The weights are:
w1 = 60056.4
w2 = 47571.4
w3 = 58937.1
w4 = 44892.7
w5 = 61194.9

bias = 46159.2

Single-Node Perceptron Program: Main Menu

1. Train Network
2. Test Network
3. Print Weights and Bias Terms
4. Exit

Your choice? 4
```
