#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <limits>
#include <cctype>

using namespace std;

const int LIMITE_ACOES = 100;

struct Acao {
    int codigo;
    string escola;
    string tema;
    string data;
    string publicoAlvo;
    string responsavel;
    int participantesPrevistos;
    int participantesReais;
    int situacao;
};

vector<Acao> acoes;

int lerInteiro(string mensagem, int minimo, int maximo) {
    string entrada;
    int valor;
    char sobra;

    while (true) {
        cout << mensagem;
        getline(cin, entrada);

        stringstream ss(entrada);

        if (ss >> valor && !(ss >> sobra)
            && valor >= minimo && valor <= maximo) {
            return valor;
        }

        cout << "Valor invalido. Digite um numero entre "
             << minimo << " e " << maximo << ".\n";
    }
}

string lerTexto(string mensagem) {
    string texto;

    while (true) {
        cout << mensagem;
        getline(cin, texto);

        if (!texto.empty()) {
            return texto;
        }

        cout << "Este campo nao pode ficar vazio.\n";
    }
}

int buscarPorCodigo(int codigo) {
    for (int i = 0; i < (int)acoes.size(); i++) {
        if (acoes[i].codigo == codigo) {
            return i;
        }
    }

    return -1;
}

string nomeSituacao(int situacao) {
    if (situacao == 1) {
        return "Planejada";
    } else if (situacao == 2) {
        return "Realizada";
    } else {
        return "Cancelada";
    }
}

string minusculo(string texto) {
    for (int i = 0; i < (int)texto.size(); i++) {
        texto[i] = (char)tolower((unsigned char)texto[i]);
    }

    return texto;
}

void mostrarAcao(Acao acao) {
    cout << "\nCodigo: " << acao.codigo << endl;
    cout << "Escola: " << acao.escola << endl;
    cout << "Tema: " << acao.tema << endl;
    cout << "Data prevista: " << acao.data << endl;
    cout << "Publico-alvo: " << acao.publicoAlvo << endl;
    cout << "Responsavel: " << acao.responsavel << endl;

    cout << "Participantes previstos: "
         << acao.participantesPrevistos << endl;

    cout << "Situacao: "
         << nomeSituacao(acao.situacao) << endl;

    if (acao.situacao == 2) {
        cout << "Participantes efetivos: "
             << acao.participantesReais << endl;
    }

    cout << "-----------------------------------\n";
}

void cadastrarAcao() {
    Acao nova;

    cout << "\n=== CADASTRAR ACAO ===\n";

    if ((int)acoes.size() >= LIMITE_ACOES) {
        cout << "Limite de " << LIMITE_ACOES
             << " acoes atingido.\n";
        return;
    }

    nova.codigo = lerInteiro("Codigo positivo: ", 1, 2147483647);

    if (buscarPorCodigo(nova.codigo) != -1) {
        cout << "Esse codigo ja esta cadastrado.\n";
        return;
    }

    nova.escola = lerTexto("Nome da escola: ");
    nova.tema = lerTexto("Tema da acao: ");
    nova.data = lerTexto("Data prevista (DD/MM/AAAA): ");
    nova.publicoAlvo = lerTexto("Publico-alvo: ");
    nova.responsavel = lerTexto("Responsavel: ");

    nova.participantesPrevistos =
        lerInteiro("Quantidade prevista de participantes: ",
                   0, 1000000);

    nova.participantesReais = 0;
    nova.situacao = 1;

    acoes.push_back(nova);

    cout << "Acao cadastrada com sucesso!\n";
}


void listarAcoes() {
    cout << "\n=== LISTA DE ACOES ===\n";

    if (acoes.empty()) {
        cout << "Nenhuma acao cadastrada.\n";
        return;
    }

    for (int i = 0; i < (int)acoes.size(); i++) {
        mostrarAcao(acoes[i]);
    }

    cout << "Total de acoes: " << acoes.size() << endl;
}

