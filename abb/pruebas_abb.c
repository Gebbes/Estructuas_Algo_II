#include "abb.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include "testing.h"
#include "pila.h"

/* *****************************************************************
 *                    PRUEBAS PARA EL ABB
 * *****************************************************************/

void pruebas_abb_vacio(){
    printf("\n\nPruebas con ABB vacio: \n");
    abb_t *arbol = abb_crear(strcmp, NULL);
    print_test("El arbol se creo: ", arbol);
    print_test("La cantidad es cero: ", (abb_cantidad(arbol) == 0 ));
    print_test("Clave pertenece devuelve false: ", abb_pertenece(arbol, "Pato") == false);
    print_test("Obtener dato es NULL: ", abb_obtener(arbol, "Pato") == NULL);
    print_test("Borrar dato devuelve NULL: ", abb_borrar(arbol, "Pato") == NULL);

    abb_destruir(arbol);
}


void pruebas_abb_pocos_elementos(){
    printf("\n\nPruebas con pocos elementos: \n");
    abb_t *arbol = abb_crear(strcmp, NULL);
    print_test("El arbol se creo correctamente: ", arbol);

    int vec[] = {1,2,3,4,5,6,7};

    print_test("Se agrego un elemento B: ", abb_guardar(arbol, "B", &vec[0]));
    print_test("La cantidad es 1: ", abb_cantidad(arbol) == 1);
    print_test("El elemento pertenece: ", abb_pertenece(arbol, "B"));
    print_test("Su dato es correcto: ", abb_obtener(arbol,"B") == &vec[0]);

    print_test("Esta clave no existe: ", abb_pertenece(arbol, "Clave")==false);

    print_test("Agrego clave A", abb_guardar(arbol,"A", &vec[1]));
    print_test("La cantidad es 2: ", abb_cantidad(arbol) == 2);
    print_test("El elemento pertenece: ", abb_pertenece(arbol, "A"));
    print_test("Su dato es correcto: ", abb_obtener(arbol,"A") == &vec[1]);

    print_test("Agrego clave E: ", abb_guardar(arbol,"E", &vec[2]));
    print_test("La cantidad es 3: ", abb_cantidad(arbol) == 3);
    print_test("El elemento pertenece: ", abb_pertenece(arbol, "E"));
    print_test("Su dato es correcto: ", abb_obtener(arbol,"E") == &vec[2]);

    print_test("Agrego clave C: ", abb_guardar(arbol,"C", &vec[3]));
    print_test("La cantidad es 4: ", abb_cantidad(arbol) == 4);
    print_test("El elemento pertenece: ", abb_pertenece(arbol, "C"));
    print_test("Su dato es correcto: ", abb_obtener(arbol,"C") == &vec[3]);

    print_test("Agrego clave F: ", abb_guardar(arbol,"F", &vec[4]));
    print_test("La cantidad es 5: ", abb_cantidad(arbol) == 5);
    print_test("El elemento pertenece: ", abb_pertenece(arbol, "F"));
    print_test("Su dato es correcto: ", abb_obtener(arbol,"F") == &vec[4]);

    print_test("Agrego clave G: ", abb_guardar(arbol,"G", &vec[5]));
    print_test("La cantidad es 6: ", abb_cantidad(arbol) == 6);
    print_test("El elemento pertenece: ", abb_pertenece(arbol, "G"));
    print_test("Su dato es correcto: ", abb_obtener(arbol,"G") == &vec[5]);

    print_test("Agrego clave H: ", abb_guardar(arbol,"H", &vec[6]));
    print_test("La cantidad es 7: ", abb_cantidad(arbol) == 7);
    print_test("El elemento pertenece: ", abb_pertenece(arbol, "H"));
    print_test("Su dato es correcto: ", abb_obtener(arbol,"H") == &vec[6]);

    print_test("Elimino el elemento A (sin hijos): ", abb_borrar(arbol,"A") == &vec[1]);
    print_test("La clave A no existe: ", abb_pertenece(arbol,"A") == false);

    print_test("Elimino el elemento F (un hijo): ", abb_borrar(arbol,"F") == &vec[4]);
    print_test("La clave F no existe: ", abb_pertenece(arbol,"F") == false);

    print_test("Elimino el elemento E (dos hijos): ", abb_borrar(arbol,"E") == &vec[2]);
    print_test("La clave E no existe: ", abb_pertenece(arbol,"E") == false);

    abb_destruir(arbol);
}


