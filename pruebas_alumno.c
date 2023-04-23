#include <stdlib.h>

#include "pa2m.h"
#include "src/lista.h"
#include "src/pila.h"
#include "src/cola.h"

void insertar_elementos()
{
	int *valor = malloc(sizeof(int));
	*valor = 1;
	int *valor_2 = malloc(sizeof(int));
	*valor_2 = 2;
	int *valor_3 = malloc(sizeof(int));
	*valor_3 = 3;
	int *valor_4 = malloc(sizeof(int));
	*valor_4 = 4;
	int *valor_5 = malloc(sizeof(int));
	*valor_5 = 5;
	int *valor_6 = malloc(sizeof(int));
	*valor_6 = 6;
	lista_t *lista = lista_crear();

	pa2m_afirmar(lista_insertar(lista, valor) != NULL,
		     "Insertar al final devuelve la lista");
	pa2m_afirmar(lista_tamanio(lista) == 1, "La lista tiene 1 elemento");
	pa2m_afirmar(lista_vacia(lista) == false, "La lista no esta vacia");
	pa2m_afirmar(lista_insertar_en_posicion(lista, valor, 0) == lista,
		     "Insertar un elemento en pos 0 devuelve la lista");
	pa2m_afirmar(lista_tamanio(lista) == 2, "La lista tiene 2 elementos");
	pa2m_afirmar(lista_insertar_en_posicion(lista, valor_2, 1) == lista,
		     "Insertar en pos 1 devuelve la lista");
	pa2m_afirmar(lista_tamanio(lista) == 3, "La lista tiene 3 elementos");
	pa2m_afirmar(lista_insertar_en_posicion(lista, valor_3, 100) == lista,
		     "Insertar en pos 100 devuelve la lista");
	pa2m_afirmar(lista_tamanio(lista) == 4, "La lista tiene 4 elementos");
	pa2m_afirmar(lista_insertar_en_posicion(lista, valor_4, 2) == lista,
		     "Insertar en pos 2 devuelve la lista");
	pa2m_afirmar(lista_tamanio(lista) == 5, "La lista tiene 5 elementos");
	pa2m_afirmar(lista_insertar_en_posicion(lista, valor_5, 4) == lista,
		     "Insertar en pos 4 devuelve la lista");
	pa2m_afirmar(lista_tamanio(lista) == 6, "La lista tiene 6 elementos");
	pa2m_afirmar(lista_insertar_en_posicion(lista, valor_6, 6) == lista,
		     "Insertar en pos 6 devuelve la lista");
	pa2m_afirmar(lista_tamanio(lista) == 7, "La lista tiene 7 elementos");
	pa2m_afirmar(lista_primero(lista) == valor,
		     "El primer elemento de la lista es correcto");
	pa2m_afirmar(lista_elemento_en_posicion(lista, 0) == valor,
		     "El elemento en la posicion 0 es el correcto");
	pa2m_afirmar(lista_elemento_en_posicion(lista, 0) == valor,
		     "El elemento en la posicion 0 es el correcto");
	pa2m_afirmar(lista_elemento_en_posicion(lista, 0) == valor,
		     "El elemento en la posicion 0 es el correcto");
	pa2m_afirmar(lista_elemento_en_posicion(lista, 0) == valor,
		     "El elemento en la posicion 0 es el correcto");
	pa2m_afirmar(lista_elemento_en_posicion(lista, 0) == valor,
		     "El elemento en la posicion 0 es el correcto");
	pa2m_afirmar(lista_elemento_en_posicion(lista, 0) == valor,
		     "El elemento en la posicion 0 es el correcto");
	pa2m_afirmar(lista_ultimo(lista) == valor_6,
		     "El ultimo elemento es el correcto");
	free(valor);
	free(valor_2);
	free(valor_3);
	free(valor_4);
	free(valor_5);
	free(valor_6);
	lista_destruir(lista);
}

