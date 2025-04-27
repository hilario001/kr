/* Exercise 3-4. In a two's complement number representation, our
version of itoa does not handle the largest negative number, that
is, the value of n equal to -(2^wordsize-1). Explain why not.
Modify it to print that value correctly, regardless of the
machine on which it runs. */
/* Why not:
 * The largest negative number -(2^wordsize-1) or -2147483648 in 32 bits
 * when converted to its two's complement causes overflow since the largest
 * positive number is 2^(wordsize-1)-1 or 2147483647 in 32 bits and makes the
 * largest negative number circles back to its value when converted.
 * The original program produces "-(" as its output if the value
 * of n is equal to -2147483648 because n % 10 + '0' produces
 * 40 which is equal to '('in ASCII and n / 10 produces a negative number
 * since n is already negative which makes the loop terminate. */

#include <stdio.h>
#include <string.h>
#include <limits.h>

#define MAX_LEN 20

void reverse(char s[]);
void itoa(int n, char s[]);

int main()
{
        char s[MAX_LEN];
        itoa(-2147483648, s);
        printf("%s\n", s);

        // trying things
        int x = 2147483648;
        int test1 = x%10;
        printf("%d\n", test1); // produces negative

        int y = 2147483647;
        int test2 = y%10;
        printf("%d\n", test2); // produces positive

        int z = -2147483648;
        printf("z: %d\n", -z);
        /* the value circles back to itself due to overflow when
         * converted to its two's complement
         *
         * ~z = 2147483647
         * ~z+1 = -2147483648 */

        return 0;
}

void reverse(char s[])
{
        int i, tmp, len;

        len = strlen(s);

        for (--len, i = 0; i < len; ++i, --len) {
                tmp = s[i];
                s[i] = s[len];
                s[len] = tmp;
        }

}

/* itoa:  convert n to characters in s */
void itoa(int n, char s[])
{
        int i, sign;

        i = 0;
        sign = n;

        if (sign < 0 && sign >= -INT_MAX) { /* record sign */
                n = -n;          /* make n positive */
        } else if (sign < -INT_MAX) { /* sign causes overflow when converted to positive */
                n = ~n;
                s[i++] = 1 + (n % 10 + '0');
                n /= 10;
        }

        do {      /* generate digits in reverse order */
                s[i++] = n % 10 + '0';  /* get next digit */
        } while ((n /= 10) > 0);    /* delete it */
        if (sign < 0)
                s[i++] = '-';
        s[i] = '\0';
        reverse(s);
}
