#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<int> h(n);
    for(int i=0; i<n; i++){
        cin >> h[i]; 
    }
    vector<ll> ans(n);
    ans[n-1] = 0;
    for(int i=n-2; i>=0; i--){
        if(h[i] >= h[i+1]){
            ans[i] = ans[i+1] + 1;
        }else{
            ans[i] = 0;
        }
    }
    cout << *max_element(ans.begin(), ans.end()) << endl;
    return 0;
}