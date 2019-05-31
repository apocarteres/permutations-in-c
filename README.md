# permutations-in-c

Simple permutaion puzle is defined like:

- Given integer N which is greater than zero
- Given three numbers A,B,C which are in range [>0 and <10]

The task is to find out how many possible ways to express given N with sum of A,B and C and print out
these valid permutations.

Examples:

n = 1, a=2,b=3,c=4
answer is 0 ways, cause we can't express 1 by any combination of 2,3 and 4

n = 2, a=2,b=3,c=4
answer is 1

n = 3, a=2,b=3,c=4
answer is 1

n = 4, a=2,b=3,c=4
answer is 2 cause: 2+2 and 4

n = 5, a=2,b=3,c=4
answer is 2 cause: 2+3 and 3+2

n = 5, a=2,b=1,c=3
answer is 10 cause: 11111, 1112, 1121, 1211, 2111, 23, 32, 113, 131, 311
