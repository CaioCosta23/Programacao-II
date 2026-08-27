#include <stdio.h>
#include <stdlib.h>

#include "conta.h"

#define SAIR 0
#define SAQUE 1
#define DEPOSITO 2
#define CADASTRO 3
#define RELATORIO 4

#define TAMANHO_MAXIMO_NOME 20
#define TAMANHO_MAXIMO_CPF 15

#define NAO_EXISTE -1

/**
 * @brief Lê o número de uma conta;
 * 
 * @return int Número lido que será colocado na conta;
 */
int LeNumeroConta() {
    int numeroConta;

    scanf("%d", &numeroConta);

    return numeroConta;
}

/**
 * @brief Lê um valor (real);
 * 
 * @return float Valor (real) lido;
 */
float LeValor() {
    float valor;

    scanf("%f", &valor);

    return valor;
}

/**
 * @brief Lê os dados de um usuário;
 * 
 * @return tUsuario Tipo de Dados Abstrato (T.A.D.) que representa a estrutura que contém os dados inicializados de um usuário;
 */
tUsuario LeUsuario() {
    tUsuario usuario;
    char nome[TAMANHO_MAXIMO_NOME], cpf[TAMANHO_MAXIMO_CPF];

    scanf("%19s %14s ", nome, cpf);

    usuario = CriaUsuario(nome, cpf);

    return usuario;
}

/**
 * @brief Lê os dados de uma conta;
 * 
 * @return tConta Tipo de Dados Abstrato (T.A.D.) que representa a estrutura que contém os dados inicializados de uma conta;
 */
tConta LeConta() {
    tUsuario usuario;
    tConta conta;
                
    usuario = LeUsuario();

    conta = CriaConta(LeNumeroConta(), usuario);

    return conta;
}

/**
 * @brief Obtém o número de uma conta;
 * 
 * @param conta Tipo de Dados Abstrato (T.A.D.) que representa a estrutura que contém os dados atualizados de uma conta;
 * @return int Número da conta;
 */
int ObtemNumeroConta(tConta conta) {
    return conta.numero;
}

/**
 * @brief Busca uma conta na lista/vetor/array de contas;
 * 
 * @param contas Lista de estruturas abstratas de dados do tipo conta (com todos os seus dados atualizados);
 * @param quantidadeContas Quantidade de contas na lista/vetor/array;
 * @return int Índice da posição da conta achada (e caso não seja encontrada, retorna um valor negativo para indicar que a conta não foi encontrada);
 */
int BuscaConta(tConta contas[], int quantidadeContas) {
    int c, numero;
    int posicao = NAO_EXISTE;

    numero = LeNumeroConta();
                
    for(c = 0; c < quantidadeContas; c++) {
        //printf("Numero: %d - Conta: %d\n", numero, contas[c].numero);
        if (VerificaConta(contas[c], numero)){
            posicao = c;
            break;
        }
    }
    //printf("Result: %d\n", posicao);
    return posicao;
}

/**
 * @brief Função (auxiliar) que varre um vertor/lista/array de contas e as imprime;
 * 
 * @param contas Lista de estruturas abstratas de dados do tipo conta (com todos os seus dados atualizados);
 * @param quantidadeContas Quantidade de contas que a lista/vetor/array possui;
 */
void ImprimeListaContas(tConta contas[], int quantidadeContas) {
    int c;

    for(c = 0; c < quantidadeContas; c++) {
        ImprimeConta(contas[c]);
    }
}


int main() {
    unsigned int quantidadeMaximaContas, operacao;
    unsigned int quantidadeContas = 0;
    unsigned short encerrar = 0;
    int posicao;

    scanf("%d\n", &quantidadeMaximaContas);

    tConta contas[quantidadeMaximaContas];

    while(1) {
        scanf("%d\n", &operacao);

        switch(operacao) {
            case SAIR:
                encerrar = 1;
                break;
            case SAQUE:
                posicao = BuscaConta(contas, quantidadeContas);

                if (posicao != NAO_EXISTE)
                    contas[posicao] = SaqueConta(contas[posicao], LeValor());

                break;
            case DEPOSITO:
                posicao = BuscaConta(contas, quantidadeContas);

                if (posicao != NAO_EXISTE)
                    contas[posicao] = DepositoConta(contas[posicao], LeValor());
                break;

            case CADASTRO:
                contas[quantidadeContas] = LeConta();

                quantidadeContas += 1;
                break;

            case RELATORIO:
                printf("===| Imprimindo Relatorio |===\n");
                ImprimeListaContas(contas, quantidadeContas);

                break;

            default:
                printf("Erro! Entrada invalida.");
                encerrar = 1;
                break;

        }

        if (encerrar)
            break;
    }

    return 0;
}