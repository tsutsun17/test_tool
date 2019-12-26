#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)
using namespace std;
typedef long long ll;
const int inf = INT_MAX;
const ll INF = 1LL << 60;
const ll mod = 1e9+7;

// TIPS: LIS 最長増加部分列
/*
    与えられるデータの配列a
    i<j かつ a_i < a_j を満たす最長の部分列

    考えかた
    https://qiita.com/python_walker/items/d1e2be789f6e7a0851e5

    単調増加性が崩れないように最終要素をいれていく
    index: 1 2 3 4 5 6
    value: 1 4 6 i i i

    で次が２の時
    index: 1 2 3 4 5 6
    value: 1 2 6 i i i

    になる
    valueが最終要素の最小値であるためこうなる

    アルゴリズム
    1. index: 増加部分列の長さ, value: 数列の最終要素の最小値の配列を作り、INFで初期化
    2. 最終要素の値で二分探索をして、その要素以上(よりも大きい値)の一番左のものを取得
    3. そのvalueを最終要素にする
    4. 配列全ての走査が終わったら、INFのindexの最小値を求め、最小増加部分列の長さを出す
*/


// strict: trueだと連続する同じ値は増加列としない
int LIS(vector<int> a,  bool strict = true) {
    vector<int> dp(a.size(), inf);
    rep(i, a.size()){
        cout << a[i] << endl;
        if(strict){
            *lower_bound(dp.begin(), dp.end(), a[i]) = a[i];
        }else{
            *upper_bound(dp.begin(), dp.end(), a[i]) = a[i];
        }
    }
    return lower_bound(dp.begin(), dp.end(), inf) - dp.begin();
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    cout << LIS(a) << endl;
    return 0;
}