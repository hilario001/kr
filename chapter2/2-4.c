/* Exercise 2-4. Write an alternative version of squeeze(s1,s2) that deletes each character in
s1 that matches any character in the string s2. */
/* Pseudocode:
 * iterate until the end of s1
 * check if current character in s1 matches any character in s2
 * if matches any, delete all the instace of the match character in s1 */
#include <stdio.h>

void squeeze(char s1[], char s2[]);

int main()
{
    char s1[] = "foo";
    char s2[] = "bar o";
    /* output: f */
    squeeze(s1, s2);
    printf("%s", s1);
    return 0;
}

void squeeze(char s1[], char s2[])
{
    int i, j;
    int tmp1, tmp2;
    
    for (i = j = 0; s1[i] != '\0'; i++) {
        for (j = 0; s1[i] != s2[j] && s2[j] != '\0'; ++j)
            ;
        /* current character of s1 matches a character in s2 */
        if (s2[j] != '\0') {
            tmp1 = tmp2 = 0;
            for (tmp1 = 0, tmp2 = 0; s1[tmp1] != '\0'; ++tmp1) {
                if (s1[tmp1] != s2[j])
                    s1[tmp2++] = s1[tmp1]; 
            }
            s1[tmp2] = '\0';
        }
    }
}

