
#ifndef _2020640131_h_
#define _2020640131_h_
#include <stdio.h>
#include <stdlib.h>
#include "gotoxy_FCD.h"
#include<string.h>

typedef struct _Nodo{
	int dato;
	struct _Nodo *sig; // Se pone struct porque aun no tengo definida mi estructura	
}Nodo;

Nodo *crearNodo(int _dato){
	Nodo *nuevo; 
	nuevo = (Nodo *)malloc(sizeof(_dato));
	nuevo->dato = _dato;
	nuevo->sig = NULL;
	return nuevo;
}

Nodo *Push(Nodo *top, int _dato){
	Nodo *nuevo;
	nuevo = crearNodo(_dato);
	if(top != NULL){
		nuevo->sig = top;
	}
	return nuevo;
}

void show(Nodo *top){
	int i=30,j=10;
	if(top == NULL){
		gotoxy(24,j);
		printf("La pila esta vacia, probablemente aun no lees el archivo para cargar la pila");
		gotoxy(24,11);
		printf("Regresa al menu y selecciona la opcion [1]");
	}else{
		while(top != NULL){
			gotoxy(i,j);
			printf("El dato de la pila es: %d", top->dato);
			top = top->sig;
			j++;
		} 
	}
}

Nodo *Pop(Nodo *cima){
	Nodo *aux; // variable para obtener la referencia de la cajita que voy a borrar
	aux = cima;
	if(cima != NULL){
		cima = cima -> sig;
		free(aux);
	}
	return cima;
}

int contarNodos(Nodo *top){
	int elementos = 0;
	if(top != NULL){
		while(top != NULL){
			elementos++;
			top = top->sig;
		}
	}
	return elementos;
}

Nodo *read(Nodo *top){
	FILE *archivo = NULL; 
	int _dato=0,i=0;
	Nodo *B = NULL;
	char atrapar='\0';
	archivo = fopen("postfija.txt","rt");
	if(archivo == NULL){
		printf("Hubo un error, probablemente no exista el archivo o se encuentra en otra ruta diferente al programa\n");
	}else{
		while(!feof(archivo)){
			fscanf(archivo,"%c",&atrapar);
			_dato=(int)atrapar;
			if(_dato==32){
				_dato=(int)atrapar-32;
			}else if(_dato==42){
				B = top->sig;
				_dato = (B->dato)*(top->dato);
				printf("\t\t\tB: %d\n",B->dato);
				printf("\t\t\tA: %d\n",top->dato);			
				printf("\t\t\tDato multiplicacion: %d\n",_dato);
				top->sig=Pop(top->sig);
				top = Pop(top);
				top = Push(top,_dato);
				escribirArchivo(top);
			}else if(_dato==43){
				if(top->dato!=58){
					B = top->sig;
					_dato = (B->dato)+(top->dato);
					printf("\t\t\tB: %d\n",B->dato);
					printf("\t\t\tA: %d\n",top->dato);			
					printf("\t\t\tDato suma: %d\n",_dato);
					top->sig=Pop(top->sig);
					top = Pop(top);
					top = Push(top,_dato);
					escribirArchivo(top);
				}
				_dato=(int)atrapar-43;
			}else if(_dato==45){
				B = top->sig;
				_dato = (B->dato)-(top->dato);
				printf("\t\t\tB: %d\n",B->dato);
				printf("\t\t\tA: %d\n",top->dato);			
				printf("\t\t\tDato resta: %d\n",_dato);
				top->sig=Pop(top->sig);
				top = Pop(top);
				top = Push(top,_dato);
				escribirArchivo(top);
			}else if(_dato==47){
				B = top->sig;
				_dato = (B->dato)/(top->dato);
				printf("\t\t\tB: %d\n",B->dato);
				printf("\t\t\tA: %d\n",top->dato);			
				printf("\t\t\tDato division: %d\n",_dato);
				top->sig=Pop(top->sig);
				top = Pop(top);
				top = Push(top,_dato);
				escribirArchivo(top);
			}else if(_dato==10){
				_dato=(int)atrapar-10;
			}else if(_dato>=50||_dato<=57){
				switch(_dato){
					case 50:
						top=Push(top,2);
					break;
					case 51:
						top=Push(top,3);
					break;
					case 52:
						top=Push(top,4);
					break;
					case 53:
						top=Push(top,5);
					break;
					case 54:
						top=Push(top,6);
					break;
					case 55: 
						top=Push(top,7);
					break;
					case 56:
						top=Push(top,8);
					break;
					case 57:
						top=Push(top,9);
					break;
					default:
						printf("\nOcurrio un error");
					break;
				}
			}else{
				printf("\nOcurrio un error al evaluar ASCII");
				break;
			}
		}
	}
	return top; 
}

void escribirArchivo(Nodo *top){
	FILE *archivo = NULL;
	archivo = fopen("postfijaEvaluacion.txt","at");
	if(archivo == NULL){
		printf("ERROR\n");
	}else{
		fprintf(archivo,"%d ",top->dato);
	}
	top=top->sig;
	fclose(archivo);
}

#endif