void pruebas_datos_NULL(){
    printf("\n\nPruebas con datos NULL es valido: \n");
    abb_t *arbol = abb_crear(strcmp, NULL);
    print_test("El arbol se creo correctamente: ", arbol);

    print_test("Se agrego un elemento B: ", abb_guardar(arbol, "B", NULL));
    print_test("La cantidad es 1: ", abb_cantidad(arbol) == 1);
    print_test("El elemento pertenece: ", abb_pertenece(arbol, "B"));
    print_test("Su dato es correcto: ", abb_obtener(arbol,"B") == NULL);

    print_test("Esta clave no existe: ", abb_pertenece(arbol, "Clave")==false);

    print_test("Agrego clave A", abb_guardar(arbol,"A", NULL));
    print_test("La cantidad es 2: ", abb_cantidad(arbol) == 2);
    print_test("El elemento pertenece: ", abb_pertenece(arbol, "A"));
    print_test("Su dato es correcto: ", abb_obtener(arbol,"A") == NULL);

    print_test("Agrego clave E: ", abb_guardar(arbol,"E", NULL));
    print_test("La cantidad es 3: ", abb_cantidad(arbol) == 3);
    print_test("El elemento pertenece: ", abb_pertenece(arbol, "E"));
    print_test("Su dato es correcto: ", abb_obtener(arbol,"E") == NULL);

    print_test("Agrego clave C: ", abb_guardar(arbol,"C", NULL));
    print_test("La cantidad es 4: ", abb_cantidad(arbol) == 4);
    print_test("El elemento pertenece: ", abb_pertenece(arbol, "C"));
    print_test("Su dato es correcto: ", abb_obtener(arbol,"C") == NULL);

    print_test("Agrego clave F: ", abb_guardar(arbol,"F", NULL));
    print_test("La cantidad es 5: ", abb_cantidad(arbol) == 5);
    print_test("El elemento pertenece: ", abb_pertenece(arbol, "F"));
    print_test("Su dato es correcto: ", abb_obtener(arbol,"F") == NULL);

    print_test("Agrego clave G: ", abb_guardar(arbol,"G", NULL));
    print_test("La cantidad es 6: ", abb_cantidad(arbol) == 6);
    print_test("El elemento pertenece: ", abb_pertenece(arbol, "G"));
    print_test("Su dato es correcto: ", abb_obtener(arbol,"G") == NULL);

    print_test("Agrego clave H: ", abb_guardar(arbol,"H", NULL));
    print_test("La cantidad es 7: ", abb_cantidad(arbol) == 7);
    print_test("El elemento pertenece: ", abb_pertenece(arbol, "H"));
    print_test("Su dato es correcto: ", abb_obtener(arbol,"H") == NULL);

    abb_destruir(arbol);
}


