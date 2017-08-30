
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef _COLA_H_
#define _COLA_H_

typedef struct info {
  int dato1;
  /* int dato2; */
}Info;


typedef struct nodo {
  Info *datos;
  struct nodo *siguiente;
}Nodo;


typedef struct cola {
  Nodo *inicio;
  Nodo *fin;
  int tamano;
}Cola;

/* Funciones de las operaciones básicas */
Cola *creaCola();
void destruirCola(Cola *c);
Nodo *crearNodo(Info *dato, Nodo *ptro);
Nodo *primero(Cola *c);
Nodo *ultimo(Cola *c);
bool vacia(Cola *c);
void ingresar(Info **pdato, int dato1);
bool push(Cola *c, int info);
Info *pop(Cola *c);

#endif /* _COLA_H_ */
