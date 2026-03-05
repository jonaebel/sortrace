#ifndef HISTORY_H
#define HISTORY_H

typedef struct Node {
    int *array; // stores current state of the array (strcpy so i dont always store the same pointer to the changing array)
    int step;
    struct Node  *next;
    int n;
} HistoryNode;


// returns steps for one history list
int get_steps(HistoryNode *node);

// creates HEAD node for history linked list
void create_history(HistoryNode **head, int *array, int n);

// Creates a new history result node (a new step in the linked list )
void add_result(HistoryNode *node, int *array,int n); // step is previous step + 1

// Prints out the whole linked list using the render function in render.c/.h
void print_history(HistoryNode *list, int n);

// frees a histroy (linked list) by going through it
void free_history(HistoryNode *list);



#endif
