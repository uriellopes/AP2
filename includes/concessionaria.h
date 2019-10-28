#include "veiculo.h"
#include "propriedade.h"
#include "chassi.h"
#include <vector>
#include <iomanip>

class Concessionaria {
    private:
        std::string nome;
        long long int cnpj;
        int qtd_estoque;
        std::vector<Carro> carros;
        std::vector<Moto> motos;
        std::vector<Caminhao> caminhoes;
        Propriedade proprietario;
        int qtd_carros;
        int qtd_motos;
        int qtd_caminhoes;
        float preco_total;
        std::vector<Chassi> chassis;
    public:
        static int qtd_concessionarias;
        static int getQtdConcessionaria();
        Concessionaria(std::string n, long long int c, std::string p);
        Concessionaria(std::string n, long long int c, long long p);
        ~Concessionaria();
        std::string getNome();
        long long int getCNPJ();
        void novoCarro(Carro c);
        void novoMoto(Moto m);
        void novoCaminhao(Caminhao c);
        std::vector<Carro> getCarros();
        std::vector<Moto> getMotos();
        std::vector<Caminhao> getCaminhoes();
        Propriedade getPropriedade();
        void showDados();
        int checkSize();
        bool verificarExiste(std::string &chassi);
        void buscarPorChassi(std::string c);
        void aumentarPreco(float value);
        void showVeiculos();
        void listarVeiculosRecentes();
        friend std::ostream& operator<< (std::ostream &o, Concessionaria const c);
};