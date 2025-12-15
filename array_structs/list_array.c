#include "list_array.h"
#include <stdlib.h>

struct _list_array {
    void ** elements;
    int num_elements;
    int max_capacity;
};

//============================== Creation and Deletion Functions ================================

list_array list_array_create(int max_capacity){
    list_array la = (list_array) malloc(sizeof(struct _list_array));
    if(la == NULL){
        return NULL;
    }

    la->elements = malloc(sizeof(void*) * max_capacity);
    if(la->elements == NULL){
        free(la);
        return NULL;
    }

    la->max_capacity = max_capacity;
    la->num_elements = 0;

    return la;
}

void list_array_delete(list_array la){
    free(la->elements);
    free(la);
}

void list_array_delete_all(list_array la, void (*delete_func)(void*)){
    for(int i = 0; i < la->num_elements; i++){
        delete_func(la->elements[i]);
    }
    free(la->elements);
    free(la);
}

//============================== State Functions ================================

int list_array_max_cap(list_array la){
    return la->max_capacity;
}

int list_array_num_elems(list_array la){
    return la->num_elements;
}

int list_array_is_empty(list_array la){
    return la->num_elements == 0;
}

int list_array_is_full(list_array la){
    return la->num_elements == la->max_capacity;
}

list_array list_array_add_cap(list_array la, int more_capacity){
    list_array new_ls = list_array_create(la->max_capacity + more_capacity);
    if(new_ls == NULL){
        return NULL;
    }

    for(int i = 0; i < la->num_elements; i++){
        new_ls->elements[i] = la->elements[i];
    }

    new_ls->num_elements = la->num_elements;
    new_ls->max_capacity = la->max_capacity + more_capacity;

    list_array_delete(la);

    return new_ls;
}

//============================== Obtain Element Funtions ================================

void* list_array_get_elem_first(list_array la){
    if(la->num_elements == 0){
        return NULL;
    }

    return la->elements[0];
}

void* list_array_get_elem_last(list_array la){
    if(la->num_elements == 0){
        return NULL;
    }

    return la->elements[la->num_elements-1];
}

void* list_array_get_elem_at(list_array la, int index){
    if(index < 0 || index >= la->num_elements){
        return NULL;
    }

    return la->elements[index];
}

//============================== Add Element Function ================================

int list_array_add_elem_last(list_array la, void* new_element){
    if(la->num_elements == la->max_capacity){
        return 0;
    }

    la->elements[la->num_elements] = new_element;
    la->num_elements++;
    return 1;
}

//============================== Remove Element Functions ================================

int list_array_rem_elem_first(list_array la){
    if(la->num_elements == 0){
        return 0;
    }

    for(int i = 0; i < la->num_elements-1; i++){
        la->elements[i] = la->elements[i+1];
    }

    la->num_elements--;
    return 1;
}

int list_array_rem_elem_last(list_array la){
    if(la->num_elements == 0){
        return 0;
    }

    la->num_elements--;
    return 1;
}

int list_array_rem_elem_at(list_array la, int index){
    if(la->num_elements == 0){
        return 0;
    }

    if(index < 0 || index > la->num_elements-1){
        return -1;
    }

    for(int i = index; i < la->num_elements-1; i++){
        la->elements[i] = la->elements[i+1];
    }

    la->num_elements--;
    return 1;
}