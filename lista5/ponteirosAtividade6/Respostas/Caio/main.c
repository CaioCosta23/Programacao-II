#include <stdio.h>
#include <stdlib.h>

#include "data.h"

/**
 * @brief Programa que lê os dados de duas datas e
 * avança os dias da data mais antiga até chegar a mais recente (informada);
 * 
 * @return int Programa principal;
 */
int main() {
    tData *data1, *data2;

    LeData(data1);
    LeData(data2);

    while(!(EhIgual(data1, data2))) {
        ImprimeData(data1);
        AvancaParaDiaSeguinte(data1);
    }

    return 0;
}