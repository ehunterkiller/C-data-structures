#include "line_array.h"
#include <stdlib.h>

struct _line_array {
    void ** elements;
    int max_capacity;
    int num_elements;
};

//============================== Creation and Deletion Functions ================================

line_array line_array_create(int max_capacity){
    line_array la = (line_array) malloc(sizeof(struct _line_array));
    if(la == NULL){
        return NULL;
    }

    la->elements = malloc(sizeof(void*) * max_capacity);
    if(la->elements == NULL){
        free(la);
    }

    la->max_capacity = max_capacity;
    la->num_elements = 0;

    return la;
}

void line_array_delete(line_array la){
    free(la->elements);
    free(la);
}

void line_array_delete_all(line_array la, void (*delete_func)(void*)){
    for(int i = 0; i < la->num_elements; i++){
        delete_func(la->elements[i]);
    }
    free(la->elements);
    free(la);
}

//============================== State Functions ================================

int line_array_max_cap(line_array la){
    return la->max_capacity;
}

int line_array_num_elems(line_array la){
    return la->num_elements;
}

int line_array_is_empty(line_array la){
    return la->num_elements == 0;
}

int line_array_is_full(line_array la){
    return la->num_elements == la->max_capacity;
}

line_array line_array_add_cap(line_array la, int more_capacity){
    line_array new_ls = line_array_create(la->max_capacity + more_capacity);
    if(new_ls == NULL){
        return NULL;
    }

    for(int i = 0; i < la->num_elements; i++){
        new_ls->elements[i] = la->elements[i];
    }

    new_ls->num_elements = la->num_elements;
    new_ls->max_capacity = la->max_capacity + more_capacity;

    line_array_delete(la);

    return new_ls;
}

//============================== Obtain Element Funtions ================================

void* line_array_get_elem_first(line_array la){
    if(la->num_elements == 0){
        return NULL;
    }

    return la->elements[0];
}

void* line_array_get_elem_last(line_array la){
    if(la->num_elements == 0){
        return NULL;
    }

    return la->elements[la->num_elements-1];
}

void* line_array_get_elem_at(line_array la, int index){
    if(index < 0 || index >= la->num_elements){
        return NULL;
    }

    return la->elements[index];
}

//============================== Add Element Function ================================

int line_array_add_elem(line_array la, void* new_element){
    if(la->num_elements == la->max_capacity){
        return 0;
    }

    la->elements[la->num_elements] = new_element;
    la->num_elements++;
    return 1;
}

//============================== Remove Element Function ================================

int line_array_rem_elem(line_array la){
    if(la->num_elements == 0){
        return 0;
    }

    for(int i = 0; i < la->num_elements-1; i++){
        la->elements[i] = la->elements[i+1];
    }

    la->num_elements--;
    return 1;
}