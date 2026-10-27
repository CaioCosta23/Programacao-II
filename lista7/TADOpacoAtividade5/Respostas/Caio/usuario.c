#include <stdio.h>
#include <stdlib.h>

#include "usuario.h"

#define TAMANHO_NOME 30
#define TAMANHO_CPF 12

#define SEPARADOR ' '

struct Usuario {
    char *nome, *cpf;
};

/**
 * @brief Realoca o tamanho da memória dinamicamente de um vetor/lista/'array' (de caracteres, neste caso);
 * 
 * @param vetorCaracteres (Ponteiro para) Vetor/Lista/'Array' de caracteres;
 * @param tamanhoParao Tamanho padrão inicial do vetor/lista/'array' de caracteres;
 */
static void realocarMemoriaVetor(char *vetorCaracteres, unsigned int tamanhoParao) {
    vetorCaracteres = (char*)realloc(vetorCaracteres, tamanhoParao *sizeof(char));

    if (vetorCaracteres == NULL) {
        printf("Erro! Realocacao de memoria do vetor de caracteres mal-sucedido.\n");
        exit(1);
    }
}

/**
 * @brief Lê uma sequência de caracteres e os armazena em um vetor/lista/'array' de caracteres;
 * 
 * @param vetorCaracteres (Ponteiro para) Vetor/Lista/'Array' de caracteres;
 * @param tamanhoPadrao Tamanho padrão inicial do vetor/lista/'array' de caracteres;
 * @return char* Ponteiro para o vetor/lista/'array' de caracteres;
 */
static char *LeVetorCaracteres(char *vetorCaracteres, unsigned int tamanhoPadrao) {
    char letra;
    unsigned int contador = 0;


    while(1) {
        scanf("%c", &letra);

        if (letra == SEPARADOR) {
            vetorCaracteres[contador] = '\0';
            break;
        }

        if (contador == tamanhoPadrao){
            tamanhoPadrao *= 2;
            realocarMemoriaVetor(vetorCaracteres, tamanhoPadrao);
        }

        vetorCaracteres[contador++] = letra;
    }
    return vetorCaracteres;
}

tUsuario *CriaUsuario() {
    tUsuario *usuario = NULL;

    usuario = (tUsuario*)malloc(sizeof(tUsuario));

    if (usuario == NULL) {
        printf("Erro! Alocacao de memoria de usuario mal-sucedida.\n");
        exit(1);
    }

    usuario->nome = NULL;

    usuario->nome = (char*)calloc(TAMANHO_NOME, sizeof(char));

    if ((*usuario).nome == NULL) {
        printf("Erro! Alocacao de memoria de nome de usuario mal-sucedida.\n");
        DestroiUsuario(usuario);
        exit(1);
    }

    usuario->cpf = NULL;

    usuario->cpf = (char*)calloc(TAMANHO_NOME, sizeof(char));

    if ((*usuario).cpf == NULL) {
        printf("Erro! Alocacao de memoria de CPF do usuario mal-sucedida.\n");
        DestroiUsuario(usuario);
        exit(1);
   }

   return usuario;
}

void LeUsuario(tUsuario *user) {
    user->nome = LeVetorCaracteres((*user).nome, TAMANHO_NOME);
    user->cpf = LeVetorCaracteres((*user).cpf, TAMANHO_CPF);
}

void ImprimeUsuario(tUsuario *user) {
    printf("Nome: %s\n", (*user).nome);
    printf("CPF: %s\n",(*user).cpf);
}

void DestroiUsuario (tUsuario *user) {
    if (user != NULL) {
        if ((*user).nome != NULL)
            free((*user).nome);
        if ((*user).cpf != NULL)
            free((*user).cpf);

        free(user);
    }
}