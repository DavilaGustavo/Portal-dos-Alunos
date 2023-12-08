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
    Professores Alexandre_Giron ("Alexandre Augusto Giron", "alexandregiron@utfpr.edu.br");
    Professores Marcia_Regina ("Marcia Regina", "marciaregina@utfpr.edu.br");
    Professores Ronaldo_Rodrigues ("Ronaldo Rodrigues", "ronaldorodrigues@utfpr.edu.br");
    Professores Marcello_Talarico ("Marcello Talarico", "marcellotalarico@utfpr.edu.br");
    Professores Daniel_Cavalcanti ("Daniel Cavalcanti", "danielcavalcanti@utfpr.edu.br");
    Professores Raquel_Ribeiro ("Raquel Ribeiro", "raquelribeiro@utfpr.edu.br");
    Professores Sergio_Flavio ("Sergio Flavio", "sergioflavio@utfpr.edu.br");
    Professores Suellen_Ribeiro ("Suellen Ribeiro", "suellenribeiro@utfpr.edu.br");
    Professores Leonardo_Lima ("Leonardo Lima", "leonardolima@utfpr.edu.br");
    Professores Cassius_Aguiar ("Cassius Rossi de Aguiar", "cassiusaguiar@utfpr.edu.br");
    Professores Mauricio_Zardo ("Mauricio Zardo Oliveira", "mauricioz@utfpr.edu.br");
    Professores Ricardo_Tavares ("Ricardo Tavares", "ricardo103@professores.utfpr.edu.br");
    Professores Gustavo_Paetzold ("Gustavo Paetzold", "gustavo103@professores.utfpr.edu.br");
    Professores Sidgley_Camargo ("Sidgley Camargo", "sidgley002@professores.utfpr.edu.br");
    Professores Jocelaine_Cargnelutti ("Jocelaine Cargnelutti", "jocelaine03@professores.utfpr.edu.br");
    Professores Pablo_Chang ("Pablo Chang", "pablochang@professores.utfpr.edu.br");
    Professores Gustavo_Dalposso ("Gustavo Dalposso", "gustavodalposso@professores.utfpr.edu.br");
    Professores Gerson_Filippini ("Gerson Filippini", "gersonfilippini@professores.utfpr.edu.br");
    Professores Evandro_Kolling ("Evandro Kolling", "evandrokolling@professores.utfpr.edu.br");
    Professores Eduardo_Vinicius ("Eduardo Vinicius", "eduardovinicius@professores.utfpr.edu.br");
    Professores Diane_Aparecida ("Diane Aparecida", "dianeaparecida@professores.utfpr.edu.br");
    Professores Luis_Carlos ("Luis Carlos", "luiscarlos@professores.utfpr.edu.br");
    Professores Tiago_Piovesan ("Tiago Piovesan", "tiagopiovesan@professores.utfpr.edu.br");
    Professores Jose_Dolores ("Jose Dolores", "josedolores@professores.utfpr.edu.br");
    Professores Alessandro_Paulo ("Alessandro Paulo", "alessandropaulo@professores.utfpr.edu.br");
    Professores Alvaro_Ricieri ("Alvaro Ricieri", "alvaroricieri@professores.utfpr.edu.br");
    Professores Osni_Hoss ("Osni Hoss", "osnihoss@professores.utfpr.edu.br");
    Professores Sandra_Regina ("Sandra Regina", "sandraregina@professores.utfpr.edu.br");
    Professores Elder_Elisandro ("Elder Elisandro", "elderelisandro@professores.utfpr.edu.br");
    Professores Rosangela_Aparecida ("Rosangela Aparecida", "rosangelaaparecida@professores.utfpr.edu.br");
    Professores Dione_Ines ("Dione_Ines", "dioneines@professores.utfpr.edu.br");
    Professores Ernesto_Osvaldo ("Ernesto Osvaldo", "ernestoosvaldo@professores.utfpr.edu.br");


    return {
        // 1º Periodo
        Materias ("Introducao a Engenharia", 1, Cassius_Aguiar, inicializarAlunosAleatorios(rand() % 40 + 5)),
        Materias ("Calculo 1", 1, Marcia_Regina, inicializarAlunosAleatorios(rand() % 40 + 5)),
        Materias ("Geometria Analitica", 1, Ronaldo_Rodrigues, inicializarAlunosAleatorios(rand() % 40 + 5)),
        Materias ("Matematica Discreta", 1, Gustavo_Paetzold, inicializarAlunosAleatorios(rand() % 40 + 5)),
        Materias ("Fisica 1", 1, Marcello_Talarico, inicializarAlunosAleatorios(rand() % 40 + 5)),
        Materias ("Fundamentos de Programacao", 1, Daniel_Cavalcanti, inicializarAlunosAleatorios(rand() % 40 + 5)),
        
        // 2º Periodo
        Materias ("Comunicacao Linguistica", 2, Raquel_Ribeiro, inicializarAlunosAleatorios(rand() % 40 + 5)),
        Materias ("Calculo 2", 2, Sergio_Flavio, inicializarAlunosAleatorios(rand() % 40 + 5)),
        Materias ("Algebra Linear", 2, Suellen_Ribeiro, inicializarAlunosAleatorios(rand() % 40 + 5)),
        Materias ("Logica para Computacao", 2, Gustavo_Paetzold, inicializarAlunosAleatorios(rand() % 40 + 5)),
        Materias ("Fisica 2", 2, Leonardo_Lima, inicializarAlunosAleatorios(rand() % 40 + 5)),
        Materias ("Estrutura de Dados", 2, Ricardo_Tavares, inicializarAlunosAleatorios(rand() % 40 + 5)),
        Materias ("Quimica A", 2, Ricardo_Tavares, inicializarAlunosAleatorios(rand() % 40 + 5)),

        // 3º Periodo
        Materias ("Pesquisa e Classificacao de Dados", 3, Ricardo_Tavares, inicializarAlunosAleatorios(rand() % 40 + 5)), 
        Materias ("Equacoes Diferenciais Ordinarias", 3, Jocelaine_Cargnelutti, inicializarAlunosAleatorios(rand() % 40 + 5)),
        Materias ("Calculo 3", 3, Dione_Ines, inicializarAlunosAleatorios(rand() % 40 + 5)),
        Materias ("Mecanica Geral 1", 3, Evandro_Kolling, inicializarAlunosAleatorios(rand() % 40 + 5)),
        Materias ("Probabilidade e Estatistica", 3, Rosangela_Aparecida, inicializarAlunosAleatorios(rand() % 40 + 5)),
        Materias ("Fisica 3", 3, Ernesto_Osvaldo, inicializarAlunosAleatorios(rand() % 40 + 5)),
        Materias ("Desenho tecnico", 3, Cassius_Aguiar, inicializarAlunosAleatorios(rand() % 40 + 5)),

        // 4º Periodo
        Materias ("Calculo 4", 4, Pablo_Chang, inicializarAlunosAleatorios(rand() % 40 + 5)),
        Materias ("Calculo Numerico", 4, Gustavo_Dalposso, inicializarAlunosAleatorios(rand() % 40 + 5)),
        Materias ("Circuitos Eletricos", 4, Cassius_Aguiar, inicializarAlunosAleatorios(rand() % 40 + 5)),
        Materias ("Teoria da Computacao", 4, Ricardo_Tavares, inicializarAlunosAleatorios(rand() % 40 + 5)),
        Materias ("Fundamentos de Orientacao a Objetos", 4, Ricardo_Tavares, inicializarAlunosAleatorios(rand() % 40 + 5)),
        Materias ("Fenomenos dos Transportes 1", 4, Gerson_Filippini, inicializarAlunosAleatorios(rand() % 40 + 5)),
        Materias ("Principios de Resistencia dos Materiais", 4, Evandro_Kolling, inicializarAlunosAleatorios(rand() % 40 + 5)),

        // 5º Periodo
        Materias ("Sinais e Sistemas", 5, Eduardo_Vinicius, inicializarAlunosAleatorios(rand() % 40 + 5)),
        Materias ("Eletronica Analogica A", 5, Cassius_Aguiar, inicializarAlunosAleatorios(rand() % 40 + 5)),
        Materias ("Circuitos Digitais", 5, Mauricio_Zardo, inicializarAlunosAleatorios(rand() % 40 + 5)),
        Materias ("Engenharia de Software", 5, Alexandre_Giron, inicializarAlunosAleatorios(rand() % 40 + 5)),
        Materias ("Banco de Dados", 5, Sidgley_Camargo, inicializarAlunosAleatorios(rand() % 40 + 5)),
        Materias ("Economia", 5, Diane_Aparecida, inicializarAlunosAleatorios(rand() % 40 + 5)),

        // 6º Periodo
        Materias ("Controle de Sistemas Lineares 1", 6, Mauricio_Zardo, inicializarAlunosAleatorios(rand() % 40 + 5)),
        Materias ("Eletrônica Analogica C", 6, Luis_Carlos, inicializarAlunosAleatorios(rand() % 40 + 5)),
        Materias ("Sistemas Digitais", 6, Tiago_Piovesan, inicializarAlunosAleatorios(rand() % 40 + 5)),
        Materias ("Compiladores", 6, Ricardo_Tavares, inicializarAlunosAleatorios(rand() % 40 + 5)),
        Materias ("Organizacao e Arquitetura de Computadores", 6, Alexandre_Giron, inicializarAlunosAleatorios(rand() % 40 + 5)),
        Materias ("Principios de Sistemas de Comunicacao", 6, Luis_Carlos, inicializarAlunosAleatorios(rand() % 40 + 5)),

        // 7º Periodo
        Materias ("Controle de Sistemas Lineares 2", 7, Jose_Dolores, inicializarAlunosAleatorios(rand() % 40 + 5)),
        Materias ("Sistemas Microcontroladores", 7, Alessandro_Paulo, inicializarAlunosAleatorios(rand() % 40 + 5)),
        Materias ("Sistemas Inteligentes", 7, Daniel_Cavalcanti, inicializarAlunosAleatorios(rand() % 40 + 5)),
        Materias ("Redes de Computadores 1", 7, Alvaro_Ricieri, inicializarAlunosAleatorios(rand() % 40 + 5)),
        Materias ("Sistemas Operacionais", 7, Alexandre_Giron, inicializarAlunosAleatorios(rand() % 40 + 5)),
        Materias ("Metodologia de Pesquisa", 7, Osni_Hoss, inicializarAlunosAleatorios(rand() % 40 + 5)),

        // 8º Periodo
        Materias ("Empreendedorismo", 8, Sandra_Regina, inicializarAlunosAleatorios(rand() % 40 + 5)),
        Materias ("Sistemas Embarcados", 8, Tiago_Piovesan, inicializarAlunosAleatorios(rand() % 40 + 5)),
        Materias ("Oficina de Integracao", 8, Daniel_Cavalcanti, inicializarAlunosAleatorios(rand() % 40 + 5)),
        Materias ("Redes de Computadores 2", 8, Alvaro_Ricieri, inicializarAlunosAleatorios(rand() % 40 + 5)),
        Materias ("Seguranca Computacional", 8, Alexandre_Giron, inicializarAlunosAleatorios(rand() % 40 + 5)), 

        // 9º Periodo
        Materias ("Computacao Grafica", 9, Sidgley_Camargo, inicializarAlunosAleatorios(rand() % 40 + 5)),
        Materias ("Sistemas Distribuidos", 9, Alvaro_Ricieri, inicializarAlunosAleatorios(rand() % 40 + 5)),
        Materias ("TCC 1", 9, Elder_Elisandro, inicializarAlunosAleatorios(rand() % 40 + 5)), 
        
        // 10º Periodo
        Materias ("TCC 2", 10, Daniel_Cavalcanti , inicializarAlunosAleatorios(rand() % 40 + 5))
    };
}

