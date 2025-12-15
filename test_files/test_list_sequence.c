#include <stdio.h>
#include <stdlib.h>
#include "../sequence_structs/list_sequence.h"
#include "test_data_type/testADT.h"

int main(){
    printf("test begin\n");

    //create a generic sequence
    printf("creating generic sequence data structure\n");

    list_sequence ls = list_sequence_create(5);
    if(ls == NULL){
        printf("something went wrong when creating generic sequence, returned NULL\n");
        return 1;
    }
    else{
        printf("generic sequence created\n");
    }

    //test if empty
    if(list_sequence_is_empty(ls)){
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
    
    //last
    printf("added elements at last\n");
    list_sequence_add_elem_last(ls,t1);
    list_sequence_add_elem_last(ls,t2);
    list_sequence_add_elem_last(ls,t3);

    printf("elements added\n");

    //test some parameters
    if(list_sequence_is_full(ls)){
        printf("generic sequence is FULL\n");
    }
    else{
        printf("generic sequence has space\n");
    }

    int max_cap = list_sequence_max_cap(ls);
    printf("generic sequence maximum capacity is %d\n",max_cap);

    int num_elems = list_sequence_num_elems(ls);
    printf("number of elements stored in generic is %d\n",num_elems);

    //iterate
    printf("iteration begin:\n");
    for(int i = 0; i < num_elems; i++){
        test_adt t = (test_adt) list_sequence_get_elem_at(ls,i);
        int data = test_adt_get_data(t);
        printf("element at %d is %d\n",i,data);
    }
    printf("iteration complete\n");

    //remove element
    printf("removing element at index 1\n");
    list_sequence_rem_elem_at(ls,1);

    num_elems = list_sequence_num_elems(ls);
    printf("number of elements stored in generic is %d\n",num_elems);

    printf("iteration begin:\n");
    for(int i = 0; i < num_elems; i++){
        test_adt t = (test_adt) list_sequence_get_elem_at(ls,i);
        int data = test_adt_get_data(t);
        printf("element at %d is %d\n",i,data);
    }
    printf("iteration complete\n");

    //resize
    printf("adding more capacity to the generic sequence\n");
    list_sequence new_ls = list_sequence_add_cap(ls,3);
    if(new_ls == NULL){
        printf("something went wrong when resizing the generic sequence\n");
    }
    else{
        printf("generic sequence resized\n");
        ls = new_ls;

        max_cap = list_sequence_max_cap(ls);
        printf("generic sequence maximum capacity is %d\n",max_cap);

        printf("iteration begin:\n");
        for(int i = 0; i < num_elems; i++){
            test_adt t = (test_adt) list_sequence_get_elem_at(ls,i);
            int data = test_adt_get_data(t);
            printf("element at %d is %d\n",i,data);
        }
        printf("iteration complete\n");
    }

    //delete
    printf("deleting generic sequence and all elements\n");
    list_sequence_delete_all(ls,test_adt_delete_gen);

    //test complete
    printf("test completed\nprogram ended\n");
    return 0;
}