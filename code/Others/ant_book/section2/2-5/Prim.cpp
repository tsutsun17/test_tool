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

static const int MAX = 100;
static const int INFTY = (1<<21);

int n;
vector<P> M[MAX];   // M[from]:=(to, cost)
int d[MAX]; // 任意の点からその点に行くための暫定の最小重み
bool used[MAX];

// ダイクストラに似ている
void prim(int r){
    priority_queue<P, vector<P>, greater<P>> que; // (cost, point)
    fill(d, d+n, INFTY);
    fill(used, used+n, 0);
    que.push(make_pair(0, r));

    while(!que.empty()){
        int c = que.top().first;
        int u = que.top().second;
        que.pop();

        // 訪問済みだったらcontinue;
        if(used[u]) continue;
        used[u] = true;
        d[u] = c;
        rep(i, M[u].size()){
            int v = M[u][i].first;
            int cost = M[u][i].second;
            que.push(make_pair(cost, v));
        }
    }

}

int main(){
    cin >> n;
    rep(i, n)rep(j, n){
        int e; cin >> e;
        if(e==-1){
            M[i].push_back(make_pair(j, INFTY));
        }else{
            M[i].push_back(make_pair(j, e));
        }

        prim(0);

        rep(i, n){
            cout << d[i] << endl;
        }
    }
    return 0;
}