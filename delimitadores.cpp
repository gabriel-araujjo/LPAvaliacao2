//
// Created by gabriel on 5/12/16.
//

#include "delimitadores.h"
#include <stack>

enum token_da_expressao { PARENTESE, COLCHETE, CHAVE };

bool valida(char *expressao, int tamanho) {
    std::stack<token_da_expressao> stack;

    for(int i = 0; i < tamanho; i++) {
        switch (expressao[i]) {
            case '{':
                stack.push(CHAVE);
                break;
            case '[':
                stack.push(COLCHETE);
                break;
            case '(':
                stack.push(PARENTESE);
                break;
            case ')':
                if (stack.top() != PARENTESE) {
                    // Deveria encontrar um fecha parêntese, mas achou outra coisa
                    return false;
                }
                stack.pop();
                break;
            case ']':
                if (stack.top() != COLCHETE) {
                    // Deveria encontrar um fecha parêntese, mas achou outra coisa
                    return false;
                }
                stack.pop();
                break;
            case '}':
                if (stack.top() != CHAVE) {
                    return false;
                }
                stack.pop();
                break;
        }
    }
    return stack.empty();
}
