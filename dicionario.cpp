//
// Created by gabriel on 5/12/16.
//

#include <stddef.h>
#include "dicionario.h"


int PreHash(char * verbete) {
    return *verbete;
}

int Hash(int ascii_code) {
    return ascii_code - 'a';
}

Dicionario DICIO_Criar_Dicionario() {
    char * verbetes[26];
    char * definicoes[26];

    for (int i = 0; i < 26; i++) {
        verbetes[i] = NULL;
    }

    Dicionario dicionario = {0, verbetes, definicoes};

    return dicionario;
}

bool DICIO_Inserir(Dicionario &dicionario, char *verbete, char *definicao) {
    int posicao = Hash(PreHash(verbete));
    if (posicao < 26 && dicionario.verbetes[posicao] == NULL) {
        dicionario.verbetes[posicao] = verbete;
        dicionario.definicoes[posicao] = definicao;
        dicionario.ocupado++;
        return true;
    }
    return false;
}

bool DICIO_Remover(Dicionario &dicionario, char *verbete) {
    int posicao = Hash(PreHash(verbete));
    if (posicao < 26 && dicionario.verbetes[posicao] != NULL) {
        dicionario.verbetes[posicao] = NULL;
        dicionario.ocupado--;
        return true;
    }
    return false;
}

const char * DICIO_Buscar(Dicionario &dicionario, char *verbete) {
    int posicao = Hash(PreHash(verbete));
    if (posicao < 26 && dicionario.verbetes[posicao] != NULL) {
        return dicionario.verbetes[posicao];
    }
    return NULL;
}
