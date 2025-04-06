#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

string gerarCarta(int naipe, int numero, int baralho) {
    string carta;
    carta += to_string(naipe);
    if (numero < 10) carta += "0";
    carta += to_string(numero);
    carta += to_string(baralho);
    return carta;
}

int main() {
    string baralho[2][52];
    vector<string> todasCartas;

    // Criação das cartas no formato "N99B"
    for (int b = 0; b < 2; ++b) {
        int index = 0;
        for (int naipe = 1; naipe <= 4; ++naipe) {
            for (int numero = 1; numero <= 13; ++numero) {
                string carta = gerarCarta(naipe, numero, b + 1);
                baralho[b][index++] = carta;
                todasCartas.push_back(carta);
            }
        }
    }

    // Embaralha as 104 cartas
    srand((unsigned int)time(0));
    random_shuffle(todasCartas.begin(), todasCartas.end());

    // Distribuição das cartas
    string mao[4][11];
    int pos = 0;
    for (int c = 0; c < 11; ++c) {
        for (int j = 0; j < 4; ++j) {
            mao[j][c] = todasCartas[pos++];
        }
    }

    //Aqui mostra as mãos dos jogadores
    for (int j = 0; j < 4; ++j) {
        cout << "Jogador " << j + 1 << ": ";
        for (int c = 0; c < 11; ++c) {
            cout << mao[j][c] << " ";
        }
        cout << endl;
    }

    return 0;
}
