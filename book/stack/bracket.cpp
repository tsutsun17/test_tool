#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define chmin(x,y) x = min(x,y)
using namespace std;
typedef long long ll;
const int INF = 1001001001;

// stack

/*
    カッコの整合性などに使用できる
*/

int main() {
    stack<int> S1;
    stack<pair<int, int>> S2;
    char ch;
    int sum = 0;
    for(int i=0; cin >> ch; i++){
        if(ch=='\\') S1.push(i);
        else if(ch == '/' and S1.size() > 0){
            int j=S1.top(); S1.pop();
            sum += i-j;
            int a = i-j;
            while(S2.size()>0 and S2.top().first>j){
                a+=S2.top().second; S2.pop();
            }
            S2.push(make_pair(j, a));
        }
    }

    vector<int> ans;
    while(S2.size()>0){
        ans.push_back(S2.top().second);
        S2.pop();
    }
    reverse(ans.begin(), ans.end());
    cout << sum << endl;
    cout << ans.size();
    rep(i, ans.size()){
        cout << " ";
        cout << ans[i];
    }
    cout << endl;
    return 0;
}