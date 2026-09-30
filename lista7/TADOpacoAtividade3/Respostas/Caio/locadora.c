#include <stdio.h>
#include <stdlib.h>

#include "locadora.h"

#define MAX_FILMES 10

typedef void (*Fptr)(tLocadora*, int*, int);

struct Locadora{
    tFilme **filmes;
    float lucro;
    int quantidadeFilmes;
};


/**
 * @brief Troca dois filmes de posição em uma lista/vetor/'array' de filmes;
 * 
 * @param filmes Lista/vetor/'array' de ponteiros de Tipos Abstratos de Dados (T.A.D.s) que representam as estruturas que contém os dados (atualizados) do(s) filme(s);
 * @param indice1 Indíce da primeira posição a ser trocada;
 * @param indice2 Indíce da segunda posição a ser trocada;
 */
static void trocaFilmes(tFilme *filmes[], int indice1, int indice2) {
    tFilme *auxiliar;

    auxiliar = filmes[indice1];
    filmes[indice1] = filmes[indice2];
    filmes[indice2] = auxiliar;
}

/**
 * @brief Libera (desaloca a memória dinamicamente de) uma lista/vetor/'array' de códigos;
 * 
 * @param codigos Ponteiro (lista/vetor/'array') para códigos;
 */
static void LiberaCodigos(int *codigos) {
    if (codigos!= NULL)
        free(codigos);
}

/**
 * @brief Realiza uma ação (genérica - vinda de uma função específica) na locadora;
 * 
 * @param locadora Ponteiro para Tipo Abstrato de Dado (T.A.D.) que representam a estrutura que contém os dados (atualizados) da locadora;
 * @param codigos Ponteiro para lista/vetor/'array' de códigos;
 * @param quantidadeCodigos Quantidade de códigos da lista/vetor/'array' de códigos;
 * 
 * @OBS: Nesse caso, as ações são ou de Alugar ou devolver livro, que vem através de 'callback';
 */
static void RealizarAcao(tLocadora *locadora, Fptr acao) {
    unsigned int quantidadeCodigos = 0;
    int *codigos = NULL;
    static unsigned int MAX_CODIGOS = 10;

    codigos = (int*)calloc(MAX_CODIGOS, sizeof(int));

    if (codigos == NULL) {
        printf("Erro! Alocacao de memoria de lista de codigos de de devolucao de filmes mal-sucedida.\n");
        exit(1);
    }

    while(scanf("%d", (codigos + quantidadeCodigos)) == 1) {
        if (quantidadeCodigos > MAX_CODIGOS){
            MAX_CODIGOS *= 2;

            codigos = (int*)realloc(codigos, MAX_CODIGOS * sizeof(int));
            
            if (codigos == NULL) {
                printf("Erro! Realocacao de memoria de lista de codigos de de devolucao de filmes mal-sucedida.\n");
                exit(1);
            }
        }
        quantidadeCodigos++;
    }
    acao(locadora, codigos, quantidadeCodigos);
    
    LiberaCodigos(codigos);
}


tLocadora *CriarLocadora() {
    tLocadora *locadora = NULL;

    locadora  = (tLocadora*)malloc(sizeof(tLocadora));

    if (locadora == NULL) {
        printf("Erro! Alocacao de memoria de locadora mal-sucedida.\n");
        exit(1);
    }

    locadora->filmes = (tFilme**)malloc(MAX_FILMES * sizeof(tFilme*));

    if ((*locadora).filmes == NULL) {
        printf("Erro! Alocacao de memoria de lista de filmes mal-sucedida.\n");
        DestruirLocadora(locadora);
        exit(1);
    }

    locadora->quantidadeFilmes = 0;
    locadora->lucro = 0;
    
    return locadora;
}

void CadastrarFilmeLocadora(tLocadora *locadora, tFilme *filme) {
    locadora->filmes[(*locadora).quantidadeFilmes++] = filme;
}

void LerCadastroLocadora(tLocadora *Locadora) {
    int codigo;
    static unsigned int QUANTIDADE_FILMES = MAX_FILMES;
    unsigned int f;
    unsigned short int jaCadastrado;

    while(scanf("%d,", &codigo) == 1) {
        if ((*Locadora).quantidadeFilmes > QUANTIDADE_FILMES) {
            QUANTIDADE_FILMES = QUANTIDADE_FILMES * 2;
            
            Locadora->filmes = (tFilme**)realloc((*Locadora).filmes, QUANTIDADE_FILMES * sizeof(tFilme*));

            if ((*Locadora).filmes == NULL) {
                printf("Erro! realocacao de memoria do vetor de filmes da locadora mal-sucedida.\n");
                DestruirLocadora(Locadora);
                exit(1);
            }
        }
        jaCadastrado = 0;

        for (f = 0; f < (*Locadora).quantidadeFilmes; f++) {
            if (VerificarFilmeCadastrado(Locadora, codigo)){
                jaCadastrado = 1;
                break;
            }
        }
        if (jaCadastrado) {
            printf("Filme ja cadastrado no estoque\n");
            scanf("%*[^\n]\n");
        }else {
            tFilme *filme;

            filme = CriarFilme();
            
            LeFilme(filme, codigo);
            CadastrarFilmeLocadora(Locadora, filme);

            printf("Filme cadastrado %d - ", codigo);
            ImprimirNomeFilme(filme);
            printf("\n");
        }
    }
}

