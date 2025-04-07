#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void clearScreen() {
    system("cls");
}

int main() {
    string mensagem;

    cout << "Digite a mensagem: ";
    getline(cin, mensagem);

    clearScreen();

    int larguraConsole = 80;
    int colunaInicial = (larguraConsole - mensagem.length()) / 2;

    gotoxy(colunaInicial, 5);
    cout << mensagem;

    Sleep(1000);

    for (size_t i = 0; i < mensagem.length(); ++i) {
        for (int linha = 6; linha <= 20; ++linha) {
            gotoxy(colunaInicial + i, linha - 1);
            cout << " ";
            gotoxy(colunaInicial + i, linha);
            cout << mensagem[i];
            Sleep(50);
        }
    }
    return 0;
}
