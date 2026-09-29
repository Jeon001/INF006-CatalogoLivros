#include <stdio.h>
#include <string.h>
#include <emscripten.h>

#define TAM 10

typedef struct {
  char titulo[100];
  float preco;
}livro;

livro livros[TAM] = {
        {"As Crônicas de Nárnia", 29.90},
        {"1984", 39.90},
        {"Six of Crows", 49.90},
        {"O Pequeno Príncipe", 24.50},
        {"O Senhor dos Anéis", 89.90},
        {"A Revolução dos Bichos", 32.00},
        {"Jogos Vorazes", 54.90},
        {"Trono de Vidro", 27.80},
        {"Orgulho e Preconceito", 35.00},
        {"Rivalidade Ardente", 42.00}
    };

void ordenaPrecoCrescente(livro livros[], int tamanho) {
    int i, j;
    livro aux;
    
    for (i = 0; i < tamanho - 1; i++) {
        for (j = 0; j < tamanho - i - 1; j++) {
            if (livros[j].preco > livros[j+1].preco) {
                aux = livros[j];
                livros[j] = livros[j+1];
                livros[j+1] = aux;
            }
        }
    }
}

void ordenaPrecoDecrescente(livro livros[], int tamanho) {
    int i, j;
    livro aux;
    
    for (i = 0; i < tamanho - 1; i++) {
        for (j = 0; j < tamanho - i - 1; j++) {
            if (livros[j].preco < livros[j+1].preco) {
                aux = livros[j];
                livros[j] = livros[j+1];
                livros[j+1] = aux;
            }
        }
    }
}

void ordenaTituloCrescente(livro vetor[], int tamanho) {
    int i, j;
    livro aux;

    for (i = 0; i < tamanho - 1; i++) {
        for (j = 0; j < tamanho - i - 1; j++) {
            if (strcmp(vetor[j].titulo, vetor[j + 1].titulo) > 0) {
                aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }
}

void ordenaTituloDecrescente(livro vetor[], int tamanho) {
    int i, j;
    livro aux;

    for (i = 0; i < tamanho - 1; i++) {
        for (j = 0; j < tamanho - i - 1; j++) {
            if (strcmp(vetor[j].titulo, vetor[j + 1].titulo) < 0) {
                aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }
}

EMSCRIPTEN_KEEPALIVE
int get_tam() {
    return TAM;
}

EMSCRIPTEN_KEEPALIVE
char* get_livro_titulo(int idx) {
    if (idx >= 0 && idx < TAM) {
        return livros[idx].titulo;
    }
    return "";
}

EMSCRIPTEN_KEEPALIVE
float get_livro_preco(int idx) {
    if (idx >= 0 && idx < TAM) {
        return livros[idx].preco;
    }
    return 0.0f;
}

EMSCRIPTEN_KEEPALIVE
void ordenar(int tipo) {
    switch(tipo) {
        case 0: ordenaPrecoCrescente(livros, TAM); break;
        case 1: ordenaPrecoDecrescente(livros, TAM); break;
        case 2: ordenaTituloCrescente(livros, TAM); break;
        case 3: ordenaTituloDecrescente(livros, TAM); break;
    }
}

void main() {
  return;
}
