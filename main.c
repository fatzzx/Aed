#include <stdio.h>
#include "pilha.h"

int main(void) {

  PILHA pilha;

  inicializando_pilha(&pilha);
  
  empilha(10, &pilha);
  empilha(20, &pilha);
  imprimePilha(&pilha);
  
  desempilha(&pilha);

  imprimePilha(&pilha);
  
  return 0;
}