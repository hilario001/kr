/* Exercise 1-17. Write a program to print all input lines that
 * are longer than 80 characters. */

#include <stdio.h>

#define VALID_LEN 81
#define MAX_LINE 1000

int get_line(char line[], int max);

int main()
{
    int len;
    char line[MAX_LINE];

    while ((len = get_line(line, MAX_LINE)) > 0) {
        if (len - 2 >= VALID_LEN - 1)
            printf("%s", line);
    }

    return 0;
}

int get_line(char line[], int max)
{
    int c, i;

    for (i = 0; i < max - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;

    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';

    return i;
}
