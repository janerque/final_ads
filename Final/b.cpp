#include <iostream>
#include <vector>
#include <deque>

using namespace std;
int INF;
int p[1000000];

int main(){
    deque<int> deque;
    vector<int> v;
    INF = 1e5;
    v.resize(10000);

    for(int i = 0; i < 10000; ++i)
        v[i] = INF;

    int a, b;
    cin >> a >> b;
    deque.push_front(a);
    v[a] = 0;

    vector<int> m;
    int c = b;

    while(deque.size()){
        if(deque.front() == b){
            while(b != a) {
                m.push_back(b);// m= 9
                b = p[b];//b=0
            }
        break;
        }
        else{
        int cur = deque.front();//cur = 5
        deque.pop_front();//deque = 0
            if(cur * 2 < 10000 && v[cur * 2] == INF){//5*2
                v[cur * 2] = v[cur] + 1;
                deque.push_back(cur * 2);
                p[cur * 2] = cur;
            }
            if(cur - 1 > 0 && v[cur - 1] == INF){
                v[cur - 1] = v[cur] + 1;
                deque.push_back(cur - 1);
                p[cur - 1] = cur;
            }
        }
    }
    cout << v[c] << endl;
    for(int i = (int)m.size() - 1; i >= 0; --i){
        cout << m[i] << ' ';
    }
}