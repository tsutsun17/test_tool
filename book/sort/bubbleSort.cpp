#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define chmin(x,y) x = min(x,y)
using namespace std;
typedef long long ll;
const int INF = 1001001001;

// バブルソート
int bubbleSort(vector<int>& A, int N){
    int sw = 0;
    bool flag = 1;
    while(flag){
        int i=0;
        flag = 0;
        for(int j=N-1; j>=1; j--){
            if(A[j]<A[j-1]){
                // 隣接要素を交換する
                swap(A[j], A[j-1]);
                flag = 1;
                sw++;
            }
        }
        i++;
    }
    return sw;
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    int sw = bubbleSort(A, N);

    rep(i, N){
        if (i) cout<< " ";
        cout << A[i];
    }

    cout << endl;
    cout << sw << endl;
    return 0;
}