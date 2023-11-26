#include "Professores.h"

// Construtor
Professores::Professores(const string& nome, const string& email)
        : nome(nome), email(email){

        }

// Metodos de Acesso

void Professores::setNome(const string& nome){
    this->nome = nome;
}

void Professores::setEmail(const string& email){
    this->email = email;
}

void Professores::adicionarMaterias(const string& materia){
    materias.push_back(materia);
}

string Professores::getNome() const{
    return nome;
}

string Professores::getEmail() const{
    return email;
}

vector<string> Professores::getMaterias() const{
    return materias;
}
