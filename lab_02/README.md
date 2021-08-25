# Algoritmos y Estructuras de Datos - Taller 2

## Sesión 2

### Arreglos en C

- Un arreglo es un tipo de dato compuesto en el que varias variables de un mismo tipo se agrupan en una sola.

- Su definición general es:

  ```C
  <tipo> nombre[tamaño];
  ```
  
  Lo que permite definir un arreglo de tipo `<tipo>` y tamaño `tamaño`. Por ejemplo, para definir un arreglo de 20 enteros cortos (`short`), usamos:
  
  ```C
  short my_array[20];
  ```
  
- Mediante arreglos, podemos agrupar muchos valores y accederlos mediante su **posición** (ubicación) en el interior del arreglo, para lo que usamos su índice (de 0 a `tamaño-1`) entre corchetes a continuación del nombre. Por ejemplo, para añadir una cierta cantidad al quinto elemento y luego mostrarlo por pantalla, hacemos:

  ``` C
  // Como partimos de 0, la quinta posición es 4
  my_array[4] += 10;
  printf("%d\n", my_array[4]);
  ```

- Una característica muy importante de los arreglos es que son **estáticos**, es decir, una vez definidos, estos no pueden modificar su tamaño. Sin embargo, esto no significa que debamos conocer su tamaño de antemano. Podemos definirlo sin declarar su tamaño, dejando los corchetes de su definición en blanco, pero dándole un conjunto de valores de inicialización usando llaves y separándolos por coma:

  ```C
  // Un arreglo de cuatro elementos 
  // ya inicializados
  int a[] = {1, 2, 3, 4};
  ```

  Por supuesto, el problema aquí es que no  tenemos el tamaño de manera explícita declarada en el arreglo.

- Esto último puede significar un problema, puesto que C no provee un mecanismo para determinar cuál es el tamaño de un arreglo. Lo más cercano es el operador `sizeof`, que entrega un valor de tipo `site_t`[^1] (definido en, por ejemplo, `stdlib.h`) con la cantidad de **bytes** que ocupa el arreglo definido. A partir de esto, podemos determinar su tamaño, dividiendo dicha cantidad por la cantidad de bytes utilizados por cada elemento:

  ```C
  /* El operador sizeof requiere paréntesis
   * si es para medir el tamaño de un tipo de
   * dato
   */
  size_t size = sizeof a/sizeof(int)
  ```

  Sin embargo, este mecanismo no funciona, por ejemplo, cuando el arreglo es el parámetro de una función: esta requerirá, si hiciese falta, el tamaño como un parámetro adicional.

[^1]: El tipo `size_t` tiene una definición dependiente de la plataforma, pero, en general, corresponde a un entero largo sin signo (`unsigned long` o algo equivalente).

### Strings

- Los **strings**, cadenas de caracteres, son arreglos de tipo `char` en C, es decir, arreglos de caracteres.

- En C, las comillas simples son para representar caracteres, mientras que las comillas dobles, son para representar strings: `'a'`, por ejemplo, es un caracter, pero `"a"` es un string.

- Se diferencian de los arreglos habituales en que el compilador, si nosotros no lo hacemos, siempre le agrega el caracter nulo `\0` al final, pues este es el caracter que indica el final de un string. Esto implica dos cosas:

  - Si nuestro string necesita N caracteres, necesitamos N+1 en nuestro arreglo de caracteres.
  - Si nuestro arreglo tiene más caracteres de los que hacen falta para llegar al caracter nulo del string, los posteriores serán ignorados.

- Por ejemplo, podemos necesitar un string corto:

  ```C
  // Necesitamos el caracter extra para '\ 0'
  char texto_1[5] = "holi"
  ```

  O un string un poco más largo, suficiente como para almacenar una cadena de tamaño considerable:

  ```C
  // Dejamos más espacio del que necesitamos
  char buffer[50] = "Un texto largo, pero no tanto"
  ```

  O dejamos que el mismo compilador determine cuántos caracteres necesitamos:

  ```C
  // El compilador añade '\0' y su tamaño
  char text[] = "A la víbora de la mar, por aquí puede pasar"
  ```

