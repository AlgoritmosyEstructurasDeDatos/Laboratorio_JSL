#include <stdio.h>
#include <stdlib.h>

char* get_line(FILE*);

int main(){
    FILE* fp = fopen("small_text.txt", "r");
    
    if(!fp){
        printf("No se puede abrir el archivo.");
        return -1;
    }
    
    /*char buff[16];
    
    fscanf(fp, "%s", buff);
    puts(buff);
    
    fscanf(fp, "%s", buff);
    puts(buff);
    */
    
    char *buff;
    buff = get_line(fp);
    puts(buff);
    free(buff);
    
    buff = get_line(fp);
    puts(buff);
    free(buff);
    
    fclose(fp);
    return 0;
}

char* get_line(FILE* fp){
    const size_t LENGTH = 15;
    const size_t STEP = 15;
    
    size_t current_size = 0;
    char c, *buffer = NULL;
    
    int n_read = 0;
    
    buffer = (char*)malloc(LENGTH + 1);
    if(buffer == NULL)
        return NULL;
    else
        current_size = LENGTH;
    
    // Mientras no haya llegado al final de la línea y no haya llegado al final de
    // archivo
    while( (c = fgetc(fp)) != '\n' && (c != EOF) ){
        n_read++;
        
        if(n_read > current_size){
            size_t new_size = current_size + STEP;
            char* tmp = (char*)realloc(buffer, new_size + 1);
            
            if(!tmp){
                free(buffer);
                return NULL;
            }
            
            buffer = tmp;
            current_size = new_size;
        } // fin if
        buffer[n_read-1] = c;
    } // fin while
    
    // Final de string
    buffer[n_read] = '\0';
    
    // String ya leído
    return buffer;
}
