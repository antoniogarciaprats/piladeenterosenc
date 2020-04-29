// -----------------------------------------------------------------------

// pila_int.h  MODULO DE CABECERAS PARA USO DE OBJETOS PILAS DINAMICAS

// -----------------------------------------------------------------------

#ifndef PILA_INT_TYPO

#define PILA_INT_TYPO

struct pila_int_typo   {
       int x;
   };

typedef struct pila_int_cabec *pila_int;

pila_int pila_int_init (void);
int pila_int_empty (pila_int p);
void pila_int_push (pila_int p, struct pila_int_typo *n);
void pila_int_pop (pila_int p, struct pila_int_typo *n);
pila_int pila_int_copy (pila_int p);
void pila_int_look (pila_int p, struct pila_int_typo *n);
void pila_int_delete (pila_int *p);

#endif


