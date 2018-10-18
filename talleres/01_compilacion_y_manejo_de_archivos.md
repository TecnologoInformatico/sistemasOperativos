# Laboratorio 01

## Desarrollo de los laboratorios

Las tareas de laboratorio se desarrollarán en equipos y se documentará lo realizado e investigado.

Para llevar a cabo esto se utilizará el lenguaje [markdown](https://github.com/adam-p/markdown-here/wiki/Markdown-Cheatsheet).

Al finalizar la tarea se realizará la entrega mediante la plataforma eva de tanto la documentación como el código.

## Compilación y manejo de archivos

El primer taller busca acercar al desarrollo de aplicaciones en C que interactúen con las APIs que brinda el sistema operativo.

## Parte 1 - Compilación

Investigue la herramienta de compilación gcc y documente la forma de utilizarla, así como las funcionalidades que encuentre útil destacar.

Cree un programa "hello world!" y hágalo compilar a modo de prueba.

## Parte 2 - Manejo de archivos

Cuando un programa finaliza la información almacenada en memoria se pierde, por lo tanto es útil utilizar el manejo de archivos para conservar lo importante.

Los archivos suelen utilizarse para el manejo de configuraciones e incluso para la implementación de bases de datos.

### Programa de registros

Se desea realizar un programa que realice una serie de registros. Para esto se contará con las siguientes funciones:

- Agregar registro
- Listar registros
- Eliminar registro

El programa manejará los registros mediante el formato *CSV*, y los registros serán:

- id (identificador definido por el sistema)
- nombre (nombre del integrante del grupo)
- email (email del integrante)

Ej:

    "12","Peteco Garcia","peteco@hotmail.com"
    "13","Pedro Dalton","elpedro@adinet.com.uy"
    "14","Bob Dylan","knockin@heavensdoor.com"

Se busca que al iniciar el programa se genere el archivo `registros.csv` en caso de no existir y que se brinden las opciones antes dispuestas.

### Librería POSIX de C

Para llevar a cabo el programa de registros se recomienda utilizar la librería estándar, dentro de la cabecera `<stdio.h>` encontrará los métodos necesarios para conseguir el objetivo. Documente la información que le resulte útil para poder reutilizarla luego de ser necesario.