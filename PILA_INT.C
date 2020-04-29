// ----------------------------------------------------------------------

// pila_int.c MODULO DE PROCEDIMIENTOS EN C PARA USO DE OBJETOS PILAS
//	      DINAMICAS

// ---------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <alloc.h>
#include "pila_int.h"

struct pila_int_cabec   {
	struct pila_int_ele *punt;
    };

struct pila_int_ele   {
	struct pila_int_typo val;
	struct pila_int_ele *sig;
    };

// ----------------------------------------------------------------------
//		  	FUNCIONES PRIVADAS
// ----------------------------------------------------------------------

void pila_int_error (int error, char *prim)    {
	switch (error)   {
	     case 1: fprintf (stderr, "\n\n\t%s: No hay suficiente memoria.\n", prim);
		     break;
	     case 2: fprintf (stderr, "\n\n\t%s: La pila no existe.\n", prim);
		     break;
	     case 3: fprintf (stderr, "\n\n\t%s: La pila esta vacia.\n", prim);
		     break;
	  }
   }
// ----------------------------------------------------------------------
//			FUNCIONES PUBLICAS
// ----------------------------------------------------------------------

pila_int pila_int_init ()     {
	pila_int nueva;

	nueva = (struct pila_int_cabec *) malloc (sizeof (struct pila_int_cabec));
	if (!nueva)    {
		pila_int_error (1, "pila_int_init");
		exit (-1);
	   }
	nueva -> punt = NULL;
	return (nueva);
   }
// ----------------------------------------------------------------------

int pila_int_empty (pila_int p)    {
	if (!p)   {
		pila_int_error (2, "pila_int_empty");
		exit (-1);
	   }
	return (p -> punt == NULL);
    }
// ----------------------------------------------------------------------

void pila_int_push (pila_int p, struct pila_int_typo *n)    {
	struct pila_int_ele *nuevo;

	if (!p)    {
		pila_int_error (2, "pila_int_push");
		exit (-1);
	   }
	nuevo = (struct pila_int_ele *) malloc (sizeof (struct pila_int_ele));
	if (!nuevo)   {
		pila_int_error (1, "pila_int_push");
		exit (-1);
	   }
	nuevo -> val = *n;
	if (pila_int_empty (p))   nuevo -> sig = NULL;
	else  nuevo -> sig = p -> punt;
	p -> punt = nuevo;
   }
// ----------------------------------------------------------------------

void pila_int_pop (pila_int p, struct pila_int_typo *n)    {
	struct pila_int_ele *viejo;

	if (!p)    {
		pila_int_error (2, "pila_int_pop");
		exit (-1);
	   }
	if (pila_int_empty (p))    {
		pila_int_error (3, "pila_int_pop");
		exit (-1);
	   }
	viejo = p -> punt;
	*n = viejo -> val;
	if (viejo -> sig == NULL)   p -> punt = NULL;
	else  p -> punt = viejo -> sig;
	free (viejo);
   }
// ----------------------------------------------------------------------

pila_int pila_int_copy (pila_int p)    {
	pila_int res;
	struct pila_int_ele *nuevo, *corr1, *corr2;

	if (!p)    {
		pila_int_error (2, "pila_int_copy");
		exit (-1);
	   }
	res = (struct pila_int_cabec *) malloc (sizeof (struct pila_int_cabec));
	if (!res)    {
		pila_int_error (1, "pila_int_copy");
		exit (-1);
	   }
	res -> punt = NULL;
	corr1 = p -> punt;
	while (corr1)   {
	      nuevo = (struct pila_int_ele *) malloc (sizeof (struct pila_int_ele));
	      if (!nuevo)   {
		    pila_int_error (1, "pila_int_copy");
		    exit (-1);
		 }
	      nuevo -> val = corr1 -> val;
	      nuevo -> sig = NULL;
	      if (pila_int_empty (res))    {
		    res -> punt = nuevo;
		    corr2 = nuevo;
		}
	      else  {
		    corr2 -> sig = nuevo;
		    corr2 = corr2 -> sig;
		}
	      corr1 = corr1 -> sig;
	  }
	return (res);
   }
// ----------------------------------------------------------------------

void pila_int_look (pila_int p, struct pila_int_typo *n)     {
	if (!p)    {
		pila_int_error (2, "pila_int_look");
		exit (-1);
	   }
	if (pila_int_empty (p))    {
		pila_int_error (3, "pila_int_look");
		exit (-1);
	   }
	*n = p -> punt -> val;
   }
// ----------------------------------------------------------------------

void pila_int_delete (pila_int *p)   {
	struct pila_int_ele *viejo;

	if (!*p)    {
		pila_int_error (2, "pila_int_delete");
		exit (-1);
	   }
	while (!pila_int_empty (*p))    {
		viejo = (*p) -> punt;
		(*p) -> punt = viejo -> sig;
		free (viejo);
	   }
	free (*p);
	*p = NULL;
   }
// ----------------------------------------------------------------------
