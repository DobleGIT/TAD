#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "lista.h"


int creaVacia (Lista *l)
{


    if (l == NULL)
        return -2;

    else if (NULL == (l->raiz = l->ultimo = (tipoCelda *) malloc(sizeof(tipoCelda))))
		return -1;
		
	else {
		
       	l->raiz->sig = NULL;
        return 0;
    }

} 

int vacia (Lista *l)
{

    if (l == NULL || l->raiz == NULL) 
        return -1;

    else if (l->raiz->sig == NULL)
		return 1;
		
	else	
        return 0;

} 

int destruye (Lista *l)
{
    if (l == NULL || l->raiz == NULL) 
        return -1;
    
    else if (l->raiz->sig != NULL) 
        return -2;
        
	else {
    	
        free(l->raiz);
        l->raiz = l->ultimo = NULL;
        
        return 0;
    }
    
} 

void imprime (Lista *l)
{
    tipoCelda *aImprimir;
    int pos;
    
    if (l == NULL || l->raiz == NULL) {
        return;
        
    } else {
    	
    	aImprimir = l->raiz->sig;
        pos = 1;
        
        while (aImprimir != NULL) {
        	
            printf("El valor %d esta en la posicion %d \n", aImprimir->elemento, pos++);
            aImprimir = aImprimir->sig;
        }
        
        printf("Hay %d valores en la lista", pos - 1);
    }
    
} 

tipoPosicion anterior (tipoPosicion p, Lista *l)
{
	
    tipoCelda *anterior;
    
    if (l == NULL || l->raiz == NULL || p == NULL) {
        return NULL;
        
    } else if (p == l->raiz) {
    	
        return l->raiz;
        
    } else {
    	
        anterior = l->raiz;
        
        while (anterior->sig != p)
            anterior = anterior->sig;
            
        return anterior;
        
    }
    
} 

tipoPosicion primero (Lista *l)
{	
    if (l == NULL || l->raiz == NULL)
    
    	return NULL;
    	
    else
    
    	return l->raiz;
    	
} 

tipoPosicion fin (Lista *l)
{
	
    if (l == NULL || l->raiz == NULL)
    
    	return NULL;
    	
    else
    
    	return l->ultimo;
		   
}

int inserta (tipoElemento x, tipoPosicion p, Lista *l)
{
	
	tipoPosicion aux;
	
    if (l == NULL || l->raiz == NULL || p == NULL)  
    
		return -1;
		
	else {
		
		aux = malloc (sizeof(tipoCelda));
		
		if (aux == NULL)
			return -2;
			
		aux->sig = p->sig;	
		aux->elemento = x;
		p->sig = aux;
		
		if (p == l->ultimo)
			l->ultimo = aux;
			
		return 0;
	} 
	
} 

int suprime (tipoPosicion p, Lista *l)
{
   tipoPosicion tmp;
	
	if(vacia(l) == -1) {
		return -1; 
	}
	else if(p == NULL) {
		return -2; 
	}else{
	

		tmp = p->sig;
		p->sig = tmp->sig;
		
		if(p->sig == NULL) {
			l->ultimo = p;
		}
		
		free(tmp);

		return 0; 
	}
} 
	


tipoPosicion siguiente (tipoPosicion p, Lista *l)
{
    if (l == NULL || l->raiz == NULL || p == NULL)
    	return NULL;
    	
    else if (p == l->ultimo)
    	return l->ultimo;
    	
    else 

    	return p->sig;
	
	
}

tipoPosicion localiza (tipoElemento x, Lista *l)
{
    tipoPosicion aux;
    
    if (l == NULL || l->raiz == NULL)
    
    	return NULL;
    	
    else {
    	
    	aux = l->raiz;
    	
    	while (aux->sig != NULL) {
    		
			if (aux->sig->elemento == x)
				return aux;
				
			aux = aux->sig;
		}
    	
    	return l->ultimo;
	}
	
}

tipoElemento recupera (tipoPosicion p, Lista *l)
{
	
    if (l == NULL || l->raiz == NULL || p == NULL)
    	return -1;
    	
    else if (p == l->ultimo)
    	return -2;
    	
	else
		return p->sig->elemento;
		
} 

int anula (Lista *l)
{
	
	tipoPosicion aux;
    aux=l->raiz->sig;
    l->raiz->sig==NULL;
	tipoPosicion aBorrar;

    if(vacia(l) == -1) {

    		return -1; 

    	}else if(vacia(l) == 0) {

    		return 0;

    	}
	
    while(fin(aux)!=0)
    {
        aBorrar=aux;
        aux=siguiente(aux,l);
        if(aBorrar!=NULL)
        {
            free(aBorrar);
        }
    }
		
	l->ultimo=primero(l);
	return 0;
		
	
	
}

int concatena(Lista *lA, Lista *lB)
{
    tipoPosicion finalA, inicioB, q;
	
	if(vacia(lA) == -1 || vacia(lB) == -1) {
		return -1; 
	}
	
	lA->ultimo->sig = lB->raiz->sig;
	lA->ultimo = lB->ultimo;
	lB->raiz->sig = NULL;
	lB->ultimo = lB->raiz;
    
        
   return 0;  
  	
} 





