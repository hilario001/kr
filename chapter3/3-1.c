#include <stdio.h>

int main()
{
        int v[] = {1,2,3,4,5,6,7,8,9,10,29,30};
        int x = 28;
        int len = sizeof(v) / sizeof(v[0]);
        int low, mid, high;

        low = 0;
        high = len - 1;
        mid = (low+high)/2;

        while (x != v[mid] && low <= high) {
                mid = (low+high)/2;
                if (x < v[mid])
                        high = mid - 1;
                else
                        low = mid + 1;
        }

        if (v[mid] == x)
                return mid;
        else
                return -1;

}
