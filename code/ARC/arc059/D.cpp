#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// DAME:

// 2or3だけ調べれば良い
int main() {
    string s;
    cin >> s;
    if(s[0] == s[1]){
        cout << 1 << ' ' << 2 << endl;
        return 0;
    }
    for(int i=2; i<s.size(); i++){
        if(s[i] == s[i-1]){
            cout << i  << ' ' << i+1 << endl;
            return 0;
        }
        if(s[i] == s[i-2]){
            cout << i-1 << ' ' << i+1 << endl;
            return 0;
        }
    }

    cout << -1 << ' ' << -1 << endl;
 
    return 0;
}