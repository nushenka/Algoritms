#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
int count = 0;
std::vector<std::string> field;
std::vector<std::pair<int, int> > steps{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
void dfs(int x, int y) {
    if (field[x][y] == '*')
        return;
    field[x][y] = '*';
    ++count;
    for (const auto& [dx, dy] : steps) {
        dfs(x + dx, y + dy);
    }
}
int main() {
    int n = 0;
    std::cin >> n;
    field.resize(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> field[i];
    }
    int st_x = 0, st_y = 0;
    std::cin >> st_x >> st_y;
    --st_x;
    --st_y;
    dfs(st_x, st_y);
    std::cout << count;
    return 0;
}