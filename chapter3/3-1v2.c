#include <stdio.h>

int main()
{
        int v[] = {1,2,3,4,5,6,7,8,9,10,29,30};
        int x = 3;
        int len = sizeof(v) / sizeof(v[0]) - 1;
        int mid = len / 2;

        while (v[mid] != x && mid <= len) {
                if (x < v[mid])
                        mid -= (len - mid) / 2;
                else
                        mid += (len - mid) / 2;
        }

        if (v[mid] == x)
                return mid;
        else
                return -1;

}

/* Pseudocode:
 * Get the ascending array input
 * Get x to find in the array
 * Find the length of the array
 * As long as the value of the mid index is not equal to x and  */
