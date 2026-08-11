#include <stdio.h>
#include <stdlib.h>

#include <math.h>

int main() {
    const unsigned short int base = 8;
    int decimal;
    int octal = 0, divisoes = 0;

    scanf("%d", &decimal);

    while(decimal > 0) {
        octal += (decimal % base) * pow(10, divisoes);
        decimal = decimal / base;
        divisoes++;
    }

    printf("%d", octal);

    return 0;
}