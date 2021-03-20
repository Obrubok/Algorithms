#include <iostream>
#include <vector>
#include <algorithm>

struct Item final {
    int value;
    int weight;
};

bool comparePrice(Item a, Item b) {
    return (static_cast<double>(a.value) / static_cast<double>(a.weight)) >
           (static_cast<double>(b.value) / static_cast<double>(b.weight));
}

void sortByPrice(std::vector<Item> &items) {
    std::sort(items.begin(), items.end(), comparePrice);
}

double get_max_knapsack_value(int capacity, std::vector <Item> items) {
    double value = 0.0;

    sortByPrice(items);

    // take items while there is empty space in knapsack
    for (auto &item:items) {
        if (capacity > item.weight) {
            // can take full item and continue
            capacity -= item.weight;
            value += item.value;
        } else {
            value += item.value * (static_cast <double>(capacity) / item.weight);
            break;
        }
    }

    return value;
}

int main() {
    int number_of_items;
    int knapsack_capacity;
    std::cout << "Введите кол-во предметов и вместимость рюкзака: " << std::endl;
    std::cin >> number_of_items >> knapsack_capacity;
    std::vector <Item> items(number_of_items);
    for (int i = 0; i < number_of_items; i++) {
        std::cin >> items[i].value >> items[i].weight;
    }

    // Удалить!
    /*std::cout << "Неотсортированный массив (по цене): " << std::endl;
    for (Item item : items) {
        std::cout << item.value << " " << item.weight << std::endl;
    }

    std::cout << "Отсортированный массив (по цене): " << std::endl;
    for (Item item : items) {
        std::cout << item.value << " " << item.weight << std::endl;
    }*/
    // Удалить!

    double max_knapsack_value = get_max_knapsack_value(knapsack_capacity, std::move(items));

    std::cout.precision(10);
    std::cout << max_knapsack_value << std::endl;

    return 0;
}
