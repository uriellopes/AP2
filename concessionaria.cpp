#include "concessionaria.h"

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

//Função para aumentar o preço em uma certa % de todos os veiculos
void Concessionaria::aumentarPreco(float value) {
    float percent = value/100;
    for(unsigned int i = 0; i < carros.size(); i++ ) {
        carros[i].setPreco(carros[i].getPreco() + (carros[i].getPreco() * percent));
    }

    for(unsigned int i = 0; i < motos.size(); i++ ) {
        motos[i].setPreco(motos[i].getPreco() + (motos[i].getPreco() * percent));
    }

    for(unsigned int i = 0; i < caminhoes.size(); i++ ) {
        caminhoes[i].setPreco(caminhoes[i].getPreco() + (caminhoes[i].getPreco() * percent));
    }

    preco_total = preco_total + ( preco_total * percent );
}

//Função para mostrar todos os carros de uma concessionária
void Concessionaria::showVeiculos() {    
    int j = 0;
    if ( qtd_estoque > 0 ) {

        std::cout << std::endl << "=================================" << std::endl;
        std::cout << "Lista de Carros da Concessionaria " << std::endl;
        std::cout << "=================================" << std::endl << std::endl;

        if( !carros.empty() ) {

            std::cout << std::setw(10) << "|" << std::setw(12) << "Marca" << std::setw(8) << "|" 
            << std::setw(12) << "Preco" << std::setw(8) << "|" 
            << std::setw(13) << "Chassi" << std::setw(7) << "|" 
            << std::setw(11) << "Data" << std::setw(6) << "|" << std::setw(10) << "Motor"<< std::endl;

            for(std::vector<Carro>::iterator i = carros.begin(); i != carros.end(); i++ ) {
                ++j;
                if ( j > 9 ) {
                    std::cout << "Carro " << j << " |" << std::setw(13) << i->getMarca() << std::setw(7) << "|" 
                    << std::setw(13) << std::fixed << std::setprecision(2) << i->getPreco() << std::setw(7) << "|"
                    << std::setw(15) << i->getChassi() << std::setw(5) << "|" 
                    << std::setw(5) << i->getData() << std::setw(5) << "|";
                    if( i->getTipo() == 1 ) {
                        std::cout << std::setw(10) << "Gasolina" << std::endl; 
                    } else {
                        std::cout << std::setw(10) << "Eletrico" << std::endl; 
                    }
                } else {
                    std::cout << std::setw(6) << "Carro " << j << "  |" << std::setw(13) << i->getMarca() << std::setw(7) << "|" 
                    << std::setw(13) << std::fixed << std::setprecision(2) << i->getPreco() << std::setw(7) << "|"
                    << std::setw(15) << i->getChassi() << std::setw(5) << "|" 
                    << std::setw(5) << i->getData() << std::setw(5) << "|";
                    if( i->getTipo() == 1 ) {
                        std::cout << std::setw(10) << "Gasolina" << std::endl; 
                    } else {
                        std::cout << std::setw(10) << "Eletrico" << std::endl; 
                    }
                }
            }
        } else {
            std::cout << "Nenhum carro cadastrado" << std::endl << std::endl;
        }

        std::cout << std::endl << "=================================" << std::endl;
        std::cout << "Lista de Motos da Concessionaria " << std::endl;
        std::cout << "=================================" << std::endl << std::endl;

        j = 0;
        if( !motos.empty() ) {

            std::cout << std::setw(10) << "|" << std::setw(12) << "Marca" << std::setw(8) << "|" 
            << std::setw(12) << "Preco" << std::setw(8) << "|" 
            << std::setw(13) << "Chassi" << std::setw(7) << "|" 
            << std::setw(11) << "Data" << std::setw(6) << "|" << std::setw(10) << "Modelo"<< std::endl;

            for(std::vector<Moto>::iterator i = motos.begin(); i != motos.end(); i++ ) {
                ++j;
                if ( j > 9 ) {
                    std::cout << "Moto " << j << " |" << std::setw(13) << i->getMarca() << std::setw(7) << "|" 
                    << std::setw(13) << std::fixed << std::setprecision(2) << i->getPreco() << std::setw(7) << "|"
                    << std::setw(15) << i->getChassi() << std::setw(5) << "|" 
                    << std::setw(5) << i->getData() << std::setw(5) << "|";
                    if( i->getTipo() == 1 ) {
                        std::cout << std::setw(10) << "Classico" << std::endl; 
                    } else {
                        std::cout << std::setw(10) << "Esportivo" << std::endl; 
                    }
                } else {
                    std::cout << std::setw(6) << "Moto " << j << "  |" << std::setw(13) << i->getMarca() << std::setw(7) << "|" 
                    << std::setw(13) << std::fixed << std::setprecision(2) << i->getPreco() << std::setw(7) << "|"
                    << std::setw(15) << i->getChassi() << std::setw(5) << "|" 
                    << std::setw(5) << i->getData() << std::setw(5) << "|";
                    if( i->getTipo() == 1 ) {
                        std::cout << std::setw(10) << "Classico" << std::endl; 
                    } else {
                        std::cout << std::setw(10) << "Esportivo" << std::endl; 
                    }
                }
            }
        } else {
            std::cout << "Nenhuma moto cadastrada" << std::endl << std::endl;
        }

        std::cout << std::endl << "====================================" << std::endl;
        std::cout << "Lista de Caminhoes da Concessionaria " << std::endl;
        std::cout << "====================================" << std::endl << std::endl;

        j = 0;
        if( !caminhoes.empty() ) {

            std::cout << std::setw(13) << "|" << std::setw(12) << "Marca" << std::setw(8) << "|" 
            << std::setw(12) << "Preco" << std::setw(8) << "|" 
            << std::setw(13) << "Chassi" << std::setw(7) << "|" 
            << std::setw(11) << "Data" << std::setw(6) << "|" << std::setw(10) << "Carga"<< std::endl;

            for(std::vector<Caminhao>::iterator i = caminhoes.begin(); i != caminhoes.end(); i++ ) {
                ++j;
                if ( j > 9 ) {
                    std::cout << "Caminhao " << j << " |" << std::setw(13) << i->getMarca() << std::setw(7) << "|" 
                    << std::setw(13) << std::fixed << std::setprecision(2) << i->getPreco() << std::setw(7) << "|"
                    << std::setw(15) << i->getChassi() << std::setw(5) << "|" 
                    << std::setw(5) << i->getData() << std::setw(5) << "|";
                    if( i->getTipo() == 1 ) {
                        std::cout << std::setw(10) << "Comum" << std::endl; 
                    } else {
                        std::cout << std::setw(10) << "Perigosa" << std::endl; 
                    }
                } else {
                    std::cout << std::setw(6) << "Caminhao " << j << "  |" << std::setw(13) << i->getMarca() << std::setw(7) << "|" 
                    << std::setw(13) << std::fixed << std::setprecision(2) << i->getPreco() << std::setw(7) << "|"
                    << std::setw(15) << i->getChassi() << std::setw(5) << "|" 
                    << std::setw(5) << i->getData() << std::setw(5) << "|";
                    if( i->getTipo() == 1 ) {
                        std::cout << std::setw(10) << "Comum" << std::endl; 
                    } else {
                        std::cout << std::setw(10) << "Perigosa" << std::endl; 
                    }
                }
            }
        } else {
            std::cout << "Nenhum caminhao cadastrada" << std::endl << std::endl;
        }

    } else {
        std::cout << "Nenhum veiculo cadastrado na concessionaria" << std::endl;
    }
}

