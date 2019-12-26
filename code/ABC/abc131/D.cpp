#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector< pair<ll, ll> > ba(n);
    for(int i=0; i<n; i++){
        cin >> ba[i].second >> ba[i].first;
    }
    sort(ba.begin(), ba.end());
    ll sum_a = 0;
    ll sum_b = 0;
    bool ans = true;
    for(int i=0; i<n; i++){
        sum_a += ba[i].second;
        if(sum_a > ba[i].first){
            ans = false;
            break;
        }
    }
    if(ans){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}