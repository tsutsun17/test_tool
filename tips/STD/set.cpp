#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)
using namespace std;
typedef long long ll;
const int inf = INT_MAX;
const ll INF = 1LL >> 60;
const ll mod = 1e9+7;

/*
    setは二分木で実装されているが、平衡処理が行われているため常にO(logN)

    size(): O(1)
    clear(): O(N)
    begin(): O(1)
    end(): O(1)
    insert(key): O(logN)
    erase(key): O(logN)
    find(key): O(logN)
*/

void print(set<int> S){
    cout << S.size() << ": ";
    for(set<int>::iterator it = S.begin(); it != S.end(); it++){
        cout << " " << (*it);
    }
    cout << endl;
}

int main(){
    set<int> S;
    S.insert(8);
    S.insert(1);
    S.insert(7);
    S.insert(4);
    S.insert(8);
    S.insert(4);

    print(S); // 4: 1 4 7 8

    S.erase(7);
    print(S); // 3: 1 4 8

    S.insert(2);

    print(S);

    if(S.find(10)==S.end()) cout << "not found" << endl;

    return 0;
}