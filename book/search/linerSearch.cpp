#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define chmin(x,y) x = min(x,y)
using namespace std;
typedef long long ll;
const int INF = 1001001001;

// TIPS: 番兵
/*
    番兵とは
        配列などの要素として設置される特別な値で、ループの制御を簡略化することができる

        vector<int> A(n+1);
        rep(i, n) cin >> A[i];


        int key; cin >> key; // 探索したい値
        A[n] = key;
        while(A[i] != key) i++;
        if(i==n){
            Aにkeyは存在しない
        }else{
            Aにkeyは存在する
        }

*/

int search(vector<int>& A, int n, int key){
    int i=0;
    A[n] = key;
    while(A[i]!=key) i++;
    return i!=key;
}

int main() {
    int i, n, q, key, sum=0;
    vector<int> A(n+1);
    scanf("%d", &n);
    rep(i, n) scanf("%d", &A[i]);
    A[n] = 0;
    scanf("%d", &q);
    rep(i, q){
        scanf("%d", &key);
        if(search(A, n, key)) sum++;
    }
    printf("%d\n", sum);

    return 0;
}