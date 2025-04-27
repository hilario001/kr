/* Exercise 1-3. Modify the temperature conversion program to
 * print a heading above the table.
 * Exercise 1-4. Write a program to print the corresponding
 * Celsius to Fahrenheit table. */

#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

void f_to_c_while();
void f_to_c_for();

void c_to_f_while();
void c_to_f_for();

void f_to_c_while() {
    double fahr = LOWER;
    double cel;

    printf("%3s %6s\n", "F", "C");
    while (fahr <= UPPER) {
        cel = (5.0/9.0) * (fahr-32);
        printf("%3.0f %6.1f\n", fahr, cel);
        fahr+=STEP;
    };
}

void f_to_c_for() {
    printf("%3s %6s\n", "F", "C");
    for (double fahr = LOWER; fahr <= UPPER; fahr+=STEP)
        printf("%3.0f %6.1f\n", fahr, (5.0/9.0) * (fahr-32.0));
}

void c_to_f_while() {
    double cel = LOWER;
    double fahr;

    printf("%3s %6s\n", "C", "F");
    while (cel <= UPPER) {
        fahr = cel * (9.0/5.0) + 32;
        printf("%3.0f %6.1f\n", cel, fahr);
        cel+=STEP;
    };
}

void c_to_f_for() {
    printf("%3s %6s\n", "C", "F");
    for (double cel = UPPER; cel >= LOWER;cel-=STEP)
        printf("%3.0f %6.1f\n", cel, cel * (9.0/5.0) + 32.0);
}

int main() {
    //f_to_c_while();
    //c_to_f_while();
    //f_to_c_for();
    c_to_f_for();
    return 0;
}

