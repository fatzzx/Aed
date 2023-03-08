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
  p->topo = -1;
}


//Função empilha
int empilha(int valor, PILHA *p){
  if(p->topo < MAX_PILHA){
      p->topo++;
      p->pilha[p->topo] = valor;
    return 1;
  }
  else{
    return 0;
  }
}

//Função desempilha
int desempilha(PILHA *p, int *e){
  if(p->topo >= 0){
    *e = p->pilha[p->topo];
    p->topo--;
    printf("Elemento retirado: %d\n", p->pilha[p->topo + 1]);
    return 1;
  }
  else{
    return 0;
  }
}

//vendo se a pilha ta vazia
int pilha_vazia(PILHA *p){
  if(p->topo == -1){
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

//ve o tamanho da pilha 
int tamanho(PILHA *p){
  return p->topo +1;
}

//ve o ultimo valor da pilha 
int top(PILHA *p, int *e){
  if (pilha_vazia(p)){
    return 0;
  }
  *e = p->pilha[p->topo];
  return 0;
}

//imprime os valores da pilha
void imprimePilha(PILHA *p){
  printf("A Pilha possui %d elementos:\n", p->topo+1);
  for(int i = (p->topo); i >= 0; i--){
    printf("%.2d na posicao %d \n", p->pilha[i], i);
  }
}

#endif
