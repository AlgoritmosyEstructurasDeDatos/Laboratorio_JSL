#include <stdio.h>
#include <stdlib.h>

#include "uintlist.h"

int main(){
    list *l = create_list();
    
    for(int i = 0; i <= 200; i+=10){
        insert_last(l, i);
    }

    char* output = list_to_string(l);
    printf("%s\n", output);
    free(output);
    
    delete_list(l);
    
    return 0;
}