void pesquisarAcao() {
    cout << "\n=== PESQUISAR ACAO ===\n";

    cout << "1 - Pesquisar por codigo\n";
    cout << "2 - Pesquisar por escola\n";
    cout << "3 - Pesquisar por tema\n";

    int opcao = lerInteiro("Escolha: ", 1, 3);

    if (opcao == 1) {
        int codigo = lerInteiro("Digite o codigo: ",
                                1, 2147483647);

        int indice = buscarPorCodigo(codigo);

        if (indice == -1) {
            cout << "Acao nao encontrada.\n";
        } else {
            mostrarAcao(acoes[indice]);
        }

        return;
    }

    string termo = minusculo(
        lerTexto("Digite o nome ou parte do texto: ")
    );

    int encontrados = 0;

    for (int i = 0; i < (int)acoes.size(); i++) {
        string campo;

        if (opcao == 2) {
            campo = minusculo(acoes[i].escola);
        } else {
            campo = minusculo(acoes[i].tema);
        }

        if (campo.find(termo) != string::npos) {
            mostrarAcao(acoes[i]);
            encontrados++;
        }
    }

    if (encontrados == 0) {
        cout << "Nenhuma acao encontrada.\n";
    } else {
        cout << "Acoes encontradas: "
             << encontrados << endl;
    }
}

void atualizarSituacao() {
    cout << "\n=== ATUALIZAR SITUACAO ===\n";

    if (acoes.empty()) {
        cout << "Nenhuma acao cadastrada.\n";
        return;
    }

    int codigo = lerInteiro("Digite o codigo da acao: ",
                            1, 2147483647);

    int indice = buscarPorCodigo(codigo);

    if (indice == -1) {
        cout << "Acao nao encontrada.\n";
        return;
    }

    cout << "1 - Planejada\n";
    cout << "2 - Realizada\n";
    cout << "3 - Cancelada\n";

    int situacao = lerInteiro("Nova situacao: ", 1, 3);

    acoes[indice].situacao = situacao;

    if (situacao == 2) {
        acoes[indice].participantesReais =
            lerInteiro("Quantidade efetiva de participantes: ",
                       0, 1000000);
    } else {
        acoes[indice].participantesReais = 0;
    }

    cout << "Situacao atualizada para "
         << nomeSituacao(situacao) << ".\n";
}

void gerarResumo() {
    int planejadas = 0;
    int realizadas = 0;
    int canceladas = 0;
    int totalPrevisto = 0;
    int totalReal = 0;

    for (int i = 0; i < (int)acoes.size(); i++) {

        totalPrevisto += acoes[i].participantesPrevistos;

        if (acoes[i].situacao == 1) {
            planejadas++;
        } else if (acoes[i].situacao == 2) {
            realizadas++;
            totalReal += acoes[i].participantesReais;
        } else {
            canceladas++;
        }
    }

    cout << "\n=== RESUMO GERAL ===\n";

    cout << "Acoes cadastradas: "
         << acoes.size() << endl;

    cout << "Acoes planejadas: "
         << planejadas << endl;

    cout << "Acoes realizadas: "
         << realizadas << endl;

    cout << "Acoes canceladas: "
         << canceladas << endl;

    cout << "Participantes previstos: "
         << totalPrevisto << endl;

    cout << "Participantes efetivos: "
         << totalReal << endl;

    if (totalPrevisto > 0) {
        double percentual =
            (double)totalReal * 100 / totalPrevisto;

        cout << "Percentual de participacao: "
             << percentual << "%\n";
    } else {
        cout << "Percentual nao calculado: "
             << "nao ha participantes previstos.\n";
    }
}


void mostrarMenu() {
    cout << "\n========== PSE EM ACAO ==========\n";

    cout << "1 - Cadastrar acao\n";
    cout << "2 - Listar todas as acoes\n";
    cout << "3 - Pesquisar acao\n";
    cout << "4 - Atualizar situacao da acao\n";
    cout << "5 - Gerar resumo geral\n";
    cout << "0 - Sair\n";

    cout << "=================================\n";
}

int main() {
    int opcao;

    do {
        mostrarMenu();

        opcao = lerInteiro("Escolha uma opcao: ", 0, 5);

        switch (opcao) {

            case 1:
                cadastrarAcao();
                break;

            case 2:
                listarAcoes();
                break;

            case 3:
                pesquisarAcao();
                break;

            case 4:
                atualizarSituacao();
                break;

            case 5:
                gerarResumo();
                break;

            case 0:
                cout << "Programa encerrado. "
                     << "Obrigado por utilizar o PSE em Acao!\n";
                break;
        }

    } while (opcao != 0);

    return 0;
}

