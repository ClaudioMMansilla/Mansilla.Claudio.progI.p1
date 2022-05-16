#include <stdio.h>
#include <stdlib.h>

#define TAMN 3

typedef struct{

	int id;
	char procesador[10];
	char marca[10];
	float precio;
	int isEmpty;

}Notebook;

int aplicarDescuento(float precio, float* pResultado);
int ordenarNoteMarcaPrecio(Notebook vec[], int tam);
int listarNotebooks(Notebook notes[], int tam);

int main() {

	setbuf(stdout, NULL);

	float precio = 100.0;

	float resultado = 0;


	aplicarDescuento(precio, &resultado);
	printf("el resultado es: %.2f", resultado);



	Notebook nuevaNote[TAMN] = {
			{1, "i5", "Intel", 200.0, 0},
			{1, "i7", "Intel", 250.0, 0},
			{1, "Razen", "AMD", 230.0, 0}
	};

	listarNotebooks(nuevaNote, TAMN);
	ordenarNoteMarcaPrecio(nuevaNote, TAMN);
	listarNotebooks(nuevaNote, TAMN);


	return EXIT_SUCCESS;
}

//1. Crear una función llamada aplicarDescuento que reciba como parámetro el precio de un producto
//y devuelva el valor del producto con un descuento del 5%. Realizar la llamada desde el main.
int aplicarDescuento(float precio, float* pResultado){

	int control = 0;

	float bufferResultado;

	if(pResultado != NULL){
		bufferResultado = precio - precio *5/100;
		*pResultado = bufferResultado;
		control = 1;

		if(control){
			*pResultado = bufferResultado;
		}
	}

	else
	{
		printf("La operacion no pudo realizarse");
	}

	return control;
}


//3. Dada la estructura Notebook(id, procesador, marca, precio)
//generar una función que permita ordenar un array de dicha estructura por marca.
//Ante igualdad de marca deberá ordenarse por precio. Hardcodear datos y mostrarlos desde el main.


int ordenarNoteMarcaPrecio(Notebook vec[], int tam){
    int control = 0;
    Notebook vecAux;

    if( vec != NULL && tam > 0)
    {
        for(int i=0; i < tam - 1; i++)
        {
            for(int j= i+1; j < tam; j++)
            {
                if( (strcmp(vec[i].marca,vec[j].marca) > 0 || vec[i].precio < vec[j].precio))
                {
                	vecAux = vec[i];
                    vec[i] = vec[j];
                    vec[j] = vecAux;
                }
            }
        }

        control = 1;
    }
    return control;
}


void mostrarNotebook(Notebook note){


	printf("%d            %10s       %10s       %.2f \n",
			note.id,
			note.procesador,
			note.marca,
			note.precio
		);
}

int listarNotebooks(Notebook notes[], int tam){

	int control = 0;
	int flagEmpty = 1;

    if(notes != NULL && tam > 0)
    {
    	system("cls");
    	printf(" ** Listado de notebooks registradas ** \n");
    	printf("--------------------------------------------------\n");
    	printf("id         Procesador       Marca        Precio \n");
    	printf("--------------------------------------------------\n");

        for(int i=0; i < tam; i++)
        {
            if( !notes[i].isEmpty)
            {
                mostrarNotebook(notes[i]);
                flagEmpty = 0;
            }
        }

        if(flagEmpty)
        {
            printf(" No hay articulos registrados en el sistema\n");
        }

    	control = 1;
    }
    return control;
}
