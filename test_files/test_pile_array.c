#include <stdio.h>
#include <stdlib.h>
#include "../array_structs/pile_array.h"
#include "test_data_type/testADT.h"

int main(){
    printf("test begin\n");

    //create a generic array
    printf("creating generic array data structure\n");

    pile_array pa = pile_array_create(5);
    if(pa == NULL){
        printf("something went wrong when creating generic array, returned NULL\n");
        return 1;
    }
    else{
        printf("generic array created\n");
    }

    //test if empty
    if(pile_array_is_empty(pa)){
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
    pile_array_add_elem_first(pa,t1);
    pile_array_add_elem_first(pa,t2);
    pile_array_add_elem_first(pa,t3);

    printf("elements added\n");

    //test some parameters
    if(pile_array_is_full(pa)){
        printf("generic array is FULL\n");
    }
    else{
        printf("generic array has space\n");
    }

    int max_cap = pile_array_max_cap(pa);
    printf("generic array maximum capacity is %d\n",max_cap);

    int num_elems = pile_array_num_elems(pa);
    printf("number of elements stored in generic is %d\n",num_elems);

    test_adt t = (test_adt) pile_array_get_elem_first(pa);
    int data = test_adt_get_data(t);
    printf("first element is %d\n",data);

    //remove element
    printf("removing first element\n");
    pile_array_rem_elem_first(pa);

    num_elems = pile_array_num_elems(pa);
    printf("number of elements stored in generic is %d\n",num_elems);

    t = (test_adt) pile_array_get_elem_first(pa);
    data = test_adt_get_data(t);
    printf("first element is %d\n",data);

    //resize
    printf("adding more capacity to the generic array\n");
    pile_array new_pa = pile_array_add_cap(pa,3);
    if(new_pa == NULL){
        printf("something went wrong when resizing the generic array\n");
    }
    else{
        printf("generic array resized\n");
        pa = new_pa;

        max_cap = pile_array_max_cap(pa);
        printf("generic array maximum capacity is %d\n",max_cap);

        t = (test_adt) pile_array_get_elem_first(pa);
        data = test_adt_get_data(t);
        printf("first element is %d\n",data);
    }

    //delete
    printf("deleting generic array and all elements\n");
    pile_array_delete_all(pa,test_adt_delete_gen);

    //test complete
    printf("test completed\nprogram ended\n");
    return 0;
}