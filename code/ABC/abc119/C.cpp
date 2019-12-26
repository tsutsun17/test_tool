#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// DAME:

int N, A, B, C;

// N本の竹をA, B, C, 無しの四つに振り分ける
// 誤差分を追加する

int dfs(int n, int a, int b, int c, const vector<int>& l) {
    if (n == N) {
        if (a == 0 || b == 0 || c == 0) return pow(10, 9);
        // -30は最初の追加は合成じゃないため
        return abs(A - a) + abs(B - b) + abs(C - c) - 30;
    }
    // 合成をしない
    int r0 = dfs(n+1, a, b, c, l);
    // 合成をする
    int r1 = dfs(n+1, a+l[n], b, c, l) + 10;
    int r2 = dfs(n+1, a, b+l[n], c, l) + 10;
    int r3 = dfs(n+1, a, b, c+l[n], l) + 10;
    return min({r0, r1, r2, r3});
}
 
int main() {
    cin >> N >> A >> B >> C;
    vector<int> l(N);
    for(int i=0; i<N; i++){
        cin >> l[i];
    }
 
    cout << dfs(0, 0, 0, 0, l) << endl;
    return 0;
}