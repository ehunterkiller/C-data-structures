#include "pile_sequence.h"
#include <stdlib.h>

struct _pile_sequence {
    void ** elements;
    int max_capacity;
    int num_elements;
};

//============================== Creation and Deletion Functions ================================

pile_sequence pile_sequence_create(int max_capacity){
    pile_sequence ps = (pile_sequence) malloc(sizeof(struct _pile_sequence));
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

void pile_sequence_delete(pile_sequence ps){
    free(ps->elements);
    free(ps);
}

void pile_sequence_delete_all(pile_sequence ps, void (*delete_func)(void*)){
    for(int i = 0; i < ps->num_elements; i++){
        delete_func(ps->elements[i]);
    }
    free(ps->elements);
    free(ps);
}

//============================== State Functions ================================

int pile_sequence_max_cap(pile_sequence ps){
    return ps->max_capacity;
}

int pile_sequence_num_elems(pile_sequence ps){
    return ps->num_elements;
}

int pile_sequence_is_empty(pile_sequence ps){
    return ps->num_elements == 0;
}

int pile_sequence_is_full(pile_sequence ps){
    return ps->num_elements == ps->max_capacity;
}

pile_sequence pile_sequence_add_cap(pile_sequence ps, int more_capacity){
    pile_sequence new_ps = pile_sequence_create(ps->max_capacity + more_capacity);
    if(new_ps == NULL){
        return NULL;
    }

    for(int i = 0; i < ps->num_elements; i++){
        new_ps->elements[i] = ps->elements[i];
    }

    new_ps->num_elements = ps->num_elements;
    new_ps->max_capacity = ps->max_capacity + more_capacity;

    pile_sequence_delete(ps);

    return new_ps;
}

//============================== Obtain Element Funtion ================================

void* pile_sequence_get_elem_first(pile_sequence ps){
    if(ps->num_elements == 0){
        return NULL;
    }

    return ps->elements[0];
}

//============================== Add Element Function ================================

int pile_sequence_add_elem_first(pile_sequence ps, void* new_element){
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

int pile_sequence_rem_elem_first(pile_sequence ps){
    if(ps->num_elements == 0){
        return 0;
    }

    for(int i = 0; i < ps->num_elements-1; i++){
        ps->elements[i] = ps->elements[i+1];
    }

    ps->num_elements--;
    return 1;
}