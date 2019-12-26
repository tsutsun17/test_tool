#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
const int inf = INT_MAX;
const ll INF = 1LL << 60;
const ll mod = 1e9+7;

int main() {
    int n;
    cin >> n;
    if(n%2 == 0){
        cout << n/2 -1 <<endl;
    }else{
        cout << n/2 << endl;
    }
    return 0;
}
