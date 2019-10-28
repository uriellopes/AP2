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
        void buscarPorChassi(std::string c);
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

//Funcao que retorna a quantidade de veiculos cadastrados
int Concessionaria::checkSize() {
    return qtd_estoque;
}

//Funcao para verificar se ja existe o chassi de um veiculos
bool Concessionaria::verificarExiste(std::string &chassi) {
    for( unsigned int i = 0; i < chassis.size(); i++ ) {
        if( chassi.compare(chassis[i].getChassi()) == 0) {
            return true;
        }
    }
    return false;
}

void Concessionaria::buscarPorChassi(std::string c) {
    bool existe = false;
    for( unsigned int i = 0; i < chassis.size(); i++ ) {
        if( c.compare(chassis[i].getChassi()) == 0) {
            existe = true;
            switch (chassis[i].getTipo()) {
            case 1:
                std::cout << "Marca: " << carros[chassis[i].getPosicao()].getMarca() << std::endl;
                std::cout << "Preco: " << carros[chassis[i].getPosicao()].getPreco() << std::endl;
                std::cout << "Chassi: " << carros[chassis[i].getPosicao()].getChassi() << std::endl;
                std::cout << "Data: " << carros[chassis[i].getPosicao()].getData() << std::endl;
                if( carros[chassis[i].getPosicao()].getTipo() == 1 ) {
                    std::cout << "Motor: Gasolina" << std::endl;
                } else {
                    std::cout << "Motor: Eletrico" << std::endl;
                }
                break;
            case 2:
                std::cout << "Marca: " << motos[chassis[i].getPosicao()].getMarca() << std::endl;
                std::cout << "Preco: " << motos[chassis[i].getPosicao()].getPreco() << std::endl;
                std::cout << "Chassi: " << motos[chassis[i].getPosicao()].getChassi() << std::endl;
                std::cout << "Data: " << motos[chassis[i].getPosicao()].getData() << std::endl;
                if( motos[chassis[i].getPosicao()].getTipo() == 1 ) {
                    std::cout << "Modelo: Classico" << std::endl;
                } else {
                    std::cout << "Modelo: Esportivo" << std::endl;
                }
                break;
            case 3:
                std::cout << "Marca: " << caminhoes[chassis[i].getPosicao()].getMarca() << std::endl;
                std::cout << "Preco: " << caminhoes[chassis[i].getPosicao()].getPreco() << std::endl;
                std::cout << "Chassi: " << caminhoes[chassis[i].getPosicao()].getChassi() << std::endl;
                std::cout << "Data: " << caminhoes[chassis[i].getPosicao()].getData() << std::endl;
                if( caminhoes[chassis[i].getPosicao()].getTipo() == 1 ) {
                    std::cout << "Carga: Comum" << std::endl;
                } else {
                    std::cout << "Carga: Perigosa" << std::endl;
                }
                break;
            }
            break;
        }
    }

    if ( !existe ) {
        std::cout << "Nao existe nenhum veiculo cadastrado com esse chassi na concessionaria!!" << std::endl;
    }
}

//Sobrecarga do operador << na classe Concessionaria
std::ostream& operator<< (std::ostream &o, Concessionaria const c) {
    o << "Nome: " << c.nome << std::endl;
    o << "CNPJ: " << c.cnpj << std::endl;
    o << "Quantidade no estoque: " << c.qtd_estoque << std::endl;
    o << c.proprietario;
    return o;
}