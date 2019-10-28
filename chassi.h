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

//Constructor da classe Chassi
Chassi::Chassi(std::string c, int t, unsigned int p) {
    chassi = c;
    tipo = t;
    posicao = p;
}

//Destrutor da classe Chassi
Chassi::~Chassi() {

}

//Getter do atributo chassi
std::string Chassi::getChassi() {
    return chassi;
}

//Getter do atributo Tipo
int Chassi::getTipo() {
    return tipo;
}

//Getter do atributo posicao
unsigned int Chassi::getPosicao() {
    return posicao;
}