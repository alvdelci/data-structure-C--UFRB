#include <iostream>
using namespace std;

#define MAX 50

int empilhar(int v[], int &topo, int valor);
int desempilhar(int v[], int &topo, int &valor);

int main(void) {
    // Declara a pilha
    int pilha[MAX];
    int topo = -1;

    // Vari�vel para armazenar dado digitado
    int dado;
    // Vari�vel que indica se acabaram valores da pilha
    int vazia;

    // L� valores e os empilha, se forem >= 0
    do {
        cout << "Digite um numero inteiro: ";
        cin >> dado;
        if (dado >=0) empilhar(pilha, topo, dado);
        } while(dado >= 0);

    // Agora mostra valores da pilha at� que eles acabem...
    do {
        vazia = desempilhar(pilha, topo, dado);
        if (vazia == 0) cout << dado << endl;
    } while (vazia == 0);
}

// Empilha um valor
// Entrada:
//  v: vetor com elementos da pilha
//  topo: topo da pilha
//  valor: valor a ser empilhado
// Retorna:
//  1- Se pilha cheia
//  0- Caso contr�rio
int empilhar(int v[], int &topo, int valor) {
    // Se a pilha est� cheia... retorna 1
    if (topo>=MAX-1) {
        cout << "ERRO: Pilha cheia!" << endl;
        return 1;
    }
    // Se pilha n�o est� cheia, vamos empilhar
    topo = topo + 1;
    v[topo] = valor;
    // Indica que valor foi empilhado
    return 0;
}


// Desempilha um valor
// Entrada:
//  v: vetor com elementos da pilha
//  topo: topo da pilha
//  valor: Local a colocar valor desempilhado
// Retorna:
//  valor: valor desempilhado
//  1- Se pilha vazia
//  0- Caso contr�rio
int desempilhar(int v[], int &topo, int &valor) {
    // Se a pilha est� vazia... retorna 1
    if (topo<0) {
        cout << "ERRO: Pilha vazia!" << endl;
        return 1;
    }
    // Se pilha n�o est� vazia, vamos desempilhar
    valor = v[topo];
    topo = topo - 1;
    // Indica que valor foi desempilhado
    return 0;
}


