#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define chmin(x,y) x = min(x,y)
using namespace std;
typedef long long ll;
const int INF = 1001001001;

struct Card {
    char suit,
    value;
};

void bubble(struct Card A[], int N){
    rep(i, N){
        for(int j=N-1; j>=i+1; j--){
            if(A[j].value < A[j-1].value){
                Card t = A[j];
                A[j] = A[j-1];
                A[j-1] = t;
            }
        }
    }
}

void selection(struct Card A[], int N){
    rep(i, N){
        int minj = i;
        for(int j=i; j<N; j++){
            if(A[j].value < A[minj].value) minj = j;
        }
        Card t = A[i];
        A[i] = A[minj];
        A[minj] = t;
    }
}

void print(struct Card A[], int N){
    rep(i, N){
        if(i > 0) cout << " ";
        cout << A[i].suit << A[i].value;
    }
    cout << endl;
}

// バブルソートと選択ソートの結果を比較
bool isStable(struct Card C1[], struct Card C2[], int N){
    rep(i, N){
        if(C1[i].suit != C2[i].suit) return false;
    }
    return true;
}

int main(){
    Card C1[100], C2[100];
    int N;
    char ch;

    cin >> N;
    rep(i, N){
        cin >> C1[i].suit >> C1[i].value;
    }

    rep(i, N) C2[i] = C1[i];

    bubble(C1, N);
    selection(C2, N);

    print(C1, N);
    cout << "Stable" << endl;

    print(C2, N);

    if(isStable(C1, C2, N)){
        cout << "Stable" << endl;
    }else{
        cout << "Not stable" << endl;
    }
    return 0;
}