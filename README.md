# Printf
A simplified version of the function printf, meant to teach about variadic functions, and their uses. For this exercise we didn't need to replicate the buffer that the original printf uses.

## Main logic

Printf takes as parameters a string and all the things you would want to print. For this exercise we only needed to deal with some cases:
  - Integers;
  - Unsigned integers;
  - Numbers in their hexadecimal form;
  - Pointer addresses;
  - Characters;
  - Strings;

The function goes through the string until it finds a "%". When it does it checks the next character to see what it would need to print. When it's identified it gets the value in the variadic list, converts the value into a string and prints it, and moves to the next item in the variadic list. Repeating until the end of the string
