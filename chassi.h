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

Chassi::Chassi(std::string c, int t, unsigned int p) {
    chassi = c;
    tipo = t;
    posicao = p;
}

Chassi::~Chassi() {

}

std::string Chassi::getChassi() {
    return chassi;
}

int Chassi::getTipo() {
    return tipo;
}

unsigned int Chassi::getPosicao() {
    return posicao;
}