void prueba_borrar_ABB_entero(){
    printf("\n\nPrueba borrando un arbol entero (con raiz): \n");
    abb_t *arbol = abb_crear(strcmp, NULL);
    print_test("El arbol se creo correctamente: ", arbol);

    print_test("Se agrego un elemento E: ", abb_guardar(arbol, "E", NULL));
    print_test("La cantidad es 1: ", abb_cantidad(arbol) == 1);
    print_test("El elemento pertenece: ", abb_pertenece(arbol, "E"));
    print_test("Su dato es correcto: ", abb_obtener(arbol,"E") == NULL);

    print_test("Se agrego un elemento B: ", abb_guardar(arbol, "B", NULL));
    print_test("La cantidad es 2: ", abb_cantidad(arbol) == 2);
    print_test("El elemento pertenece: ", abb_pertenece(arbol, "B"));
    print_test("Su dato es correcto: ", abb_obtener(arbol,"B") == NULL);

    print_test("Se agrego un elemento A: ", abb_guardar(arbol, "A", NULL));
    print_test("La cantidad es 3: ", abb_cantidad(arbol) == 3);
    print_test("El elemento pertenece: ", abb_pertenece(arbol, "A"));
    print_test("Su dato es correcto: ", abb_obtener(arbol,"A") == NULL);

    print_test("Se agrego un elemento C: ", abb_guardar(arbol, "C", NULL));
    print_test("La cantidad es 4: ", abb_cantidad(arbol) == 4);
    print_test("El elemento pertenece: ", abb_pertenece(arbol, "C"));
    print_test("Su dato es correcto: ", abb_obtener(arbol,"C") == NULL);

    print_test("Agrego clave F: ", abb_guardar(arbol,"F", NULL));
    print_test("La cantidad es 5: ", abb_cantidad(arbol) == 5);
    print_test("El elemento pertenece: ", abb_pertenece(arbol, "F"));
    print_test("Su dato es correcto: ", abb_obtener(arbol,"F") == NULL);

    print_test("Agrego clave G: ", abb_guardar(arbol,"G", NULL));
    print_test("La cantidad es 6: ", abb_cantidad(arbol) == 6);
    print_test("El elemento pertenece: ", abb_pertenece(arbol, "G"));
    print_test("Su dato es correcto: ", abb_obtener(arbol,"G") == NULL);

    print_test("Elimino el elemento B: ", abb_borrar(arbol,"B") == NULL);
    print_test("La clave B no existe: ", abb_pertenece(arbol,"B") == false);

    print_test("Elimino el elemento F: ", abb_borrar(arbol,"F") == NULL);
    print_test("La clave F no existe: ", abb_pertenece(arbol,"F") == false);

    print_test("Elimino el elemento E: ", abb_borrar(arbol,"E") == NULL);
    print_test("La clave E no existe: ", abb_pertenece(arbol,"E") == false);

    print_test("Elimino el elemento C ", abb_borrar(arbol,"C") == NULL);
    print_test("La clave C no existe: ", abb_pertenece(arbol,"C") == false);

    print_test("Elimino el elemento A: ", abb_borrar(arbol,"A") == NULL);
    print_test("La clave A no existe: ", abb_pertenece(arbol,"A") == false);

    print_test("Elimino el elemento G: ", abb_borrar(arbol,"G") == NULL);
    print_test("La clave G no existe: ", abb_pertenece(arbol,"G") == false);

    print_test("La cantidad es 0: ", abb_cantidad(arbol) == 0);

    abb_destruir(arbol);
}


void ABB_llenar_n_volumen( abb_t *arbol, size_t n, int *vec){
    size_t indice;
    int i;
    for( i = 0; i < 2*n; i++){
        indice = rand() % n; //Rand genera un int entre 0 y 32767. Le aplico mod para obtener
        char clave[5];       // una posicion aleatoria de mi arreglo.
        sprintf(clave, "%d", vec[indice]);
        if(!abb_guardar(arbol, clave, &vec[indice])){
            print_test("Todas los elementos se insertaron correctamente: ", false);
            return;
        }
    }
    for( i = 0; i < n; i = i+4){ //Hago 4 pasadas "ordenadas" pero espaciadas para llenar los
        char clave[5];           // n elementos que queria obtener.
        sprintf(clave, "%d", vec[i]);
        if(!abb_guardar(arbol, clave, &vec[i])){
            print_test("Todas los elementos se insertaron correctamente: ", false);
            return;
        }
    }
    for( i = 1; i < n; i = i+4){
        char clave[5];
        sprintf(clave, "%d", vec[i]);
        if(!abb_guardar(arbol, clave, &vec[i])){
            print_test("Todas los elementos se insertaron correctamente: ", false);
            return;
        }
    }
    for( i = 2; i < n; i = i+4){
        char clave[5];
        sprintf(clave, "%d", vec[i]);
        if(!abb_guardar(arbol, clave, &vec[i])){
            print_test("Todas los elementos se insertaron correctamente: ", false);
            return;
        }
    }
    for( i = 3; i < n; i = i+4){
        char clave[5];
        sprintf(clave, "%d", vec[i]);
        if(!abb_guardar(arbol, clave, &vec[i])){
            print_test("Todas los elementos se insertaron correctamente: ", false);
            return;
        }
    }
    print_test("Todas los elementos se insertaron correctamente: ", true);
}


