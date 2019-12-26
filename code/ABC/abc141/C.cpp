#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n, q;
    ll k;
    cin >> n >> k >> q;

    vector<ll> score(n, k-q);

    for(ll i=0; i<q; i++){
        ll aa;
        cin >> aa;
        score[aa-1]++;
    }

    for(ll i=0; i<n; i++){
        if(score[i]<=0){
            cout << "No" << endl;
        }else{
            cout << "Yes" << endl;
        }
    }

    return 0;
}