/* Exercise 1-11. How would you test the word count program?
 * What kinds of input are most likely to uncover bugs if there are any? */

#include <stdio.h>

#define OUT 0
#define IN 1

/* counts characters, lines, words */
int main()
{
    int c, nl, nw, nc;
    nl = nw = nc = 0;
    int state = OUT;

    while ((c = getchar()) != EOF) {
        ++nc;
        if (c == '\n')
            ++nl;
        if (c == ' ' || c == '\t' || c == '\n') {
            state = OUT;
        } else if (state == OUT) {
            state = IN;
            ++nw;
        }
    }

    printf("Lines: %d Words: %d Characters: %d\n", nl, nw, nc);

    /* I would test it by using special characters like \,;,:,',?,,
     * and by using numbers.
     * It would return inaccurate and unexpected output for a normal user
     * that expects "word" to have the same definition used in linguistics. */

    return 0;
}
