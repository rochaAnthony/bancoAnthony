#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
using namespace std;

int main() {
    int numeroConta1 = 0, tipoConta1 = 1;
    string nomeCliente1, cpf1;
    double saldo1 = 0;
    bool contaAtiva1 = false;
    int numeroConta2 = 0, tipoConta2 = 1;
    string nomeCliente2, cpf2;
    double saldo2 = 0;
    bool contaAtiva2 = false;
    int numeroConta3 = 0, tipoConta3 = 1;
    string nomeCliente3, cpf3;
    double saldo3 = 0;
    bool contaAtiva3 = false;
    int numeroConta4 = 0, tipoConta4 = 1;
    string nomeCliente4, cpf4;
    double saldo4 = 0;
    bool contaAtiva4 = false;
    int numeroConta5 = 0, tipoConta5 = 1;
    string nomeCliente5, cpf5;
    double saldo5 = 0;
    bool contaAtiva5 = false;

    int numeroConta = 0, tipoConta = 1;
    string nomeCliente, cpf;
    double saldo = 0;
    bool contaAtiva = false;
    int opcao = 0, quantidade = 0, posicao = 0;
    bool entradaValida = false, numeroRepetido = false;
    cout << fixed << setprecision(2);

    do {
        cout << "\n********************************\n";
        cout << "**       BANCO ANTHONY        **\n";
        cout << "********************************\n";
        cout << "1 - Cadastrar conta\n2 - Consultar conta\n";
        cout << "3 - Verificar saldo\n4 - Alterar tipo da conta\n";
        cout << "5 - Ativar/Desativar conta\n6 - Sair\nOpcao: ";
        if (!(cin >> opcao)) {
            if (cin.eof()) break;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Digite uma opcao numerica.\n";
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (opcao) {
            case 1: {
                if (quantidade == 5) {
                    cout << "Limite de cinco contas atingido.\n";
                    break;
                }
                do {
                    cout << "Numero da conta (maior que zero): ";
                    cin >> numeroConta;
                    entradaValida = !cin.fail();
                    if (cin.eof()) return 0;
                    if (!entradaValida) cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    numeroRepetido = numeroConta == numeroConta1 || numeroConta == numeroConta2 || numeroConta == numeroConta3 || numeroConta == numeroConta4 || numeroConta == numeroConta5;
                    if (!entradaValida || numeroConta <= 0)
                        cout << "Numero invalido.\n";
                    else if (numeroRepetido)
                        cout << "Ja existe uma conta com esse numero.\n";
                } while (!entradaValida || numeroConta <= 0 || numeroRepetido);

                do {
                    cout << "Nome do titular: ";
                    if (!getline(cin, nomeCliente)) return 0;
                    if (nomeCliente == "")
                        cout << "Preencha o nome.\n";
                } while (nomeCliente == "");
                do {
                    cout << "CPF: ";
                    if (!getline(cin, cpf)) return 0;
                    if (cpf == "")
                        cout << "Preencha o CPF.\n";
                } while (cpf == "");

                do {
                    cout << "Tipo (1 - Corrente, 2 - Poupanca): ";
                    cin >> tipoConta;
                    entradaValida = !cin.fail();
                    if (cin.eof()) return 0;
                    if (!entradaValida) cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    if (!entradaValida || (tipoConta != 1 && tipoConta != 2))
                        cout << "Tipo invalido.\n";
                } while (!entradaValida || (tipoConta != 1 && tipoConta != 2));

                do {
                    cout << "Saldo inicial (use ponto nos centavos): ";
                    cin >> saldo;
                    entradaValida = !cin.fail();
                    if (cin.eof()) return 0;
                    if (!entradaValida) cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    if (!entradaValida || saldo < 0)
                        cout << "Saldo invalido. Use um valor nao negativo.\n";
                } while (!entradaValida || saldo < 0);

                contaAtiva = true;
                posicao = quantidade + 1;
                switch (posicao) {
                    case 1:
                        numeroConta1 = numeroConta;
                        nomeCliente1 = nomeCliente;
                        cpf1 = cpf;
                        tipoConta1 = tipoConta;
                        saldo1 = saldo;
                        contaAtiva1 = contaAtiva;
                        break;
                    case 2:
                        numeroConta2 = numeroConta;
                        nomeCliente2 = nomeCliente;
                        cpf2 = cpf;
                        tipoConta2 = tipoConta;
                        saldo2 = saldo;
                        contaAtiva2 = contaAtiva;
                        break;
                    case 3:
                        numeroConta3 = numeroConta;
                        nomeCliente3 = nomeCliente;
                        cpf3 = cpf;
                        tipoConta3 = tipoConta;
                        saldo3 = saldo;
                        contaAtiva3 = contaAtiva;
                        break;
                    case 4:
                        numeroConta4 = numeroConta;
                        nomeCliente4 = nomeCliente;
                        cpf4 = cpf;
                        tipoConta4 = tipoConta;
                        saldo4 = saldo;
                        contaAtiva4 = contaAtiva;
                        break;
                    case 5:
                        numeroConta5 = numeroConta;
                        nomeCliente5 = nomeCliente;
                        cpf5 = cpf;
                        tipoConta5 = tipoConta;
                        saldo5 = saldo;
                        contaAtiva5 = contaAtiva;
                        break;
                }
                quantidade++;
                cout << "Conta cadastrada e ativada.\n";
                break;
            }
            case 2:
            case 3:
            case 4:
            case 5: {
                if (quantidade == 0) {
                    cout << "Cadastre uma conta primeiro.\n";
                    break;
                }
                cout << "Informe o numero da conta: ";
                if (!(cin >> numeroConta)) {
                    if (cin.eof()) return 0;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Numero invalido.\n";
                    break;
                }
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                posicao = 0;
                if (numeroConta > 0 && numeroConta == numeroConta1) posicao = 1;
                else if (numeroConta > 0 && numeroConta == numeroConta2) posicao = 2;
                else if (numeroConta > 0 && numeroConta == numeroConta3) posicao = 3;
                else if (numeroConta > 0 && numeroConta == numeroConta4) posicao = 4;
                else if (numeroConta > 0 && numeroConta == numeroConta5) posicao = 5;
                if (posicao == 0) {
                    cout << "Conta nao encontrada.\n";
                    break;
                }
                switch (posicao) {
                    case 1:
                        numeroConta = numeroConta1;
                        nomeCliente = nomeCliente1;
                        cpf = cpf1;
                        tipoConta = tipoConta1;
                        saldo = saldo1;
                        contaAtiva = contaAtiva1;
                        break;
                    case 2:
                        numeroConta = numeroConta2;
                        nomeCliente = nomeCliente2;
                        cpf = cpf2;
                        tipoConta = tipoConta2;
                        saldo = saldo2;
                        contaAtiva = contaAtiva2;
                        break;
                    case 3:
                        numeroConta = numeroConta3;
                        nomeCliente = nomeCliente3;
                        cpf = cpf3;
                        tipoConta = tipoConta3;
                        saldo = saldo3;
                        contaAtiva = contaAtiva3;
                        break;
                    case 4:
                        numeroConta = numeroConta4;
                        nomeCliente = nomeCliente4;
                        cpf = cpf4;
                        tipoConta = tipoConta4;
                        saldo = saldo4;
                        contaAtiva = contaAtiva4;
                        break;
                    case 5:
                        numeroConta = numeroConta5;
                        nomeCliente = nomeCliente5;
                        cpf = cpf5;
                        tipoConta = tipoConta5;
                        saldo = saldo5;
                        contaAtiva = contaAtiva5;
                        break;
                }
                switch (opcao) {
                    case 2:
                        cout << "Numero: " << numeroConta << "\nTitular: " << nomeCliente;
                        cout << "\nCPF: " << cpf << "\nTipo: ";
                        if (tipoConta == 1) cout << "Corrente";
                        else cout << "Poupanca";
                        cout << "\nSaldo: R$ " << saldo << "\nSituacao: ";
                        if (contaAtiva) cout << "Ativa\n";
                        else cout << "Desativada\n";
                        break;
                    case 3:
                        if (!contaAtiva) cout << "Conta desativada. Ative antes de verificar o saldo.\n";
                        else cout << "Saldo: R$ " << saldo << "\n";
                        break;
                    case 4:
                        if (!contaAtiva) {
                            cout << "Conta desativada. Ative antes de alterar o tipo.\n";
                            break;
                        }
                        do {
                            cout << "Novo tipo (1 - Corrente, 2 - Poupanca): ";
                            cin >> tipoConta;
                            entradaValida = !cin.fail();
                            if (cin.eof()) return 0;
                            if (!entradaValida) cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            if (!entradaValida || (tipoConta != 1 && tipoConta != 2))
                                cout << "Tipo invalido.\n";
                        } while (!entradaValida || (tipoConta != 1 && tipoConta != 2));
                        cout << "Tipo atualizado.\n";
                        break;
                    case 5:
                        if (contaAtiva) {
                            contaAtiva = false;
                        } else {
                            contaAtiva = true;
                        }
                        if (contaAtiva) cout << "Conta ativada.\n";
                        else cout << "Conta desativada.\n";
                        break;
                }
                switch (posicao) {
                    case 1:
                        tipoConta1 = tipoConta;
                        contaAtiva1 = contaAtiva;
                        break;
                    case 2:
                        tipoConta2 = tipoConta;
                        contaAtiva2 = contaAtiva;
                        break;
                    case 3:
                        tipoConta3 = tipoConta;
                        contaAtiva3 = contaAtiva;
                        break;
                    case 4:
                        tipoConta4 = tipoConta;
                        contaAtiva4 = contaAtiva;
                        break;
                    case 5:
                        tipoConta5 = tipoConta;
                        contaAtiva5 = contaAtiva;
                        break;
                }
                break;
            }
            case 6:
                cout << "Programa encerrado.\n";
                break;
            default:
                cout << "Opcao invalida. Escolha de 1 a 6.\n";
        }
    } while (opcao != 6);
    return 0;
}
