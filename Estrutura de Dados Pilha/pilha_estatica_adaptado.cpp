#include <iostream>
#include <ctime>
using namespace std;

const int TAMANHO_MAX = 100; // Tamanho máximo da pilha

struct DadosSistema{
    string nome;
    int numero;
    char caractere;
    float fracionario;
};

struct Pilha {
    DadosSistema dados[TAMANHO_MAX]; // Array para armazenar os elementos da pilha
    int topo; // índice do topo da pilha

    Pilha() {
        topo = -1; // Inicializa o topo da pilha como -1 (vazia)
    }
};

bool estaVazia(const Pilha& pilha) {
    return pilha.topo == -1;
}

bool estaCheia(const Pilha& pilha) {
    return pilha.topo == TAMANHO_MAX - 1;
}

void empilhar(Pilha& pilha) {
    if (estaCheia(pilha)) {
        cout << "\nA pilha esta cheia. Nao eh possivel adicionar elementos.\n";
        return;
    }
    string dadoNome;
    int dadoNumero;
    char dadoCaractere;
    float dadoFracionario;

    cout<<"\n";
    cout<<"Digite o nome do dado: ";
    cin>>dadoNome;
    cout<<"Digite o numero do dado: ";
    cin>>dadoNumero;
    cout<<"Digite o caractere do dado: ";
    cin>>dadoCaractere;
    cout<<"Digite o fracionario do dado: ";
    cin>>dadoFracionario;
    cout<<"\n";

    pilha.dados[++pilha.topo] = {dadoNome, dadoNumero, dadoCaractere, dadoFracionario}; // Incrementa o topo e insere o elemento no topo
}

void desempilhar(Pilha& pilha) {
    if (estaVazia(pilha)) {
        cout << "\nA pilha esta vazia. Nao eh possivel remover elementos.\n";
        return;
    }
    --pilha.topo; // Decrementa o topo para remover o elemento do topo
}

void imprimeTopo(const Pilha& pilha) {
    if (estaVazia(pilha)) {
        cout << "\nA pilha esta vazia. Nao ha elemento no topo.\n";
        return;
    }
    cout<<"\nO dado armazenado no topo eh o seguinte:\n";
    cout<<"Nome: "<<pilha.dados[pilha.topo].nome<<"\n";
    cout<<"Numero: "<<pilha.dados[pilha.topo].numero<<"\n";
    cout<<"Caractere: "<<pilha.dados[pilha.topo].caractere<<"\n";
    cout<<"Fracionario: "<<pilha.dados[pilha.topo].fracionario<<"\n\n";
}

int main() {
    Pilha pilha;
    int opt, tempo;

    do{
        cout<<"\nPilha do Sistema Tal\n";
        cout<<"\nOperacoes:\n";
        cout<<"1 - Empilhar Dado\n";
        cout<<"2 - Desempilhar Dado\n";
        cout<<"3 - Ver Dado do Topo\n";
        cout<<"0 - Sair\n";
        cout<<"Digite o numero da opcao que deseja: ";
        cin>>opt;
        switch(opt){
            case 0: {
                cout<<"Saindo...";
                break;
            }case 1: {
                empilhar(pilha);
                break;
            }case 2: {
                desempilhar(pilha);
                break;
            }case 3: {
                imprimeTopo(pilha);
                break;
            }default: {
                cout<<"Opcao Invalida!\n";
                break;
            }
        }
    }while(opt != 0);

    tempo = clock();
    while(clock()-tempo <5000){}
    return 0;
}

