#include <stdio.h>
#include <stdlib.h>

#include "data.h"

#define NUMERO_MESES_ANO 12

#define JANEIRO 1
#define FEVEREIRO 2
#define MARCO 3
#define ABRIL 4
#define MAIO 5
#define JUNHO 6
#define JULHO 7
#define AGOSTO 8
#define SETEMBRO 9
#define OUTUBRO 10
#define NOVEMBRO 11
#define DEZEMBRO 12

/**
 * @brief Avança os dias de uma data (dia, mês e ano se necessários); 
 * 
 * @param data Tipo de Dados Abstratos (T.A.D.) que representa a estrutura que contém os dados (atualizados) da data;
 * @return tData Tipo de Dados Abstratos (T.A.D.) que representa a estrutura que contém os dados (atualizados) da data após a mesma ter seu dia (e mês e ano, caso necessário) avançados;
 */
static tData AvancaDiaData(tData data) {
    if (data.dia == NumeroDiasMes(data)) {
        data.dia = 1;
        if (data.mes == NUMERO_MESES_ANO) {
            data.mes = 1;
            data.ano += 1;
        }else {
            data.mes += 1;
        }
    }else {
        data.dia += 1;
    }
    return data;
}

tData CriaData(int dia, int mes, int ano) {
    tData data;

    data.dia = dia;
    data.mes = mes;
    data.ano = ano;

    return data;
}

int VerificaDataValida(tData data) {
    return (((data.dia > 0) && (data.dia <= NumeroDiasMes(data))) && ((data.mes > 0) && (data.mes <= NUMERO_MESES_ANO)));
}

int VerificaBissexto(tData data) {
    return  (((data.ano % 4  == 0) && (data.ano % 100 != 00)) || (((data.ano % 100 == 0) && (data.ano % 400 == 0))));
}

int NumeroDiasMes(tData data) {
    if (data.mes == FEVEREIRO)
        if (!(VerificaBissexto(data)))
            return 28;
        else
            return 29;
    else if ((data.mes == ABRIL) || (data.mes == JUNHO) || (data.mes == SETEMBRO) || (data.mes == NOVEMBRO))
        return 30;
    else
        return 31;
}

int ComparaData(tData data1, tData data2) {
    if (data1.ano > data2.ano)
        return 1;
    else if (data1.ano == data2.ano)
        if (data1.mes > data2.mes)
            return 1;
        else if (data1.mes == data2.mes)
            if (data1.dia > data2.dia)
                return 1;
            else if (data1.dia == data2.dia)
                return 0;
            else
                return -1;
        else
            return -1;
    else
        return -1;
}

int CalculaDiasAteMes(tData data) {
    return (NumeroDiasMes(data) - data.dia);
}

int CalculaDiferencaDias(tData data1, tData data2) {
    int diferenca = 0;
    short int comparacaoData; // Variavel llógica que recebe o resultado da comparação da data;

    comparacaoData = ComparaData(data1, data2);

    if (comparacaoData != 0){
        tData dataAuxiliar;

        if (comparacaoData == 1) {
            dataAuxiliar = CriaData(data2.dia, data2.mes, data2.ano);

            while((dataAuxiliar.dia != data1.dia) || (dataAuxiliar.mes != data1.mes) || (dataAuxiliar.ano != data1.ano)) {
                dataAuxiliar = AvancaDiaData(dataAuxiliar);
                diferenca += 1;
            }
        }else if (comparacaoData == -1) {
            dataAuxiliar = CriaData(data1.dia, data1.mes, data1.ano);

            while((dataAuxiliar.dia != data2.dia) || (dataAuxiliar.mes != data2.mes) || (dataAuxiliar.ano != data2.ano)) {
                dataAuxiliar = AvancaDiaData(dataAuxiliar);
                diferenca += 1;
            }
        }
    }else {
        /*
         * Neste caso, não há necessidade de preocupação de tamanho (por atribuir um 'short int' a um 'int'), uma vez que sabemos que somente há
         * 3 possibilidade de resultaos para um compara data (-1, 0 ou 1) e naturalmente o valor 0 será a mesma coisa que a diferença de dias entre 
         * a primeira e a segunda data (que retorna 0 na função de comparação caso as duas datas sejam iguais);
        */

        diferenca = comparacaoData;
    }
    return diferenca;
}

void ImprimeMesExtenso(tData data) {
    switch(data.mes) {
        case JANEIRO:
            printf("Janeiro");
            break;
        case FEVEREIRO:
            printf("Fevereiro");
            break;
        case MARCO:
            printf("Marco");
            break;
        case ABRIL:
            printf("Abril");
            break;
        case MAIO:
            printf("Maio");
            break;
        case JUNHO:
            printf("Junho");
            break;
        case JULHO:
            printf("Julho");
            break;
        case AGOSTO:
            printf("Agosto");
            break;
        case SETEMBRO:
            printf("Setembro");
            break;
        case OUTUBRO:
            printf("Outubro");
            break;
        case NOVEMBRO:
            printf("Novembro");
            break;
        case DEZEMBRO:
            printf("Dezembro");
            break;
        default:
            printf("Erro! Mes inexistente/ data invalida.");
    }
}

void ImprimeDataExtenso(tData data) {
    printf("%02d de ", data.dia);
    ImprimeMesExtenso(data);
    printf(" de %04d\n", data.ano);
}