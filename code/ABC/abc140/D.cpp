#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// DAME: 考察メイン

/*
    シミューションではない
    反転部分の内部の幸福関係は変わらない
    幸福関係が変化するのは、反転部分と他の部分のつなぎ目のみ

    →　一回の反転では最大２つしか幸福関係が増えない
*/

int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    int score = 0;
    for(int i=0; i<n-1; i++){
        if(s[i] == s[i+1]){
            score++;
        }
    }
    int ans = min(score + 2*k, n-1);
    cout << ans << endl;
    return 0;
}