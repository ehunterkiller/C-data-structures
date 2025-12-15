#ifndef LIST_array_H
#define LIST_array_H

//data type structure definition - list array
/*
Stores elements in a array and only allows the insertion at the last position
*/
typedef struct _list_array * list_array;

//============================== Creation and Deletion Functions ================================
/*
Creates the list array
    Parameters:
        > maximum capacity
    Returns:
        > generic list pointer
*/
list_array list_array_create(int max_capacity);

/*
Deletes the list array
    Parameters:
        > generic list pointer
    Returns:
        > nothing
*/
void list_array_delete(list_array la);

/*
Deletes the list array and the elements stored in it
    Parameters:
        > generic list pointer
        > deletion function for the elements
    Returns:
        > nothing
*/
void list_array_delete_all(list_array la, void (*delete_func)(void*));

//============================== State Functions ================================
/*
Obtains the maxium capacity of the list array
    Parameters:
        > list array pointer
    Returns:
        > maximum capacity
*/
int list_array_max_cap(list_array la);

/*
Obtains the number of elements populationg the list array
    Parameters:
        > list array pointer
    Returns:
        > maximum capacity
*/
int list_array_num_elems(list_array la);

/*
Returns true if the list array is has zero elements
    Parameters:
        > list array pointer
    Returns:
        > true or false (int)
*/
int list_array_is_empty(list_array la);

/*
Returns true if the list array is at full capacity
    Parameters:
        > list array pointer
    Returns:
        > true or false (int)
*/
int list_array_is_full(list_array la);

/*
Returns a new list array with added maximum capacity
    Parameters:
        > list array pointer
        > number of new slots
    Returns:
        > new list array pointer
*/
list_array list_array_add_cap(list_array la, int more_capacity);

//============================== Obtain Element Funtions ================================
/*
Returns the element stored in first position of the list array
    Parameters:
        > list array pointer
    Returns:
        > element stored
*/
void* list_array_get_elem_first(list_array la);

/*
Returns the element stored in last position of the list array
    Parameters:
        > list array pointer
    Returns:
        > element stored
*/
void* list_array_get_elem_last(list_array la);

/*
Returns the element stored in given position of the list array
    Parameters:
        > list array pointer
        > index of the element
    Returns:
        > element stored
*/
void* list_array_get_elem_at(list_array la, int index);

//============================== Add Element Function ================================
/*
Adds the given element at the last position of the list array
    Parameters:
        > list array pointer
        > new element
    Returns:
        > success of the operation
*/
int list_array_add_elem(list_array la, void* new_element);

//============================== Remove Element Functions ================================
/*
Removes the element at the first position of the list array
    Parameters:
        > list array pointer
    Returns:
        > nothing
*/
int list_array_rem_elem_first(list_array la);

/*
Removes the element at the last position of the list array
    Parameters:
        > list array pointer
    Returns:
        > nothing
*/
int list_array_rem_elem_last(list_array la);

/*
Removes the element at the given position of the list array
    Parameters:
        > list array pointer
        > index
    Returns:
        > nothing
*/
int list_array_rem_elem_at(list_array la, int index);

#endif