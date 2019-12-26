#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    string s, t;
    cin >> s >> t;
    int sn = s.size(), tn = t.size();
    if(sn<tn){
        cout << "UNRESTORABLE"<<endl;
        return 0;
    }
    vector<string> ans(sn-tn+1);
    for(int i=0; i<sn-tn+1; i++){
        string ss = s;
        for(int j=0; j<tn; j++){
            if(s[j+i] == t[j] || s[j+i] == '?'){
                ss[j+i] = t[j];
            }else{
                ss = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
                break;
            }
        }
        for(int j=0; j<sn; j++){
            if(ss[j]=='?') ss[j]='a';
        }
        ans[i] = ss;
    }

    sort(ans.begin(), ans.end());
    if(ans[0] == "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz"){
        cout << "UNRESTORABLE"<<endl;
    }else{
        cout << ans[0] << endl;
    }
    return 0;
}