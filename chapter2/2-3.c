/* Exercise 2-3. Write a function htoi(s), which converts a string of hexadecimal digits
(including an optional 0x or 0X) into its equivalent integer value. The allowable digits are 0
through 9, a through f, and A through F. */
/* Pseudocode:
 * get hexadecimal string input
 * determine string length
 * iterate each character until length is reach
 *     get the sum of each corresponding value of the character in decimal */
#include <stdio.h>

int main()
{
    int len, i, value;
    value = i = 0;
    char s[] = "0x23e";

    // get the length of hex
    for (len = 0; s[len] != '\0'; len++);

    // optional 0x/0X prefix
    if (s[0] == '0' && s[1] == 'X' || s[1] == 'x')
        i = 2;

    for (; i < len; i++) {
        if (s[i] >= 'A' && s[i] <= 'F')
            value = 16 * value + (s[i] - ('A' - 10));
        else if (s[i] >= 'a' && s[i] <= 'f')
            value = 16 * value + (s[i] - ('a' - 10));
        else if (s[i] >= '0' && s[i] <= '9')
            value = 16 * value + (s[i] - '0');
        else
            return 1;
    }

    /* output: 574 */
    printf("%d\n", value);
    return 0;
}
