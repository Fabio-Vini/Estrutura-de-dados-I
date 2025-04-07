#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

string formatarCitacaoBibliografica(string linha) {
    istringstream iss(linha);
    vector<string> partes;
    string palavra;

    while (iss >> palavra) {
        partes.push_back(palavra);
    }

    if (partes.size() < 2) {
        return linha;
    }

    string sobrenome = partes.back();
    transform(sobrenome.begin(), sobrenome.end(), sobrenome.begin(), ::toupper);
    partes.pop_back();

    string nomeFormatado = sobrenome + ", ";

    nomeFormatado += partes[0];

    // Pega iniciais dos nomes do meio
    for (size_t i = 1; i < partes.size(); ++i) {
        nomeFormatado += " " + partes[i].substr(0, 1) + ".";
    }

    return nomeFormatado;
}

int main() {
    ifstream arquivo("nomes.txt");

    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo nomes.txt" << endl;
        return 1;
    }

    string linha;
    cout << "Nomes no formato bibliográfico:\n\n";

    while (getline(arquivo, linha)) {
        string nomeCitacao = formatarCitacaoBibliografica(linha);
        cout << nomeCitacao << endl;
    }

    arquivo.close();
    return 0;
}
