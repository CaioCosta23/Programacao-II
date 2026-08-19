#include <stdio.h>
#include <stdlib.h>

#include "string_utils.h"

#define DISTANCIA_CARACTERES_ASCII 32

// Funções auxiliares (podem ser somente visualizadas nesse arquivo);
static int verificaLetraMaiuscula(char caractere) {
    return ((caractere >= 'A') && (caractere <= 'Z'));
}

static int verificaLetraMinuscula(char caractere) {
    return ((caractere >= 'a') && (caractere <= 'z'));
}


int string_length(char str[]) {
    int s = 0;
    int tamanho = 0;

    while(str[s] != '\0'){
        tamanho += 1;
        s++;
    }
    return tamanho;
}

void string_copy(char src[], char dest[]) {
    int s = 0;

    while(src[s] != '\0') {
        dest[s] = src[s];
        s++;
    }
    dest[s] = '\0';
}


void string_upper(char str[]) {
    int s = 0;

    while(str[s] != '\0'){
        if ((verificaLetraMinuscula(str[s])) && (!(verificaLetraMaiuscula(str[s]))))
            str[s] = str[s] - DISTANCIA_CARACTERES_ASCII;
        
        s++;
    }
}

void string_lower(char str[]) {
    int s = 0;

    while(str[s] != '\0'){
        if (verificaLetraMaiuscula(str[s]) && (!(verificaLetraMinuscula(str[s]))))
            str[s] = str[s] + DISTANCIA_CARACTERES_ASCII;
        
        s++;
    }
}


void string_reverse(char str[]) {
    int tamanho, s, c;

    tamanho = string_length(str);
    
    c = tamanho;

    char copia[tamanho];

    string_copy(str, copia);

    for (s = 0; s < tamanho; s++) {
        // Decrementa antes já pensando em iniciar com um índice menor que o tamanho e ir até 0;
        str[s] = copia[--c];
    }
}