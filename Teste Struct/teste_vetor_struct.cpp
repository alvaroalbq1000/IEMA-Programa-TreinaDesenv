#include <iostream>
using namespace std;

struct AlunoIEMA{
    string nome;
    int matricula;
    int idade;
    char sexo;
    int turma;
    string curso;
};

void imprimeDados(AlunoIEMA aluno);

int main(){
    AlunoIEMA alunos[5];
    AlunoIEMA aluno1 = {"Alvaro", 59453, 17, 'm', 203, "info"};
    AlunoIEMA aluno2 = {"Anderson", 58309, 17, 'm', 203, "info"};

    alunos[0] = aluno1;
    alunos[1] = aluno2;

    cout<<"\n\n\n";
    imprimeDados(alunos[0]);
    cout<<"\n\n\n";
    imprimeDados(alunos[1]);
    cout<<"\n\n\n";

    return 0;
}

void imprimeDados(AlunoIEMA aluno){
    cout<<"Nome: "<<aluno.nome<<".\n";
    cout<<"matricula: "<<aluno.matricula<<".\n";
    cout<<"idade: "<<aluno.idade<<".\n";
    cout<<"sexo: "<<aluno.sexo<<".\n";
    cout<<"turma: "<<aluno.turma<<".\n";
    cout<<"curso: "<<aluno.curso<<".\n";
}