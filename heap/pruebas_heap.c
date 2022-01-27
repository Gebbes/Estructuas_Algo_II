#include "heap.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "testing.h"

/* *****************************************************************
 *                    FUNCIONES DE COMPARACION
 * *****************************************************************/

 int funcion_comparar_int(const void* a, const void* b){
    if(*( const int*) a > *(const int*) b){
         return 1;
    }
    if(*(const int*) a < *(const int*)b){
        return -1;
    }
     
     return 0;
 }

/* *****************************************************************
 *                    PRUEBAS PARA EL HEAP
 * *****************************************************************/

void pruebas_encolar_heap(){
    printf("\n\nPruebas encolar heap: \n");
    heap_t *heap = heap_crear(funcion_comparar_int);

    int datos[] = {30, 40, 10, 20};

    for(size_t i = 0; i < 4; i++){
        printf("\nDato: %d ", datos[i]);
        print_test("Encolar dato es true", heap_encolar(heap, &datos[i]));
        print_test("La cantidad de elementos es 1", heap_cantidad(heap) == 1);
        print_test("El maxiomo es correcto", heap_ver_max(heap) == &datos[i]);
        print_test("Heap esta vacio es false", !heap_esta_vacio(heap));
        print_test("Desencolamos, el dato obtenido es correcto", heap_desencolar(heap) == &datos[i]);
        print_test("Heap esta vacio es true", heap_esta_vacio(heap));
        print_test("La cantidad de elementos es 0", heap_cantidad(heap) == 0);
        print_test("El maximo es NULL", !heap_ver_max(heap));
        print_test("Desencolar datos es NULL", !heap_desencolar(heap));
    }

    heap_destruir(heap, NULL);
    
}


void pruebas_desencolar_heap(){
    printf("\n\nPruebas desencolar heap: \n");
    heap_t *heap = heap_crear(funcion_comparar_int);

    int datos[] = {30, 40, 10, 20};


    printf("\nDato: %d \n", datos[0]);
    print_test("Encolar dato es true", heap_encolar(heap, &datos[0]));
    print_test("La cantidad de elementos es correcta", heap_cantidad(heap) == 1);
    printf("maximo: %p", heap_ver_max(heap));
    print_test("El maximo es correcto", heap_ver_max(heap) == &datos[0]);
    print_test("Heap esta vacio es false", !heap_esta_vacio(heap));
    
    print_test("\nDesencolamos, el dato obtenido es correcto", heap_desencolar(heap) == &datos[0]);
    print_test("La cantidad de elementos es 1", heap_cantidad(heap) == 0);
    print_test("El maximo es correcto", heap_ver_max(heap) == NULL);
    print_test("Heap esta vacio es true", heap_esta_vacio(heap));

    for(size_t i = 0; i < 4; i++){
        print_test("\nEncolar dato es true", heap_encolar(heap, &datos[(i)]));
        print_test("La cantidad de elementos es correcta", heap_cantidad(heap) == (i+1));
        print_test("Heap esta vacio es false", !heap_esta_vacio(heap));
    }
    print_test("El maximo es correcto", heap_ver_max(heap) == &datos[(1)]);

 
    print_test("\nDesencolamos, el dato obtenido es correcto", heap_desencolar(heap) == &datos[1]);
    print_test("La cantidad de elementos es 1", heap_cantidad(heap) == 3);
    print_test("El maximo es correcto", heap_ver_max(heap) == &datos[(0)]);

    print_test("\nDesencolamos, el dato obtenido es correcto", heap_desencolar(heap) == &datos[0]);
    print_test("La cantidad de elementos es 1", heap_cantidad(heap) == 2);
    print_test("El maximo es correcto", heap_ver_max(heap) == &datos[(3)]);

    print_test("\nDesencolamos, el dato obtenido es correcto", heap_desencolar(heap) == &datos[3]);
    print_test("La cantidad de elementos es 1", heap_cantidad(heap) == 1);
    print_test("El maximo es correcto", heap_ver_max(heap) == &datos[(2)]);

    print_test("\nDesencolamos, el dato obtenido es correcto", heap_desencolar(heap) == &datos[2]);
    

    print_test("\nHeap esta vacio es true", heap_esta_vacio(heap));
    print_test("La cantidad de elementos es 0", heap_cantidad(heap) == 0);
    print_test("El maximo es NULL", heap_ver_max(heap) == NULL);
    print_test("Desencolar datos es NULL", !heap_desencolar(heap));

    heap_destruir(heap, NULL);

}


