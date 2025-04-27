/* Exercise 2-6. Write a function setbits(x,p,n,y) that returns x with
 * the n bits that begin at position p set to the rightmost n bits of y,
 * leaving the other bits unchanged. */
#include <stdio.h>

int setbits(int x, int p, int n, int y);

int main()
{
        int x = 5;
        int y = 10;
        //setbits(x, 3, 4, y);
        signed char i = 125;
        signed char overflow = i+i;
        printf("%d\n", overflow);
        return 0;
}

//int setbits(int x, int p, int n, int y)
/{
//        y & ~(~0 << n);
//        return 
//}
