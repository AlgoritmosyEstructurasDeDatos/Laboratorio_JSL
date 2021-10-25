#ifndef __UINTQUEUE_H__
#define __UINTQUEUE_H__

#include "uintlist.h"

// Tipo de dato que usaremos, una cola
typedef list uintqueue;

// Operaciones de cola
// Crea la cola
#define create_queue() create_list()

// Encola y desencola
#define enqueue(q, v) insert_last(q, v)
uint_t dequeue(uintqueue*);

// Elimina la cola
#define delete_queue(q) delete_list(q);

#endif
