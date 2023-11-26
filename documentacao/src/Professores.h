#ifndef PROFESSORES_H
#define PROFESSORES_H

#include <string>

using namespace std;

class Professores{
private:
    string nome;
    string email;
    string materia;

public:
    // Construtor
    Professores(const string& nome, const string& email, const string& materia);

    // Método de Acesso
    void setNome(const string& nome);
    void setEmail(const string& email);
    void setMateria(const string& materia);

    string getNome() const;
    string getEmail() const;
    string getMateria() const;
};

#endif