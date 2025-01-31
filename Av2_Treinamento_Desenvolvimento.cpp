// Autor: Álvaro Gabriel Alves Albuquerque
// Criado em: 2023
// Apenas para exibição e estudo

#include <iostream>
#include <ctime>
using namespace std;

const int TAMANHO_PILHA = 10; // Tamanho máximo da pilha
const int TAMANHO_FILA = 10;

struct DadosPilha{
    string nomeCurso;
    string materiais;
    float progresso;
};

struct Pilha {
    DadosPilha dados[TAMANHO_PILHA]; // Array para armazenar os elementos da pilha
    int topo; // índice do topo da pilha

    Pilha() {
        topo = -1; // Inicializa o topo da pilha como -1 (vazia)
    }
};

struct DadosFila{
    string nomePessoa;
    string nomeTreino;
    string horaInicial;
    string horaFinal;
};

struct Fila {
    DadosFila elementos[TAMANHO_FILA];
    int inicio;
    int fim;

    Fila() {
        inicio = 0;
        fim = -1;
    }
};

bool pilhaVazia(const Pilha& pilha);
bool pilhaCheia(const Pilha& pilha);
void empilhar(Pilha& pilha);
void desempilhar(Pilha& pilha);
void imprimeTopo(const Pilha& pilha);
void menuPilha(Pilha& pilha, int opt);

bool filaVazia(const Fila& fila);
bool filaCheia(const Fila& fila);
void enfileirar(Fila& fila);
void desenfileirar(Fila& fila);
void imprimeElementosFila(const Fila& fila);
int tamanhoFila(const Fila& fila);
void menuFila(Fila& fila);

void limpaTela(int x){
    if(x == 1){
        int temporizador = clock();
        while(clock()-temporizador<1000){}
        system("cls");
    }
    if(x == 2){
        cout << "\nPressione Enter para continuar...";
        cin.get();
        system("cls");
    }
}

int main() {
    Pilha pilhaAlv, pilhaEdu, pilhaCarlos, pilhaKyw, pilhaLaisa, pilhaVit, pilhaLet, pilhaYasmin;
    Fila fila;
    int opt, optPessoa, tempo;

    do{
        system("cls");
        cout<<"Sistema de Treinamento e Desenvolvimento\n\n";
        cout<<"Operacoes:\n";
        cout<<"1 - Pilha de Progresso em Cursos\n";
        cout<<"2 - Fila de Agendamento de Treinamento\n";
        cout<<"0 - Sair do Programa\n";
        cout<<"Digite o numero da operacao que deseja realizar: ";
        cin>>opt;
        if(opt !=0){system("cls");}

        switch(opt){
            case 0: {
                cout<<"\nSaindo...\n";
                break;
            }case 1: {
                do{
                    cout<<"Acessar Pilha do Funcionario\n\n";
                    cout<<"Funcionarios:\n";
                    cout<<"1 - Alvaro\n2 - Eduardo\n3 - Carlos\n4 - Kywanne\n5 - Laisa\n6 - Vitoria\n7 - Leticia\n8 - Yasmin\n0 - Voltar ao Menu Principal\n";
                    cout<<"Digite o numero do seu nome: ";
                    cin>>optPessoa;
                    if(opt !=0){system("cls");}

                    switch(optPessoa){
                        case 0: {
                            cout<<"\nVoltando...\n";
                            limpaTela(1);
                            break;
                        }case 1: {
                            menuPilha(pilhaAlv, optPessoa);
                            break;
                        }case 2: {
                            menuPilha(pilhaEdu, optPessoa);
                            break;
                        }case 3: {
                            menuPilha(pilhaCarlos, optPessoa);
                            break;
                        }case 4: {
                            menuPilha(pilhaKyw, optPessoa);
                            break;
                        }case 5: {
                            menuPilha(pilhaLaisa, optPessoa);
                            break;
                        }case 6: {
                            menuPilha(pilhaVit, optPessoa);
                            break;
                        }case 7: {
                            menuPilha(pilhaLet, optPessoa);
                            break;
                        }case 8: {
                            menuPilha(pilhaYasmin, optPessoa);
                            break;
                        }default: {
                            cout<<"Numero Invalido...\n";
                            limpaTela(1);
                            break;
                        }
                    }

                }while(optPessoa != 0);
                break;
            }case 2: {
                menuFila(fila);
                break;
            }default: {
                cout<<"Operacao Invalida...\n";
                limpaTela(1);
            }
        }

    }while(opt != 0);
    
    tempo = clock();
    while(clock()-tempo <5000){}
    return 0;
}


