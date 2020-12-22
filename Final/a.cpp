#include <iostream>
#include <stack>
using namespace std;

int main(){
    stack<char> ct;
    string s; 
    cin >> s;
    int cnt = 0;
    for(int i = 0; i < s.size(); i++) {
        if(ct.empty()) {
            ct.push(s[i]);
            cnt++;
            continue;
        } 
        if(s[i] == ct.top()) {
            cnt--;
            ct.pop();
        } 
        else {
            cnt++;
            ct.push(s[i]);
        } 
    }
    if(cnt == 0) 
        cout << "YES" << endl;
    else 
        cout << "NO" << endl;
    
}
