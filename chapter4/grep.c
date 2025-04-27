#include <stdio.h>

int strindex(char s[], char grep[]);

int main()
{
        char grep[] = "grep";
        char s[] = "this should be greprinted.";

        if (strindex(s, grep) >= 0)
                printf("%s\n", s);
        
        return 0;
}

int strindex(char s[], char grep[])
{
        int i, j, k;
        int contain;     // line contains the pattern

        contain = 0;

        for (i = 0; s[i] != '\0' && !contain; ++i) {
                // if: skip if current char doesn't contain first char of grep
                if (s[i] != grep[0])
                        continue;
                contain = 1;
                k = i;
                for (j = 0; grep[j] != '\0'; ++i, ++j) {
                        if (s[i] != grep[j]) {
                                contain = 0;
                                break;
                        }
                }
        }

        if (contain)
                return k;
        else
                return -1;
}
