#include "line_array.h"
#include <stdlib.h>

struct _line_array {
    void ** elements;
    int max_capacity;
    int num_elements;
};

//============================== Creation and Deletion Functions ================================

line_array line_array_create(int max_capacity){
    line_array ls = (line_array) malloc(sizeof(struct _line_array));
    if(ls == NULL){
        return NULL;
    }

    ls->elements = malloc(sizeof(void*) * max_capacity);
    if(ls->elements == NULL){
        free(ls);
    }

    ls->max_capacity = max_capacity;
    ls->num_elements = 0;

    return ls;
}

void line_array_delete(line_array ls){
    free(ls->elements);
    free(ls);
}

void line_array_delete_all(line_array ls, void (*delete_func)(void*)){
    for(int i = 0; i < ls->num_elements; i++){
        delete_func(ls->elements[i]);
    }
    free(ls->elements);
    free(ls);
}

//============================== State Functions ================================

int line_array_max_cap(line_array ls){
    return ls->max_capacity;
}

int line_array_num_elems(line_array ls){
    return ls->num_elements;
}

int line_array_is_empty(line_array ls){
    return ls->num_elements == 0;
}

int line_array_is_full(line_array ls){
    return ls->num_elements == ls->max_capacity;
}

line_array line_array_add_cap(line_array ls, int more_capacity){
    line_array new_ls = line_array_create(ls->max_capacity + more_capacity);
    if(new_ls == NULL){
        return NULL;
    }

    for(int i = 0; i < ls->num_elements; i++){
        new_ls->elements[i] = ls->elements[i];
    }

    new_ls->num_elements = ls->num_elements;
    new_ls->max_capacity = ls->max_capacity + more_capacity;

    line_array_delete(ls);

    return new_ls;
}

//============================== Obtain Element Funtion ================================

void* line_array_get_elem_first(line_array ls){
    if(ls->num_elements == 0){
        return NULL;
    }

    return ls->elements[0];
}

//============================== Add Element Function ================================

int line_array_add_elem_last(line_array ls, void* new_element){
    if(ls->num_elements == ls->max_capacity){
        return 0;
    }

    ls->elements[ls->num_elements] = new_element;
    ls->num_elements++;
    return 1;
}

//============================== Remove Element Function ================================

int line_array_rem_elem_first(line_array ls){
    if(ls->num_elements == 0){
        return 0;
    }

    for(int i = 0; i < ls->num_elements-1; i++){
        ls->elements[i] = ls->elements[i+1];
    }

    ls->num_elements--;
    return 1;
}