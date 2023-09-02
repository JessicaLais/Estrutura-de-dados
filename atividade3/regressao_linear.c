#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Ponto {
    int x;      
    float y;    
};

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s <arquivo.csv>\n", argv[0]);
        return 1;
    }
    
    FILE *arquivo = fopen(argv[1], "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s.\n", argv[1]);
        return 1;
    }

    int numRegistros = 0;
    char linha[256];
    while (fgets(linha, sizeof(linha), arquivo)) {
        numRegistros++;
    }
   
    struct Ponto *pontos = (struct Ponto *)malloc(numRegistros * sizeof(struct Ponto));

    fseek(arquivo, 0, SEEK_SET);

    for (int i = 0; i < numRegistros; i++) {
        int x;        
        float y;      
        if (fscanf(arquivo, "%d,%f", &x, &y) != 2) {
            printf("Erro ao ler o arquivo CSV.\n");
            free(pontos);
            fclose(arquivo);
            return 1;
        }
        pontos[i].x = x;
        pontos[i].y = y;
    }

    float mediaX = 0.0;   
    float mediaY = 0.0;   
    for (int i = 0; i < numRegistros; i++) {
        mediaX += pontos[i].x;
        mediaY += pontos[i].y;
    }
    mediaX /= numRegistros;
    mediaY /= numRegistros;

    float somaNumerador = 0.0;   
    float somaDenominador = 0.0; 
    for (int i = 0; i < numRegistros; i++) {
        somaNumerador += (pontos[i].x - mediaX) * (pontos[i].y - mediaY);
        somaDenominador += pow(pontos[i].x - mediaX, 2);
    }
    float inclinacao = somaNumerador / somaDenominador;
    float interceptacao = mediaY - inclinacao * mediaX;

    printf("Equação da regressão linear: y = %.4fx + %.4f\n", inclinacao, interceptacao);
    free(pontos);
    fclose(arquivo);
    return 0;
}
