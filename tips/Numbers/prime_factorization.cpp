#include <bits/stdc++.h>
using namespace std;

// MARK: 素因数分解
/*
    (n)^1/2以上の素因数はたかだか１個まで
*/

// vector.emplace_back: 値をそのまま突っ込む
// vector.push_back: 値を突っ込む前に一回作ってからコピーを突っ込む

// TIPS:
/*
    キャスト
    string to int
        stoi()
    string to ll
        stoll()

*/

// vector(素因数, 乗数)
vector<pair<int, int> > factorize(int n){
    vector< pair<int, int> > res;
    // nが変化していく
    for(int i=2; i*i <= n; ++i){
        if(n%i) continue;
        res.emplace_back(i, 0);
        while(n%i==0){
            n/=i;
            res.back().second++;
        }
    }
    if(n != 1) res.emplace_back(n, 1);
    return res;
}

