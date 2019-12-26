#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// 全パターン拡張(二次元dp)
int main() {
    int n;
    cin >> n;
    vector<vector<int> > a(n, vector<int>(3));
    for(int i=0; i<n; i++){
        for(int j=0; j<3; j++){
            cin >> a[i][j];
        }
    }

    vector<vector<int> > dp(n, vector<int>(3));
    dp[0][0] = a[0][0];
    dp[0][1] = a[0][1];
    dp[0][2] = a[0][2];

    for(int i=1; i<n; i++){
        for(int j=0; j<3; j++){
            for(int k=0; k<3; k++){
                if(k==j){
                    continue;
                }
                dp[i][k] = max(dp[i-1][j] + a[i][k], dp[i][k]);
            }
        }
    }
    cout << max(dp[n-1][0], max(dp[n-1][1], dp[n-1][2])) << endl;

    return 0;
}