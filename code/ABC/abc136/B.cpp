#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    string s;
    cin >> s;
    int keta = s.size();
    int n = atoi(s.c_str());
    int ans = 0;
    for(int i=0; i<keta/2; i++){
        ans += 9*pow(10, 2*i);
    }
    if(keta%2==1){
        ans += n-pow(10, keta-1)+1;
    }
    cout << ans << endl;
    return 0;
}