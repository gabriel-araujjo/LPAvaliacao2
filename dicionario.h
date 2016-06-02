//
// Created by gabriel on 5/12/16.
//

#ifndef LPAVALIACAO2_TABELA_H
#define LPAVALIACAO2_TABELA_H

typedef struct Dicionario {
    int ocupado;
    const char * * verbetes;
    const char * * definicoes;
};

Dicionario DICIO_Criar_Dicionario();

bool DICIO_Inserir(Dicionario & dicionario, char * verbete, char * definicao);

bool DICIO_Remover(Dicionario & dicionario, char * verbete);

const char * DICIO_Buscar(Dicionario & dicionario, char * verbete);

#endif //LPAVALIACAO2_TABELA_H
