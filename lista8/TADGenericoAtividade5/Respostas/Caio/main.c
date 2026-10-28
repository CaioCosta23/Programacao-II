#include <stdio.h>
#include <stdlib.h>

#include "agendatarefas.h"
#include "tarefasoma.h"
#include "tarefamultiplica.h"
#include "tarefaimprime.h"

#define SOMA 'S'
#define MULTIPLICACAO 'M'
#define IMPRESSAO 'I'

int main() {
    unsigned int quantidadeTarefas, t;
    tAgendaTarefas *agenda;
    int prioridade;
    char tipoTarefa;
    tSoma *soma;
    tMult *multiplicacao;
    tImpr *impressao;

    printf("Digite o numero de tarefas: ");
    scanf("%d\n", &quantidadeTarefas);

    agenda = CriaAgendaDeTarefas(quantidadeTarefas);

    printf("Digite um tipo de tarefa suportado (I/S/M))\n");

    for(t = 0; t < quantidadeTarefas; t++) {
        scanf("%d ", &prioridade);

        scanf("%c ", &tipoTarefa);

        switch(tipoTarefa) {
            case SOMA:
                float numero1, numero2;

                scanf("%f %f\n", &numero1, numero2);

                soma = CriaTarefaSoma(numero1, numero2);

                CadastraTarefaNaAgenda(agenda, prioridade, soma, ExecutaTarefaSoma, DestroiTarefaSoma);
                break;
            case MULTIPLICACAO:
                float numero1, numero2;

                scanf("%f %f\n", &numero1, numero2);

                multiplicacao = CriaTarefaMultiplicar(numero1, numero2);

                CadastraTarefaNaAgenda(agenda, prioridade, multiplicacao, ExecutaTarefaMultiplicar, DestroiTarefaMultiplicar);
                break;
            case IMPRESSAO:
                char *mensagem;
                
                scanf("%[^\n]\n", mensagem);

                impressao = CriaTarefaImprimir(mensagem);

                CadastraTarefaNaAgenda(agenda, prioridade, impressao, ExecutaTarefaImprimir, DestroiTarefaImprimir);
                break;
            default:
                break;
        }
    }

    ExecutarTarefasDaAgenda(agenda);
    DestroiAgendaDeTarefas(agenda);

    return 0;
}