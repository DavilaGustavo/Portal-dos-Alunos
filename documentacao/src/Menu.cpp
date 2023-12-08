#include "Menu.h"
#include "Alunos.h"
#include "Materias.h"
#include <iostream>
#include <algorithm>

using namespace std;

void menuAluno(Alunos& aluno, vector<Materias>& materiasDisponiveis) {
    system("cls");
    cout << endl << "Menu do Aluno!" << endl;

    int escolha;
    do {
        system("cls");
        cout << endl << "Selecione uma opcao:" << endl;
        cout << "[1]. Listar materias feitas" << endl;
        cout << "[2]. Matricular em uma materia" << endl;
        cout << "[3]. Desmatricular de uma materia" << endl;
        cout << "[4]. Informacoes das materias" << endl;
        cout << "[0]. Concluir alteracoes" << endl;

        cout << "Escolha uma opcao: ";
        cin >> escolha;

        system("cls");

        switch (escolha) {
            int i;
            case 1:
            {
                const auto& materiasFeitas = aluno.getMateriasFeitas();

                if (materiasFeitas.empty()) {
                    cout << endl << "O aluno ainda nao concluiu nenhuma materia." << endl;
                    for (i = 0; i < materiasDisponiveis.size(); ++i) {
                        cout << i + 1 << ". " << materiasDisponiveis[i].getNomeMateria() << " (" << materiasDisponiveis[i].getPeriodo() << ")" << endl;
                    }

                    int escolhaMateria;
                    cout << endl << "[1-" << i << "]. Escolha uma materia que foi concluida" << endl << "[0]. Voltar" << endl;
                    do {
                        cin >> escolhaMateria;

                        if (escolhaMateria >= 1 && escolhaMateria <= static_cast<int>(materiasDisponiveis.size())) {
                            // Adicione a lógica para marcar a matéria como feita para o aluno
                            if(aluno.getPeriodo() >= (materiasDisponiveis[escolhaMateria - 1].getPeriodo() - 2)){
                                aluno.adicionarMateriaFeita(materiasDisponiveis[escolhaMateria - 1].getNomeMateria());
                                cout << "Materia marcada como concluida!" << endl;
                            } else {
                                cout << "Nao e possivel adicionar essa materia devido ao seu periodo!" << endl;
                            }
                        } else if (escolhaMateria == 0) {
                            cout << "Voltando ao menu anterior." << endl;
                        } else {
                            cout << "Escolha invalida." << endl;
                        }

                    } while (escolhaMateria != 0);

                } else {
                    cout << endl << "Materias feitas pelo aluno:" << endl;
                    for (const auto& materia : materiasFeitas) {
                        cout << materia << endl;
                    }
                    cout << endl;
                    system("pause");
                }
                break;
            }
            case 2:
                cout << endl << "Materias disponiveis: " << endl;
                for (i = 0; i < materiasDisponiveis.size(); ++i) {
                    cout << i + 1 << ". " << materiasDisponiveis[i].getNomeMateria() << " (" << materiasDisponiveis[i].getPeriodo() << ")" << endl;
                }

                int escolhaMateria;
                cout << endl << "[1-" << i << "]. Escolha uma materia para se matricular" << endl << "[0]. Voltar" << endl;
                cin >> escolhaMateria;

                if (escolhaMateria >= 1 && escolhaMateria <= static_cast<int>(materiasDisponiveis.size())) {                    
                    vector<string> materiasFeitas = aluno.getMateriasFeitas();
                    if (find(materiasFeitas.begin(), materiasFeitas.end(), materiasDisponiveis[escolhaMateria - 1].getNomeMateria()) != materiasFeitas.end()) {
                        cout << endl << "Esta materia ja foi feita. Nao e possivel desmatricular" << endl;
                        system("pause");
                    } else {
                        cout << endl << "Porcentagem de alunos matriculados em " << materiasDisponiveis[escolhaMateria - 1].getNomeMateria() << ": "
                        << materiasDisponiveis[escolhaMateria - 1].getPorcentagem() << "% (" << materiasDisponiveis[escolhaMateria - 1].getAlunosMatriculados().size() 
                        << "/" << materiasDisponiveis[escolhaMateria - 1].getMax() << ")" << endl;

                        cout << "Confirmar a inscricao na materia: " << materiasDisponiveis[escolhaMateria - 1].getNomeMateria() << "?" << endl;
                        int escolhaConfirmacao;
                        cout << "[1]. Confirmar" << endl << "[0]. Voltar" << endl;
                        cin >> escolhaConfirmacao;

                        switch (escolhaConfirmacao) {
                            case 1:
                                // Matricular o aluno na matéria escolhida
                                materiasDisponiveis[escolhaMateria - 1].matricularAluno(aluno);
                                system("pause");
                                break;
                            case 0:
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
                for (i = 0; i < materiasDisponiveis.size(); ++i) {
                    cout << i + 1 << ". " << materiasDisponiveis[i].getNomeMateria() << " (" << materiasDisponiveis[i].getPeriodo() << ")" << endl;
                }

                cout << endl << "[1-" << i << "]. Escolha uma materia para se desmatricular" << endl << "[0]. Voltar" << endl;
                cin >> escolhaMateria;

                if (escolhaMateria >= 1 && escolhaMateria <= static_cast<int>(materiasDisponiveis.size())) {
                    vector<string> materiasFeitas = aluno.getMateriasFeitas();
                    if (find(materiasFeitas.begin(), materiasFeitas.end(), materiasDisponiveis[escolhaMateria - 1].getNomeMateria()) != materiasFeitas.end()) {
                        cout << endl << "Esta materia ja foi feita. Nao e possivel desmatricular" << endl;
                        system("pause");
                    } else {
                        cout << endl << "Porcentagem de alunos matriculados em " << materiasDisponiveis[escolhaMateria - 1].getNomeMateria() << ": "
                        << materiasDisponiveis[escolhaMateria - 1].getPorcentagem() << "% (" << materiasDisponiveis[escolhaMateria - 1].getAlunosMatriculados().size() 
                        << "/" << materiasDisponiveis[escolhaMateria - 1].getMax() << ")" << endl;
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
            case 4:     
                int escolhaMateriaLista;                        
                do {
                    system("cls");
                    cout << endl << "Todas as materias: " << endl;
                    for (i = 0; i < materiasDisponiveis.size(); ++i) {
                        cout << i + 1 << ". " << materiasDisponiveis[i].getNomeMateria() << " (" << materiasDisponiveis[i].getPeriodo() << ")" << endl;
                    }
                
                    cout << endl << "[1-" << i << "]. Escolha uma materia" << endl << "[0]. Voltar" << endl;
                    cin >> escolhaMateriaLista;

                    if (escolhaMateriaLista == 0)
                        break;

                    system("cls");
                    cout << endl << "Materia: " << materiasDisponiveis[escolhaMateriaLista - 1].getNomeMateria() << endl;
                    cout << "Professor Responsavel: " << materiasDisponiveis[escolhaMateriaLista - 1].getProfessorResponsavel().getNome() << endl;
                    cout << "Porcentagem de alunos matriculados em " << materiasDisponiveis[escolhaMateriaLista - 1].getNomeMateria() << ": "
                    << materiasDisponiveis[escolhaMateriaLista - 1].getPorcentagem() << "% (" << materiasDisponiveis[escolhaMateriaLista - 1].getAlunosMatriculados().size() 
                    << "/" << materiasDisponiveis[escolhaMateriaLista - 1].getMax() << ")" << endl;
                    
                    int escolhaAlunos;
                    cout << endl << "[1]. Mostrar alunos matriculados" << endl << "[0]. Cancelar" << endl;
                    cin >> escolhaAlunos;

                    switch (escolhaAlunos) {
                        case 1:
                            // Mostrar alunos matriculados
                            cout << endl << "Alunos matriculados em " << materiasDisponiveis[escolhaMateriaLista - 1].getNomeMateria() << ":" << endl;
                            for (const auto& alunoMatriculado : materiasDisponiveis[escolhaMateriaLista - 1].getAlunosMatriculados()) {
                                cout << alunoMatriculado.getNome() << endl;
                            }
                            cout << endl;
                            system("pause");
                            break;
                        case 0:
                            break;
                        default:
                            cout << "Opcao invalida. Tente novamente." << endl;
                    }
                }  while(escolhaMateriaLista != 0);
                break;
            case 0:
                break;
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
    system("cls");
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
    system("cls");
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
