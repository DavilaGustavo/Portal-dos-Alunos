#ifndef PROFESSORES_H
#define PROFESSORES_H

#include <string>
#include <vector>

using namespace std;

// Classe responsável por armazenar as informações dos professores
class Professores{
private:
    string nome;
    string email;
    vector<string> materias;            // vetor para armazenar múltiplas matérias

public:
    // Construtor
    Professores(const string& nome, const string& email);

    // Funções para trocar as variaveis privadas
    void setNome(const string& nome);
    void setEmail(const string& email);
    void adicionarMaterias(const string& materia);

    // Funções para ler e devolver os valores das variaveis privadas
    string getNome() const;
    string getEmail() const;
    vector<string> getMaterias() const;
};

#endif