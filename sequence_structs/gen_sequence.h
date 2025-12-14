#ifndef GEN_SEQUENCE_H
#define GEN_SEQUENCE_H

typedef struct _gen_sequence * gen_sequence;

gen_sequence gen_sequence_create(int max_capacity);

void gen_sequence_delete(gen_sequence gs);

void gen_sequence_delete_all(gen_sequence gs, void (*delete_func)(void*));

int gen_sequence_max_cap(gen_sequence gs);

int gen_sequence_num_elems(gen_sequence gs);

int gen_sequence_is_empty(gen_sequence gs);

void* gen_sequence_get_elem_first(gen_sequence gs);

void* gen_sequence_get_elem_last(gen_sequence gs);

void* gen_sequence_get_elem_at(gen_sequence gs, int index);

void gen_sequence_add_elem_first(gen_sequence gs, void* new_element);

void gen_sequence_add_elem_last(gen_sequence gs, void* new_element);

void gen_sequence_add_elem_at(gen_sequence gs, int index, void* new_element);

void gen_sequence_rem_elem_first(gen_sequence gs);

void gen_sequence_rem_elem_last(gen_sequence gs);

void gen_sequence_rem_elem_at(gen_sequence gs, int index);

#endif //GEN_SEQUENCE_H