void pruebas_heap_vacio(){
    printf("\n\nPruebas heap vacio: \n");

    heap_t *heap = heap_crear(funcion_comparar_int);

    print_test("El heap esta creado", heap);
    print_test("La cantidad de elementos es 0", heap_cantidad(heap) == 0);
    print_test("El maximo es NULL", heap_ver_max(heap) == NULL);
    print_test("El heap esta vacio", heap_esta_vacio(heap));
    print_test("Desencolar es NULL", heap_desencolar(heap) == NULL);

    heap_destruir(heap, NULL);
}


void pruebas_heap_sort(){
    printf("\n\nPruebas heap sort: \n");

    void* valores[6];

    int num1 = 1, num2 = 2, num3 = 3, num4 = 4, num5 = 5, num6 = 6;
    valores[0] = &num1;
    valores[1] = &num2;
    valores[2] = &num3;
    valores[3] = &num4;
    valores[4] = &num5;
    valores[5] = &num6;

    heap_sort(valores, 6, funcion_comparar_int);

    bool correcto = true;
    for(int i = 0; i < 6; i++){
        if(*(int*)valores[i] != (i+1)){
            correcto = false;
        }
    }
    print_test("Se ordeno correctamente", correcto);
}


int _strcmp( const void * valora, const void *valorb){
    return strcmp( ( const char*)valora, (const char*)valorb);
}


void prueba_heap_arreglo(){
    int n1 = 1, n2 = 10, n3 = 5, n4 = 22, n5 = 66, n6 = 3, n7 = 4, n8 = 0, n9 = 78, n10 = 33;
    void* arreglo[10]  = {&n1, &n2, &n3, &n4, &n5, &n6, &n7, &n8, &n9, &n10};
    int arreglo_ordenado[10]  = {78, 66, 33, 22, 10, 5, 4, 3, 1, 0};

    heap_t *heap = heap_crear_arr(arreglo, 10, funcion_comparar_int);
    print_test("El heap se creo: ", heap);

    heap_sort(arreglo, 10, funcion_comparar_int);

    for(int i = 0; i < 10; i++){
        if(arreglo_ordenado[i] != *(int* )heap_desencolar(heap)){
            print_test("Todos los elementos se ubicaron de forma adecuada: ", false);
            return;
        }
    }
    print_test("Todos los elementos se ubicaron de forma adecuada: ", true);

    heap_destruir(heap, NULL);
}


void pruebas_elemento_vacio(){
    printf("\n\nPruebas con elemento vacio: ");
    heap_t *heap = heap_crear(_strcmp);
    print_test("El creado de heap fue exitoso: ", (heap != NULL));

    char *vacia = "";

    print_test("La cantidad es 0 :", heap_cantidad(heap) == 0);

    print_test("Encolando elemento 'J': ", heap_encolar(heap, "J"));
    print_test("La cantidad es 1 :", heap_cantidad(heap) == 1);

    print_test("Encolando elemento 'B': ", heap_encolar(heap, "B"));
    print_test("La cantidad es 2 :", heap_cantidad(heap) == 2);

    print_test("Encolando elemento 'D': ", heap_encolar(heap, "D"));
    print_test("La cantidad es 3 :", heap_cantidad(heap) == 3);

    print_test("Encolando elemento 'Z': ", heap_encolar(heap, "Z"));
    print_test("La cantidad es 4 :", heap_cantidad(heap) == 4);
    
    print_test("Encolando elemento 'S': ", heap_encolar(heap, "S"));
    print_test("La cantidad es 5 :", heap_cantidad(heap) == 5);

    print_test("Encolando elemento '' (Vacio): ", heap_encolar(heap, vacia));
    print_test("La cantidad es 6 :", heap_cantidad(heap) == 6);

    bool existe = false;

    for(size_t i = 0; i < 6; i++){
        if(vacia == (char*)heap_desencolar(heap)){
            existe = true;
        }
    }

    print_test("El elemento vacio se encontraba en el heap: ", existe);

    heap_destruir(heap, NULL);
}


