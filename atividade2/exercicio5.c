#include <stdio.h>
#include <stdlib.h>

void multiplica(int arra1[], int arra2[], int resultado[], int tamanho){
    for (int i=0;i < tamanho;i++){
        resultado[i] = arra1[i] * arra2[i];
    }
}

int main() {
    int array1[] = {18, 10, 5, 4};
    int array2[] = {15, 2, 11, 32};
    int tamanho = sizeof(array1)/sizeof(array1[0]);
    int resultado[tamanho];
    
    multiplica(array1, array2, resultado, tamanho);
    for (int i=0;i < tamanho;i++){
        printf("%d", resultado[i]);
        if (i < tamanho - 1){
            printf(",");
        }
    }
    return 0;
}
