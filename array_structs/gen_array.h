#ifndef GEN_array_H
#define GEN_array_H

//data type structure definition - generic array
/*
Stores elements in a array and allows all types of data manipualtion
*/
typedef struct _gen_array * gen_array;

//============================== Creation and Deletion Functions ================================
/*
Creates the generic array
    Parameters:
        > maximum capacity
    Returns:
        > generic array pointer
*/
gen_array gen_array_create(int max_capacity);

/*
Deletes the generic array
    Parameters:
        > generic array pointer
    Returns:
        > nothing
*/
void gen_array_delete(gen_array ga);

/*
Deletes the generic array and the elements stored in it
    Parameters:
        > generic array pointer
        > deletion function for the elements
    Returns:
        > nothing
*/
void gen_array_delete_all(gen_array ga, void (*delete_func)(void*));

//============================== State Functions ================================
/*
Obtains the maxium capacity of the generic array
    Parameters:
        > generic array pointer
    Returns:
        > maximum capacity
*/
int gen_array_max_cap(gen_array ga);

/*
Obtains the number of elements populationg the generic array
    Parameters:
        > generic array pointer
    Returns:
        > maximum capacity
*/
int gen_array_num_elems(gen_array ga);

/*
Returns true if the generic array is has zero elements
    Parameters:
        > generic array pointer
    Returns:
        > true or false (int)
*/
int gen_array_is_empty(gen_array ga);

/*
Returns true if the generic array is at full capacity
    Parameters:
        > generic array pointer
    Returns:
        > true or false (int)
*/
int gen_array_is_full(gen_array ga);

/*
Returns a new generic array with added maximum capacity
    Parameters:
        > generic array pointer
        > number of new slots
    Returns:
        > new generic array pointer
*/
gen_array gen_array_add_cap(gen_array ga, int more_capacity);

//============================== Obtain Element Funtions ================================
/*
Returns the element stored in first position of the generic array
    Parameters:
        > generic array pointer
    Returns:
        > element stored
*/
void* gen_array_get_elem_first(gen_array ga);

/*
Returns the element stored in last position of the generic array
    Parameters:
        > generic array pointer
    Returns:
        > element stored
*/
void* gen_array_get_elem_last(gen_array ga);

/*
Returns the element stored in given position of the generic array
    Parameters:
        > generic array pointer
        > index of the element
    Returns:
        > element stored
*/
void* gen_array_get_elem_at(gen_array ga, int index);

//============================== Add Element Functions ================================
/*
Adds the given element at the first position of the generic array
    Parameters:
        > generic array pointer
        > new element
    Returns:
        > success of the operation
*/
int gen_array_add_elem_first(gen_array ga, void* new_element);

/*
Adds the given element at the last position of the generic array
    Parameters:
        > generic array pointer
        > new element
    Returns:
        > success of the operation
*/
int gen_array_add_elem_last(gen_array ga, void* new_element);

/*
Adds the given element at the given position of the generic array
    Parameters:
        > generic array pointer
        > new element
    Returns:
        > success of the operation
*/
int gen_array_add_elem_at(gen_array ga, int index, void* new_element);

//============================== Remove Element Functions ================================
/*
Removes the element at the first position of the generic array
    Parameters:
        > generic array pointer
    Returns:
        > nothing
*/
int gen_array_rem_elem_first(gen_array ga);

/*
Removes the element at the last position of the generic array
    Parameters:
        > generic array pointer
    Returns:
        > nothing
*/
int gen_array_rem_elem_last(gen_array ga);

/*
Removes the element at the given position of the generic array
    Parameters:
        > generic array pointer
        > index
    Returns:
        > nothing
*/
int gen_array_rem_elem_at(gen_array ga, int index);

#endif //GEN_array_H