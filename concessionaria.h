#include "veiculo.h"
#include <vector>

class Concessionaria {
    private:
        string nome;
        long long int cnpj;
        int qtd_estoque;
        //vector<Carro> carros;
    public:
        Concessionaria(string n, long long int c);
        ~Concessionaria();
        friend std::ostream& operator<< (std::ostream &o, Concessionaria const c);
};

Concessionaria::Concessionaria(string n, long long int c) {
    nome = n;
    cnpj = c;
    qtd_estoque = 0;
}

Concessionaria::~Concessionaria() {

}

//Sobrecarga do operador << na classe Concessionaria
std::ostream& operator<< (std::ostream &o, Concessionaria const c) {
    o << "Nome: " << c.nome << std::endl;
    o << "CNPJ: " << c.cnpj << std::endl;
    o << "Quantidade no estoque: " << c.qtd_estoque << std::endl;
    return o;
}