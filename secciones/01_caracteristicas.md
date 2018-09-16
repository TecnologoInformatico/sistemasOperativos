# Características del Sistema operativo

Un sistema operativo es un programa que actúa como intermediario entre el usuario y el hardware de la computadora. Se podría decir que el kernel es el programa en ejecución en todo momento en la computadora.

## Servicios brindados

Los servicios que brinda un sistema operativo puede variar de uno a otro, pero se pueden determinar determinadas clases comunes:

- Interfaz de usuario (GUI, CLI)
- Ejecución de programas
- Operaciones de E/S
- Manipulación del sistema de archivos
- Comunicaciones
- Detección de errores
- Asignación de recursos
- Auditoría
- Protección y seguridad

### Interfaz de usuario

Existen dos métodos fundamentales para interactuar con el sistema operativo.

#### Intérprete de comandos *CLI command-line interface*

Incluido en el kernel o cómo un programa especial.
Permite a los usuarios dar instrucciones a los programas e interactuar con el sistema operativo desde una línea de texto simple.

En sistemas que disponen de varios intérpretes estos son conocidos como shells.

Ejemplos son:

- En Windows: cmd, Power Shell
- En Linux: Bourne shell, C shell, Bourne Again shell, Korn shell, etc.

#### Interfaz gráfica de usuario *GUI graphical user interface*

Interfaz amigable para la interacción con el sistema operativo y los programas de usuario donde se utilizan imágenes, iconos y objetos gráficos en general para representar la información y acciones disponibles.

Suele estar caracterizada por la metáfora del escritorio, y se combina con el uso del ratón, teclado y monitor.

### Ejecución de programas

El SO deberá ser capaz de cargar un programa a memoria y ejecutarlo. El programa deberá poder finalizar, de forma normal o anormal.

### Operaciones de E/S

Deberá proveer un mecanismo de acceso ya que por eficiencia y protección los usuarios no accederán directamente al dispositivo. De este modo se brinda un acceso común a los distintos dispositivos brindando servicios tales como:

- Montaje y desmontaje de dispositivos
- Una interfaz entre el cliente y el sistema operativo para los device drivers.
- Técnicas de cache, buffering y spooling.
- Device drivers específicos

### Manipulación del sistema de archivos

Es necesario tener acceso al sistema de archivos y poder, como mínimo, leer, escribir, borrar y crear.

Proporciona una vista uniforme de todas las formas de almacenamiento, implementando el concepto de archivo como una colección de bytes. provee métodos para:

- Abrir, cerrar y crear archivos
- Leer y escribir archivos

### Comunicaciones

Los procesos deben poder comunicarse, ya sea que estén en el mismo computador o el diferentes, por lo que el S.O. debe brindarles mecanismos para poder llevar a cabo esta tarea.

### Detección de errores

El sistema deberá tomar decisiones adecuadas ante eventuales errores que ocurran, como fallo de un dispositivo de memoria, fallo en un programa, etc.

### Asignación de recursos

Debe administrar los distintos recursos disponibles en el equipo (CPU, RAM, dispositivos de entrada y salida), entre los procesos que intentan hacer uso de ellos para que se saque el mayor provecho de lo disponible.

### Auditoría

En los sistemas multi usuario es fundamental mantener un control sobre quién realiza cambios en el sistema y en que momento.

### Protección y seguridad

Se establecen mecanismos por los que se controla el acceso de los procesos a los recursos.

En un sistema multi usuario donde se ejecutan procesos de forma concurrente se deben tomar medidas que garanticen la ausencia de interferencia entre ellos. Estas medidas deben incorporar la posibilidad de definir reglas de acceso, entre otras cosas.

## Llamadas al sistema

Proporcionan una interfaz con la que poder invocar los servicios que el sistema operativo ofrece. Generalmente escritas en C y C++, y en determinadas tareas de bajo nivel en lenguaje ensamblador.

Pueden ser agrupadas de forma muy general en cinco categorías:

