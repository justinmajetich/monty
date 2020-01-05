# Monty Bytecode Interpreter

## Introduction
Our program parses and interprets files of Monty bytecode, allowing the user to store integer values to a stack and to perform manipulations on both the stack and contained values. While the supported opcodes (listed below) are limited, they serve to demonstrate the basic structure and functionality of a stack. There is an additional and unrelated folder of brainf*ck scripts in this repository (don't ask - it was a project requirement).

## Installation
To install our interpreter on your Linux machine, clone the contents of this repository into a new directory and compile with the command:

    gcc *.c -o monty


## Usage
To run monty, the user must pass a file containing Monty bytecode as an argument to the program. These Monty language files are conventionally, but not necessarily, given the extension ".m". Our interpreter operates in a non-interactive mode only and cannot receive bytecodes directly. Below is a usage example:

    user$ cat test.m
    push 0
       push    1
    push 2
    pall
    push three
    user$ monty test.m
    2
    1
    0
    L5: usage: push integer
    user$ 

## Supported Oppcodes

| Opcode |  Description|
|--|--|
|**push**|pushes an element to the top of a stack|
|**pall**|prints all of the values in a stack, top-down|
|**pint**|prints the top value in a stack|
|**pop**|removes an element from the top of a stack|
|**swap**|swaps the top two elements of a stack|
|**add**|adds the values of the top two elements of a stack|
|**nop**|does nothing|
|**sub**|subtracts the top element of the stack from the second|
|**div**|divides the second element of the stack by the top|
|**mul**|multiplies the top two elements of a stack|
|**mod**|takes the remainder of the second stack element divided by the top|
|**pchar**|prints the char associated with the value at the top of a stack|
|**pstr**|prints the chars associated with each value in a stack, top-down|
|**rotl**|rotates the top element of a stack to the bottom|
|**rotr**|rotates the bottom element of a stack to the top|
|**stack**|toggles program to stack mode (LIFO)|
|**queue**|toggles program to queue mode (FIFO)|
