# include <stdio.h>
# include <stdlib.h>
# include "array.h"
#include "task.h"



void display_menu() {

    printf("Меню:\n");
    printf("1. Инициализация массива\n");
    printf("2. Вставка элемента\n");
    printf("3. Удаление элемента\n");
    printf("4. Индивидуальное задание\n");
    printf("5. Вывод массива\n");
    printf("0. Выход\n");
    printf("Ваш выбор: ");

}

int main() {


    int* array = NULL; //array
    int size = 0; //number of actual elements
    int* size_p = &size;
    
    int capacity = 3; //number of allocated memory cells
    int* capacity_p = &capacity;


    int choice; // cli inputs choice
    int position;
    int value;
    int result;

    while (1) {
        display_menu();
        
        result = scanf("%d", &choice);

        if (result == EOF) {
            printf("До свидания!\n");
            return 0;
        }        

        if (result != 1) {
            printf("неверный ввод, попробуйте ещё раз.\n");
            fflush(NULL); 
            continue;
        }

        switch (choice) {
            case 1:
                printf("1. Инициализация массива\n");

                printf("введите размер массива ");

                int result = scanf("%d", &capacity);

                if (result == EOF) {
                    printf("Обнаружен EOF\n");
                    return 0;
                }   

                make_array(&array, capacity);
    
                int initial_size = capacity;

                for (int i = 0; i < initial_size; i++) {
                    int position = i;
                    int value;
                    printf("введите элемент %d\n", position);
                    int result = scanf("%d", &value);

                    if (result == EOF) {
                        printf("Обнаружен EOF\n");
                        return 0;
                    }   
                    add_item(array, size_p, capacity_p, position, value);
                }

                print_array(array, size);

                printf("размер - %d\n", size);
                printf("емкость - %d\n", capacity);

                break;
            case 2:
                printf("2. Вставка элемента\n");

                printf("введите индекс для вставки\n");
                result = scanf("%d", &position);

                if (result == EOF) {
                    printf("До свидания!\n");
                    return 0;
                }   

                printf("введите элемент %d\n", position);
                result = scanf("%d", &value);

                if (result == EOF) {
                    printf("До свидания!\n");
                    return 0;
                }


                insert_item_at_index(array, size_p, position, value);
                check_fix_capacity(array, size_p, capacity_p);
                
                print_array(array, size);

                printf("размер - %d\n", size);
                printf("емкость - %d\n", capacity);


                break;
            case 3:
                printf("3. Удаление элемента\n");

                printf("введите индекс для удаления\n");
                // int position;
                result = scanf("%d", &position);

                if (result == EOF) {
                    printf("Обнаружен EOF\n");
                    return 0;
                }   

                remove_item_at_index(array, size_p, position);
                check_fix_capacity(array, size_p, capacity_p);
                print_array(array, size);

                printf("размер - %d\n", size);
                printf("емкость - %d\n", capacity);
    
                break;
            case 4:
                printf("4. Индивидуальное задание\n");
                //int new_size = 0;
                task(array, size_p);
                //printf ("Новый массив: ");
                //print_array(&new_array, new_size);
                //printf("Старый массив: ");
                //print_array(array, size);
                break;
            case 5:
                printf("5. Вывод массива\n");
                //printf("Memory address of array - %p\n", &array);

                print_array(array, size);

                printf("размер - %d\n", size);
                printf("емкость - %d\n", capacity);


                // print_array(array, size, capacity);
                break;
            case 0:
                printf("Завершение.\n");
                return 0;
            default:
                printf("пожалуйста, попробуйте ещё раз.\n");
        }

        // Clear input buffer after each operation
        // while (getchar() != '\n');
        // fflush(NULL);

        // Очищаем буфер ввода после каждой операции
        //  int c;
        //  while (scanf(" %c", &c) != '\n');
        // fflush(NULL);

    }

    free(array);

}


