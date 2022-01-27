#include "pila.h"
#include <stdio.h>
#include "testing.h"


static void prueba_pila_vacia(void) {
    pila_t *pila = pila_crear();
    if(! pila){
        print_test("La pila fue creada: ", false);
        return;
    }

    if(pila) print_test("La pila fue creada: ", true);
    
    print_test("Pila esta vacia: ", pila_esta_vacia(pila));
    print_test("Ver tope devuelve NULL: ", (pila_ver_tope(pila) ==  NULL));
    print_test("Desapilar devuelve NULL: ", (pila_desapilar(pila) ==  NULL));

    pila_destruir(pila);
}


bool prueba_invariante(void){
    pila_t* pila = pila_crear();

    int a = 3, b = 4 , c = 5 , d = 6 , e = 7;

    int resultado[] = {4,5,7,6,3};
    int desapilado[5]= {0};

    bool ap_1 = pila_apilar(pila, &a);
    bool ap_2 = pila_apilar(pila, &b);

    int* puntero_b = pila_desapilar(pila);
    desapilado[0] = *puntero_b ;

    bool ap_3 = pila_apilar(pila, &c);

    int* puntero_c = pila_desapilar(pila);
    desapilado[1] = *puntero_c ;

    bool ap_4 = pila_apilar(pila, &d);
    bool ap_5 = pila_apilar(pila, &e);

    int* puntero_e = pila_desapilar(pila);
    desapilado[2] = *puntero_e ;
    int* puntero_d = pila_desapilar(pila);
    desapilado[3] = *puntero_d ;
    int* puntero_a = pila_desapilar(pila);
    desapilado[4] = *puntero_a ;

    bool apilados = (ap_1 && ap_2 && ap_3 && ap_4 && ap_5);

    print_test("Apilado 1: ", ap_1);
    print_test("Apilado 2: ", ap_2);
    print_test("Apilado 3: ", ap_3);
    print_test("Apilado 4: ", ap_4);
    print_test("Apilado 5: ", ap_5);

    
    if(! apilados){
        printf("Fallo en el apilado \n");
        return false;
    }
    
    print_test("El apilado y desapilado fue exitoso: ", apilados);
    
    for(int i = 0; i < 5; i++){
        if(resultado[i] != desapilado[i]){
            pila_destruir(pila);
            print_test("Se mantiene el invariante: ", false);
            printf("Error al desapilar, los valores no coinciden (Elemento %d)\n", i);
            return false;
        }
    }
    print_test("Se mantiene el invariante: ", true);
    pila_destruir(pila);
    return true;
}


bool prueba_volumen(void){
    pila_t *pila = pila_crear();
    int* vector[1000] = {0};
    for(int i = 0; i < 1000; i++){
        bool apilado = pila_apilar(pila, &vector[i]);
        if(!apilado){
            print_test("Apilado de elementos: ", apilado);
            pila_destruir(pila);
            return false;
            }
    }
    print_test("El apilado fue exitoso: ", true); /* Va con True por que esquiva el
                                                   False del return */
    for(int i = 999; i >= 0; i--){
        if(&vector[i] != pila_ver_tope(pila)){
            print_test("Ver tope funciono exitosamente: ", false);
            printf("Fallo en el elemento %d\n", i);
            pila_destruir(pila);
            return false;
        }
        if(&vector[i] != pila_desapilar(pila)){
            print_test("El desapilado coincidio exitosamente: ", false);
            printf("Fallo en el elemento %d\n", i);
            pila_destruir(pila);
            return false;
        }
    }
    print_test("Tanto ver tope como desapilar coincidieron en 1000 elementos: ",true);
    
    bool afirmacion = pila_esta_vacia(pila);
    print_test("La pila fue desapilada con exito hasta vacia : ", afirmacion);

    pila_destruir(pila);
    return afirmacion;
}


bool prueba_null(void){
    int a = 1, b = 3;
    pila_t *pila = pila_crear();
    print_test("Apilado 1 : ", pila_apilar(pila, &a));
    print_test("Apilado 2 : ", pila_apilar(pila, NULL));
    print_test("Apilado 3 : ", pila_apilar(pila, &b));
    
    int *valor_b = pila_desapilar(pila);

    if(valor_b != &b){
        printf("Error al desapilar b, los valores no coinciden \n");
        pila_destruir(pila);
        return false;
    }
    bool afirmacion_1 = (pila_ver_tope(pila) == NULL); // Se pasan a variable 
    bool afirmacion_2 = (pila_desapilar(pila) == NULL);  // por legibilidad
    bool afirmacion_3 = !(pila_esta_vacia(pila));    // Aplique "!" para negacion
    pila_destruir(pila);                               

    print_test("Pila ver tope devuelve NULL: ", afirmacion_1);
    print_test("Pila desapilar devuelve NULL: ", afirmacion_2);
    print_test("La pila no esta vacia: ", afirmacion_3);
    return (afirmacion_1 && afirmacion_2 && afirmacion_3);
}


