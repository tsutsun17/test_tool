#include <bits/stdc++.h>
using namespace std;

// 優先度付きキュー
/*
    priority_queue<int> q;

    追加： q.push()
    取り出し: a.pop()
    参照: a.top()
    空かどうか: a.empty()
    サイズ: a.size()

    swap(a, b): aとbを入れ替える
*/

// 1. 大きい順に取り出す less<int>
int dec(){
    int a[] = {5, 4, 6, 3, 7, 2, 8, 1, 9, 0};
    priority_queue<int> q;

    for (size_t i(0); i < sizeof(a) / sizeof(a[0]); ++i) {
        q.push(a[i]);
    }

    while (!q.empty()) {
        std::printf("%d\n", q.top());
        q.pop();
    }

    return 0;
}

// 2. 小さい順に取り出す greater<int>
int cre(){
    int a[] = {5, 4, 6, 3, 7, 2, 8, 1, 9, 0};
    priority_queue<int, vector<int>, greater<int>> q;

    for (size_t i(0); i < sizeof(a) / sizeof(a[0]); ++i) {
        q.push(a[i]);
    }

    while (!q.empty()) {
        std::printf("%d\n", q.top());
        q.pop();
    }

    return 0;
}

// 3. ラムダ式で優先順位の指定
/*
    c: ラムダ式
    priority_queue<int, vector<int> decltype(c)> q(c);
*/
int lamb(){
    int a[] = {5, 4, 6, 3, 7, 2, 8, 1, 9, 0};

    // l　が優先度低いときにtrue 全てがtrueになるようにsortされる
    auto c = [](int l, int r) { if (l % 2 == 0) return r % 2 != 0 || l >= r; else return r % 2 != 0 && l < r; };
    std::priority_queue<int, std::vector<int>, decltype(c)> q(c);

    for (size_t i(0); i < sizeof(a) / sizeof(a[0]); ++i) {
        q.push(a[i]);
    }

    while (!q.empty()) {
        std::printf("%d\n", q.top());
        q.pop();
    }

    return 0;
}