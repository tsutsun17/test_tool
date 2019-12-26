#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using Graph = vector<vector<int>>;

// DAME: ハミルトンパス
vector<bool> seen;
int n, m, ans;
void dfs(const Graph &G, int v){
    bool all_seen = true;
    for(int i=0; i<n; i++){
        if(seen[i] == false && i!=v){
            all_seen = false;
            break;
        }
    }

    if(all_seen){
        ans++;
        return;
    }
    seen[v] = true;
    for(auto next_v : G[v]){
        if(seen[next_v]) continue;
        dfs(G, next_v);
    }
    seen[v] = false;
}

int main() {
    cin >> n >> m;

    Graph G(n);
    for(int i=0; i<m; ++i){
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    seen.assign(n, false);
    dfs(G, 0);

    cout << ans << endl;
    return 0;
}