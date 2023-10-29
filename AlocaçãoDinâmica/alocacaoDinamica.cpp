#include <iostream>
#include <string>

using namespace std;

#include "util.h"


int main(){
    string *vetor;
    int tamanho;
    int qtdInseridos = 0;

    cout << "Quantos nomes quer gerenciar: ";
    cin >> tamanho;

    vetor = (string *)malloc(sizeof(string) * tamanho);
    menu(vetor, &qtdInseridos, tamanho);

    return 1;
}
