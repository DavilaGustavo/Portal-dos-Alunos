#ifndef ALUNOS_H
#define ALUNOS_H

#include <string>

using namespace std;

class Alunos {
private:
    string nome;
    string email;
    int RA;
    int periodo;

public:
    // Construtor
    Alunos(const string& nome, const string& email, int RA, int periodo);

    // Métodos de Acesso
    void setNome(const string& nome);
    void setEmail(const string& email);
    void setRA(int RA);
    void setPeriodo(int periodo);

    string getNome () const;
    string getEmail() const;
    int getRA() const;
    int getPeriodo() const;
};


#endif