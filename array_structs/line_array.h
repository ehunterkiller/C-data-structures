#ifndef LINE_array_H
#define LINE_array_H

//data type structure definition - line array
/*
Stores elements in a array and only allows the insertion at the last position and the extraction at the first position
*/
typedef struct _line_array * line_array;

//============================== Creation and Deletion Functions ================================
/*
Creates the list array
    Parameters:
        > maximum capacity
    Returns:
        > generic list pointer
*/
line_array line_array_create(int max_capacity);

/*
Deletes the list array
    Parameters:
        > generic list pointer
    Returns:
        > nothing
*/
void line_array_delete(line_array ls);

/*
Deletes the list array and the elements stored in it
    Parameters:
        > generic list pointer
        > deletion function for the elements
    Returns:
        > nothing
*/
void line_array_delete_all(line_array ls, void (*delete_func)(void*));

//============================== State Functions ================================
/*
Obtains the maxium capacity of the list array
    Parameters:
        > list array pointer
    Returns:
        > maximum capacity
*/
int line_array_max_cap(line_array ls);

/*
Obtains the number of elements populationg the list array
    Parameters:
        > list array pointer
    Returns:
        > maximum capacity
*/
int line_array_num_elems(line_array ls);

/*
Returns true if the list array is has zero elements
    Parameters:
        > list array pointer
    Returns:
        > true or false (int)
*/
int line_array_is_empty(line_array ls);

/*
Returns true if the list array is at full capacity
    Parameters:
        > list array pointer
    Returns:
        > true or false (int)
*/
int line_array_is_full(line_array ls);

/*
Returns a new list array with added maximum capacity
    Parameters:
        > list array pointer
        > number of new slots
    Returns:
        > new list array pointer
*/
line_array line_array_add_cap(line_array ls, int more_capacity);

//============================== Obtain Element Funtion ================================
/*
Returns the element stored in first position of the list array
    Parameters:
        > list array pointer
    Returns:
        > element stored
*/
void* line_array_get_elem_first(line_array ls);

//============================== Add Element Function ================================
/*
Adds the given element at the last position of the list array
    Parameters:
        > list array pointer
        > new element
    Returns:
        > success of the operation
*/
int line_array_add_elem_last(line_array ls, void* new_element);

//============================== Remove Element Function ================================
/*
Removes the element at the first position of the list array
    Parameters:
        > list array pointer
    Returns:
        > nothing
*/
int line_array_rem_elem_first(line_array ls);

#endif