#include <iostream>
#include <string>

using namespace std;
// Função para limpar a tela (funciona em Windows, Linux e macOS)
void limparTela() {
	system("cls"); // Windows
}

const int MAX_SIZE = 100; // Tamanho máximo da fila

struct Fila {
    string elementos[MAX_SIZE];
    int inicio; // Índice do início da fila
    int fim;    // Índice do fim da fila

    Fila() {
        inicio = 0;
        fim = -1;
    }

    // Função para adicionar um elemento ao final da fila
    void enfileirar(const string& nome) {
        if (fim == MAX_SIZE - 1) {
            cout << "A fila está cheia. Não é possível adicionar mais elementos." << endl;
        } else {
            fim++;
            elementos[fim] = nome;
        }
    }

    // Função para remover o elemento do início da fila
    void desenfileirar() {
        if (inicio > fim) {
            cout << "A fila está vazia." << endl;
        } else {
            cout << "Removendo: " << elementos[inicio] << endl;
            inicio++;
        }
    }

    // Função para obter o nome da pessoa na frente da fila
    string frente() {
        if (inicio > fim) {
            return "Fila vazia";
        }
        return elementos[inicio];
    }

    // Função para verificar se a fila está vazia
    bool estaVazia() {
        return (inicio > fim);
    }

    // Função para obter o número de pessoas na fila
    int tamanho() {
        return (fim - inicio + 1);
    }
};

void mostrarMenu() {
    cout << "Menu:" << endl;
    cout << "1. Adicionar nome na fila" << endl;
    cout << "2. Remover alguém da fila" << endl;
    cout << "3. Mostrar todos na fila" << endl;
    cout << "4. Sair" << endl;
    cout << "Escolha uma opção: ";
}

int main() {
    Fila filaDeLanchonete; // Criando uma fila de nomes de pessoas
    int opcao;

    do {
        limparTela(); // Limpa a tela antes de mostrar o menu
        mostrarMenu();
        cin >> opcao;

        switch (opcao) {
            case 1: {
                string nome;
                cout << "Digite o nome a ser adicionado: ";
                cin >> nome;
                filaDeLanchonete.enfileirar(nome);
                cout << nome << " foi adicionado à fila." << endl;
                break;
            }
            case 2: {
                if (!filaDeLanchonete.estaVazia()) {
                    filaDeLanchonete.desenfileirar();
                } else {
                    cout << "A fila está vazia. Não é possível remover ninguém." << endl;
                }
                break;
            }
            case 3: {
                cout << "Pessoas na fila:" << endl;
                for (int i = filaDeLanchonete.inicio; i <= filaDeLanchonete.fim; i++) {
                    cout << filaDeLanchonete.elementos[i] << endl;
                }
                break;
            }
            case 4: {
                cout << "Encerrando o programa." << endl;
                break;
            }
            default: {
                cout << "Opção inválida. Tente novamente." << endl;
            }
        }

        // Espera por uma entrada do usuário antes de continuar
        cout << "\nPressione Enter para continuar...";
        cin.ignore();
        cin.get();

    } while (opcao != 4);

    return 0;
}