//Função que lista os veiculos da concessionária que foram produzidos há menos de 90 dias
void Concessionaria::listarVeiculosRecentes() {
    time_t atual;
    time(&atual);
    tm * tempo = localtime(&atual);

    Tempo hoje = Tempo(tempo->tm_mday, tempo->tm_mon + 1, tempo->tm_year + 1900);

    int j = 0;
    if ( qtd_estoque > 0 ) {

        std::cout << std::endl << "=================================" << std::endl;
        std::cout << "Lista de Carros da Concessionaria " << std::endl;
        std::cout << "=================================" << std::endl << std::endl;

        if( !carros.empty() ) {

            std::cout << std::setw(10) << "|" << std::setw(12) << "Marca" << std::setw(8) << "|" 
            << std::setw(12) << "Preco" << std::setw(8) << "|" 
            << std::setw(13) << "Chassi" << std::setw(7) << "|" 
            << std::setw(11) << "Data" << std::setw(6) << "|" << std::setw(10) << "Motor"<< std::endl;

            for(std::vector<Carro>::iterator i = carros.begin(); i != carros.end(); i++ ) {
                if( (hoje.getQtdDias() - i->getQtdDias()) < 90 ) {
                    ++j;
                    if ( j > 9 ) {
                        std::cout << "Carro " << j << " |" << std::setw(13) << i->getMarca() << std::setw(7) << "|" 
                        << std::setw(13) << std::fixed << std::setprecision(2) << i->getPreco() << std::setw(7) << "|"
                        << std::setw(15) << i->getChassi() << std::setw(5) << "|" 
                        << std::setw(5) << i->getData() << std::setw(5) << "|";
                        if( i->getTipo() == 1 ) {
                            std::cout << std::setw(10) << "Gasolina" << std::endl; 
                        } else {
                            std::cout << std::setw(10) << "Eletrico" << std::endl; 
                        }
                    } else {
                        std::cout << std::setw(6) << "Carro " << j << "  |" << std::setw(13) << i->getMarca() << std::setw(7) << "|" 
                        << std::setw(13) << std::fixed << std::setprecision(2) << i->getPreco() << std::setw(7) << "|"
                        << std::setw(15) << i->getChassi() << std::setw(5) << "|" 
                        << std::setw(5) << i->getData() << std::setw(5) << "|";
                        if( i->getTipo() == 1 ) {
                            std::cout << std::setw(10) << "Gasolina" << std::endl; 
                        } else {
                            std::cout << std::setw(10) << "Eletrico" << std::endl; 
                        }
                    }
                }
            }
            if( j == 0) {
                std::cout << "Nenhum carro encontrado" << std::endl;
            }
        } else {
            std::cout << "Nenhum carro cadastrado" << std::endl << std::endl;
        }

        std::cout << std::endl << "=================================" << std::endl;
        std::cout << "Lista de Motos da Concessionaria " << std::endl;
        std::cout << "=================================" << std::endl << std::endl;

        j = 0;
        if( !motos.empty() ) {

            std::cout << std::setw(10) << "|" << std::setw(12) << "Marca" << std::setw(8) << "|" 
            << std::setw(12) << "Preco" << std::setw(8) << "|" 
            << std::setw(13) << "Chassi" << std::setw(7) << "|" 
            << std::setw(11) << "Data" << std::setw(6) << "|" << std::setw(10) << "Modelo"<< std::endl;

            for(std::vector<Moto>::iterator i = motos.begin(); i != motos.end(); i++ ) {
                if( (hoje.getQtdDias() - i->getQtdDias()) < 90 ) {
                    ++j;
                    if ( j > 9 ) {
                        std::cout << "Moto " << j << " |" << std::setw(13) << i->getMarca() << std::setw(7) << "|" 
                        << std::setw(13) << std::fixed << std::setprecision(2) << i->getPreco() << std::setw(7) << "|"
                        << std::setw(15) << i->getChassi() << std::setw(5) << "|" 
                        << std::setw(5) << i->getData() << std::setw(5) << "|";
                        if( i->getTipo() == 1 ) {
                            std::cout << std::setw(10) << "Classico" << std::endl; 
                        } else {
                            std::cout << std::setw(10) << "Esportivo" << std::endl; 
                        }
                    } else {
                        std::cout << std::setw(6) << "Moto " << j << "  |" << std::setw(13) << i->getMarca() << std::setw(7) << "|" 
                        << std::setw(13) << std::fixed << std::setprecision(2) << i->getPreco() << std::setw(7) << "|"
                        << std::setw(15) << i->getChassi() << std::setw(5) << "|" 
                        << std::setw(5) << i->getData() << std::setw(5) << "|";
                        if( i->getTipo() == 1 ) {
                            std::cout << std::setw(10) << "Classico" << std::endl; 
                        } else {
                            std::cout << std::setw(10) << "Esportivo" << std::endl; 
                        }
                    }
                }
            }
            if( j == 0) {
                std::cout << "Nenhuma moto encontrada" << std::endl;
            }
        } else {
            std::cout << "Nenhuma moto cadastrada" << std::endl << std::endl;
        }

        std::cout << std::endl << "====================================" << std::endl;
        std::cout << "Lista de Caminhoes da Concessionaria " << std::endl;
        std::cout << "====================================" << std::endl << std::endl;

        j = 0;
        if( !caminhoes.empty() ) {

            std::cout << std::setw(13) << "|" << std::setw(12) << "Marca" << std::setw(8) << "|" 
            << std::setw(12) << "Preco" << std::setw(8) << "|" 
            << std::setw(13) << "Chassi" << std::setw(7) << "|" 
            << std::setw(11) << "Data" << std::setw(6) << "|" << std::setw(10) << "Carga"<< std::endl;

            for(std::vector<Caminhao>::iterator i = caminhoes.begin(); i != caminhoes.end(); i++ ) {
                if( (hoje.getQtdDias() - i->getQtdDias()) < 90 ) {
                    ++j;
                    if ( j > 9 ) {
                        std::cout << "Caminhao " << j << " |" << std::setw(13) << i->getMarca() << std::setw(7) << "|" 
                        << std::setw(13) << std::fixed << std::setprecision(2) << i->getPreco() << std::setw(7) << "|"
                        << std::setw(15) << i->getChassi() << std::setw(5) << "|" 
                        << std::setw(5) << i->getData() << std::setw(5) << "|";
                        if( i->getTipo() == 1 ) {
                            std::cout << std::setw(10) << "Comum" << std::endl; 
                        } else {
                            std::cout << std::setw(10) << "Perigosa" << std::endl; 
                        }
                    } else {
                        std::cout << std::setw(6) << "Caminhao " << j << "  |" << std::setw(13) << i->getMarca() << std::setw(7) << "|" 
                        << std::setw(13) << std::fixed << std::setprecision(2) << i->getPreco() << std::setw(7) << "|"
                        << std::setw(15) << i->getChassi() << std::setw(5) << "|" 
                        << std::setw(5) << i->getData() << std::setw(5) << "|";
                        if( i->getTipo() == 1 ) {
                            std::cout << std::setw(10) << "Comum" << std::endl; 
                        } else {
                            std::cout << std::setw(10) << "Perigosa" << std::endl; 
                        }
                    }
                }
            }
            if( j == 0) {
                std::cout << "Nenhum caminhao encontrado" << std::endl;
            }
        } else {
            std::cout << "Nenhum caminhao cadastrada" << std::endl << std::endl;
        }

    } else {
        std::cout << "Nenhum veiculo cadastrado na concessionaria" << std::endl;
    }

    std::cout << std::endl;
}

//Sobrecarga do operador << na classe Concessionaria
std::ostream& operator<< (std::ostream &o, Concessionaria const c) {
    o << "Nome: " << c.nome << std::endl;
    o << "CNPJ: " << c.cnpj << std::endl;
    o << "Quantidade no estoque: " << c.qtd_estoque << std::endl;
    o << c.proprietario;
    return o;
}