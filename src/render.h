#ifndef RENDER_H
#define RENDER_H


/*Renders array like seen in example :
 * 3 ###
 * 5 #####
 * 8 ########
 *
 * n is the length of the array
 */
void  render_array(int* array, int n);

// returns position where max value sits
int find_max(int *array, int n);

void render_array_height(int *array, int n);

#endif
