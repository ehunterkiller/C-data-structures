#include <stdio.h>
#include <stdlib.h>
#include "../array_structs/list_array.h"
#include "test_data_type/testADT.h"

int main(){
    printf("test begin\n");

    //create a generic array
    printf("creating generic array data structure\n");

    list_array ls = list_array_create(5);
    if(ls == NULL){
        printf("something went wrong when creating generic array, returned NULL\n");
        return 1;
    }
    else{
        printf("generic array created\n");
    }

    //test if empty
    if(list_array_is_empty(ls)){
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
    list_array_add_elem_last(ls,t1);
    list_array_add_elem_last(ls,t2);
    list_array_add_elem_last(ls,t3);

    printf("elements added\n");

    //test some parameters
    if(list_array_is_full(ls)){
        printf("generic array is FULL\n");
    }
    else{
        printf("generic array has space\n");
    }

    int max_cap = list_array_max_cap(ls);
    printf("generic array maximum capacity is %d\n",max_cap);

    int num_elems = list_array_num_elems(ls);
    printf("number of elements stored in generic is %d\n",num_elems);

    //iterate
    printf("iteration begin:\n");
    for(int i = 0; i < num_elems; i++){
        test_adt t = (test_adt) list_array_get_elem_at(ls,i);
        int data = test_adt_get_data(t);
        printf("element at %d is %d\n",i,data);
    }
    printf("iteration complete\n");

    //remove element
    printf("removing element at index 1\n");
    list_array_rem_elem_at(ls,1);

    num_elems = list_array_num_elems(ls);
    printf("number of elements stored in generic is %d\n",num_elems);

    printf("iteration begin:\n");
    for(int i = 0; i < num_elems; i++){
        test_adt t = (test_adt) list_array_get_elem_at(ls,i);
        int data = test_adt_get_data(t);
        printf("element at %d is %d\n",i,data);
    }
    printf("iteration complete\n");

    //resize
    printf("adding more capacity to the generic array\n");
    list_array new_ls = list_array_add_cap(ls,3);
    if(new_ls == NULL){
        printf("something went wrong when resizing the generic array\n");
    }
    else{
        printf("generic array resized\n");
        ls = new_ls;

        max_cap = list_array_max_cap(ls);
        printf("generic array maximum capacity is %d\n",max_cap);

        printf("iteration begin:\n");
        for(int i = 0; i < num_elems; i++){
            test_adt t = (test_adt) list_array_get_elem_at(ls,i);
            int data = test_adt_get_data(t);
            printf("element at %d is %d\n",i,data);
        }
        printf("iteration complete\n");
    }

    //delete
    printf("deleting generic array and all elements\n");
    list_array_delete_all(ls,test_adt_delete_gen);

    //test complete
    printf("test completed\nprogram ended\n");
    return 0;
}