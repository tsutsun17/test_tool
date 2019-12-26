#include <bits/stdc++.h>
using namespace std;

// MARK: GCD
// 1. ユークリッドの互除法(2数)
int gcd(int x, int y){
    if(x<y) swap(x, y);
    if(y==0) return x;

    return gcd(y, x%y);
}

// MARK: LCM
// 1. x×y = gcd(x, y) × lcm(x, y)
int lcm(int x, int y){
    return x/gcd(x, y)*y;
}
