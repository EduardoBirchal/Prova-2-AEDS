#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define SUCESSO 0
#define True 1
#define False -1

int maiorElemento(int* vetor, int n) {
    int maior = INT_MIN; // Maior começa como o menor número possível pra um int, desse jeito pode ter número negativo no vetor

        for (int i = 0; i < n; i++) { // Loop que percorre o vetor. N é o número de elementos do vetor
            if (vetor[i] > maior) {
                maior = vetor[i];
            }
        }
    return maior;
}

int compara(int* ent, int* sai, int e, int s) {

    int i, j, comp = 0;

    for (i = 0; i < s; i++) {
        for (j = 0; j < e; j++) {
            if (sai[i] == ent[j]) {
                comp++;
            }
        }
    }

    if (comp == s) {
        return True;
    }
    else return False;

}

int main(int argc, char** argv) {

    int cod, * entrada, * saida, e = 0, s = 0;
    //cod = codigo de entrada
    //entrada = vetor que grava o numero que será inserido
    //saida = vetor do numero que deve ser retirado
    //e = parametro do vetor entrada
    //s = parametro do vetor saida

    FILE* arquivo;

    printf("Digite '1' para inserir um numero, '2' para  retirar e '0' para finalizar programa.\n");

    arquivo = fopen("entrada.bin", "r");
    if (arquivo == NULL) {
        printf("Erro de arquivo!");
        return 1;
    }

    do {

        fscanf(arquivo, "%i", &cod);

        if (cod == 1) {
            fscanf(arquivo, "%i", &entrada[e]);
            e++;
        }

        if (cod == 2) {
            fscanf(arquivo, "%i", &saida[s]);
            s++;
        }

    } while (cod != 0);

    if (compara(entrada, saida, e, s) == False) {
        printf("Impossible");
    }
    else {

    }

    fclose(arquivo);
    return SUCESSO;
}
