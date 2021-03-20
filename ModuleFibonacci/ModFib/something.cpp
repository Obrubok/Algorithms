vector<int> FindFactors(int number)
{
    vector<int> factors;
    // Проверяем делимость на 2
    while (number % 2 == 0) {
        factors.push_back(2);
        number /= 2;
    }
    // Ищем нечетные множители
    int i = 3;
    int maxFactor = sqrt(number);
    while (i <= maxFactor) {
        // Проверяем делимость на i
        while (number % i == 0) {
            // i-ый множитель
            factors.push_back(i);
            // Делим число на i
            number /= i;
            // Новая верхняя граница
            maxFactor = sqrt(number);
        }
        // Проверяем след. нечетный множитель
        i += 2;
    }

    if (number > 1) {
        factors.push_back(number);
    }

    return factors;
}

// Наибольший общий делитель
int GCD(int a, int b) // А > B
{
    int remainder = 0;
    while (b != 0) {
        remainder = a % b; // остаток
        a = b;
        b = remainder;
    }

    return a;
}

int LCM(int a, int b)
{
    return (a * b) / GCD(a, b);
}

int testFunc(vector<int> factors)
{
    struct per {
        int value;
        int exponent;
    };
}
