#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "atividade.h"

int addFila(int max, int *fila, int *size){
    if(max > 0)
    {
        int in = rand() % max;
        for(int i = 0; i < in; i++)
        {
            enqueue(1, fila, size);
        }
        return in;
    }
    return 0;
}

int removerFila(int max, int *fila, int *size){
    int out = rand() % max;
    if(out > (*size))
    {
        out = (*size);
    }
    for(int i = 0; i < out; i++)
    {
        dequeue(fila, size);
    }
    return out;
}



int main(){
    int horario = 8, *fila = malloc(4), size = 0;
    srand(time(NULL));

    printf("Mercado Mega Hiper Super Gulinha!\n");
   
    while (size > 0 || horario <= 22)
    {
        printf("Horario: %d\n", horario);

        // pessoas entrando
        printf("Entraram %d pessoas na fila.\n", addFila((horario < 17) ? 25 : ((horario < 22) ? 50 : 0), fila, &size));

        // pessoas compraram
        printf("%d pessoas finalizaram suas compras.\n", removerFila((horario < 22) ? 15 : 30, fila, &size));

        // pessoas desistindo
        printf("%d pessoas desistiram.\n", removerFila(5, fila, &size));
        if(horario != 24)
        {
            printf("Tem %d pessoas na fila.\n\n", size);
        }
        else
        {
            printf("%d pessoas foram expulsas.\n", size);
            size = 0;
        }

        horario++;
    }
    printf("Cabo");

    free(fila);
}
