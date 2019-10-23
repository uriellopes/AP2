#include <iostream>
#include "../includes/automovel.h"

//Getter do atributo estatico de Automoveis
int Automovel::getQtdCarros() {
    return qtd_carros;
}

//Contrutor da Classe
Automovel::Automovel(std::string m, float p, std::string c, Tempo d) {
    marca = m;
    preco = p;
    chassi = c;
    data_criacao = d;
    qtd_carros++;
}

//Sobrecarga do operador <<
std::ostream& operator<< (std::ostream &o, Automovel const a) {
    o << std::setw(13) << a.marca << std::setw(7) << "|" 
    << std::setw(13) << std::fixed << std::setprecision(2) << a.preco << std::setw(7) << "|"
    << std::setw(15) << a.chassi << std::setw(5) << "|" 
    << std::setw(5) << a.data_criacao;
    return o;
}

//Getter do atributo preço
void Automovel::setPreco(float value) {
    preco = value;
}

//Setter do atributo preço
float Automovel::getPreco() {
    return preco;
}

//Função que chama o getter do atributo qtd_dias da classe de Tempo
int Automovel::getQtdDias() {
    return data_criacao.getQtdDias();
}

std::string Automovel::getChassi() {
    return chassi;
}

//Destrutor da Classe
Automovel::~Automovel() {

}