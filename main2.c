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

int compara_pilha(int ent[], int n, int e){

    int i = e;

    if(n == ent[i]){
        return True;
    }
    

    return False;
}

int compara_fila(int ent[], int n, int s){

    int i;

    if(s == 0){
        s++;
    }

    for(i=0; i<s; i++){
        if(n == ent[i]){
            return True;
        }
    }
    return False;
}

int prioridade(int ent[], int n, int e){


    if(n == maiorElemento(ent, e)){
        return True;
    }

    return False;

}
void exclui_vetor(int ent[], int n, int e){

    int aux;

    for(int k = 0; k<e; k++){
        if(ent[k] == n){
            n=0;
            ent[k] = 0;
            aux = ent[k];
            ent[k] = ent[k +1];
            ent[k + 1] = aux;
                
        }
        printf("%d\n", ent[k]);
    }
}

int main(int argc, char** argv){
    
    int i, cod, entrada[Tamanho_Vet],  e = 0, s = 0, comp_p, comp_f, comp_fp, num, numInstrucoes; 


    /*======================================================*/
    do{
    printf("Digite 0 para sair\nNumero de instrucoes: ");
    scanf("%i", &numInstrucoes);

        for (i = 0; i < numInstrucoes; i++) {
            printf("%d", i);

            printf("> ");
            scanf("%i %i", &cod, &num);

            if (cod == 1) {
                entrada[e] = num;
                e++;
            }

            if (cod == 2) {
                for(int j=0; j <e; j++){
                    if( num == entrada[j]){
                        comp_p += compara_pilha(entrada, num, e);
                        comp_f += compara_fila(entrada, num, s);
                        comp_fp += prioridade(entrada, num, e);
                        s++;
                        exclui_vetor(entrada, num, e);
                        e--;
                    }
                }
            }
        }
        
        if(comp_p == s){
            printf("stack\n");
        }
        else if(comp_f == s){
            printf("queue\n");
        }
        else if(comp_fp == s){
            printf("priority queue\n");
        }   
    }while(numInstrucoes != 0);
    /*======================================================*/
    
    
    return SUCESSO;
}
