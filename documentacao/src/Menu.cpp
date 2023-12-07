#include "Menu.h"
#include "Alunos.h"
#include "Materias.h"
#include <iostream>
#include <algorithm>

using namespace std;

void menuAluno(Alunos& aluno, vector<Materias>& materiasDisponiveis) {
    cout << endl << "Menu do Aluno!" << endl;

    int escolha;
    do {
        cout << endl << "Selecione uma opcao:" << endl;
        cout << "[1]. Listar materias feitas" << endl;
        cout << "[2]. Matricular em uma materia" << endl;
        cout << "[3]. Desmatricular de uma materia" << endl;
        cout << "[0]. Concluir alteracoes" << endl;

        cout << "Escolha uma opcao: ";
        cin >> escolha;

        switch (escolha) {
            case 1:
                cout << endl << "Materias feitas pelo aluno:" << endl;
                for (const auto& materia : aluno.getMateriasFeitas()) {
                    cout << materia << endl;
                }
                break;
            case 2:
                // Matricular em uma materia
                // Mostrar materias disponiveis
                cout << endl << "Materias disponiveis: " << endl;
                for (size_t i = 0; i < materiasDisponiveis.size(); ++i) {
                    cout << i + 1 << ". " << materiasDisponiveis[i].getNomeMateria() << " (" << materiasDisponiveis[i].getPeriodo() << ")" << endl;
                }

                int escolhaMateria;
                cout << "Escolha uma materia para se matricular (0 para voltar): ";
                cin >> escolhaMateria;

                if (escolhaMateria >= 1 && escolhaMateria <= static_cast<int>(materiasDisponiveis.size())) {
                    if (find(aluno.getMateriasFeitas().begin(), aluno.getMateriasFeitas().end(), materiasDisponiveis[escolhaMateria - 1].getNomeMateria()) != aluno.getMateriasFeitas().end()) {
                        cout << "Esta materia ja foi feita. Escolha outra materia." << endl;
                    } else {
                        // Mostra a porcentagem de alunos matriculados após o aluno se inscrever
                        cout << endl << "Porcentagem de alunos matriculados em " << materiasDisponiveis[escolhaMateria - 1].getNomeMateria() << ": "
                            << materiasDisponiveis[escolhaMateria - 1].getPorcentagem() << "% (" << materiasDisponiveis[escolhaMateria - 1].getAlunosMatriculados().size() << "/" << materiasDisponiveis[escolhaMateria - 1].getMax() << ")" << endl;

                        cout << endl << "Alunos matriculados em " << materiasDisponiveis[escolhaMateria - 1].getNomeMateria() << ":" << endl;
                        for (const auto& alunoMatriculado : materiasDisponiveis[escolhaMateria - 1].getAlunosMatriculados()) {
                            cout << alunoMatriculado.getNome() << endl;
                        }
                        cout << endl;

                        cout << "Confirmar a inscricao na materia: " << materiasDisponiveis[escolhaMateria - 1].getNomeMateria() << "?" << endl;
                        int escolhaConfirmacao;
                        cout << "[1]. Confirmar" << endl << "[0]. Cancelar" << endl;
                        cin >> escolhaConfirmacao;

                        switch (escolhaConfirmacao) {
                            case 1:
                                // Matricular o aluno na matéria escolhida
                                materiasDisponiveis[escolhaMateria - 1].matricularAluno(aluno);
                                break;
                            case 0:
                                cout << "Matricula cancelada!" << endl;
                                break;
                            default:
                                cout << "Opcao invalida. Tente novamente." << endl;
                        }
                    }
                } else if (escolhaMateria == 0) {
                    cout << "Voltando ao menu anterior." << endl << endl;
                } else {
                    cout << "Escolha invalida." << endl;
                }
                break;
            case 3:
                cout << endl << "Materias disponiveis: " << endl;
                for (size_t i = 0; i < materiasDisponiveis.size(); ++i) {
                    cout << i + 1 << ". " << materiasDisponiveis[i].getNomeMateria() << " (" << materiasDisponiveis[i].getPeriodo() << ")" << endl;
                }

                cout << "Escolha uma materia para se matricular (0 para voltar): ";
                cin >> escolhaMateria;

                if (escolhaMateria >= 1 && escolhaMateria <= static_cast<int>(materiasDisponiveis.size())) {
                    if (find(aluno.getMateriasFeitas().begin(), aluno.getMateriasFeitas().end(), materiasDisponiveis[escolhaMateria - 1].getNomeMateria()) != aluno.getMateriasFeitas().end()) {
                        cout << "Esta materia ja foi feita. Escolha outra materia." << endl;
                    } else {
                        cout << endl << "Alunos matriculados em " << materiasDisponiveis[escolhaMateria - 1].getNomeMateria() << ":" << endl;
                        for (const auto& alunoMatriculado : materiasDisponiveis[escolhaMateria - 1].getAlunosMatriculados()) {
                            cout << alunoMatriculado.getNome() << endl;
                        }
                        cout << endl;

                        cout << "Confirmar a retirada da matricula na materia: " << materiasDisponiveis[escolhaMateria - 1].getNomeMateria() << "?" << endl;
                        int escolhaConfirmacao;
                        cout << "[1]. Confirmar" << endl << "[0]. Cancelar" << endl;
                        cin >> escolhaConfirmacao;

                        switch (escolhaConfirmacao) {
                            case 1:
                                // Desmatricular o aluno na matéria escolhida
                                materiasDisponiveis[escolhaMateria - 1].desmatricularAluno(aluno);
                                break;
                            case 0:
                                cout << "Desmatricula cancelada!" << endl;
                                break;
                            default:
                                cout << "Opcao invalida. Tente novamente." << endl;
                        }
                    }
                } else if (escolhaMateria == 0) {
                    cout << "Voltando ao menu anterior." << endl << endl;
                } else {
                    cout << "Escolha invalida." << endl;
                }
                break;
            case 0:
                cout << "Concluindo alteracoes. Voltando ao menu principal." << endl << endl;
                return;
            default:
                cout << "Opcao invalida. Tente novamente." << endl;
        }
    } while (escolha != 0);
}

