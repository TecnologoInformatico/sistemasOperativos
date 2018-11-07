# Laboratorio 1

## Parte 01:

### GCC
GCC es un compilador integrado del proyecto GNU para C, C++, Objective C y Fortran; es capaz de recibir un programa fuente en cualquiera de estos lenguajes y generar un programa ejecutable binario en el lenguaje de la máquina donde ha de correr.  
La sigla GCC significa "*GNU Compiler Collection*".

Para generar un ejecutable utilizando gcc primero necesitas abrir una terminal y pararte en el directorio donde se encuentra tu código fuente el cual debe ser extensión .c (*Ejemplo.c*) y luego
utilizar el comando **gcc -o NomEjec NomArchi.c** donde **NomEjec** sera el nombre que quieras que tenga el archivo ejecutable y **NomArchio.c** es le nombre del archivo donde esta el codigo.
>Nota
La opcion -o utilizada es la que permite nombrar al ejecutable de la forma que se desee.

Si el copilador no detecta errores en el codigo y se ejecuta de forma correcta se generara un ejecutable el cual podras iniciar de esta forma **./NomEjec**.

## Parte 02:
Librerias utilizadas:
 * [stdio.h](http://www.cplusplus.com/reference/cstdio/)
 * [stdlib.h](http://www.cplusplus.com/reference/cstdlib/)

De la librería stdio.h se utilizaron las funciones **fopen(),fprintf(),fscanf(),fclose(),feof().**
De la librería stdlib.h se utilizo la función **system(clear)**.

El programa cuenta con 5 funciones todas de tipo void las cuales son:

 - **Menu**.
 - **Guardar**.
 - **Mostrar**.
 - **Borrar**.
 - **Pausa**.
 - 
## **_Menu_**
Es la única función invocada desde main contienen un **switch** para poder seleccionar la acción que se quiera realizar las cuales pueden ser guardar registro ,borrar registro ,mostrar registro y salir del programa .

## **_Guardar_**
Se pedía guardar un registro compuesto de tres partes un id que se auto incrementa un nombre y un mail.
Para realizar el id que se auto incrementa se creo un archivo separado que almacena un entero el cual se lee ,se incrementa y se sobrescribe con cada registro que se ingresa , el nombre y mail son dados por el usuario.
Lo primero es crear un puntero de tipo **FILE** y apuntar a un archivo con **puntero = fopen(NomArchi"r");** la **"r"** significa que se abrirá en forma de lectura ,para comprobar que el archivo existe comparamos el puntero si este es igual a NULL significa que el archivo no existe en ese directorio por lo que debemos crearlo con  **puntero = fopen(NomArchi"w");**
 por ultimo cerramos el archivo con **fclose(puntero)**.
> la **"w"** significa que se abrirá en forma de escritura si el archivo no existe se creara y si existe se borrara su contenido.

> 
Ahora que el archivo existe es momento  de ingresarle el registro nuevamente abrimos **puntero = fopen(NomArchi"a");** 
>la **"a"** significa que se abrirá en forma de escritura y se posicionara al final del archivo sin modificar otra informacion que pueda contener este.

e ingresamos con **fprintf(puntero,"tipo dato",variable);** el registro ya fue guardado solo falta cerrar el archivo **fclose(puntero)**.

## **_Mostrar_**
La función mostrar es sencilla abre el archivo en modo de lectura y utiliza  un **while (!feof(file))** que contiene un **fgets()** el cual lee una linea del archivo y lo almacena en una variable de tipo char [] y luego se imprime con un **printf()** esto se repetirá mientras se cumpla la condición del while que es que no se haya llegado al final del archivo.

## **_Borrar_**
La función borrar funciona utilizando un archivo auxiliar en el cual se copian todos los registros menos el que se quiere borrar se abre el original en modo de lectura y el auxiliar en modo de escritura luego se copian todos los registros menos el que se quiere eliminar utilizando un discriminaste una vez terminado el proceso de copiado se cierran ambos archivos se elimina el original y se renombrar al auxiliar con el nombre del original.

## **_Pausa_**
La función pausa solo contiene un **printf** que despliega el mensaje *"presione una tecla para continuar"* y un **getchar()** para dar tiempo al usuario de ver la pantalla.
