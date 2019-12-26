#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// DAME:

/*
    エラトステネスのふるい: 1からnまでの素数をすべて求める
        2からnまでの整数をまとめて入れる　-> 一番小さい数の倍数を振るい落としていく
    +
    累積和
*/

int main() {
    int MAX = 101010;
    vector<int> is_prime(MAX, 1);
    is_prime[0] = 0;
    is_prime[1] = 0;

    // エラトステネスのふるい: 素数判定
    for(int i=2; i<MAX; ++i){
        if(!is_prime[i]){
            continue;
        }
        for(int j=i*2; j<MAX; j+=i){
            is_prime[j] = 0;
        }
    }

    // 207-like数かどうか
    vector<int> a(MAX, 0);
    for(int i=0; i<MAX; ++i){
        if(i%2==0){
            continue;
        }
        if(is_prime[i] && is_prime[(i+1)/2]){
            a[i] = 1;
        }
    }

    //　累積和
    vector<int> s(MAX+1, 0);
    for(int i=0; i<MAX; ++i){
        s[i+1] = s[i] + a[i];
    }

    // クエリ処理
    int q;
    cin >> q;

    for(int i=0; i<q; i++){
        int l, r;
        cin >> l >> r;
        r++;

        cout << s[r] - s[l] << endl;
    }

    return 0;
}