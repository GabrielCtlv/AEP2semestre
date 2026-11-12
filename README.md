# PSE EM AÇÃO — Programa saúde na escola.

## Sobre o projeto

O **PSE EM AÇÃO** é um sistema desenvolvido em C++ para auxiliar no planejamento e acompanhamento de ações de saúde realizadas em ambiente escolar.

O programa permite cadastrar ações, consultar informações, atualizar situações e gerar um resumo dos dados registrados.

Este projeto foi desenvolvido como parte da atividade acadêmica do curso de Engenharia de Software.

## Funcionalidades  

1. **Cadastrar ação:** permite registrar uma nova ação de saúde, informando código, escola, tema, data, público-alvo, responsável e quantidade prevista de participantes.
2. **Listar ações:** apresenta todas as ações cadastradas.
3. **Pesquisar ação:** permite localizar uma ação pelo código, nome da escola ou tema.
4. **Atualizar situação:** permite alterar a situação da ação para planejada, realizada ou cancelada.
5. **Gerar resumo:** apresenta a quantidade de ações por situação e informações sobre os participantes previstos e reais.
6. **Sair:** encerra o programa.

## Tecnologias utilizadas

- Linguagem de programação: C++
- Compilador: MinGW (g++)
- Padrão utilizado: C++11
- Editor recomendado: VSCode/Dev C++

## Como utilizar o sistema

Ao iniciar o programa, será apresentado um menu com as opções:

 PSE EM ACAO
1. Cadastrar acao
2. Listar acoes
3. Pesquisar acao
4. Atualizar situacao
5. Gerar resumo
6. Sair

Escolha uma opcao:

O usuário deve digitar o número correspondente à funcionalidade desejada.
Exemplo de utilização

    Escolher a opção 1 para cadastrar uma ação.

    Preencher os dados solicitados pelo sistema.

    Escolher a opção 2 para visualizar as ações cadastradas.

    Escolher a opção 3 para pesquisar uma ação.

    Escolher a opção 4 para atualizar a situação de uma ação.

    Escolher a opção 5 para visualizar o resumo das ações.


O sistema possui algumas validações para evitar erros durante a utilização:

    Não permite cadastrar ações sem preencher os campos de texto.

    Não permite cadastrar duas ações com o mesmo código.

    Verifica se o código informado existe antes de atualizar uma ação.

    Informa quando nenhuma ação é encontrada na pesquisa.

    Verifica se os valores numéricos foram digitados corretamente.

    Limita o cadastro a 100 ações durante a execução do programa.

## Armazenamento

Os dados são armazenados temporariamente na memória do programa.

Ao encerrar o programa, os dados cadastrados são perdidos. Para manter as informações permanentemente, seria necessário implementar futuramente um sistema de armazenamento em arquivos ou banco de dados.
Objetivo acadêmico

O sistema busca oferecer uma solução simples para auxiliar no planejamento e acompanhamento de ações de saúde nas escolas.
Considerações finais

O projeto PSE EM AÇÃO apresenta uma aplicação prática dos conceitos de programação em C++. Por meio de um menu interativo, o usuário consegue cadastrar, consultar, pesquisar, atualizar e visualizar informações sobre ações de saúde escolar.
