#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define MAX 2000001
#define VMAX 10000
using namespace std;
typedef long long ll;

/*
    計数ソート
        1. 数列Aの各要素が何回現れるかを計測し配列Cに追加
            Aの中に5が3回出てくる場合、C[5] = 3
        2. Cの累積和を計測
        3. 数列Aを最後から取り出し、Cの値をindexとして配列Bに配置
        4. Cの値を１引く
*/

int main(){
    int n;
    cin >> n;
    vector<int> A(n+1), B(n+1), C(VMAX+1);

    rep(i, VMAX+1) C[i] = 0;

    rep(i, n){
        cin >> A[i+1];
        C[A[i+1]]++;
    }

    for(int i=1; i<=VMAX; i++) C[i] = C[i] + C[i-1];

    for(int i=1; i<=n; i++){
        B[C[A[i]]] = A[i];
        C[A[i]]--;
    }

    for(int i=1; i<=n; i++){
        if(i>1) cout << " ";
        cout << B[i];
    }
    cout << endl;

    return 0;
}