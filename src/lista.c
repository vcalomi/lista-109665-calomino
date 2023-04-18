#include "lista.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct nodo {
	void *elemento;
	struct nodo *siguiente;
} nodo_t;

struct lista {
	nodo_t *nodo_inicio;
	nodo_t *nodo_final;
	size_t cantidad_elementos;
};

struct lista_iterador {
	nodo_t *actual;
	lista_t *lista;
	size_t iteraciones;
};

lista_t *lista_crear()
{
	return calloc(1, sizeof(lista_t));
}

lista_t *lista_insertar(lista_t *lista, void *elemento)
{
	if (!lista)
		return NULL;

	nodo_t *nuevo_nodo = calloc(1, sizeof(nodo_t));
	if (!nuevo_nodo) {
		free(nuevo_nodo);
		return NULL;
	}
	nuevo_nodo->elemento = elemento;

	if (lista->cantidad_elementos == 0) {
		lista->nodo_inicio = nuevo_nodo;
		lista->nodo_final = nuevo_nodo;
		lista->nodo_inicio->siguiente = NULL;
	} else {
		lista->nodo_final->siguiente = nuevo_nodo;
		lista->nodo_final = lista->nodo_final->siguiente;
	}

	lista->cantidad_elementos++;
	return lista;
}

lista_t *lista_insertar_en_posicion(lista_t *lista, void *elemento,
				    size_t posicion)
{
	if (!lista)
		return NULL;
	if (posicion >= lista->cantidad_elementos) {
		lista_insertar(lista, elemento);
		return lista;
	}
	nodo_t *nuevo_nodo = calloc(1, sizeof(nodo_t));
	if (!nuevo_nodo) {
		free(nuevo_nodo);
		return NULL;
	}
	nuevo_nodo->elemento = elemento;

	if (posicion == 0) {
		nodo_t *aux = lista->nodo_inicio;
		lista->nodo_inicio = nuevo_nodo;
		lista->nodo_inicio->siguiente = aux;
		lista->cantidad_elementos++;
		return lista;
	}

	nodo_t *actual = lista->nodo_inicio;
	size_t posicion_actual = 0;
	while (actual) {
		if (posicion - 1 == posicion_actual) {
			nodo_t *aux = actual->siguiente;
			actual->siguiente = nuevo_nodo;
			nuevo_nodo->siguiente = aux;
			lista->cantidad_elementos++;
			return lista;
		}
		posicion_actual++;
		actual = actual->siguiente;
	}
	free(nuevo_nodo);
	return NULL;
}

void *lista_quitar(lista_t *lista)
{
	if (!lista || !lista->cantidad_elementos)
		return NULL;
	if (lista->cantidad_elementos == 1) {
		nodo_t *aux = lista->nodo_inicio;
		lista->nodo_inicio = NULL;
		lista->nodo_final = NULL;
		lista->cantidad_elementos--;
		void *elemento = aux->elemento;
		free(aux);
		return elemento;
	}
	nodo_t *actual = lista->nodo_inicio;
	while (actual) {
		if (actual->siguiente == lista->nodo_final) {
			lista->cantidad_elementos--;
			nodo_t *aux = lista->nodo_final;
			actual->siguiente = NULL;
			lista->nodo_final = actual;
			void *elemento = aux->elemento;
			free(aux);
			return elemento;
		}
		actual = actual->siguiente;
	}
	return NULL;
}

void *lista_quitar_de_posicion(lista_t *lista, size_t posicion)
{
	if (!lista)
		return NULL;
	if (posicion >= lista->cantidad_elementos) {
		return lista_quitar(lista);
	}

	if (posicion == 0) {
		nodo_t *aux = lista->nodo_inicio;
		lista->nodo_inicio = lista->nodo_inicio->siguiente;
		lista->cantidad_elementos--;
		void *elemento = aux->elemento;
		free(aux);
		return elemento;
	}

	nodo_t *act = lista->nodo_inicio;
	nodo_t *ant = NULL;
	size_t posicion_actual = 0;
	while (act) {
		if (posicion_actual == posicion) {
			ant->siguiente = act->siguiente;
			lista->cantidad_elementos--;
			void *elemento = act->elemento;
			free(act);
			return elemento;
		}
		posicion_actual++;
		ant = act;
		act = act->siguiente;
	}

	return NULL;
}

