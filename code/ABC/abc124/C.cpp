#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    string s;
    cin >> s;
    int n = s.length();
    int ans_a=0; //0101010
    int ans_b=0; //10101010
    for(int i=0; i<n; i++){
        if(i%2==0){
            if(s[i]=='0'){
                ans_a++;
            }else{
                ans_b++;
            }
        }else{
            if(s[i]=='0'){
                ans_b++;
            }else{
                ans_a++;
            }
        }
    }
    cout << min(ans_a, ans_b) << endl;
    return 0;
}