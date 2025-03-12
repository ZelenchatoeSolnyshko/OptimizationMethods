// OptimizationMethods.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cmath>

using namespace std;
double f(double x) 
{
    double y = exp(x) - 1 - x - pow(x, 2) / 2 - pow(x, 3) / 6;
    return y;
}

void SwennAlgorithm(double x0, double* interval, double t) 
{
    double xk = x0;
    double xk1;
    double a = 0.0;
    double b = 0.0;
    double delta;
    double f1 = f(xk - t);
    double f2 = f(xk);
    double f3 = f(xk + t);
    if ((f1 >= f2) && (f2 <= f3)) {
        interval[0] = xk - t;
        interval[1] = xk + t;
        return;
    }
    else if (((f1 <= f2) && (f2 >= f3))) 
    {
        cout << " The point x0 is set incorrectly " << endl;
        return;
    }
    else if ((f1 <= f2) && (f2 <= f3)) 
    {
        delta = -t;
        b = xk;
        xk1 = b - t;
    }
    else 
    {
        delta = t;
        a = xk;
        xk1 = a + t;
    }
    int k = 1;
    for (int i = 0; f(xk1) < f(xk); i++) 
    {
        if (delta == -t) 
        {
            b = xk;
        }
        else
        {
            a = xk;
        }
        xk = xk1;
        xk1 = xk + pow(2, k) * delta;
        k = k + 1;
    }
    if (delta == -t) 
    {
        interval[0] = xk1;
        interval[1] = xk;
    }
    else
    {
        interval[0] = xk;
        interval[1] = xk1;
    }

}

double TheGoldenRatio(double* interval, double l)
{
    double ak = interval[0];
    double bk = interval[1];
    double yk = ak + (3 - sqrt(5)) * (bk - ak) / 2;
    double zk = ak + bk - yk;
    for (int i = 0; fabs(bk - ak) > l; i++)
    {
        double f1 = f(yk);
        double f2 = f(zk);
        if (f1 <= f2)
        {
            bk = zk;
            double tmp = yk;
            yk = ak + bk - tmp;
            zk = tmp;
        }
        else
        {
            ak = yk;
            double tmp = zk;
            zk = ak + bk - tmp;
            yk = tmp;
        }
    }
    double x = (bk + ak) / 2;
    return x;
}

int main()
{
    double x0;
    cout << "Select the value of the initial point x0: " << endl;
    cin >> x0;

    double t;
    cout << "Select the step size: " << endl;
    cin >> t;

    double* interval = new double[2];
    SwennAlgorithm(x0, interval, t);
    cout << "Initial uncertainty interval - [" << interval[0] << ";" << interval[1] << "]" << endl;

    double l;
    cout << "Choose the accuracy: " << endl;
    cin >> l;

    double res = TheGoldenRatio(interval, l);
    cout << "The minimum point found by the golden ratio algorithm - " << res << endl;
    cout << "Minimum of function at this point - " << f(res) << endl;
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
