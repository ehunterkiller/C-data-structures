#include <stdio.h>
#include <stdlib.h>
#include "../sequence_structs/pile_sequence.h"
#include "test_data_type/testADT.h"

int main(){
    printf("test begin\n");

    //create a generic sequence
    printf("creating generic sequence data structure\n");

    pile_sequence ps = pile_sequence_create(5);
    if(ps == NULL){
        printf("something went wrong when creating generic sequence, returned NULL\n");
        return 1;
    }
    else{
        printf("generic sequence created\n");
    }

    //test if empty
    if(pile_sequence_is_empty(ps)){
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
    pile_sequence_add_elem_first(ps,t1);
    pile_sequence_add_elem_first(ps,t2);
    pile_sequence_add_elem_first(ps,t3);

    printf("elements added\n");

    //test some parameters
    if(pile_sequence_is_full(ps)){
        printf("generic sequence is FULL\n");
    }
    else{
        printf("generic sequence has space\n");
    }

    int max_cap = pile_sequence_max_cap(ps);
    printf("generic sequence maximum capacity is %d\n",max_cap);

    int num_elems = pile_sequence_num_elems(ps);
    printf("number of elements stored in generic is %d\n",num_elems);

    test_adt t = (test_adt) pile_sequence_get_elem_first(ps);
    int data = test_adt_get_data(t);
    printf("first element is %d\n",data);

    //remove element
    printf("removing first element\n");
    pile_sequence_rem_elem_first(ps);

    num_elems = pile_sequence_num_elems(ps);
    printf("number of elements stored in generic is %d\n",num_elems);

    t = (test_adt) pile_sequence_get_elem_first(ps);
    data = test_adt_get_data(t);
    printf("first element is %d\n",data);

    //resize
    printf("adding more capacity to the generic sequence\n");
    pile_sequence new_ps = pile_sequence_add_cap(ps,3);
    if(new_ps == NULL){
        printf("something went wrong when resizing the generic sequence\n");
    }
    else{
        printf("generic sequence resized\n");
        ps = new_ps;

        max_cap = pile_sequence_max_cap(ps);
        printf("generic sequence maximum capacity is %d\n",max_cap);

        t = (test_adt) pile_sequence_get_elem_first(ps);
        data = test_adt_get_data(t);
        printf("first element is %d\n",data);
    }

    //delete
    printf("deleting generic sequence and all elements\n");
    pile_sequence_delete_all(ps,test_adt_delete_gen);

    //test complete
    printf("test completed\nprogram ended\n");
    return 0;
}