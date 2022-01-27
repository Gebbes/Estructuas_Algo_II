#include "lista.h"
#include "testing.h"
#include <stdio.h>
#include <stdlib.h>

#define NUM_PRUEBA_VOLUMEN 10000
#define NUM_PRUEBAS 6

/* *****************************************************************
 *                    PRUEBAS PARA LA LISTA
 * *****************************************************************/


/*
Prueba de algunos elementos
*/
void pruebas_algunos_elementos(){
    printf("\nINICIO DE PRUEBAS DE ALGUNOS ELEMENTOS\n");

    
    lista_t* lista = lista_crear();

    int elementos[] = {20, 30, 10, 40, 50, 60};

    /*Probamos si la lista se comporta correctamente*/
    print_test("Crea lista", lista != NULL);
    print_test("La lista esta vacia", lista_esta_vacia(lista));
    print_test("El primero de la lista es correcto", !lista_ver_primero(lista));
    print_test("El ultimo de la lista es correcto", !lista_ver_ultimo(lista));
    print_test("El largo de la lista es correcto", lista_largo(lista) == 0);
    print_test("Borrar primero es false", !lista_borrar_primero(lista));
    
    /*Probamos insertar los elementos al principio*/
    for(size_t i=0; i < NUM_PRUEBAS; i++){

        printf("nro: %d\n", elementos[i]);
        print_test("Insertamos el elemento", lista_insertar_primero(lista, &elementos[i]));
        print_test("El primer numero es correcto", lista_ver_primero(lista) == &elementos[i]); 
    }

    /*Probamos la lista con los elementos ya insertados*/
    print_test("La lista no esta vacia", !lista_esta_vacia(lista));
    print_test("El primero de la lista es correcto", lista_ver_primero(lista) == &elementos[5]);
    print_test("El ultimo de la lista es correcto", lista_ver_ultimo(lista) == &elementos[0]);
    print_test("El largo de la lista es correcto", lista_largo(lista) == 6);
    print_test("Borrar primero es correcto", lista_borrar_primero(lista) == &elementos[5]);
    print_test("El primero de la lista es correcto", lista_ver_primero(lista) == &elementos[4]);
    print_test("El ultimo de la lista es correcto", lista_ver_ultimo(lista) == &elementos[0]);
    print_test("El largo de la lista es correcto", lista_largo(lista) == 5);


    /*Probamos insertar los elementos al final*/
    for(size_t i=0; i < NUM_PRUEBAS; i++){

        printf("nro: %d\n", elementos[i]);
        print_test("Insertamos el elemento", lista_insertar_ultimo(lista, &elementos[i]));
        print_test("El ultimo numero es correcto", lista_ver_ultimo(lista) == &elementos[i]); 
    }

    /*Probamos la lista con los elementos ya insertados*/
    print_test("La lista no esta vacia", !lista_esta_vacia(lista));
    print_test("El primero de la lista es correcto", lista_ver_primero(lista) == &elementos[4]);
    print_test("El ultimo de la lista es correcto5", lista_ver_ultimo(lista) == &elementos[5]);
    print_test("El largo de la lista es correcto", lista_largo(lista) == 11);
    print_test("Borrar primero es correcto", lista_borrar_primero(lista) == &elementos[4]);
    print_test("El primero de la lista es correcto", lista_ver_primero(lista) == &elementos[3]);
    print_test("El ultimo de la lista es correcto", lista_ver_ultimo(lista) == &elementos[5]);
    print_test("El largo de la lista es correcto", lista_largo(lista) == 10);

    /*Probamos destruir la lista*/
    lista_destruir(lista, NULL);
    print_test("Lista destruida", true);

}

/*
Pueba de elemnto NULL
*/
void pruebas_null(){
    printf("\nINICIO DE PRUEBAS DE NULL\n");

    lista_t* lista = lista_crear();

    /*Probamos si la lista se comporta correctamente*/
    print_test("Lista creada", lista != NULL);
    print_test("La lista esta vacia", lista_esta_vacia(lista));
    print_test("El primero de la lista es correcto", !lista_ver_primero(lista));
    print_test("El ultimo de la lista es correcto", !lista_ver_ultimo(lista));
    print_test("El largo de la lista es correcto", lista_largo(lista) == 0);
    print_test("Borrar primero es false", !lista_borrar_primero(lista));

    /*Probamos insertar el elemento NULL*/
    print_test("Insertar NULL es true", lista_insertar_primero(lista, NULL));

    /*Probamos la lista ahora que tiene el elemento NULL*/
    print_test("La lista esta vacia", !lista_esta_vacia(lista));
    print_test("El primero de la lista es correcto", lista_ver_primero(lista) == NULL);
    print_test("El ultimo de la lista es correcto", lista_ver_ultimo(lista) == NULL);
    print_test("El largo de la lista es correcto", lista_largo(lista) == 1);
    print_test("Borrar primero es false", !lista_borrar_primero(lista));

    /*Probamos destruir la lista*/
    lista_destruir(lista, NULL);
    print_test("Lista destruida", true);

}

