void atualizar(string *vetor, int *qtdInseridos, int tamanho){
    if(*qtdInseridos == 0){
        cout << "Sem cadastros para atualizar.\n";
    }
    else{
        cout << "ATUALIZAR\n";
        string nome;
        cout << "Nome: ";
        cin >> nome;
        for(int i = 0; i < tamanho; i++){
            if(vetor[i] == nome){
                cout << "Nome atualizado: ";
                cin >> nome;
                vetor[i] = nome;
            }
        }
    }
}

void deletar(string *vetor, int *qtdInseridos, int tamanho){
    if(*qtdInseridos == 0){
        cout << "Sem cadastros para deletar.\n";
    }
    else{
        cout << "DELETAR\n";
        string nome;
        cout << "Nome: ";
        cin >> nome;
        for(int i = 0; i < tamanho; i++){
            if(vetor[i] == nome){
                vetor[i] = " ";
                *qtdInseridos -= 1;
            }
        }
    }
}

void listar(string *vetor, int qtdInseridos){
    if (qtdInseridos == 0){
        cout << "Sem cadastros para apresentar.\n";
    }
    else{
        cout << "LISTAR\n";
        for (int i = 0; i < qtdInseridos; i++){
            cout << "- " << vetor[i] << endl;
        }
    }
}

void cadastrar(string *vetor, int *qtdInseridos, int tamanho){
    if(*qtdInseridos == tamanho){
        cout << "Lista cheia.\n";
        return;
    }
    cout << "CADASTRAR\n";
    string nome;
    cout << "Nome: ";
    cin >> nome;
    vetor[*qtdInseridos] = nome;
    *qtdInseridos += 1;
}

void menu(string *vetor, int *qtdInseridos, int tamanho){
    int op;

    do
    {
        system("cls");
        cout << "1 - Cadastrar \n";
        cout << "2 - Listar \n";
        cout << "3 - Atualizar \n";
        cout << "4 - Deletar \n";
        cout << "5 - Sair \n";
        cout << "Opcao: ";
        cin >> op;
        fflush(stdin);

        switch (op)
        {
        case 1:
            cadastrar(vetor, qtdInseridos, tamanho);
            break;
        case 2:
            listar(vetor, *qtdInseridos);
            break;
        case 3:
            atualizar(vetor, qtdInseridos, tamanho);
            break;
        case 4:
            deletar(vetor, qtdInseridos, tamanho);
            break;
        case 5:
            cout << "Saindo do sistema...\n";
            break;
        default:
            cout << "Opcao inválida! Tente novamente.";
            break;
        }

        system("pause");
    } while (op != 5);
    
}