bool tope_desapilada(void){
    pila_t *pila = pila_crear();
    int vector[2] = {4,90};

    bool ap_1 = pila_apilar(pila, &vector[0]);
    bool ap_2 = pila_apilar(pila, &vector[1]);

    print_test("Apilado del elemento 1: ", ap_1);
    print_test("Apilado del elemento 2: ", ap_2);

    if(!(ap_1 && ap_2)){
        pila_destruir(pila);
        return false;
    }
    
    print_test("El apilado fue exitoso: ", true);

    bool afirmacion_F = (pila_ver_tope(pila) == NULL);

    print_test("Sin desapilar, tope no es NULL: ", !afirmacion_F);

    int *des_ap_2 = pila_desapilar(pila);
    int *des_ap_1 = pila_desapilar(pila);

    bool igual_2 = (&vector[1] == des_ap_2);
    bool igual_1 = (&vector[0] == des_ap_1);

    print_test("Coincide el desapilado del elemento 2: ", igual_2);
    print_test("Coincide el desapilado del elemento 1: ", igual_1);

    if(!(igual_1 && igual_2)){
        pila_destruir(pila);
        return false;
    }

    bool afirmacion_base = pila_esta_vacia(pila);
    print_test("La pila se vacio satisfactoriamente: ", afirmacion_base);

    bool afirmacion_T = (pila_ver_tope(pila) == NULL);

    pila_destruir(pila);
    return (afirmacion_base && !afirmacion_F && afirmacion_T);
}


bool desapilar_desapilada(void){
    pila_t *pila = pila_crear();
    int vector[2] = {4,90};

    bool ap_1 = pila_apilar(pila, &vector[0]);

    bool afirmacion_F = pila_esta_vacia(pila);
    print_test("La pila no esta vacia antes de tiempo: ", !afirmacion_F);

    int *des_ap_1 = pila_desapilar(pila);

    bool ap_2 = pila_apilar(pila, &vector[1]);
    int *des_ap_2 = pila_desapilar(pila);

    print_test("Apilado del elemento 1: ", ap_1);
    print_test("Apilado del elemento 2: ", ap_2);

    if(!(ap_1 && ap_2)){
        pila_destruir(pila);
        return false;
    }

    bool igual_1 = (&vector[0] == des_ap_1);
    bool igual_2 = (&vector[1] == des_ap_2);

    print_test("Coincide el desapilado del elemento 2: ", igual_2);
    print_test("Coincide el desapilado del elemento 1: ", igual_1);

    if(!(igual_1 && igual_2)){
        pila_destruir(pila);
        return false;
    }

    bool afirmacion_base = pila_esta_vacia(pila);
    print_test("La pila se vacio satisfactoriamente: ", afirmacion_base);

    bool afirmacion_T = (pila_desapilar(pila) == NULL);
    
    pila_destruir(pila);
    return (afirmacion_base && afirmacion_T && !afirmacion_F);
}



void pruebas_pila_estudiante() {
    printf("\n\n####    Pruebas con pila recien creada (vacia): \n");
    prueba_pila_vacia();
    printf("\n\n####    Pruebas del invariante con 5 elementos: \n");
    print_test("Resultado de la prueba: ",prueba_invariante());
    printf("\n\n####    Pruebas con volumen 1000: \n");
    print_test("Resultado de la prueba: ", prueba_volumen());
    printf("\n\n####    Pruebas con NULL: \n");
    print_test("Resultado de la prueba: ", prueba_null());
    printf("\n\n####    Pruebas desapilando hasta vacia: \n");
    print_test("Tope en desapilada es NULL: ", tope_desapilada());
    printf("Creando nueva pila \n");
    print_test("Desapilar en desapilada es NULL: ", desapilar_desapilada());
}


/*
 * Función main() que llama a la función de pruebas.
 */

#ifndef CORRECTOR  // Para que no dé conflicto con el main() del corrector.

int main(void) {
    pruebas_pila_estudiante();
    return failure_count() > 0;  // Indica si falló alguna prueba.
}

#endif
