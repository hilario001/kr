#include <stdio.h>

int main()
{
    int x = 7;
    int b = 0;
    int i;

    for (i = 0; x != 0; x >>= 1)
        if (x & 01)
            ++b;

    printf("%d\n", b);

    /* x = 111 
     *
     * First iteration:
     *   111
     * & 001
     * -----
     *   001 b = 1;
     *
     * Second iteration:
     *   011
     * & 001
     * ----- 
     *   001 b = 2; 
     *
     *   001
     * & 001
     * ----- 
     *   001 b = 3; Now the last x >>= 1, sets x to 0 */

    int y = 2;
    for (i = 0; y != 0; y &= (y-1))
        ++i;

    printf("%d\n", i);

    /*
     * 3 = 11
     * 3 - 1 = 1 = 10
     *   11
     * & 10
     * ----
     *   10 
     *
     * 10
     * 01
     * --
     * 00
     *
     * 100
     * 011
     * ---
     * 000
     *
     * 101
     * 100
     * ---
     * 100
     *
     * 110
     * 101
     * ---
     * 100
     *
     * 1110
     * 1101
     * ----
     * 1101
     * 
     * x = 7 = 111
     * (x - 1) = 6 = 110
     *   111
     * & 110
     * -----
     *   110
     *
     * x = 15 = 1111
     * (x - 1) = 1110
     *
     *   1111
     * & 1110
     * ------
     *   1110
     * */

    return 0;
}
/*
 *
 * decimal 11 to binary
 *  11 - (1*2^3) = 3 > 1 = 1
 *  2^2 = 4 > 1 = 1
 *  2^1 = 2 > 1 = 1
 *  1 - (1*1^0) = 1 - 1 = 0
 *  ------------------------
 *          1110            
 *
 * decimal 8 to binary
 * 8 - (1*2^3) = 8 - 8 = 0
 * 2^2 = 4 > 1 = 1 
 * 2^1 = 2 > 1 = 1
 * 1 - (1*1^0) = 1 - 1 = 0
 * -----------------------
 *       0110*/

/* 5 in decimal is 0101 in binary, if the left shift
 * is used with a right operand of 1, the bits is shift
 * from right to left by one bit position.
 *
 * if right operand of << is 1:
 * 0  1  0  1
 * <- <- <- <-
 * 1  0  1  0
 *
 * if right operand of << is 2, in 1 byte represention:
 * 0  0  0  0  0  1  0  1
 * 0  0  0  1  0  1  0  0
 * = 20 in decimal
 *
 * 14 & 0177:
 * 0 1 1 1 1 1 1 1
 * 1 0 0 0 1 1 1 1
 * ---------------
 * 0 0 0 0 1 1 1 0 */

/* 83, 8:56 */

/* and - both have a piece of candy
 * or - atleast one have a piece of candy
 * xor - only one has a piece of candy
 *
 * 3 & 5:
 * 011
 * 110
 * ---
 * 010
 *
 * &:
 * 1010
 * 0011
 * ----
 * 0010
 *
 * |:
 * 1010
 * 0011
 * ----
 * 1011
 *
 * ^:
 * 1010
 * 0011
 * ----
 * 1001
 *
 * <<:
 * 1010 << 1 would be 0101
 * 0110 << 2 would be 1000 */

/* Counting in binary
 * 0, 1, 10, 11, 100
 * 0, 1,  2,  3,   4 (In decimal)
 *
 * Adding in binary
 *  10      (2 in decimal)
 *  11      (3 in decimal)
 * ---
 * 101      (5 in decimal)
 *
 * 0 + 1 is 1 as 0 holds no value
 * 1 + 1 is 10 as the next number to 1 in binary is 10 the same logic applies to
 * decimal when adding 1 + 1, which is equals to 2
 *
 * c1: carry 1
 *
 *  1010
 *  1111
 * -----
 * 11001
 *
 * 1010110 (86)
 * 0010111 (23)
 * -------
 * 1101101 (109)
 * 
 * 0 + 1            = 1
 * 1 + 1            = 0 carry the 1
 * c1 + 1 = 10 + 1  = 1 carry the 1
 * c1 + 0 = 1 + 0   = 1
 * 1 + 1            = 0 carry the 1
 * c1 + 0 = 1 + 0   = 1
 * 1 + 0            = 1 (Now combine the result from here to the top)
 *
 * 0 + 1 = 1
 * 1 + 1 = 0 carry the 1
 * 1 + 0 = 1 + 1 = 0 carry the 1
 * 1 + 1 = 10 + 1 = 11
 *
 * Adding in quaternary
 *  23
 *  11
 * ---
 * 100 */

/* x = 1
 * y = 2
 * x & y = 0
 *
 * 01 (1)
 * 10 (2)
 * --
 * 00 */

/* 00001111
 * 01111111
 * 00001111 */
