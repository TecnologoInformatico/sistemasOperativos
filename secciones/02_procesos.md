# Procesos

Administración de Procesos Para comenzar debemos saber que es un proceso. Un proceso es un programa en memoria + CPU + acceso a dispositivos + otros recursos. Notemos que un proceso necesita de ciertos recursos (como CPU, memoria, archivos, dispositivos de E/S, etc.) para realizar su tarea.  

En otras palabras un proceso es un programa en ejecución, por lo que se puede notar que es una entidad activa, mientras que un programa una entidad pasiva.  

Sabiendo entonces que es un proceso, podemos decir entonces que el sistema operativo es el encargado de su administración. Es el encargado de proveer servicios para que cada proceso pueda realizar su tarea. Entre los servicios se encuentran:

- Crear y destruir procesos
- Suspender y reanudar procesos
- Proveer mecanismos para la sincronización y comunicación entre procesos
- Proveer mecanismos para prevenir dead-locks o lograr salir de ellos

## PCB

Para el sistema operativo el proceso es representado por el bloque descriptor de proceso *PCB* (Process Control Block), Donde se guarda toda la información relevante del proceso, tal como:

- identificador
- Estado del proceso
- Contador de programa
- Registros de la CPU
- Información de planificación de la CPU
- Información de gestión de memoria
- Información de contabilidad
- Estado de E/S

Entre otros datos.

## Procesos en memoria

Los procesos en memoria contienen varias secciones:

- Text (Código) Instrucciones del proceso.
- Data (Datos) Variables globales del proceso.
- Heap (Memoria dinámica) Memoria dinámica que genera el proceso.
- Stack (Pila) Utilizado para preservar el estado en la invocación anidada de procedimientos y funciones.

## Estado de los procesos

El estado de un proceso es definido por la actividad corriente en que se encuentra. Los estados de un proceso son:

- Nuevo (new): Cuando el proceso es creado.
- Ejecutando (running): El proceso tiene asignado un procesador y está ejecutando sus instrucciones.
- Bloqueado (waiting): El proceso está esperando por un evento (que se complete un pedido de E/S o una señal).
- Listo (ready): El proceso está listo para ejecutar, solo necesita del recurso procesador.
- Finalizado (terminated): El proceso finalizó su ejecución

### Transiciones entre los estados

#### Nuevo –> Listo

Al crearse un proceso pasa inmediatamente al estado listo.

#### Listo –> Ejecutando

En el estado de listo, el proceso solo espera para que se le asigne un procesador para ejecutar. Al liberarse un procesador el planificador (scheduler) selecciona el próximo proceso, según algún criterio definido, a ejecutar.

#### Ejecutando –> Listo

Ante una interrupción que se genere, el proceso puede perder el recurso procesador y pasar al estado de listo. El planificador será el encargado de seleccionar el próximo proceso a ejecutar.

#### Ejecutando –> Bloqueado

A medida que el proceso ejecuta instrucciones realiza pedidos en distintos componentes (ej.: genera un pedido de E/S). El proceso es puesto en una cola de espera hasta que se complete su pedido. De esta forma, se logra utilizar en forma más eficiente el procesador.

#### Bloqueado –> Listo

Una vez que ocurre el evento que el proceso estaba esperando en la cola de espera, el proceso es puesto nuevamente en la cola de procesos listos.

#### Ejecutando -> Terminado

Cuando el proceso ejecuta su última instrucción pasa al estado terminado. El sistema libera las estructuras que representan al proceso.

## Colas de procesos

Los procesos, según su estado, deberán esperar por determinados eventos. Puede suceder, que más de un proceso esté esperando por el mismo evento, es por eso que se deben organizar en diferentes colas o listas.

### Lista de procesos del sistema (job queue)

Esta será una lista especial, porque los procesos que están en ella no esperan por nada en particular, sino que es la lista de todos los procesos del sistema. Al crearse un nuevo proceso se agrega el PCB a esta lista. Cuando el proceso termina su ejecución es borrado.

### Cola de procesos listos (ready queue)

Esta cola se compondrá de los procesos que estén en estado listo. La estructura de esta cola dependerá de la estrategia de planificación utilizada.

### Cola de espera de dispositivos (device queue)

Los procesos que esperan por un dispositivo de E/S particular son agrupados en una lista específica al dispositivo. Cada dispositivo de E/S tendrá su cola de espera, por lo que existirán varias device queue.

## Creación de procesos

Los procesos de un sistema son creados a partir de otro proceso. Normalmente al creador se le denomina padre y al nuevo proceso hijo, lo cual genera una jerarquía de procesos en el sistema.

Una vez creado el nuevo proceso tendrán un hilo de ejecución propio, y el sistema generará un nuevo PCB para el proceso creado.

En UNIX podemos crear un nuevo proceso a través de la llamada al sistema fork.  
La invocación a esta función le retorna al padre el número de process id del hijo recién creado y al hijo el valor 0. El hijo comienza su ejecución en el retorno del fork.  

```c
int main() {
    pid_t pid;
    pid = fork();
    if (pid < 0){
        /* error */
        fprintf(stderr, "Falló el Fork");
    }
    if (pid == 0) {
        /* proceso hijo */
        fprintf("soy el hijo!");
    }
    else {
        /* proceso padre */
        fprintf("soy el padre!");
    }  
}
```

También se brinda métodos, por ejemplo [exec](http://man7.org/linux/man-pages/man3/exec.3.html), para después de utilizar fork reemplazar el espacio de memoria del proceso con un programa nuevo.

## Cambio de contexto (context switch)

A la tarea de cambiar un proceso por otro en el procesador se le denomina cambio de contexto cambio de contexto. Cuando se realiza un cambio de contexto el sistema debe preservar el estado del viejo proceso y cargar el del nuevo, esta tarea implica:

- Salvar el estado del proceso (registros, información de punteros de memoria) que está ejecutando en su PCB.
- Cambiar el estado del proceso que estaba ejecutando al que corresponda (Listo, bloqueado o terminado).
- Cargar el estado del proceso asignado a la CPU a partir de su PCB.
- Cambiar el estado del proceso nuevo a ejecutando.

El tiempo de cambio de contexto es sobrecarga, no se realiza trabajo útil mientras tanto, y que tanto demore depende del soporte de hardware.

## Comunicación entre procesos

Procesos que se ejecutan concurrentemente pueden ser procesos independientes o cooperativos. Un proceso es cooperativo si puede afectar o verse afectado por los restantes procesos que se ejecuten en el sistema, y es independiente si no. Así, cualquier proceso que comparta datos con otro será cooperativo.

### cooperación de procesos

#### Compartir información

Dado que varios usuarios pueden estar interesados en la misma información, se debe proveer un acceso concurrente a ella.

#### Acelerar cálculos

Si deseamos que una determinada operación se ejecute rápidamente, debemos dividirla en subtareas ejecutándose cada una de ellas en paralelo. Esto consigue solo si hay múltiples CPU o varios canales de E/S.