#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define chmin(x,y) x = min(x,y)
using namespace std;
typedef long long ll;
const int INF = 1001001001;

//　選択ソート
int selectSort(vector<int>& A, int N){
    int i = 0; int count = 0;
    while(i<N-1){
        int min = A[i];
        int index = i;
        for(int j=i+1; j<N; j++){
            if(min > A[j]){
                min = A[j];
                index = j;
            }
        }
        if(index != i){
            swap(A[i], A[index]);
            count++;
        }
        i++;
    }

    return count;
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    int sw = selectSort(A, N);

    rep(i, N){
        if (i) cout<< " ";
        cout << A[i];
    }

    cout << endl;
    cout << sw << endl;
    return 0;
}