void prueba_volumen_1000(){
    printf("\n\nPrueba con volumen 1000: \n");
    abb_t *arbol = abb_crear(strcmp, NULL);
    print_test("El arbol se creo correctamente: ", arbol);
    
    int vec[1000] = {0};

    for(int i = 0; i < 1000; i++){
        vec[i] = i;
    }

    size_t tam = 1000;

    print_test("La cantidad es 0: ",abb_cantidad(arbol) == 0);

    ABB_llenar_n_volumen(arbol, tam, vec);

    print_test("La cantidad es 1000: ",abb_cantidad(arbol) == 1000);

    char clave[5];
    for(int i = 0; i < tam; i++){
        sprintf(clave, "%d", vec[i]);
        if(!abb_pertenece(arbol, clave)){
            print_test("Todas las claves pertenecen al arbol: ", false);
        }
    }
    print_test("Todas las claves pertenecen al arbol: ", true);

    abb_destruir(arbol);
}


void prueba_volumen_10000(){
    printf("\n\nPrueba con volumen 10000: \n");
    abb_t *arbol = abb_crear(strcmp, NULL);
    print_test("El arbol se creo correctamente: ", arbol);
    
    int vec[10000] = {0};

    for(int i = 0; i < 10000; i++){
        vec[i] = i;
    }

    size_t tam = 10000;

    print_test("La cantidad es 0: ",abb_cantidad(arbol) == 0);

    ABB_llenar_n_volumen(arbol, tam, vec);

    print_test("La cantidad es 10000: ",abb_cantidad(arbol) == 10000);

    char clave[5];
    for(int i = 0; i < tam; i++){
        sprintf(clave, "%d", vec[i]);
        if(!abb_pertenece(arbol, clave)){
            print_test("Todas las claves pertenecen al arbol: ", false);
        }
    }
    print_test("Todas las claves pertenecen al arbol: ", true);

    abb_destruir(arbol);
}


void prueba_free()
{
    printf("\n\nPrueba con datos malloc, y destruir free: \n");

    abb_t *arbol = abb_crear(strcmp, free);
    print_test("El arbol se creo correctamente: ", arbol);

    int *a, *b, *c, *e;
    a = malloc(sizeof(int));
    *a = 1;
    
    b = malloc(sizeof(int));
    *b = 1;
    
    c = malloc(sizeof(int));
    *c = 1;

    e = malloc(sizeof(int));
    *e = 1;

    print_test("Agrego clave C: ", abb_guardar(arbol,"C", c));
    print_test("La cantidad es 1: ", abb_cantidad(arbol) == 1);
    print_test("El elemento pertenece: ", abb_pertenece(arbol, "C"));
    print_test("Su dato es correcto: ", abb_obtener(arbol,"C") == c);
    
    print_test("Agrego clave E: ", abb_guardar(arbol,"E", e));
    print_test("La cantidad es 2: ", abb_cantidad(arbol) == 2);
    print_test("El elemento pertenece: ", abb_pertenece(arbol, "E"));
    print_test("Su dato es correcto: ", abb_obtener(arbol,"E") == e);

    print_test("Se agrego un elemento B: ", abb_guardar(arbol, "B", b));
    print_test("La cantidad es 3: ", abb_cantidad(arbol) == 3);
    print_test("El elemento pertenece: ", abb_pertenece(arbol, "B"));
    print_test("Su dato es correcto: ", abb_obtener(arbol,"B") == b);

    print_test("Agrego clave A", abb_guardar(arbol,"A", a));
    print_test("La cantidad es 4: ", abb_cantidad(arbol) == 4);
    print_test("El elemento pertenece: ", abb_pertenece(arbol, "A"));
    print_test("Su dato es correcto: ", abb_obtener(arbol,"A") == a);

    int *borrado = abb_borrar(arbol, "A");
    print_test("Se elimino el elemento de A: ", borrado == a);
    free(a);


    abb_destruir(arbol);
}


