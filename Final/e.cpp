#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
int used[N],n, y[N], x[N];

void dfs(int v, int m){
    used[v] = 1;
    for(int i = 0; i < n; ++i){
        if(used[i] || abs(x[i] - x[v]) + abs(y[i] - y[v]) > m) 
            continue;
        else 
            dfs(i, m);
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> x[i] >> y[i];
    }
    int min = 0, maxi = 1e9, res = 1e9;
    while(min <= maxi){
        int m = (min + maxi) / 2;
        memset(used, 0 , sizeof used);
        dfs(0, m);
        if(used[n-1])
            res = m,
            maxi = m - 1;
        else 
            min = m + 1;
    }
    cout << res;
}