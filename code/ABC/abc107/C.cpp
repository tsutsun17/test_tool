#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// TIPS: intの上限は2^31-1

// DAME:
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> x(n);
    for(int i=0; i<n; i++){
        cin >> x[i];
    }

    int result = pow(2, 29);
    for(int i=0; i+(k-1)<n; i++){
        int tmp = 0;
        tmp += x[i+k-1] - x[i];
        tmp += min(abs(x[i]), abs(x[i+k-1]));
        result = min(result, tmp);
    }
    cout << result << endl;
    return 0;
}