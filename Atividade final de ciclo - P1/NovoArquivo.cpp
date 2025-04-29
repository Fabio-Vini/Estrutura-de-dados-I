#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Data {
private:
    int dia, mes, ano;

public:
    Data(int dia = 0, int mes = 0, int ano = 0) : dia(dia), mes(mes), ano(ano) {}

    void setDia(int dia) { this->dia = dia; }
    void setMes(int mes) { this->mes = mes; }
    void setAno(int ano) { this->ano = ano; }

    int getDia() { return dia; }
    int getMes() { return mes; }
    int getAno() { return ano; }

    string getData() {
        string sdia = to_string(dia);
        string smes = to_string(mes);
        string sano = to_string(ano);

        return sdia.insert(0, 2 - sdia.size(), '0') + "/" +
               smes.insert(0, 2 - smes.size(), '0') + "/" +
               sano.insert(0, 4 - sano.size(), '0');
    }
};

class Contato {
private:
    string email;
    string nome;
    string telefone;
    Data dtnasc;

public:
    Contato(string email = "", string nome = "", string telefone = "", Data dtnasc = Data())
        : email(email), nome(nome), telefone(telefone), dtnasc(dtnasc) {}

    void setEmail(string email) { this->email = email; }
    void setNome(string nome) { this->nome = nome; }
    void setTelefone(string telefone) { this->telefone = telefone; }
    void setDataNasc(Data dtnasc) { this->dtnasc = dtnasc; }

    string getEmail() { return email; }
    string getNome() { return nome; }
    string getTelefone() { return telefone; }
    Data getDataNasc() { return dtnasc; }

    int idade() {
        return 2025 - dtnasc.getAno();
    }
};


string nomeCitacaoBibliografica(string nomeCompleto) {
    size_t pos = nomeCompleto.find_last_of(' ');
    if (pos == string::npos)
        return nomeCompleto; // nome sem espaços
    string primeiroNome = nomeCompleto.substr(0, pos);
    string ultimoNome = nomeCompleto.substr(pos + 1);
    transform(ultimoNome.begin(), ultimoNome.end(), ultimoNome.begin(), ::toupper);
    return ultimoNome + ", " + primeiroNome;
}

int main() {
    Contato contatos[10];
    string nome, email, telefone;
    int dia, mes, ano;

    for (int i = 0; i < 10; i++) {
        cout << "Cadastro do contato " << i + 1 << endl;
        cin.ignore(); 
        cout << "Nome: ";
        getline(cin, nome);

        cout << "Email: ";
        getline(cin, email);

        cout << "Telefone: ";
        getline(cin, telefone);

        cout << "Data de nascimento (dia mes ano): ";
        cin >> dia >> mes >> ano;

        Data dtnasc(dia, mes, ano);
        contatos[i] = Contato(email, nome, telefone, dtnasc);
        cout << "----------------------------\n";
    }

    // Média das idades
    int somaIdades = 0;
    for (int i = 0; i < 10; i++) {
        somaIdades += contatos[i].idade();
    }
    double mediaIdade = static_cast<double>(somaIdades) / 10;
    cout << "Média das idades: " << mediaIdade << " anos\n";

    // Contatos com idade acima da média
    cout << "\nContatos com idade acima da média:\n";
    for (int i = 0; i < 10; i++) {
        if (contatos[i].idade() > mediaIdade) {
            cout << nomeCitacaoBibliografica(contatos[i].getNome()) << endl;
        }
    }

    // Contato(s) mais velho(s)
    int maiorIdade = 18;
    for (int i = 0; i < 10; i++) {
        if (contatos[i].idade() >= maiorIdade) {
            maiorIdade = contatos[i].idade();
        }
    }

   // Contatos maiores de idade
int maioresDeIdade = 0;
cout << "\nContatos maiores de idade:\n";
for (int i = 0; i < 10; i++) {
    if (contatos[i].idade() >= 18) {
        maioresDeIdade++;
        cout << "Nome: " << nomeCitacaoBibliografica(contatos[i].getNome()) << endl;
        cout << "Email: " << contatos[i].getEmail() << endl;
        cout << "Telefone: " << contatos[i].getTelefone() << endl;
        cout << "Idade: " << contatos[i].idade() << " anos" << endl;
        cout << "----------------------------" << endl;
    }
}
cout << "Quantidade de contatos maiores de idade: " << maioresDeIdade << endl;


    return 0;
}
