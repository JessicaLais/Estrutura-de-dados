#include <stdio.h>
#include <stdlib.h>

int contaArray(int arra[], int tamanho, int busca){
    int soma = 0;
    
    for (int i=0;i < tamanho;i++){
        if (arra[i] == busca){
            soma++;
        }
    }
    return soma;
}

int main(){
    int array[]={10,18,9,6,11,18,4,5,18,6};
    int tamanho = sizeof(array)/sizeof(array[0]);
    int busca = 18;
    
    int resultado = contaArray(array,tamanho,busca);
    printf("Quantidade de vezes que %d aparece no array e %d\n", busca, resultado);
    
    return 0;
}
