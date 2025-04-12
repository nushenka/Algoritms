#include <algorithm>
#include <iostream>
#include <vector>

void Func(const std::vector<int>& colors, const std::vector<int>& cnt) {
    for (const int& el : cnt) {
        auto lb = std::lower_bound(colors.begin(), colors.end(), el);
        auto rb = std::upper_bound(colors.begin(), colors.end(), el);
        std::cout << (rb - lb) << "\n";
    }
}
int main() {
    int n = 0;
    std::cin >> n;
    std::vector<int> colors(n);
    for (int& el : colors) {
        std::cin >> el;
    }
    int m = 0;
    std::cin >> m;
    std::vector<int> cnt(m);
    for (int& el : cnt) {
        std::cin >> el;
    }
    Func(colors, cnt);
    return 0;
}