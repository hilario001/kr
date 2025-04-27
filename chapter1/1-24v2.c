/* Exercise 1-24. Write a program to check a C program for rudimentary
 * syntax errors like unmatched parentheses, brackets and braces. Don't
 * forget about quotes, both single and double, escape sequences, and
 * comments. (This program is hard if you do it in full generality.) */

#include <stdio.h>

#define NUM_OF_DELIMETERS 6
#define COMMENT 1
#define STRING 2
#define OUT 0

int main()
{
        char delimeters[] = "([{\"'";           // delimeters to keep track of
        int track[NUM_OF_DELIMETERS];           // frequency of delimeters
        int state;                              // in a comment or not
        int c;                                  // current character input
        int i;

        state = OUT;

        while ((c = getchar()) != EOF) {
                if (state == OUT) {
                        if (c == '/') {
                               c = getchar();
                               if (c == '*') {
                                       ++track[5];
                                       state = COMMENT;
                               }
                        } else if (c == '\\') {
                                getchar();
                        } else if (c == '(' || c == ')') {
                                ++track[0];
                        } else if (c == '[' || c == ']') {
                                ++track[1];
                        } else if (c == '{' || c == '}') {
                                ++track[2];
                        } else if (c == '"') {
                                ++track[3];
                                state = STRING;
                        } else if (c == '\'') {
                                ++track[4];
                        }
                } else if (state == COMMENT) {
                        if (c == '*') {
                                c = getchar();
                                if (c == '/') {
                                        ++track[5];
                                        state = OUT;
                                }
                        }
                } else if (state == STRING) {
                        if (c == '\\')
                                getchar();
                        if (c == '"') {
                                ++track[3];
                                state = OUT;
                        }
                }
        }

        for (i = 0; i < NUM_OF_DELIMETERS - 1; i++) {
                if (track[i] % 2 != 0)
                        printf("Unmatched: %c\n", delimeters[i]);
        }
        
        if (track[i] % 2 != 0)
                printf("Unmatched: %s\n", "/*");

        return 0;
}
