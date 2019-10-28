#include "propriedade.h"

Propriedade::Propriedade() {

}

Propriedade::Propriedade(std::string f){
    fisica = f;
    tipo = 1;
}

Propriedade::Propriedade(long long int j) {
    juridica = j;
    tipo = 2;
}

int Propriedade::getTipo() {
    return tipo;
}

std::string Propriedade::getPessoaFisica() {
    return fisica;
}

long long int Propriedade::getPessoaJuridica() {
    return juridica;
}

Propriedade::~Propriedade() {

}

std::ostream& operator<< (std::ostream &o, Propriedade const p) {
    if ( p.tipo == 1 ) {
        o << "Pessoa Fisica: " << p.fisica;
    } else {
        o << "Pessoa Juridida: " << p.juridica;
    }
    return o;
}