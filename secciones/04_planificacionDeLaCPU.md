# Planificación de la CPU

La planificación es la base para lograr la multiprogramación. En un sistema multiprogramado, generalmente en un determinado instante existirán varios procesos que requieren el procesador al a vez (aquellos que están en estado pronto). Entonces, cuando este esté disponible ¿Cómo elegimos cual de los procesos ejecutará a continuación? el componente del SO que realiza esta tarea es el planificador.

## Tipos de procesos

Los procesos tienden a tener ráfagas de ejecución (CPU-burst) y ráfagas de espera de operaciones de E/S (I/O burst).

### Procesos CPU-bound

Requieren un alto uso del CPU.

### Procesos I/O-bound

Realizan  muchas operaciones de entrada/salida. 

La prioridad de un proceso para obtener un recurso será inversamente proporcional al uso que haga del mismo. Es decir, si un proceso es CPU-bound, entonces su prioridad para hacer uso de la CPU será baja.  

## Despachador

El Despachador es el módulo del SO que da el control de la CPU al proceso seleccionado por el Scheduler (Planificador). Esto implica:

Cambiar el contexto: Salvar registros del procesador en PCB del proceso saliente. Cargar los registros con los datos del PCB del proceso entrante.

Cambiar el bit de modo a usuario.

Saltar a la instrucción adecuada que había quedado el proceso que se asigno a la CPU (registro program counter).

El Planificador que corre en el despachador es el responsable de seleccionar el próximo proceso a ejecutarse. El tiempo que le toma al despachador en detener un proceso e iniciar otro se le llama **latencia de despacho**.

## Esquemas de planificación

Se invoca al planificador cuando:

1. Cuando un proceso cambia de ejecutando a bloqueado.
2. Cuando un proceso finaliza.
3. Cuando un proceso cambia de ejecutando a listo
4. Cuando el proceso cambia de bloqueado a listo.
5. Cuando se crea un nuevo proceso.

Cuando ocurren los dos primeros casos, el planificador es invocado debido a que el proceso en ejecución libera el procesador.

Los últimos tres casos se dan solamente cuando el planificador es **expropiativo**, ya que puede quitar el procesador a un proceso que estaba ejecutando para dárselo a otro.

## Planificadores no expropiadores y expropiadores

Los SO con planificadores no expropiadores (*non-preemptive*) son los que asignan el recurso procesador a un proceso, y hasta que este no lo libere, ya sea porque finaliza su ejecución o se bloquea, no se vuelve a ejecutar el planificador.  

Los SO con planificadores expropiadores (*preemptive*) son los pueden quitarle el procesador a un proceso cuando otro entra en el estado pronto (ya sea porque es nuevo o porque se desbloqueó) o porque se le impone un limitante de tiempo para ejecutar.

## Evaluación de los algoritmos de planificación

### Utilización de CPU (CPU Utilization)

Es el porcentaje de uso útil que tiene un procesador.

### Rendimiento (Throughput)

Número de procesos terminados por unidad de tiempo.

### Tiempo de retorno (Turnaround Time)

Tiempo desde que un proceso se carga hasta que finaliza su ejecución.

### Tiempo de espera (Waiting Time)

Es la suma de los tiempos que un proceso estuvo en la cola de procesos listos.

### Tiempo de respuesta (Response Time)

Tiempo desde la carga hasta que el proceso da su primer respuesta.

## Algoritmos de planificación

### FCFS (First come first served)

Este algoritmo plantea que los procesos sean ejecutados en le orden en que llegan a la cola de procesos listos, por lo tanto el tiempo de espera, en general, es alto. La implementación es sencilla, con una cola FIFO (first in first out). Este algoritmo es no expropiativo.

### SJF (Shortest Job First)

Este algoritmo asocia a cada proceso el largo de su próximo CPU-burst, asignando al procesador cuando queda disponible, el proceso que tenga menor CPU-burst.

Para poder llevar a cabo este algoritmo, es necesario conocer los tiempos de ejecución que por lo general son desconocidos.

Este algoritmo tiene dos posibles variantes:

- expropiador (si aparece un proceso con menor CPU-burst en la lista, se quita el actual y se ejecuta el nuevo).
- No expropiador (aunque aparezca un proceso con menor CPU-burst en la lista, se espera a que el proceso que tiene la CPU, deje de ejecutar)

SJF es optimo – da el menor tiempo de espera promedio para un conjunto de procesos dado, pero solamente podemos estimar la longitud de la siguiente ráfaga, para esto se puede utilizar la longitud de la ráfaga anterior de CPU, realizando un promedio exponencial.

## Basados en prioridad

Este algoritmo se basa en dar prioridades a los procesos, asignando al procesador cuando queda disponible, el proceso que tenga mayor prioridad.  
En general se utiliza un esquema expropiativo, ya que si llega un proceso con mayor prioridad al que esta ejecutando a la cola de listos, este tomará el control del CPU.

Tiene como inconveniente que sufre de posposición indefinida, ya que un proceso de baja prioridad quizá no pueda ejecutar nunca. Para ello se implementan prioridades dinámicas de envejecimiento (aumenta la prioridad según pasa tiempo sin ejecutar).

La prioridad de un proceso para el uso del recurso procesador suele ser inversamente proporcional al uso que el proceso haga del mismo. Por lo tanto un proceso tipo I/O-bound deberá tener, en general, mayor prioridad que uno tipo CPU-bound.

## Round Robin

Este algoritmo designa un intervalo de tiempo para el uso del procesador, por cada proceso (time quantum). Cuando se le asigna la CPU a un proceso, este ejecutará hasta finalizar, o hasta que se le consuma el quantum. Cuando sucede alguna de las cosas mencionadas, el procesador es asignado a otro proceso (en caso que el otro proceso no haya finalizado de ejecutar, volverá a la lista de procesos listos).

La elección del quantum es importante, ya que si es muy pequeño existirían muchos cambios de contexto (el cual lleva tiempo) y si es muy grande el sistema tenderá a ser FCFS.

Por lo general tiene un mayor tiempo de retorno que el SJF, pero mejora el tiempo de respuesta.

## Multilevel Feedback Queue

Este algoritmo se diferencia con el anterior en que los procesos si pueden cambiar de nivel, dependiendo del uso del CPU que tengan.  La cola de más alta prioridad corresponderá a los I/O bound, la mas baja a los CPU-bound.

Un algoritmo así se define por:

- Cantidad de colas.
- Algoritmo de cada cola.
- Criterio para subir de nivel un proceso.
- Criterio para bajar de nivel un proceso.
- Criterio para asignar un proceso nuevo a una de las colas.

## Sistemas multiprocesador

En un sistema simétrico, cualquier procesador ejecuta procesos de usuario. Se puede asignar una cola de listos a cada CPU (afinidad de CPU), lo cual es conveniente par el uso de la cache. Pueden haber desbalances de trabajo entre procesadores, por lo cual se pueden migran procesos de cola para balancear la carga nuevamente.
