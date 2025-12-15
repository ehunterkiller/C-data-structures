#include "gen_sequence.h"
#include <stdlib.h>

struct _gen_sequence {
    void ** elements;
    int num_elements;
    int max_capacity;
};

//============================== Creation and Deletion Functions ================================

gen_sequence gen_sequence_create(int max_capacity){
    gen_sequence gs = (gen_sequence) malloc(sizeof(struct _gen_sequence));
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

void gen_sequence_delete(gen_sequence gs){
    free(gs->elements);
    free(gs);
}

void gen_sequence_delete_all(gen_sequence gs, void (*delete_func)(void*)){
    for(int i = 0; i < gs->num_elements; i++){
        delete_func(gs->elements[i]);
    }
    free(gs->elements);
    free(gs);
}

//============================== State Functions ================================

int gen_sequence_max_cap(gen_sequence gs){
    return gs->max_capacity;
}

int gen_sequence_num_elems(gen_sequence gs){
    return gs->num_elements;
}

int gen_sequence_is_empty(gen_sequence gs){
    return gs->num_elements == 0;
}

int gen_sequence_is_full(gen_sequence gs){
    return gs->num_elements == gs->max_capacity;
}

gen_sequence gen_sequence_add_cap(gen_sequence gs, int more_capacity){
    gen_sequence new_gs = gen_sequence_create(gs->max_capacity + more_capacity);
    if(new_gs == NULL){
        return NULL;
    }

    for(int i = 0; i < gs->num_elements; i++){
        new_gs->elements[i] = gs->elements[i];
    }

    new_gs->num_elements = gs->num_elements;
    new_gs->max_capacity = gs->max_capacity + more_capacity;

    gen_sequence_delete(gs);

    return new_gs;
}

//============================== Obtain Element Funtions ================================

void* gen_sequence_get_elem_first(gen_sequence gs){
    if(gs->num_elements == 0){
        return NULL;
    }

    return gs->elements[0];
}

void* gen_sequence_get_elem_last(gen_sequence gs){
    if(gs->num_elements == 0){
        return NULL;
    }

    return gs->elements[gs->num_elements-1];
}

void* gen_sequence_get_elem_at(gen_sequence gs, int index){
    if(index < 0 || index >= gs->num_elements){
        return NULL;
    }

    return gs->elements[index];
}

//============================== Add Element Functions ================================

int gen_sequence_add_elem_first(gen_sequence gs, void* new_element){
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

int gen_sequence_add_elem_last(gen_sequence gs, void* new_element){
    if(gs->num_elements == gs->max_capacity){
        return 0;
    }

    gs->elements[gs->num_elements] = new_element;
    gs->num_elements++;
    return 1;
}

int gen_sequence_add_elem_at(gen_sequence gs, int index, void* new_element){
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

int gen_sequence_rem_elem_first(gen_sequence gs){
    if(gs->num_elements == 0){
        return 0;
    }

    for(int i = 0; i < gs->num_elements-1; i++){
        gs->elements[i] = gs->elements[i+1];
    }

    gs->num_elements--;
    return 1;
}

int gen_sequence_rem_elem_last(gen_sequence gs){
    if(gs->num_elements == 0){
        return 0;
    }

    gs->num_elements--;
    return 1;
}

int gen_sequence_rem_elem_at(gen_sequence gs, int index){
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