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

/*
    負の閉路がなければ最短距離が求まる
    負の辺があっても良い
    負の辺がない時はDijkstraをした方が良い
*/

int n, m;   // n: 頂点数, m: 辺数
vector<P> edge[10000];  // to, cost
int d[10000];   // d[i] := sからiへの暫定最短距離

void bellman(int s){
    fill(d, d+n, inf);
    d[s] = 0;
    while(true){
        bool update = false;
        rep(i, n)rep(k, edge[i].size()){
            P e = edge[i][k];
            if(d[i] != inf and d[e.first] > d[i] + e.second){
                d[e.first] = d[i] + e.second;
                update = true;
            }
        }
        if(!update) break;
    }
}

int main(){
    int u, k, v, c;
    cin >> n >> m;
    rep(i, m){
        cin >> u >> k;
        rep(j, k){
            cin >> v >> c;
            edge[u].push_back(make_pair(v, c));
        }
    }

    bellman(0);
    rep(i, n) cout << d[i] << endl;

    return 0;
}