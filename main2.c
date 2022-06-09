#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define SUCESSO 0
#define True 1
#define False 0
#define Tamanho_Vet (500)

int maiorElemento(int ent[], int e) {
    int maior = INT_MIN; // Maior começa como o menor número possível pra um int, desse jeito pode ter número negativo no vetor

    for (int i = 0; i < e; i++) { // Loop que percorre o vetor. N é o número de elementos do vetor
        if (ent[i] > maior) {
            maior = ent[i];
        }
    }
    return maior;
}

int compara_pilha(int ent[], int n, int e) {
    if (n == ent[e - 1]) {
        return True;
    }

    return False;
}

int compara_fila(int ent[], int n, int s) {
    int i;

    if (s == 0) {
        s++;
    }
    for (i = 0; i < s; i++) {
        if (n == ent[i]) {
            return True;
        }
    }

    return False;
}

int prioridade(int ent[], int n, int e) {
    if (n == maiorElemento(ent, e)) {
        return True;
    }

    return False;
}

void exclui_vetor(int ent[], int n, int e) {
    int aux;

    for (int k = 0; k < e; k++) {
        if (ent[k] == n) {
            n = 0;
            ent[k] = 0;
            aux = ent[k];
            ent[k] = ent[k + 1];
            ent[k + 1] = aux;
        }
    }
}

int main(int argc, char** argv) {
    int i, cod, entrada[Tamanho_Vet], e, s, p, f, fp, num, numInstrucoes, imp = 0;
    FILE* arquivo;

    arquivo = fopen("entrada.txt", "r");
    if (arquivo == NULL) {
        printf("Erro de arquivo!");
        return 1;
    }

    do {
        e = 0;
        s = 0;
        p = 0;
        f = 0;
        fp = 0;
        imp = 0;

        fscanf(arquivo, "%i", &numInstrucoes);

        for (i = 0; i < numInstrucoes; i++) {
            fscanf(arquivo, "%i %i", &cod, &num);

            if (cod == 1) {
                entrada[e] = num;
                e++;
            }
            if (cod == 2) {
                if (num != entrada[0] && num != entrada[e - 1] && num != maiorElemento(entrada, e)) {
                    //checa se o numero é diferente do começo, do fim ou do maior numero do vetor.
                    imp++;
                }
                p += compara_pilha(entrada, num, e);
                f += compara_fila(entrada, num, s);
                fp += prioridade(entrada, num, e);
                s++;
                exclui_vetor(entrada, num, e);
                e--;
            }
        }

        if (imp != 0) {
            printf("impossible\n");
        }
        else {
            if (p == s && fp == s || fp == s && f == s) {
                printf("not sure\n");
            }
            else {
                if (p == s) {
                    printf("stack\n");
                }
                if (f == s) {
                    printf("queue\n");
                }
                if (fp == s) {
                    printf("priority queue\n");
                }
            }
        }
    } while (getc(arquivo) != EOF);

    fclose(arquivo);
    return SUCESSO;
}
