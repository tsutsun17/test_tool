#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)
using namespace std;
typedef long long ll;
const int INF = 1001001001;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    rep(i, n){
        if(i==0) continue;
        int cnt = 0;
        for(char c='a'; c<='z'; c++){
            bool left=false, right=false;

            rep(j, i) if(s[j]==c) left=true;
            for(int j=i; j<n; j++){
                if(s[j]==c) right=true;
            }

            if(left and right) cnt++;
        }

        chmax(ans, cnt);
    }

    cout << ans << endl;
    return 0;
}