void _pila_destruir(void* pila){
    pila_destruir(pila);
}


void prueba_destruir_pila()
{
    printf("\n\nPruebas con pila destruir: \n");
    abb_t *arbol = abb_crear(strcmp, _pila_destruir);
    print_test("El arbol se creo correctamente: ", arbol);

    pila_t *pila1 = pila_crear();
    pila_t *pila2 = pila_crear();
    pila_t *pila3 = pila_crear();
    pila_t *pila4 = pila_crear();

    print_test("Agrego clave C: ", abb_guardar(arbol,"C", pila1));
    print_test("La cantidad es 1: ", abb_cantidad(arbol) == 1);
    print_test("El elemento pertenece: ", abb_pertenece(arbol, "C"));
    print_test("Su dato es la pila: ", abb_obtener(arbol,"C") == pila1);
    
    print_test("Agrego clave E: ", abb_guardar(arbol,"E", pila2));
    print_test("La cantidad es 2: ", abb_cantidad(arbol) == 2);
    print_test("El elemento pertenece: ", abb_pertenece(arbol, "E"));
    print_test("Su dato es la pila: ", abb_obtener(arbol,"E") == pila2);

    print_test("Se agrego un elemento B: ", abb_guardar(arbol, "B", pila3));
    print_test("La cantidad es 3: ", abb_cantidad(arbol) == 3);
    print_test("El elemento pertenece: ", abb_pertenece(arbol, "B"));
    print_test("Su dato es la pila: ", abb_obtener(arbol,"B") == pila3);

    print_test("Agrego clave A", abb_guardar(arbol,"A", pila4));
    print_test("La cantidad es 4: ", abb_cantidad(arbol) == 4);
    print_test("El elemento pertenece: ", abb_pertenece(arbol, "A"));
    print_test("Su dato es la pila: ", abb_obtener(arbol,"A") == pila4);
    
    pila_t *pila_borrada = abb_borrar(arbol, "A");
    pila_destruir(pila_borrada);

    pila_t *pila5 = pila_crear();

    print_test("La cantidad es 3: ", abb_cantidad(arbol) == 3);
    print_test("Se cambio la pila de B: ", abb_guardar(arbol, "B", pila5));
    print_test("El elemento pertenece: ", abb_pertenece(arbol, "B"));
    print_test("Su dato es la nueva pila: ", abb_obtener(arbol,"B") == pila5);

    abb_destruir(arbol);
}


void pruebas_datos_heap()
{
    printf("\n\nPruebas con destruir dato distinto de NULL: \n");
    prueba_free();
    prueba_destruir_pila();
}


