#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    map<int, int> a;
    for(int i=0; i<n; i++){
        int aa;
        cin >> aa;
        a[aa] += 1; 
    }
    int count = n - (n-a.size());
    if((n-a.size())%2==1){
        count--;
    }
    cout << count << endl;

    return 0;
}
