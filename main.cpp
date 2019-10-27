//g++ -Wall -pedantic -g -O0 -o exec main.cpp
#include <iostream>
#include <sstream>
#include <fstream>
#include "concessionaria.h"

#ifdef _WIN32
#define LIMPAR "CLS"
#else
#define LIMPAR "clear"
#endif

int Concessionaria::qtd_concessionarias = 0;
int Veiculo::qtd_veiculos = 0;

//Função para pressionar enter para continuar
void clear() {
    system(LIMPAR);
}

//Função para pressionar enter para continuar
void pressToCont() {
    std::cout << "Pressione Enter para continuar...";
    std::cin.ignore();
}

//Função para checar se o input é um int
bool checarDigito(std::string &input) {
    for (unsigned int i = 0; i < input.size(); i++) {
        if (!isdigit(input[i])) {
            return false;
            break;
        }
    }
    return true;
}

//Funcao para ler dados iniciais em um arquivo
void lerDados(std::vector<Concessionaria> &concessionarias) {
    
    //Abrir arquivo concessionarias.txt em modo de leitura
    std::ifstream dadosConcessionaria("concessionarias.txt");

    //Extrair informacoes do arquivo concessionarias.txt para salvar no vector concessionarias
    std::vector<std::string> values;
    std::string line, value;
    while(!dadosConcessionaria.eof()) {
        getline(dadosConcessionaria, line);
        if ( !line.empty() ) {
            std::stringstream temp(line);
            values.clear();
            while(getline(temp, value, ',')) {
                values.push_back(value);
            }
            if ( stoi(values[2]) == 1 ) {
                concessionarias.push_back(Concessionaria(values[0], stoll(values[1], nullptr, 10), values[3]));
            } else {
                concessionarias.push_back(Concessionaria(values[0], stoll(values[1], nullptr, 10), stoll(values[3], nullptr, 10)));
            }
        }
    }

    //Fechar arquivo concessionarias.txt após terminar de extrair as informacoes
    dadosConcessionaria.close();

    //Abrir arquivo veiculos.txt em modo leitura
    std::ifstream dadosVeiculos("veiculos.txt");

    //Extrair informacoes do arquivo veiculos.txt para salvar no vector concessionarias
    while(!dadosVeiculos.eof()) {
        getline(dadosVeiculos, line);
        if ( !line.empty() ) {
            std::stringstream temp(line);
            values.clear();
            while(getline(temp, value, ',')) {
                values.push_back(value);
            }
            switch (stoi(values[0])) {
            case 1:
                concessionarias[stoi(values[1])].novoCarro(Carro(values[2], stof(values[3]), values[4], Tempo(stoi(values[5]), stoi(values[6]),stoi(values[7])), stoi(values[8])));
                break;
            case 2:
                concessionarias[stoi(values[1])].novoMoto(Moto(values[2], stof(values[3]), values[4], Tempo(stoi(values[5]), stoi(values[6]),stoi(values[7])), stoi(values[8])));
                break;
            case 3:
                concessionarias[stoi(values[1])].novoCaminhao(Caminhao(values[2], stof(values[3]), values[4], Tempo(stoi(values[5]), stoi(values[6]),stoi(values[7])), stoi(values[8])));
                break;
            }
        }
    }

    //Fechar arquivo veiculos.txt após terminar de extrair as informacoes
    dadosVeiculos.close();
}

