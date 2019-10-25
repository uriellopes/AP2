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

//Classe Moto
class Moto : public Veiculo {
    private:
        int modelo;
    public:
};
////

//Classe Caminhao
class Caminhao : public Veiculo {
    private:
        int carga;
    public:
};
////