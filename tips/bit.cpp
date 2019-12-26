#include <bits/stdc++.h>
using namespace std;


// MARK: bitを用いたフラグ管理

/*
    1. i番目にフラグが立っている
        1<<i

    2. bitにi番目のフラグが立っているかどうか
        if(bit & 1<<i)

    3. bitにi番目のフラグを立てる
        bit |= 1<<i

    4. bitにi番目のフラグを消す
        bit &= 1<<i

    5. bitに何個のフラグが立っているか
        __builtin_popcount(bit)

    6. bitにi番目のフラグを立てたもの
        bit | 1<<i

    7. bitにi番目のフラグを消したもの
        bit & ~(1<<i)
*/

// MARK: 偶奇判定
/*
    int a = 201;
    if(a & 1){
        cout << "奇数" << endl;
    }else{
        cout << "偶数" << endl;
}
*/

// MARK: bitset

// MARK: マスクビット: 必要な情報を取り出すためにビットごとのAND演算を行う場合に使うビットパターン.
// 取り出す部分のビットは1, それ以外は全て0となっている

/*
    1. maskで表された部分のフラグをまとめて立てる
        bit |= mask

    2. maskで表された部分のフラグをまとめて消す
        bit &= ~mask

    3. maskで表された部分の情報のみを取り出したもの
        bit & mask

    4. maskで表された部分のどれかのフラグが立っているかどうか
        if(bit & mask)

    5. maskで表された部分の全てのフラグが立っているかどうか
        if((bit & mask) == mask)
*/



// MARK: bit全探索(部分和問題に使われる)

// 1~n-1
int bit_full_search(int n){
    // n個の要素
    // {0, 1, ..., n-1}の部分集合の全探索 2^n回のloop
    for(int bit=0; bit < 1<<n; ++bit){
        // bitであわらされる集合の処理
    }

}

// 例: n-1までで{2, 3, 5, 7}の部分集合
int bit_full_search_a(){
    int n = 10;
    int A = (1<<2) | (1<<3) | (1<<5) | (1<<7); // A = {2, 3, 5, 7}

    for(int bit=A; ; bit=(bit-1) & A){
        //ここに処理をかく


        // 最後の 0 でbreak;
        if(!bit) break;
    }
}

// TODO: 理解
// MARK: next_combination: {0, 1, ... , n-1}の部分集合のうち、要素数がkのもののみを列挙する

int next_combination(int sub){
    int x = sub & -sub;
    int y = sub + x;

    return (((sub & -y) / x) >> 1) | y;
}

int next_combination_main(){
    int n=5; // {0, 1, 2, 3, 4}の部分集合を考える
    int k=3;

    int bit=(1<<k)-1; // bit = {0, 1, 2}
    for(; bit<(1<<n); bit = next_combination(bit)){
        //　ここに処理をかく
    }
}

// TODO: 理解
// MARK: Xorshift: bitを用いたシンプルな乱数生成方法, 周期: 2^128-1
// ^: xor
unsigned int randInt(){
    static unsigned int tx = 123456789, ty=362436069, tz=521288629, tw=88675123;
    unsigned int tt = (tx^(tx<<11));
    tx = ty; ty = tz; tz = tw;
    return ( tw=(tw^(tw>>19))^(tt^(tt>>8)) );
}

int xorshift_main(){
    // サイコロを100回振ってみる
    for(int i=1; i<=100; i++){
        cout << randInt() % 6+1 << ", ";
        if(i % 10 == 0){
            cout << endl;
        }
    }
    return 0;
}

// TODO: 理解, あとで
// MARK: Binary Indexed Tree (BIT)
/*

*/

// MARk: bitDP

/*
    dp[S] := 全体集合{0, 1, 2, ..., n-1} の部分集合Sについて、その中で順序を最適化した時のSの中での最小コスト
*/

int bit_dp(){
    const int INF = 1001001001;

    // 満たすべき状態: n
    int n=200;
    // 要素数: m
    int m=20;

    vector<int> dp(1<<n, INF); // 2^n
    dp[0] = 0;

    // bit全探索 0~n-1, 2^n-1
    for(int s=0; s < 1<<n; s++){
        //
        for(int i=0; i<m; i++){
            // 次の状態への遷移
            // a → b, a →　cなど配る処理
            // 例
            /*
                int t = s | key[i].first;
                int cost = dp[s]+key[i].second;
                dp[t] = min(dp[t], cost);
            */
        }
    }
}



