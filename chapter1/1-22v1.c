/* Exercise 1-22. Write a program to ``fold'' long input lines into two or
 * more shorter lines after the last non-blank character that occurs before
 * the n-th column of input. Make sure your program does something
 * intelligent with very long lines, and if there are no blanks or tabs
 * before the specified column. */

/* Tried to copy vim's gq command behavior,
 * doesn't behave exactly the same.
 *
 * Pseudocode:
 * get a line
 * if the line exceeds the fold column
 *     if there were blanks at the fold column
 *         replace the blanks with a newline
 *     if there was unfinished text at the fold column
 *         replace the blanks before the unfinished
 *         text with a newline
 *     go to next fold column and repeat the process
 *     print the line when there are no fold column left
 * if the line did not exceed the fold column
 *     print the line */

#include <stdio.h>

#define MAX_LINE 1000

int get_line(char line[], int max);
void fold(char line[], int len, int fold_column);

int main(void)
{
    char line[MAX_LINE];
    int len;
    int fold_column = 80;

    while ((len = get_line(line, MAX_LINE)) > 0) {
        if (len - 2 > fold_column - 1)
            fold(line, len, fold_column);
        else
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

void fold(char line[], int len, int fold_column)
{
    int trailing, i, tmp;

    tmp = trailing = 0;

    for (i = fold_column - 1; i < len; i += fold_column) {
        if (line[i] == ' ' || line[i] == '\t') {
            /* count blanks between the first non-blank
             * character of the "next line" and the
             * last non-blank character of the "previous
             * line" */
            while (line[i] == ' ' || line[i] == '\t')
                ++i;

            --i;
            while (line[i] == ' ' || line[i] == '\t') {
                --i;
                ++trailing;
            }

            /* replace one blank with a newline */
            ++i;
            line[i] = '\n';
            /* decrement the blanks for the one replaced blank */
            --trailing;
            len -= trailing;
            /* move the array to the left to replace the blanks */
            for (tmp = i + 1; trailing > 0 && tmp <= len; tmp++)
                line[tmp] = line[tmp + trailing];
            trailing = 0;
        } else if (line[i] != ' ' && line[i] != '\t') {
            /* go to the last non-blank character before
             * the unfinished text */
            while (line[i] != ' ' && line[i] != '\t')
                --i;

            while (line[i] == ' ' || line[i] == '\t') {
                --i;
                ++trailing;
            }

            ++i;
            line[i] = '\n';
            --trailing;
            len -= trailing;

            for (tmp = i + 1; trailing > 0 && tmp <= len; tmp++)
                line[tmp] = line[tmp + trailing];
            trailing = 0;
        }
    } 
    printf("%s", line);
}
