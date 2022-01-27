#include "cola.h"
#include <stdio.h>
#include <stdlib.h>
#include "testing.h"
#include "pila.h"

typedef void *(*destruir_pilas)(void* dato);



bool prueba_cola_vacia(){
    cola_t *cola = cola_crear();
    print_test("La cola se creo satisfactoriamente: ", cola);

    bool vacia_1 = cola_esta_vacia(cola);
    print_test("La cola se creo vacia: ", vacia_1);

    bool vacia_VP = (cola_ver_primero(cola) == NULL);
    print_test("Ver primero devuelve NULL: ", vacia_VP);

    bool vacia_DE = (cola_desencolar(cola) == NULL);
    print_test("Desencolar devuelve NULL: ", vacia_DE);

    bool vacia_2 = cola_esta_vacia(cola);
    print_test("La cola se mantiene vacia: ", vacia_2);

    cola_destruir(cola, NULL);
    return (cola && vacia_1 && vacia_VP && vacia_DE && vacia_2);
}


bool unico_elemento_VP(){
    printf("   Pruebas con ver primero: \n");
    cola_t *cola = cola_crear();
    int A = 5;

    bool enc = cola_encolar(cola, &A);
    print_test("Encolamiento elemento: ", enc);

    bool des_enc = (cola_desencolar(cola) == &A);
    print_test("Coincide el elemento al desencolar: ", des_enc);

    if(!des_enc)return false;

    bool pre_condicion = cola_esta_vacia(cola);
    bool afirmacion = cola_ver_primero(cola) == NULL;

    print_test("La cola queda vacia: ", pre_condicion);
    print_test("Ver primero devuelve NULL: ", afirmacion);

    cola_destruir(cola, NULL);
    
    return (pre_condicion && afirmacion);
}


bool unico_elemento_DE(){                 // DE = DesEncolar
    printf("   Pruebas con desencolar: \n");
    cola_t *cola = cola_crear();
    int A = 5;

    bool enc = cola_encolar(cola, &A);
    print_test("Encolamiento elemento: ", enc);

    bool des_enc = (cola_desencolar(cola) == &A);
    print_test("Coincide el elemento al desencolar: ", des_enc);

    if(!des_enc)return false;

    bool pre_condicion = cola_esta_vacia(cola);
    bool afirmacion = cola_desencolar(cola) == NULL;

    print_test("La cola queda vacia: ", pre_condicion);
    print_test("Desencolar devuelve NULL: ", afirmacion);

    cola_destruir(cola, NULL);
    
    return (pre_condicion && afirmacion);
}


bool prueba_invariante_v5(void){
    printf("   Pruebas con volumen 5: \n");
    cola_t *cola = cola_crear();
    if(! cola)return false;

    int original[] = {3,4,5,6,7};

    print_test("Encolado N1:    ", cola_encolar(cola, &original[0]));
    print_test("Encolado N2:    ", cola_encolar(cola, &original[1]));

    int* n_3 = cola_desencolar(cola);

    print_test("Encolado N3:    ", cola_encolar(cola, &original[2]));

    int* n_4 = cola_desencolar(cola);
    int* n_5 = cola_desencolar(cola);

    print_test("Encolado N4:    ", cola_encolar(cola, &original[3]));
    print_test("Encolado N4:    ", cola_encolar(cola, &original[4]));

    int* n_6 = cola_desencolar(cola);
    int* n_7 = cola_desencolar(cola);

    bool DE_1 = (n_3 == &original[0]);
    bool DE_2 = (n_4 == &original[1]);
    bool DE_3 = (n_5 == &original[2]);
    bool DE_4 = (n_6 == &original[3]);
    bool DE_5 = (n_7 == &original[4]);

    print_test("Desencolado N1: ", DE_1);
    print_test("Desencolado N2: ", DE_2);
    print_test("Desencolado N3: ", DE_3);
    print_test("Desencolado N4: ", DE_4);
    print_test("Desencolado N5: ", DE_5);

    if(!(DE_1 && DE_2 && DE_3 && DE_4 && DE_5)) return false;

    cola_destruir(cola, NULL);
    return true;
}


