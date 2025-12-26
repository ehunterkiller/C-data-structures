#ifndef GENERIC_VECTOR_H
#define GENERIC_VECTOR_H

//data type structure definition - generic vector
/*
Stores elements in a vector and allows all types of data manipualtion
*/
typedef struct _gen_vector * gen_vector;

//============================== Creation and Deletion Functions ================================
/*
Creates the generic vector
    Parameters:
        > initial maximum capacity
        > resizing factor
    Returns:
        > generic vector pointer
*/
gen_vector gen_vector_create(int max_capacity, int resize_factor);

/*
Deletes the generic vector
    Parameters:
        > generic vector pointer
    Returns:
        > nothing
*/
void gen_vector_delete(gen_vector gv);

/*
Deletes the generic vector and the elements stored in it
    Parameters:
        > generic vector pointer
        > deletion function for the elements
    Returns:
        > nothing
*/
void gen_vector_delete_all(gen_vector gv, void (*delete_func)(void*));

//============================== State Functions ================================
/*
Obtains the maxium capacity of the generic vector
    Parameters:
        > generic vector pointer
    Returns:
        > maximum capacity
*/
int gen_vector_max_cap(gen_vector gv);

/*
Obtains the number of elements populationg the generic vector
    Parameters:
        > generic vector pointer
    Returns:
        > maximum capacity
*/
int gen_vector_num_elems(gen_vector gv);

/*
Returns true if the generic vector is has zero elements
    Parameters:
        > generic vector pointer
    Returns:
        > true or false (int)
*/
int gen_vector_is_empty(gen_vector gv);

/*
Returns true if the generic vector is at full capacity
    Parameters:
        > generic vector pointer
    Returns:
        > true or false (int)
*/
int gen_vector_is_full(gen_vector gv);

/*
Resizes the generic vector with added maximum capacity
    Parameters:
        > generic vector pointer
        > number of new slots
    Returns:
        > true or false (int)
*/
int gen_vector_add_cap(gen_vector gv, int more_capacity);

//============================== Dynamic Resize Functions ================================
/*
Returns the resize factor of the generic vector
    Parameters:
        > generic vector pointer
    Returns:
        > resize factor
*/
int gen_vector_resize_factor(gen_vector gv);

/*
Changes the resize factor of the generic vector
    Parameters:
        > generic vector pointer
        > new resize factor
    Returns:
        > nothing
*/
void gen_vector_change_resize_factor(gen_vector gv, int new_resize_factor);

//============================== Obtain Element Funtions ================================
/*
Returns the element stored in first position of the generic vector
    Parameters:
        > generic vector pointer
    Returns:
        > element stored
*/
void* gen_vector_get_elem_first(gen_vector gv);

/*
Returns the element stored in last position of the generic vector
    Parameters:
        > generic vector pointer
    Returns:
        > element stored
*/
void* gen_vector_get_elem_last(gen_vector gv);

/*
Returns the element stored in given position of the generic vector
    Parameters:
        > generic vector pointer
        > index of the element
    Returns:
        > element stored
*/
void* gen_vector_get_elem_at(gen_vector gv, int index);

//============================== Add Element Functions ================================
/*
Adds the given element at the first position of the generic vector
    Parameters:
        > generic vector pointer
        > new element
    Returns:
        > success of the operation
*/
int gen_vector_add_elem_first(gen_vector gv, void* new_element);

/*
Adds the given element at the last position of the generic vector
    Parameters:
        > generic vector pointer
        > new element
    Returns:
        > success of the operation
*/
int gen_vector_add_elem_last(gen_vector gv, void* new_element);

/*
Adds the given element at the given position of the generic vector
    Parameters:
        > generic vector pointer
        > new element
    Returns:
        > success of the operation
*/
int gen_vector_add_elem_at(gen_vector gv, int index, void* new_element);

//============================== Remove Element Functions ================================
/*
Removes the element at the first position of the generic vector
    Parameters:
        > generic vector pointer
    Returns:
        > nothing
*/
int gen_vector_rem_elem_first(gen_vector gv);

/*
Removes the element at the last position of the generic vector
    Parameters:
        > generic vector pointer
    Returns:
        > nothing
*/
int gen_vector_rem_elem_last(gen_vector gv);

/*
Removes the element at the given position of the generic vector
    Parameters:
        > generic vector pointer
        > index
    Returns:
        > nothing
*/
int gen_vector_rem_elem_at(gen_vector gv, int index);

#endif