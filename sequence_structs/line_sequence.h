#ifndef LINE_SEQUENCE_H
#define LINE_SEQUENCE_H

//data type structure definition - line sequence
/*
Stores elements in a array and only allows the insertion at the last position and the extraction at the first position
*/
typedef struct _line_sequence * line_sequence;

//============================== Creation and Deletion Functions ================================
/*
Creates the list sequence
    Parameters:
        > maximum capacity
    Returns:
        > generic list pointer
*/
line_sequence line_sequence_create(int max_capacity);

/*
Deletes the list sequence
    Parameters:
        > generic list pointer
    Returns:
        > nothing
*/
void line_sequence_delete(line_sequence ls);

/*
Deletes the list sequence and the elements stored in it
    Parameters:
        > generic list pointer
        > deletion function for the elements
    Returns:
        > nothing
*/
void line_sequence_delete_all(line_sequence ls, void (*delete_func)(void*));

//============================== State Functions ================================
/*
Obtains the maxium capacity of the list sequence
    Parameters:
        > list sequence pointer
    Returns:
        > maximum capacity
*/
int line_sequence_max_cap(line_sequence ls);

/*
Obtains the number of elements populationg the list sequence
    Parameters:
        > list sequence pointer
    Returns:
        > maximum capacity
*/
int line_sequence_num_elems(line_sequence ls);

/*
Returns true if the list sequence is has zero elements
    Parameters:
        > list sequence pointer
    Returns:
        > true or false (int)
*/
int line_sequence_is_empty(line_sequence ls);

/*
Returns true if the list sequence is at full capacity
    Parameters:
        > list sequence pointer
    Returns:
        > true or false (int)
*/
int line_sequence_is_full(line_sequence ls);

/*
Returns a new list sequence with added maximum capacity
    Parameters:
        > list sequence pointer
        > number of new slots
    Returns:
        > new list sequence pointer
*/
line_sequence line_sequence_add_cap(line_sequence ls, int more_capacity);

//============================== Obtain Element Funtion ================================
/*
Returns the element stored in first position of the list sequence
    Parameters:
        > list sequence pointer
    Returns:
        > element stored
*/
void* line_sequence_get_elem_first(line_sequence ls);

//============================== Add Element Function ================================
/*
Adds the given element at the last position of the list sequence
    Parameters:
        > list sequence pointer
        > new element
    Returns:
        > success of the operation
*/
int line_sequence_add_elem_last(line_sequence ls, void* new_element);

//============================== Remove Element Function ================================
/*
Removes the element at the first position of the list sequence
    Parameters:
        > list sequence pointer
    Returns:
        > nothing
*/
int line_sequence_rem_elem_first(line_sequence ls);

#endif