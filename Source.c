#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
  setlocale(LC_ALL, "Rus");

    int N = 0;//���������� ��������� � ������� ��������� �����
    int i = 0;// ������ �������
    double min = 0.0;//������ �������
    double max = 0.0;// ������� �������
    double drob = 0.0;// ������� �����
    double cel = 0.0; // ����� �����
    double* mas1;// ������ ��������� �����
    double sum = 0.0;//�������� �����
    int* masdrob;// ������ � �������� �������
    int j = 0;//������ �������

    printf("������� ���������� ��������� ������� - \t"); //���������� ��������� �������
    scanf_s("%d" , &N);

    if (N <= 0)
        printf("������! ���������� ��������� ������ ���� ������ ���� !"); //���������� ��������� ������ ���� ������ ����

    printf("������� ����������� ������� - \t");
    scanf_s("%lf", &min);

    printf("������� ������������ ������� - \t");
    scanf_s("%lf", &max);

    if (max < min)
        printf("������! ������������ ������� �� ����� ���� ������ ������������ !"); //�������� ������������ �������� ������

    mas1 = (double*)malloc(N * sizeof(double));//������ ��������� �����
    

    if (mas1 == 0)
    {
        printf("������! ������ ����� ����!");
        return 0;
    }

    for (i = 0; i < N; i++)
    {
        mas1[i] = (((double)rand()) / RAND_MAX) * (max - 1) + 1;  //�������� ������ ���������� �������

    }
     
    masdrob = (int*)malloc(N * sizeof(int));//������ ������ � ������� ������

    for (i = 0; i < N; i++)
    {
      drob = (mas1[i] - (int)mas1[i]) * 1000000;//�������� ������� ����� �� �����

      if (drob == 0)
        masdrob[i] = 0;
      else
      {
        masdrob[i] = (int)drob;

        while (masdrob[i] % 10 == 0) //������� �������� ����
          masdrob[i]  /= 10;
      }
    }

    for (i = 0; i < N; i++)
    {
      for (j = 0; j < N; j++)
      {
        if (i == masdrob[j])  //��������� ������� � ������� ������
        {                   
          sum = sum - mas1[i];
          mas1[i] = 0.0; //�������� ������� � ������� � �������� �������
          
        }
      }
    }

    for (i = 0; i < N; i++)
    {
      sum = sum + mas1[i];
    }
    printf("����� ����� = %lf", sum);
        free(mas1);
        free(masdrob);
        return 0;
}