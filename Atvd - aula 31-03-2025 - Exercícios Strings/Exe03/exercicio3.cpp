#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

string formatarNomeAgenda(string linha) {
    istringstream iss(linha);
    vector<string> partes;
    string palavra;

    while (iss >> palavra) {
        partes.push_back(palavra);
    }

    if (partes.size() >= 2) {
        string ultimoSobrenome = partes.back();
        partes.pop_back(); // Remove o último nome

        string resto;
        for (size_t i = 0; i < partes.size(); ++i) {
            resto += partes[i];
            if (i != partes.size() - 1) resto += " ";
        }

        return ultimoSobrenome + ", " + resto;
    }

    return linha;
}

int main() {
    ifstream arquivoEntrada("nomes.txt");

    if (!arquivoEntrada) {
        cerr << "Erro ao abrir o arquivo nomes.txt" << endl;
        return 1;
    }

    string linha;
    cout << "Nomes formatados:\n" << endl;

    while (getline(arquivoEntrada, linha)) {
        string nomeFormatado = formatarNomeAgenda(linha);
        cout << nomeFormatado << endl;
    }

    arquivoEntrada.close();
    return 0;
}
