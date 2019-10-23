#include <iostream>
#include <sstream>
#include "../includes/funcoes.h"

#ifdef _WIN32
#define LIMPAR "CLS"
#else
#define LIMPAR "clear"
#endif

// int Concessionaria::qtd_concessionaria = 0;
// int Automovel::qtd_carros = 0;

//Função para limpar a tela
void clear() {
    system(LIMPAR);
}

//Função para pressionar enter para continuar
void pressToCont() {
    std::cout << "Pressione Enter para continuar...";
    std::cin.ignore();
    std::cin.ignore();
}

//Função para checar se o input é um int
bool checarDigito(std::string &input) {
    for (unsigned int i = 0; i < input.size(); i++) {
        if (!isdigit(input[i])) {
            return false;
            break;
        }
    }
    return true;
}

//Função para chegar se o input é um float
bool checarFloat(std::string &input) {
    int ponto = 0;

    //Verificar se os elementos são digitos ou '.' para casa decimais
    for (unsigned int i = 0; i < input.size(); i++) {
        if (!isdigit(input[i])) {
            if (input[i] != '.') {
                return false;
            } else {
                ponto++;
            }
        }
    }

    //Se a quantidade de pontos for maior que 1 o input é invalido
    if (ponto < 2) {
        return true;
    } else {
        return false;
    }
}

//Função para checar se o ano inserido é bissexto
bool checkBissexto(int &ano) {
    return (ano % 4 == 0) && (ano % 100 != 0 || ano % 400 == 0);
}

//Função para testar se o input de data do usuário é válido
bool testeData(std::string &data) {
    int barra = 0;

    //Verificar se os elementos são digitos ou '/' para separar o dia/mes/ano
    for (unsigned int i = 0; i < data.size(); i++) {
        if (!isdigit(data[i])) {
            if (data[i] != '/') {
                return false;
            } else {
                //Caso a barra esteja ao lado de outra barra, no inicio ou no fim da string o input é inválido
                if( (data[i - 1] == '/' || i == 0 || i + 1 == data.size() ) ) { 
                    return false;
                } else {
                    barra++;
                }
            }
        }
    }

    //Caso tenham menos ou mais de 2 barras o input é inválido
    if (barra == 2) {
        return true;
    } else {
        return false;
    }

    return true;
}

//Função que remove as barras e troca por espaços
void converterData(std::string &data) {
    for (unsigned int i = 0; i < data.size(); i++) {
        if( data[i] == '/') {
            data[i] = ' ';
        }
    }
}

