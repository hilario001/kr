/* Exercise 3-6. Write a version of itoa that accepts three arguments instead of
two. The third argument is a minimum field min_width; the converted number must be
padded with blanks on the left if necessary to make it wide enough. */

#include <stdio.h>
#include <string.h>
#include <limits.h>

#define MAX_LEN 20

void reverse(char s[]);
void itoa(int n, char s[], int min_width);

int main()
{
        char s[MAX_LEN];
        itoa(10, s, 3);
        printf("%s\n", s); // output: " 1"
        
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

/* itoa:  convert n to characters in s with minimum width of characters */
void itoa(int n, char s[], int min_width)
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

        /* --min_width: to synch with i
         * i-1: i was incremented by the last character stored */
        for (--min_width; i-1<min_width; ++i)
                s[i] = ' ';

        s[i] = '\0';
        reverse(s);
}
