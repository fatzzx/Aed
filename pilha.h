#ifndef PILHA_H
#define PILHA_H
#include<stdio.h>
#define MAX_PILHA 100

typedef struct{
  int topo;
  int pilha[MAX_PILHA];
}PILHA;

//inciando a pilha...
void inicializando_pilha (PILHA *p){
  p->topo = 0;
}


//Função empilha
void empilha(int valor, PILHA *p){
  if(p->topo < MAX_PILHA){
      p->pilha[p->topo] = valor;
      p->topo++;
  }
  else{
    printf("Nao ha mais espaco na pilha");
  }
}

//Função desempilha
void desempilha(PILHA *p){
  if(p->topo > 0){
    p->topo--;
    printf("Elemento retirado: %d\n", p->pilha[p->topo]);
  }
  else{
    printf("A pilha esta vazia");
  }
}

//vendo se a pilha ta vazia
int pilha_vazia(PILHA *p){
  if(p->topo == MAX_PILHA-1){
    return 1;
    }else{
    return 0;
    }
}

//vendo se a pilha ta cheia
int pilha_cheia(PILHA *p){
  if(p->topo >= MAX_PILHA){
    return 1;
  }
  else{
    return 0;
  }
}

//imprime os valores da pilha
void imprimePilha(PILHA *p){
  for(int i = (p->topo -1); i >= 0; i--){
    printf("%.2d na posicao %d \n", p->pilha[i], i);
  }
}

#endif