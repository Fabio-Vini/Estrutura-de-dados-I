#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

struct Funcionario {
    string prontuario;
    string nome;
    double salario;
};

vector<Funcionario> funcionarios;

//verificar se um prontu�rio j� existe
bool prontuarioExiste(const string& prontuario) {
    for (auto& f : funcionarios) {
        if (f.prontuario == prontuario)
            return true;
    }
    return false;
}

// Incluir
void incluirFuncionario() {
    Funcionario f;
    cout << "Digite o prontu�rio (ex: Cb3029118): ";
    cin >> f.prontuario;

    if (prontuarioExiste(f.prontuario)) {
        cout << "Erro: Prontu�rio j� cadastrado!\n";
        return;
    }

    cin.ignore(); // Limpar buffer
    cout << "Digite o nome: ";
    getline(cin, f.nome);

    cout << "Digite o sal�rio: ";
    cin >> f.salario;

    funcionarios.push_back(f);
    cout << "Funcion�rio inclu�do com sucesso!\n";
}

// Excluir
void excluirFuncionario() {
    string prontuario;
    cout << "Digite o prontu�rio para excluir: ";
    cin >> prontuario;

    for (auto it = funcionarios.begin(); it != funcionarios.end(); ++it) {
        if (it->prontuario == prontuario) {
            funcionarios.erase(it);
            cout << "Funcion�rio exclu�do com sucesso!\n";
            return;
        }
    }
    cout << "Funcion�rio n�o encontrado!\n";
}

// Pesquisar
void pesquisarFuncionario() {
    string prontuario;
    cout << "Digite o prontu�rio para pesquisar: ";
    cin >> prontuario;

    for (auto& f : funcionarios) {
        if (f.prontuario == prontuario) {
            cout << "Nome: " << f.nome << "\n";
            cout << "Sal�rio: R$ " << fixed << setprecision(2) << f.salario << "\n";
            return;
        }
    }
    cout << "Funcion�rio n�o encontrado!\n";
}

// Listar
void listarFuncionarios() {
    double totalSalarios = 0.0;

    if (funcionarios.empty()) {
        cout << "Nenhum funcion�rio cadastrado.\n";
        return;
    }

    cout << "\n--- Lista de Funcion�rios ---\n";
    for (auto& f : funcionarios) {
        cout << "Prontu�rio: " << f.prontuario << "\n";
        cout << "Nome: " << f.nome << "\n";
        cout << "Sal�rio: R$ " << fixed << setprecision(2) << f.salario << "\n\n";
        totalSalarios += f.salario;
    }
    cout << "Total dos sal�rios: R$ " << fixed << setprecision(2) << totalSalarios << "\n";
}

int main() {
    int opcao;

    do {
        cout << "\nMenu:\n";
        cout << "0. Sair\n";
        cout << "1. Incluir\n";
        cout << "2. Excluir\n";
        cout << "3. Pesquisar\n";
        cout << "4. Listar\n";
        cout << "Escolha uma op��o: ";
        cin >> opcao;

        switch (opcao) {
            case 0:
                cout << "Encerrando o programa.\n";
                break;
            case 1:
                incluirFuncionario();
                break;
            case 2:
                excluirFuncionario();
                break;
            case 3:
                pesquisarFuncionario();
                break;
            case 4:
                listarFuncionarios();
                break;
            default:
                cout << "Op��o inv�lida. Tente novamente.\n";
        }

    } while (opcao != 0);

    return 0;
}
