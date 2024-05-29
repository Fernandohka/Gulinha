#include <stdio.h>
#include <stdlib.h>
#ifndef ATIVIDADE_H
#define ATIVIDADE_H

void push(int valor, int *pilha, int *size){
    realloc(pilha, sizeof(int) * ((*size) + 3));
    pilha[(*size)] = valor;
    (*size)++;
}

void pop(int *pilha, int *size){
    if(*size > 0)
    {
        (*size)--;
        realloc(pilha, sizeof(int) * ((*size) + 2));
    }
}

int top(int *pilha, int *size){
    if((*size) > 0)
    {
        return pilha[(*size) - 1];
    }
    return 0;
}




void enqueue(int valor, int *fila, int *size){
    fila[*size] = valor;
    (*size)++;
    realloc(fila, sizeof(int) * ((*size) + 2));
}

void dequeue(int *fila, int *size){
    if(*size > 0)
    {
        (*size)--;
        for(int i = 0; i < *size; i++)
        {
            fila[i] = fila[i + 1];
        }
        realloc(fila, sizeof(int) * ((*size) + 2));
    }
}

int nextqueue(int *fila){
    return fila[0];
}



#endif // !ATIVIDADE_H
