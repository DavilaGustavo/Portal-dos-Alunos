#include <iostream>
#include "Alunos.h"

using namespace std;

int main() {
    Alunos aluno("Gabriel", "gabrielduarte@alunos.utfpr.edu.br", 2382945, 5);

    cout << "Nome: " << aluno.getNome() << endl;
    cout << "Email: " << aluno.getEmail() << endl;
    cout << "RA: " << aluno.getRA()  << endl;
    cout << "Periodo: " << aluno.getPeriodo() << endl;

    return 0;
}