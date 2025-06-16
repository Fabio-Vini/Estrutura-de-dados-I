#include <iostream>
using namespace std;

struct No {
    int senha;
    No* proximo;
};

struct Fila {
    No* inicio;
    No* fim;
    int tamanho;

    Fila() {
        inicio = nullptr;
        fim = nullptr;
        tamanho = 0;
    }

    void enfileirar(int valor) {
        No* novo = new No;
        novo->senha = valor;
        novo->proximo = nullptr;

        if (fim != nullptr) {
            fim->proximo = novo;
        } else {
            inicio = novo;
        }

        fim = novo;
        tamanho++;
    }

    int desenfileirar() {
        if (inicio == nullptr) {
            cout << "Fila vazia!" << endl;
            return -1;
        }

        No* temp = inicio;
        int valor = temp->senha;
        inicio = inicio->proximo;

        if (inicio == nullptr) {
            fim = nullptr;
        }

        delete temp;
        tamanho--;
        return valor;
    }

    bool estaVazia() {
        return tamanho == 0;
    }

    int getTamanho() {
        return tamanho;
    }
};

int main() {
    Fila senhasGeradas;
    Fila senhasAtendidas;
    int seletor;
    int numeroSenha = 1;

    do {
        cout << "\n========== MENU ==========\n";
        cout << "0 - Sair\n";
        cout << "1 - Gerar senha\n";
        cout << "2 - Realizar atendimento\n";
        cout << "Senhas aguardando atendimento: " << senhasGeradas.getTam
