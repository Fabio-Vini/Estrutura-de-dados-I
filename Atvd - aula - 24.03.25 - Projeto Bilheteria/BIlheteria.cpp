#include <iostream>
#include <iomanip>

using namespace std;

const int LINHAS = 15;
const int COLUNAS = 40;
const double VALOR[3] = {50.0, 30.0, 15.0};

void exibirMapa(char mapa[LINHAS][COLUNAS]) {
    cout << "Mapa de ocupação do teatro:\n";
    for (int i = 0; i < LINHAS; i++) {
        cout << setw(2) << (i + 1) << " "; 
        for (int j = 0; j < COLUNAS; j++) {
            cout << mapa[i][j] << " ";
        }
        cout << endl;
    }
}

void calcularFaturamento(char mapa[LINHAS][COLUNAS]) {
    int lugaresOcupados = 0;
    double faturamento = 0.0;
    int ocupadosPorFileira[LINHAS] = {0};

    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            if (mapa[i][j] == '#') {
                lugaresOcupados++;
                ocupadosPorFileira[i]++;
                if (i < 5)
                    faturamento += VALOR[0];
                else if (i < 10)
                    faturamento += VALOR[1];
                else
                    faturamento += VALOR[2];
            }
        }
    }

    cout << "\nFATURAMENTO\n";
    cout << "Qtde de lugares ocupados: " << lugaresOcupados << endl;
    cout << "Valor da bilheteira: R$ " << fixed << setprecision(2) << faturamento << endl;

    cout << "\nOcupação por fileira:\n";
    for (int i = 0; i < LINHAS; i++) {
        cout << "Fileira " << setw(2) << (i + 1) << ": " << ocupadosPorFileira[i] << " lugares ocupados\n";
    }
}

int main() {
	//Inicia o mapa com as poltronas vagas
    char mapa[LINHAS][COLUNAS];

    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            mapa[i][j] = '.';
        }
    }

    int opcao;
    
    do {
        cout << "\nMENU:\n";
        cout << "0. Finalizar\n";
        cout << "1. Reservar poltrona\n";
        cout << "2. Mapa de ocupação\n";
        cout << "3. Faturamento\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1: {
                int fileira, poltrona;
                cout << "Informe a fileira (1 a 15): ";
                cin >> fileira;
                cout << "Informe a poltrona (1 a 40): ";
                cin >> poltrona;

                if (fileira < 1 || fileira > 15 || poltrona < 1 || poltrona > 40) {
                    cout << "Erro: Fileira ou poltrona inválida!\n";
                    break;
                }

                // Verifica se a poltrona já está ocupada
                if (mapa[fileira - 1][poltrona - 1] == '#') {
                    cout << "Essa poltrona já está ocupada!\n";
                } else {
                    mapa[fileira - 1][poltrona - 1] = '#';
                    cout << "Reserva realizada com sucesso!\n";
                }
                break;
            }

            case 2:
                exibirMapa(mapa);
                break;

            case 3:
                calcularFaturamento(mapa);
                break;

            case 0:
                cout << "Encerrando o sistema.\n";
                break;

            default:
                cout << "Opção inválida! Tente novamente.\n";
                break;
        }
    } while (opcao != 0);

    return 0;
}
