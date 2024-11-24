// learn5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>


struct RuggedArray
{
    int** data = NULL;
    int rows = 0;
};

int main(int argc,char** args)
{
    
    RuggedArray mas;
    scanf_s("%i", &mas.rows);
    mas.data = (int**)malloc(sizeof(int*) * mas.rows);// array of mas.rows pointers to pointers 
      
    for (int i = 0; i < mas.rows; i++)
    {
        int cols;
        scanf_s("%i", &cols);
        mas.data[i] = (int*)malloc(sizeof(int) * (cols+1));
        mas.data[i][0] = cols;
    }
 
    for (int i = 0; i < mas.rows; i++)
        for (int j = 1; j<=mas.data[i][0]; j++)
            mas.data[i][j] = rand() % 100;

    for (int i = 0; i < mas.rows; i++)
    {
        for (int j = 1; j <= mas.data[i][0]; j++) 
            printf_s("%3i", mas.data[i][j]);
        printf_s("\n");
    }
    for (int i = 0; i < mas.rows; i++)
        free(mas.data[i]);
    free(mas.data);


    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
