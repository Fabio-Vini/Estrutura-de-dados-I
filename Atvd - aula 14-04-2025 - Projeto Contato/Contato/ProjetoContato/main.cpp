#include <iostream>
#include <string>
using namespace std;

class Data
{
private:
    int dia;
    int mes;
    int ano;

public:
    Data(int dia, int mes, int ano)
    {
        this->dia = dia;
        this->mes = mes;
        this->ano = ano;
    }

    Data()
    {
        this->dia = 0;
        this->mes = 0;
        this->ano = 0;
    }


    void setDia(int dia) { this->dia = dia; }
    void setMes(int mes) { this->mes = mes; }
    void setAno(int ano) { this->ano = ano; }

    int getDia() { return this->dia; }
    int getMes() { return this->mes; }
    int getAno() { return this->ano; }

    string getData()
    {
        string sdia = to_string(this->dia);
        string smes = to_string(this->mes);
        string sano = to_string(this->ano);

        return sdia.insert(0, 2 - sdia.size(), '0') + "/" +
               smes.insert(0, 2 - smes.size(), '0') + "/" +
               sano.insert(0, 4 - sano.size(), '0');
    }
};

class Contato
{
private:
    string email;
    string nome;
    string telefone;
    Data dtnasc;

public:

    Contato() {}

    Contato(string email, string nome, string telefone, Data dtnasc)
    {
        this->email = email;
        this->nome = nome;
        this->telefone = telefone;
        this->dtnasc = dtnasc;
    }


    void setEmail(string email) { this->email = email; }
    void setNome(string nome) { this->nome = nome; }
    void setTelefone(string telefone) { this->telefone = telefone; }
    void setDataNasc(Data dtnasc) { this->dtnasc = dtnasc; }


    string getEmail() { return this->email; }
    string getNome() { return this->nome; }
    string getTelefone() { return this->telefone; }
    Data getDataNasc() { return this->dtnasc; }


    int idade()
    {
        int anoAtual = 2025;
        int idadeCalculada = anoAtual - dtnasc.getAno();
        return idadeCalculada;
    }
};

int main()
{
    Contato contatos[5];
    string nome, email, telefone;
    int dia, mes, ano;

    // Aqui vai cadastrar os contatos
    for (int i = 0; i < 5; i++)
    {
        cout << "Cadastro do contato " << i + 1 << endl;

        cin.ignore(); // limpar o buffer antes de getline
        cout << "Nome: ";
        getline(cin, nome);

        cout << "Email: ";
        getline(cin, email);

        cout << "Telefone: ";
        getline(cin, telefone);

        cout << "Data de Nascimento (dia mes ano separados por espaço): ";
        cin >> dia >> mes >> ano;

        Data dtnasc(dia, mes, ano);
        contatos[i] = Contato(email, nome, telefone, dtnasc);

        cout << endl;
    }

    // Exibição dos contatos
    cout << "----------------------------" << endl;
    cout << "Contatos Cadastrados:" << endl;
    cout << "----------------------------" << endl;

    for (int i = 0; i < 5; i++)
    {
        cout << "Contato " << i + 1 << ":" << endl;
        cout << "Nome: " << contatos[i].getNome() << endl;
        cout << "Email: " << contatos[i].getEmail() << endl;
        cout << "Telefone: " << contatos[i].getTelefone() << endl;
        cout << "Data de Nascimento: " << contatos[i].getDataNasc().getData() << endl;
        cout << "Idade: " << contatos[i].idade() << " anos" << endl;
        cout << "----------------------------" << endl;
    }

    return 0;
}
