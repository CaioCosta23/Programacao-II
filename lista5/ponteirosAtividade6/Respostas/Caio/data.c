#include <stdio.h>
#include <stdlib.h>

#include "data.h"

#define MES_28_DIAS 28
#define MES_29_DIAS 29
#define MES_30_DIAS 30
#define MES_31_DIAS 31

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

void InicializaDataParam(int dia, int mes, int ano, tData *data) {
    data->dia = dia;
    data->mes = mes;
    data->ano = ano;
}

void LeData(tData *data) {
    unsigned short int dia, mes;
    unsigned int ano;

    scanf("%hd %hd %d", &dia, &mes, &ano);

    InicializaDataParam(dia, mes, ano, data);
}

int EhBissexto(tData *data) {
    return ((((*data).ano % 4 == 0) && ((*data).ano % 100 != 0)) || (((*data).ano % 100 == 0) && ((*data).ano % 400 == 0)));
}

int InformaQtdDiasNoMes(tData *data) {
    if (((*data).mes == FEVEREIRO)) {
        if (!(EhBissexto(data)))
            return MES_28_DIAS;
        else
            return MES_29_DIAS;
    }else if (((*data).mes == ABRIL) || ((*data).mes == JUNHO) || ((*data).mes == SETEMBRO) || ((*data).mes == NOVEMBRO)) {
        return MES_30_DIAS;
    }else {
        return MES_31_DIAS;
    }
}

void AvancaParaDiaSeguinte(tData *data) {
    if ((*data).dia == InformaQtdDiasNoMes(data)) {
        data->dia = 1;
        if ((*data).mes == DEZEMBRO) {
            data->mes = 1;
            data->ano++;
        }else {
            data->mes++;
        }
    }else {
        data->dia++;
    }
}

int EhIgual(tData *data1, tData *data2) {
    return (((*data1).dia == (*data2).dia) && ((*data1).mes == (*data2).mes) && ((*data1).ano == (*data2).ano));
}

void ImprimeData(tData *data) {
    printf("'%02d/%02d/%04d'", (*data).dia, (*data).mes, (*data).ano);
}