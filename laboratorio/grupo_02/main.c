#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Datos{
	char nombre[36];
	char email[51];
};
typedef struct Datos Dato;

/**** FUNCIONES  ***/
int agregarRegistro(Dato *nuevoDato);
int listarRegistros();
int eliminarRegistro( int n );
int ingresarNombre( Dato *nuevoDato );
int ingresarEmail( Dato *nuevoDato );
int ingresarNroReg();
int validarEmail(char email[]);
int buscarIdBorrado(int n);
int getIdLinea(char linea[]);

/**** Globales *****/////
char *nombreArch        = "Registros.csv";
char *nombreElim        = ".Eliminados.txt";
char *nombreTemp        = ".Temporal.txt";
int cantReg             = 0;

int main(){
    Dato nuevoDato;
    int numId = 0;
    extern char *nombreArch;
    char linea[100];
    char c;
    int opcion;
    FILE * archivo;
    archivo = fopen(nombreArch, "r");
    if( archivo != NULL ){
        setbuf(stdin,NULL);
        fscanf(archivo,"%s",linea);
        if( strcmp(linea,"\001") == 0 ){
            remove(nombreArch);
            remove(nombreElim);
            remove(nombreTemp);
        }
        while( feof(archivo) == 0 ){
            fgets(linea,100, archivo); //Obtiene el ultimo registro
            cantReg ++;
        }
        fclose(archivo);
    }


    do{
        puts("\tMENU:" );
        puts("1) AGREGAR REGISTRO");
        puts("2) LISTAR REGISTROS");
        puts("3) ELIMINIAR REGISTRO");
        puts("4) SALIR");
        printf("SELECCIONE UNA OPCION: ");
        fflush(stdin);
        scanf("%i", &opcion);

        switch (opcion){
            case 1 ://Agrega un NuevoReg
                while( (ingresarNombre( &nuevoDato )) ==0 ){
                    puts("El \"Nombre\" ingresado no es valido");
                }
                while( ( ingresarEmail( &nuevoDato )) == 0){
                    puts("El \"Email\" ingresado no es valido");
                }
                if( agregarRegistro( &nuevoDato ) )
                    puts("Nuevo NuevoReg ingresado ok.");
                else
                    puts("Error al intentar ingresar el NuevoReg.");
                break;
            case 2 ://Lista todos los NuevoRegs

                system("clear");
                puts("PULSE \"ENTER\" PARA CONTINUAR");
                listarRegistros();
                setbuf(stdin,NULL);//Limpia el Buffer
                while ( (c = getchar()) != '\n' ){
                    putchar(c);
                }
                system("clear");
                break;
            case 3 :
                if( cantReg == 0 ){
                    system("clear");
                    puts("NO HAY NINGUN REGISTRO");
                    puts("PULSE \"ENTER\" PARA CONTINUAR");
                    setbuf(stdin,NULL);//Limpia el Buffer
                    while ( (c = getchar()) != '\n' ){
                        putchar(c);
                    }
                    system("clear");
                    break;
                }
                numId = ingresarNroReg();
                while( numId < 1 && numId > 1000000 ){
                    puts("El numero de registro no es valido");
                    numId = ingresarNroReg();
                }
                eliminarRegistro(numId);
                break;
      }

    }while( opcion != 4 );

    return 0;
}

//Buscar el numero recibido en el archivo borrados.txt que contiene los id que no se pueden usar mas
int buscarIdBorrado(int n){
    int num;
    char id[11];
    FILE * borrados;
    borrados = fopen(nombreElim, "r");
    if( borrados == NULL)return 0;
    while( feof(borrados) == 0 ){
        setbuf(stdin,NULL);//Limpia el Buffer
        fgets(id, 11, borrados);
        num = atoi(id);
        if( num == n )
            return 1;
    }
    fclose( borrados );
    return 0;
}

//Obtiene el id del arreglo que contiene a la linea completa
int getIdLinea(char linea[]){
    char num[11];
    int id;
    for(int i=0; linea[i]!=','; i++){
        num[i]=linea[i];
        num[i+1]='\0';
    }
    id = atoi(num);
    return id;
}

int agregarRegistro(Dato *nuevoDato){
    extern char *nombreArch;
    extern int cantReg;
    char linea[100];
    int ultimoId;
    if( cantReg == 0 ){//Si el contador de registros vale cero, se borran todos los archivos si existiesen
        remove(nombreArch);
        remove(nombreElim);
        remove(nombreTemp);
    }
    FILE * archivo;
    archivo = fopen(nombreArch, "r");
    if( archivo == NULL ){  //Si el archivo no esta creado, lo crea y asigna el id 1
        archivo = fopen(nombreArch, "a");
        fprintf(archivo, "1,%s,%s\n", nuevoDato->nombre, nuevoDato->email);
        fclose(archivo);
        cantReg ++;
        return 1;
    }
    while( feof(archivo) == 0 ){
        setbuf(stdin,NULL);//Limpia el Buffer
        fgets(linea,100,archivo); //Obtiene el ultimo registro
    }
    fclose( archivo );
    ultimoId = getIdLinea(linea);
    int id = ultimoId + 1;   //Es el id que se asignara al siguiente registro
    while( buscarIdBorrado( id ) ) //Verifica que no este en el archivo borrados.txt
        id++;
    archivo = fopen(nombreArch, "a");
    if( archivo == NULL ) return 0;{
        fprintf(archivo, "%d,%s,%s\n", id, nuevoDato->nombre, nuevoDato->email);
        cantReg ++;
    }
    fclose( archivo );
    return 1;
}

