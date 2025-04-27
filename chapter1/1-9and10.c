/* Exercise 1-9. Write a program to copy its input to its output, replacing each
 * string of one or more blanks by a single blank.
 *
 * Exercise 1-10. Write a program to copy its input to its output, replacing
 * each tab by \t, each backspace by \b, and each backslash by \\.
 * This makes tabs and backspaces visible in an unambiguous way. */

#include <stdio.h>

void replace_multiblanks()
{
    int c;
    while ((c = getchar()) != EOF) {
        putchar(c);
        if (c == ' ') {
            while ((c = getchar()) == ' ');
            putchar(c);
        }
    }
}

int main()
{
    replace_multiblanks();

    // exercise 1-10:
    //int c;
    //while((c = getchar()) != EOF) {
    //    switch(c) {
    //        case '\t':
    //            putchar('\\');
    //            putchar('t');
    //            break;
    //        case '\b':
    //            putchar('\\');
    //            putchar('b');
    //            break;
    //        case '\\':
    //            putchar('\\');
    //            putchar('\\');
    //            break;
    //        default:
    //            putchar(c);
    //    }
    //}

    return 0;
}
