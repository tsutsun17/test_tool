#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define chmin(x,y) x = min(x,y)
using namespace std;
typedef long long ll;
const int INF = 1001001001;

int binarySearch(vector<int>& A, int n, int key){
    int left = 0; int right = n;
    int mid;
    while(left<right){
        mid = (left+right)/2;
        if(key==A[mid]) return 1;
        if(key < A[mid]) left = mid+1;
        if(key > A[mid]) right = mid;
    }

    return 0;
}

int main() {
    int n q, k, sum=0;
    cin >> n;
    vector<int> A(n);

    rep(i, n) cin >> A[i];
    cin >> q;
    rep(i, q){
        cin >> k;
        if(binarySearch(A, n, k)) sum++;
    }

    cout << sum << endl;

    return 0;
}