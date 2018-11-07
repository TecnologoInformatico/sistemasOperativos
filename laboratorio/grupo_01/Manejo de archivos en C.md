
# **Manejo de archivos en C**
----------------------------------------------------------------------------------
&nbsp;

## Operaciones con archivos

### Funcion *fopen*

#### Descripción:

La función de la biblioteca C, abre el nombre del archivo al que se apunta, mediante el nombre del archivo usando el modo dado.

#### Prototipo:

`FILE *fopen(const char * nombre_archivo, const char * modo)`

#### Parámetros:

+ nombre_archivo : esta es la cadena C que contiene el nombre del archivo que se abrirá.
+ modo : esta es la cadena C que contiene un modo de acceso a archivos. 

#### Modos de acceso:

+ r:  Apertura para sólo lectura; coloca el puntero a fichero al principio del fichero.
+ r+ : Apertura para lectura y escritura; coloca el puntero al fichero al principio del fichero.
+ w : Apertura para sólo escritura; coloca el puntero al fichero al principio del fichero y trunca el fichero a longitud cero. Si el fichero no existe se intenta crear.
+ w+ : Apertura para lectura y escritura; coloca el puntero al fichero al principio del fichero y trunca el fichero a longitud cero. Si el fichero no existe se intenta crear.
+ a :  Apertura para sólo escritura; coloca el puntero del fichero al final del mismo. Si el fichero no existe, se intenta crear. En este modo, fseek() solamente afecta a la posición de lectura; las lecturas siempre son pospuestas.
+ a+ : Apertura para lectura y escritura; coloca el puntero del fichero al final del mismo. Si el fichero no existe, se intenta crear. En este modo, fseek() no tiene efecto, las escrituras siempre son pospuestas.
+ x :  Creación y apertura para sólo escritura; coloca el puntero del fichero al principio del mismo. Si el fichero ya existe, la llamada a fopen() fallará devolviendo FALSE y generando un error de nivel E_WARNING. Si el fichero no existe se intenta crear. Esto es equivalente a especificar las banderas O_EXCL|O_CREAT para la llamada al sistema de open(2) subyacente.
+ x+ :  Creación y apertura para lectura y escritura; de otro modo tiene el mismo comportamiento que 'x'.
+ c : Abrir el fichero para sólo escritura. Si el fichero no existe, se crea. Si existe no es truncado (a diferencia de 'w'), ni la llamada a esta función falla (como en el caso con 'x'). El puntero al fichero se posiciona en el principio del fichero. Esto puede ser útil si se desea obtener un bloqueo asistido (véase flock()) antes de intentar modificar el fichero, ya que al usar 'w' se podría truncar el fichero antes de haber obtenido el bloqueo (si se desea truncar el fichero, se puede usar ftruncate() después de solicitar el bloqueo).
+ c+ : Abrir el fichero para lectura y escritura; de otro modo tiene el mismo comportamiento que 'c'.
+ e : Establecer la bandera 'close-on-exec' en el descriptor de fichero abierto. Disponible solamente en PHP compilado en sistemas que se ajustan a POSIX.1-2008.

&nbsp;

### Funcion *fclose*

#### Descripción:

La función de la biblioteca C cierra la secuencia. Todos los buffers están enrojecidos.

#### Prototipo:
A continuación se muestra la declaración de la función fclose ().
`int fclose(FILE *stream)`

#### Parámetros:
stream : este es el puntero a un objeto FILE que especifica el stream que se cerrará.

#### Valor de retorno: 
Este método devuelve cero si la secuencia se cierra correctamente. En caso de fallo, se devuelve EOF.


### Función *rewind*:

#### Descripción:

Literalmente significa "rebobinar", sitúa el cursor de lectura/escritura al principio del archivo.

#### Prototipo:

``void rewind(FILE *fichero);``

#### Parámetros:

+ fichero : Puntero al archivo.

&nbsp;

### Función *remove*:

#### Descripción:

Elimina el archivo con el nombre pasado como parametro. Es recomendable que el archivo haya sido cerrado antes de eliminarlo utilizando esta funcion.Su valor de retoreno es 0 solo si el archivo pudo ser eliminado.

#### Prototipo:

``int remove(char * nombre_archivo);``

#### Parámetros:

+ nombre_archivo : esta es la cadena C que contiene el nombre del archivo que se eliminará.


### Función *rename*:

#### Descripción:

Cambia el nombre de un archivo. Recibe una cadena de caracteres con el nombre actual del archivo y otra con el nuevo nombre. Es recomendable que el archivo haya sido cerrado antes de renombrarlo. Retorna cero si la operación fue realizada con éxito. 

#### Prototipo:

``int rename(char * nombre_actual, char * nombre_nuevo);``

#### Parámetros:

+ nombre_actual : esta es la cadena C que contiene el nombre actual del archivo que se modificará.
+ nombre_nuevo : cadena C que contiene el nuevo nombre para el archivo.

&nbsp;
-----------------------------------------------------------------------------------
&nbsp;

## Operaciones de lectura

