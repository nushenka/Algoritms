#include <iostream>
#include <string>
#include <vector>
int ScalarProduct(const std::vector<int>& vec1, const std::vector<int>& vec2) {
    int res = 0;
    size_t size = vec1.size();
    for (size_t i = 0; i != size; ++i) {
        res += vec1[i] * vec2[i];
    }
    return res;
}

int main() {
    int m = 0;
    int n = 0;
    int max_value = std::numeric_limits<int>::min();
    std::string max_word;
    std::cin >> m >> n;
    std::vector<std::string> words;
    std::vector<std::vector<int>> coordinates;
    std::vector<std::string> res;
    words.resize(m);
    coordinates.resize(m, std::vector<int>(n));
    for (int i = 0; i < m; ++i) {
        std::cin >> words[i];
        for (int j = 0; j < n; ++j) {
            std::cin >> coordinates[i][j];
        }
    }
    for (int i = 1; i < m; ++i) {
        int product = 0;
        product = ScalarProduct(coordinates[0], coordinates[i]);
        if (product > max_value) {
            max_value = product;
            res.clear();
            res.push_back(words[i]);
        } else if (product == max_value) {
            res.push_back(words[i]);
        }
    }
    size_t s = res.size();
    for (size_t i = 0; i != s; ++i) {
        std::cout << res[i] << '\n';
    }
}