#include <string>
using std::string;

#include "tempo.h"

//Classe Veiculo
class Veiculo {
    protected:
        string marca;
        float preco;
        string chassi;
        Tempo data;
};

//Classe Carro
class Carro : public Veiculo {
    private:
        int motor;
    public:
        Carro(string m, float p, string c, Tempo d, int motor);
        ~Carro();
        string getMotor();
        friend std::ostream& operator<< (std::ostream &o, Carro const c);
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

//Getter do atributo Motor
string Carro::getMotor() {
    if( motor == 1 ) {
        return "gasolina";
    } else {
        return "eletrico";
    }
}

//Sobrecarga do operador << na classe Carro
std::ostream& operator<< (std::ostream &o, Carro const c) {
    o << "Marca: " << c.marca << std::endl;
    o << "Preco: " << c.preco << std::endl;
    o << "Chassi: " << c.chassi << std::endl;
    o << "Data: " << c.data << std::endl;
    if( c.motor == 1 ) {
        o << "Motor: gasolina" << std::endl;
    } else {
        o << "Motor: eletrico" << std::endl;
    }
    return o;
}

//Classe Moto
class Moto : public Veiculo {
    private:
        int modelo;
    public:
        Moto(string m, float p, string c, Tempo d, int md);
        ~Moto();
        string getModelo();
        friend std::ostream& operator<< (std::ostream &o, Moto const m);
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
string Moto::getModelo() {
    if( modelo == 1 ) {
        return "classico";
    } else {
        return "esportivo";
    }
}

//Sobrecarga do operador << na classe Moto
std::ostream& operator<< (std::ostream &o, Moto const m) {
    o << "Marca: " << m.marca << std::endl;
    o << "Preco: " << m.preco << std::endl;
    o << "Chassi: " << m.chassi << std::endl;
    o << "Data: " << m.data << std::endl;
    if( m.modelo == 1 ) {
        o << "Modelo: classico" << std::endl;
    } else {
        o << "Modelo: esportivo" << std::endl;
    }
    return o;
}

//Classe Caminhao
class Caminhao : public Veiculo {
    private:
        int carga;
    public:
        Caminhao(string m, float p, string c, Tempo d, int cg);
        ~Caminhao();
        string getCarga();
        friend std::ostream& operator<< (std::ostream &o, Caminhao const c);
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
string Caminhao::getCarga() {
    if( carga == 1 ) {
        return "comum";
    } else {
        return "perigosa";
    }
}

//Sobrecarga do operador << na classe Caminhao
std::ostream& operator<< (std::ostream &o, Caminhao const c) {
    o << "Marca: " << c.marca << std::endl;
    o << "Preco: " << c.preco << std::endl;
    o << "Chassi: " << c.chassi << std::endl;
    o << "Data: " << c.data << std::endl;
    if( c.carga == 1 ) {
        o << "Motor: comum" << std::endl;
    } else {
        o << "Motor: perigosa" << std::endl;
    }
    return o;
}