#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// DAME:
int gcd(int x, int y){
    if(x>y){
        swap(x, y);
    }
    if(x==0){
        return y;
    }
    int amari = y%x;
    return gcd(amari, x);
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    vector<int> gcd_l(n);

    // TIPS: i番目の左側と右側で分けて求めていく
    // L[i]はi番目までの最大公約数 i=0~n 1~n
    // R[i]はi番目からの最大公約数 i=0~n 0~n-1
    // i番目を抜いたものの最大公約数はgcd(L[i], R[i+1])となる
    vector<int> L(n+1);
    vector<int> R(n+1); 
    L[0] = 0;
    R[n] = 0;
    for(int i=1; i<n+1; i++){
        L[i] = gcd(L[i-1], a[i-1]);
    }
    for(int i=n-1; i>=0; i--){
        R[i] = gcd(R[i+1], a[i]);
    }
    for(int i=0; i<n; i++){
        gcd_l[i] = gcd(L[i], R[i+1]);
    }
    cout << *max_element(gcd_l.begin(), gcd_l.end()) << endl;

    return 0;
}