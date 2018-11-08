#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include <unistd.h> //  sleep
#include <stdlib.h> //  system

#define MAXIMO_VALOR 100
char localPath[128]; 

int agregarRegistro();
int obtenerUltimoId();
void menuPrincipal();
void leerFull();
void setId(char*, int);

int main(int argc, char const *argv[])
{
    printf("Programa ejecutando en: %s\n", argv[0]);
    strcpy(localPath, argv[0]);
    strcat(localPath, "/");
    printf("Programa ejecutando en: %s\n", localPath);
    sleep(2);
    
    printf("Iniciando programa\n");
    FILE *archivo;
    archivo = fopen("./registros.csv", "a");

    if (archivo == NULL)
    {
        printf("Error al abrir el archivo.");
        return 1;
    }
    fclose(archivo);

    menuPrincipal();

    // char opcion = '1';
    // while (opcion == '1') {
    //     printf("Agregar Registro\n");
    //     agregarRegistro();

    //     getchar();
    //     opcion = getchar();
    //     if (opcion == '\n') {
    //         opcion = '1';
    //     }
    // }

    return 0;
}

void menuPrincipal()
{
    char accion;
    int salir = 0;
    while (!salir)
    {
        system("clear");
        printf(
            "\n\n"
            "╔═══════════════════════════════════╗\n"
            "║ Registros                         ║\n"
            "╠═══════════════════════════════════╣\n"
            "║ Controles:                        ║\n"
            "║   1 - Agregar                     ║\n"
            "║   2 - Listar                      ║\n"
            "║   3 - Eliminar                    ║\n"
            "╚═══════════════════════════════════╝\n"
            "\n"
            "═════════════════════════════════════\n"
            "                presione q para salir"
            "\n\n");

        accion = getchar();
        switch (accion)
        {
        case '1':
            printf("Agregar Registro\n");
            agregarRegistro();
            break;
        case '2':
            printf("Listar Registros\n");
            leerFull();
            break;
        case '3':
            printf("Eliminar Registro\n");
            break;
        case 'q':
        case 'Q':
            system("clear");
            printf("Cerrando...\n");
            // sleep(2);
            system("clear");
            return;
            break;
        default:
            break;
        }
    }
}

int agregarRegistro()
{
    char linea[MAXIMO_VALOR], nombreRegistro[MAXIMO_VALOR];
    FILE *archivo;
    archivo = fopen("./registros.csv", "a");
    printf("\nIngrese el nombre del registro: ");
    scanf("%s", nombreRegistro); //e
    
    int id = obtenerUltimoId();
    if (id < 0) {
        return -1;
    }
    char idString[32];
    sprintf(idString, "%d", id);
    strcat(linea, idString);
    strcat(linea, ",");
    strcat(linea, nombreRegistro);

    fprintf(archivo, "%s\n", linea);
    printf("\nSe ha ingresado el registro: %s \n\n", nombreRegistro);
    fclose(archivo);
    // sleep(2);

    return id;
}

int obtenerUltimoId()
{
    char filePath[255];

    printf("%s", localPath);
    
    strcpy(filePath, localPath);
    printf("%s", filePath);


    strcat(filePath, "lastId");
    printf("%s", filePath);
    sleep(2);
    return 0;

    int id = 0;
    FILE *lastId;
    // Si el archivo no existe lo crea
    lastId = fopen(filePath, "r");
    if (lastId == NULL){
        // setId(filePath, id);
        
        lastId = fopen(filePath, "w");
        id++;
        fprintf(lastId, "%d", id);
        fclose(lastId);
    } else {
        fclose(lastId);
    }
    
    lastId = fopen(filePath, "r");
    if (lastId == NULL)
    {
        printf("\nNo se pudo abrir el archivo");
        return -1;
    }
    fscanf(lastId, "%d", &id);
    fclose(lastId);
    
    int idNuevo = id + 1;
    // setId(filePath, idNuevo);
    
    return id;
}

void setId(char* filePath, int id) {
    FILE *lastId;
    lastId = fopen(filePath, "w");
    id++;
    fprintf(lastId, "%d", id);
    fclose(lastId);
}

void leerFull()
{
    int iterador = 0;
	char linea[MAXIMO_VALOR], c = 'x';
	FILE *archivo;
	archivo = fopen("./registros.csv", "r");
    iterador = fscanf(archivo, " %[^\n]", linea);
    while (iterador != EOF)
    {
        printf(" - %s\n", linea);
        iterador = fscanf(archivo, " %[^\n]", linea);
    }
    fclose(archivo);
    sleep(2);
    printf("\n Presione ENTER para volver al menu");
    getchar();
}