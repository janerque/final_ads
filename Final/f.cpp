#include <iostream>
#include <cmath>
#include <queue>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    long long b = 0;
    long long a[n];
    vector<long long> v;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        v.push_back(b); 
        b += a[i];
    }
    v.push_back(b);
    sort(v.begin(), v.end());
    long long res = 1e18;
    for(int i = 1; i < v.size(); ++i){
        res = min(res, v[i] - v[i - 1]);
    }
    cout << res << endl;
    return 0;
}