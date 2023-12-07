#include <iostream>
#include "Materias.h"
#include "Professores.h"
#include <algorithm>

using namespace std;

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

bool Materias::verificarRestricaoPeriodo(int periodoAluno, int periodoMateria) const {
    // Defina o limite de períodos superiores permitidos
    const int limiteSuperior = 2;

    // Verifique se o período da matéria está dentro do intervalo permitido
    return (periodoAluno - periodoMateria) >= 0 && (periodoAluno - periodoMateria) <= limiteSuperior;
}

void Materias::matricularAluno(const Alunos& aluno){
    if (verificarRestricaoPeriodo(aluno.getPeriodo(), periodo)){
        alunosMatriculados.push_back(aluno);
        cout << "Aluno matriculado" << endl;
    } else {
        cout << "O aluno nao pode se matricular nesta materia: restricao de periodo" << endl;
    }
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

    return {
    Materias ("Matematica Discreta", 1, Gustavo_Paetzold),
    Materias ("Logica para Computacao", 2, Gustavo_Paetzold),
    Materias ("Estrutura de Dados", 3, Ricardo_Tavares), 
    Materias ("Banco de Dados", 5, Sidgley_Camargo),
    Materias ("Equacoes Diferenciais Ordinarias", 3, Jocelaine_Cargnelutti)
    };
}

