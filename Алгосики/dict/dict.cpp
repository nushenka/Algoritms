#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>

int main() {
    int n = 0;
    std::cin >> n;
    std::string word;
    int page = 0;
    std::map<int, std::set<std::string>> dict;
    for (int i = 0; i < n; ++i) {
        std::cin >> word >> page;
        std::map<int, std::set<std::string>>::iterator it = dict.find(page);
        if (it == dict.end()) {
            std::set<std::string> vec;
            vec.insert(word);
            dict.insert(std::make_pair(page, vec));
        } else {
            dict[page].insert(word);
        }
    }
    for (const auto& pair : dict) {
        std::cout << pair.first << " ";

        for (const auto& value : pair.second) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}