#include <iostream>
using namespace std;

struct NoArvore {
    int data;
    NoArvore* esquerda;
    NoArvore* direita;
};

NoArvore* inserirBTS(NoArvore* raiz, int chave) {
    if (raiz == nullptr) {
        NoArvore* novoNo = new NoArvore;
        novoNo->data = chave;
        novoNo->esquerda = nullptr;
        novoNo->direita = nullptr;
        return novoNo;
    }

    if (chave < raiz->data) {
        raiz->esquerda = inserirBTS(raiz->esquerda, chave);
    } else if (chave > raiz->data) {
        raiz->direita = inserirBTS(raiz->direita, chave);
    }
    // Chaves iguais não são inseridas novamente.

    return raiz;
}

NoArvore* buscar(NoArvore* raiz, int chave) {
    if (raiz == nullptr || raiz->data == chave) {
        return raiz;
    }

    if (chave < raiz->data) {
        return buscar(raiz->esquerda, chave);
    }
    return buscar(raiz->direita, chave);
}

int main() {
    NoArvore* raiz = nullptr;
    int quantidade;
    int valor;

    cout << "Quantos valores deseja inserir? ";
    cin >> quantidade;

    for (int i = 0; i < quantidade; ++i) {
        cout << "Digite um valor: ";
        cin >> valor;
        raiz = inserirBTS(raiz, valor);
    }

    cout << "Qual valor deseja buscar? ";
    cin >> valor;

    if (buscar(raiz, valor) != nullptr) {
        cout << "Valor encontrado.\n";
    } else {
        cout << "Valor nao encontrado.\n";
    }

    return 0;
}
