#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define chmin(x,y) x = min(x,y)
using namespace std;
typedef long long ll;
const int INF = 1001001001;

int main() {
    int n;
    string s;
    cin >> n >> s;
    vector<int> w(n+1, 0), e(n+1, 0);
    rep(i, n){
        if(s[i] == 'W'){
            w[i+1]++;
        }else{
            e[i+1]++;
        }
        w[i+1] += w[i];
        e[i+1] += e[i];
    }

    int ans = INF;
    for(int i=0; i<n+1; i++){
        int tmp = e[n] - e[i] + w[i] - w[0];
        chmin(ans, tmp);
    }

    cout << ans << endl;
    return 0;
}
