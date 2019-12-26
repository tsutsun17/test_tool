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
    int x;
    cin >> x;
    if(x==3 or x==5 or x==7){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }

    return 0;
}