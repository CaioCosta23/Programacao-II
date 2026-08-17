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

int verificaDataValida(int dia, int mes, int ano) {
    if (((dia > 0) && (dia <= numeroDiasMes(mes, ano))) && ((mes > 0) && (mes <= NUMERO_MESES_ANO)))
        return 1;

    return 0;
}

int verificaBissexto(int ano) {
    return (((ano % 4 == 0) && (ano % 100 != 0)) || ((ano % 100 == 0) && (ano % 400 == 0)));
}

int numeroDiasMes(int mes, int ano) {
    if (mes == FEVEREIRO)
        if (!(verificaBissexto(ano)))
            return 28;
        else
            return 29;
    else if ((mes == ABRIL) || (mes == JUNHO) || (mes == SETEMBRO) || (mes == NOVEMBRO))
        return 30;
    else
        return 31;

}

int comparaData(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2) {
    if (ano1 > ano2){
        return 1;
    }else if (ano1 == ano2){
        if (mes1 > mes2) {
            return 1;
        }else if (mes1 == mes2) {
            if (dia1 > dia2) {
                return 1;
            }else if (dia1 == dia2) {
                return 0;
            }else {
                return -1;
            }
        }else {
            return -1;
        }
    }else{
        return -1;
    }
}

int calculaDiferencaDias(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2) {
    unsigned short int dia, mes, ano;
    unsigned int quantidadeDias = 0;
    
    if (comparaData(dia1, mes1, ano1, dia2, mes2, ano2) == 1) {
        dia = dia1;
        mes = mes1;
        ano = ano1;

        while((dia != dia2) && (mes != mes2) && (ano != ano2)) {
            if (dia == numeroDiasMes(mes, ano)){
                dia = 1;

                if (mes == NUMERO_MESES_ANO){
                    mes = 1;
                    ano++;
                }else {
                    mes++;
                }
            }else{
                dia++;
            }
            quantidadeDias += 1;
        }
    }else if (comparaData(dia1, mes1, ano2, dia2, mes2, ano2) == - 1) {
        dia = dia2;
        mes = mes2;
        ano = ano2;

        while((dia != dia1) && (mes != mes1) && (ano != ano1)) {
            if (dia == numeroDiasMes(mes, ano)){
                dia = 1;

                if (mes == NUMERO_MESES_ANO){
                    mes = 1;
                    ano++;
                }else {
                    mes++;
                }
            }else{
                dia++;
            }
            quantidadeDias += 1;
        }
    }else{
        return 0;
    }

    return -1;

}

void imprimeMesExtenso(int mes) {
    switch(mes){
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
            printf("Erro! Mes inexistente");
            break;
    }
}

void imprimeDataExtenso(int dia, int mes, int ano) {
    printf("%02d de ", dia);
    imprimeMesExtenso(mes);
    printf(" de %04d\n", ano);
}