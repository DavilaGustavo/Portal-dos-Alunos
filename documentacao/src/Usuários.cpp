#include <iostream>
#include <string>

using namespace std;

class Sistema {
private:
    // Pode adicionar membros privados se necessário
};

class Materia : public Sistema {
private:
    string nomeMateria;
    int periodoMateria;
public:
    // Adicione métodos getters e setters, se necessário
};

class RA : public Sistema {
private:
    int registro;
    int periodo;
public:
    void setRegistro(int registroTemp) {
        registro = registroTemp;
    }
    void setPeriodo(int periodoTemp) {
        periodo = periodoTemp;
    }
    int getRegistro() const {
        return registro;
    }
    int getPeriodo() const {
        return periodo;
    }
};

class Alunos : public RA {
private:
    string nome;
    string email;
public:
    void setNome(const string& nomeTemp) {
        nome = nomeTemp;
    }
    void setEmail(const string& emailTemp) {
        email = emailTemp;
    }
    string getNome() const {
        return nome;
    }
    string getEmail() const {
        return email;
    }
};

int main() {
    Alunos teste;
    teste.setNome("Gustavo");
    teste.setEmail("gustavo@gmail.com");
    teste.setRegistro(2370506);
    teste.setPeriodo(6);

    cout << "Nome: " << teste.getNome() << ", RA: " << teste.getRegistro() << ", Periodo: " << teste.getPeriodo() << endl;

    return 0;
}