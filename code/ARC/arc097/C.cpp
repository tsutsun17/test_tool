#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// DAME:
// 文字列の辞書順: abc > 次の単語のabc >>　単語のながさ 
int main() {
    string s;
    int n, k;
    cin >> s >> k;
    n = s.size();
    set<string> ss;
    for(int i=0; i<n; i++){
        string sss;
        // TIPS: 長さがk以下しかありえない
        for(int j=i; j<min(i+k, n); j++){
            sss += s[j];
            ss.insert(sss);
        }
    }
    auto itr = ss.begin();
    for(int i=0; i<k-1; i++){
        ++itr;
    }

    cout << *itr << endl;
    return 0;
}