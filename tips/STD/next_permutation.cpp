#include <bits/stdc++.h>
using namespace std;

// 順列の生成 nPr

// next_permutation
/*
    辞書順に順列を生成し、元々の配列より後のものを出力していくため、必ず最初は整列させる
    a の順番を直接変化させている
    1 2 3 4
    1 2 4 3
    1 3 2 4
    1 3 4 2
    1 4 2 3
    1 4 3 2
    2 1 3 4
    2 1 4 3
    2 3 1 4
    2 3 4 1
    2 4 1 3
    2 4 3 1
    3 1 2 4
    3 1 4 2
    3 2 1 4
    3 2 4 1
    3 4 1 2
    3 4 2 1
    4 1 2 3
    4 1 3 2
    4 2 1 3
    4 2 3 1
    4 3 1 2
    4 3 2 1

    - next_permutation
    - prev_permutation: 逆順

    計算量: O(n!)

*/
int main(){
    vector<int> a(4);
    iota(a.begin(), a.end(), 1);
    do{
        for(int i=0; i<4; i++){
            cout << a[i];
            if(i!=3)cout << " ";
        }
        cout << endl;
    }while(next_permutation(a.begin(), a.end()));
}