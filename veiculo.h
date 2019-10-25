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

//Getter do atributo marca
string Veiculo::getMarca() {
    return marca;
}

//Getter do atributo preco
float Veiculo::getPreco() {
    return preco;
}

//Getter do atributo chassi
int Veiculo::getChassi() {
    return chassi;
}

//Getter do atributo data
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

//Construtor da classe Carro
Carro::Carro(string m, float p, int c, string d, int mt) {
    marca = m;
    preco = p;
    chassi = c;
    data = d;
    motor = mt;
}

//Destrutor da classe Carro
Carro::~Carro() {

}

//Getter do atributo Motor
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
        Moto(string m, float p, int c, string d, int md);
        ~Moto();
        string getModelo();
};

//Construtor da classe Moto
Moto::Moto(string m, float p, int c, string d, int md) {
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
string Moto::getModelo() {
    if( modelo == 1 ) {
        return "classico";
    } else {
        return "esportivo";
    }
}

//Classe Caminhao
class Caminhao : public Veiculo {
    private:
        int carga;
    public:
        Caminhao(string m, float p, int c, string d, int cg);
        ~Caminhao();
        string getCarga();
};

//Construtor da classe Caminhao
Caminhao::Caminhao(string m, float p, int c, string d, int cg) {
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
string Caminhao::getCarga() {
    if( carga == 1 ) {
        return "comum";
    } else {
        return "perigosa";
    }
}