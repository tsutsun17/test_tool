#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n, sum;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    int ans = 1e9+7;
    for(int i=-100; i<=100; i++){
        int sum = 0;
        for(int j=0; j<n; j++){
            sum += pow((a[j] - i), 2);
        }
        ans = min(ans, sum);
    }
    cout << ans << endl;
    return 0;
}