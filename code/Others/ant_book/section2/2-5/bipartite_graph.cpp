#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
typedef pair<int, int> P;
const int inf = INT_MAX;
const ll INF = 1LL << 60;
const ll mod = 1e9+7;

int n, m;
vector<int> g[1001];
int used[1001]; // 0: まだ, -1: 黒, 1: 白

bool dfs(int v, int c){
    used[v] = c;
    // 1回でも矛盾が起きたらfalse
    rep(i, g[v].size()){
        if(used[g[v][i]] == c) return false;
        if(g[v][i] == 0 and !dfs(g[v][i], -c)) return false;
    }
    return true;
}

int main(){
    cin >> n >> m;
    fill(used, used+n, 0);
    rep(i, m){
        int tmp;
        cin >> tmp;
        rep(j, tmp){
            int a, b;
            cin >> a >> b;
            a--; b--;
            g[a].push_back(b);
            g[b].push_back(a);
        }
    }

    rep(i, n){
        if(used[i] == 0){
            if(!dfs(i, 1)){
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}