#include <stdio.h>
#include <stdlib.h>

int fatorial(int numero);

int main() {
    int numero;

    scanf("%d", &numero);

    printf("%d\n", fatorial(numero));

    return 0;
}


int fatorial(int numero) {
    int valorBase;

    if (numero > 0) {
        return numero * fatorial((numero - 1));
    }else {
        valorBase = 1;
    }

    return valorBase;
}