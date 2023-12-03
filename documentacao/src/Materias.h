#ifndef MATERIAS_H
#define MATERIAS_H

#include <string>
#include <vector>
#include "Professores.h"
#include "Alunos.h"

using namespace std;

class Materias {
private: 
    string nomeMateria;
    int periodo;
    Professores professorResponsavel;
    vector<Alunos> alunosMatriculados;

public:
    //Construtor
    Materias(const string& nomeMateria, int periodo, const Professores& professor);

    // Funções para trocar as variaveis privadas
    void setNomeMateria(const string& nome);
    void setPeriodo(int periodo);
    void setProfessorResponsavel (const Professores& professor);
    
    // Funções de interações dos alunos
    void matricularAluno (const Alunos& aluno);
    void desmatricularAluno (const Alunos& aluno);

    // Funções para ler e devolver os valores das variaveis privadas
    string getNomeMateria() const;
    int getPeriodo() const;
    Professores getProfessorResponsavel() const;
    vector<Alunos> getAlunosMatriculados() const;

    // Funções de inicialização
    static vector<Materias> inicializarMaterias();
};


#endif