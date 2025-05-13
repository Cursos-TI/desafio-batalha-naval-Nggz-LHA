#include <stdio.h>

#define TAM 10         // Tamanho do tabuleiro 10x10
#define TAM_NAVIO 3    // Tamanho fixo dos navios
#define NAVIO 3        // Valor para representar navio no tabuleiro

int main() {
    char linha[10] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J' };
    int tabuleiro[TAM][TAM];

    // Inicializa o tabuleiro com 0 (água)
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Navio horizontal
    int linhaH = 2, colH = 4;
    if (colH + TAM_NAVIO <= TAM) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            tabuleiro[linhaH][colH + i] = NAVIO;
        }
    } else {
        printf("Erro: navio horizontal fora dos limites!\n");
        return 1;
    }

    // Navio vertical
    int linhaV = 5, colV = 1;
    if (linhaV + TAM_NAVIO <= TAM) {
        int sobreposicao = 0;
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaV + i][colV] == NAVIO) {
                sobreposicao = 1;
                break;
            }
        }
        if (!sobreposicao) {
            for (int i = 0; i < TAM_NAVIO; i++) {
                tabuleiro[linhaV + i][colV] = NAVIO;
            }
        } else {
            printf("Erro: navios horizontal e vertical se sobrepõem!\n");
            return 1;
        }
    } else {
        printf("Erro: navio vertical fora dos limites!\n");
        return 1;
    }

    // Navio diagonal principal (↘)
    int linhaD1 = 0, colD1 = 0;
    if (linhaD1 + TAM_NAVIO <= TAM && colD1 + TAM_NAVIO <= TAM) {
        int sobreposicao = 0;
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaD1 + i][colD1 + i] == NAVIO) {
                sobreposicao = 1;
                break;
            }
        }
        if (!sobreposicao) {
            for (int i = 0; i < TAM_NAVIO; i++) {
                tabuleiro[linhaD1 + i][colD1 + i] = NAVIO;
            }
        } else {
            printf("Erro: navio diagonal principal se sobrepõe!\n");
            return 1;
        }
    } else {
        printf("Erro: navio diagonal principal fora dos limites!\n");
        return 1;
    }

    // Navio diagonal secundária (↙)
    int linhaD2 = 0, colD2 = 9;
    if (linhaD2 + TAM_NAVIO <= TAM && colD2 - TAM_NAVIO + 1 >= 0) {
        int sobreposicao = 0;
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaD2 + i][colD2 - i] == NAVIO) {
                sobreposicao = 1;
                break;
            }
        }
        if (!sobreposicao) {
            for (int i = 0; i < TAM_NAVIO; i++) {
                tabuleiro[linhaD2 + i][colD2 - i] = NAVIO;
            }
        } else {
            printf("Erro: navio diagonal secundária se sobrepõe!\n");
            return 1;
        }
    } else {
        printf("Erro: navio diagonal secundária fora dos limites!\n");
        return 1;
    }

    // Exibe o tabuleiro com cabeçalho
    printf("\nTabuleiro Batalha Naval (0 = água, 3 = navio):\n\n");

    // Cabeçalho das colunas
    printf("  ");
    for (int j = 0; j < TAM; j++) {
        printf("%d ", j);
    }
    printf("\n");

    // Exibe linhas com letras e valores do tabuleiro
    for (int i = 0; i < TAM; i++) {
        printf("%c ", linha[i]);
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
