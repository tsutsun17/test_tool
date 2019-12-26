#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// 極限の問題
/*
    無限級数を公式で求めなくても、極限の性質で解ける
    S_n = sum + (1-p) * S_n-1
    で n→∞ すると、
    S_∞ = sum + (1-p) * S_∞
    S_∞ = sum/p
    で求まる
*/
int main() {
    int n, m;
    cin >> n >> m;

    ll sum = n*100 + m*1800;
    double x = 1 - pow(0.5, m);
    double ans = sum * pow(0.5, m) * pow(2, 2*m);
    cout << ans << endl;
    return 0;
}