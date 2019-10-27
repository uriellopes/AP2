class Chassi {
    private:
        std::string chassi;
        int tipo;
        unsigned int posicao;
    public:
        Chassi(std::string c, int t, unsigned int p);
        ~Chassi();
};

Chassi::Chassi(std::string c, int t, unsigned int p) {
    chassi = c;
    tipo = t;
    posicao = p;
}

Chassi::~Chassi() {

}