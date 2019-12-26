#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)
using namespace std;
typedef long long ll;
const int inf = INT_MAX;
const ll INF = 1LL << 60;
const ll mod = 1e9+7;

// MARK:　素数列挙

// 1. エラトステネスの篩
// 2からnまでの整数をまとめて入れる　-> 一番小さい数の倍数を振るい落としていく
// is_prime[i] == 0 ? is_prime: not prime   (0以外)
vector<int> sieve_of_eratosthenes(){
    int MAX = 101010;
    vector<int> is_prime(MAX, 1);
    is_prime[0] = is_prime[1] = 0;
    for(int i=2; i<MAX; ++i){
        if(!is_prime[i]) continue;
        for(int j=i*2; j<MAX; j+=i) is_prime[j] = 0;
    }

    return is_prime;
}