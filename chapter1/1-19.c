/* Exercise 1-19. Write a function reverse(s) that reverses
 * the character string s. Use it to write a program that
 * reverses its input a line at a time. */

#include <stdio.h>

#define MAX_LINE 1000

int get_line(char line[], int max);
void reverse(char line[], int len);

int main()
{
    char line[MAX_LINE];
    int len;

    while ((len = get_line(line, MAX_LINE)) > 0)
        reverse(line, len);

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

/* print the line starting from the end */
void reverse(char line[], int len)
{
    if (len == 1) {
        printf("\n");
        return;
    }

    /* len -= 2: start before newline and null */
    for (len -= 2; len != 0; len--)
        printf("%c", line[len]);

    printf("%c\n", line[len]);
}
