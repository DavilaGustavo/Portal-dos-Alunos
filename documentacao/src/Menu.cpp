#include "Menu.h"
#include "Alunos.h"
#include "Materias.h"
#include <iostream>



using namespace std;

void menuAluno() {
    cout << "Menu do Aluno!" << endl;
    Alunos aluno("X", "X", 0, 0);
    
    string nome, email;
    int RA, periodo;

    cout << endl << "Digite seu nome: ";
    cin.ignore(); // Limpar o buffer antes de usar o getline, estava ocorrendo erro
    getline(cin, nome);

    cout << "Digite seu email: ";
    getline(cin, email);

    cout << "Digite seu RA: ";
    cin >> RA;

    cout << "Digite seu periodo: ";
    cin >> periodo;

    // Login com as informações
    aluno.fazerLogin(nome, email, RA, periodo);

    cout << "Login realizado com sucesso! Informacoes do aluno:" << endl << endl;
    /*cout << "Nome: " << aluno.getNome() << endl;
    cout << "Email: " << aluno.getEmail() << endl;
    cout << "RA: " << aluno.getRA()  << endl;
    cout << "Periodo: " << aluno.getPeriodo() << endl;*/

    vector<Materias> materiasDisponiveis = Materias::inicializarMaterias();

    cout << "Materias disponiveis: " << endl;
    for (size_t i = 0; i < materiasDisponiveis.size(); ++i){
        cout << i + 1 << ". " << materiasDisponiveis[i].getNomeMateria() << endl;
    }

    int escolha;
    cout << "Escolha uma materia: ";
    cin >> escolha;

    if (escolha >= 1 && escolha <= static_cast<int>(materiasDisponiveis.size())) {
        // Matriculando o aluno na matéria escolhida
        materiasDisponiveis[escolha - 1].matricularAluno(aluno);

        /*cout << "Materia: " << materiasDisponiveis[escolha - 1].getNomeMateria() << endl;
        cout << "Professor Responsavel: " << materiasDisponiveis[escolha - 1].getProfessorResponsavel().getNome() << endl;
        cout << "Alunos Matriculados:" << endl;*/
        cout << endl << "Alunos matriculados em " << materiasDisponiveis[escolha - 1].getNomeMateria() << ":" << endl;
        for (const auto& aluno : materiasDisponiveis[escolha - 1].getAlunosMatriculados()){       
            cout << aluno.getNome() << endl;
        }
    } else {
        cout << "Escolha invalida." << endl;
    }
}

void menuAdmin() {
    cout << "Menu do Admin!" << endl;
    
}

// Void responsável por continuar o menu com a escolha do usuário
void menu(int opcao) {
    switch (opcao) {
        case 1:
            //cout << "Voce escolheu a Opcao 1." << endl;
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