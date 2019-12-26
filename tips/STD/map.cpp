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
    mapもsetと同様に平衡な二分探索木で実装されている

    size(): O(1)
    clear(): O(N)
    begin(): O(1)
    end(): O(1)
    insert((key, val)): O(logN)
    erase(key): O(logN)
    find(key): O(logN)
*/

void print(map<string, int> T){
    map<string, int>::iterator it;
    cout << T.size() << endl;
    for(it = T.begin(); it!=T.end(); it++){
        pair<string, int> item = *it;
        cout << item.first << " --> " << item.second << endl;
    }
}

int main(){
    map<string, int> T;
    T["red"] = 32;
    T["blue"] = 688;
    T["yellow"] = 122;

    T["blue"] = 312;
    print(T);

    T.insert(make_pair("zebra", 101010));
    T.insert(make_pair("white", 0));
    T.erase("yellow");

    print(T);
    pair<string, int> target = *T.find("red");
    cout << target.first << " --> " << target.second << endl;

    return 0;
}