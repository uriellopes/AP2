#include <iostream>
#include "../includes/tempo.h"

//Função para calcular a quantidade de dias para cada ano
void diasPorAno(int &ano, int &qtd) {
    qtd += (ano - 1) * 365;
}

//Função para calcular a quantidade de dias para cada mês
void diasPorMes(int &mes, int &qtd) {
    int meses[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    for(int i = 1; i < mes; i++) {
        qtd += meses[i-1];
    }
}

//Função que calcula a quantidade de anos bissextos desde a data 01/01/0001
int qtdBissexto(int &ano) {
    return ((ano - 1) / 4) - ((ano - 1) / 100) + ((ano - 1) / 400);
}

//Função para checar se o ano atual é bissexto
bool checarBissexto(int &ano) {
    return (ano % 4 == 0) && (ano % 100 != 0 || ano % 400 == 0);
}

//Construtor Padrão
Tempo::Tempo(){

}

//Construtor da classe Tempo
Tempo::Tempo(int d, int m, int a) {
    dia = d;
    mes = m;
    ano = a;
    qtd_dias = 0;

    //Calcular quantidade de dias para cada ano passado
    diasPorAno(a, qtd_dias);

    //Calcular quantidade de dias para cada mes passado
    diasPorMes(m, qtd_dias);

    //Adicionar quantidade de dias passados
    qtd_dias += (d - 1);

    //Adiciona 1 dia a mais para cada ano bissexto 
    qtd_dias += qtdBissexto(a);

    //Checa se o ano atual é bissexto e se a data ja passou de fevereiro para adicinar 1 dia caso verdadeiro
    if( checarBissexto(a) && m > 2) {
        qtd_dias += 1;
    }    
}

//Sobrecarga do opperador <<
std::ostream& operator<< (std::ostream &o, Tempo const t) {
    o << t.dia << "/" << t.mes << "/" << t.ano;
    return o;
}

//Getter do atributo qtd_dias
int Tempo::getQtdDias() {
    return qtd_dias;
}

//Destrutor da classe Tempo
Tempo::~Tempo() {
    
}