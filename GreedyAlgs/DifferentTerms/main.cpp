#include <iostream>
#include <vector>

std::vector<int> PutIntoTerms(int);

int main() {
    int number;
    std::vector<int> terms;
    std::cout << "Введите число: ";
    std::cin >> number;
    terms = PutIntoTerms(number);
    std::cout << "Длина массива слагаемых: " << terms.size() << std::endl;
    std::cout << "Слагаемые: " << std::endl;
    for (int term : terms) {
        std::cout << term << " ";
    }
    return 0;
}

std::vector<int> PutIntoTerms(int number) {
    std::vector<int> terms;
    int i = 1;
    while (number > 0) {
        if ((number - i) <= i) {
            terms.push_back(number);
            number -= number;
        } else {
            terms.push_back(i);
            number -= i;
        }
        i++;
    }

    return terms;
}
