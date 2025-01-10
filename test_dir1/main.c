# include <stdio.h>
# include <stdlib.h>


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


    // int* array = NULL; //array
    // int size = 0; //number of actual elements
    int capacity = 3; //number of allocated memory cells


    int choice; // cli inputs choice
    int position;
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


                break;
            case 2:
                printf("2. Вставка элемента\n");

                printf("введите индекс для вставки\n");
                result = scanf("%d", &position);

                if (result == EOF) {
                    printf("До свидания!\n");
                    return 0;
                }   

                break;
            case 3:
                printf("3. Удаление элемента\n");
    
                break;
            case 4:
                printf("4. Индивидуальное задание\n");
                break;
            case 5:
                printf("5. Вывод массива\n");

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


}


