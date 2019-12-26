#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define chmin(x,y) x = min(x,y)
using namespace std;
typedef long long ll;
const int INF = 1001001001;

void trace(vector<int> A, int N){
    rep(i, N){
        if(i>0) cout <<  ' ';
        cout << A[i];
    }

    cout << endl;
}
// 挿入ソート
void insertionSort(vector<int> A, int N){
    rep(i, N){
        if(i==0) continue;
        int v = A[i];
        int j = i-1;
        while(j>=0 and A[j]>v){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
        trace(A, N);
    }
}

int main() {
    int N;
    vector<int> A(100);
    cin >> N;
    rep(i, N) cin >> A[i];

    trace(A, N);
    insertionSort(A, N);
    return 0;
}