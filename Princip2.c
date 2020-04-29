// ------------------------------------------------------------------------
//		             PROGRAMA PRINCIPAL
// ------------------------------------------------------------------------

#include <stdio.h>
#include <conio.h>
#include "pila_int.h"

// -----------------------------------------------------------------------
// 		PRIMITIVA QUE CALCULA EL FIBONACCI DE UN NUMERO
// -----------------------------------------------------------------------

int Fibonacci (int num)     {
     pila_int res;
     struct pila_int_typo n;
     int fib = 0;

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

void main ()   {
    char opc, fin, seguir = 's';
    pila_int a = NULL, b = NULL;
    struct pila_int_typo n;
    int i, f;

    clrscr ();
    while (seguir == 's')   {

      printf ("\t MANEJO DE UNA PILA DINAMICA\n\n");
      printf ("\t a) Crear una pila vacia.\n");
      printf ("\t b) Introducir un elemento.\n");
      printf ("\t c) Sacar un elemento.\n");
      printf ("\t d) Mirar el elemento tope.\n");
      printf ("\t e) Realizar una copia.\n");
      printf ("\t f) Calcular la serie de Fibonacci.\n");
      printf ("\t s) Salir.\n");

      printf ("\n\t Introduzca la opcion a realizar: ");
      opc = getche ();
      switch (opc)    {
	    case 'a': a = pila_int_init ();
		      printf ("\n\n\t Operacion realizada...");
		      break;
	    case 'b': printf ("\n\n\t Introduzca el dato a guardar en la pila: ");
		      scanf ("%d", &n.x);
		      pila_int_push (a, &n);
		      break;
	    case 'c': pila_int_pop (a, &n);
		      printf ("\n\n\t El primer elemento es el: %d", n.x);
		      break;
	    case 'd': pila_int_look (a, &n);
		      printf ("\n\n\t El primer elemento de la pila A es el: %d", n.x);
		      pila_int_look (b, &n);
		      printf ("\n\n\t El primer elemento de la pila B es el: %d", n.x);
		      break;
	    case 'e': b = pila_int_copy (a);
		      printf ("\n\n\t Operacion realizada...");
		      break;
	    case 'f': printf ("\n\n\t La serie de Fibonacci queda de la siguiente forma:\n\n\t ");
		      for (i = 0; i < 24; i++)   {
			     f = Fibonacci (i);
			     printf (" %d,", f);
			 }
		      printf (".....");
		      break;
	    case 's': seguir = 'n';
	 }
	printf ("\n\n\t Pulse una tecla para continuar.....");
	fin = getch ();
	clrscr ();
     }
    if (a) pila_int_delete (&a);
    if (b) pila_int_delete (&b);
  }