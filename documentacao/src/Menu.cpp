#include "Menu.h"
#include "Alunos.h"
#include "Materias.h"
#include <iostream>
#include <algorithm>



using namespace std;

void menuAluno() {
    cout << "Menu do Aluno!" << endl;
 
    string nome, email;
    int RA, periodo;

    Alunos aluno(nome, email, RA, periodo);

    cout << endl << "Digite seu nome: ";
    cin.ignore(); // Limpar o buffer antes de usar o getline
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
        cout << i + 1 << ". " << materiasDisponiveis[i].getNomeMateria() << " (" << materiasDisponiveis[i].getPeriodo() << ")" << endl;
    }

    int escolha;
    cout << endl << "Selecao de materias feitas" << endl << "###############" << endl << "Digite 0 para sair" << endl;
    do {
        cout << "Escolha uma materia feita: ";
        cin >> escolha;

         if (escolha >= 1 && escolha <= static_cast<int>(materiasDisponiveis.size())) {
            // Adicionando a matéria à lista de matérias feitas
            aluno.adicionarMateriaFeita(materiasDisponiveis[escolha - 1].getNomeMateria());
        } else if (escolha != 0) {
            cout << "Escolha invalida." << endl;
        }
    } while (escolha != 0);

    // Mostrar matérias feitas pelo aluno
    cout << endl << "Materias feitas pelo aluno:" << endl;
    vector<string> materiasFeitas = aluno.getMateriasFeitas();
    for (const auto& materia : materiasFeitas) {
        cout << materia << endl;
    }

    cout << endl << "Inscricao de materias" << endl << "###############" << endl << "Digite 0 para sair" << endl;
    do {
        cout << "Escolha uma materia: ";
        cin >> escolha;

        if (escolha >= 1 && escolha <= static_cast<int>(materiasDisponiveis.size())) {
            if (find(materiasFeitas.begin(), materiasFeitas.end(), materiasDisponiveis[escolha - 1].getNomeMateria()) != materiasFeitas.end()) { 
                cout << "Esta materia ja foi feita. Escolha outra materia." << endl;
            } else {
                // Mostra a porcentagem de alunos matriculados após o aluno se inscrever
                cout << "Porcentagem de alunos matriculados em " << materiasDisponiveis[escolha - 1].getNomeMateria() << ": "
                    << materiasDisponiveis[escolha - 1].getPorcentagem() << "% (" << materiasDisponiveis[escolha - 1].getAlunosMatriculados().size() << "/" << materiasDisponiveis[escolha - 1].getMax() << ")" <<endl;

                /*cout << "Materia: " << materiasDisponiveis[escolha - 1].getNomeMateria() << endl;
                cout << "Professor Responsavel: " << materiasDisponiveis[escolha - 1].getProfessorResponsavel().getNome() << endl;
                cout << "Alunos Matriculados:" << endl;*/
                cout << endl << "Alunos matriculados em " << materiasDisponiveis[escolha - 1].getNomeMateria() << ":" << endl;
                for (const auto& aluno : materiasDisponiveis[escolha - 1].getAlunosMatriculados()){       
                    cout << aluno.getNome() << endl;
                }
                cout << endl;

                cout << "Confirmar a inscricao na materia: " << materiasDisponiveis[escolha - 1].getNomeMateria() << "?" << endl;
                int escolha2;
                cout << "[1]. Confirmar" << endl << "[0]. Cancelar" << endl;
                cin >> escolha2;
                switch (escolha2) {
                    case 1:
                        // Matriculando o aluno na matéria escolhida
                        materiasDisponiveis[escolha - 1].matricularAluno(aluno);
                        break;
                    case 0:
                        cout << "Matricula cancelada!" << endl;
                        break;
                    default:
                        cout << "Opcao invalida. Tente novamente." << endl;
                }
            }
        } else if (escolha == 0){
            cout << "Saindo da matricula." << endl;
        } else {
            cout << "Escolha invalida." << endl;
        }
    } while (escolha != 0);
}

/*void menuAdmin() {
    cout << "Menu do Admin!" << endl;
    
}*/

// Void responsável por continuar o menu com a escolha do usuário
void menu(int opcao) {
    switch (opcao) {
        case 1:
            //cout << "Voce escolheu a Opcao 1." << endl;
            menuAluno();
            break;
        /*case 2:
            cout << "Voce escolheu a Opcao 2." << endl;
            menuAdmin();
            break;*/
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
    cout << "[0]. Sair" << endl;

    cout << "Escolha uma opcao: ";
    cin >> opcao;

    // A continuação do menu baseado na escolha
    menu(opcao);
}