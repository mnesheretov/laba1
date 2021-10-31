#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
  setlocale(LC_ALL, "Rus");

    int N = 0;//количество элементов в массиве случайных чисел
    int i = 0;// индекс массива
    double min = 0.0;//нижняя граница
    double max = 0.0;// верхняя граница
    double drob = 0.0;// дробная часть
    double cel = 0.0; // целая часть
    double* mas1;// массив случайных чисел
    double sum = 0.0;//итоговая сумма
    int* masdrob;// массив с дробными частями
    int j = 0;//индекс массива

    printf("Введите количество элементов массива - \t"); //количество элементов массива
    scanf_s("%d" , &N);

    if (N <= 0)
        printf("Ошибка! Количество элементов должно быть больше нуля !"); //количество элементов должно быть больше нуля

    printf("Введите минимальный элемент - \t");
    scanf_s("%lf", &min);

    printf("Введите максимальный элемент - \t");
    scanf_s("%lf", &max);

    if (max < min)
        printf("Ошибка! Максимальный элемент не может быть меньше минимального !"); //проверка корректности введённых данных

    mas1 = (double*)malloc(N * sizeof(double));//массив рандомных чисел
    

    if (mas1 == 0)
    {
        printf("Ошибка! Массив равен нулю!");
        return 0;
    }

    for (i = 0; i < N; i++)
    {
        mas1[i] = (((double)rand()) / RAND_MAX) * (max - 1) + 1;  //заполняю массив рандомными числами

    }
     
    masdrob = (int*)malloc(N * sizeof(int));//создаём массив с дробной частью

    for (i = 0; i < N; i++)
    {
      drob = (mas1[i] - (int)mas1[i]) * 1000000;//отделяем дробную часть от целой

      if (drob == 0)
        masdrob[i] = 0;
      else
      {
        masdrob[i] = (int)drob;

        while (masdrob[i] % 10 == 0) //убираем ненужные нули
          masdrob[i]  /= 10;
      }
    }

    for (i = 0; i < N; i++)
    {
      for (j = 0; j < N; j++)
      {
        if (i == masdrob[j])  //сравнение индекса с дробной частью
        {                   
          sum = sum - mas1[i];
          mas1[i] = 0.0; //зануляем элемент в массиве с дробными числами
          
        }
      }
    }

    for (i = 0; i < N; i++)
    {
      sum = sum + mas1[i];
    }
    printf("Сумма равна = %lf", sum);
        free(mas1);
        free(masdrob);
        return 0;
}