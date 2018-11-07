#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	
	char string[100];
	char *id=string;
	char *nombre=string;
	char *email=string;

	FILE*archivo;
	archivo=fopen("planilla.csv", "a");

	int menu;
	int mostrarMenu=0;
	while (mostrarMenu==0){
		printf("INGRESE UNA OPCION: \n\t1-Agregar registro\n\t2-Listar registro\n\t3-Eliminar registro\n\t4-Salir\n");
		scanf("%d", &menu);

		switch(menu){
		case 1: printf("Ingese ID:\n");
			scanf("%s",id);
			fputs(strcat(id, ","),archivo);
			printf("Ingese NOMBRE:\n");
			scanf("%s",nombre);
			fputs(strcat(nombre, ","),archivo);
			printf("Ingese EMAIL:\n");
			scanf("%s",email);
			fputs(strcat(email, "\n"),archivo);
			break;
		case 2: printf("EL CONTENIDO DEL ARCHIVO ES:\n");
			fclose(archivo);
			char mostrar[1000];
			FILE *arch=fopen("planilla.csv","r");
			while(fgets(mostrar, 1000, arch)){
				printf("%s", mostrar);
			}
			archivo=fopen("planilla.csv","a");
			break;
		case 3: printf("ELIMINAR REGISTRO\n");
			FILE *aux=fopen("aux.csv", "w+");
			printf("INGRESE ID PARA ELIMINAR\n");
			scanf("%s", id);
			fclose(archivo);
			char strData[1024];
			FILE *fpt=fopen("planilla.csv","r");
			while (fgets(strData,1024,fpt)){
				char strAux[1024];
				strcpy(strAux, strData);
				char *token=strtok(strAux, ",");
				if (strcmp(token, id)!=0){
					fputs(strData, aux);
				}			
			}
			fclose(archivo);
			fclose(aux);
			remove("planilla.csv");
			rename("aux.csv", "planilla.csv");
			archivo=fopen("planilla.csv", "a");
			break;
		case 4:mostrarMenu=1;
			fclose(archivo);
			break;
		default: break;
		}
		}
	return 0;
	}
