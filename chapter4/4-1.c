/* Exercise 4-1. Write the function strindex(s,t) which returns the
position of the rightmost occurrence of t in s, or -1 if there is
none. */

#include <stdio.h>

#define MAX_LINE 1000 /* maximum input line length  */

int strindex(char source[], char searchfor[]);
int get_line(char line[], int max);

/* find all lines matching pattern  */
int main()
{
        char pattern[] = "grep"; /* t, pattern to search for  */
        char line[MAX_LINE]; /* s */

        while (get_line(line, MAX_LINE))
                return strindex(line, pattern);
}

/* get_line: get line into s, return length  */
int get_line(char s[], int lim)
{
        int i, c;

        i = 0;
        while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
                s[i++] = c;
        if (c == '\n')
                s[i++] = c;
        s[i] = '\0';
        return i;
}

/* strindex: return rightmost index of t in s, -1 if none  */
int strindex(char source[], char searchfor[])
{
        int i, j;

        for (i = 0; source[i] != '\0'; ++i) {
                for (j = 0; searchfor[j] != '\0' && source[i] == searchfor[j]; ++i, ++j)
                        ;
                if (j > 0 && searchfor[j] == '\0')
                        return i-j;
        }
        return -1;
}