bool prueba_volumen(){ 
    printf("   Pruebas con volumen 1000: \n");   
    int* vector[1000] = {0};
    cola_t *cola = cola_crear();
    if(!cola)return false;

    for(int i = 0; i < 1000; i++){
        bool ap = cola_encolar(cola, &vector[i]);
        if(!ap){
            print_test("Apilado exitoso: ", false);
            printf("Error en el apilado numero %d\n", (i+1));
            return false;
        }
    }
    print_test("Apilado exitoso: ", true);

    for(int i = 0; i < 1000 ; i++){
        if(&vector[i] != cola_ver_primero(cola)){
            print_test("Ver primero coincide para todos los elementos: ", false);
            printf("Error en la comparacion numero %d\n", (i+1));
            return false;
        }

        if(&vector[i] != cola_desencolar(cola)){
            print_test("Desencolar coincide para todos los elementos: ", false);
            printf("Error en la comparacion numero %d\n", (i+1));
            return false;
        }
    }
    
    print_test("Ver primero coincide para todos los elementos: ", true);
    print_test("Desencolar coincide para todos los elementos: ", true);
    print_test("La cola se desapilo hasta quedar vacia: ", cola_esta_vacia(cola));
    
    cola_destruir(cola, NULL);           // Desapilar y ver primero se evaluan dado que no 
    return true;                     // retornan false, entonces seria una doble afirmacion
}


bool prueba_encolando_NULL(){
    int a = 1, b = 3;
    cola_t *cola = cola_crear();
    print_test("Encolado 1 : ", cola_encolar(cola, &a));
    print_test("Encolado 2 : ", cola_encolar(cola, NULL));
    print_test("Encolado 3 : ", cola_encolar(cola, &b));
    
    int *valor_a = cola_desencolar(cola);

    if(valor_a != &a){
        printf("Error al desencolar el primer elemento, los valores no coinciden \n");
        cola_destruir(cola, NULL);
        return false;
    }
    bool afirmacion_1 = (cola_ver_primero(cola) == NULL);
    bool afirmacion_2 = (cola_desencolar(cola) == NULL);
    bool afirmacion_3 = !(cola_esta_vacia(cola));
    
    cola_destruir(cola, NULL);

    print_test("Cola ver primero devuelve NULL: ", afirmacion_1);
    print_test("Cola desencolar devuelve NULL: ", afirmacion_2);
    print_test("La cola no esta vacia: ", afirmacion_3);

    return (afirmacion_1 && afirmacion_2 && afirmacion_3);
}


bool prueba_encolando_malloc(){
    cola_t *cola = cola_crear();
    if(!cola){
        print_test("La cola se creo correctamente: ",false);
        return false;
    }
    print_test("La cola se creo correctamente: ", true);

    int *vector_1 = malloc(sizeof(int)*5);
    int *vector_2 = malloc(sizeof(int)*5);
    int *vector_3 = malloc(sizeof(int)*3);
    int *vector_4 = malloc(sizeof(int)*5);

    if(!(vector_1 && vector_2 && vector_3 && vector_4)){
        print_test("La creacion de vectores con malloc fue exitosa: ", false);
    }
    print_test("La creacion de vectores con malloc fue exitosa: ", true);


    for(int i = 0; i < 5; i++){
        vector_1[i] = i;
    }
    for(int i = 0; i < 3; i++){
        vector_3[i] = i;
    }


    print_test("Encolado N1: ", cola_encolar(cola, vector_1));
    print_test("Encolado N1: ", cola_encolar(cola, vector_2));
    print_test("Encolado N1: ", cola_encolar(cola, vector_3));
    print_test("Encolado N1: ", cola_encolar(cola, vector_4));

    cola_destruir(cola, free);

    return true;   // La confirmacion viene mas bien de Valgrind
}


void destructor_pilas(void* datos){
    pila_t *pila = datos;
    while(pila_ver_tope(pila)){       // Si es el fondo, devuelve null y se sale
        free(pila_desapilar(pila));   // del while, sino, libera el puntero     
    }
    pila_destruir(pila);
}


