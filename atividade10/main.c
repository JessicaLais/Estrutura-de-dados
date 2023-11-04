#include <stdio.h>
#include <stdlib.h>
#include "tabela_hash.h"

int main() {
    put("Argentina", "Buenos Aires");
    put("Inglaterra", "Londres");
    put("Brasil", "Brasília");

    char* capital = get("Brasil");
    if (capital != NULL) {
        printf("A capital do Brasil e: %s\n", capital);
    } else {
        printf("Brasil nao encontrado na tabela.\n");
    }
    capital = get ("Inglaterra");
    if (capital!=NULL){
            printf ("A capital da Inglaterra e: %s\n", capital);
    }else{
            printf ("Inglaterra nao encontrado na tabela.\n");
    }
 capital = get ("Argentina");
    if (capital!=NULL){
            printf ("A capital da Argentina e: %s\n", capital);
    }else{
            printf ("Argentina nao encontrado na tabela.\n");
    }

    capital = get("China");
    if (capital != NULL) {
        printf("A capital da China e: %s\n", capital);
    } else {
        printf("Canada nao encontrado na tabela.\n");
    }

    return 0;
}