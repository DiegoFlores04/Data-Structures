#ifndef _P3_lst_dbl_Quicksort_H
#define _P3_lst_dbl_Quicksort_H
#include "gotoxy.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void integrantes(){
	gotoxy(30,1);printf("INTEGRANTES............1TV5........ESTRUCTURA DE DATOS");
	gotoxy(40,2);printf("Aldrete Aguado Jonathan Cesar");
	gotoxy(40,3);printf("Flores Chavarria Diego");
	gotoxy(40,4);printf("Guadalupe Nohemi Serrano Hernandez");
	gotoxy(40,5);printf("Macedo Vazquez Abraham");
}
typedef struct _Nodo{
	struct _Nodo *siguiente; 
	struct _Nodo *anterior;
	char nombre[20];
	int edad;
	char curp[20];
}Nodo;

Nodo *crear(char _nombre[20],int _edad, char _curp[20]){
	Nodo *nuevo; 
	nuevo = (Nodo *)malloc(sizeof(Nodo));
	nuevo->edad=_edad;
	strcpy(nuevo->curp,_curp);
	strcpy(nuevo->nombre,_nombre);
	nuevo->siguiente = NULL;
	nuevo->anterior = NULL;
	return nuevo;
}

int contarLista(Nodo *lista) {
    int i = 0;
    if(lista == NULL) {
        return 0;
    } else {
        while(lista != NULL) {
            lista=lista->siguiente;
            i++;
        }
    }
    return i;
}

Nodo *insertEnd(Nodo *elemento, char nombre[20], int edad, char curp[20]) {
    Nodo *Nuevo;
    Nodo *auxiliar;
    Nuevo = crear(nombre, edad, curp);
    if(elemento == NULL) {
        return Nuevo;
    } else {
        auxiliar = elemento;
        while(auxiliar->siguiente != NULL) {
            auxiliar=auxiliar->siguiente;
        }
        auxiliar->siguiente = Nuevo;
        Nuevo->anterior = auxiliar;
    }
    return elemento;
}

void mostrarLista(Nodo *elemento){
	int x = 5, y = 8;
    if(elemento==NULL) {
        printf("LA LISTA NO TIENE ELEMENTOS\n");
    } else {
        while(elemento != NULL){
            gotoxy(x,y);printf("\t%s\t%d\t%s", elemento->nombre, elemento->edad, elemento->curp);
            elemento = elemento->siguiente;
            y++;
        }
    }
}
void mostrarListaOrdenada(Nodo *elemento){
	int x = 70, y = 8;
    if(elemento==NULL) {
        printf("LA LISTA NO TIENE ELEMENTOS\n");
    } else {
        while(elemento != NULL){
            gotoxy(x,y);printf("\t%s\t%d\t%s", elemento->nombre, elemento->edad, elemento->curp);
            elemento = elemento->siguiente;
            y++;
        }
    }
}

Nodo *leerArchivo(Nodo *lista) {
    FILE* archivo = NULL;
    char _nombre[20] = "";
    int _edad = 0;
    char _curp[20] = "";
    archivo = fopen("personas.txt","r");
    if(archivo == NULL) {
        printf("El archivo no se pudo abrir.\n");
    } else {
        while(!feof(archivo)) {
            if(feof(archivo))
                fscanf(archivo, "%s\t%d\t%s", &_nombre, &_edad, &_curp);
            else
            	fscanf(archivo, "%s\t%d\t%s", &_nombre, &_edad, &_curp);
            lista = insertEnd(lista, _nombre, _edad, _curp);
        }

    }
    fclose(archivo);
    return lista;
}

void escribir(Nodo *Lista){
    FILE* archivo = NULL;
    archivo = fopen("personasOrdenadas.txt","w"); 
    if(archivo == NULL) {
        printf("ERROR");
    }else {
        if(Lista != NULL) {
            while(Lista != NULL) {
                fprintf(archivo,"%s\t%d\t%s\n",Lista->nombre,Lista->edad,Lista->curp);
            	Lista = Lista->siguiente;
            }
        }
    }
    fclose(archivo);
}

Nodo *BorrarFinal(Nodo *final){
	Nodo *aux = final, *borrar = NULL; 
	while(aux->siguiente->siguiente!=NULL){
		aux = aux->siguiente;
	}
	borrar = aux->siguiente;
	aux->siguiente = NULL;
	free(borrar);
	return final;
}

Nodo *uLista(Nodo *lista1, Nodo *pivote, Nodo *lista2) {
    Nodo *aux1 = lista1;
    Nodo *aux2 = lista2;
    if(lista1 == NULL) {
        aux2->anterior = pivote;
        pivote->siguiente = aux2;
        return pivote;
    } else if(lista2 == NULL) {
        lista1 = insertEnd(lista1, pivote->nombre, pivote->edad, pivote->curp);
        return lista1;
    } else {
        while(aux1->siguiente != NULL) {
            aux1 = aux1->siguiente;
        }
        aux1->siguiente = pivote;
        aux2->anterior = pivote;
        pivote->anterior = aux1;
        pivote->siguiente = aux2;
    }
    return lista1;
}

Nodo *quickSort(Nodo *lista) {
    Nodo *auxLista = lista;
    Nodo *lr = NULL;
    Nodo *gr = NULL;
    Nodo *pT = lista;
    int i = 0;
    if(contarLista(lista) <= 1) {
        return lista;
    }
    for(i=1 ; i<=contarLista(lista) ; i++, auxLista = auxLista->siguiente) {
        if(i == 1)
            continue;
        if(auxLista->curp[0] == pT->curp[0]) {
            if(auxLista->curp[1] < pT->curp[1]) {
                lr = insertEnd(lr, auxLista->nombre, auxLista->edad, auxLista->curp);
            }else {
                gr = insertEnd(gr, auxLista->nombre, auxLista->edad, auxLista->curp);
            }
        }else if(auxLista->curp[0] < pT->curp[0]) {
            lr = insertEnd(lr, auxLista->nombre, auxLista->edad, auxLista->curp);
        } else {
            gr = insertEnd(gr, auxLista->nombre, auxLista->edad, auxLista->curp);
        }
    }
    return uLista(quickSort(lr), pT, quickSort(gr));
}

#endif
