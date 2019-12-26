#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// DAME:

// // 一つ目
// int main() {
//     int n;
//     cin >> n;
//     vector<string> s(n);
//     vector<int> p(n);
//     vector<int> ord(n);
//     for(int i=0; i<n; i++){
//         cin >> s[i] >> p[i];
//     }
//     // TIPS: iotaは第三引数から始まる整数列を生成する
//     iota(ord.begin(), ord.end(), 0);

//     // TIPS: lambda式を使用したsort -> lambda式の条件を満たすようにsortする
//     sort(ord.begin(), ord.end(), [&](int x, int y){
//         if(s[x]==s[y]){
//             return p[x] > p[y];
//         }
//         return s[x] < s[y];
//     });

//     for(auto e: ord){
//         cout << e+1 << endl;
//     }
//     return 0;
// }

int main() {
    int n;
    cin >> n;
    vector<pair<pair<string, int>, int> > sp(n);
    for(int i=0; i<n; i++){
        int p;
        cin >> sp[i].first.first >> p;
        p *= -1;
        sp[i].first.second = p;
        sp[i].second = i + 1;
    }
    // TIPS: pairのsortはfirstの比較の後にsecondの比較が入る
    sort(sp.begin(), sp.end());
    for(int i=0; i<n; i++){
        cout << sp[i].second << endl;
    }
    return 0;
}