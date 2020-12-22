#include <iostream>
#include <vector>

using namespace std;
vector<int> g[110];
bool used[110];
int n, m;

void dfs(int node) {
    used[node] = true;
    for (int v : g[node]) {
        if (!used[v]) {
            dfs(v);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    } 
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            dfs(i);
            cnt++;
        }
    }
    cout << cnt - 1;
}