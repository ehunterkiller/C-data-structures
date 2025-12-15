#include "gen_array.h"
#include <stdlib.h>

struct _gen_array {
    void ** elements;
    int num_elements;
    int max_capacity;
};

//============================== Creation and Deletion Functions ================================

gen_array gen_array_create(int max_capacity){
    gen_array gs = (gen_array) malloc(sizeof(struct _gen_array));
    if(gs == NULL){
        return NULL;
    }
    
    gs->elements = malloc(sizeof(void*) * max_capacity);
    if(gs->elements == NULL){
        free(gs);
        return NULL;
    }

    gs->max_capacity = max_capacity;
    gs->num_elements = 0;

    return gs;
}

void gen_array_delete(gen_array gs){
    free(gs->elements);
    free(gs);
}

void gen_array_delete_all(gen_array gs, void (*delete_func)(void*)){
    for(int i = 0; i < gs->num_elements; i++){
        delete_func(gs->elements[i]);
    }
    free(gs->elements);
    free(gs);
}

//============================== State Functions ================================

int gen_array_max_cap(gen_array gs){
    return gs->max_capacity;
}

int gen_array_num_elems(gen_array gs){
    return gs->num_elements;
}

int gen_array_is_empty(gen_array gs){
    return gs->num_elements == 0;
}

int gen_array_is_full(gen_array gs){
    return gs->num_elements == gs->max_capacity;
}

gen_array gen_array_add_cap(gen_array gs, int more_capacity){
    gen_array new_gs = gen_array_create(gs->max_capacity + more_capacity);
    if(new_gs == NULL){
        return NULL;
    }

    for(int i = 0; i < gs->num_elements; i++){
        new_gs->elements[i] = gs->elements[i];
    }

    new_gs->num_elements = gs->num_elements;
    new_gs->max_capacity = gs->max_capacity + more_capacity;

    gen_array_delete(gs);

    return new_gs;
}

//============================== Obtain Element Funtions ================================

void* gen_array_get_elem_first(gen_array gs){
    if(gs->num_elements == 0){
        return NULL;
    }

    return gs->elements[0];
}

void* gen_array_get_elem_last(gen_array gs){
    if(gs->num_elements == 0){
        return NULL;
    }

    return gs->elements[gs->num_elements-1];
}

void* gen_array_get_elem_at(gen_array gs, int index){
    if(index < 0 || index >= gs->num_elements){
        return NULL;
    }

    return gs->elements[index];
}

//============================== Add Element Functions ================================

int gen_array_add_elem_first(gen_array gs, void* new_element){
    if(gs->num_elements == gs->max_capacity){
        return 0;
    }

    for(int i = gs->num_elements-1; i >= 0; i--){
        gs->elements[i+1] = gs->elements[i];
    }

    gs->elements[0] = new_element;
    gs->num_elements++;
    return 1;
}

int gen_array_add_elem_last(gen_array gs, void* new_element){
    if(gs->num_elements == gs->max_capacity){
        return 0;
    }

    gs->elements[gs->num_elements] = new_element;
    gs->num_elements++;
    return 1;
}

int gen_array_add_elem_at(gen_array gs, int index, void* new_element){
    if(gs->num_elements == gs->max_capacity){
        return 0;
    }

    if(index < 0 || index >= gs->max_capacity){
        return -1;
    }

    for(int i = gs->num_elements-1; i >= index; i--){
        gs->elements[i+1] = gs->elements[i];
    }

    gs->elements[index] = new_element;
    gs->num_elements++;
    return 1;
}

//============================== Remove Element Functions ================================

int gen_array_rem_elem_first(gen_array gs){
    if(gs->num_elements == 0){
        return 0;
    }

    for(int i = 0; i < gs->num_elements-1; i++){
        gs->elements[i] = gs->elements[i+1];
    }

    gs->num_elements--;
    return 1;
}

int gen_array_rem_elem_last(gen_array gs){
    if(gs->num_elements == 0){
        return 0;
    }

    gs->num_elements--;
    return 1;
}

int gen_array_rem_elem_at(gen_array gs, int index){
    if(gs->num_elements == 0){
        return 0;
    }

    if(index < 0 || index > gs->num_elements-1){
        return -1;
    }

    for(int i = index; i < gs->num_elements-1; i++){
        gs->elements[i] = gs->elements[i+1];
    }

    gs->num_elements--;
    return 1;
}