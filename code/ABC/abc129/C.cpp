#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;

// DAME:
// TIPS: DP
/*
    (考え方) わかっている部分から他を求める。
        1. dp[i]をi段目からn段目までの進み方とすると、後ろから求める
        2. dp[i]をi段までの進み方とすると、前から求める
*/


// 後ろから埋めていく
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> broken(n+1);
    int a; 
    for(int i=0; i<m; i++){
        cin >> a;
        broken[a] = 1;
    }

    vector<int> dp(n+2);
    dp[n] = 1;
    for(int i=n-1; i >= 0; i--){
        if(broken[i]){
            dp[i] = 0;
            continue;
        }
        dp[i] = (dp[i+1]+dp[i+2]) % mod;
    }
    cout << dp[0] << endl;
    return 0;
}

// 前から埋めていく
int main(){
        int n, m;
    cin >> n >> m;
    vector<int> broken(n+1);
    int a; 
    for(int i=0; i<m; i++){
        cin >> a;
        broken[a] = 1;
    }

    vector<int> dp(n+1);
    dp[0] = 1;
    for(int i=1; i <= n; i++){
        if(broken[i]){
            dp[i] = 0;
            continue;
        }
        if(i==1){
            dp[i] = dp[i-1];
            continue;
        }
        dp[i] = (dp[i-1]+dp[i-2]) % mod;
    }
    cout << dp[n] << endl;
    return 0;
}