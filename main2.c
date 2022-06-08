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

int compara_pilha(int ent[], int sai[], int e, int s){

    int i, j = 0, comp_pilha = 0;

    for(i=e; i>=0; i--){ //percorre i e j ao mesmo tempo
  
        if(sai[j] == ent[i] && j < s){
            comp_pilha++;
            j++;
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

int main(int argc, char** argv){
    
    int num, cod, entrada[Tamanho_Vet], saida[Tamanho_Vet],  e = 0, s = 0, i; 
    //cod = codigo de entrada
    //entrada = vetor que grava o numero que será inserido
    //saida = vetor do numero que deve ser retirado
    //e = parametro do vetor entrada
    //s = parametro do vetor saida

    printf("quantos operacoes serão gravadas?");
    scanf("%d", &num);

    for(i = 0; i <num; i++){

        scanf("%d", &cod);

        if(cod == 1){
            scanf("%d", &entrada[e]);
            e++;
        }

        if(cod == 2){
            scanf("%d", &saida[s]);
            s++;
        }
    }
    
    if(compara_pilha(entrada, saida, e, s) == True){
        printf("stack\n");
    }
    else if(compara_fila(entrada, saida, s) == True){
        printf("queue\n");
    }
    else printf("Impossible\n");

    return SUCESSO;
}
