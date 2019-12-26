#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    map<int, int> mp1, mp2;
    for(int i=0; i<n; i++){
        cin >> v[i];
        if(i%2){
            mp2[v[i]]++;
        }else{
            mp1[v[i]]++;
        }
    }

    // 数字, count
    pair<int, int> max1, next_max1;
    max1 = make_pair(0, 0), next_max1 = make_pair(0, 0);
    for(auto m: mp1){
        int tmp = m.second;
        if(tmp > max1.second){
            next_max1 = max1;
            max1 = make_pair(m.first, m.second);
            continue;
        }
        if(tmp > next_max1.second){
            next_max1 = make_pair(m.first, m.second);
            continue;
        }
    }

    pair<int, int> max2, next_max2;
    max2 = make_pair(0, 0), next_max2 = make_pair(0, 0);
    for(auto m: mp2){
        int tmp = m.second;
        if(tmp > max2.second){
            next_max2 = max2;
            max2 = make_pair(m.first, m.second);
            continue;
        }
        if(tmp > next_max2.second){
            next_max2 = make_pair(m.first, m.second);
            continue;
        }
    }

    if(max1.first!=max2.first){
        cout << n - max1.second - max2.second << endl;
        return 0;
    }
    cout << min(n - max1.second - next_max2.second, n - next_max1.second - max2.second) << endl;

    return 0;
}