// Void responsável por chamar o menu e guardar a escolha do usuário
void chamarMenu() {
    int opcao;
    while (opcao != 0) {
    cout << "Escolha como prosseguir:" << endl;
    cout << "[1]. Aluno" << endl;
    cout << "[0]. Sair" << endl;

    cout << "Escolha uma opcao: ";
    cin >> opcao;

    // A continuação do menu baseado na escolha
    menu(opcao);
    }
}

void chamarMenuAluno() {
    // Usa uma variável estática para armazenar o objeto aluno
    static Alunos aluno("", "", 0, 0);

    // Usa uma variável estática para armazenar as matérias disponíveis
    static vector<Materias> materiasDisponiveis = Materias::inicializarMaterias();

    // Verifica se o nome do aluno está vazio para determinar se é a primeira vez que a função é chamada
    if (aluno.getNome().empty()) {
        string nome, email;
        int RA, periodo;

        cout << endl << "Digite seu nome: ";
        cin.ignore(); // Limpar o buffer antes de usar o getline
        getline(cin, nome);

        cout << "Digite seu email: ";
        getline(cin, email);

        cout << "Digite seu RA: ";
        cin >> RA;

        cout << "Digite seu periodo: ";
        cin >> periodo;

        // Atribui os valores coletados ao objeto aluno
        aluno.setNome(nome);
        aluno.setEmail(email);
        aluno.setRA(RA);
        aluno.setPeriodo(periodo);
    }

    menuAluno(aluno, materiasDisponiveis);
}

// Void responsável por continuar o menu com a escolha do usuário
void menu(int opcao) {
    switch (opcao) {
        case 1:
            //cout << "Voce escolheu a Opcao 1." << endl;
            chamarMenuAluno();
            break;
        /*case 2:
            cout << "Voce escolheu a Opcao 2." << endl;
            menuAdmin();
            break;*/
        case 0:
            cout << endl << "Saindo do programa." << endl;
            break;
        default:
            cout << "Opcao invalida. Tente novamente." << endl;
    }
}