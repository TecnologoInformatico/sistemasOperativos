#include <stdio.h>  
#define ARCHIVO "Registro.csv"
#define ARCHIVO_AUX "Registro_aux.csv"
#define POSICION "Posicion.txt"
       
//Funciones
void menu();
void guardar();
void mostrar();
void borrar();
void pausa();


int main (){

  menu();
  return 0;
}

void menu(){
    int opcion;
    do{
    	system("clear");
        printf("[1]Guardar Registro\n");
        printf("[2]Mostrar Registro\n");
        printf("[3]Borrar registro\n");
        printf("[4]Salir\n");
        printf("Elija una opcion: ");
        scanf("%i",&opcion);
        system("clear");
        switch(opcion){
            case 1:
                guardar();
                break;
            case 2:
                mostrar();
                break;
            case 3:
                borrar();
                break;
            case 4:
                printf("Cerrando el programa!");
                break;
            default:
                printf("Opcion NO existente intente otra vez\n");
                pausa();
        }
            
    }while(opcion!=4);
}

void guardar(){

	FILE *contador;
	contador=fopen(POSICION,"r");
	int cod = 1;

	if(contador == NULL){
		contador=fopen(POSICION,"w");
		fprintf(contador,"%d",cod);
		fclose(contador);
		
	}
	else{
		fscanf(contador,"%d",&cod);
		fclose(contador);
		cod++;
		contador=fopen(POSICION,"w");
		fprintf(contador,"%d",cod);
		fclose(contador);
	}	
	FILE* file;
	char Nombre[30];
	char Mail[30];
	printf("Nombre:\n");
	scanf("%s",Nombre);
	printf("Mail:\n");
	scanf("%s",Mail);
	file=fopen(ARCHIVO,"a");
   	if(file == NULL){
		printf("Error archivo no encontrado\n");
		pausa();
    	}
	if(cod == 1){
		fprintf(file,"%d,%s,%s",cod,Nombre,Mail);
		printf("Registro guardado!\n");
		fclose(file);
		pausa();
	}
	else{
		fprintf(file,"\n%d,%s,%s",cod,Nombre,Mail);
		printf("Registro guardado!\n");
		fclose(file);
		pausa();
	}

}

void borrar(){
	system("clear");
	FILE *file, *fileAux;
	fileAux=fopen(ARCHIVO_AUX,"w");
	file=fopen(ARCHIVO,"r");
	if(!file){
		printf("No se encotro el archivo\n");
		pausa();
	}
	else{
		char cod [10];
		printf("Codigo del registro a eliminar:\n");
		scanf("%s",cod);
		char cadena[100];
		while(!feof(file)){	
			int  pos=0;
			fgets(cadena,50,file);
			while(cod[pos] == cadena[pos])
				pos++;
    		if(cadena[pos] != ',')
    			fprintf(fileAux,"%s",cadena);	
	}
	fclose(file);
	fclose(fileAux);
	remove("Registro.csv");
	rename("Registro_aux.csv","Registro.csv");
	printf("Registro eliminado!\n");
	pausa();
   	}
		
}  

void mostrar(){
	FILE *file;
	file=fopen(ARCHIVO,"r");
	if(file != NULL){
		char cadena[100];      
		printf("Codigo,Nombre,Mail\n");
		while (!feof(file)){
 			fgets(cadena,2,file);
 			printf("%s",cadena);
		}
	}	
	fclose(file);
    	printf("\n");
	pausa();
}

void pausa(){
printf("Precione una tecla para continuar\n");
getchar();
getchar();
}

        
