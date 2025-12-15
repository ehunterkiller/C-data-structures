#include <stdio.h>
#include <stdlib.h>
#include "../array_structs/gen_array.h"
#include "test_data_type/testADT.h"

int main(){
    printf("test begin\n");

    //create a generic array
    printf("creating generic array data structure\n");

    gen_array gs = gen_array_create(5);
    if(gs == NULL){
        printf("something went wrong when creating generic array, returned NULL\n");
        return 1;
    }
    else{
        printf("generic array created\n");
    }

    //test if empty
    if(gen_array_is_empty(gs)){
        printf("generic array is empty\n");
    }
    else{
        printf("generic array is NOT empty\n");
    }
    
    //fill it with test elements
    printf("adding elements\n");

    test_adt t1 = test_adt_create(1);
    test_adt t2 = test_adt_create(2);
    test_adt t3 = test_adt_create(3);

    //first
    printf("added element at first\n");
    gen_array_add_elem_first(gs,t1);
    
    //last
    printf("added element at last\n");
    gen_array_add_elem_last(gs,t3);

    //midle
    printf("added element at index 1\n");
    gen_array_add_elem_at(gs,1,t2);

    printf("elements added\n");

    //test some parameters
    if(gen_array_is_full(gs)){
        printf("generic array is FULL\n");
    }
    else{
        printf("generic array has space\n");
    }

    int max_cap = gen_array_max_cap(gs);
    printf("generic array maximum capacity is %d\n",max_cap);

    int num_elems = gen_array_num_elems(gs);
    printf("number of elements stored in generic is %d\n",num_elems);

    //iterate
    printf("iteration begin:\n");
    for(int i = 0; i < num_elems; i++){
        test_adt t = (test_adt) gen_array_get_elem_at(gs,i);
        int data = test_adt_get_data(t);
        printf("element at %d is %d\n",i,data);
    }
    printf("iteration complete\n");

    //remove element
    printf("removing element at index 1\n");
    gen_array_rem_elem_at(gs,1);

    num_elems = gen_array_num_elems(gs);
    printf("number of elements stored in generic is %d\n",num_elems);

    printf("iteration begin:\n");
    for(int i = 0; i < num_elems; i++){
        test_adt t = (test_adt) gen_array_get_elem_at(gs,i);
        int data = test_adt_get_data(t);
        printf("element at %d is %d\n",i,data);
    }
    printf("iteration complete\n");

    //resize
    printf("adding more capacity to the generic array\n");
    gen_array new_gs = gen_array_add_cap(gs,3);
    if(new_gs == NULL){
        printf("something went wrong when resizing the generic array\n");
    }
    else{
        printf("generic array resized\n");
        gs = new_gs;

        max_cap = gen_array_max_cap(gs);
        printf("generic array maximum capacity is %d\n",max_cap);

        printf("iteration begin:\n");
        for(int i = 0; i < num_elems; i++){
            test_adt t = (test_adt) gen_array_get_elem_at(gs,i);
            int data = test_adt_get_data(t);
            printf("element at %d is %d\n",i,data);
        }
        printf("iteration complete\n");
    }

    //delete
    printf("deleting generic array and all elements\n");
    gen_array_delete_all(gs,test_adt_delete_gen);

    //test complete
    printf("test completed\nprogram ended\n");
    return 0;
}