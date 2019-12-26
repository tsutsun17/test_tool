#include <bits/stdc++.h>
#define ALL(a)  (a).begin(),(a).end()
using namespace std;

// TIPS: (STL) binary_search, lower_bound, upper_bound

/*
    // TIPS:
        lower_bound(A.begin(), A.end(), 4) - upper_bound(A.begin(), A.end(), 4);

        で配列A内の4の個数がわかる

*/

// binary_search
/*
    二分探索
        ソートされた配列にkeyが存在するかどうかのboolを返す
        (欠点)
            - どこにkeyがあるかどうかが分からない
            - 同じkeyが複数あった場合にどのkeyを指しているのかが分からない


    最大値の最小ちなど

    binary_search(a.begin(), a.end(), key)
*/

int binary_main() {

    vector<int> a = {1,4,4,7,7,8,8,11,13,19};

    cout << binary_search(a.begin(), a.end(), 4) << endl; //True
    cout << binary_search(a.begin(), a.end(), 9) << endl; //False
    cout << binary_search(a.begin(), a.end(), 3) << endl; //False
}

// lower_bound
/*
    二分探索
        ソートされた配列で、key以上の要素の内の一番左のイテレータを返す

    vector<int>::itrator it = lower_bound(a.begin(), a.end(), key);
    auto を使う
    *it で最初の要素
    it - a.begin() でaの最初からのindex
    it - a.end() でkey以上の要素の個数
*/

int lower_main() {

    vector<int> a = {1, 4, 4, 7, 7, 8, 8, 11, 13, 19};

    //イテレータを返す
    auto Iter1 = lower_bound(ALL(a), 4);

    //値の表示
    cout << "Iter1 = " << *Iter1 << endl; //Iter1=4

    //先頭からの距離
    cout << "Iter1 = " << Iter1 - a.begin() << endl; //Iter1 = 1

    //末尾までの距離
    cout << "Iter1 = " << a.end() - Iter1 << endl; //Iter1 = 9
}

// upper_bound
/*
    二分探索
        ソートされた配列で、keyより大きい要素の内の一番左のイテレータを返す

    vector<int>::itrator it = upper_bound(a.begin(), a.end(), key);
    auto を使う
    *it で最初の要素
    it - a.begin() でkey以下の要素の個数
    it - a.end() でkeyより大きい要素の個数
*/

int upper_main() {

    vector<int> a = {1, 4, 4, 7, 7, 8, 8, 11, 13, 19};

    //イテレータを返す
    auto Iter1 = upper_bound(ALL(a), 4);

    //値の表示
    cout << "Iter1 = " << *Iter1 << endl; //Iter1=7

    //先頭からの距離
    cout << "Iter1 = " << Iter1 - a.begin() << endl; //Iter1 = 3

    //末尾までの距離
    cout << "Iter1 = " << a.end() - Iter1 << endl; //Iter1 = 7
}