#include <stdio.h>
#include <stdlib.h>

int fibonacci(int n);

/**
 * @brief Programa que imprime o "N-ésimo" número da sequência de Fibonacci;
 * 
 * @return int Programa principal;
 */
int main() {
    int numero;

    scanf("%d", &numero);
    printf("%d\n", fibonacci(numero));
    
    return 0;
}


int fibonacci(int n){
    const unsigned short int numero1Base = 0;
    const unsigned short int numero2Base = 1;

    if (n == 0)
        return numero1Base;
    else if (n == 1)
        return numero2Base;
    else
        return fibonacci(n - 2) + fibonacci(n - 1);
    
}