//Função para validar se a data inserida é válida
bool validarData(int d, int m, int a) {
    int meses[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    //Se o ano for bissexto mudar a quantidade de dias de 28 para 29 no mes de fevereiro
    if (checkBissexto(a)) {
        meses[1] = 29;
    }
    bool anoCheck = a > 0;
    bool mesCheck = m >= 1 && m <= 12;
    bool diaCheck = d >= 1 && d <= meses[m - 1];

    return anoCheck && mesCheck && diaCheck;
}

//Função para adicionar dados inciais quando o programa for executado
void addInfo(std::vector<Concessionaria> &concessionarias) {
    //Criando concessionários para ter dados iniciais
    concessionarias.push_back(Concessionaria("Concessionaria 1", 321997547555590));
    concessionarias.push_back(Concessionaria("Concessionaria 2", 479378124000401));
    concessionarias.push_back(Concessionaria("Concessionaria 3", 122312123444407));

    //Dados iniciais de carros para as concessionárias
    //Concessionaria 1
    concessionarias[0].adicionarCarro(Automovel("Toyota", 20000.00, "AAAAAAAAAAA", Tempo(2, 1, 2019)));
    concessionarias[0].adicionarCarro(Automovel("Volkswagen", 15000.00, "BBBBBBBBBB", Tempo(17, 3, 2018)));
    concessionarias[0].adicionarCarro(Automovel("Ford", 18000.50, "CCCCCCCCCC", Tempo(31, 3, 2018)));
    concessionarias[0].adicionarCarro(Automovel("Nissan", 50500.00, "DDDDDDDDDD", Tempo(28, 8, 2019)));
    concessionarias[0].adicionarCarro(Automovel("Hyundai", 78800.00, "EEEEEEEEEE", Tempo(14, 7, 2019)));
    //Concessionaria 2
    concessionarias[1].adicionarCarro(Automovel("Chevrolet", 16500.00, "FFFFFFFFFF", Tempo(1, 9, 2019)));
    concessionarias[1].adicionarCarro(Automovel("Kia", 32000.00, "GGGGGGGGGG", Tempo(17, 8, 2018)));
    concessionarias[1].adicionarCarro(Automovel("Mercedes-Benz", 45900.50, "HHHHHHHHHH", Tempo(31, 7, 2019)));
    concessionarias[1].adicionarCarro(Automovel("Renault", 69999.90, "IIIIIIIIII", Tempo(30, 6, 2019)));
    //Concessionaria 3
    concessionarias[2].adicionarCarro(Automovel("Audi", 3600.00, "JJJJJJJJJJ", Tempo(29, 8, 2019)));
    concessionarias[2].adicionarCarro(Automovel("Peugeot", 7000.00, "KKKKKKKKKK", Tempo(17, 3, 2018)));
    concessionarias[2].adicionarCarro(Automovel("BMW", 125400.50, "LLLLLLLLLL", Tempo(31, 3, 2017)));
}

//Função para criar uma nova concessionaria
void novaConcessionaria(std::vector<Concessionaria> &concessionarias) {
    clear();
    std::string nome;
    std::string input;
    long long int cnpj;
    bool existe = false;
    bool inputValido;

    std::cout << std::endl << "#######################################" << std::endl;
    std::cout << "##   1 - Criar nova concessionaria   ##" << std::endl;
    std::cout << "#######################################" << std::endl << std::endl;

    std::cout << "Digite o nome da nova concessionaria: ";
    std::cin.ignore();
    std::getline(std::cin, nome);

    //Loop para receber um valor de CNPJ correto
    do {
        inputValido = true;
        std::cout << "Digite o CNPJ da nova concessionaria ( Digite apenas os numeros ): ";
        std::cin >> input;

        inputValido = checarDigito(input);

        if (!inputValido) {
            std::cout << std::endl;
            std::cout << "Digite apenas numeros para um valor valido!!" << std::endl;
        }
    } while (!inputValido);

    cnpj = stoll(input, nullptr, 10);

    //Verificar se já existe alguma concessionária com nome ou cpnj digitado pelo usuário cadastrada
    for (unsigned int i = 0; i < concessionarias.size(); i++) {
        if (concessionarias[i].getCNPJ() == cnpj || nome.compare(concessionarias[i].getNome()) == 0) {
            existe = true;
            break;
        }
    }

    if (existe) {
        std::cout << std::endl;
        std::cout << "==============================================================" << std::endl;
        std::cout << "Ja existe uma concessionaria cadastrada com esse nome ou cnpj!" << std::endl;
        std::cout << "==============================================================" << std::endl << std::endl;
    } else {
        concessionarias.push_back(Concessionaria(nome, cnpj));
        std::cout << std::endl;
        std::cout << "Concessionaria " << nome << " criada!" << std::endl;
        std::cout << std::endl;
    }

    pressToCont();
}

//Funcao que pega as informacoes do carro caso o carro nao esteja cadastrado ou a concessionaria esteja vazia
void cadastrarCarro(Concessionaria &c, std::string &chassi) {
    std::string marca, preco, data;
    bool error = false, dataValida = true;
    int dia, mes, ano;

    std::cout << "Digite a marca do carro: ";
    std::cin >> marca;

    //Loop para pegar um input de preço no formato correto
    do {
        if (error) {
            std::cout << std::endl << "Digite apenas numeros com um '.' separando os centavos !!" << std::endl;
        }
        std::cout << "Digite o preco do carro (xxxxxx.xx): ";
        std::cin >> preco;
        error = !checarFloat(preco);
    } while (error);

    //Loop para pegar um valor de data no formato correto e válida
    do {
        if (!dataValida) {
            std::cout << std::endl << "Digite um valor de data valido!!" << std::endl;
        }

        std::cout << "Digite a data de fabricacao do carro (dd/mm/aaaa): ";
        std::cin >> data;

        if( testeData(data) ) {
            converterData(data);
            std::istringstream(data) >> dia >> mes >> ano;        
            dataValida = validarData(dia, mes, ano);
        } else {
            dataValida = false;
        }

    } while (!dataValida);

    c.adicionarCarro(Automovel(marca, std::stof(preco), chassi, Tempo(dia, mes, ano)));
    std::cout << "Carro cadastrado com sucesso!!!" << std::endl;
}

//Função para adicionar um novo carro na concessionária
void adicionarNovoCarro(Concessionaria &c) {
    std::string chassi;

    clear();

    std::cout << "##################################" << std::endl;
    std::cout << "##   1 - Adicionar novo carro   ##" << std::endl;
    std::cout << "##################################" << std::endl << std::endl;

    std::cout << "Digite o chassi do carro: ";
    std::cin >> chassi;

    //Verificar se já existe algum carro com o chassi fornecido pelo usuário
    if (c.checkSize() > 0) {
        if (c.verificarExiste(chassi)) {
            std::cout << "Já existe um carro cadastrado com esse chassi!!" << std::endl;
        }
        else {
            cadastrarCarro(c, chassi);
        }
    } else {
        cadastrarCarro(c, chassi);
    }

    pressToCont();
}

//Função que mostra o menu e recebe o valor para aumentar o preço dos carros de uma concessionaria
void menuAumentarPreco(Concessionaria &c) {
    bool inputValido;
    float valor;
    std::string input;

    clear();
    std::cout << "####################################################" << std::endl;
    std::cout << "##   3 - Aumentar preco de todos os carros em %   ##" << std::endl;
    std::cout << "####################################################" << std::endl << std::endl;

    //Loop para pegar um valor no formato correto
    do {
        inputValido = true;
        std::cout << "Digite o valor da % desejado ( xx.x ): ";
        std::cin >> input;

        inputValido = checarFloat(input);

        if (!inputValido) {
            std::cout << std::endl;
            std::cout << "Digite apenas os numeros e com apenas um '.' para separar o decimal!!" << std::endl;
        }
    } while (!inputValido);

    valor = std::stof(input);

    c.aumentarPreco(valor);

    std::cout << "Preco de todos os carros aumentado em: " << valor << "%" << std::endl;

    pressToCont();
}

//Função para selecionar uma concessionaria
void selecionarConcessionaria(Concessionaria &c) {
    std::string input;
    int escolha;
    bool sair = false;
    bool error = false;

    //Loop para verificar se o input é uma opção válida e caso seja, chamar a função referente a opção escolhida
    do {
        clear();
        std::cout << std::endl << "###################################" << std::endl;
        std::cout << c;
        std::cout << "###################################" << std::endl << std::endl;

        std::cout << "Escolha uma das seguintes opcoes: " << std::endl << std::endl;

        std::cout << "[1] - Adicionar novo carro" << std::endl;
        std::cout << "[2] - Listar carros cadastrados" << std::endl;
        std::cout << "[3] - Aumentar preco de todos os carros em %" << std::endl;
        std::cout << "[4] - Listar carros produzidos ha menos de 90 dias" << std::endl;
        std::cout << std::endl;
        std::cout << "[0] - Sair" << std::endl;

        std::cout << std::endl;
        if (error) {
            error = false;
            std::cout << "**Digite uma opcao valida!**" << std::endl;
        }
        std::cout << "Opcao: ";
        std::cin >> input;
        
        if (checarDigito(input)) {
            escolha = std::stoi(input, nullptr);

            switch (escolha) {
            case 0:
                sair = true;
                break;
            case 1:
                adicionarNovoCarro(c);
                break;
            case 2:
                clear();
                c.showCarros();
                pressToCont();
                break;
            case 3:
                menuAumentarPreco(c);
                break;
            case 4:
                clear();
                c.listarCarrosRecentes();
                pressToCont();
                break;
            default:
                error = true;
                break;
            }
        } else {
            error = true;
        }
    } while (!sair);
}

//Função que mostra o menu principal do código
void showMenu(std::vector<Concessionaria> &concessionarias) {
    std::string input;
    int escolha;
    bool sair = false;
    bool error = false;

    //Loop para verificar se o input é uma opção válida e caso seja, realizer a operação referente a escolha
    do {
        clear();
        std::cout << std::endl << "############################################################" << std::endl;
        std::cout << "###                      BEM VINDO!!                     ###" << std::endl;
        std::cout << "############################################################" << std::endl;
        std::cout << std::endl << "Escolha uma das seguintes opcoes: " << std::endl << std::endl;
        std::cout << "[1] - Criar nova Concessionaria" << std::endl;
        std::cout << "[2] - Listar media de carros por concessionaria" << std::endl;
        int opcoes = 2;
        for (unsigned int i = 0; i < concessionarias.size(); i++) {
            std::cout << "[" << i + 3 << "] - Selecionar Concessionaria " << concessionarias[i].getNome() << std::endl;
            opcoes++;
        }

        std::cout << std::endl;
        std::cout << "[0] - Sair" << std::endl << std::endl;

        if (error) {
            error = false;
            std::cout << "**Digite uma opcao valida!**" << std::endl;
        }
        std::cout << "Opcao: ";
        std::cin >> input;

        if (checarDigito(input)) {
            escolha = std::stoi(input, nullptr);

            if (escolha >= 0 && escolha <= opcoes) {
                switch (escolha) {
                case 0:
                    sair = true;
                    break;
                case 1:
                    novaConcessionaria(concessionarias);
                    break;
                case 2:
                    clear();
                    std::cout << "A media de carros por concessionaria e de aproximadamente " << Automovel::getQtdCarros()/Concessionaria::getQtdConcessionaria() << " carros por concessionaria!!" << std::endl;
                    pressToCont();
                    break;
                default:
                    selecionarConcessionaria(concessionarias[escolha - 3]);
                    break;
                }
            } else {
                error = true;
            }
        } else {
            error = true;
        }
    } while (!sair);
}