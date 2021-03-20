#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <fstream>

using STRING = std::string;
using TABLE = std::map<char, std::string>;

struct HuffmanBinaryNode {
    STRING letter;
    HuffmanBinaryNode *leftChild;
    HuffmanBinaryNode *rightChild;

    HuffmanBinaryNode() {};

    HuffmanBinaryNode(char _letter, HuffmanBinaryNode * _left, HuffmanBinaryNode * _right) {
        this->letter = _letter;
        this->leftChild = _left;
        this->rightChild = _right;
    }

    HuffmanBinaryNode(STRING _letter, HuffmanBinaryNode * _left, HuffmanBinaryNode * _right) {
        this->letter = _letter;
        this->leftChild = _left;
        this->rightChild = _right;
    }

    HuffmanBinaryNode(HuffmanBinaryNode * _left, HuffmanBinaryNode * _right) {
        this->leftChild = _left;
        this->rightChild = _right;
    }

    ~HuffmanBinaryNode() {
        delete this->leftChild;
        delete this->rightChild;
        std::cout << "Узел удален" << std::endl;
    }
};

void TrimCharsByCond(STRING &, char chr);
TABLE GetCodeTable(std::istream & inputs, int count);
HuffmanBinaryNode * BuildHuffmanTree(TABLE & codeTable);
STRING BuildDecodedString(HuffmanBinaryNode * root, STRING & str, int length);

int main() {
    // Ввод данных
//    int countOfChars;
//    int stringLength;
//    STRING encodedString;
//    std::cin >> countOfChars >> stringLength;
//    std::cin.ignore();
//    TABLE codeTable = GetCodeTable(std::cin, countOfChars);
//    std::cin >> encodedString;

    // Ввод данных из файла ОТЛАДКА
    int countOfChars;
    int stringLength;
    STRING encodedString;
    std::ifstream debugData;
    const STRING file = "/home/alexey/proging/C++/GreedyAlgs/HuffmanRevrs/debug.txt";
    debugData.open(file);

    debugData >> countOfChars >> stringLength;
    debugData.ignore();
    TABLE codeTable = GetCodeTable(debugData, countOfChars);
    debugData >> encodedString;

    HuffmanBinaryNode * root = BuildHuffmanTree(codeTable);

    // Декодирование строки
    STRING word = BuildDecodedString(root, encodedString, stringLength);
    std::cout << "Получившееся слово: " << word << std::endl;

    delete root;

    return 0;
}

void TrimCharsByCond(STRING & str, char chr) {
    int i = -1;
    while ((i = str.find(chr)) != std::string::npos) {
        str.erase(i, 1);
    }
}

TABLE GetCodeTable(std::istream &inputs, int count) {
    TABLE codeTable;
    std::istringstream iss;
    STRING str;
    char key;
    STRING value;

    for (int i = 0; i < count; i++) {
        std::getline(inputs, str, '\n');
        TrimCharsByCond(str, ':');
        iss.clear();
        iss.str(str);
        iss >> key >> value;
        codeTable[key] = value;
    }

    return codeTable;
}

HuffmanBinaryNode ExtractLast(std::vector<HuffmanBinaryNode> & queue) {
    HuffmanBinaryNode node = queue[queue.size() - 1];
    queue.pop_back();
    return node;
}

HuffmanBinaryNode * BuildHuffmanTree(TABLE &codeTable) {
    HuffmanBinaryNode * root = new HuffmanBinaryNode("root", NULL, NULL);
    for (auto & letter : codeTable) {
        char chr = letter.first;
        STRING code = letter.second;
        int codeLength = code.length();
        HuffmanBinaryNode * current = root;
        int i = 0;
        while (i < codeLength) {
            HuffmanBinaryNode * parent = current;
            if (code[i] == '0') {
                if (!parent->leftChild) {
                    parent->leftChild = new HuffmanBinaryNode(NULL, NULL);
                }
                current = current->leftChild;
            } else {
                if (!parent->rightChild) {
                    parent->rightChild = new HuffmanBinaryNode(NULL, NULL);
                }
                current = current->rightChild;
            }
            i++;
        }
        current->letter = chr;
    }

    return root;
}

STRING BuildDecodedString(HuffmanBinaryNode * root, STRING &  str, int length) {
    HuffmanBinaryNode * current = root;
    STRING word = "";
    for (int i = 0; i < length; i++) {
        switch (str[i]) {
            case '0':
                if (current->leftChild != NULL) {
                    current = current->leftChild;
                    if (current->leftChild == NULL && current->rightChild == NULL) {
                        word += current->letter;
                        current = root;
                    }
                }
                break;
            case '1':
                if (current->rightChild !=NULL) {
                    current = current->rightChild;
                    if (current->leftChild == NULL && current->rightChild == NULL) {
                        word += current->letter;
                        current = root;
                    }
                }
                break;
        }
    }

    return word;
}
