#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<ll> x(n);
    vector<ll> sort_x(n);
    for(int i=0; i<n; i++){
        cin >> x[i];
        sort_x[i] = x[i];
    }

    sort(sort_x.begin(), sort_x.end());
    ll min_x = sort_x[n/2-1];
    ll max_x = sort_x[n/2];

    for(int i=0; i<n; i++){
        if(x[i]<max_x){
            cout << max_x << endl;
        }else{
            cout << min_x << endl;
        }
    }
    return 0;
}