//Funcao para salvar os dados em um arquivo
void salvarDados(std::vector<Concessionaria> &concessionarias) {

    //Abrir arquivos concessionarias.txt e veiculos.txt em modo de escrita
    std::ofstream dadosConcessionaria("concessionarias.txt");
    std::ofstream dadosVeiculos("veiculos.txt");

    //Salva os dados da concessionaria no arquivo concessionarias.txt e os dados dos veiculos em veiculos.txt
    for (unsigned i = 0; i < concessionarias.size(); i++) {
        dadosConcessionaria << concessionarias[i].getNome() << "," << concessionarias[i].getCNPJ() << "," << concessionarias[i].getPropriedade().getTipo() << ",";
        if(concessionarias[i].getPropriedade().getTipo() == 1) {
            dadosConcessionaria << concessionarias[i].getPropriedade().getPessoaFisica() << std::endl;
        } else {
            dadosConcessionaria << concessionarias[i].getPropriedade().getPessoaJuridica() << std::endl;
        }

        std::vector<Carro> carros = concessionarias[i].getCarros();
        for (auto j = carros.begin(); j != carros.end(); j++) {
            dadosVeiculos << "1," << i << "," << j->getMarca() << "," << j->getPreco() << "," << j->getChassi() << "," << j->getDia() << "," << j->getTipo() << std::endl;
        }

        std::vector<Moto> motos = concessionarias[i].getMotos();
        for (auto j = motos.begin(); j != motos.end(); j++) {
            dadosVeiculos << "2," << i << "," << j->getMarca() << "," << j->getPreco() << "," << j->getChassi() << "," << j->getDia() << "," << j->getTipo() << std::endl;
        }

        std::vector<Caminhao> caminhoes = concessionarias[i].getCaminhoes();
        for (auto j = caminhoes.begin(); j != caminhoes.end(); j++) {
            dadosVeiculos << "3," << i << "," << j->getMarca() << "," << j->getPreco() << "," << j->getChassi() << "," << j->getDia() << "," << j->getTipo() << std::endl;
        }
    }

    //Fecha os arquivos concessionarias.txt e veiculos.txt após inserir os dados
    dadosConcessionaria.close();
    dadosVeiculos.close();
}

void mostrarDadosConcessionarias(std::vector<Concessionaria> &concessionarias) {
    for (unsigned i = 0; i < concessionarias.size(); i++) {
        std::cout << "Concessionária " << i + 1 << std::endl;
        concessionarias[i].showDados();
        std::cout << std::endl;
    }
}

//Função para criar uma nova concessionaria
void novaConcessionaria(std::vector<Concessionaria> &concessionarias) {
    clear();
    long long int num_proprietario;
    int tipo_proprietario;
    std::string nome;
    std::string input;
    long long int cnpj;
    bool existe = false;
    bool inputValido;

    std::cout << std::endl << "#######################################" << std::endl;
    std::cout << "##   1 - Criar nova concessionaria   ##" << std::endl;
    std::cout << "#######################################" << std::endl << std::endl;

    std::cout << "Digite o nome da nova concessionaria: ";
    std::cin.ignore();
    std::getline(std::cin, nome);

    //Loop para receber um valor de CNPJ correto
    do {
        inputValido = true;
        std::cout << "Digite o CNPJ da nova concessionaria ( Digite apenas os numeros ): ";
        std::cin >> input;

        inputValido = checarDigito(input);

        if (!inputValido) {
            std::cout << std::endl;
            std::cout << "Digite apenas numeros para um valor valido!!" << std::endl;
        }
    } while (!inputValido);

    cnpj = stoll(input, nullptr, 10);

    //Verificar se já existe alguma concessionária com nome ou cpnj digitado pelo usuário cadastrada
    for (unsigned int i = 0; i < concessionarias.size(); i++) {
        if (concessionarias[i].getCNPJ() == cnpj || nome.compare(concessionarias[i].getNome()) == 0) {
            existe = true;
            break;
        }
    }

    //Se existir alertar usuario, caso nao continuar o cadastro
    if (existe) {
        std::cout << std::endl;
        std::cout << "==============================================================" << std::endl;
        std::cout << "Ja existe uma concessionaria cadastrada com esse nome ou cnpj!" << std::endl;
        std::cout << "==============================================================" << std::endl << std::endl;
    } else {

        std::cout << "Escolha o tipo de proprietario" << std::endl;
        std::cout << "1 - Pessoa Fisica" << std::endl;
        std::cout << "2 - Pessoa Juridica" << std::endl;

        do {
            std::cin >> input;

            inputValido = checarDigito(input);

            if( inputValido ) {
                tipo_proprietario = stoi(input);
                if ( tipo_proprietario > 0 && tipo_proprietario < 3) {
                    inputValido = true;
                } else {
                    inputValido = false;
                }
            }

            if (!inputValido) {
                std::cout << "Digite um valor valido!!" << std::endl;
            }
        } while (!inputValido);

        switch (tipo_proprietario) {
            case 1:
                std::cout << "Digite o nome e o sobrenome do proprietario: " << std::endl;
                std::cin.ignore();
                std::getline(std::cin, input);
                concessionarias.push_back(Concessionaria(nome, cnpj, input));
                std::cout << std::endl;
                std::cout << "Concessionaria " << nome << " criada!" << std::endl;
                break;
            case 2:
                std::cout << "Digite o numero do proprietario: " << std::endl;
                do {
                    std::cin >> input;
                    inputValido = checarDigito(input);
                    if (inputValido) {
                        num_proprietario = stoll(input, nullptr, 10);
                    }
                } while(!inputValido);

                concessionarias.push_back(Concessionaria(nome, cnpj, num_proprietario));
                std::cout << std::endl;
                std::cout << "Concessionaria " << nome << " criada!" << std::endl;
                std::cin.ignore();
                break;
        }
    }
    pressToCont();
}

