/*Exercise 1-18. Write a program to remove trailing blanks
 * and tabs from each line of input,
 * and to delete entirely blank lines. */

#include <stdio.h>

#define MAXLINE 1000

int get_line(char line[], int max);
int rm_blanks(char line[], int len);

int main(void)
{
    int len;
    char line[MAXLINE];

    while ((len = get_line(line, MAXLINE)) > 0) {
        /* there was a line that is not entirely blank */
        if (rm_blanks(line, len) > 0)
            printf("%s", line);
    }

    return 0;
}

int get_line(char line[], int max)
{
    int c, i;
    for (i = 0; i < max - 1 && (c = getchar()) != EOF && c != '\n'; i++)
        line[i] = c;

    if (c == '\n') {
        line[i] = c;
        ++i;
    }

    line[i] = '\0';
    return i;
}

/* remove entirely blank lines
 * and remove trailing blanks if line is not blank*/
int rm_blanks(char line[], int len)
{
    int i = 0;
    while (line[i] == ' ' || line[i] == '\t')
        ++i;

    if (line[i + 1] == '\0')
        return 0;

    len -= 2;
    while (line[len] == ' ' || line[len] == '\t') 
        --len;

    len += 2;
    line[len - 1] = '\n';
    line[len] = '\0';
    return len;
}
