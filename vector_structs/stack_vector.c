#include "stack_vector.h"
#include <stdlib.h>

struct _stack_vector {
    void ** elements;
    int max_capacity;
    int num_elements;
    int resize_factor;
};

//============================== Creation and Deletion Functions ================================

stack_vector stack_vector_create(int max_capacity, int resize_factor){
    stack_vector gv = (stack_vector) malloc(sizeof(struct _stack_vector));
    if(gv == NULL){
        return NULL;
    }

    gv->elements = malloc(sizeof(void*) * max_capacity);
    if(gv->elements == NULL){
        free(gv);
        return NULL;
    }

    gv->max_capacity = max_capacity;
    gv->num_elements = 0;
    gv->resize_factor = resize_factor;

    return gv;
}

void stack_vector_delete(stack_vector gv){
    free(gv->elements);
    free(gv);
}

void stack_vector_delete_all(stack_vector gv, void (*delete_func)(void*)){
    for(int i = 0; i < gv->num_elements; i++){
        delete_func(gv->elements[i]);
    }
    free(gv->elements);
    free(gv);
}

//============================== State Functions ================================

int stack_vector_max_cap(stack_vector gv){
    return gv->max_capacity;
}

int stack_vector_num_elems(stack_vector gv){
    return gv->num_elements;
}

int stack_vector_is_empty(stack_vector gv){
    return gv->num_elements == 0;
}

int stack_vector_is_full(stack_vector gv){
    return gv->num_elements == gv->max_capacity;
}

int stack_vector_add_cap(stack_vector gv, int more_capacity){
    int new_max_cap = gv->max_capacity + more_capacity;
    void **tmp = realloc(gv->elements, sizeof(void*) * new_max_cap);
    if(tmp == NULL){
        return 0;
    }

    gv->elements = tmp;
    gv->max_capacity = new_max_cap;

    return 1;
}

//============================== Dynamic Resize Functions ================================

int stack_vector_resize_factor(stack_vector gv){
    return gv->resize_factor;
}

void stack_vector_change_resize_factor(stack_vector gv, int new_resize_factor){
    gv->resize_factor = new_resize_factor;
}

//============================== Obtain Element Funtions ================================

void* stack_vector_get_elem_first(stack_vector gv){
    if(gv->num_elements == 0){
        return NULL;
    }

    return gv->elements[0];
}

void* stack_vector_get_elem_last(stack_vector gv){
    if(gv->num_elements == 0){
        return NULL;
    }

    return gv->elements[gv->num_elements-1];
}

void* stack_vector_get_elem_at(stack_vector gv, int index){
    if(index < 0 || index >= gv->num_elements){
        return NULL;
    }

    return gv->elements[index];
}

//============================== Add Element Functions ================================

int stack_vector_add_elem(stack_vector gv, void* new_element){
    if(gv->num_elements == gv->max_capacity){
        if(stack_vector_add_cap(gv,gv->resize_factor) == 0){
            return 0;
        }
    }

    for(int i = gv->num_elements-1; i >= 0; i--){
        gv->elements[i+1] = gv->elements[i];
    }

    gv->elements[0] = new_element;
    gv->num_elements++;
    return 1;
}

//============================== Remove Element Functions ================================

int stack_vector_rem_elem(stack_vector gv){
    if(gv->num_elements == 0){
        return 0;
    }

    for(int i = 0; i < gv->num_elements-1; i++){
        gv->elements[i] = gv->elements[i+1];
    }

    gv->num_elements--;
    return 1;
}