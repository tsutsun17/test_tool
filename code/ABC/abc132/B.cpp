#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
typedef pair<int, int> P;
const int inf = 1<<21;
const ll INF = 1LL << 60;
const ll mod = 1e9+7;

int main() {
    int n;
    cin >> n;
    vector<int> p(n);
    int count = 0;
    rep(i, n) cin >> p[i];

    rep(i, n-1){
        if(i==0) continue;
        if((p[i]<p[i+1] and p[i-1] < p[i]) or (p[i]<p[i-1] and p[i+1]<p[i])){
            count++;
        }
    }
    cout << count << endl;
    return 0;
}