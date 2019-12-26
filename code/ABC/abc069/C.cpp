#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


// DAME:
int main() {
    int n;
    cin >> n;
    vector<ll> a(3, 0);
    string ans;
    for(int i=0; i<n; i++){
        int aa;
        cin >> aa;

        if(aa%4==0){
            a[2]++;
        }else if(aa%4==2){
            a[1]++;
        }else{
            a[0]++;
        }
    }
    // 1の隣は必ず4, 2の隣は2か4
    // 2がない時、1の数は4の数+1以下 1414141
    if(a[1]==0){
        if(a[0] <= a[2]+1){
            ans = "Yes";
        }else{
            ans = "No";
        }
    }else{
        // 2の集団の前後は必ず4
        // 1414 22222222 4141 
        if(a[0] <= a[2]){
            ans = "Yes";
        }else{
            ans = "No";
        }
    }
    
    cout << ans << endl;
    return 0;
}