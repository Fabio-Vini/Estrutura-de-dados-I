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

//verificar se um prontuário já existe
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
    cout << "Digite o prontuário (ex: Cb3029118): ";
    cin >> f.prontuario;

    if (prontuarioExiste(f.prontuario)) {
        cout << "Erro: Prontuário já cadastrado!\n";
        return;
    }

    cin.ignore();
    cout << "Digite o nome: ";
    getline(cin, f.nome);

    cout << "Digite o salário: ";
    cin >> f.salario;

    funcionarios.push_back(f);
    cout << "Funcionário incluído com sucesso!\n";
}

// Excluir
void excluirFuncionario() {
    string prontuario;
    cout << "Digite o prontuário para excluir: ";
    cin >> prontuario;

    for (auto it = funcionarios.begin(); it != funcionarios.end(); ++it) {
        if (it->prontuario == prontuario) {
            funcionarios.erase(it);
            cout << "Funcionário excluído com sucesso!\n";
            return;
        }
    }
    cout << "Funcionário não encontrado!\n";
}

// Pesquisar
void pesquisarFuncionario() {
    string prontuario;
    cout << "Digite o prontuário para pesquisar: ";
    cin >> prontuario;

    for (auto& f : funcionarios) {
        if (f.prontuario == prontuario) {
            cout << "Nome: " << f.nome << "\n";
            cout << "Salário: R$ " << fixed << setprecision(2) << f.salario << "\n";
            return;
        }
    }
    cout << "Funcionário não encontrado!\n";
}

// Listar
void listarFuncionarios() {
    double totalSalarios = 0.0;

    if (funcionarios.empty()) {
        cout << "Nenhum funcionário cadastrado.\n";
        return;
    }

    cout << "\n--- Lista de Funcionários ---\n";
    for (auto& f : funcionarios) {
        cout << "Prontuário: " << f.prontuario << "\n";
        cout << "Nome: " << f.nome << "\n";
        cout << "Salário: R$ " << fixed << setprecision(2) << f.salario << "\n\n";
        totalSalarios += f.salario;
    }
    cout << "Total dos salários: R$ " << fixed << setprecision(2) << totalSalarios << "\n";
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
        cout << "Escolha uma opção: ";
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
                cout << "Opção inválida. Tente novamente.\n";
        }

    } while (opcao != 0);

    return 0;
}
