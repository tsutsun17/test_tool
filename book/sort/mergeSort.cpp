#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define chmin(x,y) x = min(x,y)
using namespace std;
typedef long long ll;
const int INF = 1001001001;
const int MAX = 500000;
const int SENTINEL = 2000000000;

int L[MAX/2+2], R[MAX/2+2];
int cnt;

/*
    マージソート（安定）

    (利点)
        - 安定なソート
        - O(nlogn)
    (欠点)
        - O(n)の外部のメモリを必要とする

*/

void merge(vector<int>& A, int n, int left, int mid, int right){
    int n1 = mid - left;
    int n2 = right - mid;
    rep(i, n1) L[i] = A[left + i];
    rep(i, n2) R[i] = A[mid + i];
    L[n1] = R[n2] = SENTINEL;
    int i=0, j=0;
    for(int k = left; k<right; k++){
        cnt++;
        if(L[i] <= R[j]){
            // L[i++] は　L[i]を出した後に i++ する
            A[k] = L[i++];
        }else{
            A[k] = R[j++];
        }
    }
}

void mergeSort(vector<int>& A, int n, int left, int right){
    if(left+1 < right){
        int mid = (left+right)/2;
        mergeSort(A, n, left, mid);
        mergeSort(A, n, mid, right);
        merge(A, n, left, mid, right);
    }
}

int main(){
    int n;
    cnt = 0;

    cin >> n;
    vector<int> A(n);
    rep(i, n) cin >> A[i];

    mergeSort(A, n, 0, n);
    rep(i, n){
        if(i) cout << " ";
        cout << A[i];
    }
    cout << endl;
    cout << cnt << endl;
    return 0;
}