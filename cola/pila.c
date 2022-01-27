#include "pila.h"
#include <stdlib.h>
#define capacidad_estandar 20
#define k_redimension 2
#define min_ocupacion 4




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
    pila->capacidad = capacidad_estandar;
    pila->datos = malloc(sizeof(void*)*capacidad_estandar);
    if(pila->datos == NULL){
        free(pila);
        return NULL;
    }
    return pila;
}


bool pila_esta_vacia(const pila_t *pila){
    return (pila->cantidad == 0);
}


bool redimension(pila_t *pila){   
    void ** aux = realloc(pila->datos, sizeof(void*) * pila->capacidad );
    if(aux == NULL){
        return false;
    }                     // Devuelve true en caso de exito, false en caso de fallas
    pila->datos = aux;
    return true;
}


void pila_destruir(pila_t *pila){
    free(pila->datos);
    free(pila);
}


bool pila_apilar(pila_t *pila, void *p_valor){
    if(pila->cantidad == pila->capacidad){
        pila->capacidad = pila->capacidad * k_redimension;
        bool redimension_ok = redimension(pila);
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
    if( pila->cantidad > pila->capacidad / min_ocupacion)return tope; // Caso general
    if( pila->cantidad == 0 ){
        pila->capacidad = capacidad_estandar; // Al tener que elegir entre informar 
        redimension(pila);     // un fallo menor de no redimensionar para abajo, o
        return tope;           // no devolver el valor tope, priorizo devolver tope 
    }

    pila->capacidad = pila->capacidad / k_redimension;
    redimension(pila);
    
    return tope; 
}

