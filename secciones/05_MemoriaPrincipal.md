# Memoria Principal

La memoria es un área de almacenamiento común a los procesadores y dispositivos, donde se almacenan programas, datos, etc.

El sistema deberá administrar el lugar libre y ocupado, y será el encargado de las siguientes tareas:

- Mantener que partes de la memoria están siendo usadas, y por quien.
- Decidir cuales procesos serán cargados a memoria cuando exista espacio de memoria disponible, pero no suficiente para todos los procesos que deseamos.
- Asignar y quitar espacio de memoria según sea necesario.

## Direcciones relativas y Absolutas

La mayoría de los SO permiten que un proceso de usuario resida en cualquier parte de la memoria principal. Es así que, aunque el espacio de direcciones comience en el 0000, La primera dirección de usuario no tiene porque ser 0000. Esta posibilidad afecta a las direcciones que el programa de usuario puede utilizar.

Las direcciones pueden representarse de diferentes formas. Las direcciones de un programa fuente son normalmente simbólicas.

Al compilar, el compilador se encarga de reasignar estas direcciones simbólicas a direcciones relativas (por ejemplo: 14 bytes a partir del comienzo del programa). El cargador, se encargará, a su vez, de reasignar direcciones relativas a direcciones absolutas (por ejemplo, 74F1).

## Asociación de direcciones

### Tiempo de Compilación

Si sabemos en el momento de la compilación donde va a residir el proceso en memoria, podemos generar código absoluto (con direcciones absolutas). Ahora, si en algún momento deseamos cambiar su ubicación, deberemos recompilar el código.

### Tiempo de Carga

Si es que no conocemos en tiempo de compilación donde va a residir el proceso en memoria, el compilador deberá generar código reubicable (con direcciones relativas), y en este caso se retarda la reasignación a direcciones absolutas hasta el momento de la carga. Si en algún momento deseamos cambiar su ubicación, deberemos solamente volver a cargarlo.  

### Tiempo de Ejecución

Si el proceso puede variar su ubicación en memoria durante su ejecución, entonces es necesario retardar su asignación a direcciones absolutas hasta el momento de ejecución. Para que este esquema pueda funcionar, se requiere soporte de hardware.

## Espacio de dirección lógico y físico

Una dirección generada por la CPU se denomina normalmente dirección lógica, mientras que una dirección vista por la unidad de memoria se denomina dirección física.

Los métodos de reasignación en tiempo de compilación y de carga generan direcciones físicas y lógicas idénticas; no es el caso para el tiempo de ejecución. En este caso decimos que la dirección lógica es una dirección virtual.

Al conjunto de todas las direcciones lógicas de un programa se le denomina espacio de direcciones lógicas; mientras que al conjunto de todas las direcciones físicas de un programa se le denomina espacio de direcciones físicas.

La correspondencia entre direcciones virtuales y físicas en tiempo de ejecución es establecida por un dispositivo de hardware que se denomina **unidad de gestión de memoria** (*MMU Memory Managment Unit*).

El registro de reubicación suma a todas las direcciones generadas por un proceso de usuario en el momento de enviarlas a memoria, para así generar las direcciones físicas correspondientes. Por ejemplo, si el registro de reubicación se encuentra en la dirección 14000, un acceso a la ubicación 346 se convertirá en la ubicación 14000+346 = 14346.

Entonces, el usuario solo verá direcciones entre 0 y max (las direcciones lógicas), mientras que las direcciones físicas estarán entre 0+R y R+max.

## Estrategia de asignación

¿Cómo elige el SO en que porción de memoria colocaremos un proceso? Existen varias estrategias:

### First fit

Asigna el primer “agujero” de memoria libre que satisface la necesidad.

### Best fit

Asigna el mejor “agujero” de memoria libre que exista en la memoria principal.

### Worst fit

Asigna en el “agujero” más grande que exista en la memoria principal.

Estudios de simulación han mostrado que first-fit y best-fit lograron mejores rendimientos en tiempo de asignación y utilización de la memoria que la estrategia worst-fit.

## Intercambio (Swapping)

Un proceso debe estar en memoria principal para ser ejecutado. Sin embargo, los procesos pueden ser intercambiados temporalmente, sacándolos de memoria y almacenándolos en el disco, y volviéndolos a llevar a memoria para continuar su ejecución.

Al mecanismo de llevar un proceso desde memoria principal a disco se le denomina **swap-out**. Al inverso se le denomina **swapin**. El mayor tiempo consumido en el swaping es el tiempo de transferencia.

## Protección de memoria

Protección de memoria implementada asociando un bit de protección con cada frame.
Los bits se pueden utilizar para indicar distintas situaciones: lectura-escritura, sólo-lectura, etc. y bits asociados a la tabla de páginas, indicando si es una entrada válida o no.