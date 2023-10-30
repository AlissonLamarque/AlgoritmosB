string converterMaiusculas(string texto) {
    string textoMaiusculo;
    for (char c : texto) {
        textoMaiusculo += toupper(c);
    }
    return textoMaiusculo;
}

void cadastrar(Criptomoeda* &vetor, int &qtdCripto, int &totalCripto) {
    if (qtdCripto >= totalCripto) {
        totalCripto += 1;
        Criptomoeda* novoVetor = new Criptomoeda[totalCripto];
        for (int i = 0; i < qtdCripto; i++) {
            novoVetor[i] = vetor[i];
        }
        delete[] vetor;
        vetor = novoVetor;
    }

    cout << "CADASTRAR CRIPTOMOEDA" << endl;

    cout << "Nome: ";
    cin >> vetor[qtdCripto].nome;

    cout << "Sigla: ";
    cin >> vetor[qtdCripto].sigla;
    vetor[qtdCripto].sigla = converterMaiusculas(vetor[qtdCripto].sigla);

    cout << "Valor em dolar: ";
    cin >> vetor[qtdCripto].valorDolar;

    qtdCripto++;
    cout << "Criptomoeda cadastrada com sucesso." << endl;
}

void atualizar(Criptomoeda* vetor, int qtdCripto) {
    if (qtdCripto == 0) {
        cout << "Sem criptomoedas para atualizar." << endl;
        return;
    }

    cout << "ATUALIZAR VALOR" << endl;

    string sigla;
    cout << "Informe a sigla da criptomoeda: ";
    cin >> sigla;
    sigla = converterMaiusculas(sigla);

    for (int i = 0; i < qtdCripto; i++) {
        if (vetor[i].sigla == sigla) {
            cout << "Valor atualizado em dolar: ";
            cin >> vetor[i].valorDolar;
            cout << "Valor atualizado com sucesso." << endl;
            return;
        }
    }

    cout << "Criptomoeda não encontrada." << endl;
}

void remover(Criptomoeda* vetor, int &totalCripto) {
    if (totalCripto == 0) {
        cout << "Sem criptomoedas para remover." << endl;
        return;
    }

    cout << "REMOVER CRIPTOMOEDA" << endl;

    string sigla;
    cout << "Informe a sigla da criptomoeda: ";
    cin >> sigla;
    sigla = converterMaiusculas(sigla);

    for (int i = 0; i < totalCripto; i++) {
        if (vetor[i].sigla == sigla) {
            for (int j = i; j < totalCripto - 1; j++) {
                vetor[j] = vetor[j + 1];
            }
            totalCripto--;
            cout << "Criptomoeda removida com sucesso." << endl;
            return;
        }
    }

    cout << "Criptomoeda não cadastrada." << endl;
}

void listar(Criptomoeda* vetor, int totalCripto) {
    if (totalCripto == 0) {
        cout << "Sem criptomoedas para listar." << endl;
        return;
    }

    cout << "LISTA DE CRIPTOMOEDAS" << endl;
    for (int i = 0; i < totalCripto; i++) {
        cout << vetor[i].nome << " (" << vetor[i].sigla << "): U$" << vetor[i].valorDolar << endl;
    }
}


void salvarCriptomoedas(const Criptomoeda* vetor, int qtdCripto) {
    ofstream arquivoCripto("cripto.csv");

    if (arquivoCripto.is_open()) {
        for (int i = 0; i < qtdCripto; i++) {
            arquivoCripto << vetor[i].nome << "," << vetor[i].sigla << "," << vetor[i].valorDolar << "\n";
        }
        arquivoCripto.close();
        cout << "Criptomoedas salvas com sucesso." << endl;
    } else {
        cout << "Erro ao abrir o arquivo cripto.csv." << endl;
    }
}

void carregarCriptomoedas(Criptomoeda* &vetor, int &qtdCripto, int &totalCripto) {
    ifstream arquivoCripto("cripto.csv");

    if (arquivoCripto.is_open()) {
        qtdCripto = 0;
        string linha;

        while (getline(arquivoCripto, linha)) {
            size_t pos = linha.find(",");
            if (pos != string::npos) {
                if (qtdCripto >= totalCripto) {
                    totalCripto += 1;
                    Criptomoeda* novoVetor = new Criptomoeda[totalCripto];
                    for (int i = 0; i < qtdCripto; i++) {
                        novoVetor[i] = vetor[i];
                    }
                    delete[] vetor;
                    vetor = novoVetor;
                }
                vetor[qtdCripto].nome = linha.substr(0, pos);
                linha = linha.substr(pos + 1);
                pos = linha.find(",");
                if (pos != string::npos) {
                    vetor[qtdCripto].sigla = linha.substr(0, pos);
                    vetor[qtdCripto].valorDolar = stod(linha.substr(pos + 1));
                    qtdCripto++;
                }
            }
        }
        arquivoCripto.close();
    } else {
        cout << "Erro ao abrir o arquivo cripto.csv. Criando uma base de dados vazia." << endl;
    }
}

void menu(Criptomoeda* &vetor, int &qtdCripto, int &totalCripto){
        int opcao;

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
                cadastrar(vetor, qtdCripto, totalCripto);
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
                cout << "Obrigado pela preferência! Saindo do sistema..." << endl;
                break;
            default:
                cout << "Opção inválida! Tente novamente" << endl;
        }
    } while (opcao != 5);
}