void prueba_reemplazando_datos(){
    printf("\n\nPruebas reemplazando datos: \n");
    abb_t *arbol = abb_crear(strcmp, NULL);
    print_test("El arbol se creo correctamente: ", arbol);

    print_test("Se agrego un elemento B: ", abb_guardar(arbol, "B", NULL));
    print_test("La cantidad es 1: ", abb_cantidad(arbol) == 1);
    print_test("El elemento pertenece: ", abb_pertenece(arbol, "B"));
    print_test("Su dato es NULL: ", abb_obtener(arbol,"B") == NULL);

    print_test("Agrego clave A", abb_guardar(arbol,"A", NULL));
    print_test("La cantidad es 2: ", abb_cantidad(arbol) == 2);
    print_test("El elemento pertenece: ", abb_pertenece(arbol, "A"));
    print_test("Su dato es NULL: ", abb_obtener(arbol,"A") == NULL);

    print_test("Agrego clave E: ", abb_guardar(arbol,"E", NULL));
    print_test("La cantidad es 3: ", abb_cantidad(arbol) == 3);
    print_test("El elemento pertenece: ", abb_pertenece(arbol, "E"));
    print_test("Su dato es NULL: ", abb_obtener(arbol,"E") == NULL);

    print_test("Agrego clave C: ", abb_guardar(arbol,"C", NULL));
    print_test("La cantidad es 4: ", abb_cantidad(arbol) == 4);
    print_test("El elemento pertenece: ", abb_pertenece(arbol, "C"));
    print_test("Su dato es NULL: ", abb_obtener(arbol,"C") == NULL);

    print_test("Agrego clave F: ", abb_guardar(arbol,"F", NULL));
    print_test("La cantidad es 5: ", abb_cantidad(arbol) == 5);
    print_test("El elemento pertenece: ", abb_pertenece(arbol, "F"));
    print_test("Su dato es NULL: ", abb_obtener(arbol,"F") == NULL);

    print_test("Agrego clave G: ", abb_guardar(arbol,"G", NULL));
    print_test("La cantidad es 6: ", abb_cantidad(arbol) == 6);
    print_test("El elemento pertenece: ", abb_pertenece(arbol, "G"));
    print_test("Su dato es NULL: ", abb_obtener(arbol,"G") == NULL);

    print_test("Agrego clave H: ", abb_guardar(arbol,"H", NULL));
    print_test("La cantidad es 7: ", abb_cantidad(arbol) == 7);
    print_test("El elemento pertenece: ", abb_pertenece(arbol, "H"));
    print_test("Su dato es NULL: ", abb_obtener(arbol,"H") == NULL);

    int vec[] = {1,2,3,4,5,6,7};

    print_test("Se agrego un elemento B: ", abb_guardar(arbol, "B", &vec[0]));
    print_test("El elemento pertenece: ", abb_pertenece(arbol, "B"));
    print_test("Su dato es 1: ", abb_obtener(arbol,"B") == &vec[0]);

    print_test("Esta clave no existe: ", abb_pertenece(arbol, "Clave")==false);

    print_test("Agrego clave A", abb_guardar(arbol,"A", &vec[1]));
    print_test("El elemento pertenece: ", abb_pertenece(arbol, "A"));
    print_test("Su dato es 2: ", abb_obtener(arbol,"A") == &vec[1]);

    print_test("Agrego clave E: ", abb_guardar(arbol,"E", &vec[2]));
    print_test("El elemento pertenece: ", abb_pertenece(arbol, "E"));
    print_test("Su dato es 3: ", abb_obtener(arbol,"E") == &vec[2]);

    print_test("Agrego clave C: ", abb_guardar(arbol,"C", &vec[3]));
    print_test("El elemento pertenece: ", abb_pertenece(arbol, "C"));
    print_test("Su dato es 4: ", abb_obtener(arbol,"C") == &vec[3]);

    print_test("Agrego clave F: ", abb_guardar(arbol,"F", &vec[4]));
    print_test("El elemento pertenece: ", abb_pertenece(arbol, "F"));
    print_test("Su dato es 5: ", abb_obtener(arbol,"F") == &vec[4]);

    print_test("Agrego clave G: ", abb_guardar(arbol,"G", &vec[5]));
    print_test("El elemento pertenece: ", abb_pertenece(arbol, "G"));
    print_test("Su dato es 6: ", abb_obtener(arbol,"G") == &vec[5]);

    print_test("Agrego clave H: ", abb_guardar(arbol,"H", &vec[6]));
    print_test("El elemento pertenece: ", abb_pertenece(arbol, "H"));
    print_test("Su dato es 7: ", abb_obtener(arbol,"H") == &vec[6]);

    print_test("La cantidad se mantuvo en 7: ", abb_cantidad(arbol) == 7);

    abb_destruir(arbol);
}