/*
Prueba de volumen
 */
 void pruebas_volumen(){
    printf("\nINICIO DE PRUEBAS DE VOLUMEN\n");

    lista_t* lista = lista_crear();

    /*Probamos si la lista se comporta correctamente*/
    print_test("Lista creada", lista != NULL);
    print_test("La lista esta vacia", lista_esta_vacia(lista));
    print_test("El primero de la lista es correcto", !lista_ver_primero(lista));
    print_test("El ultimo de la lista es correcto", !lista_ver_ultimo(lista));
    print_test("El largo de la lista es correcto", lista_largo(lista) == 0);
    print_test("Borrar primero es false", !lista_borrar_primero(lista));

    /*Probamos si encola correctamente*/
    size_t i;

    for(i = 0; i < NUM_PRUEBA_VOLUMEN; i++){
        
        print_test("Insertamos el elemento", lista_insertar_primero(lista, &i));
        print_test("El primer numero es correcto", lista_ver_primero(lista) == &i); 
    }

    /*Probamos la lista que ya tiene elementos*/
    print_test("La lista no esta vacia", !lista_esta_vacia(lista));
    print_test("El primero de la lista es correcto", lista_ver_primero(lista) == &i);
    print_test("El ultimo de la lista es correcto11", *(int*)lista_ver_ultimo(lista) == 10000);
    print_test("El largo de la lista es correcto", lista_largo(lista) == NUM_PRUEBA_VOLUMEN);

    /*Probamos eliminar los elementos*/
    while(!lista_esta_vacia(lista)){

        print_test("Borramos el primero y es true", lista_borrar_primero(lista) == &i);

        i--;

        if(!lista_esta_vacia(lista)){
            print_test("El primero numero es true", lista_ver_primero(lista) == &i); 
        }
    }

    /*Probamos la lista vacia*/
    print_test("La lista esta vacia", lista_esta_vacia(lista));
    print_test("El primero de la lista es correcto", !lista_ver_primero(lista));
    print_test("El ultimo de la lista es correcto12", !lista_ver_ultimo(lista));
    print_test("Borrar primero es false", !lista_borrar_primero(lista));

    /*Probamos destruir la lista*/
    lista_destruir(lista, NULL);
    print_test("Lista destruida", true);

 }

void destruir_aux(void* dato){
    lista_destruir(dato, NULL);
}

/*
Prueba de destruccion de listas en listas
 */

void prueba_destruir(){

    lista_t* lista = lista_crear();


    /*Probamos si la lista se comporta correctamente*/
    print_test("Lista creada", lista != NULL);
    print_test("La lista esta vacia", lista_esta_vacia(lista));
    print_test("El primero de la lista es correcto", !lista_ver_primero(lista));
    print_test("El ultimo de la lista es correcto13", !lista_ver_ultimo(lista));
    print_test("El largo de la lista es correcto", lista_largo(lista) == 0);
    print_test("Borrar primero es false", !lista_borrar_primero(lista));
    

    /*Probamos insertar las listas*/
    print_test("Insertamos el elemento", lista_insertar_primero(lista, lista_crear()));
    print_test("Insertamos el elemento", lista_insertar_ultimo(lista, lista_crear()));

    /*Probamos la lista*/
    print_test("La lista no esta vacia", !lista_esta_vacia(lista));
    print_test("El largo de la lista es correcto", lista_largo(lista) == 2);

    /*Probamos destruir la lista*/
    lista_destruir(lista, destruir_aux);
    print_test("Lista destruida", true);
}


/* *****************************************************************
 *                    PRUEBAS DE LOS ITERADORES
 * *****************************************************************/


bool sumar(void *elemento, void*extra){
    *(int *)extra = *(int *)extra + *(int *)elemento;
    return true;
}


