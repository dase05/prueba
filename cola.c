#include "cola.h"

Cola *creaCola(){
  Cola *nueva;

  if(nueva = (Cola *) malloc(sizeof(Cola))){// Pide memoria para la Cola
      nueva->tamano = 0; // Cola vacía
      nueva->inicio = nueva->fin = NULL; // Inicio y Fin apuntan a NULL
    }
  return nueva;
}


void destruirCola(Cola *c){
  Nodo *aux;

  while(c->inicio != NULL){
      aux = c->inicio;
      c->inicio = c->inicio->siguiente;
      free(aux->datos);
      free(aux);
    }
	free(c);
}


Nodo *crearNodo(Info *dato, Nodo *ptro){
  Nodo *nuevo;
  if(nuevo = (Nodo *) malloc(sizeof(Nodo))) }// Pide memoria para el nodo
      nuevo->datos = dato;
      nuevo->siguiente = ptro;
    }
  return nuevo;
}


Nodo *primero(Cola *c){
  return c->inicio;
}


Nodo *ultimo(Cola *c){
  return c->fin;
}


bool vacia(Cola *c){
  return (c->inicio == NULL) ? true : false;
}


void ingresar(Info **pdato, int dato1){
  if(*pdato = (Info *) malloc(sizeof(Info)))    {
      /* Se almacena la información en Info */
      (*pdato)->dato1 = dato1;
      /* pdato->dato2 = dato2; */
      /* pdato->dato3 = dato3; */
  }else{
      printf("problemas en el push\n");
      exit(0);
    }
}


bool push(Cola *c, int info){
  Info *pdato;
  Nodo *aux;
  ingresar(&pdato, info);
  // Se crea un nodo con datos y apunta a NULL
  if(aux = crearNodo(pdato, NULL)) {//además, se almacena en aux
      if(vacia(c))
        c->inicio = aux;
      else
        c->fin->siguiente = aux;
      c->fin = aux;
      c->tamano++;
      return true;
    }else{
    return false;
    }
}


Info *pop(Cola *c){
  Nodo *aux;
  Info *dato;
  aux = c->inicio; //se guarda el nodo a eliminar (el primero) en un aux
  dato = aux->datos; //sus datos también
  c->inicio = aux->siguiente;
  c->tamano--;
  if(vacia(c))
    c->fin = NULL;
  free(aux->datos);
  free(aux);

  return dato;
}

