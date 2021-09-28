#include "uintlist.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Interfaz para los nodos
node* new_node(uint_t value){
    // Crea el espacio
    node* n = (node*)malloc(sizeof(node));
    if(!n) return NULL;
    
    // Inicializa los valores
    n->value = value;
    n->previous = NULL;
    n->next = NULL;
    
    return n;
}


void free_node(node* n){
    // Un simple wrapper para el free
    free(n);
}


// Operaciones de lista
list* create_list(){
    // Crea la lista
    list* l = (list*)malloc(sizeof(list));
    if(!l) return NULL;
    
    // Inicializa los valores
    l->len = 0;
    l->head = NULL;
    l->tail = NULL;
    
    return l;
}


void insert_first(list* l, uint_t value){
    // crea un nodo
    node* n = new_node(value);
    
    // La cabeza antigua ahora es el segundo elemento (apuntado por el nuevo nodo)
    n->next = l->head;
    // La cabeza es el nuevo nodo
    l->head = n;
    // Cuando es el primer elemento insertado, debemos insertar, también, en la cola
    if(!l->tail) l->tail = n;
    // Aumenta el total de elementos
    l->len++;
}


void insert_last(list* l, uint_t value){
    node* n = new_node(value);
    
    // Cuando es el primer elemento insertado, también insertamos la cabeza
    if(!l->head) l->head = n;
    
    // Si hay elementos
    if(l->tail){
        // El penúltimo elemento
        n->previous = l->tail;
        // El penúltimo elemento ahora apunta a la cola
        l->tail->next = n;
        // La cola es el nuevo elemento
    }
    // El elemento insertado es la cola
    l->tail = n;
    // Aumenta el total de elementos
    l->len++;
}


/* Esta función borra el valor de la lista, no el nodo. Primero busca cuál es el
 * nodo que contiene el valor solicitado y borra el primero que encuentra
 */
void delete_element(list* l, uint_t value){
    // Si la lista está en blanco, no hay nada que borrar
    if (l->len == 0) return;
    
    // Primer nodo donde buscar
    node *n = l->head;
    
    // Mientras n no sea nulo y el valor no sea el que vamos a eliminar
    while(n && n->value != value)
        n = n->next;
    
    // Nada que borrar
    if(!n) return;
    
    /* Si hay un previo, hay que ponerle el próximo de este como
     * su propio próximo
     */
    if (n->previous)
        n->previous->next = n->next;
    /* Si hay un próximo, hay que ponerle el previo de este como
     * su propio previo
     */
    if (n->next)
        n->next->previous = n->previous;
    
    // Liberamos el nodo
    free_node(n);
    
    // Disminuimos el tamaño de la lista
    l->len--;
    
    // Fin
    return;
}


void empty_list(list*l){
    // Recorre la lista desde la cola, borrando los elementos que haya en ella
    while(l->tail){
        // Guarda la cola
        node *n = l->tail;
        // Mueve la cola al penúltimo
        l->tail = n->previous;
        // Borra el nodo
        free_node(n);
        l->len--;
    }
    /* Al finalizar, nos hemos quedado sin nodos, por lo que debemos, también
     * marcar que no hay cabeza en la lista
     */
    l->head = NULL;
}


void delete_list(list* l){
    // Primero la vacía
    empty_list(l);
    // Luego libera la memoria usada
    free(l);
}


char* list_to_string(list* l){
    /* Esta función creará un buffer para el string y lo devolverá.
     * La ventaja de esto es que la función se encarga de manejar el string
     * y todas sus operaciones para crear el dato final. La desventaja es que
     * el que llama a la función debe encargarse de la memoria asociada, ya que
     * el búfer es dinámico.
     */
    
    // Toma la cabeza de la lista, si no hay, retorna un puntero a string vacío
    node *n = l->head;
    if(!n){
        // Como no tenemos elementos, entregamos un string con solo el caracter
        // de fin de string
        char* tmp = (char*)malloc(sizeof(char));
        // En caso de error, no podemos escribir, así que devolvemos nulo
        if(!tmp) return NULL;
        tmp[0] = '\0';
        return tmp;
    }
    
    // Tamaño inicial del búfer
    const size_t BUFLEN = 64;
    // Tamaño actual del búfer
    size_t buf_size = BUFLEN;
    
    // Cantidad de caracteres escritos
    size_t current_len = 0;
    
    // El búfer
    char *buffer = (char*)malloc(buf_size);
    // Escribe el primer elemento a string
    /* La familia de printf devuelve la cantidad de caracteres escritos como 
     * resultado, o un número negativo si hubo un error.
     * 
     * Una función más segura que esta es snprintf, que limita cuántos caracteres
     * son escritos
     */
    current_len += sprintf(buffer, "%d", n->value);
    // Avanza al próximo elemento
    n = n->next;
    
    while (n != NULL){
        // Búfer donde escribir cada elemento (y la coma)
        char numbuf[BUFLEN];
        // Escribe y obtiene cuántos caracteres se escribieron
        size_t written = sprintf(numbuf, ", %d", n->value);
        
        // Verifica si se pasa del límite del búfer actual
        if(current_len + written >= buf_size){
            // Si se pasa, obtenemos un nuevo tamaño para el búfer
            size_t new_size = buf_size + BUFLEN;
            // Reasigna el búfer con más espacio
            char* tmp = (char*)realloc(buffer, new_size);
            // Si no funciona, devuelve hasta donde alcanzó a escribir
            if(!tmp){
                return buffer;
            }
            // Si funciona, cambia la dirección del búfer a la nueva
            buffer = tmp;
            // Y actualiza el tamaño
            buf_size = new_size;
        }
        // Concatena el búfer con el búfer del número escrito
        strcat(buffer, numbuf);
        // Actualiza la cantidad de caracteres escritos
        current_len += written;
        // Va al próximo elemento de la lista
        n = n->next;
    }
    
    // llegados aquí, el string está escrito completo.
    return buffer;
}
