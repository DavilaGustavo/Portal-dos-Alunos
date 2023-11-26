#include "Professores.h"

// Construtor
Professores::Professores(const string& nome, const string& email, const string& materia)
        : nome(nome), email(email), materia(materia){

        }

// Metodos de Acesso

void Professores::setNome(const string& nome){
    this->nome = nome;
}

void Professores::setEmail(const string& email){
    this->email = email;
}

void Professores::setMateria(const string& materia){
    this->materia = materia;
}

string Professores::getNome() const{
    return nome;
}

string Professores::getEmail() const{
    return email;
}

string Professores::getMateria() const{
    return materia;
}
