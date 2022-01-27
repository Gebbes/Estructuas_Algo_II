#include <stdlib.h>
#include <stdio.h>
#include "heap.h"
#include <string.h>


void prueba_heap_vacio(){
    heap_t *heap = heap_crear(strcmp);
}


void pruebas_heap(){
    prueba_heap_vacio();
}