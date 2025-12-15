#include "gen_array.h"
#include <stdlib.h>

struct _gen_array {
    void ** elements;
    int num_elements;
    int max_capacity;
};

//============================== Creation and Deletion Functions ================================

gen_array gen_array_create(int max_capacity){
    gen_array ga = (gen_array) malloc(sizeof(struct _gen_array));
    if(ga == NULL){
        return NULL;
    }
    
    ga->elements = malloc(sizeof(void*) * max_capacity);
    if(ga->elements == NULL){
        free(ga);
        return NULL;
    }

    ga->max_capacity = max_capacity;
    ga->num_elements = 0;

    return ga;
}

void gen_array_delete(gen_array ga){
    free(ga->elements);
    free(ga);
}

void gen_array_delete_all(gen_array ga, void (*delete_func)(void*)){
    for(int i = 0; i < ga->num_elements; i++){
        delete_func(ga->elements[i]);
    }
    free(ga->elements);
    free(ga);
}

//============================== State Functions ================================

int gen_array_max_cap(gen_array ga){
    return ga->max_capacity;
}

int gen_array_num_elems(gen_array ga){
    return ga->num_elements;
}

int gen_array_is_empty(gen_array ga){
    return ga->num_elements == 0;
}

int gen_array_is_full(gen_array ga){
    return ga->num_elements == ga->max_capacity;
}

gen_array gen_array_add_cap(gen_array ga, int more_capacity){
    gen_array new_gs = gen_array_create(ga->max_capacity + more_capacity);
    if(new_gs == NULL){
        return NULL;
    }

    for(int i = 0; i < ga->num_elements; i++){
        new_gs->elements[i] = ga->elements[i];
    }

    new_gs->num_elements = ga->num_elements;
    new_gs->max_capacity = ga->max_capacity + more_capacity;

    gen_array_delete(ga);

    return new_gs;
}

//============================== Obtain Element Funtions ================================

void* gen_array_get_elem_first(gen_array ga){
    if(ga->num_elements == 0){
        return NULL;
    }

    return ga->elements[0];
}

void* gen_array_get_elem_last(gen_array ga){
    if(ga->num_elements == 0){
        return NULL;
    }

    return ga->elements[ga->num_elements-1];
}

void* gen_array_get_elem_at(gen_array ga, int index){
    if(index < 0 || index >= ga->num_elements){
        return NULL;
    }

    return ga->elements[index];
}

//============================== Add Element Functions ================================

int gen_array_add_elem_first(gen_array ga, void* new_element){
    if(ga->num_elements == ga->max_capacity){
        return 0;
    }

    for(int i = ga->num_elements-1; i >= 0; i--){
        ga->elements[i+1] = ga->elements[i];
    }

    ga->elements[0] = new_element;
    ga->num_elements++;
    return 1;
}

int gen_array_add_elem_last(gen_array ga, void* new_element){
    if(ga->num_elements == ga->max_capacity){
        return 0;
    }

    ga->elements[ga->num_elements] = new_element;
    ga->num_elements++;
    return 1;
}

int gen_array_add_elem_at(gen_array ga, int index, void* new_element){
    if(ga->num_elements == ga->max_capacity){
        return 0;
    }

    if(index < 0 || index >= ga->max_capacity){
        return -1;
    }

    for(int i = ga->num_elements-1; i >= index; i--){
        ga->elements[i+1] = ga->elements[i];
    }

    ga->elements[index] = new_element;
    ga->num_elements++;
    return 1;
}

//============================== Remove Element Functions ================================

int gen_array_rem_elem_first(gen_array ga){
    if(ga->num_elements == 0){
        return 0;
    }

    for(int i = 0; i < ga->num_elements-1; i++){
        ga->elements[i] = ga->elements[i+1];
    }

    ga->num_elements--;
    return 1;
}

int gen_array_rem_elem_last(gen_array ga){
    if(ga->num_elements == 0){
        return 0;
    }

    ga->num_elements--;
    return 1;
}

int gen_array_rem_elem_at(gen_array ga, int index){
    if(ga->num_elements == 0){
        return 0;
    }

    if(index < 0 || index > ga->num_elements-1){
        return -1;
    }

    for(int i = index; i < ga->num_elements-1; i++){
        ga->elements[i] = ga->elements[i+1];
    }

    ga->num_elements--;
    return 1;
}