- Control de procesos
- manipulación de archivos
- manipulación de información de mantenimiento
- comunicaciones y protección

### API

Normalmente los desarrolladores de aplicaciones utilizan una API (application programing interface). Estas interfaces son más sencillas de utilizar, robustas y muchas veces se cuentan con interfaces portables que pueden ser utilizadas en varios sistemas operativos, como por ejemplo POSIX.

- Win32 API
- POSIX API
- Java API

### Interrupciones

Cuando una aplicación o un dispositivo solicita la intervención o un servicio del sistema operativo se realiza una interrupción.

La interrupción pasa el control a la rutina de manejo de interrupciones a través del vector de interrupción, que contiene las direcciones de todas las rutinas de servicio.
La arquitectura de interrupción debe salvar la dirección de la instrucción interrumpida Las interrupciones que entran son deshabilitadas mientras otra interrupción está siendo procesada.

Una trampa (trap) es una interrupción de software ocasionada por un error.

El sistema operativo es dirigido por interrupciones.

## Estructura del sistema

La estructura interna de los sistemas operativos pueden ser muy diferentes, ya que se debe tener en cuenta las metas de los usuarios (fácil uso, confiable, rápido, etc.) y las del sistema (fácil de diseñar, implementar y mantener, eficiente, etc.).  
Veremos 3 posibles diseños del sistema.

- Sistema monolítico
- Sistema en capas
- Sistema con micro núcleo

Es importante tener en cuenta que ningún sistema es puramente de un tipo.

### Sistema monolítico

Estos sistemas no tienen una estructura definida, sino que son escritos como una colección de procedimientos donde cualquier procedimiento puede invocar a otro. Escrito para proveer la mayor funcionalidad en el menor espacio.

Ejemplos de estos sistemas pueden ser MS-DOS o Linux (aunque incluye algo de capas).

### Sistema en capas

El diseño se organiza en una jerarquía de capas, donde los servicios que brinda una capa son consumidos solamente por la capa superior. La capa 0 es del Hardware y la N es la de los procesos de Usuario.

Estos sistemas tienen como ventaja que son modulares y la verificación se puede hacer a cada capa por separado (son más mantenibles). Sin embargo el diseño es muy costoso y es menos eficiente que el sistema monolítico ya que los niveles agregan una carga adicional a las llamadas al sistema.

### Sistema con micro núcleo

La idea consiste en tener un núcleo que brinde los servicios mínimos de manejo de procesos, memoria y que provea la comunicación entre procesos. Todos los restantes servicios se construyen como procesos separados del micro núcleo, que ejecutan en modo usuario.

Estos sistemas tienen como ventaja un diseño simple y funcional, que aumenta la portabilidad y la escalabilidad. Para agregar un nuevo servicio no es necesario modificar el núcleo, y es más seguro ya que los servicios corren en modo usuario. La desventaja con respecto a los sistemas monolíticos es en cuanto a la sobrecarga de comunicación entre espacios de usuario y kernel.

### Módulos

Algunas partes del núcleo pueden encontrarse en forma de archivos independientes llamados módulos que pueden ser cargados en tiempo de ejecución.

Puede ser util cargar determinados módulos en caso de que un dispositivo se encuentre disponible, al momento de que sea solicitado, o por algún tipo de política de planificación o seguridad requerida.

La mayoría de los S.O. modernos implementan módulos de kernel.

- Enfoque orientado a objetos
- Cada componente base está separado
- Cada uno habla con los otros a través de interfaces comunes.
- Cada uno puede cargarse conforme se necesita

Similar a las capas pero más flexible.

 Entre sus ventajas se encuentra el hecho de que el kernel no debe cargar todo desde un principio, pudiéndose expandir de ser requerido, el núcleo no es tan grande y no es necesario recompilar para agregar nuevos módulos.

 Tiene algunas desventajas en cuanto a la seguridad ya que un modulo puede comprometer el sistema ya que correrá en modo kernel. En algunos sistemas como Linux los módulos solo se pueden cargar con permisos elevados.