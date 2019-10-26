#include "veiculo.h"
#include <vector>

class Concessionaria {
    private:
        string nome;
        long long int cnpj;
        int qtd_estoque;
        std::vector<Carro> carros;
        std::vector<Moto> motos;
        std::vector<Caminhao> caminhoes;
    public:
        Concessionaria(string n, long long int c);
        ~Concessionaria();
        string getNome();
        long long int getCNPJ();
        void novoCarro(Carro c);
        void novoMoto(Moto m);
        void novoCaminhao(Caminhao c);
        friend std::ostream& operator<< (std::ostream &o, Concessionaria const c);
};

//Construtor da classe Concessionaria
Concessionaria::Concessionaria(string n, long long int c) {
    nome = n;
    cnpj = c;
    qtd_estoque = 0;
}

//Destrutor da classe Concessionaria
Concessionaria::~Concessionaria() {

}

//Getter do atributo nome
string Concessionaria::getNome() {
    return nome;
}

//Getter do atributo cnpj
long long int Concessionaria::getCNPJ() {
    return cnpj;
}

void Concessionaria::novoCarro(Carro c) {
    carros.push_back(c);
    qtd_estoque++;
}

void Concessionaria::novoMoto(Moto m) {
    motos.push_back(m);
    qtd_estoque++;
}

void Concessionaria::novoCaminhao(Caminhao c) {
    caminhoes.push_back(c);
    qtd_estoque++;
}

//Sobrecarga do operador << na classe Concessionaria
std::ostream& operator<< (std::ostream &o, Concessionaria const c) {
    o << "Nome: " << c.nome << std::endl;
    o << "CNPJ: " << c.cnpj << std::endl;
    o << "Quantidade no estoque: " << c.qtd_estoque;
    return o;
}