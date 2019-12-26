#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N, T;
    cin >> N >> T;
    vector<int> c(N), t(N);
    for(int i=0; i<N; i++){
        cin >> c[i] >> t[i];
    }
    int ans = 1001;
    for(int i=0; i<N; i++){
        if(t[i]<=T){
            ans = min(ans, c[i]) ;
        }
    }

    if(ans == 1001){
        cout << "TLE" << endl;
    }else{
        cout << ans << endl;
    }
    return 0;
}