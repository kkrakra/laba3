#include <stdlib.h>
#include <stdio.h>
#include "task.h"
#include "array.h"

int decrease(int value) {
    // 0 - если не уменьшается
    // 1 - если уменьшается
    int pred_digit = 0;
    while (value > 0) {
        int sled_digit = value % 10;
        if (sled_digit <= pred_digit) {
            return 0;
        }
        pred_digit = sled_digit;
        value /= 10;
    }

    return 1;
}

int task() {
    int new_array_size = 0;

        for (int i=0; i< (*capacity_p); i++) {
        printf("%d\n", array[i]);
        if (decrease(array[i]) == 1) {
            printf("%d - decrease\n", array[i]);
            new_array_size++;
        }

    }
    printf("\n");

    printf("Длина нового массива будет - %d\n", new_array_size);
    int* array2 = NULL;
    array2 = (int*)malloc(new_array_size*size_of_item);
    int j = 0;
    for (int i=0; i<capacity; i++) {
        printf("%d\n", array[i]);
        if (decrease(array[i]) == 1) {
            printf("%d - добавлено в новый массив\n", array[i]);
            array2[j] = array[i];
            
        }
    }

    for (int i=0; i<capacity; i++) {
        printf("%d\n", array[i]);
        if (decrease(array[i]) == 1) {
            printf("%d - удалено из старого массива\n", array[i]);
            remove_item_at_index(array, size_p, i);
            
        }
    }


    // посмотрим новый массив
    printf("%d, Новый массив - ");
    for (int i=0; i<new_array_size; i++) {
        printf("%d ", array2[i]);
    }
    printf("\n");

    // посмотрим измененный старый массив
    printf("%d, Старый массив - ");
    for (int i=0; i<capacity; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");


    return 0;

//remove_item_at_index(int* array, int* size, int index);

}

// int* local_array(int* array, int* size_p /*,int* new_size*/){
//     int* new_array = NULL;
//     //int new_size = 0;
// //counter 

//     for (int i = 0; i < *size_p; i++){
//         if (decreasing (array[i])){
//             new_array = (int*) malloc(new_array, (new_size + 1) * sizeof(int));
//             if (!new_array){
//                 printf ("ошибка выделения памяти.\n");
//                 return NULL;
//             }
//             new_array[new_size] = array[i];
//             (new_size)++;

//             *array = remove_item_at_index(array, size_p, i);
//             i--;
//         }
//     }
//     return new_array;
// }