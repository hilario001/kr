#include <stdio.h>

int main()
{
        int c;
        while ((c = getchar()) != EOF) {
                switch (c) {
                case 'a':
                        putchar('t');
                }
        }
}
