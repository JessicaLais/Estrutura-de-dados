#include <stdio.h>
#include <stdlib.h>

int somaArray(int arra[], int tamanho) {
    int soma = 0;
    for (int i = 0; i < tamanho; i++) {
        soma += arra[i];
    }
    return soma;
}

int main() {
    int array[] = {10,5,6,8};
    int tamanho = sizeof(array)/sizeof(array[0]);
    
    int resultado = somaArray(array,tamanho);
    
    printf("Soma dos numeros do array: %d\n", resultado);
    
    return 0;
}
