#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool ehPalindromo(string texto) {
    // Remove espaços
    texto.erase(remove(texto.begin(), texto.end(), ' '), texto.end());

    // Verifica se é palíndromo
    string reverso = texto;
    reverse(reverso.begin(), reverso.end());

    return texto == reverso;
}

int main() {
    string mensagem;

    cout << "Digite uma mensagem: ";
    getline(cin, mensagem);

    if (ehPalindromo(mensagem)) {
        cout << "A mensagem É um palíndromo." << endl;
    } else {
        cout << "A mensagem NAO é um palíndromo." << endl;
    }

    return 0;
}
