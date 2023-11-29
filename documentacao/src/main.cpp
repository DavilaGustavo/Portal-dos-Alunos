#include <iostream>
#include "Alunos.h"
#include "Professores.h"
#include "Materias.h"

using namespace std;

int main() {
    Alunos aluno("Gabriel Duarte", "gabrielduarte@alunos.utfpr.edu.br", 2382945, 5);
    Alunos aluno1("Gustavo D'avlia", "gustavin123@gmail.com", 112358 , 5);
    Alunos aluno2("Augusto Barth", "augustin123@gmail.com", 112358 , 5);
    Professores professor("Ricardo Tavares", "ricardo103@professores.utfpr.edu.br");

    Materias materia("Estrutura de Dados", 3, professor);
    Materias materiaComp("Teoria da Computacao", 5, professor);

    materia.adicionarAluno(aluno);
    materia.adicionarAluno(aluno1);

    materiaComp.adicionarAluno(aluno);
    materiaComp.adicionarAluno(aluno2);
    
    
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

    
    cout << endl;


    cout << "Materia: " << materiaComp.getNomeMateria() << endl << "Periodo: " << materiaComp.getPeriodo() << endl;
    cout << "Professor Responsavel: " << materiaComp.getProfessorResponsavel().getNome() << endl;
    cout << "Alunos Matriculados:" << endl;
    for (const auto& aluno : materiaComp.getAlunosMatriculados()){
        cout << aluno.getNome() << endl;
    }

    cout << endl;

    //cout << "Materia dada: " << professor.getMateria() << endl;


    return 0;
}