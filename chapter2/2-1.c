#include <stdio.h>
#include <limits.h>

#define SHRT_BIT 16
#define INT_BIT 32
#define DOUBLE_BIT 64

int main()
{
    double bit_size[] = {CHAR_BIT,SHRT_BIT,INT_BIT,DOUBLE_BIT, 0};
    double unsigned_char = 1;
    int i, j, len;

    len = 0;
    for (j = 0; bit_size[j] != 0; j++)
        ++len;

    double unsigned_max[len];

    for (i = 0; i < len; i++) {
        for (j = bit_size[i]; j > 0; j--)
            unsigned_char = unsigned_char * 2;
        unsigned_max[i] = unsigned_char - 1;
        unsigned_char = 1;
    }

    for (i = 0; i < len; i++) {
        printf("%2.f ", bit_size[i]);
        printf("%20.f ", unsigned_max[i]);
        printf("%20.f ", unsigned_max[i] / 2 - 0.5);
        printf("%20.f\n", unsigned_max[i] - unsigned_max[i] - unsigned_max[i] / 2);
    }

    return 0;
}
