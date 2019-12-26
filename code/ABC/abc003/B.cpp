#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)
using namespace std;
typedef long long ll;
const int inf = INT_MAX;
const ll INF = 1LL >> 60;
const ll mod = 1e9+7;

int main() {
    string s, t;
    cin >> s >> t;
    int n = s.size();
    bool flag = true;
    rep(i, n){
        if(s[i] != t[i]){
            if(s[i]=='@'){
                switch(t[i]){
                    case 'a':
                    case 't':
                    case 'c':
                    case 'o':
                    case 'd':
                    case 'e':
                    case 'r':
                        break;
                    default:
                        flag = false;
                        break;
                }
            }else if(t[i]=='@'){
                switch(s[i]){
                    case 'a':
                    case 't':
                    case 'c':
                    case 'o':
                    case 'd':
                    case 'e':
                    case 'r':
                        break;
                    default:
                        flag = false;
                        break;
                }
            }else{
                flag = false;
                break;
            }
        }

        if(!flag){
            break;
        }
    }

    if(flag){
        cout << "You can win" << endl;
    }else{
        cout << "You will lose" << endl;
    }
    return 0;
}