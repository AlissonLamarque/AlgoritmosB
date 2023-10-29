#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "Struct.h"

#include "Metodos.h"

int main() {
    Criptomoeda* vetor = nullptr;
    int qtdCripto = 0, capacidade = 0, int opcao;; 

    carregarCriptomoedas(vetor, qtdCripto, capacidade);

    do {
        cout << "MENU" << endl;
        cout << "1 - Cadastrar Criptomoeda" << endl;
        cout << "2 - Atualizar Valor" << endl;
        cout << "3 - Remover Criptomoeda" << endl;
        cout << "4 - Listar Criptomoedas" << endl;
        cout << "5 - Sair" << endl;
        cout << "Opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                cadastrar(vetor, qtdCripto, capacidade);
                salvarCriptomoedas(vetor, qtdCripto);
                break;
            case 2:
                atualizar(vetor, qtdCripto);
                salvarCriptomoedas(vetor, qtdCripto);
                break;
            case 3:
                remover(vetor, qtdCripto);
                salvarCriptomoedas(vetor, qtdCripto);
                break;
            case 4:
                listar(vetor, qtdCripto);
                break;
            case 5:
                cout << "Saindo..." << endl;
                break;
            default:
                cout << "Opção inválida." << endl;
        }
    } while (opcao != 5);

    return 0;
}