#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n, k;
    cin >> n >> k;
    map<int, ll> s;
    for(int i=0; i<n; i++){
        int a, b;
        cin >> a >> b;
        s[a] += b;
    }
    // mapの全列挙
    for(auto itr=s.begin(); itr!=s.end(); itr++){
        if(k<=itr->second){
            cout << itr->first << endl;
            break;
        }
        k-=itr->second;
    }
    return 0;
}