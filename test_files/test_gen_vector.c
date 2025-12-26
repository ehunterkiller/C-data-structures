#include <stdio.h>
#include <stdlib.h>
#include "../vector_structs/gen_vector.h"
#include "test_data_type/testADT.h"

int main(){
    printf("test begin\n");

    //create a generic vector
    printf("creating generic vector data structure\n");

    gen_vector gv = gen_vector_create(5,5);
    if(gv == NULL){
        printf("something went wrong when creating generic vector, returned NULL\n");
        return 1;
    }
    else{
        printf("generic vector created\n");
    }

    //test if empty
    if(gen_vector_is_empty(gv)){
        printf("generic vector is empty\n");
    }
    else{
        printf("generic vector is NOT empty\n");
    }
    
    //fill it with test elements
    printf("adding elements\n");

    test_adt t1 = test_adt_create(1);
    test_adt t2 = test_adt_create(2);
    test_adt t3 = test_adt_create(3);

    //first
    printf("added element at first\n");
    gen_vector_add_elem_first(gv,t1);
    
    //last
    printf("added element at last\n");
    gen_vector_add_elem_last(gv,t3);

    //midle
    printf("added element at index 1\n");
    gen_vector_add_elem_at(gv,1,t2);

    printf("elements added\n");

    //test some parameters
    if(gen_vector_is_full(gv)){
        printf("generic vector is FULL\n");
    }
    else{
        printf("generic vector has space\n");
    }

    int max_cap = gen_vector_max_cap(gv);
    printf("generic vector maximum capacity is %d\n",max_cap);

    int num_elems = gen_vector_num_elems(gv);
    printf("number of elements stored in generic is %d\n",num_elems);

    int resize_factor = gen_vector_resize_factor(gv);
    printf("resize factor is %d\n",resize_factor);

    //iterate
    printf("iteration begin:\n");
    for(int i = 0; i < num_elems; i++){
        test_adt t = (test_adt) gen_vector_get_elem_at(gv,i);
        int data = test_adt_get_data(t);
        printf("element at %d is %d\n",i,data);
    }
    printf("iteration complete\n");

    //remove element
    printf("removing element at index 1\n");
    gen_vector_rem_elem_at(gv,1);

    num_elems = gen_vector_num_elems(gv);
    printf("number of elements stored in generic is %d\n",num_elems);

    printf("iteration begin:\n");
    for(int i = 0; i < num_elems; i++){
        test_adt t = (test_adt) gen_vector_get_elem_at(gv,i);
        int data = test_adt_get_data(t);
        printf("element at %d is %d\n",i,data);
    }
    printf("iteration complete\n");

    //auto resize
    printf("adding more elements (auto resize test)\n");

    test_adt t4 = test_adt_create(4);
    test_adt t5 = test_adt_create(5);
    test_adt t6 = test_adt_create(6);

    gen_vector_add_elem_at(gv,1,t2);
    gen_vector_add_elem_last(gv,t4);
    gen_vector_add_elem_last(gv,t5);
    gen_vector_add_elem_last(gv,t6);

    max_cap = gen_vector_max_cap(gv);
    printf("generic vector maximum capacity is %d\n",max_cap);

    num_elems = gen_vector_num_elems(gv);
    printf("number of elements stored in generic is %d\n",num_elems);
    
    printf("iteration begin:\n");
    for(int i = 0; i < num_elems; i++){
        test_adt t = (test_adt) gen_vector_get_elem_at(gv,i);
        int data = test_adt_get_data(t);
        printf("element at %d is %d\n",i,data);
    }
    printf("iteration complete\n");

    //delete
    printf("deleting generic vector and all elements\n");
    gen_vector_delete_all(gv,test_adt_delete_gen);

    //test complete
    printf("test completed\nprogram ended\n");
    return 0;
}