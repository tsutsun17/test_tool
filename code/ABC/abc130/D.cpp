#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// DAME: 

// TIPS: しゃくとり法 or 累積和+二分探索
/*
    しゃくとり法
        - l<rが必ず成り立つ
        - lとrを右だけに動かすためO(N)
        - 「条件」を満たす区間 (連続する部分列) のうち、最小の長さを求めよ
        - 「条件」を満たす区間 (連続する部分列) のうち、最大の長さを求めよ
        - 「条件」を満たす区間 (連続する部分列) を数え上げよ
*/
int main() {
    ll n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    // 区間の合計
    ll s = 0;
    // i: 左側の添字, j: 右側の添字
    int j = 0;
    // for文内のansはk未満の部分区間の数を出している
    ll ans = 0;
    for(int i=0; i<n; i++){
        while(j<n && s+a[j] < k){
            s += a[j];
            ++j;
        }
        ans += j-i;
        s -= a[i];
    }
    ans = (ll)n*(n+1)/2 - ans;
    cout << ans << endl;

    return 0;
}