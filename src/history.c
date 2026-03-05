#include "array.h"
#include "histroy.h"
#include "render.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void create_history(HistoryNode **head ,int *array, int n){
    (*head)  = malloc(sizeof(HistoryNode));
    (*head)->array = copy_array(array, n);
    (*head)->step = 0;
    (*head)->n = n;
}

void add_result(HistoryNode *node, int *array, int n){
    HistoryNode *new_node = malloc(sizeof(HistoryNode));
    while (node->next != NULL) {
        node = node->next;
    }
    node->next = new_node;
    new_node->array = copy_array(array, n);
    new_node->step = node->step + 1;
    new_node->n = n;
}

int get_steps(HistoryNode *node){
    while (node->next != NULL) {
        node = node->next;
    }
    return node->step;
}

void print_history(HistoryNode *list, int n){
    while (list != NULL) {
        printf("Step %i: \n", list->step);
        render_array(list->array,n);
        printf("\n");
        list = list->next;
    }

}

void free_history(HistoryNode *list){
    HistoryNode *temp_node;
    while (list != NULL) {
        temp_node = list->next;
        free(list->array);
        free(list);
        list = temp_node;
    }
}
