/* Exercise 1-20. Write a program detab that replaces tabs in 
 * the input with the proper number of blanks to space to the next
 * tab stop. Assume a fixed set of tab stops, say every n columns.
 * Should n be a variable or a symbolic parameter? 
 * 
 * Should n be a variable depends if the program will be used to 
 * interact with a user allowing them to set their tab preferences
 * and symbolic constant if only the programmer will use the program */

#include <stdio.h>

int main(void)
{
        int tab_size = 4;
        int c;      // current character
        int n;      // column number
        int nb;     // number of blanks to print instead of a tab

        n = 0;
        while ((c = getchar()) != EOF) {
            if (c == '\t') {
                nb = tab_size - n % tab_size;
                while (nb > 0) {
                    putchar(' ');
                    --nb;
                    ++n;
                }
            } else {
                putchar(c);
                ++n;
                if (c == '\n')
                    n = 0;
            }
        }
        return 0;
}
