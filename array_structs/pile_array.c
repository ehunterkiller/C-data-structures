#include "pile_array.h"
#include <stdlib.h>

struct _pile_array {
    void ** elements;
    int max_capacity;
    int num_elements;
};

//============================== Creation and Deletion Functions ================================

pile_array pile_array_create(int max_capacity){
    pile_array pa = (pile_array) malloc(sizeof(struct _pile_array));
    if(pa == NULL){
        return NULL;
    }
    
    pa->elements = malloc(sizeof(void*) * max_capacity);
    if(pa->elements == NULL){
        free(pa);
        return NULL;
    }

    pa->max_capacity = max_capacity;
    pa->num_elements = 0;

    return pa;
}

void pile_array_delete(pile_array pa){
    free(pa->elements);
    free(pa);
}

void pile_array_delete_all(pile_array pa, void (*delete_func)(void*)){
    for(int i = 0; i < pa->num_elements; i++){
        delete_func(pa->elements[i]);
    }
    free(pa->elements);
    free(pa);
}

//============================== State Functions ================================

int pile_array_max_cap(pile_array pa){
    return pa->max_capacity;
}

int pile_array_num_elems(pile_array pa){
    return pa->num_elements;
}

int pile_array_is_empty(pile_array pa){
    return pa->num_elements == 0;
}

int pile_array_is_full(pile_array pa){
    return pa->num_elements == pa->max_capacity;
}

pile_array pile_array_add_cap(pile_array pa, int more_capacity){
    pile_array new_ps = pile_array_create(pa->max_capacity + more_capacity);
    if(new_ps == NULL){
        return NULL;
    }

    for(int i = 0; i < pa->num_elements; i++){
        new_ps->elements[i] = pa->elements[i];
    }

    new_ps->num_elements = pa->num_elements;
    new_ps->max_capacity = pa->max_capacity + more_capacity;

    pile_array_delete(pa);

    return new_ps;
}

//============================== Obtain Element Funtions ================================

void* pile_array_get_elem_first(pile_array pa){
    if(pa->num_elements == 0){
        return NULL;
    }

    return pa->elements[0];
}

void* pile_array_get_elem_last(pile_array pa){
    if(pa->num_elements == 0){
        return NULL;
    }

    return pa->elements[pa->num_elements-1];
}

void* pile_array_get_elem_at(pile_array pa, int index){
    if(index < 0 || index >= pa->num_elements){
        return NULL;
    }

    return pa->elements[index];
}

//============================== Add Element Function ================================

int pile_array_add_elem_first(pile_array pa, void* new_element){
    if(pa->num_elements == pa->max_capacity){
        return 0;
    }

    for(int i = pa->num_elements-1; i >= 0; i--){
        pa->elements[i+1] = pa->elements[i];
    }

    pa->elements[0] = new_element;
    pa->num_elements++;
    return 1;
}

//============================== Remove Element Function ================================

int pile_array_rem_elem_first(pile_array pa){
    if(pa->num_elements == 0){
        return 0;
    }

    for(int i = 0; i < pa->num_elements-1; i++){
        pa->elements[i] = pa->elements[i+1];
    }

    pa->num_elements--;
    return 1;
}