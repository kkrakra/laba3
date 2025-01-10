#ifndef ARRAY_H
#define ARRAY_H

int make_array(int** array, int capacity);

int* add_capacity(int** array_p, int* capacity_p);
int decrease_capacity(int** array_p, int*capacity_p);
int check_fix_capacity(int*array, int* size_p, int* capacity_p);


int add_item(int* array, int* size_p, int* capacity_p, int position, int item);
int insert_item_at_index(int* array, int* size_p, int index, int new_item);
int remove_item_at_index(int* array, int* size_p, int index);
int print_array(int* arr, int size);


#endif 
