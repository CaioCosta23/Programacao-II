#include <stdio.h>
#include <stdlib.h>

#include "data.h"

/**
 * @brief Programa que lê uma data, e imprime a mesma por extenso, informa se o ano é bissexto, a quantidade
 * de dias que o mês da data possui e a data seguinte;
 * 
 * @return int Programa Principal;
 */
int main() {
    int dia, mes, ano;

    scanf("%d/%d/%d\n", &dia, &mes, &ano);

    if (verificaDataValida(dia, mes, ano)) {
        printf("Data informada: ");
        imprimeDataExtenso(dia, mes, ano);
        if (verificaBissexto(ano))
            printf("O ano informado eh bissexto\n");
        else
            printf("O ano informado nao eh bissexto\n");
        
            printf("O mes informado possui %d dias\n", numeroDiasMes(mes, ano));
            printf("A data seguinte eh: ");
            imprimeProximaData(dia, mes, ano);
    }else {
        printf("A data informada eh invalida\n");
    }
    
    return 0;
}