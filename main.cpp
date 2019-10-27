//g++ -Wall -pedantic -g -O0 -o exec main.cpp
#include <iostream>
#include <sstream>
#include <fstream>
#include "concessionaria.h"

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

int main() {

    //Vector para armazenar todas as concessionarias e suas informacoes
    std::vector<Concessionaria> concessionarias;

    // //Chamar funcao para pegar dados inicias em um arquivo
    lerDados(concessionarias);

    std::cout << concessionarias[0] << std::endl;
    std::cout << concessionarias[1] << std::endl;
    std::cout << concessionarias[2] << std::endl;

    // //Chamar funcao para salvar os dados em um arquivo
    salvarDados(concessionarias);

    return 0;
}