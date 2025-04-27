/* Exercise 1-13. Write a program to print a histogram of the
 * lengths of words in its input. It easy to draw the histogram
 * with the bars horizontal; a vertical orientation is more challenging. */

#include <stdio.h>

void horizontal_histogram(int saved_len[], int array_len);
void vertical_histogram(int saved_len[], int highest_len, int array_len);

#define MAX_INPUT 1000                  // max number of input words

int main()
{
        int c;                          // current input character
        int len;                        // length of current word
        int saved_len[MAX_INPUT];       // length of each word stored here
        int i;
        int highest_len;                // highest word length seen
        
        highest_len = len = i = 0;

        while (i < MAX_INPUT && (c = getchar()) != EOF) {
                if (c != ' ' && c != '\t' && c != '\n')
                        ++len;

                if (len > 0 && (c == ' ' || c == '\t' || c == '\n')) {
                        saved_len[i++] = len;

                        if (len > highest_len)
                                highest_len = len;

                        len = 0;
                }
        }

        if (i > 0)
                horizontal_histogram(saved_len, i);
                //vertical_histogram(saved_len, highest_len, i);
        else
                return 1;

        return 0;
}

void horizontal_histogram(int saved_len[], int array_len)
{
        /* Output:
         * 1 *** (3)
         * 2 ****** (6)
         * 3 ** (2)
         * 4 ******** (8)
         * 5 **** (4) */

        int i, j;

        for (i = 0; i < array_len; i++) {
                printf("%3d ", i + 1);

                for (j = 0; j < saved_len[i]; j++)
                        printf("%c", '*');

                printf(" (%d)\n", saved_len[i]);
        }
}

void vertical_histogram(int saved_len[], int highest_len, int array_len)
{
        /* Output:
           *
           *   *   
           * * *   *
           * * *   *
           * * * * *
           1 2 3 4 5 */

        int i;

        for (; highest_len > 0; --highest_len) {
                for (i = 0; i < array_len; i++) {
                        if (saved_len[i] >= highest_len)
                                printf("* ");
                        else
                                printf("  ");
                }
                printf("\n");
        }

        for (i = 1; i <= array_len; i++)
                printf("%d ", i);
}
