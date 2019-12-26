#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define chmin(x,y) x = min(x,y)
using namespace std;
typedef long long ll;
const int MAX = 1000;
const int VMAX = 10000;

int n, A[MAX], s;
int B[MAX], T[VMAX + 1];

// DAME:
int solve(){
    int ans = 0;

    bool V[MAX];
    rep(i, n){
        B[i] = A[i];
        V[i] = false;
    }

    sort(B, B+n);
    rep(i, n) T[B[i]] = i;
    rep(i, n){
        if(V[i]) continue;
        int cur = i, S = 0, m = VMAX, an = 0;
        while(1){
            V[cur] = true;
            an++;
            int v = A[cur];
            chmin(m, v);
            S += v;
            cur = T[v];
            if(V[cur]) break;
        }
        ans += min(S+(an-2)*m, m+S+(an+1)*s);
    }
    return ans;
}

int main(){
    cin >> n;
    s = VMAX;
    rep(i, n){
        cin >> A[i];
        chmin(s, A[i]);
    }
    int ans = solve();

    cout << ans << endl;
    return 0;
}