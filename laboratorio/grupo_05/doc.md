## ejecucion de programas se puede realizar mediante el uso de

./ nombre_del_archivo.
## copilar y crear archivo ejecutable

gcc -o nombredelejecutable nombredelarchivo.c

## ingresa el texto por fuera del documento en la consola
realisando lo que dice

echo "ingrese el texto que ira al final del archivo" >> doc.md

## ingresar el texto en la primera linea del archivo
sed -i '1i Texto al principio de la lista' doc.md

## ingresa el texto en la ultima linea
sed -d '$a Aqui el texto que ira a la ultima linea' doc.md

## agregar registro


## comandos usados para listar son los siquientes
cat doc.md
permite ver el contenido del archivo sin ser modificado

te permite ver los directorios y los archivos del
directorio actual
ls

## borra el archivo con este comando
rm nombredearchivo

## borrar el directorio se puede realizar con el comando
rm -rf nombredirectorio

## Librerias
stdio.h
stdlib.h
conio.h
cstdlib
string.h


#stdio.h
contienens las definiciones de macros las constantesy las delcaracion de las funciones estandar

#gets
se leen los caracteres de entrada estandar y los almacena en una cadena

#fflush
el programa se detiene a la espera que el usuario, tecle una entrada requerida.

#fopen
abre un archivo del nobre asignado en el string

#fclose
cerrar el archivo.
es importante cerrarlo al finalizar las operaciones.

#fwrite
escribe todo lo que tenemos en la esteructura en el archivo

#fread
te permite leer lo que tenes en el archivo 

#FILE
es un tipo de dato especial para el manejo de archivos.

#stdlib.h
Administra la memoria, reliza conversiones de cadenas, genera numeros aleatorios

#conio.h
se utiliza mas que nada para los comandos getch

# getch();
el getch sirve para darle una pausa a un programa en c, esta pausa dura hasta que el usuario preciona una tecla.

#cstdlib
Genera nimero aleatorio, aritmetica de enteros, busqueda de lo mismos, clasificacion y conversion.

#string.h
manejo de strings(seria array de char).

#strcmp
compara dos cadenas de caracteres si da 0 son iguales. 

