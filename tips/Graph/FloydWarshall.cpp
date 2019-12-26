#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)
using namespace std;
typedef long long ll;
const int inf = INT_MAX;
const ll INF = 1LL << 60;
const ll mod = 1e9+7;

static const int MAX = 100;
static const ll INFTY = (1LL<<32);

// FloydWarshall
/*
    kが一番外のループである理由
        kまでのノードを使った時のi,j間の最短距離を更新していく
        kが0の時はi,jの直接距離が最短距離
        kが1の時は、１を使ったものとi,jの直接距離の短い方が最短距離
        kがnの時は、n-1までのノードを経由できるという条件での最短距離と、さらにnを経由した時の最短距離を比較
*/

int n;
ll d[MAX][MAX];

void floyd(){
    rep(k, n)rep(i, n){
        if(d[i][k] == INFTY) continue;
        rep(j, n){
            if(d[k][j] == INFTY) continue;
            chmin(d[i][j], d[i][k] + d[k][j]);
        }
    }
}

int main(){
    int e, u, v, c;
    cin >> n >> e;

    rep(i, n)rep(j, n) d[i][j] = ((i==j) ? 0: INFTY);
    rep(i, e){
        cin >> u >> v >> c;
        d[u][v] = c;
    }

    floyd();

    bool negative = false;
    rep(i, n){
        // 負の閉路がある
        if(d[i][i] < 0) negative = true;
    }

    if(negative){
        cout << "NEGATIVE CYCLE" << endl;
    }else{
        rep(i, n)rep(j, n){
            if(j) cout << " ";
            if(d[i][j] == INFTY) cout << "INF";
            else cout << d[i][j];
        }
        cout << endl;
    }

}