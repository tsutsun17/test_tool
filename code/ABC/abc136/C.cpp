#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<ll> h(n);
    for(int i=0; i<n; i++){
        cin >> h[i];
    }
    bool flag = true;
    for(int i=n-1; i>=1; i--){
        if(h[i]-h[i-1]==-1){
            h[i-1] -= 1;
        }else if(h[i-1]>h[i]){
            flag = false;
            break;
        }
    }
    if(flag){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}