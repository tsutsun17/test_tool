#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define chmin(x,y) x = min(x,y)
using namespace std;
typedef long long ll;
const int INF = 1001001001;

/*
    クイックソート（不安定）
        1. partitionで対象の部分配列を前後２つの部分配列へ分割する
        2. 前半の部分配列に対してquickSortを行う
        3. 後半の部分配列に対してquickSortを行う

    (利点)
        - 追加のメモリ領域を必要としない(内部ソート)
        - O(nlogn) だが、最悪 O(n^2)
    (欠点)
        - 不安定なソート
*/

// partition
int partition(vector<int>& A, int p, int r){
    int x = A[r];
    int i = p-1;
    for(int j=p; j<r; j++){
        if(A[j] <= x){
            i++;
            swap(A[i], A[j]);
        }
    }
    swap(A[i+1], A[r]);
    return i+1;
}

// quickSort
void quickSort(vector<int>& A, int p, int r){
    if (p<r) {
        int q = partition(A, p, r);
        quickSort(A, p, q-1);
        quickSort(A, q+1, r);
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> A(n);
    rep(i, n) cin >> A[i];

    quickSort(A, 0, n-1);

    rep(i, n){
        if (i) cout << " ";
        cout << A[i];
    }
    cout << endl;

    return 0;
}