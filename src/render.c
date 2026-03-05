#include "render.h"
#include <stdio.h>
#include <string.h>

int find_max(int *array, int n){
    int value = 0;
    int idx = 0;
    for(int i = 0; i < n; i++){
        if (array[i] > value) {
            value = array[i];
            idx = i;
        }
    }
    return idx;
}

void render_array_height(int *array, int n){
    int max_idx = find_max(array,n);
    for (int i = array[max_idx]; i>0; i--) {
        for (int j = 0; j < n; j++) {
            if (array[j]>=i ) {
                printf("█ ");
            }else {
                printf("  ");
            }
        }
        printf("\n");
    }
    for (int i = 0; i < n; i++) {
        printf("--");
    }
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("%i ", array[i]);
    }
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("━━━");
    }
    printf("\n");

}

void render_array(int *array, int n){
    if (array == NULL) {
        printf("Nullpointer : given array is not created yet user create_array(int n) to create one");
    }
    for (int i = 0; i < n; i++) {
        printf("%i ", array[i]);
        for (int j = array[i]; j > 0; j--) {
            printf("█");
        }
        printf("\n");
    }


}
