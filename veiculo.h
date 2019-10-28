#include "tempo.h"

//Classe Veiculo
class Veiculo {
    protected:
        std::string marca;
        float preco;
        std::string chassi;
        Tempo data;
    public:
        static int qtd_veiculos;
        static int getQtdVeiculos();
        std::string getMarca();
        float getPreco();
        void setPreco(float p);
        std::string getChassi();
        Tempo getData();
        std::string getDia();
        virtual int getTipo() = 0;
        int getQtdDias();
};

//Classe Carro
class Carro : public Veiculo {
    private:
        int motor;
    public:
        Carro(std::string m, float p, std::string c, Tempo d, int motor);
        ~Carro();
        int getTipo();
};

//Classe Moto
class Moto : public Veiculo {
    private:
        int modelo;
    public:
        Moto(std::string m, float p, std::string c, Tempo d, int md);
        ~Moto();
        int getTipo();
};

//Classe Caminhao
class Caminhao : public Veiculo {
    private:
        int carga;
    public:
        Caminhao(std::string m, float p, std::string c, Tempo d, int cg);
        ~Caminhao();
        int getTipo();
};