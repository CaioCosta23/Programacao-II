#include <stdio.h>
#include <stdlib.h>

/*
 * OBS (IMPORTANTE!): Muitos dos casos de testes foram criados com programas executáveis diferentes, então por isso,
 * muitos casos de testes terão diferença (alguns acusando diferença por solicitarem quebra de linha ou por estarem
 * ordenados - quando não deveriam estar). Esssas diferenças poderão ser percebidas nas comparações da saída da pasta 
 * "outprog" (pasta criada com as saídas desse código) com as saídas de testes ("output");
*/

void imprimeNaoRepetidos(int livros[], int quantidadeLivros, int repetidos[], int quantidadeRepetidos) {
    int l, r;
    unsigned short int achado;
    int naoRepetidos = 0;

    for (l = 0; l < quantidadeLivros; l++) {
        achado = 0;
        for(r = 0; r < quantidadeRepetidos; r++) {
            if (livros[l] == repetidos[r]) {
                achado = 1;
            }
        }
        if (!(achado)) {
            printf("%d ", livros[l]);
            naoRepetidos += 1;
        }
    }

    if(naoRepetidos == 0)
        printf("NENHUM");
}

/**
 * @brief Programa que verifica quais livros não possuem cópias em estoque
 * (livros que não possuem identificador repetido);
 * 
 * @return int Programa Principal;
 */
int main() {
    int quantidadeLivros, l, r, quantidadeNaoRepetidos;
    int contRepetidos = 0;

    scanf("%d", &quantidadeLivros);

    int livros[quantidadeLivros];
    int repetidos[quantidadeLivros];

    for(l = 0; l < quantidadeLivros; l++) {
        scanf("%d", &livros[l]);
        
        for(r = 0; r < l; r++) {
            if (livros[l] == livros[r]){
                repetidos[contRepetidos] = livros[l];
                contRepetidos++;
                break;
            }
        }
    }

    imprimeNaoRepetidos(livros, quantidadeLivros, repetidos, contRepetidos);

    return 0;
}