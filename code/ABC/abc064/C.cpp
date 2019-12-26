#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    vector<int> rate(8, 0);
    int free = 0;
    sort(a.begin(), a.end());
    for(int i=0; i<n; i++){
        if(a[i]<3200){
            if(a[i]<400){
                rate[0]++;
            }else if(a[i]<800){
                rate[1]++;
            }else if(a[i]<1200){
                rate[2]++;
            }else if(a[i]<1600){
                rate[3]++;
            }else if(a[i]<2000){
                rate[4]++;
            }else if(a[i]<2400){
                rate[5]++;
            }else if(a[i]<2800){
                rate[6]++;
            }else if(a[i]<3200){
                rate[7]++;
            }
        }else{
            free++;
        }
    }
    int ans = 0;
    for(int i=0; i<8; i++){
        if(rate[i]>0){
            ans++;
        }
    }
    if(ans == 0){
        cout << 1 << ' ';
    }else{
        cout << ans << ' ';
    }

    cout << ans+free << endl;
    return 0;
}