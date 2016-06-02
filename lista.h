//
// Created by gabriel on 5/12/16.
//

#ifndef LPAVALIACAO2_LISTA_H
#define LPAVALIACAO2_LISTA_H


typedef struct ListNode{
    int value;
    ListNode * next;
    ListNode * prev;
};

typedef ListNode * ListNodePtr;

typedef struct Lista{
    int tamanho;
    ListNodePtr inicio;
    ListNodePtr fim;
};

Lista LIS_Criar_Lista();

bool LIS_Adicionar_Elemento(Lista & lista, int valor, int posicao);

bool LIS_Set_Elemento(Lista & lista, int valor, int posicao);

int LIS_Recuperar_Elemento(Lista & lista, int posicao);

int LIS_Indice_Do_Elemento(Lista & lista, int elemento);

int LIS_Remover_Elemento(Lista & lista, int posicao);

Lista LIS_Remover_Elementos(Lista & L1, Lista L2);

#endif //LPAVALIACAO2_LISTA_H
