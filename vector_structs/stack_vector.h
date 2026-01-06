#ifndef STACK_VECTOR_H
#define STACK_VECTOR_H

//data type structure definition - stack vector
/*
Stores elements in a vector and only allows the insertion at the first position and the extraction at the first position
*/
typedef struct _stack_vector * stack_vector;

//============================== Creation and Deletion Functions ================================
/*
Creates the stack vector
    Parameters:
        > initial maximum capacity
        > resizing factor
    Returns:
        > stack_vector pointer
*/
stack_vector stack_vector_create(int max_capacity, int resize_factor);

/*
Deletes the stack vector
    Parameters:
        > stack vector pointer
    Returns:
        > nothing
*/
void stack_vector_delete(stack_vector gv);

/*
Deletes the stack vector and the elements stored in it
    Parameters:
        > stack vector pointer
        > deletion function for the elements
    Returns:
        > nothing
*/
void stack_vector_delete_all(stack_vector gv, void (*delete_func)(void*));

//============================== State Functions ================================
/*
Obtains the maxium capacity of the stack vector
    Parameters:
        > stack vector pointer
    Returns:
        > maximum capacity
*/
int stack_vector_max_cap(stack_vector gv);

/*
Obtains the number of elements populationg the stack vector
    Parameters:
        > stack vector pointer
    Returns:
        > maximum capacity
*/
int stack_vector_num_elems(stack_vector gv);

/*
Returns true if the stack vector is has zero elements
    Parameters:
        > stack vector pointer
    Returns:
        > true or false (int)
*/
int stack_vector_is_empty(stack_vector gv);

/*
Returns true if the stack vector is at full capacity
    Parameters:
        > stack vector pointer
    Returns:
        > true or false (int)
*/
int stack_vector_is_full(stack_vector gv);

/*
Resizes the stack vector with added maximum capacity
    Parameters:
        > stack vector pointer
        > number of new slots
    Returns:
        > true or false (int)
*/
int stack_vector_add_cap(stack_vector gv, int more_capacity);

//============================== Dynamic Resize Functions ================================
/*
Returns the resize factor of the stack vector
    Parameters:
        > stack vector pointer
    Returns:
        > resize factor
*/
int stack_vector_resize_factor(stack_vector gv);

/*
Changes the resize factor of the stack vector
    Parameters:
        > stack vector pointer
        > new resize factor
    Returns:
        > nothing
*/
void stack_vector_change_resize_factor(stack_vector gv, int new_resize_factor);

//============================== Obtain Element Funtions ================================
/*
Returns the element stored in first position of the stack vector
    Parameters:
        > stack vector pointer
    Returns:
        > element stored
*/
void* stack_vector_get_elem_first(stack_vector gv);

/*
Returns the element stored in last position of the stack vector
    Parameters:
        > stack vector pointer
    Returns:
        > element stored
*/
void* stack_vector_get_elem_last(stack_vector gv);

/*
Returns the element stored in given position of the stack vector
    Parameters:
        > stack vector pointer
        > index of the element
    Returns:
        > element stored
*/
void* stack_vector_get_elem_at(stack_vector gv, int index);

//============================== Add Element Functions ================================
/*
Adds the given element at the first position of the stack vector
    Parameters:
        > stack vector pointer
        > new element
    Returns:
        > success of the operation
*/
int stack_vector_add_elem(stack_vector gv, void* new_element);

//============================== Remove Element Functions ================================
/*
Removes the element at the first position of the stack vector
    Parameters:
        > stack vector pointer
    Returns:
        > nothing
*/
int stack_vector_rem_elem(stack_vector gv);

#endif