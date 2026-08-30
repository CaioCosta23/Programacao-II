#include <stdio.h>
#include <stdlib.h>

#include "data.h"

/**
 * @brief Lê os dados/informações de uma data; 
 * 
 * @return tData Tipo Abstrato de Dados (T.A.D.) que representa uma estrutura de dados que contém as informações/dados iniciais de uma data;
 */
tData leData() {
    unsigned short int dia, mes;
    int ano;
    tData data;

    scanf("%02hd/%02hd/%04d\n", &dia, &mes, &ano);

    data = CriaData(dia, mes, ano);

    return data;
}


/**
 * @brief Programa que lê datas, informa qual é mais antiga e qual é mais atual, imprime-as na tela
 * e informa a diferença (em dias) entre as datas;
 * 
 * @return int Programa principal;
 */
int main() {
    tData data1, data2;
    
    data1 = leData();
    data2 = leData();

    if ((!(VerificaDataValida(data1))) || (!(VerificaDataValida(data2)))) {
        printf("A primeira e/ou segunda data(s) invalida(s)\n");
    }else {
        unsigned short int comparacaoData;

        comparacaoData = ComparaData(data1, data2);

        printf("Primeira data: ");

        if (comparacaoData != 0) {
            if (comparacaoData == 1) {
                ImprimeDataExtenso(data2);
                printf("Segunda data: ");
                ImprimeDataExtenso(data1);
                printf("A primeira data eh mais antiga\n");
            }else if (comparacaoData == -1) {
                ImprimeDataExtenso(data1);
                printf("Segunda data: ");
                ImprimeDataExtenso(data2);
                printf("A segunda data eh mais antiga\n");
            }
        }else {
            printf("Segunda data: ");
            ImprimeDataExtenso(data2);
            printf("As datas sao iguais\n");
        }
        printf("A diferenca em dias entre as datas eh: %d dias\n", CalculaDiferencaDias(data1, data2));
    }

    return 0;
}