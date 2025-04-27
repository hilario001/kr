/* Exercise 3-2. Write a function escape(s,t) that converts characters like newline
and tab into visible escape sequences like \n and \t as it copies the string t
to s. Use a switch. Write a function for the other direction as well, converting
escape sequences into the real characters. */

#include <stdio.h>

void char_to_escape(int t);
void escape_to_char(int t);

int main()
{
        int c;
        
        while ((c = getchar()) != EOF)
                escape_to_char(c);
                //char_to_escape(c);

        return 0;
}

void escape_to_char(int c)
{
        if (c == '\\') {
                switch (c = getchar()) {
                case 'n':
                        putchar('\n');
                        break;
                case 't':
                        putchar('\t');
                        break;
                default:
                        putchar(c);
                }
        } else {
                putchar(c);
        }
}

void char_to_escape(int c)
{
        switch (c) {
        case '\n':
                putchar('\\');
                putchar('n');
                break;
        case '\t':
                putchar('\\');
                putchar('t');
                break;
        default:
                putchar(c);
        }
}
