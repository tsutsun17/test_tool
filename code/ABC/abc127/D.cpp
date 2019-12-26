#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    vector<pair<ll, int> > cb(m);
    for(int i=0; i<m; i++){
        cin >> cb[i].second >> cb[i].first;
    }
    sort(a.begin(), a.end());
    sort(cb.begin(), cb.end(), greater<pair<ll, int> >());

    ll ans = 0;
    int index = 0;
    bool flag = true;
    for(int i=0; i<m; i++){
        if(flag){
            int count = 0;
            for(int j=index; j<index+cb[i].second; j++){
                if(a[j] >= cb[i].first){
                    flag = false;
                    break;
                }
                count++;
                a[j] = cb[i].first;
            }
            index += count;
        }else{
            break;
        }
    }

    for(int i=0; i<n; i++){
        ans += a[i];
    }

    cout << ans << endl;
    
    return 0;
}