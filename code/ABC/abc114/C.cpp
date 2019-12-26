#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)
using namespace std;
typedef long long ll;
const int inf = INT_MAX;
const ll INF = 1LL >> 60;
const ll mod = 1e9+7;

// DAME:
/*
    3,5,7を使ったものを全列挙して、
    3,5,7を一回以上使っていたらans++する
*/
ll n, ans=0;
void dfs(ll x, int a, int b, int c){
    if(x>n) return;
    // 3, 5, 7が一回以上使われている
    if(a and b and c) ans++;
    // 3, 5, 7を右から追加する
    dfs(x*10+3, 1, b, c);
    dfs(x*10+5, a, 1, c);
    dfs(x*10+7, a, b, 1);
}

int main() {
    cin >> n;
    dfs(0, 0, 0, 0);
    cout << ans << endl;
    return 0;
}