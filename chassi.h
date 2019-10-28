class Chassi {
    private:
        std::string chassi;
        int tipo;
        unsigned int posicao;
    public:
        Chassi(std::string c, int t, unsigned int p);
        ~Chassi();
        std::string getChassi();
        int getTipo();
        unsigned int getPosicao();
};