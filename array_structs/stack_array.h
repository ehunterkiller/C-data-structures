#ifndef STACK_ARRAY_H
#define STACK_ARRAY_H

//data type structure definition - line array
/*
Stores elements in a array and only allows the insertion at the first position and the extraction at the first position
*/
typedef struct _stack_array * stack_array;

//============================== Creation and Deletion Functions ================================
/*
Creates the stack array
    Parameters:
        > maximum capacity
    Returns:
        > stack array pointer
*/
stack_array stack_array_create(int max_capacity);

/*
Deletes the stack array
    Parameters:
        > stack array pointer
    Returns:
        > nothing
*/
void stack_array_delete(stack_array pa);

/*
Deletes the stack array and the elements stored in it
    Parameters:
        > stack array pointer
        > deletion function for the elements
    Returns:
        > nothing
*/
void stack_array_delete_all(stack_array pa, void (*delete_func)(void*));

//============================== State Functions ================================
/*
Obtains the maxium capacity of the stack array
    Parameters:
        > stack array pointer
    Returns:
        > maximum capacity
*/
int stack_array_max_cap(stack_array pa);

/*
Obtains the number of elements populationg the stack array
    Parameters:
        > stack array pointer
    Returns:
        > maximum capacity
*/
int stack_array_num_elems(stack_array pa);

/*
Returns true if the stack array is has zero elements
    Parameters:
        > stack array pointer
    Returns:
        > true or false (int)
*/
int stack_array_is_empty(stack_array pa);

/*
Returns true if the stack array is at full capacity
    Parameters:
        > stack array pointer
    Returns:
        > true or false (int)
*/
int stack_array_is_full(stack_array pa);

/*
Returns a new stack array with added maximum capacity
    Parameters:
        > stack array pointer
        > number of new slots
    Returns:
        > new stack array pointer
*/
stack_array stack_array_add_cap(stack_array pa, int more_capacity);

//============================== Obtain Element Funtions ================================
/*
Returns the element stored in first position of the stack array
    Parameters:
        > stack array pointer
    Returns:
        > element stored
*/
void* stack_array_get_elem_first(stack_array pa);

/*
Returns the element stored in last position of the stack array
    Parameters:
        > stack array pointer
    Returns:
        > element stored
*/
void* stack_array_get_elem_last(stack_array pa);

/*
Returns the element stored in given position of the stack array
    Parameters:
        > stack array pointer
        > index of the element
    Returns:
        > element stored
*/
void* stack_array_get_elem_at(stack_array pa, int index);

//============================== Add Element Function ================================
/*
Adds the given element at the first position of the stack array
    Parameters:
        > stack array pointer
        > new element
    Returns:
        > success of the operation
*/
int stack_array_add_elem(stack_array pa, void* new_element);

//============================== Remove Element Function ================================
/*
Removes the element at the first position of the stack array
    Parameters:
        > stack array pointer
    Returns:
        > nothing
*/
int stack_array_rem_elem(stack_array pa);

#endif