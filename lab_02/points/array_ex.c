#include <stdio.h>
#include <stdlib.h>

#define LENGTH 10

void show_array(int*, size_t);

int main(){
    int array[LENGTH] = {2, 3, 4, 5, 6};
    
    printf("Ingrese 5 valores:\n");
    scanf("%d %d %d %d %d", array+5, array+6, array+7, array+8, array+9);
    
    show_array(array, LENGTH);
    
    return 0;
}

void show_array(int* array, size_t size){
    for(int i=0; i < size - 1; i++)
        printf("%d, ", array[i]);

    printf("%d\n", array[size-1]);
    return;
}
