#include "pila.h"
#include <stdlib.h>
#define CAPACIDAD_ESTANDARD 20 
#define K_REDIMENSION 2  
#define MIN_OCUPACION 4  




/* Definición del struct pila proporcionado por la cátedra.
 */
struct pila {
    void **datos;
    size_t cantidad;   // Cantidad de elementos almacenados.
    size_t capacidad;  // Capacidad del arreglo 'datos'.
};

/* *****************************************************************
 *                    PRIMITIVAS DE LA PILA
 * *****************************************************************/

// ...

pila_t *pila_crear(void){
    pila_t* pila = malloc(sizeof(pila_t));
    if(pila == NULL){
        return NULL;
    }
    pila->cantidad = 0;
    pila->capacidad = CAPACIDAD_ESTANDARD;
    pila->datos = malloc(sizeof(void*)*CAPACIDAD_ESTANDARD);
    if(pila->datos == NULL){
        free(pila);
        return NULL;
    }
    return pila;
}


bool pila_esta_vacia(const pila_t *pila){
    return (pila->cantidad == 0);
}


bool redimension(pila_t *pila, size_t nueva_capacidad){   
    void ** aux = realloc(pila->datos, sizeof(void*) * nueva_capacidad );
    if(aux == NULL){
        return false;
    }                     // Devuelve true en caso de exito, false en caso de fallas
    pila->datos = aux;
    pila->capacidad = nueva_capacidad;
    return true;
}


void pila_destruir(pila_t *pila){
    free(pila->datos);
    free(pila);
}


bool pila_apilar(pila_t *pila, void *p_valor){
    if(pila->cantidad == pila->capacidad){
        size_t nueva_capacidad = pila->capacidad * K_REDIMENSION;
        bool redimension_ok = redimension(pila, nueva_capacidad);
        if(! redimension_ok) return false;
    }
    pila->datos[pila->cantidad] = p_valor;
    pila->cantidad += 1;
    return true;
}


void *pila_ver_tope(const pila_t *pila){
    if(pila_esta_vacia(pila)){
        return NULL;
    }
    size_t ultima_posicion = (pila->cantidad) - 1;   //  Se usa unicamente para mejorar
    return pila->datos[ultima_posicion];          // legibilidad
}


void *pila_desapilar(pila_t *pila){
    if(pila_esta_vacia(pila)){
        return NULL;
    }
    void *tope = pila_ver_tope(pila);
    pila->cantidad -= 1;
    if( pila->cantidad > pila->capacidad / MIN_OCUPACION)return tope; // Caso general
    size_t nueva_capacidad = pila->capacidad / K_REDIMENSION;
    if(nueva_capacidad >= CAPACIDAD_ESTANDARD)redimension(pila, nueva_capacidad);
    return tope; 
}

