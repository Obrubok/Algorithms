#include <iostream>
#include <vector>

using PAIR = std::pair<std::string, long>;

void GetData(std::istream &inputs, long & count, std::vector<PAIR> & coms);

int main() {


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