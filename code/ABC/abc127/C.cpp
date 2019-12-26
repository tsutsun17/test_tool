#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> L(m);
    vector<int> R(m);
    for(int i=0; i<m; i++){
        cin >> L[i];
        cin >> R[i];
    }
    int max_l = *max_element(L.begin(), L.end());
    int min_r = *min_element(R.begin(), R.end());

    int difference = min_r - max_l + 1;
    if(difference <= 0){
        cout << 0 << endl;
    }else{
        cout << difference << endl;
    }
    return 0;
}