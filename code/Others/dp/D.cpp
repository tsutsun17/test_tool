#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// ナップサックdp
int main() {
    int n;
    ll W;
    cin >> n >> W;
    vector<ll> weight(n+1);
    vector<ll> value(n+1);

    weight[0] = 0;
    value[0] = 0;

    for(int i=1; i<n+1; i++){
        cin >> weight[i] >> value[i];
    }

    // dp[i][w]: i番目の商品で合計の重さがwを超えない時の最大合計value
    vector<vector<ll> > dp(n+1, vector<ll>(W+1));
    // 初期値: ０番目の時は全て０
    for(int i=0; i<=W; i++){
        dp[0][i] = 0;
    }

    for(int i=1; i<n+1; i++){
        for(ll w=0; w<=W; w++){
            if(w >= weight[i]){
                dp[i][w] = max(dp[i-1][w-weight[i]] + value[i], dp[i-1][w]);
            }else{
                dp[i][w] = max(dp[i-1][w], dp[i][w]);
            }
        }
    }

    cout << dp[n][W] << endl;

    return 0;
}