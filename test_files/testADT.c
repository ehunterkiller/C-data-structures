#include "testADT.h"
#include <stdlib.h>

struct _test_adt {
   int data;
};


test_adt test_adt_create(int data){
    test_adt t = (test_adt)malloc(sizeof(struct _test_adt));

    if(t == NULL){
        return NULL;
    }

    t->data = data;

    return t;
}

void test_adt_delete(test_adt t){
    free(t);
}

void test_adt_delete_gen(void* t){
    test_adt_delete((test_adt)t);
}

int test_adt_get_data(test_adt t){
    return t->data;
}