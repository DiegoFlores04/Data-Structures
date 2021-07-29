#include "P3_lst_dbl_Quicksort.h"

int main(){
	system("color 20");
	Nodo *listaPrincipal = NULL;
	Nodo *listaOrdenada = NULL;
	integrantes();
	listaPrincipal = leerArchivo(listaPrincipal);
	gotoxy(15,7);printf("LISTA SIN ORDENAR");
	mostrarLista(listaPrincipal);
	gotoxy(80,7);printf("LISTA ORDENADA");
	listaOrdenada = quickSort(listaPrincipal);
	mostrarListaOrdenada(listaOrdenada);
	escribir(listaOrdenada);
	gotoxy(20,26);printf("La lista ordenada se ha guardado en el archivo de nombre personasOrdenadas.txt\n");
	int i = 0;
	for(i = 0 ; i<contarLista(listaPrincipal) ; i++){
		listaPrincipal = BorrarFinal(listaPrincipal);
	}
	return 0;
}
