/* Exercise 3-3. Write a function expand(s1,s2) that expands shorthand notations
   like a-z in the string s1 into the equivalent complete list abc...xyz in s2.
   Allow for letters of either case and digits, and be prepared to handle cases
   like a-b-c and a-z0-9 and -a-z. Arrange that a leading or trailing - is taken
   literally */
#include <stdio.h>
#include <ctype.h>

#define MAX_LINE 1000

void expand(char s1[], char s2[]);
int get_line(char s[], int max);

int main()
{
        char s1[MAX_LINE];
        char s2[MAX_LINE];

        if (get_line(s1, MAX_LINE) > 0) {
                expand(s1, s2);
                printf("%s\n", s2);
        } else {
                return 1;
        }

        return 0;
}

int get_line(char s[], int max)
{
    int c, i;

    for (i = 0; i < max - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;

    if (c == '\n') {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';

    return i;
}

void expand(char s1[], char s2[])
{
        int i, j, tmp;
        int end;        // end of the string to expand

        i = j = 0; 
        while (s1[i] != '\0' && i < MAX_LINE) {
                if (s1[i-1] == '-' && isalnum(s1[i-2]) && isalnum(s1[i])) {
                        // find the end of the expand i.e. a-b-c (c is the end)
                        for (end = i; isalnum(s1[end]) && s1[end-1] == '-'; end+=2)
                                ;
                        end -= 2;

                        // i.e. a-0
                        if (isalpha(s1[i-2]) && !(isalpha(s1[end]))) {
                                s2[j++] = s1[i];
                                break;
                        }

                        // i.e. 0-a
                        if (isdigit(s1[i-2]) && !(isdigit(s1[end]))) {
                                s2[j++] = s1[i];
                                break;
                        }

                        /* if: the string to expand has ascending numeric values to be inserted
                         * i.e a-z (97-122), 0-9 (48-57)
                         * else if: descending i.e. z-a (122-97), 9-0 (57-48) */
                        if (s1[i-2] - s1[end] <= 0) {
                                for (j -= 2, tmp = s1[i-2]; tmp <= s1[end] && j < MAX_LINE; ++tmp)
                                        s2[j++] = tmp; 
                        } else {
                                for (j -= 2, tmp = s1[i-2]; tmp >= s1[end] && j < MAX_LINE; --tmp)
                                        s2[j++] = tmp; 
                        }
                        i = end + 1;
                } else {
                        s2[j++] = s1[i++];
                }
        }
        s2[j] = '\0';
}
