#include "Alunos.h"

// Construtor
Alunos::Alunos(const string& nome, const string& email, int RA, int periodo)
    : nome(nome), email(email), RA(RA), periodo(periodo){}

// Funções para trocar as variaveis privadas
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

// Funções para ler e devolver os valores das variaveis privadas
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

void Alunos::adicionarMateriaFeita(const string& materia){
    materiasFeitas.push_back(materia);
}

vector<string> Alunos::getMateriasFeitas() const {
    return materiasFeitas;
}

// Método para permitir inserção de informações após a criação do objeto

void Alunos::fazerLogin(const string& nome, const string& email, int RA, int periodo){
    this->nome = nome;
    this->email = email;
    this->RA = RA;
    this->periodo = periodo;
}