void recorrer_con_iterador_externo()
{
	int *valor = malloc(sizeof(int));
	*valor = 1;
	int *valor_2 = malloc(sizeof(int));
	*valor_2 = 2;
	int *valor_3 = malloc(sizeof(int));
	*valor_3 = 3;
	int *valor_4 = malloc(sizeof(int));
	*valor_4 = 4;
	int *valor_5 = malloc(sizeof(int));
	*valor_5 = 5;
	int *valor_6 = malloc(sizeof(int));
	*valor_6 = 6;
	lista_t *lista = lista_crear();
	lista_insertar(lista, valor);

	lista_iterador_t *it = lista_iterador_crear(lista);
	pa2m_afirmar(lista_iterador_tiene_siguiente(it),
		     "El iterador tiene siguiente");
	pa2m_afirmar(lista_iterador_elemento_actual(it) == valor,
		     "El elemento es el correcto");

	lista_insertar(lista, valor_2);
	lista_insertar(lista, valor_3);
	lista_insertar(lista, valor_4);
	lista_insertar(lista, valor_5);
	lista_insertar(lista, valor_6);

	pa2m_afirmar(lista_iterador_avanzar(it) == true,
		     "Puedo avanzar el iterador");
	pa2m_afirmar(lista_iterador_elemento_actual(it) == valor_2,
		     "El elemento es el correcto");
	pa2m_afirmar(lista_iterador_avanzar(it) == true,
		     "Puedo avanzar el iterador");
	pa2m_afirmar(lista_iterador_elemento_actual(it) == valor_3,
		     "El elemento es el correcto");
	pa2m_afirmar(lista_iterador_avanzar(it) == true,
		     "Puedo avanzar el iterador");
	pa2m_afirmar(lista_iterador_elemento_actual(it) == valor_4,
		     "El elemento es el correcto");
	pa2m_afirmar(lista_iterador_avanzar(it) == true,
		     "Puedo avanzar el iterador");
	pa2m_afirmar(lista_iterador_elemento_actual(it) == valor_5,
		     "El elemento es el correcto");
	pa2m_afirmar(lista_iterador_avanzar(it) == true,
		     "Puedo avanzar el iterador");
	pa2m_afirmar(lista_iterador_elemento_actual(it) == valor_6,
		     "El elemento es el correcto");
	pa2m_afirmar(lista_iterador_avanzar(it) == false,
		     "Avanzar el iterador devuelve falso");
	pa2m_afirmar(lista_iterador_elemento_actual(it) == NULL,
		     "El elemento es NULL");

	free(valor);
	free(valor_2);
	free(valor_3);
	free(valor_4);
	free(valor_5);
	free(valor_6);
	lista_destruir(lista);
	lista_iterador_destruir(it);
}

void quitar_elementos()
{
	pa2m_afirmar(lista_quitar(NULL) == NULL,
		     "No puedo quitar un elemento si no hay lista");

	lista_t *lista = lista_crear();

	pa2m_afirmar(lista_quitar(lista) == NULL,
		     "No puedo quitar un elemento si la lista esta vacia");

	int *valor = malloc(sizeof(int));
	*valor = 1;
	int *valor_2 = malloc(sizeof(int));
	*valor_2 = 2;
	int *valor_3 = malloc(sizeof(int));
	*valor_3 = 3;
	int *valor_4 = malloc(sizeof(int));
	*valor_4 = 4;
	int *valor_5 = malloc(sizeof(int));
	*valor_5 = 5;
	int *valor_6 = malloc(sizeof(int));
	*valor_6 = 6;

	lista_insertar(lista, valor);
	lista_insertar(lista, valor_2);
	lista_insertar(lista, valor_3);
	lista_insertar(lista, valor_4);
	lista_insertar(lista, valor_5);
	lista_insertar(lista, valor_6);

	pa2m_afirmar(lista_tamanio(lista) == 6, "La lista tiene 6 elementos");
	pa2m_afirmar(
		lista_quitar(lista) == valor_6,
		"Quitar un elemento al final devuelve el elemento correcto");
	pa2m_afirmar(lista_tamanio(lista) == 5, "La lista tiene 5 elementos");
	pa2m_afirmar(
		lista_quitar_de_posicion(lista, 0) == valor,
		"Quitar el elemento de posicion 0 devuelve el elemento correcto");
	pa2m_afirmar(lista_tamanio(lista) == 4, "La lista tiene 4 elementos");
	pa2m_afirmar(
		lista_quitar_de_posicion(lista, 1) == valor_3,
		"Quitar el elemento de posicion 1 devuelve el elemento correcto");
	pa2m_afirmar(lista_tamanio(lista) == 3, "La lista tiene 3 elementos");
	pa2m_afirmar(
		lista_quitar_de_posicion(lista, 100) == valor_5,
		"Quitar el elemento de posicion mayor que la cantidad de elementos de la lista devuelve el ultimo elemento");
	pa2m_afirmar(lista_tamanio(lista) == 2, "La lista tiene 2 elementos");
	pa2m_afirmar(
		lista_quitar(lista) == valor_4,
		"Quitar un elemento al final devuelve el elemento correcto");
	pa2m_afirmar(lista_vacia(lista) == false, "La lista no esta vacia");
	pa2m_afirmar(
		lista_quitar(lista) == valor_2,
		"Quitar un elemento al final devuelve el elemento correcto");
	pa2m_afirmar(lista_vacia(lista) == true, "La lista esta vacia");

	free(valor);
	free(valor_2);
	free(valor_3);
	free(valor_4);
	free(valor_5);
	free(valor_6);
	lista_destruir(lista);
}

