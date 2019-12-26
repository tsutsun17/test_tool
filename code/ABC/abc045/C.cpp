#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int inf = 1<<21;
const ll INF = 1LL << 60;
const ll mod = 1e9+7;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    ll ans = 0;
    for(int bit=0; bit<(1<<s.size()-1); bit++){
        bool pre;
        string ss = "0";
        rep(i, s.size()){
            if(i==0){
                pre = (bit & (1<<i));
                ss += s[i];
            }else{
                if(((bit & (1<<i))>0 and pre>0) or ((bit & 1<<i)==0 and pre==0)){
                    ss += s[i];
                }else{
                    ans += stoll(ss);
                    ss = s[i];
                    pre = !pre;
                }
            }
        }
        ans += stoll(ss);
        ss = "0";
    }
    cout << ans << endl;
    return 0;
}