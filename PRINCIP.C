// ------------------------------------------------------------------------
//		             PROGRAMA PRINCIPAL
// ------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include "pila_int.h"

// -----------------------------------------------------------------------
// 		PRIMITIVA QUE CALCULA EL FIBONACCI DE UN NUMERO
// -----------------------------------------------------------------------

unsigned long Fibonacci (int num)     {
     pila_int res;
     struct pila_int_typo n;
     unsigned long fib = 0;

     if (num < 0)   {
	   fprintf (stderr, "\n Fibonacci: El fibonacci de un numero negativo no existe.\n");
	   exit (-1);
	}

     res = pila_int_init ();
     n.x = num;
     pila_int_push (res, &n);
     while (!pila_int_empty (res))    {
	   pila_int_pop (res, &n);
	   if ((n.x == 0) || (n.x == 1))   fib += n.x;
	   else    {
		n.x = n.x--;      pila_int_push (res, &n);
		n.x = n.x--;      pila_int_push (res, &n);
	     }
       }

     pila_int_delete (&res);
     return (fib);
   }

// -----------------------------------------------------------------------

void main (int argc, char *argv[])   {
	int i, num;
	unsigned long fib;
	if (argc < 2)    {
		printf ("\n ERROR (Fibonacc): La ejecucion del progama se debe hacer de la forma:\n");
		printf ("\t fibonacc <n1> <n2> ... <nn>");
		exit (1);
	   }

	for (i = 1; i < argc; i++)   {
		num = atoi (argv [i]);
		fib = Fibonacci (num);
		printf ("\n Fibonacci (%d) = %lu" ,num, fib);
	   }
  }

// ----------------------------------------------------------------------