//g++ -Wall -pedantic -g -O0 -o exec main.cpp
#include <iostream>
#include "concessionaria.h"

int main() {

    Carro c = Carro("asdasdsad", 1233.12, 54545, "14/02/2019", 2);

    std::cout << c.getMarca() << std::endl;
    std::cout << c.getPreco() << std::endl;
    std::cout << c.getChassi() << std::endl;
    std::cout << c.getData() << std::endl;
    std::cout << c.getMotor() << std::endl;

    Moto m;

    Caminhao cm;

    return 0;
}