void sumo_numeros(){
    lista_t *lista = lista_crear();
    if(!lista){
        print_test("La lista se creo exitosamente: ", false);
        return;
    }
    print_test("La lista se creo exitosamente: ", true);

    int vec[15] = {0};
    int total = 0;
    for(int i = 0; i < 15; i++){
        vec[i]= 10;
        if(!lista_insertar_ultimo(lista, &vec[i])){
            print_test("Los elementos se insertaron correctamente: ", false);
            return;
        }
    }
    print_test("Los elementos se insertaron correctamente: ", true);

    lista_iterar(lista,sumar, &total);
    print_test("La suma es correcta: ", total == 150);
    lista_destruir(lista, NULL);
}


bool buscar_15(void* elemento, void *extra){
    *(int *)extra += 1;
    return(*(int *)elemento != 15);     // Si son iguales, devuelve false
}


void busqueda_lineal(){
    lista_t *lista = lista_crear();
    if(!lista){
        print_test("La lista se creo exitosamente: ", false);
        return;
    }
    print_test("La lista se creo exitosamente: ", true);
    int vector[11] = {2,3,1,6,8,3,15,10,34,22,90}; //15 esta en pos 6
    for(int i = 0; i < 11; i++){
        if(!lista_insertar_ultimo(lista, &vector[i])){
            print_test("Los elementos se insertaron correctamente: ", false);
            return;
        }
    }
    print_test("Los elementos se insertaron correctamente: ", true);

    int posicion = -1; 

    lista_iterar(lista, buscar_15, &posicion);

    print_test("La posicion da 6: ", posicion  == 6);

    lista_destruir(lista, NULL);
}


void pruebas_iter_interno(){
    printf("\n\n");
    printf("Prueba de iterador interno sin corte, sumo 15 numeros.\n");
    sumo_numeros();
    printf("\n\n");
    printf("Prueba de iterador interno con corte, busco el numero 15 en un arreglo.\n");
    busqueda_lineal();
    printf("\n\n");
}


void creado_apunta_primero(){
    lista_t *lista = lista_crear();
    if(!lista){
        print_test("La lista se creo exitosamente: ", false);
        return;
    }
    print_test("La lista se creo exitosamente: ", true);

    int A = 1;
    int B = 2;
    int C = 3;

    print_test("Insercion N1: ", lista_insertar_primero(lista,&C));
    print_test("Insercion N2: ", lista_insertar_primero(lista,&B));
    print_test("Insercion N3: ", lista_insertar_primero(lista,&A));
    

    lista_iter_t *iter = lista_iter_crear(lista);
    if(!iter){
        print_test("El iterador se creo exitosamente: ", false);
        return;
    }
    print_test("El iterador se creo exitosamente: ", true);
    
    print_test("Coincide el Iter actual y Lista primero: ",
    lista_iter_ver_actual(iter) == lista_ver_primero(lista));
    
    lista_iter_avanzar(iter);
    lista_iter_avanzar(iter);

    lista_iter_avanzar(iter);

    print_test("Avanzo al final, y estoy en el final: ", lista_iter_al_final(iter));
    
    lista_destruir(lista, NULL);
    lista_iter_destruir(iter);
}


void insertando_al_final(){
    lista_t *lista1 = lista_crear();
    lista_t *lista2 = lista_crear();

    if(!(lista1 && lista2)){
        print_test("Las dos listas se crearon exitosamente: ", false);
        return;
    }
    print_test("Las dos listas se crearon exitosamente: ", true);

    int A = 1;
    int B = 2;
    int C = 3;

    print_test("Insercion N1 en lista 1: ", lista_insertar_primero(lista1,&B));
    print_test("Insercion N2 en lista 1: ", lista_insertar_primero(lista1,&A));

    print_test("Insercion N1 en lista 2: ", lista_insertar_primero(lista2,&B));
    print_test("Insercion N2 en lista 2: ", lista_insertar_primero(lista2,&A));

    print_test("Insercion N3 en lista 1 con Insertar_al_ultimo: ", 
    lista_insertar_ultimo(lista1, &C));

    lista_iter_t *iter = lista_iter_crear(lista2);
    if(!iter){
        print_test("El iterador se creo exitosamente: ", false);
    }
    print_test("El iterador se creo exitosamente: ", iter);

    lista_iter_avanzar(iter);
    lista_iter_avanzar(iter);

    print_test("Iter esta al final: ", lista_iter_al_final(iter));
    print_test("Insercion N3 en lista 2, con iterador",lista_iter_insertar(iter, &C));
    print_test("N3 es el ultimo de lista 1: ", lista_ver_ultimo(lista1) == &C);
    print_test("Iter no sigue al final: ", (!lista_iter_al_final(iter)));
    print_test("N3 es el ultimo de lista 2: ", lista_ver_ultimo(lista2) == &C);


    lista_iter_destruir(iter);
    lista_destruir(lista1,NULL);
    lista_destruir(lista2,NULL);
}


