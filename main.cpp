//g++ -Wall -pedantic -g -O0 -o exec main.cpp
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include "concessionaria.h"

using namespace std;

int main() {

    //Receber valores de um arquivo para criar dados iniciais
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
    }
    dados.close();

    // string S, T; 
    
    // getline(cin,S);
    
    // stringstream X(S);
    
    // while(getline(X, T, ' ')) 
    // { 
    //     cout<<T<<endl; 
    // } 

    // Carro c = Carro("asdasdsad", 1233.12, 54545, Tempo(14,2,2019), 2);

    // cout << c.getMarca() << endl;
    // cout << c.getPreco() << endl;
    // cout << c.getChassi() << endl;
    // cout << c.getData() << endl;
    // cout << c.getMotor() << endl << endl;

    // Moto m = Moto("asdasdsad", 1233.12, 54545, Tempo(14,2,2019), 1);

    // cout << m.getMarca() << endl;
    // cout << m.getPreco() << endl;
    // cout << m.getChassi() << endl;
    // cout << m.getData() << endl;
    // cout << m.getModelo() << endl << endl;

    // Caminhao cm = Caminhao("asdasdsad", 1233.12, 54545, Tempo(14,2,2019), 1);

    // cout << cm.getMarca() << endl;
    // cout << cm.getPreco() << endl;
    // cout << cm.getChassi() << endl;
    // cout << cm.getData() << endl;
    // cout << cm.getCarga() << endl;
    return 0;
}