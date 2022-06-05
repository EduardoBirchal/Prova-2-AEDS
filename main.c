#include <stdio.h>
#include <stdlib.h>
#define SUCESSO 0

int maiorElemento(int *vetor, int n) {
    int maior = INT_MIN // Maior começa como o menor número possível pra um int, desse jeito pode ter número negativo no vetor

    for (int i = 0; i < n; i++) { // Loop que percorre o vetor. N é o número de elementos do vetor
        if (vetor[i] > maior) {
            maior = vetor[i];
        }
    }
    return maior;
}

int main(int argc, char** argv)
{
    printf("Hello World!");
    return SUCESSO;
}
