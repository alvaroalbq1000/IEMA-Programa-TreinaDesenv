#include <iostream>
#include <ctime>
using namespace std;

const int TAMANHO_FILA = 100; // Tamanho máximo da fila

struct DadosFila{
    string nome;
    int numero;
    char caractere;
    float fracionario;
};

struct Fila {
    DadosFila elementos[TAMANHO_FILA]; // Array para armazenar os elementos da fila
    int inicio; // índice da frente da fila
    int fim; // índice da costa da fila

    Fila() {
        inicio = 0; // inicializa a frente da fila como 0
        fim = -1; // inicializa a costa da fila como -1
    }
};

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

    fila.elementos[++fila.fim] = {dadoNome, dadoNumero, dadoCaractere, dadoFracionario}; // incrementa a costa e insere o elemento na frente
}

void desenfileirar(Fila& fila) {
    if (filaVazia(fila)) {
        cout << "A fila esta vazia.\n";
        return;
    }
    ++fila.inicio; // incrementa a frente para remover o elemento da frente
}

void imprimeElementosFila(const Fila& fila) {
    if (filaVazia(fila)) {
        cout << "A fila esta vazia.\n";
        return;
    }
    cout<<"Pessoas na Fila:\n";
    for (int i = fila.inicio; i <= fila.fim; i++) {
        cout<<"\nO dado armazenado na posicao "<< i+1 << " eh o seguinte:\n";
        cout<<"Nome: "<<fila.elementos[i].nome<<"\n";
        cout<<"Numero: "<<fila.elementos[i].numero<<"\n";
        cout<<"Caractere: "<<fila.elementos[i].caractere<<"\n";
        cout<<"Fracionario: "<<fila.elementos[i].fracionario<<"\n\n";
    }
}

int tamanhoFila(const Fila& fila) {
    return (fila.fim - fila.inicio + 1);
}

int main() {
    Fila fila;
    int opt, tempo;

    do {
        cout<<"\nFila do Sistema Tal\n";
        cout<<"\nOperacoes:\n";
        cout<<"1 - Enfileirar Dado\n";
        cout<<"2 - Desenfileirar Dado\n";
        cout<<"3 - Mostrar todos os Dados da Fila\n";
        cout<<"4 - Mostrar Tamanho da Fila\n";
        cout<<"0 - Sair\n";
        cout<<"Digite o numero da opcao que deseja: ";
        cin>>opt;

        switch (opt) {
            case 0: {
                cout<<"Saindo...";
                break;
            }case 1: {
                enfileirar(fila);
                break;
            }
            case 2: {
                desenfileirar(fila);
                break;
            }
            case 3: {
                imprimeElementosFila(fila);
                break;
            }
            case 4: {
                cout << "Tamanho da Fila: " << tamanhoFila(fila) << " dados\n";
                break;
            }
            default: {
                cout << "Opcao invalida.\n";
                break;
            }
        }
    } while (opt != 0);

    tempo = clock();
    while(clock()-tempo <5000){}
    return 0;
}
