#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
#define SIZE 4
#define EPS_CONST 0.01

int main()
{
    setlocale(LC_ALL, "Russian");

    //Метод простых итераций
    cout << "Метод простых итераций:\n";
    double Temp = 0, Norm, ESP, delta = INT_MAX;
    int n = 1;    //Номер итерации

    double Norma_1[SIZE] = { 0 }, Norma_2[SIZE] = { 0 }, Norma_b[SIZE] = { 0 }, B[SIZE] = { 0 }, Iterations[50][SIZE] = { 0 };

    double a[SIZE][SIZE] = {
                            {-19, 2, -1, -8},
                             {2, 14, 0, -4},
                             {6, -5, -20, -6},
                             {-6, 4, -2, 15}
                            };

    double b[SIZE] = { 38, 20, 52, 43 };

    //Перестановка
    for (int i = 0; i < SIZE; i++)
    {
        B[i] = -1 * b[i];;
        b[i] = -1 * a[i][i];
        a[i][i] = 0;
    }

    //Привидение к виду
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            a[i][j] /= b[i];
        }
        B[i] /= b[i];
        b[i] /= b[i];
    }

    //Вывод системы
    cout << "Система:\n\n";
    for (int i = 0; i < SIZE; i++)
    {
        cout << b[i] << "*X" << i + 1 << " = ";
        for (int j = 0; j < SIZE; j++)
        {
            cout << setw(9) << a[i][j] << " * X" << j + 1 << " + ";
        }
        cout << setw(5) << B[i] << endl;
    }
    cout << "\n";

    //Вычисление нормы
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            Norma_1[i] += fabs(a[i][j]);
            Norma_2[i] += fabs(a[j][i]);
            Norma_b[i] = fabs(B[i]);
        }
    }

    //Поиск максимума среди норм
    double max_1 = Norma_1[0];
    double max_2 = Norma_2[0];
    double max_b = Norma_b[0];
    for (int i = 1; i < SIZE; i++)
    {
        if (Norma_1[i] > max_1)
        {
            max_1 = Norma_1[i];
        }
        if (Norma_2[i] > max_2)
        {
            max_2 = Norma_2[i];
        }
        if (Norma_b[i] > max_b)
        {
            max_b = Norma_b[i];
        }
    }
    Norm = fmin(max_1, max_2); //Минимальная из норм
    cout << "Норма B: " << Norm << endl;
    cout << "Норма бэтта: " << max_b << endl;

    if (Norm < 1)    //Так как ||B|| < 1, то итерационный процесс будет сходиться к точному решению системы
    {
        cout << "           ";
        for (int i = 0; i < SIZE; i++)
            cout << setw(14) << "x" << i + 1;
        cout << setw(15) << "ESP" << setw(15) << "Delta" << "\n\n";
        //За начальный вектор
        cout << "Итерация N1: ";
        for (int i = 0; i < SIZE; i++)
        {
            Iterations[0][i] = B[i];
            cout << setw(15) << Iterations[0][i];
        }
        cout << endl;

        ESP = pow(Norm, 1) / (1 - Norm) * max_b;    //Вычисление погрешности

        while (delta > EPS_CONST)
        {
            ESP = pow(Norm, n) / (1 - Norm) * max_b;    //Вычисление погрешности

            cout << "Итерация N" << n + 1 << ": ";
            for (int i = 0; i < SIZE; i++)
            {
                for (int j = 0; j < SIZE; j++)
                {
                    Temp += a[i][j] * Iterations[n - 1][j];
                }
                Iterations[n][i] += (Temp + B[i]);
                cout << setw(15) << Iterations[n][i];
                Temp = 0;
            }
            if (n != 0)
            {
                delta = max(max(abs(Iterations[n][0] - Iterations[n - 1][0]), abs(Iterations[n][1] - Iterations[n - 1][1])), abs(Iterations[n][2] - Iterations[n - 1][2]));
            }
            n++;
            cout << setw(15) << ESP;
            cout << setw(15) << delta;
            cout << endl;
        }
    }

    cout << "\nКоличество требуемых итераций: " << n << "\n\n";

    cout << "___________________________________________________________________________\n";
    cout << "Метод Зейделя:\n";

    //Метод Зейделя
    Temp = 0;
    n = 1;    //Номер итерации
    int Zeidel;

    double A[SIZE][SIZE] = {             {-19, 2, -1, -8},
        {2, 14, 0, -4},
        {6, -5, -20, -6},
        {-6, 4, -2, 15}};

    double C[SIZE] = { 38, 20, 52, 43 };

    //Обнуляем все элементы из предыдущего метода
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < 50; j++)
        {
            B[i] = 0;
            Iterations[i][j] = 0;
            Norma_1[i] = 0;
            Norma_2[i] = 0;
            Norma_b[i] = 0;
        }

    //Перестановка
    for (int i = 0; i < SIZE; i++)
    {
        B[i] = -1 * C[i];
        C[i] = -1 * A[i][i];
        A[i][i] = 0;
    }

    //Привидение к виду
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            A[i][j] /= C[i];
        }
        B[i] /= C[i];
        C[i] /= C[i];
    }

    cout << "Система:\n\n";
    //Вывод системы
    for (int i = 0; i < SIZE; i++)
    {
        cout << C[i] << "*X" << i + 1 << " = ";
        for (int j = 0; j < SIZE; j++)
        {
            cout << setw(9) << A[i][j] << " * X" << j + 1 << " + ";
        }
        cout << setw(5) << B[i] << endl;
    }
    cout << "\n\n";

    //Вычисление нормы
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            Norma_1[i] += fabs(a[i][j]);
            Norma_2[i] += fabs(a[j][i]);
            Norma_b[i] = fabs(B[i]);
        }
    }

    //Поиск максимума среди норм
    max_1 = Norma_1[0];
    max_2 = Norma_2[0];
    max_b = Norma_b[0];
    for (int i = 1; i < SIZE; i++)
    {
        if (Norma_1[i] > max_1)
        {
            max_1 = Norma_1[i];
        }
        if (Norma_2[i] > max_2)
        {
            max_2 = Norma_2[i];
        }
        if (Norma_b[i] > max_b)
        {
            max_b = Norma_b[i];
        }
    }
    Norm = fmin(max_1, max_2); //Минимальная из норм
    cout << "Норма B: " << Norm << endl;
    cout << "Норма бэтта: " << max_b << endl;

    if (Norm < 1)    //Так как ||B|| < 1, то итерационный процесс будет сходиться к точному решению системы
    {
        cout << "           ";
        for (int i = 0; i < SIZE; i++)
            cout << setw(14) << "x" << i + 1;
        cout << setw(15) << "ESP" << setw(15) << "Delta" << "\n\n";
        //Начальный вектор
        cout << "Итерация N1: ";
        for (int i = 0; i < SIZE; i++)
        {
            Iterations[0][i] = B[i];
            cout << setw(15) << Iterations[0][i];
        }
        cout << endl;;

        ESP = pow(Norm, 1) / (1 - Norm) * max_b;

        delta = INT_MAX;
        while (delta > EPS_CONST)
        {
            ESP = pow(Norm, n) / (1 - Norm) * max_b;    //Вычисление погрешности

            cout << "Итерация N" << n + 1 << ": ";
            for (int i = 0; i < SIZE; i++)
            {
                for (int j = 0; j < SIZE; j++)
                {
                    if (j >= i) Zeidel = n - 1;
                    else Zeidel = n;

                    Temp += A[i][j] * Iterations[Zeidel][j];
                }
                Iterations[n][i] += (Temp + B[i]);
                cout << setw(15) << Iterations[n][i];
                Temp = 0;
            }
            if (n != 0)
            {
                delta = max(max(abs(Iterations[n][0] - Iterations[n - 1][0]), abs(Iterations[n][1] - Iterations[n - 1][1])), abs(Iterations[n][2] - Iterations[n - 1][2]));
            }
            n++;
            cout << setw(15) << ESP;
            cout << setw(15) << delta;
            cout << endl;
        }
    }
    cout << "\nКоличество требуемых итераций: " << n << endl;
    return 0;
}





