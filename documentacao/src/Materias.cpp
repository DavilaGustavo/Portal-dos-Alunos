#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Materias.h"
#include "Professores.h"
#include <algorithm>

using namespace std;

// Construtor
Materias::Materias(const string& nomeMateria, int periodo, const Professores& professor, const vector<Alunos>& alunos)
    : nomeMateria(nomeMateria), periodo(periodo), professorResponsavel(professor), alunosMatriculados(alunos) {}

void Materias::setNomeMateria(const string& nomeMateria){
    this->nomeMateria = nomeMateria;
}

void Materias::setPeriodo(int periodo){
    this->periodo = periodo;
}

void Materias::setProfessorResponsavel(const Professores& professor){
    this->professorResponsavel = professor;
}

bool Materias::verificarRestricaoPeriodo(int periodoAluno, int periodoMateria) const {
    // Defina o limite de períodos superiores permitidos
    const int limiteSuperior = 2;

    // Verifique se o período da matéria está dentro do intervalo permitido
    if (periodoMateria > (periodoAluno + 2))
        return 0;
    else
        return 1;
}

void Materias::matricularAluno(const Alunos& aluno){
    if (!verificarRestricaoPeriodo(aluno.getPeriodo(), periodo)){
        cout << endl << "Restricao de periodo!" << endl;
    } else if (alunosMatriculados.size() == maxAlunos){
        cout << endl << "Maximo de alunos permitidos!" << endl;
    } else if (verificarAlunoMatriculado(aluno)) {
        cout << endl << "Aluno ja esta matriculado nesta materia!" << endl;
    } else {
        alunosMatriculados.push_back(aluno);
        cout << endl << "Aluno matriculado!" << endl;
    }
}

bool Materias::verificarAlunoMatriculado(const Alunos& aluno) const {
    return find_if(alunosMatriculados.begin(), alunosMatriculados.end(),
                   [aluno](const Alunos& a) {
                       return a.getRA() == aluno.getRA();
                   }) != alunosMatriculados.end();
}

void Materias::desmatricularAluno(const Alunos& aluno){
    if (!verificarAlunoMatriculado(aluno)) {
        cout << "O aluno nao esta matriculado nessa disciplina!" << endl;
    }
    else {
    alunosMatriculados.erase(remove_if(alunosMatriculados.begin(), alunosMatriculados.end(),
                                        [aluno](const Alunos& RA){
                                            return RA.getRA() == aluno.getRA();
                                            }),alunosMatriculados.end());
        cout << endl << "Aluno desmatriculado!" << endl;
    }
}

string Materias::getNomeMateria() const{
    return nomeMateria;
}

int Materias::getPeriodo() const{
    return periodo;
}

Professores Materias::getProfessorResponsavel() const{
    return professorResponsavel;
}

vector <Alunos> Materias::getAlunosMatriculados() const{
    return alunosMatriculados;
}

int Materias::getMax() const{
    return maxAlunos;
}

float Materias::getPorcentagem() const{
    //cout << "chegou aqui" << alunosMatriculados.size() << endl;
    if (alunosMatriculados.size() != 0)
        return 100.0f * (alunosMatriculados.size()) / maxAlunos;
    else
        return 0;
}

