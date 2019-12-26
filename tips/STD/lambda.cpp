#include <bits/stdc++.h>
using namespace std;

// lambda式
/*
    例:
    auto f = [](int a, int b) { return a + b; };

    // キャプチャ
    [&]       : デフォルトで環境にある変数を参照して、ラムダ式のなかで使用する
    [=]       : デフォルトで環境にある変数をコピーして、ラムダ式のなかで使用する
    [&x]      : 変数xを参照して、ラムダ式のなかで使用する
    [x]       : 変数xをコピーして、ラムダ式のなかで使用する
    [&, x]    : デフォルトで参照キャプチャ、変数xのみコピーして、ラムダ式のなかで使用する
    [=, &x]   : デフォルトでコピーキャプチャ、変数xのみ参照して、ラムダ式のなかで使用する
    [this]    : *thisのメンバを参照して、ラムダ式のなかで使用する
    [this, x] : *thisのメンバを参照し、変数xのみコピーして、ラムダ式のなかで使用する
*/

// 1. sortでのlambda式 (pairのsecondでsort)
int sort_lambda(){
    vector<pair<int, int>> a;

    // l rの順番
    sort(a.begin(), a.end(), [](const pair<int, int>& l, const pair<int, int>& r){ return l.second < r.second;} );

    return 0;
}


// 2. sortする前のindexの情報が欲しい
int index_lambda(){
    vector<int> vec;
    vector<int> index(vec.size());
    iota(index.begin(), index.end(), 0);


    // indexのvectorをvecの大きさ順にsort
    sort(
        index.begin(),
        index.end(),
        [&](int x, int y){return vec[x] < vec[y];}
    );
}