void prueba_clave_vacia(){
    printf("\n\nPruebas con clave y dato vacios: \n");
    abb_t *arbol = abb_crear(strcmp, NULL);
    print_test("El arbol se creo correctamente: ", arbol);

    char *clave = "", *valor = "";

    print_test("Se guardo la clave y valor vacios: ",abb_guardar(arbol, clave, valor));
    print_test("La cantidad es 1: ", abb_cantidad(arbol) == 1);
    print_test("La clave vacia pertenece: ", abb_pertenece(arbol, clave));
    print_test("Su elemento es vacio: ", abb_obtener(arbol, clave) == valor);

    print_test("Reemplazo el dato de la clave: ", abb_guardar(arbol, clave, NULL));
    print_test("La cantidad es 1: ", abb_cantidad(arbol) == 1);
    print_test("La clave vacia pertenece: ", abb_pertenece(arbol, clave));
    print_test("Su elemento es NULL: ", abb_obtener(arbol, clave) == NULL);

    abb_borrar(arbol, clave);
    abb_destruir(arbol);
}

/* *****************************************************************
 *                    PRUEBAS DE LOS ITERADORES
 * *****************************************************************/

static void prueba_iterar_abb_vacio(){
    abb_t* abb = abb_crear(strcmp, NULL);
    abb_iter_t* iter = abb_iter_in_crear(abb);
    print_test("Prueba abb iter crear iterador hash vacio", iter);
    print_test("Prueba abb iter esta al final", abb_iter_in_al_final(iter));
    print_test("Prueba abb iter avanzar es false", !abb_iter_in_avanzar(iter));
    print_test("Prueba abb iter ver actual es NULL", !abb_iter_in_ver_actual(iter));

    abb_iter_in_destruir(iter);
    abb_destruir(abb);
}

static size_t buscar(const char* clave, char* claves[], size_t largo)
{
    for (size_t i = 0; i < largo; i++) {
        if (strcmp(clave, claves[i]) == 0) return (size_t) i;
    }
    return -1;
}


static void prueba_abb_iterar(){
    abb_t* abb = abb_crear(strcmp, NULL);

    char *claves[] = {"perro", "gato", "vaca"};
    char *valores[] = {"guau", "miau", "mu"};

    // Inserta 3 valores 
    print_test("Prueba abb insertar clave1", abb_guardar(abb, claves[0], valores[0]));
    print_test("Prueba abb insertar clave2", abb_guardar(abb, claves[1], valores[1]));
    print_test("Prueba abb insertar clave3", abb_guardar(abb, claves[2], valores[2]));

    // Prueba de iteración sobre las claves almacenadas.
    abb_iter_t* iter = abb_iter_in_crear(abb);
    const char *clave;
    size_t indice;

    print_test("Prueba abb iterador esta al final, es false", !abb_iter_in_al_final(iter));

    // Primer valor 
    clave = abb_iter_in_ver_actual(iter);
    indice = buscar(clave, claves, sizeof(claves) / sizeof(char *));
    print_test("Prueba abb iterador ver actual, es una clave valida", indice != -1);
    print_test("Prueba abb iterador ver actual, no es el mismo puntero", clave != claves[indice]);
    print_test("Prueba abb iterador avanzar es true", abb_iter_in_avanzar(iter));
    print_test("Prueba abb iterador esta al final, es false", !abb_iter_in_al_final(iter));

    // Segundo valor 
    clave = abb_iter_in_ver_actual(iter);
    indice = buscar(clave, claves, sizeof(claves) / sizeof(char *));
    print_test("Prueba abb iterador ver actual, es una clave valida", indice != -1);
    print_test("Prueba abb iterador ver actual, no es el mismo puntero", clave != claves[indice]);
    print_test("Prueba abb iterador avanzar es true", abb_iter_in_avanzar(iter));
    print_test("Prueba abb iterador esta al final, es false", !abb_iter_in_al_final(iter));

    // Tercer valor 
    clave = abb_iter_in_ver_actual(iter);
    indice = buscar(clave, claves, sizeof(claves) / sizeof(char *));
    print_test("Prueba abb iterador ver actual, es una clave valida", indice != -1);
    print_test("Prueba abb iterador ver actual, no es el mismo puntero", clave != claves[indice]);
    abb_iter_in_avanzar(iter);
    print_test("Prueba abb iterador esta al final, es true", abb_iter_in_al_final(iter));

    // Vuelve a tratar de avanzar, por las dudas 
    print_test("Prueba abb iterador ver actual, es NULL", !abb_iter_in_ver_actual(iter));
    print_test("Prueba abb iterador avanzar es false", !abb_iter_in_avanzar(iter));
    print_test("Prueba abb iterador esta al final, es true", abb_iter_in_al_final(iter));

    abb_iter_in_destruir(iter);
    abb_destruir(abb);
}

