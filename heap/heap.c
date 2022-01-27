#include "heap.h"
#include <stdlib.h>
#include <stdbool.h>
#define CAPACIDAD_ESTANDARD 15
#define K_REDIMENSION 2


typedef int (*cmp_func_t) (const void *a, const void *b);

typedef struct heap
{
    void **datos;
    size_t cantidad;
    size_t capacidad;
    cmp_func_t comparacion;
} heap_t;



heap_t *heap_crear(cmp_func_t cmp)
{
    heap_t *heap = malloc(sizeof(heap_t));
    if(!heap) return NULL;

    heap->cantidad = 0;
    heap->capacidad = CAPACIDAD_ESTANDARD;
    heap->datos = malloc(sizeof(void *) * CAPACIDAD_ESTANDARD);
    heap->comparacion = cmp;
    return heap;
}


bool redimension(heap_t *heap, size_t n)
{
    heap->datos = realloc(heap->datos,n);
    return (heap->datos != NULL);
}


void heapify(void *arreglo[], size_t n, cmp_func_t cmp)
{
    if( n < 2) return;

    //upheap(arreglo, n, cmp);

    heapify(arreglo, n-1, cmp);
}


heap_t *heap_crear_arr(void *arreglo[], size_t n, cmp_func_t cmp)
{
    heap_t *heap = heap_crear(cmp);
    if(!heap) return NULL;

    heap->cantidad = n;

    while(heap->capacidad >= CAPACIDAD_ESTANDARD)
    {
        heap->capacidad = heap->capacidad * K_REDIMENSION;
    }

    if(heap->capacidad > CAPACIDAD_ESTANDARD && !redimension(heap, n)) return NULL;

    for(size_t i = 0; i < n; i++)
    {
        heap->datos[i] = arreglo[i];
    }

    heapify(heap->datos, heap->cantidad, cmp);
    return heap;
}


void heap_destruir(heap_t *heap, void destruir_elemento(void *e))
{
    if(destruir_elemento)
    {
        for(size_t i = 0; i < heap->cantidad; i++)
        {
        destruir_elemento(heap->datos[i]);
        }
    }

    free(heap->datos);
    free(heap);
}


size_t heap_cantidad(const heap_t *heap)
{
    return heap->cantidad;
}


bool heap_esta_vacio(const heap_t *heap)
{
    return (heap_cantidad(heap) == 0);
}


void heap_sort(void *elementos[], size_t cant, cmp_func_t cmp);


