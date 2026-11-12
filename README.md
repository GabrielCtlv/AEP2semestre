
# PSE em Ação

Sistema de terminal desenvolvido em linguagem C para apoiar o planejamento e o acompanhamento de ações coletivas do Programa Saúde na Escola (PSE).

## Funcionalidades

1. Cadastrar ação (código, escola, tema, data, público-alvo, responsável e participantes).
2. Listar todas as ações.
3. Pesquisar por código, escola ou tema.
4. Atualizar situação para: planejada, realizada ou cancelada. Ao marcar como realizada, informa participantes efetivos.
5. Gerar resumo geral e indicadores de participação.
6. Encerrar o programa.

## Requisitos

- Compilador C com suporte ao padrão C11 (GCC, MinGW ou equivalente).
- Terminal ou Prompt de Comando.

## Compilação

### Linux

```bash
gcc -std=c11 -Wall -Wextra -pedantic pse_em_acao.c -o pse_em_acao
```

### Windows (MinGW)

```bash
gcc -std=c11 -Wall -Wextra -pedantic pse_em_acao.c -o pse_em_acao.exe
```

## Execução

### Linux

```bash
./pse_em_acao
```

### Windows

```bash
pse_em_acao.exe
```

## Regras e validações

- Armazenamento em memória durante a execução, com limite de 100 ações.
- Código deve ser positivo e não pode se repetir.
- Campos textuais são obrigatórios.
- Quantidades de participantes aceitam apenas números inteiros não negativos.
- Pesquisas sem resultado e códigos inexistentes recebem mensagens informativas.
- Ao encerrar o programa, os registros são perdidos, pois esta versão não utiliza banco de dados nem arquivo persistente.

## Integrantes

- Kauan Soares Souza — 26008190-2
- Gabriel Henrique Chatalov — 26005259-2
- Ilaerte Dos Reis Camargo Vilella — 26010463-2

## Instituição

UniCesumar — Universidade Cesumar

Projeto acadêmico — 2026.
