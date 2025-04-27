/* Exercise 1-21. Write a program entab that replaces strings of blanks by the minimum 
number of tabs and blanks to achieve the same spacing. Use the same tab stops as for detab. 
When either a tab or a single blank would suffice to reach a tab stop, which should be given 
preference? */

#include <stdio.h>

int main(void)
{
        int nb;     // number of current blanks
        int tabs;   // number of tabs to print instead of spaces
        int c;
        int blanks; // remainder blanks

        tab_size = 8;
        nb = tabs = 0;

        while ((c = getchar()) != EOF) {
                if (c == ' ') {
                        ++nb;
                } else {
                        /* replace 7 blanks that is followed by a tab by a tab */
                        if (c == '\t' && nb == tab_size - 1)
                                nb = 0;

                        // there were blanks convertable to tabs
                        for (tabs = nb / tab_size; tabs > 0; tabs--)
                                putchar('\t');

                        /* the blanks wasn't enough to be converted as tabs
                         * or print the remainder blanks from the replaced blanks */
                        for (blanks = nb % tab_size; blanks > 0; blanks--)
                                putchar(' ');

                        putchar(c);
                        nb = 0;
                }
        }
        return 0;
}
