#include <stdio.h>
#include <stdlib.h>

#include "curve.h"
#include "point.h"

float polinomy(float);

int main(){
//     point c[10];
//     
//     for(int i = 0; i < 10; i++){
//         char buff[20];
//         c[i] = create_point(i, i*i);
//         point_to_str(buff, c[i]);
//         printf("%s\n", buff);
//     }
//     
//  
//     return 0;

    curve c;
    float x[10];
    c = (curve)malloc(sizeof(point)*10);
    
    for(int i = 0; i < 10; i++){
        char s_point[20];
        x[i] = -1.0 + ((float)i)/5.0;
        c[i] = create_point(x[i], polinomy(x[i]));
        point_to_str(s_point, c[i]);
        printf("%s\n", s_point);
    }
        
    free(c);
    
    return 0;
}

float polinomy(float x){
    return x*x + 2*x + 1;
}
