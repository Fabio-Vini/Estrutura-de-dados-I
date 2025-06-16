#include <iostream>
using namespace std;

const int MAX = 100;

struct Fila {
    int vetor[MAX];
    int* inicio;
    int* fim;
    int tamanho;

    Fila() {
        inicio = vetor;
        fim = vetor;
        tamanho = 0;
    }

    void enfileirar(int valor) {
        if (tamanho == MAX) {
            cout << "Fila cheia!" << endl;
            return;
        }
        *fim = valor;
        fim++;
        tamanho++;
    }

    int desenfileirar() {
        if (tamanho == 0) {
            cout << "Fila vazia!" << endl;
            return -1;
        }
        int valor = *inicio;
        for (int i = 0; i < tamanho - 1; i++) {
            vetor[i] = vetor[i + 1];
        }
        fim--;
        tamanho--;
        return valor;
    }

    int getTamanho() {
        return tamanho;
    }

    bool estaVazia() {
        return tamanho == 0;
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
        cout << "Senhas aguardando atendimento: " << senhasGeradas.getTamanho() << endl;
        cout << "Escolha uma opcao: ";
        cin >> seletor;

        switch (seletor) {
            case 0:
                if (!senhasGeradas.estaVazia()) {
                    cout << "Ainda há senhas aguardando atendimento. Continue até atender todas." << endl;
                } else {
                    cout << "\nEncerrando sistema...\n";
                    cout << "Total de senhas atendidas: " << senhasAtendidas.getTamanho() << endl;
                }
                break;

            case 1:
                senhasGeradas.enfileirar(numeroSenha);
                cout << "Senha gerada: " << numeroSenha << endl;
                numeroSenha++;
                break;

            case 2:
                if (senhasGeradas.estaVazia()) {
                    cout << "Nenhuma senha para atender!" << endl;
                } else {
                    int senha = senhasGeradas.desenfileirar();
                    senhasAtendidas.enfileirar(senha);
                    cout << "Atendendo senha: " << senha << endl;
                }
                break;

            default:
                cout << "Opcao invalida. Tente novamente." << endl;
        }

    } while (!(seletor == 0 && senhasGeradas.estaVazia()));

    return 0;
}
