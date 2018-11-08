# Laboratorio 01, SISTEMAS OPERATIVOS

## GRUPO: Balbinai, Bauza, Collazo.



## Parte 01

>### Forma de utilizar gcc:

>>En consola: gcc nombre_del_archivo.extension

>### Funcionalidades del gcc:

>>```gcc hola.c
``` :
compila el programa en C hola.c, genera un archivo ejecutable a.out.

>>```gcc -o hola hola.c
``` :
compila el programa en C hola.c, genera un archivo ejecutable hola.

>>```gcc -c hola.c
``` :
no genera el ejecutable, sino el código objeto, en el archivo hola.o. 

>>Si no se indica un nombre para el archivo objeto, usa el nombre del archivo en C y le cambia la extensión por .o.

>>```gcc -c -o objeto.o hola.c
``` :
genera el código objeto indicando el nombre de archivo. 

## Parte 02

>###Funciones implementadas:

>>**fopen("planilla.csv", "a" o "r" o "w+")**: Abre y crea archivos en disco, con la bandera **"a"** abre el archivo para escritura al final del contenido y si no existe lo crea, con la bandera **"r"** abre el archivo en modo lectura (antes debe existir), y con la bandera **"w+"** abre el archivo en modo lectura y escritura, se crea si no existe o se sobrescribe si no existe.

>>**fputs("cadena", "puntero al archivo")**: Escribe una cadena de caracteres en un fichero.

>>**strcat("cadena", "constante char")**: Concatena una cadena a otra.

>>**fclose("planilla.csv")**: Cierra el archivo, si esta abierto.

>>**fgets("cadena a ser leída", "tope de la cadena a ser leída", "puntero al archivo")**: Lee cadena hasta un salto de linea, hasta que termine el archivo, o hasta que llegue al tope.

>>**strcpy("cadena a ser copiada", "cadena resultante")**: Copia el contenido de una cadena en otra.

>>**strcmp("cadena a ser comparada", "cadena a ser comparada")**: Compara dos cadenas.

>>**remove("planilla.csv")**: Elimina el archivo.

>>**rename("nombre actual", "nuevo nombre")**: Renombra el archivo.

>###Bibliotecas

>>**stdio.h**: Para poder utilizar las funciones: fclose, fopen, rename, remove, fputs y fgets.

>>**string.h**: Para poder utilizar las funciones: strcat, strcpy y strcmp.

>>**stdlib.h**: Librería estándar de C.
