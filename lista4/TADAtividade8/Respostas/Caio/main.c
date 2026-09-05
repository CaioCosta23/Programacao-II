#include <stdio.h>
#include <stdlib.h>

#include "departamento.h"

tDepartamento leDepartamento() {
    char curso1[STRING_MAX], curso2[STRING_MAX], curso3[STRING_MAX], nome[STRING_MAX], diretor[STRING_MAX];
    int media1, media2, media3;

    scanf("%[^\n]\n", nome);
    scanf("%[^\n]\n", diretor);
    scanf("%[^\n]\n", curso1);
    scanf("%[^\n]\n", curso2);
    scanf("%[^\n]\n", curso3);
    scanf("%d %d %d\n", &media1, &media2, &media3);

    return criaDepartamento(curso1, curso2, curso3, nome, media1, media2, media3, diretor);
}

/**
 * @brief Programa que captura os dados de departamentos, analisa-os e exibe-os na tela;
 * 
 * @return int Programa principal;
 */
int main() {
    int quantidadeDepartamentos, d;
    
    scanf("%d\n", &quantidadeDepartamentos);

    tDepartamento departamentos[quantidadeDepartamentos];

    for(d = 0; d < quantidadeDepartamentos; d++) {
        departamentos[d] = leDepartamento();
    }

    ordenaPorMediaDepartamentos(departamentos, quantidadeDepartamentos);

    for(d = 0; d < quantidadeDepartamentos; d++) {
        imprimeAtributosDepartamento(departamentos[d]);
    }

    return 0;
}