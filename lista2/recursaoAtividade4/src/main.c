#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_MAXIMO 1000

int palindromo(char palavra[], int tamanho);

int calculaTamanhoPalavra(char palavra[]) {
    int tamanho = 0;
    
    while(palavra[tamanho] != '\0') {
        tamanho++;
    }

    return tamanho;
}

/**
 * @brief Programa que verifica se uma palavra é palindromo;
 * 
 * @return int Programa Principal;
 */
int main() {
    char palavra[TAMANHO_MAXIMO];
    int tamanho;

    while(scanf("%s", palavra) == 1) {
        tamanho = calculaTamanhoPalavra(palavra);
    
        if (palindromo(palavra, tamanho))
            printf("SIM\n");
        else
            printf("NAO\n");
        }

    return 0;
}


int palindromo(char palavra[], int tamanho){
    unsigned short int palavraPalindroma = 1;

    if (tamanho > 0) {
        // Verifica se último caractere marcado é igual ao primeiro marcado (na rodada);
        if (palavra[tamanho - 1] == palavra[calculaTamanhoPalavra(palavra) - tamanho]) {
            return palindromo(palavra, (tamanho - 1));
        }else {
            palavraPalindroma = 0;
        }
    }
    return palavraPalindroma;
}