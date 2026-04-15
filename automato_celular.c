#include <stdio.h>

#define TAM 49

int main() {
    int vetor[TAM] = {0}, vetor_atualizado[TAM] = {0};
    int n;
    int central_1 = TAM / 2 - 1, central_2 = TAM / 2;

    // definicao do ponto central do vetor
    for (int i = 0; i < TAM; i++) {
        if (TAM % 2 == 0) {
            if (i == central_1 || i == central_2)
                vetor[i] = 1;
        } else {
            if (i == central_2)
                vetor[i] = 1;
        }
    }

    printf("Informe um valor N de iteracoes: ");
    scanf("%d", &n);

    // imprime o vetor atual
    for (int i = 0; i < TAM; i++)
        printf("%d  ", vetor[i]);

    // atualizacao do vetor de acordo com a regra v[i] = (v[i-1] + v[i+1]) % 2 (borda 0)
    for (int i = 0; i < n; i++) {
        printf("\n");

        for (int j = 0; j < TAM; j++) {
            if (j == 0)
                vetor_atualizado[j] = (0 + vetor[j+1]) % 2; // 0 ou vetor[TAM - 1] pra ser circular
            else if (j == TAM - 1)
                vetor_atualizado[j] = (vetor[j-1] + 0) % 2; // 0 ou vetor[0] pra ser circular
            else
                vetor_atualizado[j] = (vetor[j-1] + vetor[j+1]) % 2;
        }

        for (int j = 0; j < TAM; j++) {
            vetor[j] = vetor_atualizado[j];
            printf("%d  ", vetor[j]);
        }
    }

    return 0;
}
