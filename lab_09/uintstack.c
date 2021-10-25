#include "uintstack.h"

#include <stdlib.h>

uintstack* create_stack(uint_t size){
    uintstack *s = (uintstack*)malloc(sizeof(uintstack));
    
    s->max_size = size;
    s->top = 0;
    s->values = (uint_t*)calloc(sizeof(uint_t), s->max_size);
    
    return s;
}


void delete_stack(uintstack* s){
    free(s->values);
    free(s);
}

bool stack_empty(uintstack* s){
    if(s->top == 0) return true;
    else return false;
}


void push(uintstack* s, uint_t x){
    s->top++;
    s->values[s->top] = x;
}


uint_t pop(uintstack* s){
    if(!stack_empty(s)){
        s->top--;
        return s->values[s->top];
    }
    
    return 0;
}
