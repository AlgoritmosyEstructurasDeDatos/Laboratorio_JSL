#ifndef __UINTSTACK_H__
#define __UINTSTACK_H__

#include "uintlist.h"
#include <stdbool.h>

typedef struct {
    uint_t max_size;
    uint_t top;
    uint_t *values;
} uintstack;

uintstack* create_stack(uint_t);
void delete_stack(uintstack*);

bool stack_empty(uintstack*);
void push(uintstack*, uint_t);
uint_t pop(uintstack*);

#endif
