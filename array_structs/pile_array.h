#ifndef PILE_array_H
#define PILE_array_H

//data type structure definition - line array
/*
Stores elements in a array and only allows the insertion at the first position and the extraction at the first position
*/
typedef struct _pile_array * pile_array;

//============================== Creation and Deletion Functions ================================
/*
Creates the pile array
    Parameters:
        > maximum capacity
    Returns:
        > pile array pointer
*/
pile_array pile_array_create(int max_capacity);

/*
Deletes the pile array
    Parameters:
        > pile array pointer
    Returns:
        > nothing
*/
void pile_array_delete(pile_array ps);

/*
Deletes the pile array and the elements stored in it
    Parameters:
        > pile array pointer
        > deletion function for the elements
    Returns:
        > nothing
*/
void pile_array_delete_all(pile_array ps, void (*delete_func)(void*));

//============================== State Functions ================================
/*
Obtains the maxium capacity of the pile array
    Parameters:
        > pile array pointer
    Returns:
        > maximum capacity
*/
int pile_array_max_cap(pile_array ps);

/*
Obtains the number of elements populationg the pile array
    Parameters:
        > pile array pointer
    Returns:
        > maximum capacity
*/
int pile_array_num_elems(pile_array ps);

/*
Returns true if the pile array is has zero elements
    Parameters:
        > pile array pointer
    Returns:
        > true or false (int)
*/
int pile_array_is_empty(pile_array ps);

/*
Returns true if the pile array is at full capacity
    Parameters:
        > pile array pointer
    Returns:
        > true or false (int)
*/
int pile_array_is_full(pile_array ps);

/*
Returns a new pile array with added maximum capacity
    Parameters:
        > pile array pointer
        > number of new slots
    Returns:
        > new pile array pointer
*/
pile_array pile_array_add_cap(pile_array ps, int more_capacity);

//============================== Obtain Element Funtion ================================
/*
Returns the element stored in first position of the pile array
    Parameters:
        > pile array pointer
    Returns:
        > element stored
*/
void* pile_array_get_elem_first(pile_array ps);

//============================== Add Element Function ================================
/*
Adds the given element at the first position of the pile array
    Parameters:
        > pile array pointer
        > new element
    Returns:
        > success of the operation
*/
int pile_array_add_elem_first(pile_array ps, void* new_element);

//============================== Remove Element Function ================================
/*
Removes the element at the first position of the pile array
    Parameters:
        > pile array pointer
    Returns:
        > nothing
*/
int pile_array_rem_elem_first(pile_array ps);

#endif