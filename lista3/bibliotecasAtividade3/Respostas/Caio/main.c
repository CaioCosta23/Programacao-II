#include <stdio.h>
#include <stdlib.h>

#include "data.h"

typedef struct {
    unsigned short int dia, mes;
    int ano;
}Data;

Data leData(){
    Data data;

    scanf("%02hd/%02hd/%04d\n", &data.dia, &data.mes, &data.ano);

    return data;
}

int main() {
    Data data1, data2;

    data1 = leData();
    data2 = leData();

    if ((verificaDataValida(data1.dia, data1.mes, data1.ano)) && (verificaDataValida(data2.dia, data2.mes, data2.ano))){
        int diferencaDias;

        printf("Primeira data: ");
        imprimeDataExtenso(data1.dia, data1.mes, data1.ano);
        printf("Segunda data: ");
        imprimeDataExtenso(data2.dia, data2.mes, data2.ano);

        if (comparaData(data1.dia, data1.mes, data1.ano, data2.dia, data2.mes, data2.ano) == -1)
            printf("A primeira data eh mais antiga\n");
        else if (comparaData(data1.dia, data1.mes, data1.ano, data2.dia, data2.mes, data2.ano) == 1)
            printf("A segunda data eh mais antiga\n");
        else
            printf("As datas sao iguais\n");
        
        diferencaDias = calculaDiferencaDias(data1.dia, data1.mes, data1.ano, data2.dia, data2.mes, data2.ano);
        if (diferencaDias < 10)
            printf("A diferenca em dias entre as datas eh: %02d dias", calculaDiferencaDias(data1.dia, data1.mes, data1.ano, data2.dia, data2.mes, data2.ano));
        else
            printf("A diferenca em dias entre as datas eh: %d dias\n", calculaDiferencaDias(data1.dia, data1.mes, data1.ano, data2.dia, data2.mes, data2.ano));
    }else{
        printf("A primeira e/ou segunda data(s) invalida(s)\n");
    }

    return 0;
}