#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define chmin(x,y) x = min(x,y)
using namespace std;
typedef long long ll;
const int INF = 1001001001;


int gcd(int a, int b){
    if(a<b){
        swap(a,b);
    }
    if(b==0) return a;
    return gcd(b, a%b);
}

int main() {
    int n;
    ll X;
    cin >> n >> X;
    vector<ll> x(n);

    rep(i, n) cin >> x[i];
    rep(i, n) x[i] = abs(X - x[i]);
    rep(i, n){
        if(i==0) continue;
        x[i] = gcd(x[i-1], x[i]);
    }

    cout << x[n-1] << endl;

    return 0;
}