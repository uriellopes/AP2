# 2019.2 - Avaliação Prática 1
Professor:  Renan Cipriano Moioli  
Turma:  IMD0030 - Linguagem de Programação I - T02

Dupla:  Uriel Lira Lopes - 2016045704  
        Mariano José da Silva Filho - 20150146803

## Notas de atualização
1. Concessionárias agora armazenam 3 tipos de veiculos( Carro, Moto e Caminhao), cada 1 com um atributo relativo a eles **( Questão A da AP2 )**;
2. Agora ao ser finalizado o programa escreve as informações em arquivos **( Questão B da AP2 )**;
3. Agora ao ser inicializado o programa lê arquivos para cadastrar as concessionarias iniciais **( Questão C da AP2 )**;
4. Agora as concessionarias tem um atributo relativo ao dono, que pode ser tanto pessoa física como jurídica **( Questão D da AP2 )**;
5. Agora as concessionarias tem um atributo que armazena os chassis dos veiculos cadastrados para fazer uma busca por chassi **( Questão E da AP2 )**;
6. No menu incial agora tem uma opção para mostrar as informações( nome, dono, quantidade de cada tipo de veiculo e o valor total dos veiculos ) de todas as concessionárias **( Questão F da AP2 )**;
7. O programa agora utiliza de uma classe abstrata **Veiculo** para criar uma funcao que retorna o tipo deo veiculo cadastrado, no caso, para carros retorna o tipo de motor, para motos o modelo, e para caminhoes o tipo de carga **( Questão G da AP2 )**.

## Instruções
1. Para compilar o programa basta digitar make no terminal;
2. Para rodar o programa basta digitar make run no terminal;
3. Para remover os arquivos .o e o executavel basta digitar make clean no terminal.

## Funcionalidades

1. Ao ser inicializado o programa irá abrir o arquivo **concessionarias.txt** em modo leitura e irá cadastrar as concessionárias nele e  depois irá fecha-lo. Após isso, ele irá abrir o arquivo **veiculos.txt** em modo de leitura e cadastrar todos os veiculos contido nele nas respectivas concessionárias **( Questão C da AP2 )**.

