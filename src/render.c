#include "render.h"
#include <stdio.h>
#include <string.h>


void render_array(int *array, int n){
    if (array == NULL) {
        printf("Nullpointer : given array is not created yet user create_array(int n) to create one");
    }
    for (int i = 0; i < n; i++) {
        printf("%i ", array[i]);
        for (int j = array[i]; j > 0; j--) {
            printf("#");
        }
        printf("\n");
    }


}
