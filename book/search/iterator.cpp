#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define chmin(x,y) x = min(x,y)
using namespace std;
typedef long long ll;
const int INF = 1001001001;

// TIPS: イテレータ
/*
    ++: イテレータを次の要素に進める
    ==, !=: 二つのイテレータが同じ位置を示しているかどうかを返す
    =: 左辺のイテレータが参照している要素の「位置」に右辺の値を代入する
    *: その位置にある要素を返す


    共通のインタフェース（関数などの使い方）でコンテナに対する反復処理を行うことができるポインタのようなもの
*/

void print(vector<int> v){
    for(vector<int>::iterator it = v.begin(); it!=v.end(); it++){
        cout << *it;
    }
    cout << endl;
}

int main() {
    int N=4;
    vector<int> v;
    rep(i, N){
        int x;
        cin >> x;
        v.push_back(x);
    }

    print(v);
    vector<int>::iterator it = v.begin();
    *it = 3; // 先頭の要素をv[0]を３にする
    it++; // 一つ進める
    (*it)++; // v[1]の要素に１を加算する

    print(v);
    return 0;
}