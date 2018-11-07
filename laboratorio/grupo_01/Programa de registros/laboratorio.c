#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LARGO_NOMBRE	21
#define LARGO_CORREO	41

const char separador = ';';
char * nombreArchivoRegistros = "reg.csv";
char * nombreArchivoRegAux = "reg-aux.csv";
char * nombreArchivoID = "proxID.txt";

void agregar();
void eliminar();
void listar();
void pausa();
int archivoExiste(char *);
void intToCharArray(int, char [7]);

int main(){
	int opcion = 0;
	
	do{
		system("clear");
		printf("--- Registros ---\n");
		printf("1- Agregar\n");
		printf("2- Eliminar\n");
		printf("3- Listar\n");
		printf("0- SALIR\n");
		scanf("%d", &opcion);
		fflush(stdin);
		
		switch (opcion){
			case 1:
				agregar();
				break;
			case 2:
				eliminar();
				break;
			case 3:
				listar();
				break;
			case 0:
				return 0;
				break;
			default:
				break;
		}
	}while(opcion != 0);
	
	return 0;
}


//-------------------------------------------------------------------------
void agregar(){
	FILE *ficheroRegistros = fopen(nombreArchivoRegistros, "a");	// abre o crea el archivo para escribir al final
	FILE * ficheroID;
	int id = 100;	// id por defecto
	int i;	// contador
	char c;	// para leer y escribir
	char idAsignado[7];
	char nombre[LARGO_NOMBRE];	// almacenara el nombre
	char correo[LARGO_CORREO];	// almacenara el apellido
	
	if (archivoExiste(nombreArchivoID) == 1){				// si el archivo que guarda el proximo ID existe
		ficheroID = fopen(nombreArchivoID, "r+");			// se abre para lectura y escritura (ya existe)
		if (fread(&id, sizeof(int), 1, ficheroID) != 1){	// se carga en ID (que es un int), el unico elemento del archivo, si retorna 1, es correcto
			printf("Error al leer proximo id\n");
			return;
		}
	}else{
		ficheroID = fopen(nombreArchivoID, "w");			// crea el archivo para escribir en el
		if (fwrite(&id, sizeof(int), 1, ficheroID) != 1){	// almacena el id, que es int, que es uno solo, en el archivo, si no devuelve 1 hubo un error
			printf("Error al escribir primer id\n");
			return;
		}
	}
	rewind(ficheroID); 										// rebobina el puntero de archivo para una nueva escritura
	
	intToCharArray(id, idAsignado); 
	
	// ingreso de nombre y correo
	printf("Su numero ID autoasignado es: %s\n", idAsignado);
	printf("Ingrese su nombre (%d caracteres): ", LARGO_NOMBRE-1);
	scanf("%[^\n]", nombre);
	printf("Ingrese su correo (%d caracteres): ", LARGO_CORREO-1);
	scanf("%[^\n]", correo);
	
	// guarda los datos en el archivo
	fputs(idAsignado, ficheroRegistros);
	fputc(separador, ficheroRegistros);
	fputs(nombre, ficheroRegistros);
	fputc(separador, ficheroRegistros);
	fputs(correo, ficheroRegistros);
	fputc('\n', ficheroRegistros);
	
	id++;
	if (fwrite(&id, sizeof(int), 1, ficheroID) != 1){	// guarda el id actualizado
		printf("Error al actualizar el id\n");
		return;
	}
	
	fclose(ficheroRegistros);
	fclose(ficheroID); 
	
}

