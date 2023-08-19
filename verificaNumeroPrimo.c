#include <stdio.h>

int main(int argc, char *argv[]){
    int numero = atoi(argv[1]);
    int resultado = verificaNumeroPrimo(numero);
    
    printf("%d\n", resultado);
    return 0;
}

int verificaNumeroPrimo(int n){
    if (n <= 1){
        return 0; 
    }
    for (int i = 2; i * i <= n; i++){
        if (n % i == 0){
            return 0; 
        }
    }
    return 1; 
}