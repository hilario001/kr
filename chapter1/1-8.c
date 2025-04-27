/* Exercise 1-8. Write a program to count blanks, tabs, and newlines. */

#include <stdio.h>

void counter()
{
    double blanks, tabs, newlines;
    blanks, tabs, newlines = 0;
    int c; 

    while ((c = getchar()) != EOF) {
        switch(c) {
            case ' ': ++blanks; break;
            case '\t': ++tabs; break;
            case '\n': ++newlines; break;
            default: ;
        }
    }

    printf("Blanks: %.0f\nTabs: %.0f\nNewlines: %.0f\n",
            blanks, tabs, newlines);
}
        
int main()
{
    counter();
    return 0;
}
