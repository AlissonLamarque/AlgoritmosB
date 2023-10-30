#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "structs.h"
#include "metodos.h"

int main() {
    Criptomoeda* vetor = nullptr;
    int qtdCripto = 0, totalCripto = 0; 

    carregarCriptomoedas(vetor, qtdCripto, totalCripto);
    menu(vetor, qtdCripto, totalCripto);

    return 0;
}