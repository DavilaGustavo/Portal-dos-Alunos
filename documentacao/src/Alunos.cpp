#include "Alunos.h"

// Construtor
Alunos::Alunos(const string& nome, const string& email, int RA, int periodo)
    : nome(nome), email(email), RA(RA), periodo(periodo){
        // Lógica de inicialização
    }

    // Métodos de acesso
void Alunos::setNome(const string& nome){
    this->nome = nome;
}

void Alunos::setEmail(const string& email){
    this->email = email;
}

void Alunos::setRA(int RA){
    this->RA = RA;  
}

void Alunos::setPeriodo(int periodo){
    this->periodo = periodo;
}

string Alunos::getNome() const{
    return nome;
}

string Alunos::getEmail() const{
    return email;
}

int Alunos::getRA() const{
    return RA;
}

int Alunos::getPeriodo() const{
    return periodo;
}

