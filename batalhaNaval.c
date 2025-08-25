#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 5
#define NAVIOS 3

void inicializarTabuleiro(char t[TAM][TAM]) {
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            t[i][j] = '~'; // água
}

void posicionarNavios(char t[TAM][TAM]) {
    srand((unsigned)time(NULL));
    for (int n = 0; n < NAVIOS; n++) {
        int x, y;
        do {
            x = rand() % TAM;
            y = rand() % TAM;
        } while (t[x][y] == 'N');
        t[x][y] = 'N';
    }
}

void exibirTabuleiro(char t[TAM][TAM], int revelar) {
    printf("  ");
    for (int i = 0; i < TAM; i++) printf("%d ", i);
    printf("\n");
    for (int i = 0; i < TAM; i++) {
        printf("%d ", i);
        for (int j = 0; j < TAM; j++) {
            char c = t[i][j];
            if (c == 'N' && !revelar) c = '~';
            printf("%c ", c);
        }
        printf("\n");
    }
}

int main(void) {
    char tab[TAM][TAM];
    int acertos = 0;

    inicializarTabuleiro(tab);
    posicionarNavios(tab);

    printf("=== BATALHA NAVAL ===\n");
    while (acertos < NAVIOS) {
        int x, y;
        exibirTabuleiro(tab, 0);
        printf("Digite linha e coluna (0-%d): ", TAM - 1);
        if (scanf("%d %d", &x, &y) != 2) {
            printf("\nEntrada inválida. Encerrando.\n");
            return 0;
        }
        if (x < 0 || x >= TAM || y < 0 || y >= TAM) {
            printf("Coordenada fora do tabuleiro!\n");
            continue;
        }
        if (tab[x][y] == 'N') {
            printf("💥 Acertou um navio!\n");
            tab[x][y] = 'X';
            acertos++;
        } else if (tab[x][y] == '~') {
            printf("🌊 Água!\n");
            tab[x][y] = 'O';
        } else {
            printf("Você já tentou essa posição.\n");
        }
    }

    printf("\n🎉 Parabéns! Você afundou todos os navios!\n");
    exibirTabuleiro(tab, 1);
    return 0;
}
// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0
