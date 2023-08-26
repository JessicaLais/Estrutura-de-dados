#include <stdio.h>
#include <stdlib.h>

void menorMaiorNumero(int arra[], int tamanho, int *menor, int *maior){
    *menor = arra[0];
    *maior = arra[0];
    
    for (int i=1;i < tamanho;i++){
        if (arra[i]<*menor){
            *menor = arra[i];
        }
        if (arra[i]>*maior){
            *maior = arra[i];
        }
    }
}

int main(){
    int array[] = {4,3,9,6,2,18,17};
    int tamanho = sizeof(array)/sizeof(array[0]);
    int menor,maior;

    menorMaiorNumero(array,tamanho,&menor,&maior);
    printf("Menor numero e %d\n", menor);
    printf("Maior numero e %d\n", maior);
    
    return 0;
}

