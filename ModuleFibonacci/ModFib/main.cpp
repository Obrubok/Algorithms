#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int Fib3(int n);
int FibLastDigit(int n);
int FibModule(int n, int m);
vector<long> FibArray(int n);
vector<int> GetPizanoPeriod(uint m);
int GetRemainder(long n, uint m);

int main()
{
    long n = 0;
    uint m = 0;
//    cout << "Введите номер числа Фибоначчи: ";
//    cin >> n;
//    cout << "Введите делитель: ";
//    cin >> m;
//    cout << "Остаток от деления по модулю m = " << FibModule(n, m) << endl;
//    cout << "Остатки от деления по модулю 4: " << endl;
//    for (int i = 0; i <= 18; i++) {
//        cout << FibModule(i, 4) << " ";
//    }
//    cout << "\n";

    cout << "Введите делитель: ";
    cin >> m;
    cout << "Период Пизано по модулю " << m << " :" << endl;
    vector<int> fibs = GetPizanoPeriod(m);
    for (uint i = 0; i < fibs.size(); i++) {
        cout << fibs[i] << " ";
    }
    cout << "\n";
    cout << "Введите номер числа Фибоначчи: ";
    cin >> n;
    cout << "Остаток " << n << " числа Фибоначчи от деления на " << m << " : " << GetRemainder(n, m) << endl;

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
    for (int i = 2; i <= n; i++) {
        temp = b;
        b = (a + b) % 10;
        a = temp;
    }

    return b;
}

int FibModule(int n, int m)
{
    if (n <= 1) {
        return n % m;
    }
    int a = 0, b = 1, temp = 0;
    for (int i = 2; i <= n; i++) {
        temp = b;
        b = (a + b) % m;
        a = temp;
    }

    return b;
}

vector<long> FibArray(int n)
{
    vector<long> fibs;
    fibs.push_back(0);
    fibs.push_back(1);
    for (int i = 2; i <= n; i++) {
        fibs.push_back(fibs[i - 1] + fibs[i - 2]);
    }

    return fibs;
}

vector<int> GetPizanoPeriod(uint m)
{
    vector<int> fibRems;
    fibRems.push_back(0);
    fibRems.push_back(1);
    uint i = 2;
    while (i <= 6 * m + 1) {
        fibRems.push_back((fibRems[i - 1] + fibRems[i - 2]) % m);
        if ((fibRems[i - 1] == 0) && (fibRems[i] == 1)) {
            fibRems.erase(fibRems.end() - 2, fibRems.end());
            return fibRems;
        }
        i += 1;
    }
    return fibRems;
}

int GetRemainder(long n, uint m)
{
    vector<int> fibRems = GetPizanoPeriod(m);
    int periodPizanoSize = fibRems.size();
    cout << "Длина периода Пизано: " << periodPizanoSize << endl;
    return fibRems[n % periodPizanoSize];
}
