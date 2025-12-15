#ifndef TEST_ADT_H_
#define TEST_ADT_H_

typedef struct _test_adt * test_adt;

test_adt test_adt_create(int data);

void test_adt_delete(test_adt t);

void test_adt_delete_gen(void* t);

int test_adt_get_data(test_adt t);

#endif