#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> x(n);
    for(int i=0; i<n; i++){
        cin >> x[i];
    }
    int ans = 0;
    for(int i=0; i<n; i++){
        if(x[i] >= abs(k-x[i])){
            ans += abs(k-x[i]);
        }else{
            ans += x[i];
        }
    }
    cout << 2*ans << endl;
    return 0;
}