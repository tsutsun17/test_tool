#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    int count = 0;
    vector< pair<char, int> > ss;
    for(int i=0; i<n; i++){
        if(s[i]!='x'){
            count++;
            ss.push_back(make_pair(s[i], i));
        }
    }
    int ans = 0;
    vector<char> l;
    vector<char> r;

    // xのみの時
    if(count == 0){
        cout << 0 << endl;
        return 0;
    }

    // 回文にできるかの判断
    for(int i=0; i<count/2; i++){
        if(ss[i].first != ss[count-1-i].first){
            cout << -1 << endl;
            return 0;
        }
    }

    int l_index = 0;
    int r_index = n-1;
    
    for(int i=0; i<n; i++){
        if(l_index >= r_index){
            break;
        }
        if(s[l_index] == s[r_index]){
            l_index++;
            r_index--;
        }else{
            ans++;
            if(s[l_index]=='x'){
                l_index++;
            }else{
                r_index--;
            }
        }
    }

    cout << ans << endl;
    return 0;
}