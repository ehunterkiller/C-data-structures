#include "line_vector.h"
#include <stdlib.h>

struct _line_vector {
    void ** elements;
    int max_capacity;
    int num_elements;
    int resize_factor;
};

//============================== Creation and Deletion Functions ================================

line_vector line_vector_create(int max_capacity, int resize_factor){
    line_vector gv = (line_vector) malloc(sizeof(struct _line_vector));
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

void line_vector_delete(line_vector gv){
    free(gv->elements);
    free(gv);
}

void line_vector_delete_all(line_vector gv, void (*delete_func)(void*)){
    for(int i = 0; i < gv->num_elements; i++){
        delete_func(gv->elements[i]);
    }
    free(gv->elements);
    free(gv);
}

//============================== State Functions ================================

int line_vector_max_cap(line_vector gv){
    return gv->max_capacity;
}

int line_vector_num_elems(line_vector gv){
    return gv->num_elements;
}

int line_vector_is_empty(line_vector gv){
    return gv->num_elements == 0;
}

int line_vector_is_full(line_vector gv){
    return gv->num_elements == gv->max_capacity;
}

int line_vector_add_cap(line_vector gv, int more_capacity){
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

int line_vector_resize_factor(line_vector gv){
    return gv->resize_factor;
}

void line_vector_change_resize_factor(line_vector gv, int new_resize_factor){
    gv->resize_factor = new_resize_factor;
}

//============================== Obtain Element Funtions ================================

void* line_vector_get_elem_first(line_vector gv){
    if(gv->num_elements == 0){
        return NULL;
    }

    return gv->elements[0];
}

void* line_vector_get_elem_last(line_vector gv){
    if(gv->num_elements == 0){
        return NULL;
    }

    return gv->elements[gv->num_elements-1];
}

void* line_vector_get_elem_at(line_vector gv, int index){
    if(index < 0 || index >= gv->num_elements){
        return NULL;
    }

    return gv->elements[index];
}

//============================== Add Element Functions ================================

int line_vector_add_elem(line_vector gv, void* new_element){
    if(gv->num_elements == gv->max_capacity){
        if(line_vector_add_cap(gv,gv->resize_factor) == 0){
            return 0;
        }
    }

    gv->elements[gv->num_elements] = new_element;
    gv->num_elements++;
    return 1;
}

//============================== Remove Element Functions ================================

int line_vector_rem_elem(line_vector gv){
    if(gv->num_elements == 0){
        return 0;
    }

    for(int i = 0; i < gv->num_elements-1; i++){
        gv->elements[i] = gv->elements[i+1];
    }

    gv->num_elements--;
    return 1;
}