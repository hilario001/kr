/* Exercise 1-22. Write a program to ``fold'' long input lines into two or
 * more shorter lines after the last non-blank character that occurs before
 * the n-th column of input. Make sure your program does something
 * intelligent with very long lines, and if there are no blanks or tabs
 * before the specified column. */

/* Pseudocode:
 * get a character
 * increment column number
 * if character is a newline
 *      print the character
 *      reset column number to 0
 * else if current column is greater than fold column
 *      print a newline
 *      print the character
 *      reset column number to 1
 * else print the character */

#include <stdio.h>

int main(void)
{
    int c;
    int fold_column = 80;
    int n = 0;  // column number
    while ((c = getchar()) != EOF) {
        ++n;
        if (c == '\n') {
            putchar(c);
            n = 0;
        } else if (n > fold_column) {
                putchar('\n');
                putchar(c);
                n = 1;
        } else {
            putchar(c);
        }
    }
    return 0;
}
