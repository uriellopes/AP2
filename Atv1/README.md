# 2019.2 - Avaliação Prática 1
Professor:  Renan Cipriano Moioli  
Turma:  IMD0030 - Linguagem de Programação I - T02

Dupla:  Uriel Lira Lopes - 2016045704  
        Gustavo Batista de Araújo Gorgônio - 2016045689

## Instruções
1. Para compilar o programa basta digitar make no terminal;
2. Para rodar o programa basta digitar make run no terminal;
3. Para remover os arquivos .o e o executavel basta digitar make clean no terminal.

## Funcionalidades
1. Ao rodar o programa será mostrado um menu inicial com as seguintes opções:
    - Criar uma nova concessionária ( Questão C da AP1 );
    - Listar a média de carros por concessionária ( Questão H da AP1 );
    - Selecionar alguma das concessionárias cadastradas.  
    **OBS:** O programa irá verificar o input do usuário é um digito e se é uma das opções, caso seja falso aparecerá uma mensagem de erro.

    1. Ao selecionar "Criar nova concessionária"
    Ao selecionar criar nova concessionária aparece mensagens de texto pedindo as informações necessária para cadastrar-la ( Questão B da AP1 ).  
    **OBS:** Caso ja exista uma concessionária de mesmo nome ou de msm CNPJ aparecerá uma mensagem de erro e retornará ao menu inicial.  
    **OBS2:** O CNPJ só aceita valores inteiros, caso outro tipo de valor seja digitado aparecerá uma mensagem de error.

    2. Ao selecionar "Listar a média de carros por concessionária" aparecerá uma mensagem mostrando o valor da média e retornará ao menu inicial.

    3. Ao seleciar alguma das concessionárias cadastradas aparecerá as informações dessa concessionária e um menu referente a ela com as seguintes opções:
        - Adicionar novo carro ( Questão D da AP1 );
        - Listar carros cadastrados ( Questão E da AP1 );
        - Aumentar o preço de todos os carros em % ( Questão F da AP1 );
        - Listar carros produzidos há menos de 90 dias (Questão G da AP1 ).

        1. Ao selecionar "Adicionar novo carro" aparecerá mensagens de texto pedindo as informações necessária para adicionar o carro ( Questão A da AP1 ).  
        **OBS:** Caso já exista um carro de mesmo chassi cadastrado, aparecerá uma mensagem de erro e retornará para o menu da concessionária.  
        **OBS2:** O preço do carro so aceita valores inteiros ou float, seperando as casas decimais por um ponto("."), caso outro valor seja digitado aparecerá uma mensagem de erro.  
        **OBS3:** A data de fabricação devera ser uma data válida e separando dia, mês e ano por uma barra("/"), do tipo dd/mm/aaaa, caso outro valor seja digitado aparecerá uma mensagem de erro.

        2. Ao selecionar "Listar carros cadastrados" aparecerá uma tabela com todos os carros cadastrados na concessionária.

        3. Ao selecionar "Aumentar o preço de todos os carros em %" aparecera uma mensagem pedindo o valor a ser aumentado.  
        **OBS:** O valor deverá ser um inteiro ou um float, caso outro valor seja digitado aparecerá uma mensagem de erro.

        4. Ao selecionar "Listar carros produzidos há menos de 90 dias" aparecerá uma tabela com todos os carros com menos de 90 dias de fabricação a partir da data atual.
