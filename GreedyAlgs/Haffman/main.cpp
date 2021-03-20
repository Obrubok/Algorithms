#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

//using Freq = std::pair<char, int>;

struct Freq {
    char letter;
    int priority;
    std::string code;
};

struct Node {
    char letter;
    std::string code;
    int priority;//?????
};

Freq ExtractMin(std::vector<Freq>&);
std::vector<Freq> Insert(std::map<char, int>&);
void Delete(std::vector<Freq>&, int);
int SizeOfQueue(std::vector<Freq>&);
std::map<char, int> CountOfDiffChars(std::string);
void SortQueue(std::vector<Freq>&);

int main() {
    std::string str;
    std::cout << "Введите последовательность букаф: " << std::endl;
    std::cin >> str;
    std::map <char, int> letters = CountOfDiffChars(str);
    std::map <char, std::string> codeTable;
    for (auto letter : letters) {
        codeTable.insert(std::make_pair(letter.first, ""));
    }
    std::vector<Freq> queueOfLetters;
    queueOfLetters = Insert(letters);
    SortQueue(queueOfLetters);

    std::cout << "Очередь: " << std::endl;
    for (auto member : queueOfLetters) {
        std::cout << member.letter << " : " << member.priority << std::endl;
    }
    std::cout << "Длина очереди: " << SizeOfQueue(queueOfLetters) << std::endl;
    std::cout << "Словарь: " << std::endl;
    for (auto code : codeTable) {
        std::cout << code.first << " : " << code.second << std::endl;
    }

    return 0;
}

Freq ExtractMin(std::vector<Freq> &queue) {
    Freq minPriority = queue[0];
    int minPriorityIndex = 0;
    for (int i = 1; i < sizeof(queue); i++) {
        if (queue[i].priority < minPriority.priority) {
            minPriority = queue[i];
            minPriorityIndex = i;
        }
    }

    Delete(queue, minPriorityIndex);

    return minPriority;
}

std::vector<Freq> Insert(std::map<char, int> &letters) {
    std::vector<Freq> queue;
    for (auto letter : letters) {
        Freq node;
        node.letter = letter.first;
        node.priority = letter.second;
        queue.push_back(node);
    }

    return queue;
}

void Delete(std::vector<Freq> &queue, int index) {
    queue.erase(queue.cbegin() + index);
}

int SizeOfQueue(std::vector<Freq> &queue) {
    return queue.size();
}

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

void SortQueue(std::vector<Freq> &queue) {
    std::sort(queue.begin(), queue.end(), [](Freq first, Freq second) -> bool {
        return first.priority > second.priority;
    });
}