void buscar_elementos()
{
	lista_t *lista = lista_crear();

	int *valor = malloc(sizeof(int));
	*valor = 1;
	int *valor_2 = malloc(sizeof(int));
	*valor_2 = 2;
	int *valor_3 = malloc(sizeof(int));
	*valor_3 = 3;
	int *valor_4 = malloc(sizeof(int));
	*valor_4 = 4;
	int *valor_5 = malloc(sizeof(int));
	*valor_5 = 5;
	int *valor_6 = malloc(sizeof(int));
	*valor_6 = 6;

	lista_insertar(lista, valor);
	lista_insertar(lista, valor_2);
	lista_insertar(lista, valor_3);
	lista_insertar(lista, valor_4);
	lista_insertar(lista, valor_5);
	lista_insertar(lista, valor_6);

	pa2m_afirmar(lista_elemento_en_posicion(NULL, 1) == NULL,
		     "No puedo buscar elementos si no existe la lista");
	pa2m_afirmar(lista_elemento_en_posicion(lista, 3) == valor_4,
		     "El elemento en la posicion 4 es el correcto");
	pa2m_afirmar(
		lista_elemento_en_posicion(lista, 100) == NULL,
		"Buscar un elemento en una posicion inexistente devuelve NULL");
	pa2m_afirmar(lista_primero(lista) == valor,
		     "El elemento en la primera posicion es correcto");
	pa2m_afirmar(lista_ultimo(lista) == valor_6,
		     "El elemento en la ultima posicion es el correcto");
	pa2m_afirmar(lista_buscar_elemento(lista, NULL, 0) == NULL,
		     "No se puede buscar un elemento sin funcion comparadora");

	lista_destruir_todo(lista, free);
}

void pruebas_pila()
{
	pila_t *pila = pila_crear();

	int *valor = malloc(sizeof(int));
	*valor = 1;
	int *valor_2 = malloc(sizeof(int));
	*valor_2 = 2;

	pa2m_afirmar(pila_apilar(NULL, valor) == NULL,
		     "Apilar sino existe pila devuelve NULL");
	pa2m_afirmar(pila_apilar(pila, valor) == pila,
		     "Apilar un elemento devuelve la pila");
	pa2m_afirmar(pila_tope(pila) == valor,
		     "El tope de la pila es el elemento correcto");
	pa2m_afirmar(pila_tamanio(pila) == 1,
		     "El tamaño de la pila es el correcto");
	pa2m_afirmar(pila_vacia(pila) == false, "La pila no esta vacia");
	pa2m_afirmar(pila_apilar(pila, valor_2) == pila,
		     "Apilar un elemento devuelve la pila");
	pa2m_afirmar(pila_desapilar(pila) == valor_2,
		     "Desapilar devuelve el elemento correcto");

	free(valor);
	free(valor_2);
	pila_destruir(pila);
}

void pruebas_cola()
{
	cola_t *cola = cola_crear();

	int *valor = malloc(sizeof(int));
	*valor = 1;
	int *valor_2 = malloc(sizeof(int));
	*valor_2 = 2;

	pa2m_afirmar(cola_encolar(NULL, valor) == NULL,
		     "Encolar si la cola no existe devuelve NULL");
	pa2m_afirmar(cola_encolar(cola, valor) == cola,
		     "Encolar un elemento devuelve la cola");
	pa2m_afirmar(cola_frente(cola) == valor,
		     "El frente de la cola es el elemento correcto");
	pa2m_afirmar(cola_tamanio(cola) == 1,
		     "El tamaño de la cola es el correcto");
	pa2m_afirmar(cola_vacia(cola) == false, "La cola no esta vacia");
	pa2m_afirmar(cola_encolar(cola, valor_2) == cola,
		     "Encolar un elemento devuelve la cola");
	pa2m_afirmar(cola_desencolar(cola) == valor,
		     "Desencolar devuelve el elemento correcto");

	free(valor);
	free(valor_2);
	cola_destruir(cola);
}

int main()
{
	pa2m_nuevo_grupo("\nPruebas de insercion de elementos");
	insertar_elementos();
	pa2m_mostrar_reporte();

	pa2m_nuevo_grupo("\nPruebas de quitar elementos");
	quitar_elementos();
	pa2m_mostrar_reporte();

	pa2m_nuevo_grupo("\nPruebas de buscar elementos");
	buscar_elementos();
	pa2m_mostrar_reporte();

	pa2m_nuevo_grupo("\nPruebas de iterador externo");
	recorrer_con_iterador_externo();

	pa2m_nuevo_grupo("\nPruebas de pila");
	pruebas_pila();

	pa2m_nuevo_grupo("\nPruebas de cola");
	pruebas_cola();

	return pa2m_mostrar_reporte();
}
