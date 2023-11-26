#ifndef PROFESSORES_H
#define PROFESSORES_H

#include <string>
#include <vector>

using namespace std;

class Professores{
private:
    string nome;
    string email;
    vector<string> materias; // vetor para armazenar múltiplas matérias

public:
    // Construtor
    Professores(const string& nome, const string& email);

    // Método de Acesso
    void setNome(const string& nome);
    void setEmail(const string& email);
    void adicionarMaterias(const string& materia);

    string getNome() const;
    string getEmail() const;
    vector<string> getMaterias() const;
};

#endif