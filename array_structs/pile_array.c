#include "pile_array.h"
#include <stdlib.h>

struct _pile_array {
    void ** elements;
    int max_capacity;
    int num_elements;
};

//============================== Creation and Deletion Functions ================================

pile_array pile_array_create(int max_capacity){
    pile_array ps = (pile_array) malloc(sizeof(struct _pile_array));
    if(ps == NULL){
        return NULL;
    }
    
    ps->elements = malloc(sizeof(void*) * max_capacity);
    if(ps->elements == NULL){
        free(ps);
        return NULL;
    }

    ps->max_capacity = max_capacity;
    ps->num_elements = 0;

    return ps;
}

void pile_array_delete(pile_array ps){
    free(ps->elements);
    free(ps);
}

void pile_array_delete_all(pile_array ps, void (*delete_func)(void*)){
    for(int i = 0; i < ps->num_elements; i++){
        delete_func(ps->elements[i]);
    }
    free(ps->elements);
    free(ps);
}

//============================== State Functions ================================

int pile_array_max_cap(pile_array ps){
    return ps->max_capacity;
}

int pile_array_num_elems(pile_array ps){
    return ps->num_elements;
}

int pile_array_is_empty(pile_array ps){
    return ps->num_elements == 0;
}

int pile_array_is_full(pile_array ps){
    return ps->num_elements == ps->max_capacity;
}

pile_array pile_array_add_cap(pile_array ps, int more_capacity){
    pile_array new_ps = pile_array_create(ps->max_capacity + more_capacity);
    if(new_ps == NULL){
        return NULL;
    }

    for(int i = 0; i < ps->num_elements; i++){
        new_ps->elements[i] = ps->elements[i];
    }

    new_ps->num_elements = ps->num_elements;
    new_ps->max_capacity = ps->max_capacity + more_capacity;

    pile_array_delete(ps);

    return new_ps;
}

//============================== Obtain Element Funtion ================================

void* pile_array_get_elem_first(pile_array ps){
    if(ps->num_elements == 0){
        return NULL;
    }

    return ps->elements[0];
}

//============================== Add Element Function ================================

int pile_array_add_elem_first(pile_array ps, void* new_element){
    if(ps->num_elements == ps->max_capacity){
        return 0;
    }

    for(int i = ps->num_elements-1; i >= 0; i--){
        ps->elements[i+1] = ps->elements[i];
    }

    ps->elements[0] = new_element;
    ps->num_elements++;
    return 1;
}

//============================== Remove Element Function ================================

int pile_array_rem_elem_first(pile_array ps){
    if(ps->num_elements == 0){
        return 0;
    }

    for(int i = 0; i < ps->num_elements-1; i++){
        ps->elements[i] = ps->elements[i+1];
    }

    ps->num_elements--;
    return 1;
}