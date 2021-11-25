/*
If A and B are two integers:

1. Bitwise OR -> |
A | B

2. Bitwise AND -> &
A & B

3. Bitwise XOR -> ^
A ^ B

4. Bitwise NOT -> ~
~A (Reverse all the bits of A)

5. Bit Shift Operators -> << and >>
A = A << x 
This will shift all the bits of A towards left by x.
This is equal to multiplying A by the power of 2.

A = A >> x
Shift bits of A by x units towards right.
Equal to diving A by power of 2.


Bit Tricks:
1. x & (x-1) 
will clear the lowest set bit of x

2. x & ~(x-1) 
extracts the lowest set bit of x (all others are clear). Pretty patterns when applied to a linear sequence.

3. x & (x + (1 << n)) = x 
with the run of set bits (possibly length 0) starting at bit n cleared.

4. x & ~(x + (1 << n)) = the run of set bits (possibly length 0) in x, starting at bit n.

5. x | (x + 1) = x 
with the lowest cleared bit set.

6. x | ~(x + 1) = extracts the lowest cleared bit of x (all others are set).

7. x | (x - (1 << n)) = x, with the run of cleared bits (possibly length 0) starting at bit n set.

8. x | ~(x - (1 << n)) = the lowest run of cleared bits (possibly length 0) in x, starting at bit n are the only clear bits.
*/