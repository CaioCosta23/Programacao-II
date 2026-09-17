#include <stdio.h>
#include <stdlib.h>

#include "departamento.h"

/**
 * @brief Programa que lê as informações de vários departamentos (como nome, nome do diretor, nome de 3 cursos
 * e a média das notas de cada curso) e ordena-os pela média das médias das notas;
 * 
 * @return int Programa principal;
 */
int main () {
    int quantidadeDepartamentos, d, media1, media2, media3;
    char curso1[STRING_MAX], curso2[STRING_MAX], curso3[STRING_MAX], diretor[STRING_MAX], nome[STRING_MAX];

    scanf("%d\n", &quantidadeDepartamentos);
    
    tDepartamento departamentos[quantidadeDepartamentos];

    for(d = 0; d < quantidadeDepartamentos; d++) {
        scanf("%[^\n]\n", nome);
        scanf("%[^\n]\n", diretor);
        scanf("%[^\n]\n", curso1);
        scanf("%[^\n]\n", curso2);
        scanf("%[^\n]\n", curso3);
        scanf("%d %d %d\n", &media1, &media2, &media3);

        departamentos[d] = CriaDepartamento(curso1, curso2, curso3, nome, media1, media2, media3, diretor);
    }

    OrdenaDepartamentosPorMedia(departamentos, quantidadeDepartamentos);
    
    for (d = 0; d < quantidadeDepartamentos; d++)
        ImprimeAtributosDepartamento(departamentos[d]);

    return 0;
}