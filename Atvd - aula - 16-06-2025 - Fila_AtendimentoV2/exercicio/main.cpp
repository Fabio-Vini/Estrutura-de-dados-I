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
        No* novo = new No{valor, nullptr};

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

    void listar() {
        No* atual = inicio;
        while (atual != nullptr) {
            cout << atual->senha << " ";
            atual = atual->proximo;
        }
        cout << endl;
    }
};

struct Guiche {
    int id;
    Fila senhasAtendidas;
    Guiche* proximo;
};

struct ListaGuiches {
    Guiche* inicio;

    ListaGuiches() {
        inicio = nullptr;
    }

    void adicionarGuiche(int id) {
        Guiche* novo = new Guiche{id, Fila(), nullptr};
        novo->proximo = inicio;
        inicio = novo;
    }

    Guiche* buscarGuiche(int id) {
        Guiche* atual = inicio;
        while (atual != nullptr) {
            if (atual->id == id)
                return atual;
            atual = atual->proximo;
        }
        return nullptr;
    }

    int contarGuiches() {
        int cont = 0;
        Guiche* atual = inicio;
        while (atual != nullptr) {
            cont++;
            atual = atual->proximo;
        }
        return cont;
    }

    void listarSenhasAtendidas(int id) {
        Guiche* g = buscarGuiche(id);
        if (g == nullptr) {
            cout << "Guich� n�o encontrado.\n";
            return;
        }
        if (g->senhasAtendidas.estaVazia()) {
            cout << "Nenhuma senha atendida por este guich�.\n";
        } else {
            cout << "Senhas atendidas pelo guich� " << id << ": ";
            g->senhasAtendidas.listar();
        }
    }

    int contarTotalSenhasAtendidas() {
        int total = 0;
        Guiche* atual = inicio;
        while (atual != nullptr) {
            total += atual->senhasAtendidas.getTamanho();
            atual = atual->proximo;
        }
        return total;
    }
};

int main() {
    Fila senhasGeradas;
    ListaGuiches listaGuiches;
    int seletor, numeroSenha = 1;

    do {
        cout << "\n========== MENU ==========\n";
        cout << "0 - Sair\n";
        cout << "1 - Gerar senha\n";
        cout << "2 - Abrir guich�\n";
        cout << "3 - Realizar atendimento\n";
        cout << "4 - Listar senhas atendidas\n";
        cout << "Senhas aguardando atendimento: " << senhasGeradas.getTamanho() << endl;
        cout << "Guich�s abertos: " << listaGuiches.contarGuiches() << endl;
        cout << "Escolha uma op��o: ";
        cin >> seletor;

        switch (seletor) {
            case 1: { // Gerar senha
                senhasGeradas.enfileirar(numeroSenha++);
                cout << "Senha gerada com sucesso!\n";
                break;
            }

            case 2: { // Abrir guich�
                int id;
                cout << "Digite o ID do novo guich�: ";
                cin >> id;
                if (listaGuiches.buscarGuiche(id)) {
                    cout << "Guich� com esse ID j� existe.\n";
                } else {
                    listaGuiches.adicionarGuiche(id);
                    cout << "Guich� " << id << " aberto com sucesso.\n";
                }
                break;
            }

            case 3: {
                int id;
                cout << "Digite o ID do guich� que est� chamando a senha: ";
                cin >> id;
                Guiche* g = listaGuiches.buscarGuiche(id);
                if (g == nullptr) {
                    cout << "Guich� n�o encontrado!\n";
                } else if (senhasGeradas.estaVazia()) {
                    cout << "Nenhuma senha para atender!\n";
                } else {
                    int senhaAtendida = senhasGeradas.desenfileirar();
                    g->senhasAtendidas.enfileirar(senhaAtendida);
                    cout << "Senha " << senhaAtendida << " atendida no guich� " << id << ".\n";
                }
                break;
            }

            case 4: {
                int id;
                cout << "Digite o ID do guich�: ";
                cin >> id;
                listaGuiches.listarSenhasAtendidas(id);
                break;
            }

            case 0: {
                if (!senhasGeradas.estaVazia()) {
                    cout << "Ainda h� senhas aguardando atendimento. N�o � poss�vel sair.\n";
                    seletor = -1; // For�a o loop a continuar
                } else {
                    int total = listaGuiches.contarTotalSenhasAtendidas();
                    cout << "Encerrando programa. Total de senhas atendidas: " << total << endl;
                }
                break;
            }

            default:
                cout << "Op��o inv�lida!\n";
        }
    } while (seletor != 0);

    return 0;
}
