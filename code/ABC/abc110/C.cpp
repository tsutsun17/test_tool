#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define chmin(x,y) x = min(x,y)
using namespace std;
typedef long long ll;
const int INF = 1001001001;

vector<char> ss{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

// TIPS:
/*
    int a = s[i] - 'a';
    でcharをintに変換できる
*/

int main() {
    string s, t;
    cin >> s >> t;
    int n = s.size();
    map<char, int> sm, tm;

    int tmp = 1;
    rep(i, n){
        if(sm[s[i]] == 0){
            sm[s[i]] = tmp;
            tmp++;
        }
    }

    tmp = 1;
    rep(i, n){
        if(tm[t[i]] == 0){
            tm[t[i]] = tmp;
            tmp++;
        }
    }

    rep(i, n){
        s[i] = ss[sm[s[i]]];
        t[i] = ss[tm[t[i]]];
    }

    if(s == t){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}