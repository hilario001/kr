/* Exercise 2-2. Write a loop equivalent to the for loop above without using && or ||
 * for (i=0; i < lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
 *      s[i] = c; */
#include <stdio.h>

int get_line(char s[], int lim);

#define MAX_LINE 100

int main()
{
    char s[MAX_LINE];
    int i, c;
    int lim = MAX_LINE;

    for (i = 0; i < lim-1; i++) {
        c = getchar();
        if (c == EOF) {
            s[i] = c;
        } else {
            if (c != '\n') {
                s[i] = c;
            } else {
                s[i] = c;
                ++i;
                s[i] = '\0';
            }
        }
    }

    printf("d\n", len);
    printf("%s", s);

    return 0;
}