void heap_llenar_n_volumen( heap_t *heap, size_t n, int *vec){
    size_t indice;
    size_t i;
    for( i = 0; i < n; i++){
        indice = rand() % n; //Rand genera un int entre 0 y 32767. Le aplico mod para obtener
        char elemento[5];       // una posicion aleatoria de mi arreglo.
        sprintf(elemento, "%d", vec[indice]);
        if(!heap_encolar(heap, elemento)){
            print_test("Todas los elementos se insertaron correctamente: ", false);
            return;
        }
    }
    print_test("Todas los elementos se insertaron correctamente: ", true);
}


void prueba_volumen_1000(){
    printf("\n\nPrueba con volumen 1000: \n");
    heap_t *heap = heap_crear(_strcmp);
    print_test("El heap se creo correctamente: ", heap);
    
    int vec[1000] = {0};

    for(int i = 0; i < 1000; i++){
        vec[i] = i;
    }

    size_t tam = 1000;

    print_test("La cantidad es 0: ", heap_cantidad(heap) == 0);

    heap_llenar_n_volumen(heap, tam, vec);

    print_test("La cantidad es 1000: ", heap_cantidad(heap) == 1000);

    heap_destruir(heap, NULL);
}


void prueba_volumen_10000(){
    printf("\n\nPrueba con volumen 10000: \n");
    heap_t *heap = heap_crear(_strcmp);
    print_test("El heap se creo correctamente: ", heap);
    
    int vec[10000] = {0};

    for(int i = 0; i < 10000; i++){
        vec[i] = i;
    }

    size_t tam = 10000;

    print_test("La cantidad es 0: ", heap_cantidad(heap) == 0);

    heap_llenar_n_volumen(heap, tam, vec);

    print_test("La cantidad es 10000: ", heap_cantidad(heap) == 10000);

    heap_destruir(heap, NULL);
}


void pruebas_destruccion_free(){
    printf("\n\nPrueba con elemento de malloc: \n");
    heap_t *heap = heap_crear(_strcmp);
    print_test("El heap se creo correctamente: ", heap);

    int *a, *b, *c, *d, *e;
    a = malloc(sizeof(int));
    b = malloc(sizeof(int));
    c = malloc(sizeof(int));
    d = malloc(sizeof(int));
    e = malloc(sizeof(int));

    *a = 45;
    *b = 70;
    *c = 2;
    *d = 4;
    *e = 45;


    print_test("Los mallocs fueron concedidos: ",(a && b && c && d && e));

    print_test("Encolando el numero 45 :", heap_encolar(heap, a));
    print_test("La cantidad es  1:", heap_cantidad(heap) == 1);

    print_test("Encolando el numero 70 :", heap_encolar(heap, b));
    print_test("La cantidad es 2 :", heap_cantidad(heap) == 2);

    print_test("Encolando el numero 2 :", heap_encolar(heap, c));
    print_test("La cantidad es 3 :", heap_cantidad(heap) == 3);

    print_test("Encolando el numero 4 :", heap_encolar(heap,d ));
    print_test("La cantidad es 4 :", heap_cantidad(heap) == 4);

    print_test("Encolando el numero 45 :", heap_encolar(heap, e));
    print_test("La cantidad es 5 :", heap_cantidad(heap) == 5);

    heap_destruir(heap, free);
}


/* *****************************************************************
 *                    LLAMADO A PRUEBAS
 * *****************************************************************/



void pruebas_heap_estudiante(){
    pruebas_encolar_heap();
    pruebas_desencolar_heap();
    pruebas_heap_vacio();
    pruebas_heap_sort();
    prueba_heap_arreglo();
    pruebas_elemento_vacio();
    prueba_volumen_1000();
    prueba_volumen_10000();
    pruebas_destruccion_free();
    
}
/*
 * Función main() que llama a la función de pruebas.
 */

#ifndef CORRECTOR  // Para que no dé conflicto con el main() del corrector.

int main(void) {
    pruebas_heap_estudiante();
    return failure_count() > 0;  // Indica si falló alguna prueba.
}

#endif
