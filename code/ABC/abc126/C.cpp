#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    double n, k;
    cin >> n >> k;
    double ans;

    for(int i=1; i<n+1; i++){
        int score = 0;
        score += i;
        double m = 1/n;

        while(score<k){
            score*=2;
            m/=2;
        }
        ans += m;
    }
    // TIPS: setprecisionでdoubleの精度を調整できる
    cout << setprecision(12) << ans << endl;
    return 0;
}