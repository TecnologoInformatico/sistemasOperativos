# Sistemas de archivos

El sistema de archivos es el modo en el que el sistema operativo organiza los archivos almacenados en el disco.

Entre sus tareas se encuentran:

- Utilizar de forma eficiente el espacio disponible en el disco.
- Catalogar los archivos para obtenerlos de forma rápida y segura.
- Proveer métodos para realizar operaciones básicas.
  - crear
  - renombrar
  - eliminar
  - copiar
  - mover
- Brindar una estructura para que el equipo pueda cargar el sistema.

## FAT

Divide el espacio del disco en unidades llamadas sectores de 512bytes, y los maneja en grupos de sectores denominados cluster.

Para acceder a los datos primero se busca el cluster y luego se accede al sector mediante su indice.

Cada cluster sólo puede almacenar un archivo, por lo que mientras más grande es el tamaño de los cluster más será el espacio desperdiciado.

El tamaño de los cluster se establece dividiendo el tamaño del disco entre la cantidad máxima de cluster que se pueden crear.

## FAT16, FAT32

La diferencia principal de FAT16 con FAT32 está en la cantidad de cluster que pueden enumerar.

FAT16 utiliza un número binario de 16 bits, mientras que FAT32 de 32bits.

FAT16 por lo tanto puede tener un máximo de (2^16 - 1) 65535 clusters.
Teniendo en cuenta que se puede tener un máximo de 65535 clusters,
que cada cluster puede albergar hasta 128 sectores y que cada sector es de 512 bytes.

Significa que el máximo tamaño que puede tener FAT16 es = 65535 x 128 x 512 = 4 GB

## NTFS
