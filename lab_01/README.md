# Algoritmos y Estructuras de Datos - Taller

*Este README.md se ve mejor con Typora o equivalente*

[toc]

## El Taller/Laboratorio

- Sesiones prácticas semanales.
- Dos proyectos a lo largo del semestre: 20% de la nota de la asignatura cada una.
- Lenguaje a utilizar: C
- Herramientas obligatorias: GCC 10.2
  - Los códigos el profesor los probará en Linux.
- Herramientas opcionales:
  - IDE de su agrado (se recomienda acostumbrarse al uso de consola).
  - Makefile

## Sesión 1

### Estructuras en C

- Una de las construcciones más básicas en C es la estructura (`struct`). Su objetivo es permitir que una variable combine varios (tipos de) datos en sí. Podemos definir una estructura como:

  ```C
  struct [tag] {
      tipo_1 valor_1;
      tipo_2 valor_2;
      ...;
      tipo_n valor_n;
  } [variable];
  ```

  Lo que permite definir la estructura con una etiqueta (`tag`) opcional, para luego declarar variables que tengan los miembros definidos. Por ejemplo, podemos definir la estructura `vector` y definir los vectores `v` y `w` con:

  ```C
  struct vector {
      // Almacena las coordenadas del vector
      float x;
      float y;
      float z;
  } v, w;
  ```

- Una vez definida la estructura y las variables de ese tipo, podemos acceder a sus miembros usando la notación de punto:

  ```C
  /* Asigna las coordenadas de v a partir 
   * de las de w
   */
  v.x = 2*w.x;
  v.y = w.y;
  v.z = -w.z;
  ```

  Lo que viene a continuación del punto es un dato del tipo declarado, con todo lo que ello significa.

- Como puede ser que tengamos la estructura definida en un encabezado, al ser importante y/o general (ver, por ejemplo, la estructura `tm` de la biblioteca [`time.h`](https://www.tutorialspoint.com/c_standard_library/time_h.htm)), la podemos usar como tipo de dato, en cuyo caso, definimos una nueva variable usando la construcción `struct tag variable`:

  ```C
  struct vector u = {5.0, -1.5, 2.5};
  ```

  Las llaves nos permiten definir los valores iniciales de la estructura, todos a la vez.

- Alternativamente, podemos usar la estructura para definir un tipo usando `typedef`:

  ```C
  typedef struct {
      // Almacena las coordenadas del vector
      float x;
      float y;
      float z;
  } vector;
  
  vector u, v = {5.0, -1.5, 2.5}, w;
  ```

- Al tener una estructura que represente un tipo de dato compuesto, podemos ya hacer operaciones sobre ellas.

### Estructura de archivos en C

- Hay principalmente dos tipos de archivos en C:

  - Código fuente, con extensión `.c`, corresponden a los que tienen las definiciones de funciones y el código a ejecutar.

  - *Headers*, con extensión `.h`, corresponden a archivos con definiciones de tipos, constantes y funciones generales que incluir desde nuestros códigos. Los incluimos en otros *headers* o en nuestros códigos fuentes con la instrucción de preprocesador `#include` de dos maneras:

    ```C
    /* Para incluir bibliotecas/headers
     * del "sistema" o aquellas que estén en
     * ubicaciones que el compilador conozca.
     */
    #include <módulo.h>
    /* Para incluir bibliotecas/headers en la
     * misma carpeta del código fuente
     */
    #include "módulo.h"
    ```

- Al momento de compilar, solo incluimos como parámetros de GCC los códigos fuentes, no los headers, ya que estos serán incluidos por el compilador sin necesidad de nuestra intervención.

### Ejemplo

- Creemos una biblioteca para manejar vectores en un espacio bidimensional cartesiano, es decir, vectores con coordenadas $x$ e $y$, junto a las operaciones básicas vectoriales:
  - Suma vectorial $\vec{v_1} + \vec{v_2}$
  - Resta vectorial $\vec{v_1} - \vec{v_2}$
  - Multiplicación por escalar $a\cdot\vec{v_1}$
  - Módulo del vector (requerirá la biblioteca `math.h`), $||\vec{v}||$​
- Adicionalmente, veamos funciones para dar un formato de visualización cómodo al vector y pedirlo por teclado.
- Para esto, creamos la biblioteca `vector.h`, con los **prototipos** de las funciones a desarrollar, además de la definición del tipo de dato `vec2d_t`, para representar vectores bidimensionales.
- Junto a ello, escribiremos el código de cada función en el archivo para código fuente `vector.c`

### Ejercicio

- Hay que implementar una biblioteca para números complejos. Un número $z$ pertenece al conjunto de los números complejos $\mathbb{C}$, si está formado por una parte real y una imaginaria y tiene la forma general $z = a + ib$, en donde $a$ corresponde a su **parte real** y $b$​​, a si **parte imaginaria**.

- La constante imaginaria $i$​ (llamada $j$​ en algunas disciplinas, como ingeniería eléctrica o ciertas áreas de la física) es tal que $i^2 = -1$​, por lo que no tiene una representación numérica: el número complejo se representa, entonces, como un par ordenado $z = (a, b)$​, donde $a, b\in\mathbb{R}$​. Nótese que esto implica de inmediato que $\mathbb{R}\subset\mathbb{C}$ y que $z\in\mathbb{R}$ si $b=0$.

- Un número imaginario tiene varias operaciones que debemos implementar:

  - Suma (o resta): $z_1 + z_2 = (a_1 + a_2, b_1 + b_2)$
  - Multiplicación: $z_1\cdot z_2 = (a_1a_2 - b_1b_2, a_1a_2 + b_1b_2)$​, fórmula que surge de hacer la multiplicación considerando $i$ como una constante más y usando su propiedad de que $i^2 = -1$​.
  - Multiplicación por escalar ($x\in\mathbb{R}$): $xz = (ax, bx)$
  - Valor absoluto (módulo): $|z| = \sqrt{a^2 + b^2}$
  - Inverso multiplicativo: si $z\neq 0$​, $z^{-1} = \left(\frac{x}{|z|^2}, -\frac{y}{|z|^2}\right)$​
  - División: $\frac{z_1}{z_2} = z_1z_2^{-1}$
  - Conjugado: $\bar{z} = (a, -b)$

  Varias de estas operaciones se pueden escribir a partir de otras, por ejemplo, el valor absoluto se puede escribir como $|z| = \sqrt{z\bar{z}}$.

- Implemente una estructura para representar a un número complejo y las funciones necesarias para poder hacer las operaciones señaladas sobre los números complejos. Note que varias de las operaciones están definidas en función de otras: aproveche este hecho, para reutilizar el código ya escrito en otras de las funciones.