- La característica de terminar con el caracter nulo puede ser aprovechada para determinar cuántos caracteres tiene un string sin necesidad de saberlo de antemano. Por ejemplo, podemos hacer:

  ```C
  size_t length = 0;
  while (text[length] != '\0'){
      length++;
  }
  ```

  Tras el ciclo, `length` tiene la cantidad de caracteres en el string.

- Una alternativa muy útil es utilizar la biblioteca `string.h`, que contiene varias operaciones comunes sobre strings, como copias, concatenación de strings, comparación, etc. Particularmente, contiene la instrucción `strlen`, que permite determinar el tamaño del string:

  ```C
  #import <string.h>
  // El resto del código va aquí
  size_t length = strlen(text);
  ```

### Arreglos como Punteros 

- Una característica muy importante de los arreglos es que sus nombres son ***punteros*** al primer elemento de estos. Cuando utilizamos uno como parámetro de una función, en realidad, estamos pasando la dirección al primero de sus elementos. Así, un encabezado de función que utiliza punteros es, por ejemplo,  como este:

  ```C
  // Función que busca un término en un arreglo
  int search(float* array, float term, int size);
  ```

  El parámetro `size` es pedido para poder saber hasta qué elemento puedo recorrer el arreglo. Dentro de la función, este arreglo puede ser utilizado como un puntero, utilizando el álgebra de estos[^2]. Por ejemplo, para verificar si el elemento está dentro del arreglo, podemos hacer:

  ```C
  // i lo definimos como el iterador para acceder
  // al arreglo
  if( *(array+i) == term ) return i;
  ```

  De modo que desplazamos la posición del arreglo en `i` posiciones. Esto es equivalente a acceder mediante la notación normal de arreglo:

  ```C
  if( array[i] == term ) return i;
  ```

- Esta idea la podemos aplicar un poco "a la inversa": si tenemos un puntero para cierto tipo de dato, podemos inicializarlo de manera dinámica mediante `malloc` (en `stdlib.h`). Esto sirve tanto si necesitamos un valor para dicho puntero, como si necesitamos una **colección** de valores para este, es decir, si necesitamos un arreglo. Por ejemplo,

  ```C
  #include <stdio.h>
  // El resto del código va aquí
  // Inicializamos el puntero.
  /* NULL es una constante "vacía" (0, básicamente) 
   * que permite dar un valor inicial al puntero.
   * No es estrictamente necesario, pero sí 
   * buena práctica el inicializar los punteros.
  */
  int *p=NULL, *array=NULL;
  unsigned int size = 20;
  // Inicializa un único valor
  p = (int*)malloc(sizeof(int));
  // Inicializa un bloque de memoria para 20 enteros
  array = (int*)malloc(sizeof(int)*size);
  
  // Luego, podemos asignarle valores
  *p = 10;
  array[10] = *p;
  ```

- El gran problema surgido de esta aproximación, claro, es que, como se señala antes, no hay forma de saber cuántos elementos tiene el arreglo generado así. Hemos de tener un registro muy cuidadoso de dónde almacenaremos el tamaño del arreglo, de modo que esté disponible para cuando lo necesitemos, de otro modo, podríamos incurrir en violaciones de segmento (*segmentation fault* o **segfault**, ocurrida porque nuestro programa intenta acceder zonas de memoria que no le están permitidas).



[^2]: Sumar y restar enteros a un puntero permite desplazar el sitio al que apuntan en esa cantidad de "posiciones", entendiendo estas como bloques de memoria del tamaño adecuado para representar el dato al que apuntan. Por ejemplo, si tenemos un puntero a entero `p` y le sumamos 2 (`p + 2`), el resultado serán 8 bytes después (el tamaño de un entero es 4 bytes). Por otro lado, si tenemos el puntero `p_c`, a caracter, y le sumamos esos mismos 2, `p_c + 2`, el resultado serán 2 bytes después, ya que un caracter solo usa un byte.

