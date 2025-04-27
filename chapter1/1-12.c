/* not exercise 1-12 */
#include <stdio.h>

#define OUT 0
#define IN 1

int main()
{
    int c;
    int state = OUT;
    while ((c = getchar()) != EOF) {
        putchar(c);
        if (c == ' ' || c == '\t') {
           state = OUT; 
           putchar('\n');
           while ((c = getchar()) == ' ' || c == '\t')
               ;
           putchar(c);
        } else if (state == OUT) {
            state = IN;
        }
    }

    return 0;
}
