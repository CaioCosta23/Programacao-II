#include <stdio.h>
#include <stdlib.h>

#include "agendatarefas.h"
#include "tarefasoma.h"
#include "tarefamultiplica.h"
#include "tarefaimprime.h"

#define SOMA 'S'
#define MULTIPLICACAO 'M'
#define IMPRESSAO 'I'

#define TAMANHO_MAXIMO_MENSAGEM 1000

int main() {
    unsigned int quantidadeTarefas, t;
    tAgendaTarefas *agenda;
    int prioridade;
    char tipoTarefa;
    tSoma *soma;
    tMult *multiplicacao;
    tImpr *impressao;
    float numero1, numero2;

    printf("Digite o numero de tarefas:\n");
    scanf("%d\n", &quantidadeTarefas);

    agenda = CriaAgendaDeTarefas(quantidadeTarefas);

    for(t = 0; t < quantidadeTarefas; t++) {
        scanf("%d ", &prioridade);

        scanf("%c ", &tipoTarefa);

        switch(tipoTarefa) {
            case SOMA:
                scanf("%f %f\n", &numero1, &numero2);

                soma = CriaTarefaSoma(numero1, numero2);

                CadastraTarefaNaAgenda(agenda, prioridade, soma, ExecutaTarefaSoma, DestroiTarefaSoma);
                break;
            case MULTIPLICACAO:
                scanf("%f %f\n", &numero1, &numero2);

                multiplicacao = CriaTarefaMultiplicar(numero1, numero2);

                CadastraTarefaNaAgenda(agenda, prioridade, multiplicacao, ExecutaTarefaMultiplicar, DestroiTarefaMultiplicar);
                break;
            case IMPRESSAO:
                char mensagem[TAMANHO_MAXIMO_MENSAGEM];
                
                scanf("%[^\n]\n", mensagem);

                impressao = CriaTarefaImprimir(mensagem);

                CadastraTarefaNaAgenda(agenda, prioridade, impressao, ExecutaTarefaImprimir, DestroiTarefaImprimir);
                break;
            default:
                printf("Digite um tipo de tarefa suportado (I/S/M))\n");
                
                scanf("%*[^\n]");
                scanf("%*c");
                
                t--;
                break;
        }
    }
    ExecutarTarefasDaAgenda(agenda);
    DestroiAgendaDeTarefas(agenda);

    return 0;
}