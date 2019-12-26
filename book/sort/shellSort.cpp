#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define chmin(x,y) x = min(x,y)
using namespace std;
typedef long long ll;
const int INF = 1001001001;

/*
    shell-sort
    一定の間隔gだけ離れた要素のみを対象とした挿入ソート
*/

ll cnt;
int l;
int n;
vector<int> G;

// 間隔gを指定した挿入ソート
void insertionSort(vector<int>& A, int n, int g){
    for(int i=g; i<n; i++){
        int v = A[i];
        int j = i-g;
        while(j>=0 and A[j]>v){
            A[j+g] = A[j];
            j-=g;
            cnt++;
        }
        A[j+g] = v;
    }
}

void shellSort(vector<int>& A, int n){
    // 数列G = {1, 4, 13, 40, ...} g_i+1 = g_i * 3 + 1
    for(int h=1;;){
        if(h>n) break;
        G.push_back(h);
        h = 3*h+1;
    }

    for(int i=G.size()-1; i>=0; i--){
        insertionSort(A, n, G[i]);
    }
}

int main(){
    cin >> n;
    vector<int> A(n);
    // より速い入力scanf関数を使用
    rep(i, n) scanf("%d", &A[i]);
    cnt = 0;

    shellSort(A, n);

    cout << G.size() << endl;
    for(int i=G.size()-1; i>=0; i--){
        printf("%d", G[i]);
        if(i) printf(" ");
    }

    printf("\n");
    printf("%d\n", cnt);
    rep(i, n) printf("%d\n", A[i]);

    return 0;
}