void *lista_elemento_en_posicion(lista_t *lista, size_t posicion)
{
	if (!lista || posicion >= lista->cantidad_elementos) {
		return NULL;
	}

	size_t posicion_actual = 0;
	nodo_t *actual = lista->nodo_inicio;
	while (actual) {
		if (posicion == posicion_actual) {
			return actual->elemento;
		}
		actual = actual->siguiente;
		posicion_actual++;
	}
	return actual->elemento;
}

void *lista_buscar_elemento(lista_t *lista, int (*comparador)(void *, void *),
			    void *contexto)
{
	if (!lista || !comparador || !lista->nodo_inicio)
		return NULL;

	nodo_t *actual = lista->nodo_inicio;
	while (actual) {
		if (comparador(actual->elemento, contexto) == 0)
			return actual->elemento;
		actual = actual->siguiente;
	}
	return NULL;
}

void *lista_primero(lista_t *lista)
{
	if (!lista || lista->cantidad_elementos == 0)
		return NULL;
	return lista->nodo_inicio->elemento;
}

void *lista_ultimo(lista_t *lista)
{
	if (!lista || lista->cantidad_elementos == 0)
		return NULL;
	return lista->nodo_final->elemento;
}

bool lista_vacia(lista_t *lista)
{
	if (!lista)
		return true;
	if (!lista->nodo_inicio)
		return true;
	if (lista->cantidad_elementos == 0)
		return true;
	return false;
}

size_t lista_tamanio(lista_t *lista)
{
	if (!lista)
		return 0;
	return lista->cantidad_elementos;
}

void lista_destruir(lista_t *lista)
{
	if (!lista)
		return;
	nodo_t *actual = lista->nodo_inicio;
	while (actual) {
		nodo_t *siguiente = actual->siguiente;
		free(actual);
		actual = siguiente;
	}
	free(lista);
}

void lista_destruir_todo(lista_t *lista, void (*funcion)(void *))
{
	if (!lista)
		return;
	if (funcion != NULL) {
		nodo_t *actual = lista->nodo_inicio;
		while (actual) {
			nodo_t *siguiente = actual->siguiente;
			funcion(actual->elemento);
			actual = siguiente;
		}
	}
	lista_destruir(lista);
}

lista_iterador_t *lista_iterador_crear(lista_t *lista)
{
	if (!lista)
		return NULL;
	lista_iterador_t *iterador = calloc(1, sizeof(lista_iterador_t));
	if (!iterador) {
		free(iterador);
		return NULL;
	}
	iterador->lista = lista;
	iterador->actual = lista->nodo_inicio;
	return iterador;
}

bool lista_iterador_tiene_siguiente(lista_iterador_t *iterador)
{
	if (!iterador || !iterador->lista->cantidad_elementos) {
		return false;
	}
	if (iterador->iteraciones < iterador->lista->cantidad_elementos) {
		return true;
	}

	return false;
}

bool lista_iterador_avanzar(lista_iterador_t *iterador)
{
	if (lista_iterador_tiene_siguiente(iterador)) {
		iterador->actual = iterador->actual->siguiente;

		iterador->iteraciones++;
		return true;
	}
	return false;
}

void *lista_iterador_elemento_actual(lista_iterador_t *iterador)
{
	if (!iterador || !iterador->lista ||
	    !iterador->lista->cantidad_elementos)
		return NULL;
	if (iterador->iteraciones == iterador->lista->cantidad_elementos)
		return NULL;
	return iterador->actual->elemento;
}

void lista_iterador_destruir(lista_iterador_t *iterador)
{
	free(iterador);
}

size_t lista_con_cada_elemento(lista_t *lista, bool (*funcion)(void *, void *),
			       void *contexto)
{
	if (!lista || !funcion)
		return 0;

	nodo_t *actual = lista->nodo_inicio;
	size_t elementos_recorridos = 0;
	while (actual) {
		if (funcion(actual->elemento, contexto)) {
			elementos_recorridos++;
		} else if (!funcion(actual->elemento, contexto)) {
			elementos_recorridos++;
			return elementos_recorridos;
		}
		actual = actual->siguiente;
	}
	return elementos_recorridos;
}
