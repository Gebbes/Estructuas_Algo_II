#include "cola.h"

#include <stdlib.h>

#include <stdio.h>


typedef struct nodos nodo_t;

typedef void (*destruir_t)(void *dato);

struct nodos {
    void *dato;
    nodo_t *siguiente;
};


struct cola {
    nodo_t *primero;
    nodo_t *ultimo;    
};


cola_t *cola_crear(void){
    cola_t *cola = malloc(sizeof(cola_t));
    if(! cola){                    // if malloc no me concedio memoria
        return NULL;  
    }
    cola->primero = NULL;
    cola->ultimo = NULL;
    return cola;
}



void cola_destruir(cola_t *cola, destruir_t destruir_dato){
    while(! cola_esta_vacia(cola)){
        void* dato = cola_desencolar(cola);
        if(destruir_dato){                     // If no me pasan NULL          
            destruir_dato(dato);
        }
    }
    free(cola);
}


bool cola_esta_vacia(const cola_t *cola){
    bool primero = (cola->primero == NULL);
    bool ultimo = (cola->ultimo == NULL);
    return (primero && ultimo);
    
}


nodo_t *crear_nodo(void* valor, nodo_t* siguiente){
    nodo_t *nodo = malloc(sizeof(nodo_t));
    if(! nodo)return NULL;           // Si malloc no me concedio memoria
    nodo->dato = valor;
    nodo->siguiente = siguiente;
    return nodo;
}


bool cola_encolar(cola_t *cola, void *valor){
    nodo_t *nodo = crear_nodo(valor, NULL);

    if(! nodo)return false;           // Si malloc no me concedio memoria

    if(cola_esta_vacia(cola)){ 
        cola->primero = nodo;
    }else{
        cola->ultimo->siguiente = nodo;
    }

    cola->ultimo = nodo;
    return true;
}


void *cola_ver_primero(const cola_t *cola){
    if(cola_esta_vacia(cola))return NULL;
    return cola->primero->dato;
}


void *cola_desencolar(cola_t *cola){
    if(cola_esta_vacia(cola))return NULL;

    if(cola->primero == cola->ultimo) cola->ultimo = NULL;

    nodo_t *aux_nodo = cola->primero->siguiente;
    void *aux_dato = cola->primero->dato;
    free(cola->primero);
    cola->primero = aux_nodo;           // Si es el ultimo, aux es null
    return aux_dato;
}

