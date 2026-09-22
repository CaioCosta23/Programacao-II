#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_MAXIMO_ROTULOS 1001

/**
 * @brief Obtém o tamanho de um lista/vetor/'array' de caracteres;
 * 
 * @param lista Lista/Vetor/'Array' de caracteres;
 * @return unsigned short int Tamanho da lista/vetor/'array' de caracteres;
 */
static unsigned short int obtemTamanhoLista(char lista[]) {
    unsigned short int contador = 0;

    while(lista[contador] != '\0')
        contador++;

    return contador;
}

/**
 * @brief Troca dois itens promocionais de lugar em uma lista/vetor/'array';
 * 
 * @param promocionais Lista/Vetor/'Array' de promocionais;
 * @param indice1 Índice da primeira posição (na lista/vetor/'array') da troca;
 * @param indice2 Índice da segunda posição (na lista/vetor/'array') da troca;
 */
static void trocaPromocionais(char promocionais[], int indice1, int indice2){
    char auxiliar;
    
    auxiliar = promocionais[indice1];
    promocionais[indice1] = promocionais[indice2];
    promocionais[indice2] = auxiliar;
}

/**
 * @brief Troca dois itens valores que representam a quantidade de um determinado promocional de lugar em uma lista/vetor/'array';
 * 
 * @param quantidades Lista/Vetor/'Array' de quantidades (de cada promocional);
 * @param indice1 Índice da primeira posição (na lista/vetor/'array') da troca;
 * @param indice2 Índice da segunda posição (na lista/vetor/'array') da troca;
 */
static void trocaQuantidades(int quantidades[], int indice1, int indice2){
    int auxiliar;
    
    auxiliar = quantidades[indice1];
    quantidades[indice1] = quantidades[indice2];
    quantidades[indice2] = auxiliar;
}

/**
 * @brief Ordena (de acordo com suas posições na tabela ASCII) os promocionais e suas quantidades
 * (em suas respectivas listas);
 * 
 * @param promocionais Lista/Vetor/'Array' de promocionais;
 * @param quantidades Lista/Vetor/'Array' de quantidades (de cada promocional);
 * @param tamanhoListas Tamanho das listas/vetores/'arrays' (de promocionais e suas quantidades);
 */
static void ordenaListas(char promocionais[], int quantidades[], int tamanhoListas) {
    unsigned short int l1, l2;

    for(l1 = 0; (l1 < tamanhoListas - 1); l1++) {
        for(l2 = l1 + 1; (l2 < tamanhoListas); l2++) {
            if ((int)promocionais[l1] > (int)promocionais[l2]) {
                trocaPromocionais(promocionais, l1, l2);
                trocaQuantidades(quantidades, l1, l2);
            }
        }
    }
}

/**
 * @brief Programa que lista determinados itens promocionais (nesse caso, representados por caracteres),
 * nos quais os promocionais que possuirem uma quantidade de itens maior que o limite pré-estabelecido,
 * são impressos na tela (em ordem de aparição na TABELA ASCII - de acordo com cada caractere); 
 * 
 * @return int Programa principal;
 */
int main() {
    unsigned int quantidadeLimite;
    char rotulo[TAMANHO_MAXIMO_ROTULOS], listaPromocionais[TAMANHO_MAXIMO_ROTULOS];
    unsigned short int tamanhoRotulo, l;
    unsigned short int tamanhoListaFunkos = 0, contador = 0, quantidadeListada = 0;
    int quantidadePromocionais[TAMANHO_MAXIMO_ROTULOS];
    unsigned short int existePromocao = 0;

    scanf("%d", &quantidadeLimite);
    scanf("%1000s", rotulo);

    tamanhoRotulo = obtemTamanhoLista(rotulo);

    // Inicializa a lista de quantidades promocionais;
    for(l = 0; l < tamanhoRotulo; l++)
        quantidadePromocionais[l] = 0;

    while (contador < tamanhoRotulo) {
        if (contador == 0){
            listaPromocionais[quantidadeListada] = rotulo[contador];
            quantidadePromocionais[quantidadeListada++]++;
        }else {
            unsigned short int p;
            unsigned short int caractereAchado = 0; // Variável lógica;

            for(p = 0; p < quantidadeListada; p++) {
                if (rotulo[contador] == listaPromocionais[p]){
                    caractereAchado = 1;
                    break;
                }
            }
            if (caractereAchado){
                quantidadePromocionais[p]++;
            }else {
                listaPromocionais[quantidadeListada] = rotulo[contador];
                quantidadePromocionais[quantidadeListada++]++;

            }
        }
        contador++;
    }

    ordenaListas(listaPromocionais, quantidadePromocionais, quantidadeListada);

    
    for(l = 0; l < quantidadeListada; l++)
        if (quantidadePromocionais[l] > quantidadeLimite){
            printf("%c: %d\n", listaPromocionais[l], quantidadePromocionais[l]);
            existePromocao = 1;
        }
    
    if (!(existePromocao))
        printf("NENHUM\n");

    return 0;
}