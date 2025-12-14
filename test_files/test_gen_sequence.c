#include <stdio.h>
#include <stdlib.h>
#include "../sequence_structs/gen_sequence.h"
#include "testADT.h"

int main(){
    printf("test begin\n");

    //create a generic sequence
    printf("creating generic sequence data structure\n");

    gen_sequence gs = gen_sequence_create(5);
    if(gs == NULL){
        printf("something went wrong when creating generic sequence, returned NULL\n");
        return 1;
    }
    else{
        printf("generic sequence created\n");
    }

    //test if empty
    if(gen_sequence_is_empty(gs)){
        printf("generic sequence is empty\n");
    }
    else{
        printf("generic sequence is NOT empty\n");
    }
    
    //fill it with test elements
    printf("adding elements\n");

    test_adt t1 = test_adt_create(1);
    test_adt t2 = test_adt_create(2);
    test_adt t3 = test_adt_create(3);

    //first
    printf("added element at first\n");
    gen_sequence_add_elem_first(gs,t1);
    
    //last
    printf("added element at last\n");
    gen_sequence_add_elem_last(gs,t3);

    //midle
    printf("added element at index 1\n");
    gen_sequence_add_elem_at(gs,1,t2);

    printf("elements added\n");

    //test some parameters
    if(gen_sequence_is_full(gs)){
        printf("generic sequence is FULL\n");
    }
    else{
        printf("generic sequence has space\n");
    }

    int max_cap = gen_sequence_max_cap(gs);
    printf("generic sequence maximum capacity is %d\n",max_cap);

    int num_elems = gen_sequence_num_elems(gs);
    printf("number of elements stored in generic is %d\n",num_elems);

    //iterate
    printf("iteration begin:\n");
    for(int i = 0; i < num_elems; i++){
        test_adt t = (test_adt) gen_sequence_get_elem_at(gs,i);
        int data = test_adt_get_data(t);
        printf("element at %d is %d\n",i,data);
    }
    printf("iteration complete\n");

    //remove element
    printf("removing element at index 1\n");
    gen_sequence_rem_elem_at(gs,1);

    num_elems = gen_sequence_num_elems(gs);
    printf("number of elements stored in generic is %d\n",num_elems);

    printf("iteration begin:\n");
    for(int i = 0; i < num_elems; i++){
        test_adt t = (test_adt) gen_sequence_get_elem_at(gs,i);
        int data = test_adt_get_data(t);
        printf("element at %d is %d\n",i,data);
    }
    printf("iteration complete\n");

    //delete
    printf("deleting generic sequence and all elements\n");
    gen_sequence_delete_all(gs,test_adt_delete_gen);

    //test complete
    printf("test completed\nprogram ended\n");
    return 0;
}