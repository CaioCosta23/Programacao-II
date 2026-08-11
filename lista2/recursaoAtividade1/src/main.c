#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_MAXIMO_STRINGS 1000

void imprimeInvertido(char string[], int indice);

/**
 * @brief Programa que recebe uma string e imprime ela ao contrário de forma recursiva;
 * 
 * @return int Programa principal;
 */
int main() {
    char string[TAMANHO_MAXIMO_STRINGS];
    unsigned int indiceInicial;
    
    while(scanf("%s", string) == 1){
        indiceInicial = 0;
        imprimeInvertido(string, indiceInicial);
        // Espaço colocado aqui peor causa da formatação das saídas de teste;
        printf(" ");
    }

    return 0;
}


void imprimeInvertido(char string[], int indice) {

    if(string[indice] != '\0'){
        imprimeInvertido(string, indice + 1);
        printf("%c", string[indice]);
    }
}