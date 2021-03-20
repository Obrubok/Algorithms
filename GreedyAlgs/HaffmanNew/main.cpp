#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

struct HaffmanBinaryNode {
    std::string letter;
    int priority;
    HaffmanBinaryNode* leftChild;
    HaffmanBinaryNode* rightChild;
};

// Объявления функций
std::map<char, int> CountOfDiffChars(std::string str);
std::vector<HaffmanBinaryNode> Insert(std::map<char, int> &letters);
void SortQueue(std::vector<HaffmanBinaryNode>&);
int SizeOfQueue(std::vector<HaffmanBinaryNode>&);
HaffmanBinaryNode ExtractLast(std::vector<HaffmanBinaryNode>&);
std::map <char, std::string> DoCodeTableBlank(std::map<char, int>&);
std::map<char, std::string> BuildCodeTable(std::vector<HaffmanBinaryNode>&, std::map<char, int>&);
std::string EncodeString(std::string, std::map<char, std::string>&);
// Конец объявлений функций

int main() {
    // Ввод исходной строки
    std::string str;
    std::cout << "Введите последовательность букаф: " << std::endl;
    std::cin >> str;

    // Подсчёт количества каждой буквы засчет посимвольного переноса в map
    std::map <char, int> letters = CountOfDiffChars(str);
    // Объявление вектора для очереди
    std::vector<HaffmanBinaryNode> queueOfLetters;
    // Вставка букв с приоритетами в очередь
    queueOfLetters = Insert(letters);
    // Сортировка очереди
    SortQueue(queueOfLetters);

    // Переменные для вывода
    int countOfDiffChars = SizeOfQueue(queueOfLetters);
    std::map<char, std::string> codeTable = BuildCodeTable(queueOfLetters, letters);
    std::string resultString = EncodeString(str, codeTable);

    // Вывод длины очереди и длины закодированной строки
    std::cout << countOfDiffChars << " " << resultString.size() << std::endl;
    // Кодовая таблица ПОСЛЕ ЗАПОЛНЕНИЯ
    for (auto letter : codeTable) {
        std::cout << letter.first << ": " << letter.second << std::endl;
    }
    // Закодированная строка
    std::cout << resultString << std::endl;

    return 0;
}

// Подсчёт кол-ва разных символов и возврат значения в map
std::map<char, int> CountOfDiffChars(std::string str) {
    std::map <char, int> lettersCount;
    for (int i = 0; i < str.size(); i++) {
        auto ret = lettersCount.insert(std::make_pair(str[i], 1));
        if (!ret.second) {
            ret.first->second++;
        }
    }

    return lettersCount;
}

// Вставка узлов символов в "импровизированную" очередь с приоритетами
std::vector<HaffmanBinaryNode> Insert(std::map<char, int> &letters) {
    std::vector<HaffmanBinaryNode> queue;
    for (auto letter : letters) {
        HaffmanBinaryNode node;
        node.letter = letter.first;
        node.priority = letter.second;
        node.leftChild = NULL;
        node.rightChild = NULL;
        queue.push_back(node);
    }

    return queue;
}

// Сортировка очереди
void SortQueue(std::vector<HaffmanBinaryNode> &queue) {
    std::sort(queue.begin(), queue.end(), [](HaffmanBinaryNode first, HaffmanBinaryNode second) -> bool {
        return first.priority > second.priority;
    });
}

// Возвращает длину очереди (вектора)
int SizeOfQueue(std::vector<HaffmanBinaryNode> &queue) {
    return queue.size();
}

// Извлекает последний элемент "очереди"
// Так как вектор при извлечении
// отсортирован по-убыванию, то извлекает минимальный элемент
HaffmanBinaryNode ExtractLast(std::vector<HaffmanBinaryNode>& queue) {
    HaffmanBinaryNode node = queue[queue.size() - 1];
    queue.pop_back();
    return node;
}

// Вспомогательная функция для построения заготовки кодовой таблицы
std::map<char, std::string> DoCodeTableBlank(std::map<char, int>& letters) {
    std::map <char, std::string> codeTable;
    for (auto letter : letters) {
        codeTable.insert(std::make_pair(letter.first, ""));
    }

    return codeTable;
}

// Построение кодовой таблицы
std::map<char, std::string> BuildCodeTable(std::vector<HaffmanBinaryNode>& queue, std::map<char, int>& letters) {
    std::map<char, std::string> codeTable = DoCodeTableBlank(letters);
    if (queue.size() == 1) {
        char letter = queue[0].letter[0];
        codeTable[letter] = '0';
    }
    while (queue.size() > 1) {
        HaffmanBinaryNode firstMinNode = ExtractLast(queue);
        HaffmanBinaryNode secondMinNode = ExtractLast(queue);
        HaffmanBinaryNode* newNode = new HaffmanBinaryNode;
        newNode->letter = firstMinNode.letter + secondMinNode.letter;
        newNode->priority = firstMinNode.priority + secondMinNode.priority;
        // присвоение детей и расчет кодов
        // левое дитя
        newNode->leftChild = &firstMinNode;
        int size = firstMinNode.letter.size();
        for (int i = 0; i < size; i++) {
            char letter = firstMinNode.letter[i];
            codeTable[letter] = '0' + codeTable[letter];
        }
        // правое дитя
        newNode->rightChild = &secondMinNode;
        size = secondMinNode.letter.size();
        for (int i = 0; i < size; i++) {
            char letter = secondMinNode.letter[i];
            codeTable[letter] = '1' + codeTable[letter];
        }
        // --конец присвоения детей
        queue.push_back(*newNode);
        SortQueue(queue);
        delete newNode;
    }

    return codeTable;
}

// Кодирование заданной строки
std::string EncodeString(std::string sourceString, std::map<char, std::string>& codeTable) {
    std::string resultString = "";
    int size = sourceString.size();
    for (int i = 0; i < size; i++) {
        char symbol = sourceString[i];
        resultString = resultString + codeTable[symbol];
    }

    return resultString;
}
