#ifndef ALUNOS_H
#define ALUNOS_H

#include <string>
#include <vector>

using namespace std;

// Classe responsável por armazenar as informações dos alunos
class Alunos {
private:
    string nome;
    string email;
    int RA;
    int periodo;
    vector<string> materiasFeitas;

public:
    // Construtor
    Alunos(const string& nome, const string& email, int RA, int periodo);

    // Funções para trocar as variaveis privadas
    void setNome(const string& nome);
    void setEmail(const string& email);
    void setRA(int RA);
    void setPeriodo(int periodo);

    // Funções para ler e devolver os valores das variaveis privadas
    string getNome () const;
    string getEmail() const;
    int getRA() const;
    int getPeriodo() const;

    // Funções relacionadas as matérias feitas pelo aluno
    void adicionarMateriaFeita(const string& materia);
    vector <string> getMateriasFeitas() const;

    // Método para permitir inserção de informações após a criação do objeto
    void fazerLogin(const string& nome, const string& email, int RA, int periodo);
};

#endif