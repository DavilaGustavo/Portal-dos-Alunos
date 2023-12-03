#include <iostream>
#include "Alunos.h"
#include "Professores.h"
#include "Materias.h"
#include "Menu.h"

using namespace std;

int main() {
    chamarMenu();

    // Inicializando as classes aluno/professor com informações a fim de teste
    Alunos aluno("Gabriel Duarte", "gabrielduarte@alunos.utfpr.edu.br", 2382945, 5);
    Alunos aluno1("Gustavo D'avlia", "gustavin123@gmail.com", 112358, 5);
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

        cout << "Materia: " << materiasDisponiveis[escolha - 1].getNomeMateria() << endl;
        cout << "Professor Responsavel: " << materiasDisponiveis[escolha - 1].getProfessorResponsavel().getNome() << endl;
    } else {
        cout << "Escolha invalida." << endl;
    }










    /*Alunos aluno2("Augusto Barth", "augustin123@gmail.com", 112358 , 5);
    Professores professor("Ricardo Tavares", "ricardo103@professores.utfpr.edu.br");

    Materias materia("Estrutura de Dados", 3, professor);
    Materias materiaComp("Teoria da Computacao", 5, professor);

    materia.matricularAluno(aluno);
    materia.matricularAluno(aluno1);    
    
    cout << "Nome: " << aluno.getNome() << endl;
    cout << "Email: " << aluno.getEmail() << endl;
    cout << "RA: " << aluno.getRA()  << endl;
    cout << "Periodo: " << aluno.getPeriodo() << endl;
    
    cout << endl;
    
    cout << "Materia: " << materia.getNomeMateria() << endl << "Periodo: " << materia.getPeriodo() << endl;
    cout << "Professor Responsavel: " << materia.getProfessorResponsavel().getNome() << endl;
    cout << "Alunos Matriculados:" << endl;
    for (const auto& aluno : materia.getAlunosMatriculados()){
        cout << aluno.getNome() << endl;
    }
*/
    
    cout << endl;

    return 0;
}