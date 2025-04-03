#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 10
#define NAVIO 3
#define AFETADO 5
#define AGUA 0

void inicializarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

void exibirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    printf("  TABULEIRO BATALHA NAVAL\n\n");
    printf("   A B C D E F G H I J\n");
    
    for (int i = 0; i < TAMANHO; i++) {
        printf("%2d ", i + 1);
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Aplica uma habilidade especial no tabuleiro
//
// - Cone: Forma uma área triangular apontando para baixo.
// - Cruz: Afeta a linha e a coluna do ponto de origem.
// - Octaedro: Cria uma área losangular em torno do ponto de origem.
//
// Parâmetros:
// - tabuleiro: Matriz representando o tabuleiro do jogo.
// - linha: Linha do ponto de origem da habilidade.
// - coluna: Coluna do ponto de origem da habilidade.
// - tipo: Tipo de habilidade ('C' para Cone, 'X' para Cruz, 'O' para Octaedro).
void aplicarHabilidade(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, char tipo) {
    int i, j;
    
    if (tipo == 'C') { // Cone
        int tamanho = 3;
        for (i = 0; i < tamanho; i++) {
            for (j = -i; j <= i; j++) {
                int lin = linha + i, col = coluna + j;
                if (lin >= 0 && lin < TAMANHO && col >= 0 && col < TAMANHO) {
                    tabuleiro[lin][col] = AFETADO;
                }
            }
        }
    }
    else if (tipo == 'X') { // Cruz
        int tamanho = 2;
        for (i = -tamanho; i <= tamanho; i++) {
            int lin1 = linha + i, col1 = coluna;
            int lin2 = linha, col2 = coluna + i;
            if (lin1 >= 0 && lin1 < TAMANHO) tabuleiro[lin1][col1] = AFETADO;
            if (col2 >= 0 && col2 < TAMANHO) tabuleiro[lin2][col2] = AFETADO;
        }
    }
    else if (tipo == 'O') { // Octaedro
        int tamanho = 2;
        for (i = -tamanho; i <= tamanho; i++) {
            for (j = -tamanho + abs(i); j <= tamanho - abs(i); j++) {
                int lin = linha + i, col = coluna + j;
                if (lin >= 0 && lin < TAMANHO && col >= 0 && col < TAMANHO) {
                    tabuleiro[lin][col] = AFETADO;
                }
            }
        }
    }
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO];
    inicializarTabuleiro(tabuleiro);

    // Posicionamento de exemplo de navios
    tabuleiro[2][3] = NAVIO;
    tabuleiro[2][4] = NAVIO;
    tabuleiro[2][5] = NAVIO;
    
    // Aplicando habilidades
    aplicarHabilidade(tabuleiro, 4, 4, 'C'); // Cone
    aplicarHabilidade(tabuleiro, 7, 7, 'X'); // Cruz
    aplicarHabilidade(tabuleiro, 2, 2, 'O'); // Octaedro
    
    // Exibir tabuleiro
    exibirTabuleiro(tabuleiro);
    return 0;
}