bool prueba_apilando_malloc(){
    cola_t *cola = cola_crear();
    if(!cola)return false;

    pila_t *pila_1 = pila_crear();
    pila_t *pila_2 = pila_crear();
    pila_t *pila_3 = pila_crear();
    pila_t *pila_4 = pila_crear();

    if(! (pila_1 && pila_2 && pila_3 && pila_4)){
        print_test("Las pilas se crearon correctamente: ", false);
        return false;
    }
    print_test("Las pilas se crearon correctamente: ", true);

    int vector[5] = {1,2,3,4,5};

    for(int i = 0; i < 5; i++){
        int *a = malloc(sizeof(int));
        if(! a){
            return false;
        }
        *a = vector[i];
        bool ap = pila_apilar(pila_1, a);
        if(! ap)return false;
    }


    for(int i = 0; i < 5; i++){
        int *a = malloc(sizeof(int));
        if(! a){
            return false;
        }
        *a = vector[i];
        bool ap = pila_apilar(pila_2, a);
        if(! ap)return false;
    }

    
    for(int i = 0; i < 5; i++){
        int *a = malloc(sizeof(int));
        if(! a){
            return false;
        }
        *a = vector[i];
        bool ap = pila_apilar(pila_3, a);
        if(! ap)return false;
    }

    
    for(int i = 0; i < 5; i++){
        int *a = malloc(sizeof(int));
        if(! a){
            return false;
        }
        *a = vector[i];
        bool ap = pila_apilar(pila_4, a);
        if(! ap)return false;
    }

    bool enc_1 = cola_encolar(cola, pila_1);
    bool enc_2 = cola_encolar(cola, pila_2);
    bool enc_3 = cola_encolar(cola, pila_3);
    bool enc_4 = cola_encolar(cola, pila_4);

    if(!(enc_1 && enc_2 && enc_3 && enc_4))return false;

    cola_destruir(cola, destructor_pilas);

    return true;
}


bool prueba_destruyendo_vacia(){
    cola_t *cola = cola_crear();
    print_test("La cola se creo: ", cola);
    print_test("La cola esta vacia: ", cola_esta_vacia(cola));
    cola_destruir(cola, destructor_pilas);
    return true;
}


bool prueba_destruyendo_con_null(){
    cola_t *cola = cola_crear();
    print_test("La cola se creo con exito: ", cola);

    int vector[] = {3,4,5,6,7};
    for(int i = 0; i < 5; i++){
        bool ap = cola_encolar(cola, &vector[i]);
        if(!ap){
            print_test("Apilado exitoso: ", false);
            printf("Error en el apilado numero %d\n", (i+1));
            return false;
        }
    }
    print_test("Los apilados fueron exitosos: ", true);
    cola_destruir(cola, NULL);
    return true;
}


void pruebas_cola_estudiante(void){
    printf("                 Pruebas con cola vacia: \n");
    print_test("La cola esta vacia: ", prueba_cola_vacia() );
    printf("\n\n");
    printf("                 Pruebas de comportamiento de desencolada == vacia: \n");
    print_test("Resultado ver primero da NULL: ", unico_elemento_VP());
    printf("\n");
    print_test("Resultado desencolar da NULL: ", unico_elemento_DE());
    printf("\n\n");
    printf("                 Pruebas sobre mantener el invariante: \n");
    print_test("Mantiene el invariante con tamaño 5: ", prueba_invariante_v5());
    printf("\n");
    print_test("Volumen 1000: carga, descarga e invariante: ",prueba_volumen()); 
    printf("\n\n"); 
    printf("                 Pruebas encolando NULL: \n");
    print_test("Resultado de pruebas encolando NULL: ", prueba_encolando_NULL() );
    printf("\n\n");
    printf("                 Pruebas destruyendo colas: \n");
    print_test("Cola con mallocs adentro: ", prueba_encolando_malloc());
    print_test("Encolando pilas con mallocs apilados: ", prueba_apilando_malloc());
    printf("   Prueba con cola vacia: \n");
    print_test("Cola vacia con funcion distina de NULL: ", prueba_destruyendo_vacia());
    printf("   Pruebas cola no vacia + NULL: \n");
    print_test("Cola no vacia con funcion NULL: ", prueba_destruyendo_con_null());
    printf("\n\n");
}

/*
 * Función main() que llama a la función de pruebas.
 */

#ifndef CORRECTOR  // Para que no dé conflicto con el main() del corrector.

int main(void) {
    pruebas_cola_estudiante();
    return failure_count() > 0;  // Indica si falló alguna prueba.
}

#endif
