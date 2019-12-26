#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<int> w(n+1);
    w[0] = 0;
    for(int i=1; i<n+1; i++){
        cin >> w[i];
        w[i] += w[i-1];
    }
    int han = w[n]/2;
    int pre = han;
    for(int i=1; i<n+1; i++){
        int tmp = abs(han-w[i]);
        if(pre > tmp){
            pre = tmp;
        }else{
            cout << abs(w[i-1] - (w[n] - w[i-1])) << endl;
            return 0;
        }
    }
    
    return 0;
}