#include "../includes/veiculo.h"

//Getter do atributo marca
std::string Veiculo::getMarca() {
    return marca;
}

//Getter do atributo preco
float Veiculo::getPreco() {
    return preco;
}

//Setter do atributo preco
void Veiculo::setPreco(float p) {
    preco = p;
}

//Getter do atributo chassi
std::string Veiculo::getChassi() {
    return chassi;
}

//Getter do atributo data
Tempo Veiculo::getData() {
    return data;
}

//Funcao que retorna a data no formato para salvar no arquivo
std::string Veiculo::getDia() {
    return data.saveData();
}

//Getter do atributo estatico qtd_veiculos
int Veiculo::getQtdVeiculos() {
    return qtd_veiculos;
}

//Função que chama o getter do atributo qtd_dias da classe de Tempo
int Veiculo::getQtdDias() {
    return data.getQtdDias();
}

//Construtor da classe Carro
Carro::Carro(std::string m, float p, std::string c, Tempo d, int mt) {
    marca = m;
    preco = p;
    chassi = c;
    data = d;
    motor = mt;
    qtd_veiculos++;
}

//Destrutor da classe Carro
Carro::~Carro() {

}

//Getter do atributo motor
int Carro::getTipo() {
    return motor;
}

//Construtor da classe Moto
Moto::Moto(std::string m, float p, std::string c, Tempo d, int md) {
    marca = m;
    preco = p;
    chassi = c;
    data = d;
    modelo = md;
    qtd_veiculos++;
}

//Destrutor da classe Moto
Moto::~Moto() {

}

//Getter do atributo Modulo
int Moto::getTipo() {
    return modelo;
}

//Construtor da classe Caminhao
Caminhao::Caminhao(std::string m, float p, std::string c, Tempo d, int cg) {
    marca = m;
    preco = p;
    chassi = c;
    data = d;
    carga = cg;
    qtd_veiculos++;
}

//Destrutor da classe Caminhao
Caminhao::~Caminhao() {

}

//Getter do atributo Carga
int Caminhao::getTipo() {
    return carga;
}