
# **Compilador GCC**

## �Que es GCC?

GCC es un compilador integrado del proyecto GNU para C, C++, Objective C y Fortran; es capaz de recibir un programa fuente en cualquiera de estos lenguajes y generar un programa ejecutable binario en el lenguaje de la m�quina donde ha de correr. 
Para verificar que la herramienta est� instalada se utiliza el comando  `gcc --version`
Este comando mostrar� el n�mero de versi�n del compilador de C. Si el sistema no reconoce el comando, es posible que GCC aun no est� instalado.
En el caso de querer compilar un programa en C++, se debe usat `g++` en lugar de `gcc`.

&nbsp;

## Compilar un programa en C

Para compilar un programa en C con GCC se debe ir a la carpeta donde est� guardado el c�digo fuente, para ello se utiliza el comando `cd`.
Una vez en la  carpeta, para compilar el programa `main.c` y obtener el ejecutable `HolaMundo`, se ejecuta el comando `gcc main.c -o HolaMundo`
En el caso de que se produzca algun error y se necesite obtener m�s informaci�n sobre ese error, se utiliza el comando `gcc -Wall -o errorlog file1.c`. Luego, se debe abrir el archivo `errorlog` en la carpeta actual con el comando `cat errorlog`.
Una vez compilado sin errores, el programa podr� ser ejecutado con el comando `./HolaMundo`

&nbsp;

## Codigo 'Hola Mundo' en C

```c
#include <stdio.h>

int main(){
	printf("Hola mundo! \n");
	return 0;
}
```

&nbsp;


## Webgraf�a

+ [Las opciones m�s utilizadas del compilador gcc](http://www.it.uc3m.es/pbasanta/asng/course_notes/ch13.html)
+ [C�mo compilar un programa en C usando el compilador GNU (GCC)](https://es.wikihow.com/compilar-un-programa-en-C-usando-el-compilador-GNU- 
(GCC))
