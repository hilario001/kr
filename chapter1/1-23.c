/* Exercise 1-23. Write a program to remove all comments from a C program.
 * Don't forget to handle quoted strings and character constants properly.
 * C comments don't nest. */

/* 03/01/25: Added comment and escape handling in code, not in pseudocode
 * Pseudocode:
 * get a character
 * if the character is a slash
 *      get the next character after the slash
 *      if the next character is an asterisk (a multiline comment)
 *          make the state of the program to "in a comment"
 *          while the state is "in a comment"
 *                  get a character until an asterisk is encountered
 *                  get the next character after the asterisk
 *                  if character after the asterisk is a slash
 *                      make the state "not in a comment"
 *                  if character after the asterisk is NOT a slash
 *                      keep the state "in a comment" to repeat the process
 *      if the next character is also a slash (one line comment)
 *          don't print the characters until the newline
 *      if the next character is NOT an asterisk or a slash
 *          print a slash (the value of c variable got overwritten by the character next
 *          to it)
 *          print the character
 * if the character is not a slash
 *      print the character */

#include <stdio.h>

#define IN 1        // in a comment
#define OUT 0       // not in a comment

int main(void)
{
    int c;
    int state = OUT;
    while ((c = getchar()) != EOF) {
        if (c == '/') {
            c = getchar();
            if (c == '*') {
                state = IN;
                while (state == IN) {
                    while ((c = getchar()) != '*')
                        ;
                    c = getchar();
                    if (c == '/')
                        state = OUT;
                }
            } else if (c == '/') {
                while ((c = getchar()) != '\n')
                    ;
                putchar(c);
            } else {
                putchar('/'); 
                putchar(c);
            }
        } else if (c == '"') {
            putchar(c);
            while ((c = getchar()) != '"')
                putchar(c);
            putchar(c);
        } else if (c == '\\') {
            putchar(c);
            putchar(getchar());
        } else {
            putchar(c);
        }
    }
    return 0;
}
