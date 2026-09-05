#include <stdio.h>
#include <stdlib.h>

#include "biblioteca.h"

#define CADASTRAR 1
#define REMOVER 2
#define LISTAR 3

#define MAX_CARACTERES 50

void imprimeMenu() {
    printf("Lista de operacoes:\n");
    printf("1 - Cadastrar livros.\n");
    printf("2 - Remoover livros.\n");
    printf("3 - Listar todos os livros cadastrados\n");
}

int main() {
    int quantidadeOperacoes, o;
    unsigned short int opcao;
    tBiblioteca biblioteca;

    biblioteca = inicializarBiblioteca();

    scanf("%d\n", &quantidadeOperacoes);

    for(o = 0; o < quantidadeOperacoes; o++) {
        imprimeMenu();
        
        scanf("%d", &opcao);

        switch(opcao) {
            case CADASTRAR:
                biblioteca = adicionarLivrosNaBiblioteca(biblioteca, lerLivro());
                break;
            case REMOVER:
                char titulo[MAX_CARACTERES];
                
                scanf("%[^\n]\n", titulo);
                
                biblioteca = removerLivroNaBiblioteca(biblioteca, titulo);
                break;
            case LISTAR:
                listarLivrosDaBiblioteca(biblioteca);
            default:
                printf("Erro! A opcao digitada eh invalida.\n");
                break;
        }
    }

    return 0;
}