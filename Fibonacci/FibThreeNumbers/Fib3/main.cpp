#include <iostream>

using namespace std;

int Fib3(int n);
int FibLastDigit(int n);

int main()
{
    int n;
    cout << "Введите номер числа Фибоначчи: ";
    cin >> n;
    cout << n << " число Фибоначчи = " << Fib3(n) << endl;
    cout << "Последняя цифра " << n << " числа Фибоначчи: " << FibLastDigit(n) << endl;

    return 0;
}

int Fib3(int n)
{
    if (n <= 1) {
        return n;
    }
    int a, b, temp;
    a = 0;
    b = 1;
    for (int i = 2; i <= n; i++) {
        temp = b;
        b += a;
        a = temp;
        temp = b - a;
    }

    return b;
}

int FibLastDigit(int n)
{
    if (n <= 1) {
        return n;
    }
    int a = 0, b = 1, temp = 0;
//    a = 0;
//    b = 1;
//    temp = 0;
    for (int i = 2; i <= n; i++) {
        temp = b;
        b = (a + b) % 10;
        a = temp;
    }

    return b;
}
