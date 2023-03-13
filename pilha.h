#ifndef PILHA_H
#define PILHA_H
#include<stdio.h>
#define MAX_PILHA 100

typedef int tp_item;

typedef struct{
  int topo;
  tp_item pilha[MAX_PILHA];
}PILHA;

//inciando a pilha...
void inicializando_pilha (PILHA *p){
  p->topo = -1;
}


//Função empilha
int empilha(tp_item valor, PILHA *p){
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
int desempilha(PILHA *p, tp_item *e){
  if(p->topo >= 0){
    *e = p->pilha[p->topo];
    p->topo--;
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
int top(PILHA *p, tp_item *e){
  if (pilha_vazia(p)){
    return 0;
  }
  *e = p->pilha[p->topo];
  return 1;
}

//imprime os valores da pilha
void imprimePilha(PILHA *p){
  printf("A Pilha possui %d elementos:\n", p->topo+1);
  for(int i = (p->topo); i >= 0; i--){
    printf("%.2d na posicao %d \n", p->pilha[i], i);
  }
}

void retiraImpares(PILHA *p, PILHA *p2){
  while(p->topo !=0){
    empilha(p->pilha[p->topo], p2);
    p->topo--;
  }
}

//função para comparar pilhas
int compara_pilhas(PILHA p1, PILHA p2) {
  if (tamanho(&p1) != tamanho(&p2)) {
    return 0;
  }
  
  tp_item e1, e2;
  
  while (!pilha_vazia(&p1)) {
    desempilha(&p1, &e1);
    desempilha(&p2, &e2);
    if (e1 != e2) {
      return 0;
    }
  }
  return 1;
}

//empilha uma pilha na outra 
void empilhaPilhas(PILHA *p, PILHA *p2){
  while(!pilha_vazia(p2)){
    empilha(p2->pilha[p2->topo], p);
    p2->topo--;
  }
}

//outra função para empilhar
int empilha_pilha(PILHA *p, PILHA *p2){
  if(tamanho(p) + tamanho(p2) > MAX_PILHA){
    return 0;
  }
  while(!pilha_vazia(p2)){
    empilha(p2->pilha[p2->topo], p);
    p2->topo--;
  }
  return 1;
}


//Outra função de retirar impares pq n sei se a outra esta certa
void retira_impares(PILHA *p) {
  PILHA aux;
  tp_item e;
  inicializando_pilha(&aux);
  
  while (!pilha_vazia(p)) {
    desempilha(p, &e);
    if (e % 2 == 0) {
      empilha(e, &aux);
    }
  }
  while (!pilha_vazia(&aux)) {
    desempilha(&aux, &e);
    empilha(e, p);
  }
}



#endif
