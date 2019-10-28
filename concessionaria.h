#include "veiculo.h"
#include "propriedade.h"
#include "chassi.h"
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
        int qtd_carros;
        int qtd_motos;
        int qtd_caminhoes;
        float preco_total;
        std::vector<Chassi> chassis;
    public:
        static int qtd_concessionarias;
        static int getQtdConcessionaria();
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
        void showDados();
        int checkSize();
        bool verificarExiste(std::string &chassi);
        friend std::ostream& operator<< (std::ostream &o, Concessionaria const c);
};

//Construtor da classe Concessionaria para pessoa fisica
Concessionaria::Concessionaria(std::string n, long long int c, std::string p) {
    nome = n;
    cnpj = c;
    qtd_estoque = 0;
    proprietario = Propriedade(p);
    qtd_carros = 0;
    qtd_motos = 0;
    qtd_caminhoes = 0;
    preco_total = 0;
    qtd_concessionarias++;
}

//Construtor da classe Concessionaria para pessoa juridica
Concessionaria::Concessionaria(std::string n, long long int c, long long int p) {
    nome = n;
    cnpj = c;
    qtd_estoque = 0;
    proprietario = Propriedade(p);
    qtd_carros = 0;
    qtd_motos = 0;
    qtd_caminhoes = 0;
    preco_total = 0;
    qtd_concessionarias++;
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
    qtd_carros++;
    preco_total = preco_total + c.getPreco();
    chassis.push_back(Chassi(c.getChassi(), 1, carros.size() - 1));
}

//Funcao para adicionar nova moto
void Concessionaria::novoMoto(Moto m) {
    motos.push_back(m);
    qtd_estoque++;
    qtd_motos++;
    preco_total = preco_total + m.getPreco();
    chassis.push_back(Chassi(m.getChassi(), 2, motos.size() - 1));
}

//Funcao para adicionar novo caminhao
void Concessionaria::novoCaminhao(Caminhao c) {
    caminhoes.push_back(c);
    qtd_estoque++;
    qtd_caminhoes++;
    preco_total = preco_total + c.getPreco();
    chassis.push_back(Chassi(c.getChassi(), 3, caminhoes.size() - 1));
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

//Getter do atributo proprietario
Propriedade Concessionaria::getPropriedade() {
    return proprietario;
}

//Getter do atributo estatico qtd_concessionarias
int Concessionaria::getQtdConcessionaria() {
    return qtd_concessionarias;
}

//Funcao que mostrar os dados de proprietario, quantiade de carro, motos e caminhoes, e o preco total dos veiculos
void Concessionaria::showDados() {
    std::cout << "Nome: " << nome << std::endl;
    std::cout << "Proprietário " << proprietario << std::endl;
    std::cout << "Quantidade de Carros: " << qtd_carros << std::endl;
    std::cout << "Quantidade de Motos: " << qtd_motos << std::endl;
    std::cout << "Quantidade de Caminhoes: " << qtd_caminhoes << std::endl;
    std::cout << "Preço total dos veiculos: " << preco_total << std::endl;
}

//Funcao que retorna o tamanho do vector carros
int Concessionaria::checkSize() {
    return carros.size();
}

//Funcao para verificar se ja existe o chassi de um carro
bool Concessionaria::verificarExiste(std::string &chassi) {
    for(unsigned int i = 0; i < carros.size(); i++ ) {
        if( chassi.compare(carros[i].getChassi()) == 0 ) {
            return true;
        }
    }
    return false;
}

//Sobrecarga do operador << na classe Concessionaria
std::ostream& operator<< (std::ostream &o, Concessionaria const c) {
    o << "Nome: " << c.nome << std::endl;
    o << "CNPJ: " << c.cnpj << std::endl;
    o << "Quantidade no estoque: " << c.qtd_estoque << std::endl;
    o << c.proprietario;
    return o;
}