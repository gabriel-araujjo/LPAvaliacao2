//
// Created by gabriel on 5/12/16.
//

#include "fila_circular.h"

FilaCircular FILA_Criar_Fila(int tamanho_maximo) {
    Lista lista = LIS_Criar_Lista();

    for (int i = 0; i < tamanho_maximo; i++) {
        LIS_Adicionar_Elemento(lista, 1, 0);
    }

    FilaCircular filaCircular = {
            lista,
            tamanho_maximo,
            0/*indice de inicio*/,
            0/*tamanho na fila*/};
    return filaCircular;
}


bool FILA_Inserir(FilaCircular &fila, int elemento) {
    if (fila.tamanho_fila >= fila.tamanho_maximo)
        return false;
    LIS_Set_Elemento(fila.lista, elemento, (fila.indice_inicio + fila.tamanho_fila) % fila.tamanho_maximo);
    fila.tamanho_fila++;
    return true;
}

int FILA_Remover(FilaCircular &fila) {
    if (fila.tamanho_fila == 0)
        return 0;
    int elemento = LIS_Recuperar_Elemento(fila.lista, fila.indice_inicio);
    fila.indice_inicio = ( fila.indice_inicio + 1 ) % fila.tamanho_maximo;
    fila.tamanho_fila--;
    return elemento;
}