// Função auxiliar para gerar nomes aleatórios com sobrenomes
string gerarNomeAleatorio() {
    // Lista de nomes possíveis
    std::vector<std::string> nomes = {
        "Ana", "Carlos", "David", "Eva", "Fernanda",
        "Gabriel", "Heloisa", "Igor", "Julia", "Kai",
        "Larissa", "Miguel", "Natalia", "Otavio", "Paula",
        "Emily", "Rafael", "Sofia", "Thiago", "Ursula",
        "Arthur", "Beatriz", "Caio", "Diana", "Eduardo",
        "Fernanda", "Gustavo", "Helena", "Isaac", "Juliana",
        "Lucas", "Maria", "Nicolas", "Olivia", "Pedro",
        "Rafaela", "Samuel", "Tatiane", "Vinicius", "Yasmin",
        "Zelia", "Adriano", "Bianca", "Cesar", "Daniela",
        "Erick"
    };

    // Lista de sobrenomes comuns
    std::vector<std::string> sobrenomes = {
        "Silva", "Santos", "Oliveira", "Pereira", "Lima",
        "Fernandes", "Costa", "Rodrigues", "Almeida", "Nunes",
        "Martins", "Lopes", "Gomes", "Carvalho", "Mendes",
        "Barbosa", "Ferreira", "Ribeiro", "Souza", "Dias",
        "Castro", "Fernando", "Pinto", "Goncalves", "Monteiro",
        "Correia", "Moraes", "Cavalcanti", "Duarte", "Mello",
        "Siqueira", "Leal", "Dantas", "Cardoso", "Rocha",
        "Nogueira", "Guimaraes", "Freitas", "Machado", "Borges",
        "Vieira", "Lima", "Miranda", "Bastos", "Sales",
        "Ramos", "Correa"
    };

    // Inicializa a semente do gerador de números aleatórios apenas uma vez
    static bool seedInitialized = false;
    if (!seedInitialized) {
        srand(static_cast<unsigned int>(time(0)));
        seedInitialized = true;
    }

    // Escolhe um nome aleatório da lista
    string nome = nomes[rand() % nomes.size()];

    // Escolhe um sobrenome aleatório da lista
    string sobrenome = sobrenomes[rand() % sobrenomes.size()];

    // Combina nome e sobrenome
    return nome + " " + sobrenome;
}

// Função para inicializar um vetor de Alunos com nomes aleatórios
vector<Alunos> inicializarAlunosAleatorios(int quantidade) {
    vector<Alunos> alunos;

    for (int i = 0; i < quantidade; ++i) {
        string nome = gerarNomeAleatorio();
        string email = nome + "@gmail.com";
        int RA = 2300000 + i;
        int periodo = 1 + i % 10;

        alunos.emplace_back(nome, email, RA, periodo);
    }

    return alunos;
}

// Inicializador de matérias e professores
vector<Materias> Materias::inicializarMaterias(){
    int numAlunosAleatorio = rand() % 35 + 10; // Garante que não ultrapasse 44
    vector<Alunos> alunosAleatorios = inicializarAlunosAleatorios(numAlunosAleatorio);

    Professores Alexandre_Giron ("Alexandre Augusto Giron", "alexandregiron@utfpr.edu.br");
    Professores Cassius_Aguiar ("Cassius Rossi de Aguiar", "cassiusaguiar@utfpr.edu.br");
    Professores Mauricio_Zardo ("Mauricio Zardo Oliveira", "mauricioz@utfpr.edu.br");
    Professores Ricardo_Tavares ("Ricardo Tavares", "ricardo103@professores.utfpr.edu.br");
    Professores Gustavo_Paetzold ("Gustavo Paetzold", "gustavo103@professores.utfpr.edu.br");
    Professores Sidgley_Camargo ("Sidgley Camargo", "sidgley002@professores.utfpr.edu.br");
    Professores Jocelaine_Cargnelutti ("Jocelaine Cargnelutti", "jocelaine03@professores.utfpr.edu.br");

    return {
        Materias ("Computacao Grafica", 9, Sidgley_Camargo, alunosAleatorios),
        Materias ("Circuitos Digitais", 5, Mauricio_Zardo, alunosAleatorios),
        Materias ("Engenharia de Software", 5, Alexandre_Giron, alunosAleatorios),
        Materias ("Compiladores", 6, Alexandre_Giron, alunosAleatorios),
        Materias ("Eletronica Analogica A", 5, Cassius_Aguiar, alunosAleatorios),
        Materias ("Circuitos Eletricos", 4, Cassius_Aguiar, alunosAleatorios),
        Materias ("Matematica Discreta", 1, Gustavo_Paetzold, alunosAleatorios),
        Materias ("Logica para Computacao", 2, Gustavo_Paetzold, alunosAleatorios),
        Materias ("Estrutura de Dados", 3, Ricardo_Tavares, alunosAleatorios), 
        Materias ("Banco de Dados", 5, Sidgley_Camargo, alunosAleatorios),
        Materias ("Equacoes Diferenciais Ordinarias", 3, Jocelaine_Cargnelutti, alunosAleatorios)
    };
}

