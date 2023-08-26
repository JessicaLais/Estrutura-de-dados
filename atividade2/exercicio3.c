#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int buscaString(char *arra[], int tamanho, char *busca){
    for (int i=0;i < tamanho;i++){
        if (strcmp(arra[i],busca) == 0){
            return 1; 
        }
    }
    return 0;
}

int main(){
    char *array[]={"folha", "Jamaica", "EBD", "K"};
    int tamanho = sizeof(array)/sizeof(array[0]);
    char *busca = "EBD";
    
    int resultado = buscaString(array,tamanho,busca);
    printf("Resultado da busca: %d\n", resultado);

    return 0;
}
