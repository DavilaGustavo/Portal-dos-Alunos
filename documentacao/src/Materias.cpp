#include "Materias.h"
#include "Professores.h"
#include <algorithm>

// Construtor
Materias::Materias(const string& nomeMateria, int periodo, const Professores& professor)
    : nomeMateria(nomeMateria), periodo(periodo), professorResponsavel(professor){}

void Materias::setNomeMateria(const string& nomeMateria){
    this->nomeMateria = nomeMateria;
}

void Materias::setPeriodo(int periodo){
    this->periodo = periodo;
}

void Materias::setProfessorResponsavel(const Professores& professor){
    this->professorResponsavel = professor;
}

void Materias::matricularAluno(const Alunos& aluno){
    alunosMatriculados.push_back(aluno);
}

void Materias::desmatricularAluno(const Alunos& aluno){
    alunosMatriculados.erase(remove_if(alunosMatriculados.begin(), alunosMatriculados.end(),
                                        [aluno](const Alunos& RA){
                                            return RA.getRA() == aluno.getRA();
                                        }),alunosMatriculados.end());
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

// Inicializador de matérias e professores
vector<Materias> Materias::inicializarMaterias(){
    Professores Ricardo_Tavares ("Ricardo Tavares", "ricardo103@professores.utfpr.edu.br");
    Professores Gustavo_Paetzold ("Gustavo Paetzold", "gustavo103@professores.utfpr.edu.br");
    Professores Sidgley_Camargo ("Sidgley Camargo", "sidgley002@professores.utfpr.edu.br");
    Professores Jocelaine_Cargnelutti("Jocelaine Cargnelutti", "jocelaine03@professores.utfpr.edu.br");

    Materias Matematica_Discreta ("Matematica Discreta", 1, Gustavo_Paetzold);
    Materias Logica_Comp ("Logica para Computacao", 2, Gustavo_Paetzold);
    Materias Estrutura_de_Dados ("Estrutura de Dados", 3, Ricardo_Tavares); 
    Materias BD ("Banco de Dados", 5, Sidgley_Camargo);
    Materias EDO ("Equacoes Diferenciais Ordinarias", 3, Jocelaine_Cargnelutti);

    return {Matematica_Discreta,Logica_Comp, Estrutura_de_Dados, BD, EDO};
}

