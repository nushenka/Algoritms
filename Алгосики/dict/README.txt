#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    size_t n = 0;
    size_t m = 0;
    std::cin >> n;
    std::vector<std::string> sinonym1(n);
    std::vector<std::string> sinonym2(n);
    std::unordered_map<std::string_view, std::string_view> dict;
    for (size_t i = 0; i < n; ++i) {
        std::cin >> sinonym1[i] >> sinonym2[i];
        dict[sinonym1[i]] = sinonym2[i];
        dict[sinonym2[i]] = sinonym1[i];
    }
    std::cin >> m;
    std::string k;
    for (size_t i = 0; i < m; ++i) {
        std::cin >> k;
        std::cout << dict[k] << "\n";
    }

    return 0;
}