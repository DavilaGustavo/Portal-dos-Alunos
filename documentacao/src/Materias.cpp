#include "Materias.h"

// Construtor
Materias::Materias(const string& nomeMateria, int periodo, const Professores& professor)
    : nomeMateria(nomeMateria), periodo(periodo), professorResponsavel(professor){
        // Lógica de inicialização, se necessário
    }

void Materias::setNomeMateria(const string& nomeMateria){
    this->nomeMateria = nomeMateria;
}

void Materias::setPeriodo(int periodo){
    this->periodo = periodo;
}

void Materias::setProfessorResponsavel(const Professores& professor){
    this->professorResponsavel = professor;
}

void Materias::adicionarAluno(const Alunos& aluno){
    alunosMatriculados.push_back(aluno);
}

string Materias::getNomeMateria() const{
    return nomeMateria;
}
int Materias::getPeriodo() const{
    return periodo;
}

Professores Materias::getProfessorResponsavel() const{
    return professorResponsavel;
}

vector <Alunos> Materias::getAlunosMatriculados() const{
    return alunosMatriculados;
}