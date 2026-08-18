#include <stdio.h>

int main(void) {

    float celsius, fahr;
    float lower, upper, step;

    lower = 0; /* lower limit of temperatuire scale */
    upper = 300; /* upper limit */
    step = 20; /* step size */

    printf("%0s %0s\n", "Celsius", "Fahr");

    celsius = lower;
    while (celsius <= upper) {
        fahr = celsius * (9.0/5.0) + 32.0;
        printf("%5.0f %6.1f\n", celsius, fahr);
        celsius += step;
    }

    return 0;
}