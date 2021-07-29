#ifndef _FILA_H_
#define _FILA_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gotoxy_FCD.h"

typedef struct _Nodo{
    int saldo;
    char NoCuenta[7];
    char nombre[8]; 
    struct _Nodo *siguiente;
} Nodo;

Nodo *CrearNodito(int _saldo,char *_NoCuenta,char *_nombre){
    Nodo *nuevo;
    nuevo= (Nodo *)malloc(sizeof(Nodo));
    nuevo->saldo = _saldo;
    strcpy(nuevo->NoCuenta,_NoCuenta);
    strcpy(nuevo->nombre,_nombre);
    nuevo->siguiente= NULL;
    return nuevo;
}



Nodo *AgregarNodo(Nodo *frente, int _saldo, char _noCuenta[7], char _nombre[8]){
    Nodo *nuevo, *aux;
    nuevo=CrearNodito(_saldo,_noCuenta,_nombre);
    if(frente==NULL){
        return nuevo;
    }else{
        aux=frente;
        while(aux->siguiente!=NULL){
            aux=aux->siguiente;
        }
        aux->siguiente=nuevo;
        return frente;
    }
}

void MostrarPagos(Nodo *frente){
	int x=65,y=9;
    if(frente==NULL){
        printf("No hay nada en la fila \n");
    }else{
        while(frente!=NULL){
            gotoxy(x,y);printf("|\t%s\t%s\t%d\t|", frente->nombre, frente->NoCuenta, frente->saldo);
            frente=frente->siguiente;
           	y++;
        }
    }
}

void MostrarCobros(Nodo *frente){
	int x=10,y=9;
    if(frente==NULL){
        printf("No hay nada en la fila \n");
    }else{
        while(frente!=NULL){
            gotoxy(x,y);printf("|\t%s\t%s\t%d\t|", frente->nombre, frente->NoCuenta, frente->saldo);
            putchar('\n');
            frente=frente->siguiente;
            y++;
        }
    }
}

Nodo *BorrarNodo(Nodo *frente){
    Nodo *aux;
    aux=frente;
    if(frente==NULL){
        printf("No hay nada");
        return frente;
    }else{
        frente=frente->siguiente;
        free(aux);
        return frente;
    }
}
void ArchivoCobros(Nodo *cobro){
	FILE *Archivo = NULL;
	int i = 0;
	Archivo = fopen("Cobros.txt","at");
	if(Archivo == NULL){
		fprintf(Archivo,"ERROR al abrir el archivo");
	}else{
		while(cobro!=NULL){
			fprintf(Archivo,"%s\t%s\t%d\n",cobro->nombre,cobro->NoCuenta,cobro->saldo);	
			cobro = cobro->siguiente;
		}
	}
	fclose(Archivo);
}

void ArchivoPagos(Nodo *pagos){
	FILE *Archivo = NULL;
	int i = 0;
	Archivo = fopen("Pagos.txt","at");
	if(Archivo == NULL){
		fprintf(Archivo,"ERROR al abrir el archivo");
	}else{
		while(pagos!=NULL){
			fprintf(Archivo,"%s\t%s\t%d\n",pagos->nombre,pagos->NoCuenta,pagos->saldo);	
			pagos = pagos->siguiente;
		}
	}
	fclose(Archivo);
}

Nodo *leerArchivo(Nodo *frente){
	FILE *archivo = NULL; 
	int _Saldo = 0;
	char _Nombre [8] = {'\0'}; 
	char _NoCuenta [7] = {'\0'};
	archivo = fopen("personas.txt","r");
	if(archivo == NULL){
		printf("El archivo no existe\n");
		return 1;
	}else{
		while(!feof(archivo)){
			fflush(stdin);
			fscanf(archivo,"%s",&_Nombre);fflush(stdin);
			fscanf(archivo,"%s",&_NoCuenta);fflush(stdin);
			fscanf(archivo,"%d",&_Saldo);
			frente = AgregarNodo(frente,_Saldo,_NoCuenta,_Nombre);
		}
		frente = frente->siguiente;
		fclose(archivo);
	}
	return frente; 
}

#endif
