#include <stdio.h>

#include <stdlib.h>

#include <limits.h>

#define SUCESSO 0
#define True 1
#define False 0
#define Tamanho_Vet 500

int maiorElemento(int ent[], int e) {
    int maior = INT_MIN; // Maior começa como o menor número possível pra um int, desse jeito pode ter número negativo no vetor

    for (int i = 0; i < e; i++) { // Loop que percorre o vetor. 'e' é o número de elementos do vetor
        if (ent[i] > maior) {
            maior = ent[i];
        }
    }
    return maior;
}

int compara_pilha(int ent[], int n, int e) { // Vê se a operação é uma operação de pilha checando se o número é o último do vetor
    if (n == ent[e - 1]) {
        return True;
    }

    return False;
}

int compara_fila(int ent[], int n, int s) { // Vê se a operação é uma operação de fila ao checar se o número é o primeiro do vetor
    if (n == ent[0]) {
        return True;
    }

    return False;
}

int prioridade(int ent[], int n, int e) { // Vê se a operação é uma operação de fila de prioridade checando se o número é o maior do vetor
    if (n == maiorElemento(ent, e)) {
        return True;
    }

    return False;
}

void exclui_vetor(int ent[], int n, int e) { // Exclui um número do vetor transformando ele em 0 e empurrando ele pro fim do vetor
    int aux;

    for (int k = 0; k < e; k++) {
        if (ent[k] == n) {
            n = 0; // Uma vez que encontra o número, transforma ele em 0 e a partir daí vai só empurrar o 0 pra frente
            ent[k] = 0;
            aux = ent[k];
            ent[k] = ent[k + 1];
            ent[k + 1] = aux;
        }
    }
}

int main(int argc, char** argv) {
    // Declarando variáveis
    int i, cod, entrada[Tamanho_Vet], e, s, p, f, fp, num, numInstrucoes, imp = 0;
    FILE* arquivo;

    // Abrindo o arquivo para leitura
    arquivo = fopen("entrada.txt", "r");
    if (arquivo == NULL) {
        printf("Erro de arquivo!");
        return 1;
    }

    // Loop de leitura de instruções
    do {
        // Resetando as variáveis
        e = 0; // Número de elementos do vetor
        s = 0; // Número de elementos removidos do vetor
        p = 0; // Aumenta em 1 quando uma operação pode ser uma operação de pilha
        f = 0; // Aumenta em 1 quando uma operação pode ser uma operação de fila
        fp = 0; // Aumenta em 1 quando uma operação pode ser uma operação de fila de prioridade
        imp = 0; // Aumenta em 1 quando uma operação é impossível

        fscanf(arquivo, "%i", &numInstrucoes);

        // Loop de execução de instruções
        for (i = 0; i < numInstrucoes; i++) {
            fscanf(arquivo, "%i %i", &cod, &num);
            if (cod == 1) {
                entrada[e] = num;
                e++;
            }
            if (cod == 2) {
                if (num != entrada[0] && num != entrada[e - 1] && num != maiorElemento(entrada, e)) { // Checa se o numero é diferente do começo, do fim ou do maior número do vetor.
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
                else if (f == s) {
                    printf("queue\n");
                }
                else if (fp == s) {
                    printf("priority queue\n");
                }
                else {
                    printf("impossible\n");
                }
            }
        }
    } while (getc(arquivo) != EOF); // Faz o loop enquanto não chegar no EOF

    fclose(arquivo);
    return SUCESSO;
}
