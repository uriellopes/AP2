//g++ -Wall -pedantic -g -O0 -o exec main.cpp
#include <iostream>
#include <sstream>
#include <fstream>
#include "concessionaria.h"

using namespace std;

//Funcao para ler dados iniciais em um arquivo
void lerDados(vector<Concessionaria> &concessionarias) {
    
    //Abrir arquivo concessionarias.txt em modo de leitura
    ifstream dadosConcessionaria("concessionarias.txt");

    //Extrair informacoes do arquivo concessionarias.txt para salvar no vector concessionarias
    vector<string> values;
    string line, value;
    while(!dadosConcessionaria.eof()) {
        getline(dadosConcessionaria, line);
        if ( !line.empty() ) {
            stringstream temp(line);
            values.clear();
            while(getline(temp, value, ',')) {
                values.push_back(value);
            }
            concessionarias.push_back(Concessionaria(values[0], stoll(values[1], nullptr, 10)));
        }
    }

    //Fechar arquivo concessionarias.txt após terminar de extrair as informacoes
    dadosConcessionaria.close();
}

void salvarDados(vector<Concessionaria> &concessionarias) {

    //Abrir arquivo concessionarias.txt em modo de escrita
    ofstream dadosConcessionaria("concessionarias.txt");

    //Salvar dados do vetor concessionaria dentro do arquivo concessionarias.txt
    for (auto i = concessionarias.begin(); i != concessionarias.end(); i++) {
        dadosConcessionaria << i->getNome() << "," << i->getCNPJ() << endl;        
    }

    //Fechar arquivo após salvar os dados
    dadosConcessionaria.close();
}

int main() {

    //Vector para armazenar todas as concessionarias e suas informacoes
    vector<Concessionaria> concessionarias;

    //Chamar funcao para pegar dados inicias em um arquivo
    lerDados(concessionarias);

    //Chamar funcao para salvar os dados em um arquivo
    salvarDados(concessionarias);

    return 0;
}