//-------------------------------------------------------------------------
void eliminar(){
	/*
	Abre dos veces el archivo de registros, una para buscar el id a borrar y la otra para transcribir la info a un archivo auxiliar
	luego de transcribir los registros (exeptuando el que hay que eliminar) se borra el archivo original y se renombra el auxiliar para que quede como original
	*/
	FILE *ficheroRegistros, *fRegAux, *faux;	// para transcribir, para buscar el id, para escribir en un archivo auxiliar
	char idEliminar[7];	// id del registro que se debe borrar
	char idBuscar[7];	// id obtenidos durante la busqueda
	char  c1, c2;	// para transcribir de 'ficheroRegistros', para leer de 'fRegAux'
	int i;	// contador
	
	if (archivoExiste(nombreArchivoRegistros)  == 0){	// verifica que el archivo exista
		printf("No se encontro el archivo de registros...\n");
		return;
	}else{
		ficheroRegistros = fopen(nombreArchivoRegistros, "r");	// abre o crea el archivo para escribir al final
		fRegAux = fopen(nombreArchivoRegistros, "r");
	}
	
	printf("Ingrese el ID del registro a eliminar: ");
	scanf("%s", idEliminar);
	
	// aca empieza lo entreverado
	
	faux = fopen(nombreArchivoRegAux, "a");	// crea un archivo auxiliar en blanco
	
	while ((c1=fgetc(ficheroRegistros)) != EOF){	// recorre el archivo original hasta el final
		for (i = 0; (c2=fgetc(fRegAux)) != ';'; i++){	// lee el id del registro
			idBuscar[i] = c2;
		}
		idBuscar[i] = '\0';
		
		while ((c2=fgetc(fRegAux)) != '\n');	// luego de obtener el id del registro se adelanta hasta el proximo (luego del \n)
		
		if (strcmp(idBuscar, idEliminar) != 0){	// si el id encontrado no es el que se quiere eliminar
			do {	// transcribe el char obtenido al archivo auxiliar
				fputc(c1, faux);
			}while ((c1 = fgetc(ficheroRegistros)) != '\n');
			fputc('\n', faux);	// añade un \n para preparar para el siguiente registro
		}else{	// si el id encontrado es el que no hay que transcribir
			while ((c1=fgetc(ficheroRegistros)) != '\n');	// c1 se adelanta hasta la proxima linea
		}
	}
	
	// el archivo original esta igual que antes, pero en el auxiliar ya no esta el registro a eliminar
	
	fclose(ficheroRegistros);	// se cierran los archivos
	fclose(fRegAux);
	fclose(faux);
	
	remove(nombreArchivoRegistros);	// borra el archivo original
	rename(nombreArchivoRegAux, nombreArchivoRegistros); 	// renombra al auxiliar para que quede como el nuevo original
	pausa();
}

//-------------------------------------------------------------------------
void listar(){
	FILE *fichero;
	char  c;
	
	if (archivoExiste(nombreArchivoRegistros)  == 0){	// verifica que el archivo exista
		printf("No se encontro el archivo de registros...\n");
		pausa();
		return;
	}
	
	fichero = fopen(nombreArchivoRegistros, "r");	// abre el archivo (sabiendo que existe)
	
	printf("-------- Registros --------\n");
	while ((c = fgetc(fichero)) != EOF){	// rrecorre el archivo mostrando su contenido
		printf("%c", c);
	}
	printf("---------------------------\n");
	
	fclose(fichero);	// cierra el archivo
	pausa();
}

//-------------------------------------------------------------------------
void pausa(){
	printf("Pulse ENTER para continuar...");
	getchar();
	getchar();
}

//-------------------------------------------------------------------------
int archivoExiste(char * nombreArchivo){
	// abre para lectura el archivo con el nombre indicado
	FILE * fichero = fopen(nombreArchivo, "r");
	
	// fopen devuelve NULL si no lo pudo abrir
	if (fichero == NULL){
		return 0;
	}else{
		fclose(fichero); // cierra el archivo abierto (que existe)
		return 1;
	}
}

//-------------------------------------------------------------------------
void intToCharArray(int numero, char arrResultado[7]){
	/* Recibe un int 'numero' y un array de 7 lugares donde devolvera el resultado */
	// rango de un int: -32768 a 32767
	char arrAux[7];	// dado el rango del int, se necesitan 6 char para reperesentarlo + '\0'
	int i, j;	// contadores
		
	if (numero < 0){	// si el numero es negativo
		arrResultado[0] = '-';	// agrega el - primero
		j = 1;	// los digitos se escribiran desde la posicion 1
	}else{
		j = 0;	// los digitos se escribiran desde la posicion 0
	}
	
	for (i = 0; i < 7; i++){	// rellena el array con el numero al revez
		arrAux[i] = (numero % 10) + 48;	// guarda el ultimo digito (suma 48 porque es el codigo de char)
		numero /= 10;	// divide entre 10 para eliminar el digito ya guardado
		if (numero == 0){
			break; // si se llega a 0, ya se procesaron todos los digitos
		}
	}
	
	for (; i >= 0; i--, j++){
		arrResultado[j] = arrAux[i];	// rellena el array resultado al derecho con el auxiliar que esta al revez
	}
	arrResultado[j] = '\0';
}



