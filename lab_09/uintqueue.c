#include "uintqueue.h"

uint_t dequeue(uintqueue* q){
    node* first = q->head;
    q->head = first->next;
    q->len--;
    
    uint_t value = first->value;
    free_node(first);
    
    
    return value;
}
