/* Exercsise 1-6. Verify that the expression getchar() != EOF is 0 or 1.
 * Exercise 1-7. Write a program to print the value of EOF. */

#include <stdio.h>

int main()
{
    int c = getchar() != EOF;
    printf("%d\n", c);

    printf("%d\n", EOF);
    return 0;
}
