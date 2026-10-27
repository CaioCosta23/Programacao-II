#include <stdio.h>
#include <stdlib.h>

#include "agendatarefas.h"

typedef void (*ponteiroExecucao)(void*);
typedef void (*ponteiroLiberacao)(void*);

struct agendatarefas {
    void **tarefas;
    int *prioridades;
    int numeroTarefas, quantidadeTarefasAlocadas;
    ponteiroExecucao *execucao;
    ponteiroLiberacao *liberacao;
};


/**
 * @brief Verifica se a nova prioridade (advinda de uma nova tarefa) é maior que uma prioridade já listada (referente á uma tarefa da lista/vetor/'array' de tarefas);
 * 
 * @param prioridadeListada Prioridade de uma tarefa já listada na lista/vetor/'array' de tarefas;
 * @param novaPrioridade Prioridade de uma nova tarefa que acabou de ser cadastrada na list/vetor/'array' de tarefas da agenda;
 * @return unsigned short int 1 (verdadeiro) se a prioridade da nova tarefa listada for maior que a prioridade da tarefa que já está na lista/vetor/'array' de tarefas da agenda ou 0 (falso), caso contrário;
 */
static unsigned short int VerificaMaiorPrioridade(int prioridadeListada, int novaPrioridade) {
    return prioridadeListada < novaPrioridade;
}

/**
 * @brief Troca de posições duas tarefas da lista/vetor/'array' de tarefas da agenda e, consequentemente,
 * suas respsctivas prioridades (que estão nas mesmas posições na lista/vetor/'array' de prioridades,
 * funções de execução e liberação de tarefas da agenda);
 * 
 * @param agenda Ponteiro para o Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém os dados (atualzados) de uma agenda de tarefas;
 * @param indice1 Índice da posição da primeira tarefa e da prioridade dessa tarefa nas listas/vetores/'arrays' de tarefas e
 * prioridades de tarefas da agenda que será trocada com a segunda (em suas respectivas listas/vetores/'arrays');
 * @param indice2 Índice da posição da segunda tarefa e da prioridade dessa tarefa nas listas/vetores/'arrays' de tarefas e
 * prioridades de tarefas da agenda que será trocada com a primeira (em suas respectivas listas/vetores/'arrays');
 */
static void trocaPosicoesTarefas(tAgendaTarefas *agenda, int indice1, int indice2) {
    void *tarefaAuxiliar;
    int prioridadeAuxiliar;
    ponteiroExecucao funcaoExecucaoAuxiliar;
    ponteiroLiberacao funcaoLiberacaoAuxiliar;

    tarefaAuxiliar = (*agenda).tarefas[indice1];
    agenda->tarefas[indice1] = (*agenda).tarefas[indice2];
    agenda->tarefas[indice2] = tarefaAuxiliar;

    prioridadeAuxiliar = (*agenda).prioridades[indice1];
    agenda->prioridades[indice1] = (*agenda).prioridades[indice2];
    agenda->prioridades[indice2] = prioridadeAuxiliar;

    funcaoExecucaoAuxiliar = (*agenda).execucao[indice1];
    agenda->execucao[indice1] = (*agenda).execucao[indice2];
    agenda->execucao[indice2] = funcaoExecucaoAuxiliar;

    funcaoLiberacaoAuxiliar = (*agenda).liberacao[indice1];
    agenda->liberacao[indice1] = (*agenda).liberacao[indice2];
    agenda->liberacao[indice2] = funcaoLiberacaoAuxiliar;
}

tAgendaTarefas *CriaAgendaDeTarefas(int numElem) {
    tAgendaTarefas *agenda = NULL;
    
    agenda = (tAgendaTarefas*)malloc(sizeof(tAgendaTarefas));

    if (agenda == NULL) {
        printf("Erro! Alocacao de memoria de agenda de tarefas mal-sucedida.\n");
        exit(1);
    }

    agenda->tarefas = NULL;

    agenda->tarefas = (void**)malloc(numElem * sizeof(void*));

    if ((*agenda).tarefas == NULL) {
        printf("Erro! Alocacao de memoria para lista/vetor/'array' de tarefas da agendda mal-sucedida.\n");
        DestroiAgendaDeTarefas(agenda);
        exit(1);
    }

    agenda->prioridades = NULL;

    agenda->prioridades = (int*)calloc(numElem, sizeof(int));

    if ((*agenda).prioridades == NULL) {
        printf("Erro! Alocacao de memoria de vetor de prioridades de tarefas mal-sucedida.\n");
        DestroiAgendaDeTarefas(agenda);
        exit(1);
    }

    agenda->execucao = NULL;

    agenda->execucao = (ponteiroExecucao*)malloc(numElem * sizeof(ponteiroExecucao));

    if ((*agenda).execucao == NULL) {
        printf("Erro! Alocacao de memoria de ponteiros para funções de execucao de tarefas mal-sucedida.\n");
        DestroiAgendaDeTarefas(agenda);
        exit(1);
    }

    agenda->liberacao = NULL;

    agenda->liberacao = (ponteiroLiberacao*)malloc(numElem * sizeof(ponteiroLiberacao));

    if ((*agenda).liberacao == NULL) {
        printf("Erro! Alocacao de memoria de ponteiros para funções de liberacao (dinamica de memoria) de tarefas mal-sucedida.\n");
        DestroiAgendaDeTarefas(agenda);
        exit(1);
    }

    agenda->numeroTarefas = 0;
    agenda->quantidadeTarefasAlocadas = numElem;

    return agenda;
}

void CadastraTarefaNaAgenda(tAgendaTarefas *tar, int prioridade, void *tarefa, void (*executa)(void*), void (*destroi)(void*)) {
    tar->tarefas[(*tar).numeroTarefas] = tarefa;
    tar->prioridades[(*tar).numeroTarefas] = prioridade;
    tar->execucao[(*tar).numeroTarefas] = executa;
    tar->liberacao[(*tar).numeroTarefas] = destroi;

    tar->numeroTarefas++;

    unsigned int t;

    for(t = (*tar).numeroTarefas - 1; t > 0 ; t--) {
        if (VerificaMaiorPrioridade((*tar).prioridades[t - 1], (*tar).prioridades[t]))
            trocaPosicoesTarefas(tar, t, (t - 1));
        else
            break;
    }
}

void ExecutarTarefasDaAgenda(tAgendaTarefas *tar) {
    unsigned int t;
    for(t = 0; t < (*tar).numeroTarefas; t++)
        tar->execucao[t]((*tar).tarefas[t]);
}

void DestroiAgendaDeTarefas(tAgendaTarefas *tar) {
    if (tar != NULL) {
        if ((*tar).tarefas != NULL) {
            if ((*tar).execucao != NULL)
                free((*tar).execucao);
            
            if ((*tar).liberacao != NULL) {
                unsigned int t;

                for(t = 0; t < (*tar).numeroTarefas; t++)
                    tar->liberacao[t]((*tar).tarefas[t]);
                
                free((*tar).liberacao);
            }
            free((*tar).tarefas);
        }
        if ((*tar).prioridades != NULL)
            free((*tar).prioridades);

        free(tar);
    }
}