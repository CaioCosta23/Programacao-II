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
    int numeroConta;
    tUsuario usuario;
    tConta conta;
                
    usuario = LeUsuario();

    scanf("%d\n", &numeroConta);

    conta = CriaConta(numeroConta, usuario);

    return conta;
}

/**
 * @brief Lê o número de uma conta;
 * 
 * @return int Número lido que será colocado na conta;
 */
int LeNumeroConta() {
    int numeroConta;

    scanf("%d\n", &numeroConta);

    return numeroConta;
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
 * @return tConta Conta procurada (caso a mesma tenha sido achada) ou uma conta com valores inicialiados (caso a conta procurada não tenha sido achada);
 */
tConta BuscaConta(tConta contas[], int quantidadeContas) {
    tUsuario usuario = {"", ""};
    tConta conta = {-1, usuario, -1};
    int c;
                
    for(c = 0; c < quantidadeContas; c++) {
        if (VerificaConta(contas[c], LeNumeroConta())){
            conta = contas[c];
            break;
        }
    }

    return conta;
}

/**
 * @brief Função (auxiliar) que varre um vertor/lista/array de contas e as imprime;
 * 
 * @param contas Lista de estruturas abstratas de dados do tipo conta (com todos os seus dados atualizados);
 * @param quantidadeContas Quantidade de contas que a lista/vetor/array possui;
 */
static void ImprimeListaContas(tConta contas[], int quantidadeContas) {
    int c;

    for(c = 0; c < quantidadeContas; c++) {
        ImprimeConta(contas[c]);
    }
}


int main() {
    unsigned int quantidadeMaximaContas, operacao;
    unsigned int quantidadeContas = 0;
    unsigned short encerrar = 0;
    tConta conta;

    scanf("%d\n", &quantidadeMaximaContas);

    tConta contas[quantidadeMaximaContas];

    while(1) {
        scanf("%d", &operacao);

        switch(operacao) {
            case SAIR:
                encerrar = 1;
                break;
            case SAQUE:
                conta = BuscaConta(contas, quantidadeContas);

                if (ObtemNumeroConta(conta) != -1)
                    SaqueConta(conta, LeValor());

                break;
            case DEPOSITO:
                conta = BuscaConta(contas, quantidadeContas);

                if (ObtemNumeroConta(conta) != -1)
                    DepositoConta(conta, LeValor());
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