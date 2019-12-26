#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n, m, x;
    cin >> n >> m >> x;
    map<int, int> a;
    for(int i=0; i<m; i++){
        int aa;
        cin >> aa;
        aa--;
        a[aa]++;
    }
    int ans_a = 0;
    int ans_b = 0;
    for(int i=x-1; i<n; i++){
        ans_a += a[i];
    }

    for(int i=x-1; i>=0; i--){
        ans_b += a[i];
    }

    cout << min(ans_a, ans_b) << endl;

    return 0;
}