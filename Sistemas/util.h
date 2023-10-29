void inicializarVetor(Veiculo vetor[], int n){
    for (int i = 0; i < n; i++){
        vetor[i].placa = "";
        vetor[i].horarioEntrada = "";
    }
}

int entrarGaragem(Veiculo *vetor, int n, int quantidadeCarros){
    string placa, hora;
    bool carroLocalizado;
    
    cout << "\nCadastro de Veiculo\n";

        if(quantidadeCarros == n){
            cout << "Garagem lotada!";
            
        }
        else{
            while (true){
                cout << "Informe a placa em maiusculo: ";
                cin >> placa;
                if (placa.length() == 7){
                    break;
                }
                else{
                    cout << "Digite corretamente a placa!\n";
                }
            }
            while (true){
                cout << "Informe a hora de entrada [hh:mm]: ";
                cin >> hora;
                if (hora.length() == 5){
                    break;
                }
                else{
                    cout << "Digite corretamente a hora de entrada!\n";
                }
            }

            carroLocalizado = false;
            for(int i=0; i < n; i++){
                if(placa == vetor[i].placa){
                    cout << "Carro já na garagem.\n";
                    carroLocalizado = true;
                    break;
                }
            }
            if(!carroLocalizado){
                for(int i=0; i < n; i++){
                    if(vetor[i].placa == ""){
                        vetor[i].placa = placa;
                        vetor[i].horarioEntrada = hora;
                        cout << "Carro inserido no sistema!\n";
                        quantidadeCarros++;
                        break;
                    }
                }
            }
        }
        return quantidadeCarros; 
}

void listarGaragem(Veiculo *vetor, int n, int quantidadeCarros){
    cout << "\nListagem de veiculos\n";
        if(quantidadeCarros == 0){
            cout << "Garagem vazia!\n";
        }
        else{
            for(int i = 0; i < n; i++){
                if(vetor[i].placa != ""){
                    cout << "Placa: " << vetor[i].placa << endl;
                }
            }
        }
}

int retirarGaragem(Veiculo *vetor, int n, int quantidadeCarros){
    string placa, horarioSaida, horarioEntrada, tempSaida, tempEntrada;
    int horaSaida, horaEntrada, horasGaragem, custoGaragem;
    bool carroLocalizado;
    
    cout << "\nRetirada de Veiculo\n";

        if(quantidadeCarros == 0){
            cout << "Garagem vazia!\n";
        }
        else{
            while (true){
                cout << "Informe a placa em maiusculo: ";
                cin >> placa;
                if (placa.length() == 7){
                    break;
                }
                else{
                    cout << "Digite corretamente a placa!\n";
                }
            }

            carroLocalizado = false;
            for(int i=0; i < n; i++){
                if(placa == vetor[i].placa){
                    carroLocalizado = true;
                }
                if(!carroLocalizado){
                    cout << "Carro com a placa inserida nao localizado.\n";
                    break;
                }
                if(carroLocalizado){
                    while (true){
                        cout << "Informe a hora de saida [hh:mm]: ";
                        cin >> horarioSaida;

                        tempSaida = horarioSaida.substr(0, 2);
                        tempEntrada = vetor[i].horarioEntrada.substr(0, 2);

                        horaSaida = stoi(tempSaida);
                        horaEntrada = stoi(tempEntrada);
                        horasGaragem = horaSaida - horaEntrada;

                        if (horarioSaida.length() == 5){
                            if (horaSaida <= horaEntrada || horasGaragem > 23 || horaSaida > 23){
                            cout << "Digite uma hora de saida valida!\n";
                            }
                            else{
                                break;
                            }
                        }
                        else{
                            cout << "Digite corretamente a hora de saida!\n";
                        }
                    }

                    custoGaragem = horasGaragem * 5;
                    cout << "Tempo de estadia: " << horaSaida - horaEntrada << " horas. Valor a ser cobrado: " << custoGaragem << " reais." << endl;

                    vetor[i].placa = "";
                    vetor[i].horarioEntrada = "";
                    quantidadeCarros--;
                    cout << "Carro sendo retirado da garagem.\n";
                    break;
                }
            }
        }
    return quantidadeCarros;
}