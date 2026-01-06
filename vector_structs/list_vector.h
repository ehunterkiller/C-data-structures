#ifndef LIST_VECTOR_H
#define LIST_VECTOR_H

//data type structure definition - list vector
/*
Stores elements in a vector and only allows the insertion at the last position
*/
typedef struct _list_vector * list_vector;

//============================== Creation and Deletion Functions ================================
/*
Creates the list vector
    Parameters:
        > initial maximum capacity
        > resizing factor
    Returns:
        > list vector pointer
*/
list_vector list_vector_create(int max_capacity, int resize_factor);

/*
Deletes the list vector
    Parameters:
        > list vector pointer
    Returns:
        > nothing
*/
void list_vector_delete(list_vector gv);

/*
Deletes the list vector and the elements stored in it
    Parameters:
        > list vector pointer
        > deletion function for the elements
    Returns:
        > nothing
*/
void list_vector_delete_all(list_vector gv, void (*delete_func)(void*));

//============================== State Functions ================================
/*
Obtains the maxium capacity of the list vector
    Parameters:
        > list vector pointer
    Returns:
        > maximum capacity
*/
int list_vector_max_cap(list_vector gv);

/*
Obtains the number of elements populationg the list vector
    Parameters:
        > list vector pointer
    Returns:
        > maximum capacity
*/
int list_vector_num_elems(list_vector gv);

/*
Returns true if the list vector is has zero elements
    Parameters:
        > list vector pointer
    Returns:
        > true or false (int)
*/
int list_vector_is_empty(list_vector gv);

/*
Returns true if the list vector is at full capacity
    Parameters:
        > list vector pointer
    Returns:
        > true or false (int)
*/
int list_vector_is_full(list_vector gv);

/*
Resizes the list vector with added maximum capacity
    Parameters:
        > list vector pointer
        > number of new slots
    Returns:
        > true or false (int)
*/
int list_vector_add_cap(list_vector gv, int more_capacity);

//============================== Dynamic Resize Functions ================================
/*
Returns the resize factor of the list vector
    Parameters:
        > list vector pointer
    Returns:
        > resize factor
*/
int list_vector_resize_factor(list_vector gv);

/*
Changes the resize factor of the list vector
    Parameters:
        > list vector pointer
        > new resize factor
    Returns:
        > nothing
*/
void list_vector_change_resize_factor(list_vector gv, int new_resize_factor);

//============================== Obtain Element Funtions ================================
/*
Returns the element stored in first position of the list vector
    Parameters:
        > list vector pointer
    Returns:
        > element stored
*/
void* list_vector_get_elem_first(list_vector gv);

/*
Returns the element stored in last position of the list vector
    Parameters:
        > list vector pointer
    Returns:
        > element stored
*/
void* list_vector_get_elem_last(list_vector gv);

/*
Returns the element stored in given position of the list vector
    Parameters:
        > list vector pointer
        > index of the element
    Returns:
        > element stored
*/
void* list_vector_get_elem_at(list_vector gv, int index);

//============================== Add Element Functions ================================
/*
Adds the given element at the last position of the list vector
    Parameters:
        > list vector pointer
        > new element
    Returns:
        > success of the operation
*/
int list_vector_add_elem(list_vector gv, void* new_element);

//============================== Remove Element Functions ================================
/*
Removes the element at the first position of the list vector
    Parameters:
        > list vector pointer
    Returns:
        > nothing
*/
int list_vector_rem_elem_first(list_vector gv);

/*
Removes the element at the last position of the list vector
    Parameters:
        > list vector pointer
    Returns:
        > nothing
*/
int list_vector_rem_elem_last(list_vector gv);

/*
Removes the element at the given position of the list vector
    Parameters:
        > list vector pointer
        > index
    Returns:
        > nothing
*/
int list_vector_rem_elem_at(list_vector gv, int index);

#endif