//Função que mostra o menu principal do código
void showMenu(std::vector<Concessionaria> &concessionarias) {
    std::string input;
    int escolha;
    bool sair = false;
    bool error = false;

    //Loop para verificar se o input é uma opção válida e caso seja, realizer a operação referente a escolha
    do {
        clear();
        std::cout << std::endl << "############################################################" << std::endl;
        std::cout << "###                      BEM VINDO!!                     ###" << std::endl;
        std::cout << "############################################################" << std::endl;
        std::cout << std::endl << "Escolha uma das seguintes opcoes: " << std::endl << std::endl;
        std::cout << "[1] - Criar nova Concessionaria" << std::endl;
        std::cout << "[2] - Listar media de carros por concessionaria" << std::endl;
        std::cout << "[3] - Listar dados das concessionarias" << std::endl;
        int opcoes = 3;
        for (unsigned int i = 0; i < concessionarias.size(); i++) {
            std::cout << "[" << i + 4 << "] - Selecionar Concessionaria " << concessionarias[i].getNome() << std::endl;
            opcoes++;
        }

        std::cout << std::endl;
        std::cout << "[0] - Sair" << std::endl << std::endl;

        if (error) {
            error = false;
            std::cout << "**Digite uma opcao valida!**" << std::endl;
        }
        std::cout << "Opcao: ";
        std::cin >> input;

        if (checarDigito(input)) {
            escolha = std::stoi(input, nullptr);

            if (escolha >= 0 && escolha <= opcoes) {
                switch (escolha) {
                case 0:
                    sair = true;
                    break;
                case 1:
                    novaConcessionaria(concessionarias);
                    break;
                case 2:
                    clear();
                    std::cout << "A media de veiculos por concessionaria e de aproximadamente " << Veiculo::getQtdVeiculos()/Concessionaria::getQtdConcessionaria() << " veiculos por concessionaria!!" << std::endl;
                    std::cin.ignore();
                    pressToCont();
                    break;
                case 3:
                    clear();
                    mostrarDadosConcessionarias(concessionarias);
                    std::cin.ignore();
                    pressToCont();
                    break;
                default:
                    //selecionarConcessionaria(concessionarias[escolha - 3]);
                    break;
                }
            } else {
                error = true;
            }
        } else {
            error = true;
        }
    } while (!sair);
}

int main() {

    //Vector para armazenar todas as concessionarias e suas informacoes
    std::vector<Concessionaria> concessionarias;

    //Chamar funcao para pegar dados inicias em um arquivo
    lerDados(concessionarias);

    //Funcao que chama o menu inicial
    showMenu(concessionarias);

    //Chamar funcao para salvar os dados em um arquivo
    salvarDados(concessionarias);

    return 0;
}