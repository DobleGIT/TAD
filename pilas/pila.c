#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "pila.h"


int pilaCreaVacia (Pila *p)
{
	
    if (p == NULL)
    	return -1;

    else {

    	*p = NULL;
    	return 0;
	}
	
} 

int pilaVacia (Pila *p)
{
	
    if (p == NULL)
    	return -1;

    else if (*p == NULL)
    	return 1;

    else

    	return 0; 
    	
} 

int pilaInserta (Pila *p,tipoElemento elemento)
{
	
	tipoCelda *aux;
	
    if (p == NULL)
    	return -1;

    else {
    	
    	aux = malloc (sizeof(tipoCelda));
    	
    	if (aux == NULL)
    		return -2;
    	
    	aux->elemento = elemento;
    	
    	if (*p == NULL)

    		aux->sig = NULL;

		else

			aux->sig = *p;
			
		*p = aux;
		
		return 0;
	}
    
    
} 

tipoElemento pilaSuprime (Pila *p)
{
	
	tipoCelda *aBorrar;
	tipoElemento elemento;
	
    if (p == NULL)
    	return -1;
    	
    else if (*p == NULL)
		return -2;
		
	else {
		
    	aBorrar = *p;
    	elemento = aBorrar->elemento;
    	*p = aBorrar->sig;
    	
    	free (aBorrar);
    	return elemento;
	}
    
}