2. Após a leitura dos arquivos será mostrado o menu inicial com as seguintes opções:
    - Criar uma nova concessionária **( atualizado da AP1 para a Questão A da AP2 )**;
    - Listar a média de carros por concessionária ( Questão H da AP1 );
    - Listar os dados das concessionarias **( Questão F da AP2 )**;
    - Selecionar alguma das concessionárias cadastradas.
    **OBS:** O programa irá verificar o input do usuário é um digito e se é uma das opções, caso seja falso aparecerá uma mensagem de erro.
    - Sair;

    1. Ao selecionar "Criar nova concessionária"
    Ao selecionar criar nova concessionária aparece mensagens de texto pedindo as informações necessária para cadastrar-la, como nome, cnpj, se o proprietario é pessoa fisica ou juridica, e o nome do dono, caso fisico, ou numero, caso juridico **( atualizado da AP1 para Questão D da AP2 )**.  
    **OBS:** Caso ja exista uma concessionária de mesmo nome ou de msm CNPJ aparecerá uma mensagem de erro e retornará ao menu inicial.  
    **OBS2:** O CNPJ só aceita valores inteiros, caso outro tipo de valor seja digitado aparecerá uma mensagem de error.

    2. Ao selecionar "Listar a média de carros por concessionária" aparecerá uma mensagem mostrando o valor da média e retornará ao menu inicial.

    3. Ao selecionar "Listar dados das concessionárias" aparecerá as informações( nome, proprietario e o tipo, quantidade de carros, motos e caminhoes, e o preco aproximado de todos os veiculos) de todas as concessionárias.

    4. Ao seleciar alguma das concessionárias cadastradas aparecerá as informações dessa concessionária e um menu referente a ela com as seguintes opções:
        - Adicionar novo carro **( atualizado para a Questão A da AP2 )**;
        - Adicionar nova moto **( criado para a Questão A da AP2 )**;
        - Adicionar novo caminhao **( criado para a Questão A da AP2 )**;
        - Buscar por chassi **( Questao E da AP2 )**;
        - Listar veiculos cadastrados ( Questão E da AP1 );
        - Aumentar o preço de todos os veiculos em % ( Questão F da AP1 );
        - Listar veiculos produzidos há menos de 90 dias (Questão G da AP1 );
        - Sair.

        1. Ao selecionar "Adicionar novo carro" aparecerá mensagens de texto pedindo as informações necessária para adicionar o carro;  
        **OBS:** Caso já exista um veiculo de mesmo chassi cadastrado, aparecerá uma mensagem de erro e retornará para o menu da concessionária.  
        **OBS2:** O preço do carro so aceita valores inteiros ou float, seperando as casas decimais por um ponto("."), caso outro valor seja digitado aparecerá uma mensagem de erro.  
        **OBS3:** A data de fabricação devera ser uma data válida e separando dia, mês e ano por uma barra("/"), do tipo dd/mm/aaaa, caso outro valor seja digitado aparecerá uma mensagem de erro.

        2. Ao selecionar "Adicionar nova moto" aparecerá mensagens de texto pedindo as informações necessária para adicionar a moto;  
        **OBS:** Caso já exista um veiculo de mesmo chassi cadastrado, aparecerá uma mensagem de erro e retornará para o menu da concessionária.  
        **OBS2:** O preço do carro so aceita valores inteiros ou float, seperando as casas decimais por um ponto("."), caso outro valor seja digitado aparecerá uma mensagem de erro.  
        **OBS3:** A data de fabricação devera ser uma data válida e separando dia, mês e ano por uma barra("/"), do tipo dd/mm/aaaa, caso outro valor seja digitado aparecerá uma mensagem de erro.

        3. Ao selecionar "Adicionar novo caminhao" aparecerá mensagens de texto pedindo as informações necessária para adicionar o caminhao.
        **OBS:** Caso já exista um veiculo de mesmo chassi cadastrado, aparecerá uma mensagem de erro e retornará para o menu da concessionária.  
        **OBS2:** O preço do carro so aceita valores inteiros ou float, seperando as casas decimais por um ponto("."), caso outro valor seja digitado aparecerá uma mensagem de erro.  
        **OBS3:** A data de fabricação devera ser uma data válida e separando dia, mês e ano por uma barra("/"), do tipo dd/mm/aaaa, caso outro valor seja digitado aparecerá uma mensagem de erro.

        4. Ao selecionar "Busca por chassi" será pedido para digitar o chassi do veiculo para verificar se ele existe na concessionaria. Caso exista aparecerá todas as informações do respectivo veiculo, caso não aparecerá uma mensagem alertando o usuário que não foi encontrado.

        5. Ao selecionar "Listar veiculos cadastrados" aparecerá uma tabela com todos os veiculos cadastrados na concessionária.

        6. Ao selecionar "Aumentar o preço de todos os veiculos em %" aparecera uma mensagem pedindo o valor a ser aumentado.  
        **OBS:** O valor deverá ser um inteiro ou um float, caso outro valor seja digitado aparecerá uma mensagem de erro.

        7. Ao selecionar "Listar veiculos produzidos há menos de 90 dias" aparecerá uma tabela com todos os veiculos com menos de 90 dias de fabricação a partir da data atual.

        8. Ao selecionar "Sair" volta ao menu inicial.
    
    5. Ao Selecionar "Sair" irá sair do menu incial e realizer as ações para fechar o programa.

3. Ao sair do menu incial, o programa irá abrir novamente os arquivos **concessionaria.txt** e **veiculos.txt** em modo de escrita e irá salvar todos os dados necessários em seus respectivos arquivos **( Questão B da AP2 )**.