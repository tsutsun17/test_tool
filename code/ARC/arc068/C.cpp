#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll x;
    cin >> x;
    ll a = floor(x/11);
    if(x%11==0){
        cout << 2*a << endl;
        return 0;
    }
    if(x%11<=6){
        cout << 2*a + 1 << endl;
        return 0;
    }
    cout << 2*a+2 << endl;
    return 0;
}