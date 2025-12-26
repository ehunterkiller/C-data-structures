#include "stack_array.h"
#include <stdlib.h>

struct _stack_array {
    void ** elements;
    int max_capacity;
    int num_elements;
};

//============================== Creation and Deletion Functions ================================

stack_array stack_array_create(int max_capacity){
    stack_array pa = (stack_array) malloc(sizeof(struct _stack_array));
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

void stack_array_delete(stack_array pa){
    free(pa->elements);
    free(pa);
}

void stack_array_delete_all(stack_array pa, void (*delete_func)(void*)){
    for(int i = 0; i < pa->num_elements; i++){
        delete_func(pa->elements[i]);
    }
    free(pa->elements);
    free(pa);
}

//============================== State Functions ================================

int stack_array_max_cap(stack_array pa){
    return pa->max_capacity;
}

int stack_array_num_elems(stack_array pa){
    return pa->num_elements;
}

int stack_array_is_empty(stack_array pa){
    return pa->num_elements == 0;
}

int stack_array_is_full(stack_array pa){
    return pa->num_elements == pa->max_capacity;
}

stack_array stack_array_add_cap(stack_array pa, int more_capacity){
    stack_array new_ps = stack_array_create(pa->max_capacity + more_capacity);
    if(new_ps == NULL){
        return NULL;
    }

    for(int i = 0; i < pa->num_elements; i++){
        new_ps->elements[i] = pa->elements[i];
    }

    new_ps->num_elements = pa->num_elements;
    new_ps->max_capacity = pa->max_capacity + more_capacity;

    stack_array_delete(pa);

    return new_ps;
}

//============================== Obtain Element Funtions ================================

void* stack_array_get_elem_first(stack_array pa){
    if(pa->num_elements == 0){
        return NULL;
    }

    return pa->elements[0];
}

void* stack_array_get_elem_last(stack_array pa){
    if(pa->num_elements == 0){
        return NULL;
    }

    return pa->elements[pa->num_elements-1];
}

void* stack_array_get_elem_at(stack_array pa, int index){
    if(index < 0 || index >= pa->num_elements){
        return NULL;
    }

    return pa->elements[index];
}

//============================== Add Element Function ================================

int stack_array_add_elem(stack_array pa, void* new_element){
    if(pa->num_elements == pa->max_capacity){
        return 0;
    }

    pa->elements[pa->num_elements] = new_element;
    pa->num_elements++;
    return 1;
}

//============================== Remove Element Function ================================

int stack_array_rem_elem(stack_array pa){
    if(pa->num_elements == 0){
        return 0;
    }

    pa->num_elements--;
    return 1;
}