#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<ll, ll> > ab(n);
    for(int i=0; i<n; i++){
        cin >> ab[i].first >> ab[i].second;
    }

    sort(ab.begin(), ab.end());

    ll sum = 0;
    ll count = 0;
    for(int i=0; i<m; i++){
        if(count+ab[i].second < m){
            sum += ab[i].first * ab[i].second;
            count += ab[i].second;
        }else{
            sum += (ab[i].first) * (m-count);
            count += m-count;
        }

        if(count == m){
            cout << sum << endl;
            return 0;
        }
    }  

    return 0;
}