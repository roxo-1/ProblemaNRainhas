#include <stdio.h>
#include <stdbool.h>

int count=0;
bool eh_seguro(int tabuleiro[], int linha, int coluna){
    for (int i = 0; i < linha; i++) {
        if (tabuleiro[i] == coluna || tabuleiro[i] - i == coluna - linha || tabuleiro[i] + i == coluna + linha) {
            return false;
        }
    }
    return true;
}

void resolve_n_rainhas(int N, int tabuleiro[], int linha){
    if(linha==N){
        count++;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (tabuleiro[i] == j) {
                    printf("R ");  // Imprime 'R' para rainha
                } else {
                    printf("X ");  // Imprime 'X' para espaço vazio
                }
            }
            printf("\n");
        }
        printf("\n");
        return;
    }

    for (int col = 0; col < N; col++) {
        if (eh_seguro(tabuleiro, linha, col)) {
            tabuleiro[linha] = col;  // Coloca a rainha na posição (linha, col)
            resolve_n_rainhas(N, tabuleiro, linha + 1);  // Chama recursivamente para a próxima linha
        }
    }
}

int main(){
    int N;
    printf("Informe a quantidade de rainhas N: ");
    scanf("%d", &N);
    int tabuleiro[N];
    resolve_n_rainhas(N, tabuleiro, 0);
    if (count == 0) {
        printf("Nenhuma solução encontrada para N = %d.\n", N);
    } else {
        printf("Total de soluções: %d\n", count);
    }
    return 0;
}