Un archivo generalmente debe verse como un string (una cadena de caracteres) que esta guardado en el disco duro. Para trabajar con los archivos existen diferentes formas y diferentes funciones.

&nbsp;

### Funcion *fgetc*:

#### Descripción:

Esta función lee un caracter a la vez del archivo que esta siendo señalado con el puntero *archivo. En caso de que la lectura sea exitosa devuelve el caracter leído y en caso de que no lo sea o de encontrar el final del archivo devuelve EOF. Esta función se usa generalmente para recorrer archivos de texto.

#### Prototipo:

``char fgetc(FILE *archivo);``

#### Parámetros:

+ fichero : Puntero al archivo.

&nbsp;

### Funcion *fread*:

#### Descripción:

Esta función lee un bloque de una "stream" de datos. Efectúa la lectura de un arreglo de elementos "count", cada uno de los cuales tiene un tamaño definido por "size". Luego los guarda en el bloque de memoria especificado por "ptr". El indicador de posición de la cadena de caracteres avanza hasta leer la totalidad de bytes. Si esto es exitoso la cantidad de bytes leídos es (size*count).

#### Prototipo:

``size_t fread ( void * puntero, size_t tamano, size_t cantidad, FILE * archivo );``

#### Parámetros:

+ puntero : Puntero a un bloque de memoria con un tamaño mínimo de (size*tamano) bytes, a partir del cual se escribira lo leido desde el archivo.
+ tamano : Tamaño en bytes de cada elemento (de los que se leeran).
+ cantidad : Número de elementos, los cuales tienen un tamaño "tamano".
+ archivo: Puntero a objetos FILE, que especifica  el archivo de entrada.


&nbsp;
----------------------------------------------------------------------------------
&nbsp;


## Operaciones de escritura:

Así como se puede leer datos desde un fichero, también se pueden crear y escribir ficheros con la información que se desea almacenar, Para trabajar con los archivos existen diferentes formas y diferentes funciones. Las mas utilizadas son:

&nbsp;

### Función *fputc*:

#### Descripción:

Escribe un carácter a la vez del archivo que esta siendo señalado con el puntero *archivo. El valor de retorno es el carácter escrito, si la operación fue completada con éxito, en caso contrario será EOF.

#### Prototipo:

``int fputc(int carácter, FILE *archivo);``

#### Parámetros:

+ archivo : Puntero al archivo.

&nbsp;

### Función *fwrite*:

#### Descripción:

Esta función está pensada para trabajar con registros de longitud constante. Es capaz de escribir hacia un fichero uno o varios registros de la misma longitud almacenados a partir de una dirección de memoria determinada (por ejemplo, un array de enteros) . El valor de retorno es la cantidad de registros escritos. Los parámetros son: un puntero a la zona de memoria de donde se obtendrán los datos a escribir, el tamaño en bytes de cada registro, el número de registros a escribir y un puntero a la estructura FILE del fichero al que se hará la escritura.

#### Prototipo:

``size_t fwrite(void *puntero, size_t tamano, size_t cantidad, FILE *archivo);``

#### Parámetros:

+ puntero : Puntero a un bloque de memoria con un tamaño mínimo de (size*tamano) bytes, a partir del cual se leeran los datos a escribir en el archivo.
+ tamano : Tamaño en bytes de cada elemento (de los que se escribirán).
+ cantidad : Número de elementos, los cuales tienen un tamaño "tamano".
+ archivo: Puntero a objetos FILE, que especifica el archivo de salida..


&nbsp;
----------------------------------------------------------------------------------
&nbsp;


## Implementación de las operaciones con archivos en el programa de registros

Para el software desarrollado fue necesario utilizar las funciones anteriormente mencionadas ya que la información ingresada por el usuario debía tener persistencia luego de cerrar el programa.
Para lograrlo, se debió crear o abrir el archivo donde se guardan los datos, para seguidamente escribir en el los datos del nuevo registro. Estas operaciones también fueron necesarias al momento de eliminar un registro, ya que el programa transcribe el contenido del archivo a un archivo auxiliar, luego de lo cual es necesario eliminar el  original y renombrar el auxiliar para que pueda ser accedido posteriormente con el nombre del original.
Dado que cada registro debe poseer un identificador, se almacena en otro archivo un contador de tipo *int* el cual se incrementa al crear un nuevo registro.


&nbsp;
----------------------------------------------------------------------------------
&nbsp;


## Webgrafía
+ [WikiLibros - Programación en C/Manejo de archivos](https://es.wikibooks.org/wiki/Programaci%C3%B3n_en_C/Manejo_de_archivos "WikiLibros - Programación en C/Manejo de archivos")
+ [PDF sobre manejo de archivos](http://informatica.utem.cl/~mcast/PROGRAMACION/PROGRAV/2007/ARCHIVOS/archivos-1.pdf "PDF sobre manejo de archivos")
+ [Librerias ANSI C - Función rename ANSI C](http://c.conclase.net/librerias/?ansifun=rename "Librerias ANSI C - Función rename ANSI C")
