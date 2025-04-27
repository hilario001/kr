/* Exercise 1-13. Write a program to print a histogram of the
 * lengths of words in its input. It easy to draw the histogram
 * with the bars horizontal; a vertical orientation is more challenging. */

#include <stdio.h>

#define MAX_WORD 1000   // max word input
#define OUT 0           // not in a word
#define IN 1            // in a word

void xhistogram(int nw, char wd[]);
void yhistogram(int nw, char wd[]);

// print the length of input words in histogram horizontally or vertically
int main()
{
    int c;              // character input
    int state;          // in a word, or not
    int max;            // longest word so far
    int nw;             // number of words
    int len;            // length of current word
    int i, j;           // loop counter
    char wd[MAX_WORD];  // words are saved here

    state = OUT;
    max = 0;
    nw = 0;
    len = 0;
    
    /* get length of each word, total number of words, longest word */   
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            state = OUT;
            wd[nw] = len;
            if (wd[nw] > max)
                max = wd[nw];
        } else if (state == OUT) {
            state = IN;
            ++nw;   // first increment makes index 0 a waste, hence loop below starts at 1
            len = 1;
        } else {
            ++len;
        }
    }

    if (nw == 0) {
        printf("No input\n");
        return 0;
    }

    xhistogram(nw, wd);

    /* print horizontally
     * outer loop: number of words (vertical)
     * inner loop: length of current word (horizontal) */
    //for (i = 1; i <= nw; i++) {
    //    printf("%3d ", i);
    //    for (j = 0; j < wd[i]; j++) {
    //        printf("*");
    //    }
    //    printf(" (%d)\n", j);
    //}

    /* print vertically
     * outer loop: length of the longest word (vertical)
     * inner loop: length of current word is greater than or equal to current length of longest word (horizontal) */
    //for (i = max; i > 0; i--) {
    //    printf("%3d ", i);
    //    for (j = 1; j <= nw; j++) {
    //        if (wd[j] >= i) 
    //            printf("%3c", '|');
    //        else
    //            printf("%3c", ' ');
    //    }
    //    printf("\n");
    //}
    
    // bottom number label for vertical histogram
    //printf("     ");
    //for (i = 1; i <= nw; i++)
    //    printf("%2d ", i);

    //printf("\n");
    return 0;
}

/* print horizontally */
void xhistogram(int nw, char wd[])
{
     /* outer loop: number of words (vertical)
     * inner loop: length of current word (horizontal) */

    int i, j;
    for (i = 1; i <= nw; i++) {
        printf("%3d ", i);
        for (j = 0; j < wd[i]; j++) {
            printf("*");
        }
        printf(" (%d)\n", j);
    }

}
