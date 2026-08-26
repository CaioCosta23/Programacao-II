#include <stdio.h>
#include <stdlib.h>

#include "usuario.h"

/**
 * @brief Função auxiliar que copia uma string para outra (assim como a função "strcpy(dest, src)", da biblioteca <string.h>);
 * 
 * @param atributo String que representa o atributo que receberá o conteúdo;
 * @param string String que será copiada para dentro do atributo;
 * 
 * @OBS: A função é static posi será usada apenas nesse arquivo;
 */
static void copiaString(char atributo[], char string[]){
    short int indice = -1;
    
    do {
        indice++;
        atributo[indice] = string[indice];
    }while (string[indice] != '\0');
}

tUsuario CriaUsuario(char nome[20], char cpf[15]) {
    tUsuario usuario;

    copiaString(usuario.nome, nome);
    copiaString(usuario.cpf, cpf);

    return usuario;
}

void ImprimeUsuario(tUsuario user) {
    printf("Nome: %s\n", user.nome);
    printf("CPF: %s", user.cpf);
}