#ifndef LINE_VECTOR_H
#define LINE_VECTOR_H

//data type structure definition - line vector
/*
Stores elements in a vector and only allows the insertion at the last position and the extraction at the first position
*/
typedef struct _line_vector * line_vector;

//============================== Creation and Deletion Functions ================================
/*
Creates the line vector
    Parameters:
        > initial maximum capacity
        > resizing factor
    Returns:
        > line vector pointer
*/
line_vector line_vector_create(int max_capacity, int resize_factor);

/*
Deletes the line vector
    Parameters:
        > line vector pointer
    Returns:
        > nothing
*/
void line_vector_delete(line_vector gv);

/*
Deletes the line vector and the elements stored in it
    Parameters:
        > line vector pointer
        > deletion function for the elements
    Returns:
        > nothing
*/
void line_vector_delete_all(line_vector gv, void (*delete_func)(void*));

//============================== State Functions ================================
/*
Obtains the maxium capacity of the line vector
    Parameters:
        > line vector pointer
    Returns:
        > maximum capacity
*/
int line_vector_max_cap(line_vector gv);

/*
Obtains the number of elements populationg the line vector
    Parameters:
        > line vector pointer
    Returns:
        > maximum capacity
*/
int line_vector_num_elems(line_vector gv);

/*
Returns true if the line vector is has zero elements
    Parameters:
        > line vector pointer
    Returns:
        > true or false (int)
*/
int line_vector_is_empty(line_vector gv);

/*
Returns true if the line vector is at full capacity
    Parameters:
        > line vector pointer
    Returns:
        > true or false (int)
*/
int line_vector_is_full(line_vector gv);

/*
Resizes the line vector with added maximum capacity
    Parameters:
        > line vector pointer
        > number of new slots
    Returns:
        > true or false (int)
*/
int line_vector_add_cap(line_vector gv, int more_capacity);

//============================== Dynamic Resize Functions ================================
/*
Returns the resize factor of the line vector
    Parameters:
        > line vector pointer
    Returns:
        > resize factor
*/
int line_vector_resize_factor(line_vector gv);

/*
Changes the resize factor of the line vector
    Parameters:
        > line vector pointer
        > new resize factor
    Returns:
        > nothing
*/
void line_vector_change_resize_factor(line_vector gv, int new_resize_factor);

//============================== Obtain Element Funtions ================================
/*
Returns the element stored in first position of the line vector
    Parameters:
        > line vector pointer
    Returns:
        > element stored
*/
void* line_vector_get_elem_first(line_vector gv);

/*
Returns the element stored in last position of the line vector
    Parameters:
        > line vector pointer
    Returns:
        > element stored
*/
void* line_vector_get_elem_last(line_vector gv);

/*
Returns the element stored in given position of the line vector
    Parameters:
        > line vector pointer
        > index of the element
    Returns:
        > element stored
*/
void* line_vector_get_elem_at(line_vector gv, int index);

//============================== Add Element Functions ================================
/*
Adds the given element at the last position of the line vector
    Parameters:
        > line vector pointer
        > new element
    Returns:
        > success of the operation
*/
int line_vector_add_elem(line_vector gv, void* new_element);

//============================== Remove Element Functions ================================
/*
Removes the element at the first position of the line vector
    Parameters:
        > line vector pointer
    Returns:
        > nothing
*/
int line_vector_rem_elem(line_vector gv);

#endif