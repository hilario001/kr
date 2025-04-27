/* Exercise 1-24. Write a program to check a C program for rudimentary
 * syntax errors like unmatched parentheses, brackets and braces. Don't
 * forget about quotes, both single and double, escape sequences, and
 * comments. (This program is hard if you do it in full generality.) */

/* (,[,{,",',comments
 *
 * Reflection:
 *
 * The number of situations to not consider a character as having to have
 * a matching character are discrete.
 *
 * The rule as to determine if there is a syntax error is if there is a missing
 * character that is meant to pair an opening character, in code, it can mean
 * that the frequency of both pairs is an odd number.
 *
 * The line that the closing character is in doesn't matter, no matter how far
 * it is from the opening character.
 *
 * There could be other matching characters inside the body of other matching
 * characters
 *
 * The line and column position of the opening character that has a missing pair
 * is a feature for later on and need not to be worry about yet.
 *
 * The process is per character input, line is possible but I can't picture a
 * vision yet.
 *
 * The order of when to check if the current character matches any opening
 * characters matters.
 *
 * The process of determining if an opening character has to have a closing
 * character is the most crucial and the hard part of the program.
 *
 * The process of figuring out when and when not to consider if a character is
 * an opening or closing character has to be done per character.
 *
 * When not to consider ( as an opening character:
 *      1. When inside a comment
 *      2. When inside a single quote
 *      3. When inside a double quote
 *
 *  Pseudocode:
 *      get a line
 *      get a character until end of the line
 *      if the character is ( or )
 *          check if it is inside a comment
 *              don't increment its frequency
 *          check if it is inside a single quote
 *              don't increment its frequency
 *          check if it is inside a double quote
 *              don't increment its frequency
 *          else, increment its frequency
 *
 * */

#include <stdio.h>

#define MAX_LEN 1000
#define N 6     /* number of characters to keep track of e.g. open parenthesis,
                 * open bracket */
#define IN 1
#define OUT 0
int get_line(char line[], int max_len);
int main(void)
{
    int c;
    /* store frequency of the characters that need to be tracked */
    int freq[N];
    char matchc[N] = {'(','[','{','"','\''}; 
    /* matchc: characters that need to be tracked */
    char line[MAX_LEN];
    int len;
    int j;
    int i = 0;
    int state = OUT;

    for (int i = 0; i < N; i++)
        freq[i] = 0;

    while (len = get_line(line, MAX_LEN) > 0) {
        for (j = 0; j < N; j++) {
            while (i < len && state == OUT) {
                if (line[i] == '/' && line[i + 1] == '*') {
                    state = IN;
                    ++freq[N];
                } else if (line[i] == matchc[j] || line[i] == matchc[j]
                        && line[i - 1] == '\''
                        && line[i + 1] == '\'');
                else {
                    ++freq[j];
                }
                ++i;
            }
            while (i < len && state == IN) {
                if (line[i] == '*' && line[i + 1] == '/') {
                    ++freq[N];
                    state == IN;
                }
                ++i;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        if (freq[i] % 2 != 0)
            printf("Syntax error, unmatched %c\n", matchc[i]);
    }
    return 0;
}
int get_line(char line[], int max_len)
{
    int i, c;

    for (i = 0; i<max_len-1 && (c = getchar()) != EOF && c != '\n'; i++)
        line[i] = c;

    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}
