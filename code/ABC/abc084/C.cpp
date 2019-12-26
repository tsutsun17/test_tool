#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// DAME: 
// シミュレーション
int main() {
    int n;
    cin >> n;
    vector<int> c(n-1);
    vector<int> s(n-1);
    vector<int> f(n-1);
    int max_s = 0;
    for(int i=0; i<n-1; i++){
        cin >> c[i] >> s[i] >> f[i];
    }
    for(int i=0; i<n; i++){
        int t=0;
        for(int j=i; j<n-1; j++){
            if(t<s[j]){
                t = s[j];
            }else if(t%f[j]==0){
                t = t;
            }else{
                t = t + f[j] - t%f[j];
            }
            t += c[j];
        }
        cout << t << endl;
    }

    return 0;
}