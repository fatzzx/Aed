#include <stdio.h>
#include "pilha.h"
#include <stdbool.h>

int main() {
    PILHA p;
    char expressao[10000];
    bool valid = true;
    int i = 0;
    tp_item e;

    inicializando_pilha(&p);

    printf("Digite uma expressão: \n");
  
    fgets(expressao, sizeof(expressao), stdin);

    while (expressao[i] != '\0') {
        char symb = expressao[i];

        if (symb == '(' || symb == '[' || symb == '{') {
            empilha(symb, &p);
          
        } else if (symb == ')' || symb == ']' || symb == '}') {
            if (pilha_vazia(&p)) {
                valid = false;
                break;
              
            } else {
                desempilha(&p, &e);
                if (!((e == '(' && symb == ')') || (e == '[' && symb == ']') ||  (e == '{' && symb == '}'))){
                    valid = false;
                    break;
                }
            }
        }
        i++;
    }

    if (!pilha_vazia(&p)) {
        valid = false;
    }

    if (valid) {
        printf("correct");
    } else {
        printf("incorrect");
    }

    return 0;
}
