#include <iostream>
using namespace std;

const int TAM = 30;


//PILHA COM LISTA ENCADEADA
struct No {
    int valor;
    No* proximo;
};

void pushLista(No*& topo, int valor) {
    No* novo = new No;
    novo->valor = valor;
    novo->proximo = topo;
    topo = novo;
}

int popLista(No*& topo) {
    if (topo == nullptr) return -1;
    int valor = topo->valor;
    No* temp = topo;
    topo = topo->proximo;
    delete temp;
    return valor;
}

void mostrarPilhaLista(No*& topo, string tipo) {
    cout << "\n[Pilha (Lista) " << tipo << " - Ordem Decrescente]: ";
    while (topo != nullptr) {
        cout << popLista(topo) << " ";
    }
    cout << endl;
}

//PILHA COM VETOR

struct PilhaVetor {
    int dados[TAM];
    int topo = -1;
};

void pushVetor(PilhaVetor& p, int valor) {
    if (p.topo < TAM - 1) {
        p.dados[++p.topo] = valor;
    }
}

int popVetor(PilhaVetor& p) {
    if (p.topo >= 0) {
        return p.dados[p.topo--];
    }
    return -1;
}

void mostrarPilhaVetor(PilhaVetor& p, string tipo) {
    cout << "\n[Pilha (Vetor) " << tipo << " - Ordem Decrescente]: ";
    while (p.topo >= 0) {
        cout << popVetor(p) << " ";
    }
    cout << endl;
}

int main() {
    No* pilhaParLista = nullptr;
    No* pilhaImparLista = nullptr;

    PilhaVetor pilhaParVetor;
    PilhaVetor pilhaImparVetor;

    int numero, anterior = -9999;

    for (int i = 0; i < 30; i++) {
        do {
            cout << "Digite o " << i + 1 << "º número (maior que " << anterior << "): ";
            cin >> numero;
        } while (numero <= anterior);
        anterior = numero;

        if (numero % 2 == 0) {
            pushLista(pilhaParLista, numero);
            pushVetor(pilhaParVetor, numero);
        } else {
            pushLista(pilhaImparLista, numero);
            pushVetor(pilhaImparVetor, numero);
        }
    }

    mostrarPilhaLista(pilhaParLista, "Pares");
    mostrarPilhaLista(pilhaImparLista, "Ímpares");

    mostrarPilhaVetor(pilhaParVetor, "Pares");
    mostrarPilhaVetor(pilhaImparVetor, "Ímpares");

    return 0;
}