void insertando_medio(){
    int vector[] = {1,2,3,4,5};

    lista_t *lista = lista_crear();
    if(!lista){
        print_test("La lista se creo exitosamente: ", false);
        return;
    }
    print_test("La lista se creo exitosamente: ", true);

    print_test("Enlisto el numero 1 :", lista_insertar_ultimo(lista, &vector[0]));
    print_test("Enlisto el numero 2 :", lista_insertar_ultimo(lista, &vector[1]));
    print_test("Enlisto el numero 4 :", lista_insertar_ultimo(lista, &vector[3]));
    print_test("Enlisto el numero 5 :", lista_insertar_ultimo(lista, &vector[4]));

    lista_iter_t *iter = lista_iter_crear(lista);
    if(!iter){
        print_test("El iterador se creo exitosamente: ", false);
    }
    print_test("El iterador se creo exitosamente: ", iter);

    print_test("Avanzo el iter y no esta al final: ",lista_iter_avanzar(iter));
    print_test("Avanzo el iter y no esta al final: ",lista_iter_avanzar(iter));

    print_test("La posicion actual contiene un 4: ",
    lista_iter_ver_actual(iter) == &vector[3]);

    print_test("Inserto el 3 con iterador: ", lista_iter_insertar(iter, &vector[2]));
    
    lista_iter_destruir(iter);

    lista_iter_t *iter2 = lista_iter_crear(lista);
    if(!iter2){
        print_test("El segundo iterador se creo exitosamente: ", false);
    }
    print_test("El segundo iterador se creo exitosamente: ", iter2);

    print_test("Inicio y el elemento es 1: ", lista_iter_ver_actual(iter2) == &vector[0]);

    lista_iter_avanzar(iter2);
    print_test("Avanzo y el elemento es 2: ", lista_iter_ver_actual(iter2) == &vector[1]);

    lista_iter_avanzar(iter2);
    print_test("El elemento actual es el 3 (pos 3): ",
    lista_iter_ver_actual(iter2) == &vector[2]);

    lista_iter_avanzar(iter2);
    print_test("Avanzo y el elemento es 4: ", lista_iter_ver_actual(iter2) == &vector[3]);

    lista_iter_avanzar(iter2);
    print_test("Avanzo y el elemento es 5: ", lista_iter_ver_actual(iter2) == &vector[4]);
    
    lista_iter_destruir(iter2);
    lista_destruir(lista,NULL);
}


void remover_prim_afecta_lista(){
    lista_t *lista = lista_crear();
    if(!lista){
        print_test("La lista se creo exitosamente: ", false);
        return;
    }
    print_test("La lista se creo exitosamente: ", true);

    int A = 1;
    int B = 2;
    int C = 3;

    print_test("Insercion N3: ", lista_insertar_primero(lista,&C));
    print_test("Insercion N2: ", lista_insertar_primero(lista,&B));
    print_test("Insercion N1: ", lista_insertar_primero(lista,&A));

    lista_iter_t *iter = lista_iter_crear(lista);
    if(!iter){
        print_test("El iterador se creo exitosamente: ", false);
    }
    print_test("El iterador se creo exitosamente: ", iter);

    print_test("Se remueve el primero: ",lista_iter_borrar(iter) == &A);
    print_test("El primero ya no es A: ", lista_ver_primero(lista) != &A);
    print_test("El primero es B: ",lista_ver_primero(lista) == &B);

    lista_iter_destruir(iter);
    lista_destruir(lista,NULL);
}


void remover_ult_afecta_lista(){
    lista_t *lista = lista_crear();
    if(!lista){
        print_test("La lista se creo exitosamente: ", false);
        return;
    }
    print_test("La lista se creo exitosamente: ", true);

    int A = 1;
    int B = 2;
    int C = 3;

    print_test("Insercion N1: ", lista_insertar_ultimo(lista,&A));
    print_test("Insercion N2: ", lista_insertar_ultimo(lista,&B));
    print_test("Insercion N3: ", lista_insertar_ultimo(lista,&C));

    lista_iter_t *iter = lista_iter_crear(lista);
    if(!iter){
        print_test("El iterador se creo exitosamente: ", false);
    }
    print_test("El iterador se creo exitosamente: ", iter);

    lista_iter_avanzar(iter);
    print_test("Avanzo y estoy en B: ", lista_iter_ver_actual(iter) == &B);

    lista_iter_avanzar(iter);
    print_test("Avanzo y estoy en C: ", lista_iter_ver_actual(iter) == &C);

    print_test("Se remueve el ultimo: ",lista_iter_borrar(iter) == &C);
    print_test("El ultimo ya no es C: ", lista_ver_ultimo(lista) != &C);
    print_test("El ultimo es B: ",lista_ver_ultimo(lista) == &B);

    lista_iter_destruir(iter);
    lista_destruir(lista,NULL);
}