int listarRegistros(){
    extern char *nombreArch;
    char linea[100];
    FILE * archivo;
    archivo = fopen(nombreArch, "r");
    if( archivo == NULL ){
        return 0;
    }
    while( feof(archivo) == 0 ){
        strcpy(linea,"\0");
        setbuf(stdin, NULL);
        fgets(linea,100,archivo); //Obtiene el ultimo registro
        printf("%s", linea);
    }
    fclose( archivo );
    return 1;
}

int eliminarRegistro(int n){
    extern char *nombreArch;
    extern char *nombreTemp;
    extern char *nombreElim;
    extern int cantReg;
    if( cantReg == 0 )return 0; //Si el contador de registros vale cero, se sale si hacer nada
    FILE * archivo;
    FILE * temp;
    FILE * borrados;
    int id;
    char linea[100];
    borrados = fopen(nombreElim, "a"); //Fichero que guarda el id de los registros eliminados
    if( borrados == NULL ) return 0;
    temp = fopen(nombreTemp, "a");     //Fichero temporal para guardar los registros excepto el borrado
    if( temp == NULL ) return 0;
    archivo = fopen(nombreArch, "r"); //Fichero que contiene los registros
    if( archivo == NULL ) return 0;

    while( feof(archivo) == 0 ){
        strcpy(linea, "\0");    // Limpia el arreglo de char linea
        setbuf(stdin,NULL);     //Limpia el Buffer
        fgets(linea,100,archivo);
        if( (id=getIdLinea(linea)) > 0 ){
            if(id != n && cantReg > 0){
                fprintf(temp, linea);
            }else{
                fprintf(borrados,"%d", id);
                cantReg --;
                if( cantReg == 0 ){ // Si la cantidad de registros llega a cero borra todos los archivos
                    remove(nombreArch);
                    remove(nombreElim);
                    remove(nombreTemp);
                }
            }
        }
    }
    remove(nombreArch); // Eliminamos el archivo
    rename(nombreTemp,nombreArch); // Renombramos el archivo
    fclose(borrados);
    fclose( temp );
    fclose( archivo );
    return 1;
}


 int ingresarNombre(Dato *nuevoDato ){
    char nombre[36];
    system("clear");
    printf("INGRESE UN \"NOMBRE\" POR FAVOR: ");
    setbuf(stdin,NULL);//Limpia el Buffer
    scanf(" %[^\n]", nombre);
    if( strlen(nombre) > 2 && strlen(nombre) < 36 ){
        strcpy(nuevoDato->nombre, nombre);
        system("clear");
        return 1;
    }
    else{
        return 0;
    }
}

int ingresarEmail( Dato *nuevoDato ){
    char email[51];
    printf("INGRESE UN \"Email\" POR FAVOR: ");
    setbuf(stdin,NULL);//Limpia el Buffer
    scanf("%s", email);
    if( strlen(email) > 10 && strlen(email) < 51 && validarEmail(email)==1 ){
        strcpy(nuevoDato->email, email);
        system("clear");
        return 1;
    }
    else{
        return 0;
    }
}

int ingresarNroReg(){ //Valida el formato del numero de registro ingresado para eliminar
    char num[11];
    system("clear");
    printf("INGRESE EL NUMERO DEL REGISTRO A ELIMINAR: ");
    setbuf(stdin,NULL);
    scanf(" %s", num);
    system("clear");
    if( strlen(num) > 0 && strlen(num) < 12 ){
        if( (atoi(num)) != 0 )
        return atoi(num);
    }
    else{
        return 0;
    }
}

int validarEmail(char email[]){
   // return 1;
    int arroba,punto,pasa,mayor,c_P,c_S,i;
    int tam=strlen(email);
    char teste='.';
    for (i = 0; i < tam; i++) {
       if(email[i] > 3){
         mayor=1;
       }
       if(email[i] == '@'){
        arroba=1;
       }
       if(arroba == 1 &&  email[i] >= 3){
        c_P=1;
       }
       if(email[i]=='.'){
            punto=1;
        }
        if(punto=1 && email[i] >=2){
            c_S=1;
        }
        if(mayor==1 && arroba == 1 && c_P==1 && c_S ==1){
            pasa=1;
        }
        else{
            pasa=0;
        }
    }
    return pasa;
}




