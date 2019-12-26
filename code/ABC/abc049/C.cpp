#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define chmin(x,y) x = min(x,y)
using namespace std;
typedef long long ll;
const int INF = 1001001001;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    for(int i=n-1; i>=0; i--){
        string ss;
        rep(j, 7){
            ss.push_back(s[i-j]);
        }
        if(ss=="remaerd"){
            i -= 6;
            continue;
        }
        ss = "";

        rep(j, 6){
            ss.push_back(s[i-j]);
        }
        if(ss=="resare"){
            i -= 5;
            continue;
        }

        ss = "";

        rep(j, 5){
            ss.push_back(s[i-j]);
        }
        if(ss=="esare" || ss=="maerd"){
            i -= 4;
            continue;
        }
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    return 0;
}