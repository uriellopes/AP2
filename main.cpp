//g++ -Wall -pedantic -g -O0 -o exec main.cpp
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include "concessionaria.h"

using namespace std;

int main() {
    vector<Carro> carros;

    //Receber valores de um arquivo para dos iniciais e salvar em um vetor
    vector<string> values;
    string line, texto;
    ifstream dados("dados.txt"); 
    while(!dados.eof()) {
        getline(dados, line);
        stringstream temp(line);
        values.clear();
        while(getline(temp, texto, ',')) {
            values.push_back(texto);
        }
        carros.push_back(Carro(values[0], stof(values[1]), stoi(values[2]), Tempo(stoi(values[3]), stoi(values[4]), stoi(values[5])), stoi(values[6])));
    }
    dados.close();

    cout << carros[0] << endl;
    cout << carros[1] << endl;
    
    return 0;
}