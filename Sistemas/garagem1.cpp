#include <iostream>
#include <string>

using namespace std;
#include "structs.h"

#define TAM 10


int main(){
    Veiculo vetor[TAM];
    int opcao;

    do{
        system("cls");
        cout << "MENU\n";
        cout << "1 - Entrar na garagem\n";
        cout << "2 - Listar veiculos\n";
        cout << "3 - Remover da garagem\n";
        cout << "4 - Sair do sistema\n";
        cout << "Opcao: ";
        cin >> opcao;

        switch (opcao)
        {
        case 1:
            cout << "Cadastro de Veiculo\n";
            break;
        case 2:
            cout << "Listagem de veiculos\n";
            break;
        case 3:
            cout << "Retirada de veiculo\n";
            break;
        case 4:
            /* code */
            break;
        
        default:
            cout << "Opcao Invalida!\n";
            break;
        }

        system("pause");
    } while(opcao != 4);

    return 1;
}
