#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>

using PAIR = std::pair<std::string, long>;

void GetData(std::istream &inputs, long & count, std::vector<PAIR> & coms);

class Heap {
private:
    long maxHeap[100000];
    long count;

    void SiftDown(long it);
    void SiftDown2(long it);
    void SiftUp(long it);
    long GetCount();
public:
    Heap();
    void Insert(long p);
    long ExtractMax();
    //void Remove(long it);
    //long GetMax();
    //void ChangePriority(long it, long p);
};

Heap::Heap() {
    this->count = 0;
}

long Heap::ExtractMax() {
    long value = -1;
    if (count != 0) {
        value = maxHeap[0];
        maxHeap[0] = maxHeap[count - 1];
        count--;
        SiftDown(0);
    }
    return value;
}

void Heap::Insert(long p) {
    maxHeap[count] = p;
    count++;
    SiftUp(count-1);
}

void Heap::SiftDown(long it) {
    if (count < 2) {
        return;
    }
    long left = 2 * it + 1;
    long right = 2 * it + 2;
    while (left < count) {
        long chanIt = left;
        if (maxHeap[right] > maxHeap[left] && right < count) {
            chanIt = right;
        }
        if (maxHeap[it] < maxHeap[chanIt]) {
            std::swap(maxHeap[it], maxHeap[chanIt]);
        } else {
            return;
        }
        it = chanIt;
        left = 2 * it + 1;
        right = 2 * it + 2;
    }
}

void Heap::SiftDown2(long it) {
    while (2 * it + 1 < count) {
        long left = 2 * it + 1;
        long right = 2 * it + 2;
        long j = left;
        if (right < count && maxHeap[right] > maxHeap[left]) {
            j = right;
        }
        if (maxHeap[it] >= maxHeap[j]) {
            break;
        }
        std::swap(maxHeap[it], maxHeap[j]);
        it = j;
    }
}

void Heap::SiftUp(long it) {
    if (count < 2) {
        return;
    }
    while (it > 0 && maxHeap[it] > maxHeap[(it - 1) / 2]) {
        std::swap(maxHeap[it], maxHeap[(it - 1) / 2]);
        it = (it - 1) / 2;
    }
}

int main() {
    std::string file = "/home/alexey/proging/C++/GreedyAlgs/Heap/debug.txt.buc3";
    std::ifstream data;
    data.open(file);
    Heap heap;
    long comsCount;
    std::vector<PAIR> commands;
    GetData(data, comsCount,commands);

    for (long i = 0; i < comsCount; i++) {
        if (commands[i].first == "ExtractMax") {
            std::cout << heap.ExtractMax() << std::endl;
        } else {
            heap.Insert(commands[i].second);
        }
    }

    return 0;
}

void GetData(std::istream &inputs, long & count, std::vector<PAIR> & coms) {
    std::istringstream iss;
    std::string str;
    std::getline(inputs, str, '\n');
    iss.str(str);
    iss >> count;
    iss.clear();
    for (long i = 0; i < count; i++) {
        std::getline(inputs, str);
        if (str == "ExtractMax") {
            coms.push_back(std::make_pair(str, 0));
        } else {
            iss.str(str);
            std::string tmpStr;
            long tmpInt;
            iss >> tmpStr >> tmpInt;
            coms.push_back(std::make_pair(tmpStr, tmpInt));
            iss.clear();
        }
    }
}
