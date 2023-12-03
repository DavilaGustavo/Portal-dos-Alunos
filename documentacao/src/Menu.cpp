#include "Menu.h"
#include <iostream>

using namespace std;

void menuAluno() {
    cout << "Menu do Aluno!" << endl;
}

void menuAdmin() {
    cout << "Menu do Admin!" << endl;
}

// Void responsável por continuar o menu com a escolha do usuário
void menu(int opcao) {
    switch (opcao) {
        case 1:
            cout << "Voce escolheu a Opcao 1." << endl;
            menuAluno();
            break;
        case 2:
            cout << "Voce escolheu a Opcao 2." << endl;
            menuAdmin();
            break;
        case 0:
            cout << "Saindo do programa." << endl;
            break;
        default:
            cout << "Opcao invalida. Tente novamente." << endl;
    }
}

// Void responsável por chamar o menu e guardar a escolha do usuário
void chamarMenu() {
    int opcao;
    cout << "Escolha como prosseguir:" << endl;
    cout << "[1]. Aluno" << endl;
    cout << "[2]. Admin" << endl;
    cout << "[0]. Sair" << endl;

    cout << "Escolha uma opcao: ";
    cin >> opcao;

    // A continuação do menu baseado na escolha
    menu(opcao);
}