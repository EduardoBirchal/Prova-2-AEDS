#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define SUCESSO 0
#define True 1
#define False -1
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

int compara_se_impossible(int ent[], int sai[], int e, int s){

    int i, j, comp = 0;

    for(i = 0; i < s; i++){
        for(j = 0; j<e; j++){
            if(sai[i] == ent[j]){
                comp++;
            }
        }
    }

    if(comp == s){
        return True;
    }
    else return False;


}


int compara_pilha(int ent[], int sai[], int e, int s){

    int i, j, comp_pilha=0;

    for(i=e, j=0; i>=0, j < s; i--, j++){ //percorre i e j ao mesmo tempo
  
        if(sai[j] == ent[i]){
            comp_pilha++;
        }
    }

    if(comp_pilha == s){
        return True;
    }
    else return False;
}

int compara_fila(int ent[], int sai[], int s){

    int i, comp_fila = 0;

    for(i = 0; i < s; i++){
        if(sai[i] == ent[i]){
            comp_fila++;
        }
    }

    if(comp_fila == s){
        return True;
    }
    else return False;

}

int prioridade(int ent[], int sai[], int e, int s){

    int i, j, comp_prio = 0;

    for(i = 0; i < s; i++){
        if(sai[i] == maiorElemento(ent, e)){
            comp_prio++;
            for(j=0; j<e; j++){
                if(ent[j] == maiorElemento(ent, e)){
                    ent[j] = 0;
                }
            }
        }
    }

    if(comp_prio == s){
        return True;
    }
    else return False;

}

int deletarElemento(int vet[], int alvo) {
    int i = 0;

    do {
        if (vet[i] == alvo) {
            vet[i] = 0;
            return SUCESSO;
        }
        i++;
    } while (vet[i] != NULL);

    return -1;
}

int main(int argc, char** argv) {

    int cod, entrada[Tamanho_Vet], e = 0, s = 0, numInstrucoes = 0, num;
    //cod = codigo de entrada
    //entrada = vetor que grava o numero que será inserido
    //saida = vetor do numero que deve ser retirado
    //e = parametro do vetor entrada
    //s = parametro do vetor saida

    printf("Digite '1' para inserir um numero, '2' para  retirar e '0' para finalizar programa.\n");

    /*======================================================*/
    do {
        e = 0;
        printf("Digite 0 para sair\nNumero de instrucoes: ");
        scanf("%i", &numInstrucoes);

        for (int i = 0; i < numInstrucoes; i++) {

            printf("> ");
            scanf("%i %i", &cod, &num);

            if (cod == 1) {
                entrada[e] = num;
                e++;
            }

            if (cod == 2) {
                // compara()
                if (deletarElemento(entrada, num) == 1) {

                }
            }

        }
    } while (numInstrucoes != 0);
    /*======================================================*/

    return SUCESSO;
}
