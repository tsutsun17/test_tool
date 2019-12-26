#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int inf = 1<<21;
const ll INF = 1LL >> 60;
const ll mod = 1e9+7;

/*
    牛ゲー
    最短経路問題の双対問題を考えると線形計画問題になる
    d[i]: 1番目からi番目までの距離
    (AL < BL, AD < BD)
    d[AL] + DL >= d[BL]
    d[BD] - DD >= d[AD]
    d[i+1] - 0 >= d[i]

    d[i] + c >= d[i+1]の考えができるものは最短経路問題にできるのか？
    ここで求まるのは条件を満たした最大距離

*/

vector<P> edges[10002];
int d[1002];
int n,ML,MD;

void bellman(int s){
    fill(d, d+n, inf);
    d[s] = 0;
    while(true){
        bool update = false;
        rep(i, n)rep(k, edges[i].size()){
            P e = edges[i][k];
            if(d[i] != inf and d[e.first] > d[i] + e.second){
                d[e.first] = d[i] + e.second;
                update = true;
            }
        }
        if(!update) break;
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> ML >> MD;
    // d[i+1] - 0 >= d[i]
    rep(i, n-1) edges[i+1].push_back(make_pair(i, 0));
    // d[AL] + DL >= d[BL]
    rep(i, ML){
        int from, to, cost;
        cin >> from >> to >> cost;
        from--; to--;
        edges[from].push_back(make_pair(to, cost));
    }
    // d[AD] - DD >= d[BD]
    rep(i, MD){
        int from, to, cost;
        cin >> from >> to >> cost;
        from--; to--;
        edges[to].push_back(make_pair(from, -cost));
    }

    bellman(0);

    rep(i, n) cout << d[i] << endl;

    return 0;
}