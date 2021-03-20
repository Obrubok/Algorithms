#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

vector<int> selectionSort(vector<int> array);

int main() {
    vector<int> array;
    srand(time(NULL));
    cout << "Сгенерированный массив: " << endl;
    for (int i = 0; i < 10; ++i) {
        array.push_back(1 + rand() % 51);
        cout << array[i] << " ";
    }
    cout << endl;
    array = selectionSort(array);
    cout << "Отсортированный массив: " << endl;
    for (int i = 0; i < array.size(); ++i) {
        cout << array[i] << " ";
    }

    return 0;
}

vector<int> selectionSort(vector<int> array) {
    for (int i = 0; i < array.size(); i++) {
        int min = i;
        for (int j = i + 1; j < array.size(); j++) {
            if (array[min] > array[j]) {
                min = j;
            }
        }
        if (min != i) {
            swap(array[i], array[min]);
        }
    }

    return array;
}
