#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
std::vector<std::vector<int>> graf;
std::vector<int> used;
bool isCycle = false;
void dfs(int v) {
    used[v] = 1;
    for (int to : graf[v]) {
        if (used[to] == 0) {
            dfs(to);
           
        } else if (used[to] == 1) {
            isCycle = true;
        }
    }
	used[v] = 2;
}
int main() {
    int n = 0;
    std::cin >> n;
    int c = 0;
    graf.resize(n);
    used.assign(n, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int x = 0;
            std ::cin >> x;
            if (x == 1) {
                graf[i].push_back(j);
            }
        }
    }
    for (int v = 0; v < n; ++v) {
        if (used[v] == 0) {
            dfs(v);
        }
    }
    std::cout << isCycle;
}