#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define chmin(x,y) x = min(x,y)
using namespace std;
typedef long long ll;
const int INF = 1001001001;

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

int main(){
    int n;
    cin >> n;
    vector<int> A(n);
    rep(i, n) cin >> A[i];

    int q = partition(A, 0, n-1);

    rep(i, n){
        if (i) cout << " ";
        if (i==q) cout << "[";
        cout << A[i];
        if(i==q) cout << "]";
    }
    cout << endl;

    return 0;
}