void remover_medio(){
    int vector[] = {1,2,3,4,5};

    lista_t *lista = lista_crear();
    if(!lista){
        print_test("La lista se creo exitosamente: ", false);
        return;
    }
    print_test("La lista se creo exitosamente: ", true);

    lista_iter_t *iter = lista_iter_crear(lista);
    if(!iter){
        print_test("El iterador se creo exitosamente: ", false);
    }
    print_test("El iterador se creo exitosamente: ", iter);

    for(int i = 4; i >= 0 ; i--){
        lista_iter_insertar(iter, &vector[i]);
    }

    print_test("Inicio y el elemento es 1: ", lista_iter_ver_actual(iter) == &vector[0]);

    lista_iter_avanzar(iter);
    print_test("Avanzo y el elemento es 2: ", lista_iter_ver_actual(iter) == &vector[1]);

    lista_iter_avanzar(iter);
    print_test("Avanzo y el elemento es 3: ", lista_iter_ver_actual(iter) == &vector[2]);

    lista_iter_avanzar(iter);
    print_test("Avanzo y el elemento es 4: ", lista_iter_ver_actual(iter) == &vector[3]);

    lista_iter_avanzar(iter);
    print_test("Avanzo y el elemento es 5: ", lista_iter_ver_actual(iter) == &vector[4]);

    lista_iter_destruir(iter);    
    lista_iter_t *iter2 = lista_iter_crear(lista);
    if(!iter2){
        print_test("El segundo iterador se creo exitosamente: ", false);
    }
    print_test("El segundo iterador se creo exitosamente: ", iter2);

    lista_iter_avanzar(iter2);
    print_test("Elimino el numero 2: ", lista_iter_borrar(iter2) == &vector[1]);

    lista_iter_destruir(iter2);

    lista_iter_t *iter3 = lista_iter_crear(lista);
    if(!iter3){
        print_test("El tercer iterador se creo exitosamente: ", false);
    }
    print_test("El tercer iterador se creo exitosamente: ", iter3);

    print_test("Inicio y el elemento es 1: ", lista_iter_ver_actual(iter3) == &vector[0]);

    lista_iter_avanzar(iter3);
    print_test("Avanzo y el elemento es 3: ", lista_iter_ver_actual(iter3) == &vector[2]);

    lista_iter_avanzar(iter3);
    print_test("Avanzo y el elemento es 4: ", lista_iter_ver_actual(iter3) == &vector[3]);

    lista_iter_avanzar(iter3);
    print_test("Avanzo y el elemento es 5: ", lista_iter_ver_actual(iter3) == &vector[4]);

    lista_iter_destruir(iter3);

    lista_destruir(lista,NULL);
}


void pruebas_iter_externo(){
    printf("Prueba recien creado apunta al primer elemento: \n");
    creado_apunta_primero();
    printf("\n\n");
    printf("Prueba insertando al final, cambia el ultimo de la lista: \n");
    insertando_al_final();
    printf("\n\n");
    printf("Prueba insertando en el medio se hace correctamente: \n");
    insertando_medio();
    printf("\n\n");
    printf("Prueba remover el primero modifica el primer elemento de la Lista: \n");
    remover_prim_afecta_lista();
    printf("\n\n");
    printf("Prueba remover el ultimo modifica el ultimo elemento de la Lista: \n");
    remover_ult_afecta_lista();
    printf("\n\n");
    printf("Prueba al remover un elemento este ya no esta: \n");
    remover_medio();
    printf("\n\n");
    
}


void pruebas_lista_estudiante() {
    pruebas_algunos_elementos();
    pruebas_null();
    pruebas_volumen();
    prueba_destruir();
    pruebas_iter_interno();
    pruebas_iter_externo();
}

/*
 * Función main() que llama a la función de pruebas.
 */

#ifndef CORRECTOR  // Para que no dé conflicto con el main() del corrector.

int main(void) {
    pruebas_lista_estudiante();
    return failure_count() > 0;  // Indica si falló alguna prueba.
}

#endif
