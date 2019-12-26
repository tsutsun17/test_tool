#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// DAME:
/*
    dfsしながらしながら累積和
*/

vector<int> to[200005];
vector<int> ans;

// p は親の番号
void dfs(int v, int p=-1){
    for(int u: to[v]){
        // 無限ループ防止
        if(u==p) continue;
        // 累積和
        ans[u] += ans[v];
        dfs(u, v);
    }
}

int main(){
    int n, q;
    cin >> n >> q;
    for(int i=0; i<n-1; i++){
        int a, b;
        cin >> a >> b;
        --a, --b;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    ans.resize(n); // TIPS: resizeすると0うめされる
    for(int i=0; i<q; i++){
        int p, x;
        cin >> p >> x;
        --p;
        ans[p] += x;
    }

    dfs(0);
    for(int i=0; i<n; i++){
        cout << ans[i] << ' ';
    }

    return 0;
}