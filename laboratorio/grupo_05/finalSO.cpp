#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <cstdlib>
#include <string.h>



struct datos{
	int  num;
	char id[20];
	char nombre[30];
	char email[30];	
};
typedef struct datos DATO;


char menu();
void insertar(int & );
void mostrar();
void comparayBorra();
void stop();
int contarR(int &  );



int main(){
	DATO e;
	char op;
	int n=0;
	do{
		op = menu();
		
		switch(op){
			case '1':
				system("cls");
				insertar(n);

			break;
			case '2':
				system("cls");
				mostrar();
			break;
			case '3':
				system("cls");
				comparayBorra();
				remove("Registro.csv"); // Eliminamos el archivo
    			system("PAUSE");
   				rename("ArchivoAux.csv","Registro.csv");// Renombramos el archivo
   				
   				
			break;
		}
	}while(op!='4');
	
}
char menu(){
	char op;
	system("cls");
	printf("\n  * * MENU * *");
	printf("\n (1)INSERTAR REGISTRO :");
	printf("\n (2)MOSTRAR REGISTRO :");
	printf("\n (3)BORRAR REGISTRO :");
	printf("\n (4)SALIR");
	printf("\n Opcion --> "); fflush(stdin);
	op = getch();
	return op;
}

void insertar(int &n){
	FILE *fich;
	DATO e;
	
	if((fich = fopen("Registro.csv","ab"))==NULL){
		printf("\nArchivo no existe! ");
	}else{
		contarR(n);	
		e.num=n;						//despues de contar ya sabemos con qe id sera el siguiente..... 
		sprintf(e.id, "%d", n);					//pasa el int a char.....
		printf("\n Ingrese Nombre: "); fflush(stdin);
		gets(e.nombre);

		printf(" Ingrese Email: "); fflush(stdin);
		gets(e.email);
		
			
		fwrite(&e,sizeof(e),1,fich);	// Escribe todo lo que tenemos en la estructura en el fichero . . . .. . 
		fclose(fich);	//Cierra el fichero para que no quede abierto . . . . .
	}
	
}	

void mostrar(){					//Muestras registros.......
	FILE *fich;
	DATO e;

	if((fich = fopen("Registro.csv","rb")) == NULL){
		printf("\n Archivo no existe ");
	}else{
		
		fread(&e,sizeof(e),1,fich);	// Lee los registros del Fichero Posicion por posicion . . . .
		while(! feof(fich)){	// Recorriendo el Fichero . . . .
			printf("\n ____________________________");
			printf("\n Id........: %s",e.id);	
			printf("\n Nombre......: %s",e.nombre);	
			printf("\n Email......: %s",e.email);
			printf("\n ____________________________");
			fread(&e,sizeof(e),1,fich);
		
		}
	}
	fclose(fich);
	getch();

}




void comparayBorra(){										//Compara el id ingresado por el usuario con el del resitro para eliminar.......
	FILE *fich, *fichAux;

	DATO e;
	
	fichAux=fopen("ArchivoAux.csv","wb");
	fich = fopen("Registro.csv","rb");
	if(!fich){
		printf("\n Archivo Vacio ");
	}else{
		char id[20];
		printf("Ingrese id para borrar registro: ");
		fflush(stdin);
		gets(id);
		while(fread(&e, sizeof(e),1, fich)){

            if ((strcmp(e.id,id))!=0){					//Compara dos cadenas si  son iguales retorna 0..........
                fwrite(&e, sizeof(e),1, fichAux);		//Escribe en un nuevo archivo los registros que n oson iguales y asi eliminar el archivo original
            }
        }

        stop();
        fclose(fich);
        fclose(fichAux);

}
}
void stop(){
    printf("Precione una tecla para continuar\n");
	getch();
}

int contarR(int &n){				//Retorna la cantidad de registros que hay .......
	FILE *fich;
	DATO e;

	fich = fopen("Registro.csv","rb");
	if(!fich){
		printf("\n Archivo Vacio ");
	}else{
		
		while(fread(&e,sizeof(e),1,fich)){	// Recorriendo el Fichero ......
									
															
		    }
		    n++;
        	}
        fclose(fich);
        
        return n;
       
}

