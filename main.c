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
int enter(int *choice){
		int result = 0;
        while (result != 1){
    	result = scanf("%d", choice);
		if (result == EOF){
			       printf ("До свидания!\n");
			        return EOF;
		}
       	if (result != 1){
  	     printf ("введено некоректное значение\n");
		}
		scanf("%*[^\n]");
        }
        return 1;
    }


int main() {


    int* array = NULL;
    int size = 0;
    int* size_p = &size;
    
    int capacity = 3;
    int* capacity_p = &capacity;


    int choice;
    int position;
    int value;
    int result;

//	enter( &choice);
    while (1) {
        display_menu();
       result =  enter (&choice);      
       if (result == EOF) {
           printf("До свидания!\n");
           free (array);
            return 0;
       }        

      //  if (result != 1) {
        //    printf("неверный ввод, попробуйте ещё раз.\n");
          //  fflush(NULL); 
           // continue;
        //}


        switch (choice) {
            case 1:
                printf("1. Инициализация массива\n");

                printf("введите размер массива ");

                result =  enter (&capacity);      
                     if (result == EOF) {
                         printf("До свидания!\n");
                         free (array);
                          return 0;
                     }        

                make_array(&array, capacity);
    
                int initial_size = capacity;

                for (int i = 0; i < initial_size; i++) {
                    int position = i;
                    int value;
                    printf("введите элемент %d\n", position);
                  result =  enter (&value);      
                         if (result == EOF) {
                             printf("До свидания!\n");
                             free (array);
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
                result =  enter (&position);      
                     if (result == EOF) {
                         printf("До свидания!\n");
                         free (array);
                          return 0;
                     }         

                printf("введите элемент\n");
                result =  enter (&value);      
                     if (result == EOF) {
                         printf("До свидания!\n");
                         free (array);
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
              result =  enter (&position);      
                     if (result == EOF) {
                         printf("До свидания!\n");
                         free (array);
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
                task(array, size_p);
                break;
            case 5:
                printf("5. Вывод массива\n");
                print_array(array, size);
                printf("размер - %d\n", size);
                printf("емкость - %d\n", capacity);

                break;
            case 0:
                printf("Завершение.\n");
                free (array);
                return 0;
            default:
                printf("пожалуйста, попробуйте ещё раз.\n");
        }

    }

    free(array);

}


