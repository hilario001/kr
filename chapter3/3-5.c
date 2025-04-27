/* Exercise 3-5. Write the function itob(n,s,b) that converts the integer
n into a base b character representation in the string s. In
particular, itob(n,s,16) formats s as a hexadecimal integer in s. */

#include <stdio.h>
#include <string.h>
#include <limits.h>

#define MAX_LEN 20
#define HEX 16
#define HEX_A 10        // start of hex's alphabet letters
#define HEX_F 15        // end of hex's alphabet letters

void reverse(char s[]);
void itob(int n, char s[], int base);

int main()
{
        char s[MAX_LEN];
        itob(15,s,16);
        printf("%s\n", s);

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

void itob(int n, char s[], int base)
{
        int i, sign;

        i = 0;
        sign = n;

        if (sign < 0 && sign >= -INT_MAX) { /* record sign */
                n = -n;          /* make n positive */
        } else if (sign < -INT_MAX) { /* sign causes overflow when converted to positive */
                n = ~n;
                s[i++] = 1 + (n % base + '0');
                n /= base;
        }

        if (base != HEX) {
                do {      /* generate digits in reverse order */
                        s[i++] = n % base + '0';  /* get next digit */
                } while ((n /= base) > 0);    /* delete it */
        } else {
                do {
                        if (n % base >= HEX_A && n % base <= HEX_F)
                                s[i++] = n % base + ('a' - HEX_A);
                        else
                                s[i++] = n % base + '0';
                } while ((n /= base) > 0);
        }

        if (sign < 0)
                s[i++] = '-';

        s[i] = '\0';
        reverse(s);
}
