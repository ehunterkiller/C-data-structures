#ifndef GEN_SEQUENCE_H
#define GEN_SEQUENCE_H

//data type structure definition - generic sequence
typedef struct _gen_sequence * gen_sequence;

/*
Creates the generic sequence
    Parameters:
        > maximum capacity
    Returns:
        > generic sequence pointer
*/
gen_sequence gen_sequence_create(int max_capacity);

/*
Deletes the generic sequence
    Parameters:
        > generic sequence pointer
    Returns:
        > nothing
*/
void gen_sequence_delete(gen_sequence gs);

/*
Deletes the generic sequence and the elements stored in it
    Parameters:
        > generic sequence pointer
        > deletion function for the elements
    Returns:
        > nothing
*/
void gen_sequence_delete_all(gen_sequence gs, void (*delete_func)(void*));

/*
Obtains the maxium capacity of the generic sequence
    Parameters:
        > generic sequence pointer
    Returns:
        > maximum capacity
*/
int gen_sequence_max_cap(gen_sequence gs);

/*
Obtains the number of elements populationg the generic sequence
    Parameters:
        > generic sequence pointer
    Returns:
        > maximum capacity
*/
int gen_sequence_num_elems(gen_sequence gs);

/*
Returns true if the generic sequence is has zero elements
    Parameters:
        > generic sequence pointer
    Returns:
        > true or false (int)
*/
int gen_sequence_is_empty(gen_sequence gs);

/*
Returns true if the generic sequence is at full capacity
    Parameters:
        > generic sequence pointer
    Returns:
        > true or false (int)
*/
int gen_sequence_is_full(gen_sequence gs);

/*
Returns the element stored in first position of the generic sequence
    Parameters:
        > generic sequence pointer
    Returns:
        > element stored
*/
void* gen_sequence_get_elem_first(gen_sequence gs);

/*
Returns the element stored in last position of the generic sequence
    Parameters:
        > generic sequence pointer
    Returns:
        > element stored
*/
void* gen_sequence_get_elem_last(gen_sequence gs);

/*
Returns the element stored in given position of the generic sequence
    Parameters:
        > generic sequence pointer
        > index of the element
    Returns:
        > element stored
*/
void* gen_sequence_get_elem_at(gen_sequence gs, int index);

/*
Adds the given element at the first position of the generic sequence
    Parameters:
        > generic sequence pointer
        > new element
    Returns:
        > nothing
*/
void gen_sequence_add_elem_first(gen_sequence gs, void* new_element);

/*
Adds the given element at the last position of the generic sequence
    Parameters:
        > generic sequence pointer
        > new element
    Returns:
        > nothing
*/
void gen_sequence_add_elem_last(gen_sequence gs, void* new_element);

/*
Adds the given element at the given position of the generic sequence
    Parameters:
        > generic sequence pointer
        > new element
    Returns:
        > nothing
*/
void gen_sequence_add_elem_at(gen_sequence gs, int index, void* new_element);

/*
Removes the element at the first position of the generic sequence
    Parameters:
        > generic sequence pointer
    Returns:
        > nothing
*/
void gen_sequence_rem_elem_first(gen_sequence gs);

/*
Removes the element at the last position of the generic sequence
    Parameters:
        > generic sequence pointer
    Returns:
        > nothing
*/
void gen_sequence_rem_elem_last(gen_sequence gs);

/*
Removes the element at the given position of the generic sequence
    Parameters:
        > generic sequence pointer
        > index
    Returns:
        > nothing
*/
void gen_sequence_rem_elem_at(gen_sequence gs, int index);

#endif //GEN_SEQUENCE_H