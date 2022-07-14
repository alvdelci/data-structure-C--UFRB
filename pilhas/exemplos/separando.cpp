#include <iostream>
#include <cctype>
using namespace std;

#define MAX 50

int empilhar(char v[], int &topo, char valor);
int desempilhar(char v[], int &topo, char &valor);

int main(void) {
    // Declara a pilhas
    char letras[MAX];
    int ltopo = -1;
    char digitos[MAX];
    int dtopo = -1;

    // Vari�vel para armazenar dado digitado
    char texto[2*MAX];
    // Vari�vel que indica se acabaram valores da pilha
    int vazia;
    // Vari�vel para desempilhamento
    char dado;
    // Contador
    int i;

    cout << "Digite uma mensagem com letras e n�meros:" << endl;
    cin.getline(texto,2*MAX);

    i = 0;
    while (texto[i] != '\0') {
        if (isdigit(texto[i])) empilhar(digitos, dtopo, texto[i]);
        if (isalpha(texto[i])) empilhar(letras, ltopo, texto[i]);
        i = i + 1;
    }

    // Agora mostra letras at� que elas acabem...
    cout << "Letras..." << endl;
    do {
        vazia = desempilhar(letras, ltopo, dado);
        if (vazia == 0) cout << dado << endl;
    } while (vazia == 0);

    // Agora mostra d�gitos das pilha at� que eles acabem...
    cout << "N�meros..." << endl;
    do {
        vazia = desempilhar(digitos, dtopo, dado);
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
int empilhar(char v[], int &topo, char valor) {
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
int desempilhar(char v[], int &topo, char &valor) {
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