void AlugarFilmesLocadora(tLocadora *locadora, int *codigos, int quantidadeCodigos) {
    unsigned int c, f;
    unsigned int contador = 0, custo = 0;
    unsigned short int aluguelBemSucedido = 0, filmeEncontrado = 0; // Variáveis Lógicas;
    
    for(c = 0; c < quantidadeCodigos; c++) {
        filmeEncontrado = 0;
        for(f = 0; f < (*locadora).quantidadeFilmes; f++) {
            if (VerificarFilmeCadastrado(locadora, *(codigos + c))) {
                if (EhMesmoCodigoFilme((*locadora).filmes[f], *(codigos + c))) {
                    filmeEncontrado = 1;
                    if (ObterQtdEstoqueFilme((*locadora).filmes[f]) > 0) {
                        contador += 1;
                        custo += ObterValorFilme((*locadora).filmes[f]);

                        AlugarFilme((*locadora).filmes[f]);

                        aluguelBemSucedido = 1;
                    }else {
                        printf("Filme %d - ", *(codigos + c));
                        ImprimirNomeFilme((*locadora).filmes[f]);
                        printf(" nao disponivel no estoque. Volte mais tarde.\n");
                    }
                    break;
                }
            }
        }
        if (!(filmeEncontrado))
            printf("Filme %d nao cadastrado.\n", *(codigos + c));
    }
    if (aluguelBemSucedido)
        printf("Total de filmes alugados: %d com custo de R$%d\n", contador, custo);
}

void LerAluguelLocadora(tLocadora *locadora) {
    RealizarAcao(locadora, AlugarFilmesLocadora);
}

void DevolverFilmesLocadora(tLocadora *locadora, int *codigos, int quantidadeCodigos) {
    unsigned int c, f;
    unsigned short int filmeEncontrado;

    for(c = 0; c < quantidadeCodigos; c++) {
          filmeEncontrado = 0;
        for(f = 0; f < (*locadora).quantidadeFilmes; f++) {
            if (VerificarFilmeCadastrado(locadora, *(codigos + c))) {
                if (EhMesmoCodigoFilme((*locadora).filmes[f], *(codigos + c))){
                    filmeEncontrado = 1;
                    if (ObterQtdAlugadaFilme((*locadora).filmes[f])) {
                        
                        DevolverFilme((*locadora).filmes[f]);

                        locadora->lucro += ObterValorFilme((*locadora).filmes[f]);
                        
                        printf("Filme %d - ", ObterCodigoFilme((*locadora).filmes[f]));
                        ImprimirNomeFilme((*locadora).filmes[f]);
                        printf(" Devolvido!\n");
                    }else {
                        printf("Nao e possivel devolver o filme %d - ", *(codigos + c));
                        ImprimirNomeFilme((*locadora).filmes[f]);
                        printf(".\n");
                    }
                    break;
                }
            }        
        }
        if (!(filmeEncontrado))
            printf("Filme %d nao cadastrado.\n", *(codigos + c));
    }
}

void LerDevolucaoLocadora(tLocadora *locadora) {
    RealizarAcao(locadora, DevolverFilmesLocadora);
}

void ConsultarEstoqueLocadora(tLocadora *locadora) {
    unsigned int f;

    printf("~ESTOQUE~\n");

    for(f = 0; f < (*locadora).quantidadeFilmes; f++) {
        printf("%d - ", ObterCodigoFilme((*locadora).filmes[f]));
        ImprimirNomeFilme((*locadora).filmes[f]);
        printf(" Fitas em estoque: %d\n", ObterQtdEstoqueFilme((*locadora).filmes[f]));
    }
}

void ConsultarLucroLocadora(tLocadora *locadora) {
    if ((*locadora).lucro > 0)
        printf("\nLucro total R$%.0f\n", (*locadora).lucro);
}

int VerificarFilmeCadastrado(tLocadora *locadora, int codigo) {
    unsigned int f;

    for(f = 0; f < (*locadora).quantidadeFilmes; f++) {
        if (EhMesmoCodigoFilme((*locadora).filmes[f], codigo))
            return 1;
    }
    return 0;
}

void OrdenarFilmesLocadora(tLocadora *locadora) {
    unsigned int f1, f2;

    for(f1 = 0; f1 < ((*locadora).quantidadeFilmes - 1); f1++) {
        for(f2 = f1 + 1; f2 < (*locadora).quantidadeFilmes; f2++) {
            if (CompararNomesFilmes((*locadora).filmes[f1], (*locadora).filmes[f2]) == 1)
                trocaFilmes((*locadora).filmes, f1, f2);
        }
    }
}

void DestruirLocadora(tLocadora *locadora) {
    if (locadora != NULL) {
        if ((*locadora).filmes != NULL) {
            unsigned int f;

            for(f = 0; f < (*locadora).quantidadeFilmes; f++)
                DestruirFilme((*locadora).filmes[f]);

            free((*locadora).filmes);
        }
        free(locadora);
    }
}