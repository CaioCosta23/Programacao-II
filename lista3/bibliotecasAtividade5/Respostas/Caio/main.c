#include <stdio.h>
#include <stdlib.h>

#include "string_utils.h"


#define TAMANHO_MAXIMO 1000

#define OBTER_TAMANHO 1
#define COPIAR 2
#define CONVERTER_PARA_MAIUSCULA 3
#define CONVERTER_PARA_MINUSCULA 4
#define INVERTER 5
#define ENCERRAR 6


void imprimirMenu() {
    printf("1 - Tamanho da string\n");
    printf("2 - Copiar string\n");
    printf("3 - Converter string para letras maiusculas\n");
    printf("4 - Converter string para letras minusculas\n");
    printf("5 - Imprimir string ao contrario\n");
    printf("6 - Encerrar o programa\n");
    printf("Opcao escolhida: ");
}

int main() {
    char string[TAMANHO_MAXIMO];
    unsigned short int opcao;

    scanf("%[^\n]\n", string);

    char copia[string_length(string)];

    do {
        imprimirMenu();
        scanf("%hd", &opcao);

        switch(opcao) {
            case OBTER_TAMANHO:
                printf("\nTamanho da string: %d\n", string_length(string));
                
                break;
            case COPIAR:
                string_copy(string, copia);

                printf("\nString copiada: %s\n", copia);
                
                break;
            case CONVERTER_PARA_MAIUSCULA:
                string_upper(string);
                
                printf("\nString convertida para maiusculas: %s\n", string);

                break;
            case CONVERTER_PARA_MINUSCULA:
                string_lower(string);
                
                printf("\nString convertida para minusculas: %s\n", string);
            
                break;
            case INVERTER:
                string_reverse(string);

                printf("\nString invertida: %s\n", string);

                break;
            case ENCERRAR:
                break;
            default:
                printf("Erro na selecao das opcoes");
                opcao = ENCERRAR;
                break;
        }
        printf("\n");
    }while(opcao != ENCERRAR);
    
    return 0;
}