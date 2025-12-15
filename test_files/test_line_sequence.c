#include <stdio.h>
#include <stdlib.h>
#include "../sequence_structs/line_sequence.h"
#include "test_data_type/testADT.h"

int main(){
    printf("test begin\n");

    //create a generic sequence
    printf("creating generic sequence data structure\n");

    line_sequence ls = line_sequence_create(5);
    if(ls == NULL){
        printf("something went wrong when creating generic sequence, returned NULL\n");
        return 1;
    }
    else{
        printf("generic sequence created\n");
    }

    //test if empty
    if(line_sequence_is_empty(ls)){
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
    line_sequence_add_elem_last(ls,t1);
    line_sequence_add_elem_last(ls,t2);
    line_sequence_add_elem_last(ls,t3);

    printf("elements added\n");

    //test some parameters
    if(line_sequence_is_full(ls)){
        printf("generic sequence is FULL\n");
    }
    else{
        printf("generic sequence has space\n");
    }

    int max_cap = line_sequence_max_cap(ls);
    printf("generic sequence maximum capacity is %d\n",max_cap);

    int num_elems = line_sequence_num_elems(ls);
    printf("number of elements stored in generic is %d\n",num_elems);

    test_adt t = (test_adt) line_sequence_get_elem_first(ls);
    int data = test_adt_get_data(t);
    printf("first element is %d\n",data);

    //remove element
    printf("removing first element\n");
    line_sequence_rem_elem_first(ls);

    num_elems = line_sequence_num_elems(ls);
    printf("number of elements stored in generic is %d\n",num_elems);

    t = (test_adt) line_sequence_get_elem_first(ls);
    data = test_adt_get_data(t);
    printf("first element is %d\n",data);

    //resize
    printf("adding more capacity to the generic sequence\n");
    line_sequence new_ls = line_sequence_add_cap(ls,3);
    if(new_ls == NULL){
        printf("something went wrong when resizing the generic sequence\n");
    }
    else{
        printf("generic sequence resized\n");
        ls = new_ls;

        max_cap = line_sequence_max_cap(ls);
        printf("generic sequence maximum capacity is %d\n",max_cap);

        t = (test_adt) line_sequence_get_elem_first(ls);
        data = test_adt_get_data(t);
        printf("first element is %d\n",data);
    }

    //delete
    printf("deleting generic sequence and all elements\n");
    line_sequence_delete_all(ls,test_adt_delete_gen);

    //test complete
    printf("test completed\nprogram ended\n");
    return 0;
}