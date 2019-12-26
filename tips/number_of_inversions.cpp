#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
using namespace std;
typedef long long ll;
const int MAX = 200000;
const int SENTINEL = 2000000000;


// 反転数, 転倒数
/*
    mergeSortを使用する

*/

int L[MAX/2+2], R[MAX/2+2];

ll merge(vector<int>& A, int n, int left, int mid, int right){
    ll cnt = 0;
    int n1 = mid - left;
    int n2 = right - mid;
    rep(i, n1) L[i] = A[left + i];
    rep(i, n2) R[i] = A[mid + i];
    L[n1] = R[n2] = SENTINEL;
    int i=0, j=0;
    for(int k = left; k<right; k++){
        if(L[i] <= R[j]){
            A[k] = L[i++];
        }else{
            A[k] = R[j++];
            cnt += n1-i; // = mid + j - k - 1
        }
    }
    return cnt;
}

ll mergeSort(vector<int>& A, int n, int left, int right){
    ll v1, v2, v3;
    if(left+1 < right){
        int mid = (left+right)/2;
        v1 = mergeSort(A, n, left, mid);
        v2 = mergeSort(A, n, mid, right);
        v3 = merge(A, n, left, mid, right);
        return v1+v2+v3;
    }else return 0;
}

int main(){
    int n;
    cin >> n;
    vector<int> A(n);
    rep(i, n) cin >> A[i];

    ll ans = mergeSort(A, n, 0, n);
    cout << ans << endl;
    return 0;
}