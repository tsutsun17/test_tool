#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)
using namespace std;
typedef long long ll;
const int inf = INT_MAX;
const ll INF = 1LL << 60;
const ll mod = 1e9+7;

// 冪乗
/*
    普通はO(N)
    繰り返し自乗法
        pow(x,n) = 1                // nが0
                 = pow(x^2. n/2)    // nが偶数
                 = pow(x^2, n/2)*x  // nが奇数

    O(logN)
*/

// unsignedは正の数字のみとなるため、1ビット分長くなる
typedef unsigned long long ull;

ull power(ull x, ull n, ull M){
    ull res = 1;
    if(n>0){
        res = power(x, n/2, M);
        if(n%2==0) res = (res*res)%M;
        else res = (((res*res)%M)*x)%M;
    }
    return res;
}

int main(){
    int m, n;
    cin >> m >> n;
    cout << power(m,n,1000000007) << endl;
    return 0;
}