#include <string>
using std::string;

//Classe Veiculo
class Veiculo {
    private:
        string marca;
        float preco;
        int chassi;
        string data;
};
////

//Classe Carro
class Carro : public Veiculo {
    private:
        int motor;
    public:
};
////

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