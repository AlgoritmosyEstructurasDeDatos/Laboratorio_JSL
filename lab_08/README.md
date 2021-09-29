# Laboratorio de Grafos

En estos archivos, se encuentra un módulo para leer grafos desde un archivo con el formato dado como ejemplo en `sample.digraph` (que, a decir verdad, se trata como un grafo no dirigido en este programa).

Para compilarlo, puede utilizarse el programa `make` y, directamente en consola, escribir:
```[shell]
$ make
```
y se compilarán todos los elementos. Alternativamente, puede hacerse
```[shell]
$ gcc -o full_test main.c graphloader.c tdagraph.c uintlist.c
```
pero resultaría conveniente que conozcan `make` y sus bondades para compilar proyectos.

# Estructura

El proyecto consiste de tres módulos, además de un par de archivos de prueba. El programa `main.c` corresponde a la prueba de carga de un grafo y su visualización como un mensaje "sencillo" por pantalla. El programa `test_list.c` es uno para probar la generación de una lista de enteros y su visualización.

## Módulo para listas

El módulo `uintlist.h` contiene la interfaz para una lista de números enteros sin signo, tratada como lista doblemente enlazada. Tiene varias de las operaciones básicas, como insertar al inicio, al final, borrar, crear y convertir a string (como valores separados por coma). Una función que debiese ser añadida es la de buscar un elemento (y así retornar su posición o el nodo en que se encuentra) y otra que permita verificar si un elemento está presente en ella (esto podría hacerse haciendo un buscar que entregue el nodo o `NULL`, si no se encuentra el valor; mientras que la función de verificar si existe el nodo, entrega `true` o `false`, macros definidas en `stdbool.h`, según si el resultado de la búsqueda es `NULL` o no).

## Módulo para grafos no dirigidos

Presenta una interfaz con las operaciones básicas de grafo, además de una estructura de conveniencia que permite almacenar una arista como dos enteros, `u` para la fuente y `v` para el destino. La función `is_edge`, para verificar si una arista existe dentro del grafo y base para algunas de las funciones, debería ser implementada con la función de buscar o verificar existencia de valor propuesta en la descripción del módulo `uintlist` en la sección anterior.

Como ejercicio, se debería implementar un grafo como una matriz de adyacencia y, para este módulo, una interfaz que permita ampliar las operaciones para incluir:
- Obtener los vértices adyacentes (*no* las aristas), tal vez como arreglo.
- Obtener el grado de un vértice.
- Obtener las aristas como un arreglo de aristas.
- Obtener el grado máximo y el grado mínimo.
- Verificar si un vértice es adyacente a otro (nótese que esto es *similar* a lo que hace la función `is_edge`, sin embargo, no es lo mismo).

Además de otras operaciones que permitan verificar algunas de las definiciones de grafos vistas en clases.

En el próximo laboratorio, veremos cómo implementar algunos algoritmos de búsqueda, como BFS y similares.

## Módulo para carga de grafos

Simplemente una función para cargar el grafo desde un archivo con el formato de `sample.digraph`. Se sugiere crear una función para almacenar un grafo siguiendo el mismo formato.
