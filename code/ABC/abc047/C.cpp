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
    char prev = s[0];
    int count = 0;
    rep(i, n){
        if(i==0) continue;
        if(s[i]!=prev){
            count++;
            prev = s[i];
        }
    }

    cout << count  << endl;
    return 0;
}