bool pilhaVazia(const Pilha& pilha) {
    return pilha.topo == -1;
}

bool pilhaCheia(const Pilha& pilha) {
    return pilha.topo == TAMANHO_PILHA - 1;
}

void empilhar(Pilha& pilha) {
    if (pilhaCheia(pilha)) {
        cout << "\nA pilha esta cheia. Nao eh possivel adicionar elementos.\n";
        return;
    }
    string dadoNomeCurso;
    string dadoMateriais;
    float dadoProgresso;

    cout<<"\n";
    cout<<"Digite o nome do curso: ";
    getline(cin, dadoNomeCurso);
    cout<<"Digite os materiais utilizados: ";
    getline(cin, dadoMateriais);
    cout<<"Digite a porcentagem de conclusao do curso (de 0 a 100): ";
    cin>>dadoProgresso;
    cout<<"\n";

    pilha.dados[++pilha.topo] = {dadoNomeCurso, dadoMateriais, dadoProgresso}; // Incrementa o topo e insere o elemento no topo
    cin.ignore();
}

void desempilhar(Pilha& pilha) {
    if (pilhaVazia(pilha)) {
        cout << "\nA pilha esta vazia. Nao eh possivel remover elementos.\n";
        return;
    }
    --pilha.topo; // Decrementa o topo para remover o elemento do topo
    cout<<"\nDesempilhado com sucesso.\n";
}

void imprimeTopo(const Pilha& pilha) {
    if (pilhaVazia(pilha)) {
        cout << "\nA pilha esta vazia. Nao ha elemento no topo.\n";
        return;
    }
    cout<<"\nO curso armazenado no topo eh o seguinte:\n";
    cout<<"Nome do curso: "<<pilha.dados[pilha.topo].nomeCurso<<"\n";
    cout<<"Materiais utilizados: "<<pilha.dados[pilha.topo].materiais<<"\n";
    cout<<"Progresso (em %): "<<pilha.dados[pilha.topo].progresso<<"%\n\n";
}

void menuPilha(Pilha& pilha, int opt){
    int optPilha;
    do{
        cout<<"Pilha de progresso em cursos do(a) ";
        if(opt == 1){cout<<"Alvaro\n";}
        else if(opt == 2){cout<<"Eduardo\n";}
        else if(opt == 3){cout<<"Carlos\n";}
        else if(opt == 4){cout<<"Kywanne\n";}
        else if(opt == 5){cout<<"Laisa\n";}
        else if(opt == 6){cout<<"Vitoria\n";}
        else if(opt == 7){cout<<"Leticia\n";}
        else{cout<<"Yasmin\n";}

        cout<<"\nOperacoes:\n";
        cout<<"1 - Empilhar Dado\n";
        cout<<"2 - Desempilhar Dado\n";
        cout<<"3 - Ver Dado do Topo\n";
        cout<<"0 - Voltar ao Menu de Funcionarios\n";
        cout<<"Digite o numero da opcao que deseja: ";
        cin>>optPilha;
        cin.ignore();

        switch(optPilha){
            case 0: {
                cout<<"\nVoltando...\n";
                limpaTela(1);
                break;
            }case 1: {
                empilhar(pilha);
                limpaTela(2);
                break;
            }case 2: {
                desempilhar(pilha);
                limpaTela(2);
                break;
            }case 3: {
                imprimeTopo(pilha);
                limpaTela(2);
                break;
            }default: {
                cout<<"\nOpcao Invalida...\n";
                limpaTela(1);
                break;
            }
        }

    }while(optPilha != 0);
}