void generar_claves(char* claves[], size_t largo){
    for(size_t i = 0; i <largo; i++){
        claves[i] = malloc(10 * sizeof(char));
        sprintf(claves[i], "%ld", rand() % largo);
    }
}

void prueba_abb_iterar_volumen(size_t largo){
    abb_t* abb = abb_crear(strcmp, NULL);
    char **claves = malloc(largo * sizeof(char *));

    generar_claves(claves, largo);

    size_t valores[largo];

     //Inserta 'largo' parejas en el hash 
    bool ok = true;
    for (unsigned i = 0; i < largo; i++) {
        sprintf(claves[i], "%08d", i);
        valores[i] = i;
    }


    for (unsigned i = 0; i < largo; i++) {
        ok = abb_guardar(abb, claves[i], &valores[i]);
        if(!ok) break;
    }

    // Prueba de iteración sobre las claves almacenadas.
    abb_iter_t* iter = abb_iter_in_crear(abb);
    print_test("Prueba abb iterador esta al final, es false", !abb_iter_in_al_final(iter));

    ok = true;
    unsigned i;
    const char *clave;
    size_t *valor;

    for (i = 0; i < largo; i++) {
        if ( abb_iter_in_al_final(iter) ) {
            ok = false;
            break;
        }
        clave = abb_iter_in_ver_actual(iter);
        if ( clave == NULL ) {
            ok = false;
            break;
        }
        valor = abb_obtener(abb, clave);
        if ( valor == NULL ) {
            ok = false;
            break;
        }
        *valor = largo;
        abb_iter_in_avanzar(iter);
    }
    print_test("Prueba abb iteración en volumen", ok);
    print_test("Prueba abb iteración en volumen, recorrio todo el largo", i == largo);
    print_test("Prueba abb iterador esta al final, es true", abb_iter_in_al_final(iter));

    ok = true;
    for (i = 0; i < largo; i++) {
        if ( valores[i] != largo ) {
            ok = false;
            break;
        }
    }
    print_test("Prueba abb iteración en volumen, se cambiaron todo los elementos", ok);

    for(size_t j = 0; j < largo; j++){
        free(claves[j]);
    }

    free(claves);
    abb_iter_in_destruir(iter);
    abb_destruir(abb);
}

/* *****************************************************************
 *                    LLAMADO A PRUEBAS
 * *****************************************************************/



void pruebas_abb_estudiante(){
    pruebas_abb_vacio();
    pruebas_abb_pocos_elementos();
    pruebas_datos_NULL();
    prueba_borrar_ABB_entero();
    prueba_volumen_1000();
    prueba_volumen_10000();
    pruebas_datos_heap();
    prueba_reemplazando_datos();
    prueba_clave_vacia();
    prueba_abb_iterar_volumen(1000);
    prueba_iterar_abb_vacio();
    prueba_abb_iterar();
    
}
/*
 * Función main() que llama a la función de pruebas.
 */

#ifndef CORRECTOR  // Para que no dé conflicto con el main() del corrector.

int main(void) {
    pruebas_abb_estudiante();
    return failure_count() > 0;  // Indica si falló alguna prueba.
}

#endif
