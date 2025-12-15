#include <stdio.h>
#include <stdlib.h>
#include "../array_structs/line_array.h"
#include "test_data_type/testADT.h"

int main(){
    printf("test begin\n");

    //create a generic array
    printf("creating generic array data structure\n");

    line_array la = line_array_create(5);
    if(la == NULL){
        printf("something went wrong when creating generic array, returned NULL\n");
        return 1;
    }
    else{
        printf("generic array created\n");
    }

    //test if empty
    if(line_array_is_empty(la)){
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
    
    //last
    printf("added elements at last\n");
    line_array_add_elem_last(la,t1);
    line_array_add_elem_last(la,t2);
    line_array_add_elem_last(la,t3);

    printf("elements added\n");

    //test some parameters
    if(line_array_is_full(la)){
        printf("generic array is FULL\n");
    }
    else{
        printf("generic array has space\n");
    }

    int max_cap = line_array_max_cap(la);
    printf("generic array maximum capacity is %d\n",max_cap);

    int num_elems = line_array_num_elems(la);
    printf("number of elements stored in generic is %d\n",num_elems);

    test_adt t = (test_adt) line_array_get_elem_first(la);
    int data = test_adt_get_data(t);
    printf("first element is %d\n",data);

    //remove element
    printf("removing first element\n");
    line_array_rem_elem_first(la);

    num_elems = line_array_num_elems(la);
    printf("number of elements stored in generic is %d\n",num_elems);

    t = (test_adt) line_array_get_elem_first(la);
    data = test_adt_get_data(t);
    printf("first element is %d\n",data);

    //resize
    printf("adding more capacity to the generic array\n");
    line_array new_la = line_array_add_cap(la,3);
    if(new_la == NULL){
        printf("something went wrong when resizing the generic array\n");
    }
    else{
        printf("generic array resized\n");
        la = new_la;

        max_cap = line_array_max_cap(la);
        printf("generic array maximum capacity is %d\n",max_cap);

        t = (test_adt) line_array_get_elem_first(la);
        data = test_adt_get_data(t);
        printf("first element is %d\n",data);
    }

    //delete
    printf("deleting generic array and all elements\n");
    line_array_delete_all(la,test_adt_delete_gen);

    //test complete
    printf("test completed\nprogram ended\n");
    return 0;
}