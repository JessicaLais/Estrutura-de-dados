#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bubble_sort.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s <arquivo_de_entrada.txt>\n", argv[0]);
        return 1;
    }

    char *nome_fp = argv[1];
    char nome_fp_saida[] = "arq_palavras_ordenado.txt";

    FILE *fp = fopen(nome_fp, "r");
    if (!fp) {
        perror("Erro ao abrir arquivo de entrada");
        return 1;
    }

    FILE *fp_saida = fopen(nome_fp_saida, "w");
    if (!fp_saida) {
        perror("Erro ao criar arquivo de saída");
        fclose(fp);
        return 1;
    }

    int num_palavras = 0;
    char buffer[256];

    char **palavras = NULL;

    while (fgets(buffer, sizeof(buffer), fp)) {
        strtok(buffer, "\n");
        palavras = realloc(palavras, (num_palavras + 1) * sizeof(char *));
        palavras[num_palavras] = strdup(buffer);
        num_palavras++;
    }

    bubbleSort(palavras, num_palavras);

    for (int i = 0; i < num_palavras; i++) {
        fprintf(fp_saida, "%s\n", palavras[i]);
        free(palavras[i]);
    }

    free(palavras);

    fclose(fp);
    fclose(fp_saida);

    printf("Palavras ordenadas com sucesso em %s\n", nome_fp_saida);

    return 0;
}
