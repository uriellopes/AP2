//g++ -Wall -pedantic -g -O0 -o exec main.cpp
#include <iostream>
#include <sstream>
#include <fstream>
#include "concessionaria.h"

//Verifica o tipo de SO para definir o tipo da variavel para limpar o terminal
#ifdef _WIN32
#define LIMPAR "CLS"
#else
#define LIMPAR "clear"
#endif

//Atributos estaticos para armazenar a quantidade de concessionarias e veiculos cadastrados
int Concessionaria::qtd_concessionarias = 0;
int Veiculo::qtd_veiculos = 0;

//Função para pressionar enter para continuar
void clear() {
    system(LIMPAR);
}

//Função para pressionar enter para continuar
void pressToCont() {
    std::cout << "Pressione Enter para continuar...";
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

//Função para checar se o ano inserido é bissexto
bool checkBissexto(int &ano) {
    return (ano % 4 == 0) && (ano % 100 != 0 || ano % 400 == 0);
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

//Funcao para ler dados iniciais em um arquivo
void lerDados(std::vector<Concessionaria> &concessionarias) {
    
    //Abrir arquivo concessionarias.txt em modo de leitura
    std::ifstream dadosConcessionaria("concessionarias.txt");

    //Extrair informacoes do arquivo concessionarias.txt para salvar no vector concessionarias
    std::vector<std::string> values;
    std::string line, value;
    while(!dadosConcessionaria.eof()) {
        getline(dadosConcessionaria, line);
        if ( !line.empty() ) {
            std::stringstream temp(line);
            values.clear();
            while(getline(temp, value, ',')) {
                values.push_back(value);
            }
            if ( stoi(values[2]) == 1 ) {
                concessionarias.push_back(Concessionaria(values[0], stoll(values[1], nullptr, 10), values[3]));
            } else {
                concessionarias.push_back(Concessionaria(values[0], stoll(values[1], nullptr, 10), stoll(values[3], nullptr, 10)));
            }
        }
    }

    //Fechar arquivo concessionarias.txt após terminar de extrair as informacoes
    dadosConcessionaria.close();

    //Abrir arquivo veiculos.txt em modo leitura
    std::ifstream dadosVeiculos("veiculos.txt");

    //Extrair informacoes do arquivo veiculos.txt para salvar no vector concessionarias
    while(!dadosVeiculos.eof()) {
        getline(dadosVeiculos, line);
        if ( !line.empty() ) {
            std::stringstream temp(line);
            values.clear();
            while(getline(temp, value, ',')) {
                values.push_back(value);
            }
            switch (stoi(values[0])) {
            case 1:
                concessionarias[stoi(values[1])].novoCarro(Carro(values[2], stof(values[3]), values[4], Tempo(stoi(values[5]), stoi(values[6]),stoi(values[7])), stoi(values[8])));
                break;
            case 2:
                concessionarias[stoi(values[1])].novoMoto(Moto(values[2], stof(values[3]), values[4], Tempo(stoi(values[5]), stoi(values[6]),stoi(values[7])), stoi(values[8])));
                break;
            case 3:
                concessionarias[stoi(values[1])].novoCaminhao(Caminhao(values[2], stof(values[3]), values[4], Tempo(stoi(values[5]), stoi(values[6]),stoi(values[7])), stoi(values[8])));
                break;
            }
        }
    }

    //Fechar arquivo veiculos.txt após terminar de extrair as informacoes
    dadosVeiculos.close();
}

//Funcao para salvar os dados em um arquivo
void salvarDados(std::vector<Concessionaria> &concessionarias) {

    //Abrir arquivos concessionarias.txt e veiculos.txt em modo de escrita
    std::ofstream dadosConcessionaria("concessionarias.txt");
    std::ofstream dadosVeiculos("veiculos.txt");

    //Salva os dados da concessionaria no arquivo concessionarias.txt e os dados dos veiculos em veiculos.txt
    for (unsigned i = 0; i < concessionarias.size(); i++) {
        dadosConcessionaria << concessionarias[i].getNome() << "," << concessionarias[i].getCNPJ() << "," << concessionarias[i].getPropriedade().getTipo() << ",";
        if(concessionarias[i].getPropriedade().getTipo() == 1) {
            dadosConcessionaria << concessionarias[i].getPropriedade().getPessoaFisica() << std::endl;
        } else {
            dadosConcessionaria << concessionarias[i].getPropriedade().getPessoaJuridica() << std::endl;
        }

        std::vector<Carro> carros = concessionarias[i].getCarros();
        for (auto j = carros.begin(); j != carros.end(); j++) {
            dadosVeiculos << "1," << i << "," << j->getMarca() << "," << j->getPreco() << "," << j->getChassi() << "," << j->getDia() << "," << j->getTipo() << std::endl;
        }

        std::vector<Moto> motos = concessionarias[i].getMotos();
        for (auto j = motos.begin(); j != motos.end(); j++) {
            dadosVeiculos << "2," << i << "," << j->getMarca() << "," << j->getPreco() << "," << j->getChassi() << "," << j->getDia() << "," << j->getTipo() << std::endl;
        }

        std::vector<Caminhao> caminhoes = concessionarias[i].getCaminhoes();
        for (auto j = caminhoes.begin(); j != caminhoes.end(); j++) {
            dadosVeiculos << "3," << i << "," << j->getMarca() << "," << j->getPreco() << "," << j->getChassi() << "," << j->getDia() << "," << j->getTipo() << std::endl;
        }
    }

    //Fecha os arquivos concessionarias.txt e veiculos.txt após inserir os dados
    dadosConcessionaria.close();
    dadosVeiculos.close();
}

//Função para criar uma nova concessionaria
void novaConcessionaria(std::vector<Concessionaria> &concessionarias) {
    clear();
    long long int num_proprietario;
    int tipo_proprietario;
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

    //Caso valido salvar o valor do CNPJ
    cnpj = stoll(input, nullptr, 10);

    //Verificar se já existe alguma concessionária com nome ou cpnj digitado pelo usuário cadastrada
    for (unsigned int i = 0; i < concessionarias.size(); i++) {
        if (concessionarias[i].getCNPJ() == cnpj || nome.compare(concessionarias[i].getNome()) == 0) {
            existe = true;
            break;
        }
    }

    //Se existir alertar usuario, caso nao, continuar o cadastro
    if (existe) {
        std::cout << std::endl;
        std::cout << "==============================================================" << std::endl;
        std::cout << "Ja existe uma concessionaria cadastrada com esse nome ou cnpj!" << std::endl;
        std::cout << "==============================================================" << std::endl << std::endl;
    } else {

        std::cout << "Escolha o tipo de proprietario" << std::endl;
        std::cout << "1 - Pessoa Fisica" << std::endl;
        std::cout << "2 - Pessoa Juridica" << std::endl;

        //Loop que verifica se foi digitado um valor correto
        do {
            std::cin >> input;

            inputValido = checarDigito(input);

            if( inputValido ) {
                tipo_proprietario = stoi(input);
                if ( tipo_proprietario > 0 && tipo_proprietario < 3) {
                    inputValido = true;
                } else {
                    inputValido = false;
                }
            }

            if (!inputValido) {
                std::cout << "Digite um valor valido!!" << std::endl;
            }
        } while (!inputValido);

        //Caso válido realizer a açao correspondente
        switch (tipo_proprietario) {
            case 1:
                std::cout << "Digite o nome e o sobrenome do proprietario: " << std::endl;
                std::cin.ignore();
                std::getline(std::cin, input);
                concessionarias.push_back(Concessionaria(nome, cnpj, input));
                std::cout << std::endl;
                std::cout << "Concessionaria " << nome << " criada!" << std::endl;
                break;
            case 2:
                std::cout << "Digite o numero do proprietario: " << std::endl;
                do {
                    std::cin >> input;
                    inputValido = checarDigito(input);
                    if (inputValido) {
                        num_proprietario = stoll(input, nullptr, 10);
                    }
                } while(!inputValido);

                concessionarias.push_back(Concessionaria(nome, cnpj, num_proprietario));
                std::cout << std::endl;
                std::cout << "Concessionaria " << nome << " criada!" << std::endl;
                std::cin.ignore();
                break;
        }
    }
    pressToCont();
}

//Funcao que mostrar os dados das concessionarias ( Proprietario, quantidade de cada veiculo e o valor total dos veiculos)
void mostrarDadosConcessionarias(std::vector<Concessionaria> &concessionarias) {
    for (unsigned i = 0; i < concessionarias.size(); i++) {
        std::cout << "Concessionária " << i + 1 << std::endl;
        concessionarias[i].showDados();
        std::cout << std::endl;
    }
}

//Funcao que pega as informacoes do carro caso o carro nao esteja cadastrado ou a concessionaria esteja vazia
void cadastrarCarro(Concessionaria &c, std::string &chassi) {
    std::string marca, preco, data, input;
    bool error = false, dataValida = true, inputValido = false;
    int dia, mes, ano, motor;

    std::cout << "Digite a marca do carro: ";
    std::cin.ignore();
    std::getline(std::cin, marca);

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

    std::cout << "Escolha o tipo de motor do carro" << std::endl;
    std::cout << "1 - Gasolina" << std::endl;
    std::cout << "2 - Eletrico" << std::endl;

    do {
        std::cin >> input;

        inputValido = checarDigito(input);

        if( inputValido ) {
            motor = stoi(input);
            if ( motor > 0 && motor < 3) {
                inputValido = true;
            } else {
                inputValido = false;
            }
        }

        if (!inputValido) {
            std::cout << "Digite um valor valido!!" << std::endl;
        }
    } while (!inputValido);

    c.novoCarro(Carro(marca, std::stof(preco), chassi, Tempo(dia, mes, ano), motor));
    std::cout << "Carro cadastrado com sucesso!!!" << std::endl;
}

//Função para adicionar um novo carro na concessionária
void adicionarNovoCarro(Concessionaria &c) {
    std::string chassi;

    std::cout << "##################################" << std::endl;
    std::cout << "##   1 - Adicionar novo carro   ##" << std::endl;
    std::cout << "##################################" << std::endl << std::endl;

    std::cout << "Digite o chassi do carro: ";
    std::cin >> chassi;

    //Verificar se já existe algum veiculo com o chassi fornecido pelo usuário
    if (c.checkSize() > 0) {
        if (c.verificarExiste(chassi)) {
            std::cout << "Já existe um veiculo cadastrado com esse chassi!!" << std::endl;
        }
        else {
            cadastrarCarro(c, chassi);
        }
    } else {
        cadastrarCarro(c, chassi);
    }

    std::cin.ignore();
    pressToCont();
}

//Funcao que pega as informacoes do carro caso o carro nao esteja cadastrado ou a concessionaria esteja vazia
void cadastrarMoto(Concessionaria &c, std::string &chassi) {
    std::string marca, preco, data, input;
    bool error = false, dataValida = true, inputValido = false;
    int dia, mes, ano, modelo;

    std::cout << "Digite a marca da moto: ";
    std::cin.ignore();
    std::getline(std::cin, marca);

    //Loop para pegar um input de preço no formato correto
    do {
        if (error) {
            std::cout << std::endl << "Digite apenas numeros com um '.' separando os centavos !!" << std::endl;
        }
        std::cout << "Digite o preco da moto (xxxxxx.xx): ";
        std::cin >> preco;
        error = !checarFloat(preco);
    } while (error);

    //Loop para pegar um valor de data no formato correto e válida
    do {
        if (!dataValida) {
            std::cout << std::endl << "Digite um valor de data valido!!" << std::endl;
        }

        std::cout << "Digite a data de fabricacao da moto (dd/mm/aaaa): ";
        std::cin >> data;

        if( testeData(data) ) {
            converterData(data);
            std::istringstream(data) >> dia >> mes >> ano;        
            dataValida = validarData(dia, mes, ano);
        } else {
            dataValida = false;
        }

    } while (!dataValida);

    std::cout << "Escolha o tipo de modelo da moto" << std::endl;
    std::cout << "1 - Classico" << std::endl;
    std::cout << "2 - Esportivo" << std::endl;

    do {
        std::cin >> input;

        inputValido = checarDigito(input);

        if( inputValido ) {
            modelo = stoi(input);
            if ( modelo > 0 && modelo < 3) {
                inputValido = true;
            } else {
                inputValido = false;
            }
        }

        if (!inputValido) {
            std::cout << "Digite um valor valido!!" << std::endl;
        }
    } while (!inputValido);

    c.novoMoto(Moto(marca, std::stof(preco), chassi, Tempo(dia, mes, ano), modelo));
    std::cout << "Moto cadastrada com sucesso!!!" << std::endl;
}

//Função para adicionar um nova moto na concessionária
void adicionarNovaMoto(Concessionaria &c) {
    std::string chassi;

    std::cout << "##################################" << std::endl;
    std::cout << "##   2 - Adicionar nova moto   ##" << std::endl;
    std::cout << "##################################" << std::endl << std::endl;

    std::cout << "Digite o chassi da moto: ";
    std::cin >> chassi;

    //Verificar se já existe algum veiculo com o chassi fornecido pelo usuário
    if (c.checkSize() > 0) {
        if (c.verificarExiste(chassi)) {
            std::cout << "Já existe um veiculo cadastrado com esse chassi!!" << std::endl;
        }
        else {
            cadastrarMoto(c, chassi);
        }
    } else {
        cadastrarMoto(c, chassi);
    }

    std::cin.ignore();
    pressToCont();
}

//Funcao que pega as informacoes do carro caso o carro nao esteja cadastrado ou a concessionaria esteja vazia
void cadastrarCaminhao(Concessionaria &c, std::string &chassi) {
    std::string marca, preco, data, input;
    bool error = false, dataValida = true, inputValido = false;
    int dia, mes, ano, carga;

    std::cout << "Digite a marca do caminhao: ";
    std::cin.ignore();
    std::getline(std::cin, marca);

    //Loop para pegar um input de preço no formato correto
    do {
        if (error) {
            std::cout << std::endl << "Digite apenas numeros com um '.' separando os centavos !!" << std::endl;
        }
        std::cout << "Digite o preco do caminhao (xxxxxx.xx): ";
        std::cin >> preco;
        error = !checarFloat(preco);
    } while (error);

    //Loop para pegar um valor de data no formato correto e válida
    do {
        if (!dataValida) {
            std::cout << std::endl << "Digite um valor de data valido!!" << std::endl;
        }

        std::cout << "Digite a data de fabricacao do caminhao (dd/mm/aaaa): ";
        std::cin >> data;

        if( testeData(data) ) {
            converterData(data);
            std::istringstream(data) >> dia >> mes >> ano;        
            dataValida = validarData(dia, mes, ano);
        } else {
            dataValida = false;
        }

    } while (!dataValida);

    std::cout << "Escolha o tipo de carga do caminhao" << std::endl;
    std::cout << "1 - Comum" << std::endl;
    std::cout << "2 - Perigosa" << std::endl;

    do {
        std::cin >> input;

        inputValido = checarDigito(input);

        if( inputValido ) {
            carga = stoi(input);
            if ( carga > 0 && carga < 3) {
                inputValido = true;
            } else {
                inputValido = false;
            }
        }

        if (!inputValido) {
            std::cout << "Digite um valor valido!!" << std::endl;
        }
    } while (!inputValido);

    c.novoCaminhao(Caminhao(marca, std::stof(preco), chassi, Tempo(dia, mes, ano), carga));
    std::cout << "Caminhao cadastrado com sucesso!!!" << std::endl;
}

//Função para adicionar um novo carro na concessionária
void adicionarNovoCaminhao(Concessionaria &c) {
    std::string chassi;

    std::cout << "#####################################" << std::endl;
    std::cout << "##   3 - Adicionar novo caminhao   ##" << std::endl;
    std::cout << "#####################################" << std::endl << std::endl;

    std::cout << "Digite o chassi do caminhao: ";
    std::cin >> chassi;

    //Verificar se já existe algum veiculo com o chassi fornecido pelo usuário
    if (c.checkSize() > 0) {
        if (c.verificarExiste(chassi)) {
            std::cout << "Já existe um veiculo cadastrado com esse chassi!!" << std::endl;
        }
        else {
            cadastrarCaminhao(c, chassi);
        }
    } else {
        cadastrarCaminhao(c, chassi);
    }

    std::cin.ignore();
    pressToCont();
}

void buscarPorChassi(Concessionaria &c) {
    std::string input;

    std::cout << "Digite o chassi do veiculo: ";
    std::cin.ignore();
    std::getline(std::cin, input);

    if (c.checkSize() > 0) {
        c.buscarPorChassi(input);
    } else {
        std::cout << "Nao existe nenhum veiculo cadastrado com esse chassi na concessionaria!!" << std::endl;
    }

    std::cout << std::endl;
    pressToCont();
}

//Função que mostra o menu e recebe o valor para aumentar o preço dos carros de uma concessionaria
void menuAumentarPreco(Concessionaria &c) {
    bool inputValido;
    float valor;
    std::string input;

    std::cout << "######################################################" << std::endl;
    std::cout << "##   6 - Aumentar preco de todos os veiculos em %   ##" << std::endl;
    std::cout << "######################################################" << std::endl << std::endl;

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

    std::cin.ignore();
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
        std::cout << c << std::endl;
        std::cout << "###################################" << std::endl << std::endl;

        std::cout << "Escolha uma das seguintes opcoes: " << std::endl << std::endl;

        std::cout << "[1] - Adicionar novo carro" << std::endl;
        std::cout << "[2] - Adicionar nova moto" << std::endl;
        std::cout << "[3] - Adicionar novo caminhao" << std::endl;
        std::cout << "[4] - Buscar por chassi" << std::endl;
        std::cout << "[5] - Listar veiculos cadastrados" << std::endl;
        std::cout << "[6] - Aumentar preco de todos os veiculos em %" << std::endl;
        std::cout << "[7] - Listar veiculos produzidos ha menos de 90 dias" << std::endl;
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
                clear();
                adicionarNovoCarro(c);
                break;
            case 2:
                clear();
                adicionarNovaMoto(c);
                break;
            case 3:
                clear();
                adicionarNovoCaminhao(c);
                break;
            case 4:
                clear();
                buscarPorChassi(c);
                break;
            case 5:
                // clear();
                // c.showCarros();
                // pressToCont();
                break;
            case 6:
                clear();
                menuAumentarPreco(c);
                break;
            case 7:
                // clear();
                // c.listarCarrosRecentes();
                // pressToCont();
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
        std::cout << "[3] - Listar dados das concessionarias" << std::endl;
        int opcoes = 3;
        for (unsigned int i = 0; i < concessionarias.size(); i++) {
            std::cout << "[" << i + 4 << "] - Selecionar Concessionaria " << concessionarias[i].getNome() << std::endl;
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
                    std::cout << "A media de veiculos por concessionaria e de aproximadamente " << Veiculo::getQtdVeiculos()/Concessionaria::getQtdConcessionaria() << " veiculos por concessionaria!!" << std::endl;
                    std::cin.ignore();
                    pressToCont();
                    break;
                case 3:
                    clear();
                    mostrarDadosConcessionarias(concessionarias);
                    std::cin.ignore();
                    pressToCont();
                    break;
                default:
                    selecionarConcessionaria(concessionarias[escolha - 4]);
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

int main() {

    //Vector para armazenar todas as concessionarias e suas informacoes
    std::vector<Concessionaria> concessionarias;

    //Chamar funcao para pegar dados inicias em um arquivo
    lerDados(concessionarias);

    //Funcao que chama o menu inicial
    showMenu(concessionarias);

    //Chamar funcao para salvar os dados em um arquivo
    salvarDados(concessionarias);

    return 0;
}