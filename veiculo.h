#include "tempo.h"

//Classe Veiculo
class Veiculo {
    protected:
        string marca;
        float preco;
        string chassi;
        Tempo data;
    public:
        string getMarca();
        float getPreco();
        string getChassi();
        Tempo getData();
        string getDia();
        virtual int getTipo() = 0;
};

//Getter do atributo marca
string Veiculo::getMarca() {
    return marca;
}

//Getter do atributo preco
float Veiculo::getPreco() {
    return preco;
}

//Getter do atributo chassi
string Veiculo::getChassi() {
    return chassi;
}

//Getter do atributo data
Tempo Veiculo::getData() {
    return data;
}

string Veiculo::getDia() {
    return data.saveData();
}

//Classe Carro
class Carro : public Veiculo {
    private:
        int motor;
    public:
        Carro(string m, float p, string c, Tempo d, int motor);
        ~Carro();
        int getTipo();
};

//Construtor da classe Carro
Carro::Carro(string m, float p, string c, Tempo d, int mt) {
    marca = m;
    preco = p;
    chassi = c;
    data = d;
    motor = mt;
}

//Destrutor da classe Carro
Carro::~Carro() {

}

//Getter do atributo motor
int Carro::getTipo() {
    return motor;
}

//Classe Moto
class Moto : public Veiculo {
    private:
        int modelo;
    public:
        Moto(string m, float p, string c, Tempo d, int md);
        ~Moto();
        int getTipo();
};

//Construtor da classe Moto
Moto::Moto(string m, float p, string c, Tempo d, int md) {
    marca = m;
    preco = p;
    chassi = c;
    data = d;
    modelo = md;
}

//Destrutor da classe Moto
Moto::~Moto() {

}

//Getter do atributo Modulo
int Moto::getTipo() {
    return modelo;
}

//Classe Caminhao
class Caminhao : public Veiculo {
    private:
        int carga;
    public:
        Caminhao(string m, float p, string c, Tempo d, int cg);
        ~Caminhao();
        int getTipo();
};

//Construtor da classe Caminhao
Caminhao::Caminhao(string m, float p, string c, Tempo d, int cg) {
    marca = m;
    preco = p;
    chassi = c;
    data = d;
    carga = cg;
}

//Destrutor da classe Caminhao
Caminhao::~Caminhao() {

}

//Getter do atributo Carga
int Caminhao::getTipo() {
    return carga;
}