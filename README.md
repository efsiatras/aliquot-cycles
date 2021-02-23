# Aliquot Cycles Finder
Finds Aliquot cycles. It also finds how many of those Aliquot cycles included Perfect or Amicable numbers.

## What is an Aliquot cycle?
In mathematics, an **Aliquot sequence** is a sequence of positive integers in which each term is the sum of the proper divisors of the previous term.
If the sequence reaches the number 1, it ends, because the sum of the proper divisors of 1 is 0.

Numbers whose Aliquot sequence terminates in a cycle belong to an **Aliquot cycle**.

## Perfect and Amicable numbers
- A **Perfect number** is a positive integer that is equal to the sum of its positive divisors, excluding the number itself.

- **Amicable numbers** are two different numbers so related that the sum of the proper divisors of each is equal to the other number. 

## Compilation
`$ gcc aliquot_cycles.c -o aliquot_cycles`
## Usage
`$ ./aliquot_cycles`
