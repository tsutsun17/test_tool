#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int inf = 1<<21;
const ll INF = 1LL << 60;
const ll mod = 1e9+7;

static const int MAX = 100002;

int n;
int K;
vector<P> G[MAX];
void BFS(int s, vector<int>& ans){
    queue<P> que;
    que.push(make_pair(s, 0));
    while(!que.empty()){
        int u = que.front().first;
        int pre = que.front().second;
        que.pop();
        int tmp = 0;
        rep(i, G[u].size()){
            int v = G[u][i].second;
            int index = G[u][i].first;
            tmp++;
            if(pre==tmp) tmp++;
            ans[index] = tmp;
            que.push(make_pair(v, tmp));
        }
        chmax(K, tmp);
    }
}

int main() {
    cin >> n;
    K=0;

    rep(i, n-1){
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(make_pair(i, b));
    }
    vector<int> ans(n-1, 0);
    BFS(0, ans);

    cout << K << endl;
    rep(i, n-1){
        cout << ans[i] << endl;
    }
    return 0;
}