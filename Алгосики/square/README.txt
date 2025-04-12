#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
std::vector<std::set<int>> graf;
std::vector<int> used;
std::vector<int> path;
void dfs(int v) {
    used[v] = 1;
    for (auto to : graf[v]) {
        if (used[to] == 0) {
            path.push_back(to + 1);
            dfs(to);
            path.push_back(v + 1);
        }
    }
}
int main() {
    int n = 0, m = 0, v = 0;
    std::cin >> n >> m >> v;
    --v;
    graf.resize(n);
    used.assign(n, 0);
    for (int i = 0; i < m; ++i) {
        int x = 0, y = 0;
        std::cin >> x >> y;
        --x;
        --y;
        if (graf[x].find(y) != graf[x].end() || graf[y].find(x) != graf[y].end() || x == y) {
            continue;
        } else {
            graf[x].insert(y);
            graf[y].insert(x);
        }
    }
    path.push_back(v + 1);
    dfs(v);
    int s = path.size();
    std::cout << s << "\n";
    for (int i = 0; i < s; ++i) {
        std::cout << path[i] << " ";
    }

    return 0;
}