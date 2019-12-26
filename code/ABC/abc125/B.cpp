#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<int> V(n);
    vector<int> C(n);
    for(int i=0; i<n; i++){
        cin >> V[i];
    }
    for(int i=0; i<n; i++){
        cin >> C[i];
    }
    int ans=0;
    for(int i=0; i<n; i++){
        if(V[i]-C[i]<=0){
            continue;
        }
        ans += V[i]-C[i];
    }
    cout << ans << endl;
    return 0;
}