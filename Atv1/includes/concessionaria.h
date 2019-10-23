#include <vector>
#include "automovel.h"

class Concessionaria {
    private:
        std::string nome;
        long long int cnpj;
        int qtd_estoque;
        std::vector<Automovel> carros;
    public:
        static int qtd_concessionaria;
        static int getQtdConcessionaria();
        Concessionaria(std::string nome, long long int cnpj);
        friend std::ostream& operator<< (std::ostream &o, Concessionaria const c);
        void adicionarCarro( Automovel c );
        void showCarros();
        std::string getNome();
        long long int getCNPJ();
        void aumentarPreco(float value);
        void listarCarrosRecentes();
        int checkSize();
        bool verificarExiste(std::string &chassi);
        ~Concessionaria();
};