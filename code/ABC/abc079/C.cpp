#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    string s;
    cin >> s;
    int a = s[0] - '0';
    int b = s[1] - '0';
    int c = s[2] - '0';
    int d = s[3] - '0'; 
    int ans = a;
    vector<char> ops(3);

    for(int i=0; i<=1; i++){
        if(i==0){
            ans += b;
            ops[0] = '+';
        }else{
            ans -= b;
            ops[0] = '-';
        }
        for(int j=0; j<=1; j++){
            if(j==0){
                ans += c;
                ops[1] = '+';
            }else{
                ans -= c;
                ops[1] = '-';
            }
            for(int l=0; l<=1; l++){
                if(l==0){
                    ans += d;
                    ops[2] = '+';
                }else{
                    ans -= d;
                    ops[2] = '-';
                }
                if(ans == 7){
                    cout << a << ops[0] << b << ops[1] << c << ops[2] << d << "=7";
                    return 0;
                }else{
                    if(l==0){
                        ans -= d;
                    }else{
                        ans += d;
                    }
                }
            }
            if(j==0){
                ans -= c;
            }else{
                ans += c;
            }
        }
        if(i==0){
            ans -= b;
        }else{
            ans += b;
        }
    }



    return 0;
}