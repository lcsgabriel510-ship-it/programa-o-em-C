#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define TAMANHO 8

// Função para inicializar o tabuleiro
void inicializar_tabuleiro(char tabuleiro[TAMANHO][TAMANHO]) {
    char pecas_iniciais[] = {'T', 'C', 'B', 'D', 'R', 'B', 'C', 'T'}; // Torre, Cavalo, Bispo, Dama, Rei...

    // Peças pretas (vão ser as letras minúsculas)
    for (int i = 0; i < TAMANHO; i++) {
        tabuleiro[0][i] = tolower(pecas_iniciais[i]);
        tabuleiro[1][i] = 'p';
        tabuleiro[6][i] = 'P';
        tabuleiro[7][i] = pecas_iniciais[i];
    }

    // quadradinho vazios
    for (int i = 2; i < 6; i++)
        for (int j = 0; j < TAMANHO; j++)
            tabuleiro[i][j] = '.';
}

// Função para mostrar o tabuleiro
void mostrar_tabuleiro(char tabuleiro[TAMANHO][TAMANHO]) {
    printf("\n    a b c d e f g h\n");
    printf("   -----------------\n");
    for (int i = 0; i < TAMANHO; i++) {
        printf("%d | ", 8 - i);
        for (int j = 0; j < TAMANHO; j++) {
            printf("%c ", tabuleiro[i][j]);
        }
        printf("|\n");
    }
    printf("   -----------------\n");
}

// Converter coordenadas tipo 'e2' para índices da matriz
int coluna_para_indice(char c) {
    return c - 'a';
}

int linha_para_indice(char c) {
    return 8 - (c - '0');
}

// Função que move uma peça
void mover_peca(char tabuleiro[TAMANHO][TAMANHO], char origem[3], char destino[3]) {
    int linha_origem = linha_para_indice(origem[1]);
    int coluna_origem = coluna_para_indice(origem[0]);
    int linha_destino = linha_para_indice(destino[1]);
    int coluna_destino = coluna_para_indice(destino[0]);

    char peca = tabuleiro[linha_origem][coluna_origem];

    if (peca == '.') {
        printf("❌ Nenhuma peça na origem!\n");
        return;
    }

    tabuleiro[linha_destino][coluna_destino] = peca;
    tabuleiro[linha_origem][coluna_origem] = '.';
}

int main() {
    char tabuleiro[TAMANHO][TAMANHO];
    inicializar_tabuleiro(tabuleiro);

    char origem[3], destino[3];

    printf("=== Simulador simples de Xadrez ===\n");
    mostrar_tabuleiro(tabuleiro);

    while (1) {
        printf("\nDigite o movimento (por exemplo: d6 d8) ou digite 'sair': ");
        if (scanf("%2s", origem) != 1)
            break;

        if (strcmp(origem, "sair") == 0)
            break;

        scanf("%2s", destino);

        mover_peca(tabuleiro, origem, destino);
        mostrar_tabuleiro(tabuleiro);
    }

    printf("Jogo encerrado.\n");
    return 0;
}
