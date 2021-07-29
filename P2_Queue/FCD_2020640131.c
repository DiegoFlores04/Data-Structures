#include "FCD_2020640131.h"
#include <windows.h>
#include <time.h>
#include <conio.h>
int main(){
	Nodo *salaEspera = NULL;
	Nodo *FilaCobros = NULL;
	Nodo *FilaPagos = NULL;
	Nodo *aux = NULL;
	system("color 9F");
	gotoxy(50,1);printf("--> NOTA <--");
	gotoxy(20,2);printf("El programa utiliza la funcion Sleep() para simular la asignacion de los lugares\n");
	gotoxy(20,3);printf("presione enter para borrar esta nota y ver la continuacion del programa, saludos!\n");
	gotoxy(20,5);system("pause");
	salaEspera = leerArchivo(salaEspera); 
	srand(time(NULL));
	int turno;
	while(salaEspera!=NULL){
		turno=rand()%2;
		if(turno==0){
			system("cls");
			gotoxy(45,2); printf("BANCO DE IZTAPALAPA");
			gotoxy(45,5); printf("Asignando Turno...");
			FilaPagos = AgregarNodo(FilaPagos,salaEspera->saldo,salaEspera->NoCuenta,salaEspera->nombre);
			aux=salaEspera;
			free(aux);
			salaEspera = salaEspera->siguiente;
		}else if(turno==1){
			system("cls");
			gotoxy(45,2); printf("BANCO DE IZTAPALAPA");
			gotoxy(45,5); printf("Asignando Turno...");
			FilaCobros = AgregarNodo(FilaCobros,salaEspera->saldo,salaEspera->NoCuenta,salaEspera->nombre);	
			aux=salaEspera;
			free(aux);
			salaEspera = salaEspera->siguiente;
		}
		Sleep(2000);
	}
	ArchivoCobros(FilaCobros);
	ArchivoPagos(FilaPagos);
	system("cls");
	gotoxy(45,5); printf("BANCO DE IZTAPALAPA");
	gotoxy(20,7);printf("fila de cobros");
	MostrarCobros(FilaCobros);
	gotoxy(75,7);printf("fila de pagos");
	MostrarPagos(FilaPagos);
	printf("\n\n\n\n\n\n\n\n\n\t\t\tElaborado por Alumno: Flores Chavarria Diego\n\n\n\n\n\n");
	return 0;
}
