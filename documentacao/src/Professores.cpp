#include "Professores.h"

// Construtor
Professores::Professores(const string& nome, const string& email)
        : nome(nome), email(email){}

// Funções para trocar as variaveis privadas
void Professores::setNome(const string& nome){
    this->nome = nome;
}
void Professores::setEmail(const string& email){
    this->email = email;
}
void Professores::adicionarMaterias(const string& materia){
    materias.push_back(materia);
}
    
// Funções para ler e devolver os valores das variaveis privadas
string Professores::getNome() const{
    return nome;
}
string Professores::getEmail() const{
    return email;
}
vector<string> Professores::getMaterias() const{
    return materias;
}
