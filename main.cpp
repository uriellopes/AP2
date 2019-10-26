//g++ -Wall -pedantic -g -O0 -o exec main.cpp
#include <iostream>
#include <sstream>
#include <fstream>
#include "concessionaria.h"

using namespace std;

int main() {

    //Vector para armazenar todas as concessionarias e suas informacoes
    vector<Concessionaria> concessionarias;

    //Abrir arquivo concessionarias.txt
    ifstream dados("concessionarias.txt");

    //Extrair informacoes do arquivo concessionarias.txt para salvar no vector concessionarias
    vector<string> values;
    string line, value;
    while(!dados.eof()) {
        getline(dados, line);
        stringstream temp(line);
        values.clear();
        while(getline(temp, value, ',')) {
            values.push_back(value);
        }
        concessionarias.push_back(Concessionaria(values[0], stoll(values[1], nullptr, 10)));
    }

    //Fechar arquivo concessionarias.txt após terminar de extrair as informacoes
    dados.close();

    cout << concessionarias[0] << endl;
    cout << concessionarias[1] << endl;
    cout << concessionarias[2] << endl;
    
    return 0;
}