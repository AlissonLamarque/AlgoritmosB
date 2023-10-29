#include <iostream>
#include <string>

using namespace std;
#include "structs.h"
#include "util.h"

#define TAM 10


int main(){
    Veiculo vetor[TAM];
    int opcao, quantidadeCarros;
    string placa, hora;
    bool carroLocalizado;

    inicializarVetor(vetor, TAM);
    quantidadeCarros = 0;

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

            if(quantidadeCarros == TAM){
                cout << "Garagem lotada!";
            }
            else{
                while (true){
                    cout << "\nInforme a placa em maiusculo: ";
                    cin >> placa;
                    if (placa.length() == 7){
                        break;
                    }
                    else{
                        cout << "Digite corretamente a placa!\n";
                    }
                }
                while (true){
                    cout << "\nInforme a hora de entrada [hh:mm]: ";
                    cin >> hora;
                    if (hora.length() == 5){
                        break;
                    }
                    else{
                        cout << "Digite corretamente a hora de entrada!\n";
                    }
                }

                carroLocalizado = false;
                for(int i=0; i < TAM; i++){
                    if(placa == vetor[i].placa){
                        cout << "Carro já na garagem.\n";
                        carroLocalizado = true;
                        break;
                    }
                }
                if(!carroLocalizado){
                    for(int i=0; i < TAM; i++){
                        if(vetor[i].placa == ""){
                            vetor[i].placa = placa;
                            vetor[i].horaEntrada = hora;
                            cout << "Carro inserido no sistema!\n";
                            quantidadeCarros++;
                            break;
                        }
                    }
                }
            }
            break;
        case 2:
            cout << "Listagem de veiculos\n";
            if(quantidadeCarros == 0){
                cout << "Garagem vazia!\n";
            }
            else{
                for(int i = 0; i < TAM; i++){
                    if(vetor[i].placa != ""){
                        cout << "Placa: " << vetor[i].placa << endl;
                    }
                }
            }
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
