#include <iostream>
#include "delimitadores.h"
#include "lista.h"
#include "fila_circular.h"
#include "dicionario.h"

using namespace std;


void questao1() {
    /**
     * Ver função
     *
     *      bool valida(char *)
     *
     * em delimitadores.(h/cpp)
     *
     */
    cout << "questao1" << endl;
    cout << "valida(\"10 x { 50 + 10 /[50 % 6) }\", 26) = "
    << (valida("10 x { 50 + 10 /[50 % 6) }", 26) ? "true": "false") << endl;

    cout << "valida(\"10 x { 50 + 10 /(50 % 6) }\", 26) = "
    << (valida("10 x { 50 + 10 /(50 % 6) }", 26) ? "true": "false")<< endl;
}

void questao2() {
    /**
     * Ver função
     *
     *      Lista LIS_Remover_Elementos(Lista & L1, Lista L2)
     *
     * em lista.(h/cpp)
     */
    cout << "questao2" << endl;
    Lista lista = LIS_Criar_Lista();
    for (int i = 10; i > 0; i--) {
        LIS_Adicionar_Elemento(lista, i, 0);
    }

    cout << "L1: " ;
    for(int i = 0; i < lista.tamanho; i++) {
        cout << LIS_Recuperar_Elemento(lista, i) << " ";
    }
    cout << endl;

    Lista toRemove = LIS_Criar_Lista();
    for (int i = 5; i > 0; i--) {
        LIS_Adicionar_Elemento(toRemove, i, 0);
    }

    for (int i = 20; i <= 25; i++) {
        LIS_Adicionar_Elemento(toRemove, i, 0);
    }

    cout << "L2: " ;
    for(int i = 0; i < toRemove.tamanho; i++) {
        cout << LIS_Recuperar_Elemento(toRemove, i) << " ";
    }
    cout << endl;

    cout << "Removendo L2 de L1 ... " << endl;

    Lista removido = LIS_Remover_Elementos(lista, toRemove);

    cout << "L1: ";

    for(int i = 0; i < lista.tamanho; i++) {
        cout << LIS_Recuperar_Elemento(lista, i) << " ";
    }
    cout << endl;

    cout << "elementos de L2 que não puderam ser removidos: ";

    for(int i = 0; i < removido.tamanho; i++) {
        cout << LIS_Recuperar_Elemento(removido, i) << " ";
    }
    cout << endl;

    cout << "L2: " ;
    for(int i = 0; i < toRemove.tamanho; i++) {
        cout << LIS_Recuperar_Elemento(toRemove, i) << " ";
    }
    cout << endl;

}

void questao3() {
    /**
     * Ver arquivos fila_circular.h e fila_circular.cpp
     */
    cout << "questao3" << endl;

    FilaCircular filaCircular = FILA_Criar_Fila(3);

    cout << "filaCircular.indice_inicio = " << filaCircular.indice_inicio << endl;
    FILA_Inserir(filaCircular, 1);
    cout << FILA_Remover(filaCircular) << endl;
    cout << "filaCircular.indice_inicio = " << filaCircular.indice_inicio << endl;
    FILA_Inserir(filaCircular, 2);
    FILA_Inserir(filaCircular, 3);
    FILA_Inserir(filaCircular, 4);
    cout << FILA_Remover(filaCircular) << endl;
    cout << FILA_Remover(filaCircular) << endl;
    cout << FILA_Remover(filaCircular) << endl;
    cout << FILA_Remover(filaCircular) << endl;

}

void questao4() {
    /**
     * Ver arquivos dicionario.h e dicionario.cpp
     */
    cout << "questao4" << endl;
}

int main() {

    questao1();
    cout << endl << endl << endl;
    questao2();
    cout << endl << endl << endl;
    questao3();
    cout << endl << endl << endl;

    return 0;
}