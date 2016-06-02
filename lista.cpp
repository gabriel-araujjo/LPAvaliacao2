//
// Created by gabriel on 5/12/16.
//

#include "lista.h"

Lista LIS_Criar_Lista() {
    Lista lista = {0, new ListNode, new ListNode};
    lista.inicio->next = lista.fim;
    lista.fim->prev = lista.inicio;
    return lista;
}

bool LIS_Adicionar_Elemento(Lista & lista, int valor, int posicao) {
    ListNodePtr novo_no, cursor;
    int cursor_index;

    while (posicao > lista.tamanho || posicao < 0 || valor == 0)
        return false;

    novo_no = new ListNode;
    novo_no->value = valor;


    if (posicao > lista.tamanho/2) {
        cursor = lista.fim;
        cursor_index = lista.tamanho;
        while (cursor_index > posicao) {
            cursor = cursor->prev;
            cursor_index--;
        };
        novo_no->next = cursor;
        novo_no->prev = cursor->prev;
        novo_no->prev->next = novo_no;
        cursor->prev = novo_no;
    } else {
        cursor = lista.inicio;
        cursor_index = 0;
        while (cursor_index < posicao) {
            cursor = cursor->next;
            cursor_index++;
        }
        novo_no->prev = cursor;
        novo_no->next = cursor->next;
        novo_no->next->prev = novo_no;
        cursor->next = novo_no;
    }
    lista.tamanho++;
    return true;
}

int LIS_Recuperar_Elemento(Lista & lista, int posicao) {
    ListNodePtr cursor;
    int cursor_index;

    if (posicao >= lista.tamanho || posicao < 0) return 0;


    if (posicao > lista.tamanho/2) {
        cursor = lista.fim;
        cursor_index = lista.tamanho;
        while (cursor_index > posicao) {
            cursor = cursor->prev;
            cursor_index--;
        };
    } else {
        cursor = lista.inicio;
        cursor_index = 0;
        while (cursor_index <= posicao) {
            cursor = cursor->next;
            cursor_index++;
        }
    }
    return cursor->value;
}

int LIS_Remover_Elemento(Lista &lista, int posicao) {
    ListNodePtr cursor;
    int cursor_index, value;

    while (posicao > lista.tamanho || posicao < 0)
        return 0;

    if (posicao > lista.tamanho/2) {
        cursor = lista.fim;
        cursor_index = lista.tamanho;
        while (cursor_index > posicao) {
            cursor = cursor->prev;
            cursor_index--;
        };
    } else {
        cursor = lista.inicio;
        cursor_index = 0;
        while (cursor_index <= posicao) {
            cursor = cursor->next;
            cursor_index++;
        }
    }
    cursor->prev->next = cursor->next;
    cursor->next->prev = cursor->prev;
    lista.tamanho--;
    value = cursor->value;
    delete cursor;
    return value;
}

Lista LIS_Remover_Elementos(Lista &L1, Lista L2) {
    Lista elementos_nao_removidos = LIS_Criar_Lista();
    int indice;
    for (ListNodePtr no = L2.inicio->next; no != L2.fim; no = no->next) {
        indice = LIS_Indice_Do_Elemento(L1, no->value);
        if (!LIS_Remover_Elemento(L1, indice)) { //Não foi possível remover
            LIS_Adicionar_Elemento(elementos_nao_removidos, no->value, elementos_nao_removidos.tamanho);
        }
    }
    return elementos_nao_removidos;
}

int LIS_Indice_Do_Elemento(Lista &lista, int elemento) {
    ListNodePtr no;
    int indice;
    for (indice = 0, no = lista.inicio->next; no != lista.fim; no = no->next, ++indice) {
        if (elemento == no->value) return indice;
    }
    return -1;
}

bool LIS_Set_Elemento(Lista &lista, int valor, int posicao) {
    ListNodePtr cursor;
    int cursor_index;

    while (posicao > lista.tamanho || posicao < 0)
        return 0;

    if (posicao > lista.tamanho/2) {
        cursor = lista.fim;
        cursor_index = lista.tamanho;
        while (cursor_index > posicao) {
            cursor = cursor->prev;
            cursor_index--;
        };
    } else {
        cursor = lista.inicio;
        cursor_index = 0;
        while (cursor_index <= posicao) {
            cursor = cursor->next;
            cursor_index++;
        }
    }
    cursor->value = valor;
    return true;
}
