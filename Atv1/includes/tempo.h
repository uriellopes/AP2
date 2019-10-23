class Tempo {
    private:
        int dia;
        int mes;
        int ano;
        int qtd_dias; //Var para armazenar a quantidade de dias passados desde 01/01/0001
    public:
        Tempo();
        Tempo(int dia, int mes, int ano);
        friend std::ostream& operator<< (std::ostream &o, Tempo const t);
        int getQtdDias();
        ~Tempo();
};