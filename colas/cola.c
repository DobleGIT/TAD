#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "cola.h"

//Jaime Gomez Garcia 

int colaCreaVacia (Cola *c)
{
	
    if (c == NULL)
    {
	 return -1;    	
	}
		
	else 
	{
		
		c->frente = c->fondo=NULL;
		return 0;
			
	}
	
}

int colaVacia (Cola *c)
{
	
    if (c == NULL)
    {
    	return -1;	
	}
	else if (c->frente == NULL && c->fondo == NULL)
	{
		return 1;
	}	
	else
	{
		return 0; //la cola no esta vacia
	}
   	
} 

int colaInserta (Cola *c, tipoElemento elemento)
{
	tipoCelda *aux;
	
    if (c == NULL)
    {
    	return -1;
	}
	
	else 
	{
		
		aux = malloc (sizeof(tipoCelda));
		
		if (aux == NULL)
			return -2;
			
		aux->elemento = elemento;
		aux->sig = NULL;
		
		if (colaVacia(c))
			c->fondo = c->frente = aux;
			
		else {
			
			c->fondo->sig = aux;
			c->fondo = aux;
			
		}
	}
		
		return 0;
}  

tipoElemento colaSuprime(Cola *c)
{
    tipoCelda *aBorrar;
	tipoElemento elemento;

	if(c==NULL){

		return -1;
	} else if(c->frente == NULL && c->fondo == NULL){

			return -2;

		}else{

			aBorrar=c->frente;
			elemento=aBorrar->elemento;

			if(c->fondo==c->frente){
			c->frente=c->fondo=NULL;
			}else{
			c->frente=aBorrar->sig;
			}

			free(aBorrar);
			return elemento;
			
		}
}

