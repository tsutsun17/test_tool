#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// DAME:

// TIPS: stack処理

/*
    かっこ列の整合性
    - stackを使用
    - 左かっこがきたらstackに追加
    - 右かっこがきた時に、stackが空だったら[不整合エラー検出]で、空でなかったらstackにある左かっこと
    今ある右かっことをペアにしてstackからpopする
*/

// (を左から必要分, )を右から必要分
int main() {
    int n;
    string s;
    cin >> n >> s;
    int need_left = 0;
    int pointer = 0;
    
    for(int i=0; i<s.size(); i++){
        if(s[i] == '('){
            ++pointer;
        }else{
            if(pointer == 0){
                ++need_left;
            }else{
                --pointer;
            }
        }
    }

    int need_right = pointer;

    string res = "";
    for(int i=0; i<need_left; i++){
        res += '(';
    }
    res += s;

    for(int i=0; i<need_right; i++){
        res+=')';
    }
    cout << res << endl;

    return 0;
}