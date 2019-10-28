#include <iostream>
#include <string>

class Propriedade {
    private:
        int tipo;
        std::string fisica;
        long long int juridica;
    public:
        Propriedade();
        Propriedade(std::string f);
        Propriedade(long long int j);
        ~Propriedade();
        int getTipo();
        std::string getPessoaFisica();
        long long int getPessoaJuridica();
        friend std::ostream& operator<< (std::ostream &o, Propriedade const p);
};