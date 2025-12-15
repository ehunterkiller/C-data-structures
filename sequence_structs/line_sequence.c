#include "line_sequence.h"
#include <stdlib.h>

struct _line_sequence {
    void ** elements;
    int max_capacity;
    int num_elements;
};

//============================== Creation and Deletion Functions ================================

line_sequence line_sequence_create(int max_capacity){
    line_sequence ls = (line_sequence) malloc(sizeof(struct _line_sequence));
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

void line_sequence_delete(line_sequence ls){
    free(ls->elements);
    free(ls);
}

void line_sequence_delete_all(line_sequence ls, void (*delete_func)(void*)){
    for(int i = 0; i < ls->num_elements; i++){
        delete_func(ls->elements[i]);
    }
    free(ls->elements);
    free(ls);
}

//============================== State Functions ================================

int line_sequence_max_cap(line_sequence ls){
    return ls->max_capacity;
}

int line_sequence_num_elems(line_sequence ls){
    return ls->num_elements;
}

int line_sequence_is_empty(line_sequence ls){
    return ls->num_elements == 0;
}

int line_sequence_is_full(line_sequence ls){
    return ls->num_elements == ls->max_capacity;
}

line_sequence line_sequence_add_cap(line_sequence ls, int more_capacity){
    line_sequence new_ls = line_sequence_create(ls->max_capacity + more_capacity);
    if(new_ls == NULL){
        return NULL;
    }

    for(int i = 0; i < ls->num_elements; i++){
        new_ls->elements[i] = ls->elements[i];
    }

    new_ls->num_elements = ls->num_elements;
    new_ls->max_capacity = ls->max_capacity + more_capacity;

    line_sequence_delete(ls);

    return new_ls;
}

//============================== Obtain Element Funtion ================================

void* line_sequence_get_elem_first(line_sequence ls){
    if(ls->num_elements == 0){
        return NULL;
    }

    return ls->elements[0];
}

//============================== Add Element Function ================================

int line_sequence_add_elem_last(line_sequence ls, void* new_element){
    if(ls->num_elements == ls->max_capacity){
        return 0;
    }

    ls->elements[ls->num_elements] = new_element;
    ls->num_elements++;
    return 1;
}

//============================== Remove Element Function ================================

int line_sequence_rem_elem_first(line_sequence ls){
    if(ls->num_elements == 0){
        return 0;
    }

    for(int i = 0; i < ls->num_elements-1; i++){
        ls->elements[i] = ls->elements[i+1];
    }

    ls->num_elements--;
    return 1;
}