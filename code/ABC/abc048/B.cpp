#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll a, b, x;
    cin >> a >> b >> x;

    ll d = b/x;

    if(a==0){
        cout << d+1 << endl;;
    }else{
        cout << d-(a-1)/x << endl;
    }
    return 0;
}