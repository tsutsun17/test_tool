#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector< pair<double, string> > mo(n);
    double sum=0.0;
    for(int i=0; i<n; i++){
        cin >> mo[i].first >> mo[i].second;
    }
    for(int i=0; i<n; i++){
        if(mo[i].second == "BTC"){
            sum += 380000.0 * mo[i].first;
            continue;
        }
        sum += mo[i].first;
    }
    cout << setprecision(15) << sum << endl;
    return 0;
}