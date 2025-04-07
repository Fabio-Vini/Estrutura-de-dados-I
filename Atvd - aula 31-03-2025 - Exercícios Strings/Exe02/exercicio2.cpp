#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool ehPalindromo(string texto) {
    // Remove espa�os
    texto.erase(remove(texto.begin(), texto.end(), ' '), texto.end());

    // Verifica se � pal�ndromo
    string reverso = texto;
    reverse(reverso.begin(), reverso.end());

    return texto == reverso;
}

int main() {
    string mensagem;

    cout << "Digite uma mensagem: ";
    getline(cin, mensagem);

    if (ehPalindromo(mensagem)) {
        cout << "A mensagem � um pal�ndromo." << endl;
    } else {
        cout << "A mensagem NAO � um pal�ndromo." << endl;
    }

    return 0;
}
