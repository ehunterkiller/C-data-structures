#include "list_sequence.h"
#include <stdlib.h>

struct _list_sequence {
    void ** elements;
    int num_elements;
    int max_capacity;
};

//============================== Creation and Deletion Functions ================================

list_sequence list_sequence_create(int max_capacity){
    list_sequence ls = (list_sequence) malloc(sizeof(struct _list_sequence));
    if(ls == NULL){
        return NULL;
    }

    ls->elements = malloc(sizeof(void*) * max_capacity);
    if(ls->elements == NULL){
        free(ls);
        return NULL;
    }

    ls->max_capacity = max_capacity;
    ls->num_elements = 0;

    return ls;
}

void list_sequence_delete(list_sequence ls){
    free(ls->elements);
    free(ls);
}

void list_sequence_delete_all(list_sequence ls, void (*delete_func)(void*)){
    for(int i = 0; i < ls->num_elements; i++){
        delete_func(ls->elements[i]);
    }
    free(ls->elements);
    free(ls);
}

//============================== State Functions ================================

int list_sequence_max_cap(list_sequence ls){
    return ls->max_capacity;
}

int list_sequence_num_elems(list_sequence ls){
    return ls->num_elements;
}

int list_sequence_is_empty(list_sequence ls){
    return ls->num_elements == 0;
}

int list_sequence_is_full(list_sequence ls){
    return ls->num_elements == ls->max_capacity;
}

list_sequence list_sequence_add_cap(list_sequence ls, int more_capacity){
    list_sequence new_ls = list_sequence_create(ls->max_capacity + more_capacity);
    if(new_ls == NULL){
        return NULL;
    }

    for(int i = 0; i < ls->num_elements; i++){
        new_ls->elements[i] = ls->elements[i];
    }

    new_ls->num_elements = ls->num_elements;
    new_ls->max_capacity = ls->max_capacity + more_capacity;

    list_sequence_delete(ls);

    return new_ls;
}

//============================== Obtain Element Funtions ================================

void* list_sequence_get_elem_first(list_sequence ls){
    if(ls->num_elements == 0){
        return NULL;
    }

    return ls->elements[0];
}

void* list_sequence_get_elem_last(list_sequence ls){
    if(ls->num_elements == 0){
        return NULL;
    }

    return ls->elements[ls->num_elements-1];
}

void* list_sequence_get_elem_at(list_sequence ls, int index){
    if(index < 0 || index >= ls->num_elements){
        return NULL;
    }

    return ls->elements[index];
}

//============================== Add Element Function ================================

int list_sequence_add_elem_last(list_sequence ls, void* new_element){
    if(ls->num_elements == ls->max_capacity){
        return 0;
    }

    ls->elements[ls->num_elements] = new_element;
    ls->num_elements++;
    return 1;
}

//============================== Remove Element Functions ================================

int list_sequence_rem_elem_first(list_sequence ls){
    if(ls->num_elements == 0){
        return 0;
    }

    for(int i = 0; i < ls->num_elements-1; i++){
        ls->elements[i] = ls->elements[i+1];
    }

    ls->num_elements--;
    return 1;
}

int list_sequence_rem_elem_last(list_sequence ls){
    if(ls->num_elements == 0){
        return 0;
    }

    ls->num_elements--;
    return 1;
}

int list_sequence_rem_elem_at(list_sequence ls, int index){
    if(ls->num_elements == 0){
        return 0;
    }

    if(index < 0 || index > ls->num_elements-1){
        return -1;
    }

    for(int i = index; i < ls->num_elements-1; i++){
        ls->elements[i] = ls->elements[i+1];
    }

    ls->num_elements--;
    return 1;
}