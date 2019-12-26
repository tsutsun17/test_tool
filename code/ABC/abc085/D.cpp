#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;
    ll h, count = 0;
    cin >> n >> h;
    ll max_a = 0;
    vector<ll> B(n);
    for(int i=0; i<n; i++){
        ll a, b;
        cin >> a >> b;
        max_a = max(max_a, a);
        B[i] = b; 
    }

    sort(B.begin(), B.end());
    int index = 0;
    bool flag = true;
    for(int i=0; i<n; i++){
        if(B[i]>max_a){
            index = i;
            flag = false;
            break;
        }
    }
    if(flag){
        index = n-1;
    }

    ll sum = 0;
    for(int i=n-1; i>=index; i--){
        sum += B[i];
        if(sum >= h){
            cout << n-i << endl;
            return 0;
        }
    };
    count += n-index;
    // 切り上げ
    count += ceil((double)(h-sum)/max_a);
    cout << count << endl;

    return 0;
}