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

/*
    A xor B = C
    C xor A = B

    a, b
    0~b(A)と0~a-1(B)のxorを計算して
    A xor B = C(a~bのxor)

    F(A, B) = F(0, A − 1) ⊕ F(0, B)

    0からのxorを計算するときに、0と1は1, 2と３は1という法則を使うと楽
*/

ll solve(ll a){
    ll cnt = (a+1)/2;
    ll ans = cnt % 2;
    if(a%2==0) ans ^= a;
    return ans;
}

int main() {
    ll a, b;
    cin >> a >> b;
    ll ans;
    ans = solve(b) ^ solve(a-1);
    cout << ans << endl;

    return 0;
}