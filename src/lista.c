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
	nodo_t *nodo_penultimo;
	nodo_t *nodo_final;
	size_t cantidad_elementos;
};

struct lista_iterador {
	nodo_t *actual;
	lista_t *lista;
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
	if (!nuevo_nodo)
		return NULL;

	if (lista->cantidad_elementos == 0) {
		lista->nodo_inicio = nuevo_nodo;
		lista->nodo_final = nuevo_nodo;
		lista->nodo_inicio->siguiente = lista->nodo_final;
	} else {
		lista->nodo_penultimo = lista->nodo_final;
		lista->nodo_final->siguiente = nuevo_nodo;
		lista->nodo_final = lista->nodo_final->siguiente;
	}

	lista->cantidad_elementos++;
	return lista;
}

lista_t *lista_insertar_en_posicion(lista_t *lista, void *elemento,
				    size_t posicion)
{
	return NULL;
}

void *lista_quitar(lista_t *lista)
{
	return NULL;
}

void *lista_quitar_de_posicion(lista_t *lista, size_t posicion)
{
	return NULL;
}

void *lista_elemento_en_posicion(lista_t *lista, size_t posicion)
{
	return NULL;
}

void *lista_buscar_elemento(lista_t *lista, int (*comparador)(void *, void *),
			    void *contexto)
{
	return NULL;
}

void *lista_primero(lista_t *lista)
{
	return NULL;
}

void *lista_ultimo(lista_t *lista)
{
	return NULL;
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
	free(lista);
}

void lista_destruir_todo(lista_t *lista, void (*funcion)(void *))
{
	for (size_t i = 0; i < lista_tamanio(lista); i++) {
		nodo_t *actual = malloc(sizeof(nodo_t *));
		if (!actual) {
			free(actual);
			free(lista);
		}
		nodo_t *aux = malloc(sizeof(nodo_t *));
		if (!aux) {
			free(actual);
			free(lista);
		}
		aux = actual->siguiente;
		free(actual);
		// !!!!!!!REVER
	}
}

lista_iterador_t *lista_iterador_crear(lista_t *lista)
{
	return NULL;
}

bool lista_iterador_tiene_siguiente(lista_iterador_t *iterador)
{
	return false;
}

bool lista_iterador_avanzar(lista_iterador_t *iterador)
{
	return false;
}

void *lista_iterador_elemento_actual(lista_iterador_t *iterador)
{
	return NULL;
}

void lista_iterador_destruir(lista_iterador_t *iterador)
{
}

size_t lista_con_cada_elemento(lista_t *lista, bool (*funcion)(void *, void *),
			       void *contexto)
{
	return 0;
}
