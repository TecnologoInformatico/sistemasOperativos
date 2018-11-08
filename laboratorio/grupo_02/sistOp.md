# GCC #
___

GCC es un compilador portable, se ejecuta en la mayoría de las plataformas disponibles hoy, y puede producir salidas para muchos tipos de procesadores.
Es un compilador que viene por defecto en todos (o casi) todos los linux.

GCC no es solo un compilador nativo —también puede compilar cruzado cualquier programa, produciendo ficheros ejecutables para un sistema diferente desde el que GCC está siendo usado. Esto permite compilar software para sistemas embebidos que no son capaces de
ejecutar un compilador. GCC está escrito en C con un fuerte enfoque hacia la portabilidad, y puede compilarse a sí mismo, así puede ser adaptado a nuevos sistemas fácilmente.

GCC tiene un diseño modular, permitiendo que el soporte para nuevos lenguajes y arquitecturas sea añadido. Añadir un nuevo front-end a GCC habilita el uso de este lenguaje en cualquier arquitectura y proporciona que estén disponibles facilidades (tales como librerías) en tiempo de ejecución. De manera similar, si se añade soporte para una nueva arquitectura éste se vuelve disponible para todos los lenguajes.

Finalmente, y de manera más importante, GCC es software libre, distribuido bajo la GNU General Public License (GNU GPL). Esto significa que se tiene la libertad para usar y modificar GCC, como con todo el software de GNU. Si se necesita soporte para un nuevo tipo de CPU, un nuevo lenguaje, o una nueva funcionalidad es posible añadirla uno mismo o contratar a alguien para mejorar GCC de manera personalizada.

___

El clásico programa de ejemplo para el lenguaje C es 'Hola Mundo'.

```c
#include <stdio.h> 
int main() { 
  	 printf ("¡Hola mundo!.\n"); 
  	 return 0; 
	}
```

Se asume que el código fuente está almacenado en un fichero llamado ‘HolaMundo.c’. Para compilar el fichero ‘HolaMundo.c’ con gcc, se puede usar el siguiente comando:

`
$ gcc HolaMundo.c -o hola
`


Esto compila el código fuente de ‘HolaMundo.c’ a código máquina y lo almacena en el fichero ejecutable ‘hola’. El fichero de salida para el código máquina se especifica usando la opción 
‘-o’. Esta opción normalmente es el último argumento en la línea de comandos. Si se omite, la salida es escrita a un fichero por defecto llamado ‘a.out’.
Si ya existe un fichero con el mismo nombre que el fichero ejecutable en el directorio actual, entonces se sobrescribirá.

Luego, para ejecutar el programa, se escribe la ruta del ejecutable así:

`
$ ./hola
¡Hola mundo!
`

Esto carga el fichero ejecutable en memoria y hace que la CPU empiece a ejecutar las instrucciones que contiene. La ruta ./ se refiere al directorio actual, así ./hola carga y ejecuta el fichero ejecutable ‘HolaMundo’ localizado en el directorio actual.


La opción ‘-Wall’ activa todos los avisos más comunes (por lo tanto, se recomienda usar siempre esta opción). Hay muchas otras opciones de avisos, pero ‘-Wall’, (se podría decir) es la más importante, GCC no producirá avisos a menos que estén activados. Los avisos del compilador son una ayuda esencial detectando problemas al programar en C y C++.

Si el programa es valido, el compilador no produce avisos con la opción ‘-Wall’, ya que no tiene ningún error, si el código fuente no produce avisos ni errores, se dice que compila limpiamente.

El comando para ejecutar seria así:
	
`
$ gcc -Wall HolaMundo.c -o hola
`

____

## Librerias ##

Las librerías que utilizamos para trabajar fueron: `stdlib.h` que contiene muchas utilidades para los programadores, tales como la gestión de memoria dinámica, la ordenación y búsqueda en arrays o el control de procesos.

La biblioteca `string.h`, que contiene un conjunto de funciones para manipular cadenas: copiar, cambiar caracteres, comparar cadenas, etc.

Y por ultimo, la librería `stdio.h`, que contiene las funciones de entrada/salida, es decir, aquellas que transportan datos entre el programa, y la entrada y salida estándar (teclado y pantalla respectivamente). La entrada/salida no forma parte del lenguaje C, si no que se proporciona a través de esta librería.

___

## Funciones ##

Algunas de las funciones que utilizamos fueron: 

**fgets** función está diseñada para leer cadenas de caracteres. Leerá hasta n-1 caracteres o hasta que lea un cambio de línea '\n', o un final de archivo EOF. En este último caso, el carácter de cambio de línea '\n' también es leído.

`char *fgets(char *buffer, int tamaño, FILE *archivo);`

El primer parámetro buffer sería un puntero a un espacio de memoria del tipo char (podríamos usar un arreglo de char). El segundo parámetro es tamaño que es el limite en cantidad de caracteres a leer para la función fgets. Y por ultimo el puntero del archivo, forma en que fgets sabrá a que archivo debe leer.


**fscanf** funciona igual que scanf en cuanto a parámetros, pero la entrada se toma de un fichero en lugar del teclado.

`int fscanf(FILE *fichero, const char *formato, argumento, ...);`


**fprintf** La función fprintf funciona igual que printf en cuanto a parámetros, pero la salida se dirige a un archivo en lugar de a la pantalla.


`int fprintf(FILE *archivo, const char *formato, argumento, ...);`


**fopen** esta función sirve para abrir y crear ficheros en disco.


`FILE * fopen (const char *filename, const char *opentype);`

Los parámetros de entrada de fopen son: filename: una cadena que contiene un nombre de fichero válido. opentype: especifica el tipo de fichero que se abrirá o se creará.

Una lista de parámetros opentype para la función fopen son:

"r" : abrir un archivo para lectura, el fichero debe existir.

"w" : abrir un archivo para escritura, se crea si no existe o se sobreescribe si existe.

"a" : abrir un archivo para escritura al final del contenido, si no existe se crea.

"r+" : abrir un archivo para lectura y escritura, el fichero debe existir.

"w+" : crear un archivo para lectura y escritura, se crea si no existe o se sobreescribe si existe.

"r+b ó rb+" : Abre un archivo en modo binario para actualización (lectura y escritura).

"rb" : Abre un archivo en modo binario para lectura.


**fclose** Esta función sirve para poder cerrar un fichero que se ha abierto.

`fclose (FILE *stream);`

Un valor de retorno cero indica que el fichero ha sido correctamente cerrado, si ha habido algún error, el valor de retorno es la constante EOF.
Un detalle a tener en cuenta, es que el lenguaje C no tiene dentro de si una estructura para el manejo de excepciones o de errores, por eso es necesario comprobar que el archivo fue abierto con éxito `if (fp == NULL)`. Si fopen pudo abrir el archivo con éxito devuelve la referencia al archivo `(FILE *)`, de lo contrario devuelve `NULL` y en este caso se deberá revisar la dirección del archivo o los permisos del mismo.


**atoi**  convierte una cadena en un entero. Devuelve el entero correspondiente, y 0 si la cadena no es un entero.

`atoi(char *cad)`


**remove** funcion para eliminar o remover ficheros. Te regresa un 0 si se pudo eliminar, y un valor diferente a 0 si no se pudo.

`remove(const char *nombre);`


**rename** funcion para renombrar ficheros

`rename( const char *nombre_viejo, const char *nombre_nuevo );`













