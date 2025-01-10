# include <stdio.h>
# include <stdlib.h>
# include "array.h"


int make_array(int** array, int capacity) {
    printf("адресс - %p\n", &*array);
    *array = (int*)malloc(capacity * sizeof(int));
    if (*array == NULL) {
        printf("Ошибка выделения памяти\n");
        return 1;
    }

    return 0;
}

int* add_capacity(int** array, int* capacity_p) {
    // Calculate new size (double the old size)
    (*capacity_p) = (*capacity_p) * 2;

    // Reallocate memory
    *array = realloc(*array, (*capacity_p) * sizeof(int));

    // Check if allocation was successful
    if (*array == NULL) {
        printf("ошибка выделения памяти\n");
        return NULL; // Return NULL to indicate failure
    }

    printf("новая емкость - %d\n", *capacity_p);

    // If we got here, the reallocation succeeded
    return *array;
}

int decrease_capacity(int** array, int*capacity) {
    // Calculate new size (double the old size)
    (*capacity) = (*capacity) / 2;

    // Reallocate memory
    *array = realloc(*array, (*capacity) * sizeof(int));

    // Check if allocation was successful
    if (*array == NULL) {
        printf("ошибка выделения памяти\n");
        return 1;
        // return NULL; // Return NULL to indicate failure
    }
    return 0;

    printf("новая емкость - %d\n", *capacity);
}

int check_fix_capacity(int*array, int* size, int* capacity) {
    if (*size > *capacity) {
        add_capacity(&array, capacity);
    }

    if (*size < *capacity/2) {
        decrease_capacity(&array, capacity);
    }

    return 0;

}

int add_item(int* array, int* size, int* capacity, int position, int item) {

    if (position < 0 || position > (*capacity) - 1) {
        printf("неверный индекс - %d\n", position);
        add_capacity(&array, capacity);
    }

    array[position] = item;

    (*size)++;
    printf("новый размер - %d\n", *size);
    printf("добавленный эллемент, Array[%d] - %d\n", position, array[position]);

    return 0;
} 


int insert_item_at_index(int* array, int* size, int index, int new_item) {
    // Check if the index is valid
    if (index < 0 || index > *size-1) {
        printf("неверный индекс\n");
        return 1;
    }
    

    // Shift elements to the right
    for (int i = *size; i > index; i--) {
        // printf("a[%d] = a[%d]\n", i, i-1);
        array[i] = array[i - 1];
        // printf("%d\n", array[i]);
    }

    // Insert the new item
    array[index] = new_item;

    (*size)++;
    printf("Новый размер - %d\n", *size);
    printf("добавленный элемент, массив[%d] - %d\n", index, array[index]);
    
    return 0;
}



int remove_item_at_index(int* array, int* size, int index) {
    // Check if the index is valid
    if (index < 0 || index >= *size) {
        printf("Неверный индекс\n");
        return 1;
    }

    // Shift elements to the left
    for (int i = index; i < *size - 1; i++) {
        array[i] = array[i + 1];
    }

    // Decrement the size
    (*size)--;

    return 0;
}


int print_array(int* arr, int size) {
        for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}