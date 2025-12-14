#include "gen_sequence.h"
#include <stdlib.h>

struct _gen_sequence {
    void ** elements;
    int num_elements;
    int max_capacity;
};


gen_sequence gen_sequence_create(int max_capacity){
    gen_sequence gs = (gen_sequence) malloc(sizeof(gen_sequence));
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

int gen_sequence_max_cap(gen_sequence gs){
    return gs->max_capacity;
}

int gen_sequence_num_elems(gen_sequence gs){
    return gs->num_elements;
}

int gen_sequence_is_empty(gen_sequence gs){
    return gs->num_elements == 0;
}

void* gen_sequence_get_elem_first(gen_sequence gs){
    return gs->elements[0];
}

void* gen_sequence_get_elem_last(gen_sequence gs){
    return gs->elements[gs->num_elements-1];
}

void* gen_sequence_get_elem_at(gen_sequence gs, int index){
    return gs->elements[index];
}

void gen_sequence_add_elem_first(gen_sequence gs, void* new_element){
    if(gs->num_elements == gs->max_capacity){
        return;
    }

    for(int i = gs->num_elements; i > 0; i--){
        gs->elements[i] = gs->elements[i+1];
    }

    gs->elements[0] = new_element;
}

void gen_sequence_add_elem_last(gen_sequence gs, void* new_element){
    if(gs->num_elements == gs->max_capacity){
        return;
    }

    gs->elements[gs->num_elements] = new_element;
}

void gen_sequence_add_elem_at(gen_sequence gs, int index, void* new_element){
    if(gs->num_elements == gs->max_capacity){
        return;
    }

    if(index < 0 || index > gs->max_capacity-1){
        return;
    }

    for(int i = gs->num_elements; i >= index; i--){
        gs->elements[i] = gs->elements[i+1];
    }

    gs->elements[index] = new_element;
}

void gen_sequence_rem_elem_first(gen_sequence gs){
    if(gs->num_elements == 0){
        return;
    }

    for(int i = 0; i < gs->num_elements-1; i++){
        gs->elements[i] = gs->elements[i+1];
    }

    gs->num_elements--;
}

void gen_sequence_rem_elem_last(gen_sequence gs){
    if(gs->num_elements == 0){
        return;
    }

    gs->num_elements--;
}

void gen_sequence_rem_elem_at(gen_sequence gs, int index){
    if(gs->num_elements == 0){
        return;
    }

    if(index < 0 || index > gs->num_elements-1){
        return;
    }

    for(int i = index; i < gs->num_elements-1; i++){
        gs->elements[i] = gs->elements[i+1];
    }

    gs->num_elements--;
}