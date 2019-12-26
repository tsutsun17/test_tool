#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> h(n);
    for(int i=0; i<n; i++){
        cin >> h[i];
    }
    vector<int> dp(n);
    dp[0] = 0;

    for(int i=1; i<n; i++){
        int kk =0;
        if(i-k > 0){
            kk = i-k;
        }
        for(int j=kk; j<i; j++){
            if(j==kk){
                dp[i] = dp[j] + abs(h[i] - h[j]);
            }else{
                dp[i] = min(dp[j] + abs(h[i] - h[j]), dp[i]);
            }
        }
    }

    cout << dp[n-1] << endl;
    return 0;
}