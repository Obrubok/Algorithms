#include <iostream>
#include <cstdint>

using namespace std;

int GCD(int a, int b);

int main() {
    int a = 0, b = 0;
    cout << "Введите а и б через пробел:" << endl;
    cin >> a >> b;
    cout << endl;
    cout << "Наибольший общий делитель чисел а и б:" << endl;
    cout << GCD(a, b);

    return 0;
}

int GCD(int a, int b) {
    if (a == 0) {
        return b;
    }
    if (b == 0) {
        return a;
    }
    if (a >= b) {
        return GCD(a % b, b);
    }
    if (b >= a) {
        return GCD(a, b % a);
    }

    return 0;
}
