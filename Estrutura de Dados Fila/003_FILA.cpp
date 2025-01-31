#include <iostream>
#include <string>

using namespace std;
// Fun��o para limpar a tela (funciona em Windows, Linux e macOS)
void limparTela() {
	system("cls"); // Windows
}

const int MAX_SIZE = 100; // Tamanho m�ximo da fila

struct Fila {
    string elementos[MAX_SIZE];
    int inicio; // �ndice do in�cio da fila
    int fim;    // �ndice do fim da fila

    Fila() {
        inicio = 0;
        fim = -1;
    }

    // Fun��o para adicionar um elemento ao final da fila
    void enfileirar(const string& nome) {
        if (fim == MAX_SIZE - 1) {
            cout << "A fila est� cheia. N�o � poss�vel adicionar mais elementos." << endl;
        } else {
            fim++;
            elementos[fim] = nome;
        }
    }

    // Fun��o para remover o elemento do in�cio da fila
    void desenfileirar() {
        if (inicio > fim) {
            cout << "A fila est� vazia." << endl;
        } else {
            cout << "Removendo: " << elementos[inicio] << endl;
            inicio++;
        }
    }

    // Fun��o para obter o nome da pessoa na frente da fila
    string frente() {
        if (inicio > fim) {
            return "Fila vazia";
        }
        return elementos[inicio];
    }

    // Fun��o para verificar se a fila est� vazia
    bool estaVazia() {
        return (inicio > fim);
    }

    // Fun��o para obter o n�mero de pessoas na fila
    int tamanho() {
        return (fim - inicio + 1);
    }
};

void mostrarMenu() {
    cout << "Menu:" << endl;
    cout << "1. Adicionar nome na fila" << endl;
    cout << "2. Remover algu�m da fila" << endl;
    cout << "3. Mostrar todos na fila" << endl;
    cout << "4. Sair" << endl;
    cout << "Escolha uma op��o: ";
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
                cout << nome << " foi adicionado � fila." << endl;
                break;
            }
            case 2: {
                if (!filaDeLanchonete.estaVazia()) {
                    filaDeLanchonete.desenfileirar();
                } else {
                    cout << "A fila est� vazia. N�o � poss�vel remover ningu�m." << endl;
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
                cout << "Op��o inv�lida. Tente novamente." << endl;
            }
        }

        // Espera por uma entrada do usu�rio antes de continuar
        cout << "\nPressione Enter para continuar...";
        cin.ignore();
        cin.get();

    } while (opcao != 4);

    return 0;
}


