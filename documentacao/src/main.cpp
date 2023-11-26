#include <iostream>
#include "Alunos.h"
#include "Professores.h"

using namespace std;

int main() {
    Alunos aluno("Gabriel Duarte", "gabrielduarte@alunos.utfpr.edu.br", 2382945, 5);
    Professores professor("Ricardo Tavares", "ricardo103@professores.utfpr.edu.br", "Estrutura de Dados");

    cout << "Nome: " << aluno.getNome() << endl;
    cout << "Email: " << aluno.getEmail() << endl;
    cout << "RA: " << aluno.getRA()  << endl;
    cout << "Periodo: " << aluno.getPeriodo() << endl;
    cout << endl;
    cout << "Nome: " << professor.getNome() << endl;
    cout << "Email: " << professor.getEmail() << endl;
    cout << "Materia dada: " << professor.getMateria() << endl;


    return 0;
}