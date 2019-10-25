#include <string>
using std::string;

//Classe Veiculo
class Veiculo {
    protected:
        string marca;
        float preco;
        int chassi;
        string data;
    public:
        string getMarca();
        float getPreco();
        int getChassi();
        string getData(); 
};
////

string Veiculo::getMarca() {
    return marca;
}

float Veiculo::getPreco() {
    return preco;
}

int Veiculo::getChassi() {
    return chassi;
}

string Veiculo::getData() {
    return data;
}

//Classe Carro
class Carro : public Veiculo {
    private:
        int motor;
    public:
        Carro(string m, float p, int c, string d, int motor);
        ~Carro();
        string getMotor();
};
////

//Funções da classe Carro
Carro::Carro(string m, float p, int c, string d, int mt) {
    marca = m;
    preco = p;
    chassi = c;
    data = d;
    motor = mt;
}

Carro::~Carro() {

}

string Carro::getMotor() {
    if( motor == 1 ) {
        return "gasolina";
    } else {
        return "eletrico";
    }
}
////

//Classe Moto
class Moto : public Veiculo {
    private:
        int modelo;
    public:
        Moto(string m, float p, int c, string d, int md);
        ~Moto();
        string getModelo();
};
////

//Funções da classe Moto
Moto::Moto(string m, float p, int c, string d, int md) {
    marca = m;
    preco = p;
    chassi = c;
    data = d;
    modelo = md;
}

Moto::~Moto() {

}

string Moto::getModelo() {
    if( modelo == 1 ) {
        return "classico";
    } else {
        return "esportivo";
    }
}
////

//Classe Caminhao
class Caminhao : public Veiculo {
    private:
        int carga;
    public:
        Caminhao(string m, float p, int c, string d, int cg);
        ~Caminhao();
        string getCarga();
};
////

//Funções da classe Caminhao
Caminhao::Caminhao(string m, float p, int c, string d, int cg) {
    marca = m;
    preco = p;
    chassi = c;
    data = d;
    carga = cg;
}

Caminhao::~Caminhao() {

}

string Caminhao::getCarga() {
    if( carga == 1 ) {
        return "comum";
    } else {
        return "perigosa";
    }
}
////