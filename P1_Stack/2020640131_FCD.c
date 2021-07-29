#include "2020640131_FCD.h"


int main(){	
	int i=0,op=0;
	Nodo *cima=NULL;
	char *path = "postfijaEvaluacion.txt";
	char menu;

	do{	
		system("cls");
		system("color 07");
		gotoxy(50,8);
		printf("BIENVENIDO");
		gotoxy(30,10);
		printf("1.- Leer y realizar evaluaciones del archivo \"postfija\" \n");
		gotoxy(30,11);
		printf("2.- Mostrar pila despues de las evaluaciones \n");
		gotoxy(30,12);
		gotoxy(30,13);
		printf("Selecciones una opcion: ");
		scanf("%d",&op);
		switch(op){
			case 1:
				system("color 0C");
				system("cls");
				cima=read(cima);
			break;
			case 2:
				system("color 02");
				system("cls");
				show(cima);
			break;
			default:
				system("cls");
				gotoxy(52,5);
				printf("->ERROR<-\n");
				printf("\n\n\n");
				return 1;
			break;
		}
		gotoxy(24,28);
		printf("Volver al menu principal? (Y/N): "); scanf("%s",&menu);
	}while(menu == 'Y' || menu == 'y');
	return 0;
}
	

