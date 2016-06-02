//
// Created by gabriel on 5/12/16.
//

#ifndef LPAVALIACAO2_LISTA_CIRCULAR_H
#define LPAVALIACAO2_LISTA_CIRCULAR_H

#include "lista.h"

typedef struct FilaCircular {
    Lista lista;
    int tamanho_maximo;
    int indice_inicio;
    int tamanho_fila;
};

FilaCircular FILA_Criar_Fila(int tamanho_maximo);

bool FILA_Inserir(FilaCircular & fila, int elemento);

int FILA_Remover(FilaCircular & fila);

#endif //LPAVALIACAO2_LISTA_CIRCULAR_H
