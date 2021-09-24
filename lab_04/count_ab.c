#include <stdio.h>
#include <stdlib.h>
// Macros para usar definiciones de booleanos un poco más cómodas
// que el tipo por defecto
#include <stdbool.h>
// Operaciones de strings
#include <string.h>

// Estructura para stack de caracteres
// Estrictamente, podrían haberse utilizado las listas enlazadas de la
// sesión pasada, definiendo operaciones específicas de stack
typedef struct stack_node *link;

typedef struct stack_node {
    char c;
    link next;
} stack, *p_stack;


// Verifica si el stack está vacío
// Por la definición, es solo un wrapper para un comparador, pero que
// ayuda a clarificar las operaciones
bool is_empty(p_stack p){
    return p == NULL;
}


// Crea un nodo para el stack
p_stack create_node(char c){
    p_stack n = (p_stack)malloc(sizeof(stack));
    n->c = c;
    n->next = NULL;
    
    return n;
}


// Empuja un valor dentro del stack
p_stack push(p_stack p, char c){
    p_stack new = create_node(c);
    new->next = p;
    return new;
}


// Saca el último valor ingresado al stack
/* Por la construcción utilizada, la "cola" (tope) del stack es el último
 * elemento ingresado. Al eliminarlo, perdemos la referencia al próximo,
 * generando un memory leak. Si utilizamos como entrada el tipo p_stack*,
 * estamos pidiendo un puntero a puntero (pues p_stack es, a su vez un puntero
 * a estructura). Con esto, cualquier cambio que hagamos a la dirección 
 * apuntada por el argumento se verá reflejado fuera de la función.
 * 
 * Un lugar donde aparecen punteros a punteros más o menos frecuentes es en
 * matrices: el nombre de un arreglo es un puntero a la primera posición. Un
 * arreglo de arreglos es un puntero al puntero a la primera posición.
 */
char pop(p_stack* p){
    // Verifica que haya algo que quitar
    if (is_empty(*p))
        exit(EXIT_FAILURE);
    
    // Valor a recuperar
    char value = (*p)->c;
    // Siguiente elemento
    p_stack n = (*p);
    // Ahora el tope del stack apunta al elemento siguiente
    (*p) = n->next;
    // Libera el elemento recuperado
    free(n);
    
    // Retorna el valor recuperado
    /* N.B.: si esto fuera un stack de strings, hay que copiar el contenido
     * del string antes de liberar el nodo, o lo perderemos.
     */
    return value;
}


// Vacía el stack
void empty_stack(p_stack s){
    while (!is_empty(s)){
        p_stack n = s->next;
        free(s);
        s = n;
    }
}


int main(){
    // String no equilibrado
    char* S = "ABAAAABBBAABABABABABBBBBAAAABBABABABBBAAAAA";
    // String equilibrado
//     char* S = "AABBAABB";
    
    // Stacks para A's y B's
    p_stack p_a = NULL, p_b = NULL;
    
    // Largo del string
    size_t len = strlen(S);
    
    // Rellena los stacks, según si hay A o B. Esto asume que no hay otro caracter
    for(int i = 0; i < len; i++)
        if (S[i] == 'A')
            p_a = push(p_a, 'A');
        else
            p_b = push(p_b, 'B');
        
    /* Mientras haya algo en ambos stacks, se saca de ambos. Se detiene al vaciarse
     * cualquiera de los stacks
     */
    while (!is_empty(p_a) && !is_empty(p_b)){
        printf("%c %c\n", pop(&p_a), pop(&p_b));
    }
    
    // Si ambos stacks están vacíos, la cantidad es la misma
    if (is_empty(p_a) && is_empty(p_b))
        puts("Misma cantidad de A y B");
    else
        puts("Nope");
    
    // Si los stacks están vacíos, no hace nada, pero si no, los vacía
    empty_stack(p_a);
    empty_stack(p_b);
    
    return 0;
}
