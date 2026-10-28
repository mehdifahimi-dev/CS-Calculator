# CS-Calculator
A C++ calculator designed for computer science students.

## Bitwise Calculator

Supports:
    - AND
    - OR
    - XOR
    - NOT
    - Left Shift
    - Logical Right Shift
    - Arithmetic Right Shift

NOTE: Left shift uses unbounded-width binary values. Bits are not discarded when they move beyond a fixed width such as 8-bit or 32-bit. The result grows as needed.

## 2's Complement
    - Finds the 2's complement of a binary number.

NOTE: The bit width entered by the user is preserved. For example, '0001' is treated as a 4-bit value and becomes '1111', while '00000001' is treated as an 8-bit value and becomes '11111111'.

## Web Version
A web version of CS Calculator is currently being developed to make the calculator accessible directly through a browser. 
The web interface is being built with assistance from AI (ChatGPT), which has been used for guidance while learning HTML, CSS, and JavaScript. The calculator's core functionality was originally developed in C++.