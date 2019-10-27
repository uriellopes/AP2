#include "veiculo.h"
#include "propriedade.h"
#include <vector>

class Concessionaria {
    private:
        std::string nome;
        long long int cnpj;
        int qtd_estoque;
        std::vector<Carro> carros;
        std::vector<Moto> motos;
        std::vector<Caminhao> caminhoes;
        Propriedade proprietario;
    public:
        Concessionaria(std::string n, long long int c, std::string p);
        Concessionaria(std::string n, long long int c, long long p);
        ~Concessionaria();
        std::string getNome();
        long long int getCNPJ();
        void novoCarro(Carro c);
        void novoMoto(Moto m);
        void novoCaminhao(Caminhao c);
        std::vector<Carro> getCarros();
        std::vector<Moto> getMotos();
        std::vector<Caminhao> getCaminhoes();
        Propriedade getPropriedade();
        friend std::ostream& operator<< (std::ostream &o, Concessionaria const c);
};

//Construtor da classe Concessionaria
Concessionaria::Concessionaria(std::string n, long long int c, std::string p) {
    nome = n;
    cnpj = c;
    qtd_estoque = 0;
    proprietario = Propriedade(p);
}

Concessionaria::Concessionaria(std::string n, long long int c, long long int p) {
    nome = n;
    cnpj = c;
    qtd_estoque = 0;
    proprietario = Propriedade(p);
}

//Destrutor da classe Concessionaria
Concessionaria::~Concessionaria() {

}

//Getter do atributo nome
std::string Concessionaria::getNome() {
    return nome;
}

//Getter do atributo cnpj
long long int Concessionaria::getCNPJ() {
    return cnpj;
}

//Funcao para adicionar novo carro
void Concessionaria::novoCarro(Carro c) {
    carros.push_back(c);
    qtd_estoque++;
}

//Funcao para adicionar nova moto
void Concessionaria::novoMoto(Moto m) {
    motos.push_back(m);
    qtd_estoque++;
}

//Funcao para adicionar novo caminhao
void Concessionaria::novoCaminhao(Caminhao c) {
    caminhoes.push_back(c);
    qtd_estoque++;
}

//Funcao que retorna o vetor de carros
std::vector<Carro> Concessionaria::getCarros() {
    return carros;
}

//Funcao que retorna o vetor de motos
std::vector<Moto> Concessionaria::getMotos() {
    return motos;
}

//Funcao que retorna o vetor de caminhoes
std::vector<Caminhao> Concessionaria::getCaminhoes() {
    return caminhoes;
}

Propriedade Concessionaria::getPropriedade() {
    return proprietario;
}

//Sobrecarga do operador << na classe Concessionaria
std::ostream& operator<< (std::ostream &o, Concessionaria const c) {
    o << "Nome: " << c.nome << std::endl;
    o << "CNPJ: " << c.cnpj << std::endl;
    o << "Quantidade no estoque: " << c.qtd_estoque << std::endl;
    o << c.proprietario;
    return o;
}