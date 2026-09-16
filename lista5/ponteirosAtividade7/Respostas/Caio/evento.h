#ifndef EVENTO_H
#define EVENTO_H

#define MAX_EVENTOS 10

typedef struct {
    char nome[50];
    int dia, mes, ano;
}Evento;

/**
 * @brief Cadastraa um evento na lista/vetor/'array' de eventos;
 * 
 * @param eventos Ponteiro (vetor/lista/'array') Tipos Abstratos de Dados (T.A.D.s) que contém as informações dos eventos;
 * @param numEventos Ponteiro pata o número de eventos da lista/vetor/'array';
 */
void cadastrarEvento(Evento *eventos, int *numEventos);

/**
 * @brief 
 * 
 * @param eventos Ponteiro (vetor/lista/'array') Tipos Abstratos de Dados (T.A.D.s) que contém as informações dos eventos (com os dados atualizados);
 * @param numEventos Ponteiro para o numero de eventos da lista/vetor/'array' de eventos;
 */
void trocarDataEvento(Evento *eventos, int *numEventos);

/**
 * @brief Troca a posição de dois eventos na lista/vetor/'array' de eventos, utilizando como base da troca os índices das posições dos mesmos na lista/vetor/'array'; 
 * 
 * @param eventos Ponteiro (vetor/lista/'array') Tipos Abstratos de Dados (T.A.D.s) que contém as informações dos eventos (com os dados atualizados);
 * @param indiceA Ponteiro para o índice da primeira posição da troca;
 * @param indiceB Ponteiro para o índice da segunda posição da troca;
 * @param numEventos Ponteiro para o numero de eventos da lista/vetor/'array' de eventos;
 */
void trocarIndicesEventos(Evento *eventos, int *indiceA, int *indiceB, int numEventos);

/**
 * @brief Exibe os eventos da listaaa/vetor/'array'  de eventos;
 * 
 * @param eventos Ponteiro (vetor/lista/'array') Tipos Abstratos de Dados (T.A.D.s) que contém as informações dos eventos (com os dados atualizados);
 * @param numEventos Ponteiro para o numero de eventos da lista/vetor/'array' de eventos;
 */
void exibirEventos(Evento *eventos, int numEventos);

#endif
