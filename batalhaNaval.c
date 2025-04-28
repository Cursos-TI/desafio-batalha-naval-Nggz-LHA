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

    // Declara dois navios de tamanho 3
    int navioH[TAM_NAVIO] = {NAVIO, NAVIO, NAVIO};  // Navio horizontal
    int navioV[TAM_NAVIO] = {NAVIO, NAVIO, NAVIO};  // Navio vertical

    // Coordenadas iniciais dos navios
    int linhaH = 2, colH = 4;  // Navio horizontal começa em [2][4]
    int linhaV = 5, colV = 1;  // Navio vertical começa em [5][1]

    // Valida se os navios estão dentro dos limites
    if (colH + TAM_NAVIO <= TAM && linhaV + TAM_NAVIO <= TAM) {
        
        // Posiciona o navio horizontal
        for (int i = 0; i < TAM_NAVIO; i++) {
            tabuleiro[linhaH][colH + i] = navioH[i];
        }

        // Verifica se há sobreposição para o navio vertical
        int sobreposicao = 0;
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaV + i][colV] == NAVIO) {
                sobreposicao = 1;
                break;
            }
        }

        // Posiciona o navio vertical se não houver sobreposição
        if (!sobreposicao) {
            for (int i = 0; i < TAM_NAVIO; i++) {
                tabuleiro[linhaV + i][colV] = navioV[i];
            }
        } else {
            printf("Erro: os navios se sobrepõem!\n");
            return 1;
        }
    } else {
        printf("Erro: os navios estão fora dos limites do tabuleiro!\n");
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
