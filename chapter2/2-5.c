/* Exercise 2-5. Write the function any(s1,s2), which returns the first location in a string s1
   where any character from the string s2 occurs, or -1 if s1 contains no characters from s2.
   (The standard library function strpbrk does the same job but returns a pointer to the
   location.) */
/* Pseudocode:
 * iterate until the end of s2
 * check if current character in s2 matches any character in s1
 *      if matches a character, return the index of the matched character from s1
 * if all characters in s2 doesn't match any character in s1
 * then return -1 */
#include <stdio.h>

#define MAX_INPUT 1000

int any(const char s1[], const char s2[]);

int main()
{
        char s1[] = "foo";
        char s2[MAX_INPUT];
        int c, i;

        i = 0;

        while (i < MAX_INPUT - 1 && (c = getchar()) != EOF
                        && c != '\n')
                s2[i++] = c;

        s2[i] = '\0';
        printf("%d\n", any(s1, s2));
        // output: 1, if input is "bar o"
        return 0;
}

int any(const char s1[], const char s2[])
{
        int i, j;

        for (i = 0; s2[i] != '\0'; i++) {
                j = 0;
                while (s2[i] != s1[j] && s1[j] != '\0')
                        ++j;

                if (s1[j] != '\0')
                        return j;
        }

        return -1;
}