bool filaVazia(const Fila& fila) {
    return (fila.inicio > fila.fim);
}

bool filaCheia(const Fila& fila) {
    return fila.fim == TAMANHO_FILA - 1;
}

void enfileirar(Fila& fila) {
    if (filaCheia(fila)) {
        cout << "A fila esta cheia. Nao eh possivel adicionar mais elementos.\n";
        return;
    }
    string dadoNomePessoa;
    string dadoNomeTreino;
    string dadoHoraInicial;
    string dadoHoraFinal;

    cout<<"\n";
    cout<<"Digite o nome do Funcionario: ";
    getline(cin, dadoNomePessoa);
    cout<<"Digite o nome do Treinamento: ";
    getline(cin, dadoNomeTreino);
    cout<<"Digite o horario de inicio (hh:mm): ";
    getline(cin, dadoHoraInicial);
    cout<<"Digite o horario de encerramento (hh:mm): ";
    getline(cin, dadoHoraFinal);
    cout<<"\n";

    fila.elementos[++fila.fim] = {dadoNomePessoa, dadoNomeTreino, dadoHoraInicial, dadoHoraFinal};
}

void desenfileirar(Fila& fila) {
    if (filaVazia(fila)) {
        cout << "\nA fila esta vazia.\n";
        return;
    }
    ++fila.inicio;
    cout<<"\nDesempilhado com sucesso.\n";
}

void imprimeElementosFila(const Fila& fila) {
    if (filaVazia(fila)) {
        cout << "\nA fila esta vazia.\n";
        return;
    }
    cout<<"\n\nPessoas na Fila:\n";
    for (int i = fila.inicio; i <= fila.fim; i++) {
        cout<<"\nO agendamento armazenado na posicao "<< i+1 << " eh o seguinte:\n";
        cout<<"Funcionario: "<<fila.elementos[i].nomePessoa<<"\n";
        cout<<"Treinamento: "<<fila.elementos[i].nomeTreino<<"\n";
        cout<<"Inicio: "<<fila.elementos[i].horaInicial<<"\n";
        cout<<"Encerramento: "<<fila.elementos[i].horaFinal<<"\n\n";
    }
}

int tamanhoFila(const Fila& fila) {
    return (fila.fim - fila.inicio + 1);
}

void menuFila(Fila& fila){
    int optFila;
    do {
        cout<<"Fila de Agendamento de Treinamento\n";
        cout<<"\nOperacoes:\n";
        cout<<"1 - Enfileirar Dado\n";
        cout<<"2 - Desenfileirar Dado\n";
        cout<<"3 - Mostrar todos os Dados da Fila\n";
        cout<<"4 - Mostrar Tamanho da Fila\n";
        cout<<"0 - Voltar ao Menu Principal\n";
        cout<<"Digite o numero da opcao que deseja: ";
        cin>>optFila;
        cin.ignore();

        switch (optFila) {
            case 0: {
                cout<<"\nVoltando...\n";
                limpaTela(1);
                break;
            }case 1: {
                enfileirar(fila);
                limpaTela(2);
                break;
            }
            case 2: {
                desenfileirar(fila);
                limpaTela(2);
                break;
            }
            case 3: {
                imprimeElementosFila(fila);
                limpaTela(2);
                break;
            }
            case 4: {
                cout << "\nTamanho da Fila: " << tamanhoFila(fila) << " dados\n";
                limpaTela(2);
                break;
            }
            default: {
                cout << "\nOpcao invalida...\n";
                limpaTela(1);
                break;
            }
        }

    } while (optFila != 0);
}