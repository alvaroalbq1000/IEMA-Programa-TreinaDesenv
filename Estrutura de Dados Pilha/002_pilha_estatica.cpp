#include <iostream>

using namespace std;

const int TAMANHO_MAX = 100; // Tamanho m�ximo da pilha

struct Pilha {
    int dados[TAMANHO_MAX]; // Array para armazenar os elementos da pilha
    int topo; // �ndice do topo da pilha

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

void empilhar(Pilha& pilha, int valor) {
    if (estaCheia(pilha)) {
        cout << "A pilha est� cheia. N�o � poss�vel adicionar elementos." << endl;
        return;
    }
    pilha.dados[++pilha.topo] = valor; // Incrementa o topo e insere o elemento no topo
}

void desempilhar(Pilha& pilha) {
    if (estaVazia(pilha)) {
        cout << "A pilha est� vazia. N�o � poss�vel remover elementos." << endl;
        return;
    }
    --pilha.topo; // Decrementa o topo para remover o elemento do topo
}

int valorTopo(const Pilha& pilha) {
    if (estaVazia(pilha)) {
        cout << "A pilha est� vazia. N�o h� elemento no topo." << endl;
        return -1;
    }
    return pilha.dados[pilha.topo]; // Retorna o valor do topo da pilha
}

int main() {
    Pilha pilha;

    empilhar(pilha, 10);
    empilhar(pilha, 20);
    empilhar(pilha, 30);

    cout << "Topo da pilha: " << valorTopo(pilha) << endl;

    desempilhar(pilha);
    cout << "Topo da pilha ap�s desempilhar: " << valorTopo(pilha) << endl;

    desempilhar(pilha);
    desempilhar(pilha);

    if (estaVazia(pilha)) {
        cout << "A pilha est� vazia." << endl;
    } else {
        cout << "A pilha n�o est� vazia." << endl;
    }

    return 0;
}

