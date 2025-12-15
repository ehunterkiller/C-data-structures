#ifndef LIST_SEQUENCE_H
#define LIST_SEQUENCE_H

//data type structure definition - list sequence
/*
Stores elements in a array and only allows the insertion at the last position
*/
typedef struct _list_sequence * list_sequence;

//============================== Creation and Deletion Functions ================================
/*
Creates the list sequence
    Parameters:
        > maximum capacity
    Returns:
        > generic list pointer
*/
list_sequence list_sequence_create(int max_capacity);

/*
Deletes the list sequence
    Parameters:
        > generic list pointer
    Returns:
        > nothing
*/
void list_sequence_delete(list_sequence ls);

/*
Deletes the list sequence and the elements stored in it
    Parameters:
        > generic list pointer
        > deletion function for the elements
    Returns:
        > nothing
*/
void list_sequence_delete_all(list_sequence ls, void (*delete_func)(void*));

//============================== State Functions ================================
/*
Obtains the maxium capacity of the list sequence
    Parameters:
        > list sequence pointer
    Returns:
        > maximum capacity
*/
int list_sequence_max_cap(list_sequence ls);

/*
Obtains the number of elements populationg the list sequence
    Parameters:
        > list sequence pointer
    Returns:
        > maximum capacity
*/
int list_sequence_num_elems(list_sequence ls);

/*
Returns true if the list sequence is has zero elements
    Parameters:
        > list sequence pointer
    Returns:
        > true or false (int)
*/
int list_sequence_is_empty(list_sequence ls);

/*
Returns true if the list sequence is at full capacity
    Parameters:
        > list sequence pointer
    Returns:
        > true or false (int)
*/
int list_sequence_is_full(list_sequence ls);

/*
Returns a new list sequence with added maximum capacity
    Parameters:
        > list sequence pointer
        > number of new slots
    Returns:
        > new list sequence pointer
*/
list_sequence list_sequence_add_cap(list_sequence ls, int more_capacity);

//============================== Obtain Element Funtions ================================
/*
Returns the element stored in first position of the list sequence
    Parameters:
        > list sequence pointer
    Returns:
        > element stored
*/
void* list_sequence_get_elem_first(list_sequence ls);

/*
Returns the element stored in last position of the list sequence
    Parameters:
        > list sequence pointer
    Returns:
        > element stored
*/
void* list_sequence_get_elem_last(list_sequence ls);

/*
Returns the element stored in given position of the list sequence
    Parameters:
        > list sequence pointer
        > index of the element
    Returns:
        > element stored
*/
void* list_sequence_get_elem_at(list_sequence ls, int index);

//============================== Add Element Function ================================
/*
Adds the given element at the last position of the list sequence
    Parameters:
        > list sequence pointer
        > new element
    Returns:
        > success of the operation
*/
int list_sequence_add_elem_last(list_sequence ls, void* new_element);

//============================== Remove Element Functions ================================
/*
Removes the element at the first position of the list sequence
    Parameters:
        > list sequence pointer
    Returns:
        > nothing
*/
int list_sequence_rem_elem_first(list_sequence ls);

/*
Removes the element at the last position of the list sequence
    Parameters:
        > list sequence pointer
    Returns:
        > nothing
*/
int list_sequence_rem_elem_last(list_sequence ls);

/*
Removes the element at the given position of the list sequence
    Parameters:
        > list sequence pointer
        > index
    Returns:
        > nothing
*/
int list_sequence_rem_elem_at(list_sequence ls, int index);

#endif