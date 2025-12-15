#ifndef PILE_SEQUENCE_H
#define PILE_SEQUENCE_H

//data type structure definition - line sequence
/*
Stores elements in a array and only allows the insertion at the first position and the extraction at the first position
*/
typedef struct _pile_sequence * pile_sequence;

//============================== Creation and Deletion Functions ================================
/*
Creates the pile sequence
    Parameters:
        > maximum capacity
    Returns:
        > pile sequence pointer
*/
pile_sequence pile_sequence_create(int max_capacity);

/*
Deletes the pile sequence
    Parameters:
        > pile sequence pointer
    Returns:
        > nothing
*/
void pile_sequence_delete(pile_sequence ps);

/*
Deletes the pile sequence and the elements stored in it
    Parameters:
        > pile sequence pointer
        > deletion function for the elements
    Returns:
        > nothing
*/
void pile_sequence_delete_all(pile_sequence ps, void (*delete_func)(void*));

//============================== State Functions ================================
/*
Obtains the maxium capacity of the pile sequence
    Parameters:
        > pile sequence pointer
    Returns:
        > maximum capacity
*/
int pile_sequence_max_cap(pile_sequence ps);

/*
Obtains the number of elements populationg the pile sequence
    Parameters:
        > pile sequence pointer
    Returns:
        > maximum capacity
*/
int pile_sequence_num_elems(pile_sequence ps);

/*
Returns true if the pile sequence is has zero elements
    Parameters:
        > pile sequence pointer
    Returns:
        > true or false (int)
*/
int pile_sequence_is_empty(pile_sequence ps);

/*
Returns true if the pile sequence is at full capacity
    Parameters:
        > pile sequence pointer
    Returns:
        > true or false (int)
*/
int pile_sequence_is_full(pile_sequence ps);

/*
Returns a new pile sequence with added maximum capacity
    Parameters:
        > pile sequence pointer
        > number of new slots
    Returns:
        > new pile sequence pointer
*/
pile_sequence pile_sequence_add_cap(pile_sequence ps, int more_capacity);

//============================== Obtain Element Funtion ================================
/*
Returns the element stored in first position of the pile sequence
    Parameters:
        > pile sequence pointer
    Returns:
        > element stored
*/
void* pile_sequence_get_elem_first(pile_sequence ps);

//============================== Add Element Function ================================
/*
Adds the given element at the first position of the pile sequence
    Parameters:
        > pile sequence pointer
        > new element
    Returns:
        > success of the operation
*/
int pile_sequence_add_elem_first(pile_sequence ps, void* new_element);

//============================== Remove Element Function ================================
/*
Removes the element at the first position of the pile sequence
    Parameters:
        > pile sequence pointer
    Returns:
        > nothing
*/
int pile_sequence_rem_elem_first(pile_sequence ps);

#endif